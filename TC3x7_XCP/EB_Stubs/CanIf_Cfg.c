/**
 * \file
 *
 * \brief AUTOSAR CanIf
 *
 * This file contains the implementation of the AUTOSAR
 * module CanIf.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2018 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
[!CODE!]
[!AUTOSPACING!]

/*
 *  MISRA-C:2012 Deviations:
 *
 *  MISRAC2012-1) Deviated Rule: 9.5 (Required)
 *    Where designated initializers are used to initialize an array object the
 *    size of the array shall be specified explicitly.
 *
 *    Reason:
 *    Array size and initialization are depending on configuration whereas the
 *    array declaration is used by configuration-independent library code.
 */

/*==================[inclusions]=============================================*/
[!INCLUDE "../include/CanIf_PreCompileMacros.m"!]

#define CANIF_NO_CFGCLASSMIX_REQUIRED
#define CANIF_NO_PBCFG_REQUIRED
#include <CanIf.h>                /* CanIf Types */
#include <CanIf_Int.h>

[!IF "$canifMFSupport"!][!//
[!INCLUDE "../include/CanIf_DecoupledProcessing.m"!][!//
#include <SchM_CanIf.h>
[!ELSE!]
[!VAR "decoupledRxSupported" = "false()"!]
[!VAR "txDecoupledSupport" = "false()"!]
[!ENDIF!]

[!/* *** include transceiver drivers if necessary *** */!]
[!IF "$canTrcvSupport"!]
  [!IF "$useTransceiverInfix = 'true'"!]
    [!FOR "i"="0" TO "$trcvDriversNum - 1"!]
      [!VAR "trcvInfix"!][!CALL "CreateTrcvInfixByIdx", "idx"="$i"!][!ENDVAR!]
      [!IF "$trcvInfix = ''"!]
#include <CanTrcv.h>              /* AUTOSAR CanTrcv definitions */
      [!ELSE!]
#include <CanTrcv_[!"$trcvInfix"!].h>   /* AUTOSAR CanTrcv definitions */
      [!ENDIF!]
    [!ENDFOR!]
  [!ELSE!]
#include <CanTrcv.h>              /* AUTOSAR CanTrcv definitions */
  [!ENDIF!]
[!ENDIF!]

/* do not indirectly include PduR_SymbolicNames_PBcfg.h via PduR_CanIf.h */
#define PDUR_NO_PBCFG_REQUIRED

[!LOOP "text:split($ulCbFuncLUT)"!]
  [!VAR "tmpUpperLayerName"="text:split( ., ':' )[1]"!]
  [!IF "$tmpUpperLayerName = 'PDUR'"!]
#include <PduR_CanIf.h>            /* PduR callback function declarations */
  [!ENDIF!][!//
  [!IF "$tmpUpperLayerName = 'CAN_TP'"!]
#include <CanTp_Cbk.h>             /* CanTp callback function declarations */
  [!ENDIF!][!//
  [!IF "$tmpUpperLayerName = 'CAN_TSYN'"!]
#include <CanTSyn_Cbk.h>           /* CanTSyn callback function declarations */
  [!ENDIF!][!//
  [!IF "$tmpUpperLayerName = 'CAN_NM'"!]
#include <CanNm_Cbk.h>             /* CanNm callback function declarations */
  [!ENDIF!][!//
[!ENDLOOP!]

[!LOOP "CanIfPublicCfg/CanIfPublicCddHeaderFile/*"!][!//
#include <[!"."!]>   /* CDD header file */
[!ENDLOOP!][!//

/*==================[macros]=================================================*/

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[internal constants]=====================================*/

/*==================[external constants]=====================================*/

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanIf_MemMap.h>

[!IF "$canTrcvSupport"!]
/** \brief Configuration of CanTrcv function pointers */
CONST( CanIf_CanTrcvConfigType, CANIF_APPL_CONST )
  CanIf_CanTrcvConfig[[!"$trcvDriversNum"!]] =
{
[!FOR "i"="0" TO "$trcvDriversNum - 1"!]
  [!IF "$useTransceiverInfix = 'true'"!]
    [!VAR "trcvInfix"!][!CALL "CreateTrcvInfixByIdx", "idx"="$i"!]_[!ENDVAR!]
  [!ELSE!]
    [!VAR "trcvInfix" = "''"!]
  [!ENDIF!]
  {
    &CanTrcv_[!"$trcvInfix"!]SetOpMode,
    &CanTrcv_[!"$trcvInfix"!]GetOpMode,
[!IF "$canTrcvWakeupSupport = 'true'"!]
    &CanTrcv_[!"$trcvInfix"!]GetBusWuReason,
    &CanTrcv_[!"$trcvInfix"!]SetWakeupMode,
  [!SELECT "CanIfTrcvDrvCfg/*[position() = ($i+1)]"!]
  [!IF "count(CanIfTrcvCfg/*[CanIfTrcvWakeupSupport = 'true']) > 0"!]
    &CanTrcv_[!"$trcvInfix"!]CheckWakeup,
  [!ELSE!]
    NULL_PTR,
  [!ENDIF!]
  [!ENDSELECT!]
[!ENDIF!]
[!IF "$canifPNSupport"!]
  [!VAR "CanTrcvPnSupport"!][!CALL "GetPnSupportByIdx", "idx"="$i"!][!ENDVAR!]
  [!IF "$CanTrcvPnSupport = 'true'"!]
    &CanTrcv_[!"$trcvInfix"!]ClearTrcvWufFlag,
    &CanTrcv_[!"$trcvInfix"!]CheckWakeFlag
  [!ELSE!]
    &CanIf_ClearTrcvWufFlag_HlpNoPn,
    &CanIf_CheckWakeFlag_HlpNoPn
  [!ENDIF!]
[!ENDIF!]
  },
[!ENDFOR!]
};
[!ENDIF!]


[!IF "($ulRxIndicationSupport = 'true') or ($cddRxIndicationSupport = 'true') or ($ulTxConfirmationSupport = 'true') or ($dlcErrorNotifSupport = 'true') or ($dlcPassedNotifSupport = 'true')"!]
/** \brief Configuration of upper layer callback function pointers */
/* Deviation MISRAC2012-1 <START> */
CONST( CanIf_CbkFctPtrTblType, CANIF_APPL_CONST ) CanIf_CbkFctPtrTbl[] =
{
  [!LOOP "text:split($ulCbFuncLUT)"!]
  {
    [!VAR "tmpUpperLayerName"="text:split( ., ':' )[1]"!]
     /* [!"$tmpUpperLayerName"!] */
    [!VAR "tmpRxIndication"="text:split( ., ':' )[3]"!]
    [!VAR "tmpCddRxIndication"="text:split( ., ':' )[4]"!]
    [!VAR "tmpTxConfirmation"="text:split( ., ':' )[5]"!]
    [!VAR "tmpDlcFailedNofif"="text:split( ., ':' )[6]"!]
    [!VAR "tmpDlcPassedNofif"="text:split( ., ':' )[7]"!]
[!IF "$ulRxIndicationSupport = 'true'"!]
    [!"$tmpRxIndication"!],
[!ENDIF!]
[!IF "$cddRxIndicationSupport = 'true'"!]
    [!"$tmpCddRxIndication"!],
[!ENDIF!]
[!IF "$ulTxConfirmationSupport = 'true'"!]
    [!"$tmpTxConfirmation"!],
[!ENDIF!]
[!IF "$dlcErrorNotifSupport = 'true'"!]
    [!"$tmpDlcFailedNofif"!],
[!ENDIF!]
[!IF "$dlcPassedNotifSupport = 'true'"!]
    [!"$tmpDlcPassedNofif"!],
[!ENDIF!]
  },
  [!ENDLOOP!]
};
/* Deviation MISRAC2012-1 <STOP> */
[!ENDIF!]


[!IF "$txDecoupledSupport = 'true'"!]
/** \brief Configuration of Tx decoupled processing */
/* Deviation MISRAC2012-1 <START> */
CONST( CanIf_MfTxPtrTblType, CANIF_APPL_CONST ) CanIf_MfTxFctPtrTbl[] =
{
  [!VAR "txOffset" = "num:i(0)"!]
  [!LOOP "as:modconf('CanIf')[1]/CanIfPublicCfg/CanIfTxProcessing/*"!]
  {
    &SchM_ActMainFunction_CanIf_Tx_[!"node:name(.)"!],
    [!"$txOffset"!]U,
    [!"num:i(CanIfTxPduQueueSize)"!]U
    [!VAR "txOffset" = "num:i($txOffset + CanIfTxPduQueueSize)"!]
  },
  [!ENDLOOP!]
};
/* Deviation MISRAC2012-1 <STOP> */
[!ENDIF!]


[!IF "$decoupledRxSupported = 'true'"!]
/** \brief Configuration of Rx decoupled processing */
/* Deviation MISRAC2012-1 <START> */
CONST( CanIf_MfRxPtrTblType, CANIF_APPL_CONST ) CanIf_MfRxFctPtrTbl[] =
{
  [!VAR "rxOffset" = "num:i(0)"!]
  [!VAR "rxPayloadOffset" = "num:i(0)"!]
  [!LOOP "as:modconf('CanIf')[1]/CanIfPublicCfg/CanIfRxProcessing/*"!]
  {
    &SchM_ActMainFunction_CanIf_Rx_[!"node:name(.)"!],
    [!"num:i(CanIfPublicMaxPayloadQueueSize)"!]U,
    [!"$rxPayloadOffset"!]U,
    [!"$rxOffset"!]U,
    [!"num:i(CanIfRxPduQueueSize)"!]U
    [!VAR "rxOffset" = "num:i($rxOffset + CanIfRxPduQueueSize)"!]
    [!VAR "rxPayloadOffset" = "num:i($rxPayloadOffset + CanIfPublicMaxPayloadQueueSize)"!]
  },
  [!ENDLOOP!]
};
/* Deviation MISRAC2012-1 <STOP> */
[!ENDIF!]

#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanIf_MemMap.h>

/*==================[external data]==========================================*/

[!SELECT "as:modconf('CanIf')[1]/CanIfPublicCfg"!]

#define CANIF_START_SEC_VAR_NO_INIT_8
#include <CanIf_MemMap.h>

#if( ( CANIF_WAKEUP_VALIDATION_API == STD_ON ) || \
     ( CANIF_PUBLIC_TXCONFIRM_POLLING_SUPPORT == STD_ON )  || \
     ( CANIF_PUBLIC_PN_SUPPORT == STD_ON) )

/** \brief Controller flags
 **
 ** This array contains the wakeup flags of all configured
 ** controllers. If a bit/flag has the value 1 it is set.
 ** Bit masks are:
 ** CANIF_WAKEUP_MASK             Wakeup flag
 ** CANIF_WAKEUP_VALIDATION_MASK  Wakeup validation flag
 ** CANIF_TX_CONFIRMATION_MASK    Tx confirmation flag
 ** CANIF_PN_FILTER_ACTIVE_MASK   Partial networking filter flag
 */
VAR( uint8, CANIF_VAR )
  CanIf_CanControllerFlags[[!"CanIfPublicMaxCtrl"!]U];

#endif /* ( CANIF_WAKEUP_VALIDATION_API == STD_ON ) || \
          ( CANIF_PUBLIC_TXCONFIRM_POLLING_SUPPORT == STD_ON ) */

[!IF "CanIfPublicReadTxPduNotifyStatusApi = 'true'"!]
/** \brief Bit-array of Tx notification flags (if enabled) */
VAR( uint8, CANIF_VAR )
  CanIf_TxLPduNotifyFlags[([!IF "node:exists(CanIfPublicMaxTxNotifyPdus)"!][!"CanIfPublicMaxTxNotifyPdus"!][!ELSE!]1[!ENDIF!]U+7U)/8U];
[!ENDIF!]

[!IF "CanIfPublicReadRxPduNotifyStatusApi = 'true'"!]
/** \brief Bit-array of Rx notification flags (if enabled) */
VAR( uint8, CANIF_VAR )
  CanIf_RxLPduNotifyFlags[([!IF "node:exists(CanIfPublicMaxRxNotifyPdus)"!][!"CanIfPublicMaxRxNotifyPdus"!][!ELSE!]1[!ENDIF!]U+7U)/8U];
[!ENDIF!]

[!IF "CanIfPublicReadRxPduDataApi = 'true'"!]
/** \brief Array of Rx buffers */
VAR( uint8, CANIF_VAR ) CanIf_RxBuffer[[!IF "node:exists(CanIfPublicMaxRxBuffer)"!][!"CanIfPublicMaxRxBuffer"!][!ELSE!]1[!ENDIF!]U];
[!ENDIF!]

[!IF "CanIfPublicTxBuffering = 'true'"!]
/** \brief Tx buffer memory */
VAR( uint8, CANIF_VAR ) CanIf_TxBufferMemory[[!IF "node:exists(CanIfPublicMaxTxBufferSize)"!][!"CanIfPublicMaxTxBufferSize"!][!ELSE!]1[!ENDIF!]U];
[!ENDIF!]

[!IF "$decoupledRxSupported = 'true'"!]
/** \brief Array of Rx queued data */
VAR( uint8, CANIF_VAR )
  CanIf_RxDataQueue[[!"num:i($canifMaxPayloadQueueSize)"!]U];
[!ENDIF!]

#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include <CanIf_MemMap.h>

#define CANIF_START_SEC_VAR_NO_INIT_16
#include <CanIf_MemMap.h>

[!IF "$decoupledRxSupported"!]
/** \brief Array of Rx queue Indexes
 **
 ** This is the array of Rx queue Indexes used to get the payload index during
 ** message reception if Rx processing is enabled.
 */
VAR( uint16, CANIF_VAR )
  CanIf_MFRxQueueIdx[[!"$numRxMFs"!]U];
[!ENDIF!]

[!IF "$publicTxBufferingSupport = 'true'"!]
/** \brief Array of a HTH's number of pending Tx requests */
VAR( CanIf_TxBufferIndexType, CANIF_VAR )
  CanIf_NrOfPendingTxRequests[[!IF "node:exists(CanIfPublicMaxHths)"!][!"CanIfPublicMaxHths"!][!ELSE!]1[!ENDIF!]U];

/** \brief Pending transmit request buffers
 **
 ** This array stores pending transmit request IDs. It is named as array (8)
 ** in the CAN interface design.
 */
VAR( CanIf_LPduIndexType, CANIF_VAR )
  CanIf_PendingTxBuffers[[!IF "node:exists(CanIfPublicMaxTxBuffers)"!][!"CanIfPublicMaxTxBuffers"!][!ELSE!]1[!ENDIF!]U];
[!ENDIF!]

[!IF "$decoupledRxSupported = 'true'"!]
/** \brief Total size of the queue
 **
 ** This variable shows the current value of the queue of the CAN interface.
 */
VAR( uint16, CANIF_VAR ) CanIf_TotalRxQueueSize[[!"$numRxMFs"!]U];
[!ENDIF!]

[!IF "$txDecoupledSupport = 'true'"!]
/** \brief Total size of the queue
 **
 ** This variable shows the current value of the queue of the CAN interface.
 */
VAR( uint16, CANIF_VAR ) CanIf_TotalTxQueueSize[[!"$numTxMFs"!]U];
[!ENDIF!]

#define CANIF_STOP_SEC_VAR_NO_INIT_16
#include <CanIf_MemMap.h>

#define CANIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include <CanIf_MemMap.h>

VAR( CanIf_ControllerModeType, CANIF_VAR )
  CanIf_CanControllerMode[[!"CanIfPublicMaxCtrl"!]U];

VAR( CanIf_PduModeType, CANIF_VAR )
  CanIf_PduMode[[!"CanIfPublicMaxCtrl"!]U];

[!IF "CanIfPublicSetDynamicTxIdApi"!]
/** \brief Array for dynamic CAN IDs
 **
 ** This array contains the current set CAN ID for dynamic Tx L-PDUs.
 */
 VAR( Can_IdType, CANIF_VAR )
  CanIf_DynamicTxLPduCanIds[[!IF "node:exists(CanIfPublicMaxDynTxPdus)"!][!"CanIfPublicMaxDynTxPdus"!][!ELSE!]1[!ENDIF!]U];
[!ENDIF!]

[!IF "$publicTxBufferingSupport"!]
/** \brief Array of Tx buffers
 **
 ** This is the array of Tx buffers used during message transmission if Tx
 ** buffering is enabled.
 */
VAR( CanIf_TxBufferType, CANIF_VAR )
  CanIf_TxBuffer[[!IF "node:exists(CanIfPublicMaxTxBuffers)"!][!"CanIfPublicMaxTxBuffers"!][!ELSE!]1[!ENDIF!]U];
[!ENDIF!]

[!IF "$txDecoupledSupport"!]
/** \brief Array of Tx queue
 **
 ** This is the array of Tx queue used during message transmission confirmation
 ** if Tx processing is enabled.
 */
VAR( CanIf_TxQueueType, CANIF_VAR )
  CanIf_TxPduQueue[[!"$canifTxPduQueueSize"!]U];
[!ENDIF!]

[!IF "$decoupledRxSupported"!]
/** \brief Array of Rx queue
 **
 ** This is the array of Rx queue used during message reception
 ** if Rx processing is enabled.
 */
VAR( CanIf_RxQueueType, CANIF_VAR )
  CanIf_RxPduQueue[[!"$canifRxPduQueueSize"!]U];
[!ENDIF!]

#define CANIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include <CanIf_MemMap.h>

[!ENDSELECT!]

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

/*==================[end of file]============================================*/
[!ENDCODE!][!//
