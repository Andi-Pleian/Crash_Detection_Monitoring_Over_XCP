/**
 * \file
 *
 * \brief AUTOSAR ComM
 *
 * This file contains the implementation of the AUTOSAR
 * module ComM.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2017 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
[!AUTOSPACING!][!//

/* !LINKSTO ComM503_Refine,1 */

/*==================[inclusions]============================================*/
[!INCLUDE "../include/ComM_Checks.m"!][!//

/* prevent RTE symbols defined in ComM.h to be visible for ComM's .c files */
#if (defined COMM_INTERNAL_USAGE)
#error COMM_INTERNAL_USAGE already defined
#endif
#define COMM_INTERNAL_USAGE

#include <ComM_BSW.h>                   /* public API symbols */
#include <ComM_BSW_Cfg.h>               /* internal BSW config dependent header */

#if (COMM_CANSM_ACCESS_NEEDED == STD_ON)
#include <CanSM_ComM.h>                 /* Can state manager */
#endif

#if (COMM_FRSM_ACCESS_NEEDED == STD_ON)
#include <FrSm.h>                       /* Flexray state manager */
#endif

#if (COMM_LINSM_ACCESS_NEEDED == STD_ON)
#include <LinSM.h>                      /* Lin state manager */
#endif

/*==================[macros]================================================*/

[!SELECT "ComMConfigSet/*[1]"!][!//

[!IF "as:modconf('ComM')[1]/ComMGeneral/ComMPncSupport = 'true'"!]

[!LOOP "ComMPnc/*"!]
[!VAR "count" = "num:i(count(ComMPncComSignal/*[ComMPncComSignalDirection='TX']/ComMPncComSignalRef))"!]
/** \brief Number of Tx EIRA Com Signals mapped to ComMPnc_[!"ComMPncId"!] */
#if (defined COMM_NUM_TX_PNC_[!"ComMPncId"!])
#error COMM_NUM_TX_PNC_[!"ComMPncId"!] already defined
#endif
#define COMM_NUM_TX_PNC_[!"ComMPncId"!]  [!"$count"!]

[!ENDLOOP!]

[!ENDIF!][!//

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[internal constants]====================================*/

#define COMM_START_SEC_CONST_8
#include <MemMap.h>


/*---------------[Partial Network Cluster (PNC)]-----------------*/


[!IF "as:modconf('ComM')[1]/ComMGeneral/ComMPncSupport = 'true'"!][!//

[!/* Get the size of the largest ComSignal (= COMM_PN_INFO_LENGTH) to be able to initialize the
    following arrays completely */!]
[!VAR "SigSize1" = "0"!][!//
[!VAR "SigSize2" = "0"!][!//
[!/* Get the length of the largest Com signal for array-type signals */!]
[!IF "count(node:refs(ComMPnc/*/ComMPncComSignal/*/ComMPncComSignalRef)[text:contains(string(ComSignalType), 'UINT8_')]) != 0"!][!//
[!VAR "SigSize1" = "num:max(node:refs(ComMPnc/*/ComMPncComSignal/*/ComMPncComSignalRef)[text:contains(string(ComSignalType), 'UINT8_')]/ComSignalLength)"!][!//
[!ENDIF!][!//
[!/* Get the length of the largest Com signal for non array-type signals */!]
[!IF "count(node:refs(ComMPnc/*/ComMPncComSignal/*/ComMPncComSignalRef)[not(text:contains(string(ComSignalType), 'UINT8_'))]) != 0"!][!//
[!VAR "SigSize2" = "num:max(node:foreach(node:refs(ComMPnc/*/ComMPncComSignal/*/ComMPncComSignalRef)[not(text:contains(string(ComSignalType), 'UINT8_'))]/ComSignalType, 'SigType', 'node:when($SigType = "BOOLEAN", "8", substring-after($SigType, "T"))')) div 8 "!][!//
[!ENDIF!][!//

[!IF "$SigSize1 < $SigSize2"!][!//
[!VAR "SigSize1" = "num:i($SigSize2)"!][!//
[!ENDIF!][!//

[!VAR "PncMaskLength" = "num:i((num:max(as:modconf('ComM')[1]/ComMConfigSet/*[1]/ComMPnc/*/ComMPncId) div 8) + 1)"!][!//


[!/* Generate a bit mask array for each unique RX EIRA signal */!]
[!LOOP "node:order(node:refs(ComMPnc/*/ComMPncComSignal/*[ComMPncComSignalKind='EIRA']
        [ComMPncComSignalDirection='RX']/ComMPncComSignalRef), 'ComHandleId')"!]

[!/* Save the Signal Handle first */!]
[!VAR "HandleId" = "ComHandleId"!]

/** \brief Array of Rx Eira Com signal masks for Com Signal [!"node:name(.)"!] */
STATIC CONST(uint8, COMM_CONST) ComM_PncRxEiraMask_[!"node:name(.)"!][COMM_PN_INFO_LENGTH] =
{
[!/* Do this for all bytes in the EIRA */!][!//
  [!FOR "I" = "1" TO "$PncMaskLength"!][!//
    [!VAR "Mask" = "0"!][!/*
    Get all PNCs within the range of this byte
    */!][!LOOP "node:order(as:modconf('ComM')[1]/ComMConfigSet/*[1]/ComMPnc/*[ComMPncId >= num:i(($I - 1) * 8) and
            ComMPncId < num:i($I * 8)], 'ComMPncId')"!][!/*
          Check if this PNC contain the selected signal reference
          */!][!IF "node:containsValue(node:refs(ComMPncComSignal/*[ComMPncComSignalKind='EIRA']
          [ComMPncComSignalDirection='RX']/ComMPncComSignalRef)/ComHandleId, $HandleId)"!][!/*
          If so, set the respective bit
          */!][!VAR "Mask" = "bit:bitset($Mask, ComMPncId)"!][!//
      [!ENDIF!][!//
    [!ENDLOOP!][!//
  [!"num:inttohex(bit:shr($Mask, (($I - 1) * 8)))"!]U,
  [!ENDFOR!][!//
  [!/* Initialize the array completely to avoid MISRA warnings */!][!//
  [!FOR "I" = "$PncMaskLength + 1" TO "$SigSize1"!][!//
  0x00U,
  [!ENDFOR!][!//
};
[!ENDLOOP!]

#if(COMM_PNC_GW_ENABLED == STD_ON)
[!/* Generate a bit mask array for each unique RX ERA signal */!]
[!LOOP "node:order(node:refs(ComMPnc/*/ComMPncComSignal/*[ComMPncComSignalKind='ERA']
        [ComMPncComSignalDirection='RX']/ComMPncComSignalRef), 'ComHandleId')"!]

[!/* Save the Signal Handle first */!]
[!VAR "HandleId" = "ComHandleId"!]

/** \brief Array of Rx Era Com signal masks for Com Signal [!"node:name(.)"!] */
STATIC CONST(uint8, COMM_CONST) ComM_PncRxEraMask_[!"node:name(.)"!][COMM_PN_INFO_LENGTH] =
{
[!/* Do this for all bytes in the EIRA */!][!//
  [!FOR "I" = "1" TO "$PncMaskLength"!][!//
    [!VAR "Mask" = "0"!][!/*
    Get all PNCs within the range of this byte
    */!][!LOOP "node:order(as:modconf('ComM')[1]/ComMConfigSet/*[1]/ComMPnc/*[ComMPncId >= num:i(($I - 1) * 8) and
            ComMPncId < num:i($I * 8)], 'ComMPncId')"!][!/*
          Check if this PNC contain the selected signal reference
          */!][!IF "node:containsValue(node:refs(ComMPncComSignal/*[ComMPncComSignalKind='ERA'][as:ref(ComMPncComSignalChannelRef)/ComMPncGatewayType='COMM_GATEWAY_TYPE_ACTIVE']
          [ComMPncComSignalDirection='RX']/ComMPncComSignalRef)/ComHandleId, $HandleId)"!][!/*
          If so, set the respective bit
          */!][!VAR "Mask" = "bit:bitset($Mask, ComMPncId)"!][!//
      [!ENDIF!][!//
    [!ENDLOOP!][!//
  [!"num:inttohex(bit:shr($Mask, (($I - 1) * 8)))"!]U,
  [!ENDFOR!][!//
  [!/* Initialize the array completely to avoid MISRA warnings */!][!//
  [!FOR "I" = "$PncMaskLength + 1" TO "$SigSize1"!][!//
  0x00U,
  [!ENDFOR!][!//
};
[!ENDLOOP!]
#endif

[!/* Generate a bit mask array for each unique TX EIRA signal */!]
[!LOOP "node:order(node:refs(ComMPnc/*/ComMPncComSignal/*
            [ComMPncComSignalDirection='TX']/ComMPncComSignalRef), 'ComHandleId')"!]
[!/* Save the Signal Handle first */!]
[!VAR "HandleId" = "ComHandleId"!]
/** \brief Array of Tx Eira Com signal masks for Com Signal [!"node:name(.)"!] */
STATIC CONST(uint8, COMM_CONST) ComM_PncTxMask_[!"node:name(.)"!][COMM_PN_INFO_LENGTH] =
{
[!/* Do this for all bytes in the EIRA */!][!//
  [!FOR "I" = "1" TO "num:i((num:max(as:modconf('ComM')[1]/ComMConfigSet/*[1]/ComMPnc/*/ComMPncId) div 8) + 1)"!][!//
    [!VAR "Mask" = "0"!][!/*
    Get all PNCs within the range of this byte
    */!][!LOOP "node:order(as:modconf('ComM')[1]/ComMConfigSet/*[1]/ComMPnc/*[ComMPncId >= num:i(($I - 1) * 8) and
            ComMPncId < num:i($I * 8)], 'ComMPncId')"!][!/*
          Check if this PNC contain the selected signal reference
          */!][!IF "node:containsValue(node:refs(ComMPncComSignal/*
          [ComMPncComSignalDirection='TX']/ComMPncComSignalRef)/ComHandleId, $HandleId)"!][!/*
          If so, set the respective bit
          */!][!VAR "Mask" = "bit:bitset($Mask, ComMPncId)"!][!//
      [!ENDIF!][!//
    [!ENDLOOP!][!//
  [!"num:inttohex(bit:shr($Mask, (($I - 1) * 8)))"!]U,
  [!ENDFOR!][!//
  [!/* Initialize the array completely to avoid MISRA warnings */!][!//
  [!FOR "I" = "$PncMaskLength + 1" TO "$SigSize1"!][!//
  0x00U,
  [!ENDFOR!][!//
};
[!ENDLOOP!]
[!ENDIF!][!//


[!LOOP "node:order(ComMPnc/*, 'ComMPncId')"!]
[!IF "num:i(count(ComMPncComSignal/*[ComMPncComSignalDirection='TX']/ComMPncComSignalRef)) != 0"!]
/** \brief List of Tx Eira Com signals mapped to ComMPnc_[!"ComMPncId"!] */
STATIC CONST(uint8, COMM_CONST) ComM_TxSig_Pnc_[!"ComMPncId"!][COMM_NUM_TX_PNC_[!"ComMPncId"!]] =
{
[!LOOP "node:order(node:refs(ComMPncComSignal/*[ComMPncComSignalDirection='TX']/ComMPncComSignalRef), 'ComHandleId')"!]
[!VAR "HandleId" = "ComHandleId"!]
[!VAR "SigIndex" = "0"!]
[!LOOP "node:order(node:refs(as:modconf('ComM')[1]/ComMConfigSet/*[1]/ComMPnc/*/ComMPncComSignal/*[ComMPncComSignalDirection='TX']/ComMPncComSignalRef), 'ComHandleId')"!]
[!IF "ComHandleId = $HandleId"!]
  [!"num:i($SigIndex)"!], /* [!"node:name(.)"!] */
[!ENDIF!]
[!VAR "SigIndex" = "$SigIndex + 1"!]
[!ENDLOOP!]
[!ENDLOOP!]
};
[!ENDIF!][!//
[!ENDLOOP!][!//

#define COMM_STOP_SEC_CONST_8
#include <MemMap.h>


/*==================[external constants]====================================*/

#define COMM_START_SEC_CONST_8
#include <MemMap.h>

[!IF "count(ComMChannel/*) > 1"!][!//

CONST(NetworkHandleType, COMM_CONST)
  ComM_NmChannelOfChannel[COMM_NUM_CHANNELS] =
{
[!LOOP "node:order(ComMChannel/*, 'ComMChannelId')"!][!//
[!IF "(ComMNetworkManagement/ComMNmVariant = 'FULL') or (ComMNetworkManagement/ComMNmVariant = 'PASSIVE')"!][!//
  [!"num:i(as:modconf('Nm')[1]/NmChannelConfig/*[as:ref(NmComMChannelRef)/ComMChannelId = node:current()/ComMChannelId]/NmChannelId)"!]U,
[!ELSE!][!//
  /* ComM channel [!"name(.)"!], ID=[!"ComMChannelId"!]
   * not associated with NM channel, NM never used */
  0xFFU,
[!ENDIF!][!//
[!ENDLOOP!][!//
};

[!ENDIF!][!//

[!IF "as:modconf('ComM')[1]/ComMGeneral/ComMWakeupInhibitionEnabled = 'true'"!]
CONST(uint8, COMM_CONST)
  ComM_EB_NoWakeupNvStorage[COMM_NUM_BYTES_NVM] =
{
[!VAR "VarNoWakeupNvStorage" = "0"!][!//
[!LOOP "node:order(ComMChannel/*, 'ComMChannelId')"!][!//
  [!IF "ComMGlobalNvmBlockDescriptor = 'true'"!][!//
   [!VAR "VarNoWakeupNvStorage" = "bit:or($VarNoWakeupNvStorage,bit:shl(1,num:i(ComMChannelId mod 8)))"!][!//
  [!ENDIF!][!//
  [!IF "((ComMChannelId + 1) mod 8) = 0 "!][!//
    [!"num:i($VarNoWakeupNvStorage)"!]U,
    [!VAR "VarNoWakeupNvStorage" = "0"!][!//
  [!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "((node:order(ComMChannel/*, 'ComMChannelId')[last()]/ComMChannelId + 1) mod 8) != 0"!]
  [!"num:i($VarNoWakeupNvStorage)"!]U
[!ENDIF!][!//
};
[!ENDIF!][!//

[!IF "count(ComMPnc/*) > 0"!][!//

/** \brief List of Pnc Ids */
CONST(PNCHandleType, COMM_CONST) ComM_PncID[COMM_NUM_PNC] =
{
[!LOOP "node:order(ComMPnc/*, 'ComMPncId')"!][!//
  [!"ComMPncId"!], /* for PNC [!"name(.)"!] */
[!ENDLOOP!][!//
};

CONST(boolean, COMM_CONST)
  ComM_PncNmRequest[COMM_NUM_CHANNELS] =
{
[!LOOP "node:order(ComMChannel/*, 'ComMChannelId')"!][!//
[!IF "ComMNetworkManagement/ComMPncNmRequest = 'true'"!][!//
 TRUE,
[!ELSE!][!//
 FALSE,
[!ENDIF!][!//
[!ENDLOOP!][!//
};

[!ENDIF!][!//

#define COMM_STOP_SEC_CONST_8
#include <MemMap.h>

#define COMM_START_SEC_CONST_16
#include <MemMap.h>

/* Main function period in ms for each channel */
CONST(uint16, COMM_CONST) ComM_MainFunctionPeriodMs[COMM_NUM_CHANNELS] =
{
[!LOOP "node:order(ComMChannel/*, 'ComMChannelId')"!][!//
  [!"num:i(ComMMainFunctionPeriod * 1000)"!]U, /* for channel [!"name(.)"!] */
[!ENDLOOP!][!//
};

#if ((COMM_NM_VARIANT_LIGHT_NEEDED == STD_ON)      \
     || (COMM_NM_VARIANT_NONE_NEEDED == STD_ON))
/* Timeout after which state "NetReqNoNm" is left when ComMNmVariant='LIGHT' or
 * 'NONE' */
CONST(uint16, COMM_CONST) ComM_NetReqNoNmTimeoutMs[COMM_NUM_CHANNELS] =
{
[!LOOP "node:order(ComMChannel/*, 'ComMChannelId')"!][!//
  /* for channel [!"name(.)"!] */
[!IF "(ComMNetworkManagement/ComMNmVariant = 'LIGHT') or (ComMNetworkManagement/ComMNmVariant = 'NONE')"!][!//
  [!"num:i((../../../../ComMGeneral/ComMTMinFullComModeDuration * 1000) div (ComMMainFunctionPeriod * 1000))"!]U, /* Nm variant 'LIGHT' or 'NONE' */
[!ELSE!][!//
  0xFFU, /* channel with real bus NM support, value never used */
[!ENDIF!][!//
[!ENDLOOP!][!//
};
#endif

#if (COMM_NM_VARIANT_LIGHT_NEEDED == STD_ON)
/* Timeout after which state "ready sleep" is left in ComMNmVariant=LIGHT */
CONST(uint16, COMM_CONST) ComM_ReadySleepNoNmTimeoutMs[COMM_NUM_CHANNELS] =
{
[!LOOP "node:order(ComMChannel/*, 'ComMChannelId')"!][!//
  /* for channel [!"name(.)"!] */
[!IF "(ComMNetworkManagement/ComMNmVariant = 'LIGHT')"!][!//
  [!"num:i((ComMNetworkManagement/ComMNmLightTimeout * 1000) div (ComMMainFunctionPeriod * 1000))"!]U, /* Nm variant LIGHT */
[!ELSEIF "(ComMNetworkManagement/ComMNmVariant = 'NONE')"!][!//
  0U,    /* Nm variant NONE, "ready sleep" state is instantly left */
[!ELSE!][!//
  0xFFU, /* channel with real bus NM support, value never used */
[!ENDIF!][!//
[!ENDLOOP!][!//
};
#endif

[!IF "as:modconf('ComM')[1]/ComMGeneral/ComMPncSupport = 'true'"!]
CONST(Com_SignalIdType, COMM_CONST) ComM_RxComSignalEiraCfg[COMM_NUM_RX_EIRA_SIGNALS] =
{
[!LOOP "node:order(node:refs(ComMPnc/*/ComMPncComSignal/*[ComMPncComSignalKind='EIRA']
        [ComMPncComSignalDirection='RX']/ComMPncComSignalRef), 'ComHandleId')"!]
  [!"ComHandleId"!],  /* [!"node:name(.)"!] */
[!ENDLOOP!][!//
};

#if(COMM_PNC_GW_ENABLED == STD_ON)
CONST(Com_SignalIdType, COMM_CONST) ComM_RxComSignalEraCfg[COMM_NUM_RX_ERA_SIGNALS] =
{
[!LOOP "node:order(node:refs(ComMPnc/*/ComMPncComSignal/*[ComMPncComSignalKind='ERA']
        [ComMPncComSignalDirection='RX']/ComMPncComSignalRef), 'ComHandleId')"!]
  [!"ComHandleId"!],  /* [!"node:name(.)"!] */
[!ENDLOOP!][!//
};
#endif

#if (COMM_NUM_TX_SIGNALS > 0U)
CONST(Com_SignalIdType, COMM_CONST) ComM_TxComSignalCfg[COMM_NUM_TX_SIGNALS] =
{
[!LOOP "node:order(node:refs(ComMPnc/*/ComMPncComSignal/*[ComMPncComSignalDirection='TX']/ComMPncComSignalRef), 'ComHandleId')"!]
  [!"ComHandleId"!], /* [!"node:name(.)"!] */
[!ENDLOOP!]
};
#endif /* (COMM_NUM_TX_SIGNALS > 0U) */
[!ENDIF!][!//

#define COMM_STOP_SEC_CONST_16
#include <MemMap.h>

#define COMM_START_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

[!IF "as:modconf('ComM')[1]/ComMGeneral/ComMModeLimitationEnabled = 'true'"!][!//
CONST(ComM_ASR40_InhibitionStatusType, COMM_CONST)
  ComM_ChannelInhibitionStatusInit[COMM_NUM_BYTES_NVM] =
{
[!VAR "VarComMNoCom" = "0"!][!//
[!LOOP "node:order(ComMChannel/*, 'ComMChannelId')"!][!//
  [!IF "ComMNoCom = 'true'"!][!//
   [!VAR "VarComMNoCom" = "bit:or($VarComMNoCom,bit:shl(1,num:i(ComMChannelId mod 8)))"!][!//
  [!ENDIF!][!//
  [!IF "((ComMChannelId + 1) mod 8) = 0"!][!//
    [!"num:i($VarComMNoCom)"!]U,
    [!VAR "VarComMNoCom" = "0"!][!//
  [!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "((node:order(ComMChannel/*, 'ComMChannelId')[last()]/ComMChannelId + 1) mod 8) != 0"!]
  [!"num:i($VarComMNoCom)"!]U
[!ENDIF!][!//
};
[!ENDIF!][!//

[!IF "(as:modconf('ComM')[1]/ComMGeneral/ComMModeLimitationEnabled = 'true') or (as:modconf('ComM')[1]/ComMGeneral/ComMWakeupInhibitionEnabled = 'true')"!][!//
CONST(ComM_NvDataType, COMM_CONST) ComM_EB_NvROM =
{
  0U, /* InhibitionCounter */
  [!"num:i(as:modconf('ComM')[1]/ComMGeneral/ComMEcuGroupClassification)"!]U, /* ECUGroupClassification */
[!IF "(as:modconf('ComM')[1]/ComMGeneral/ComMWakeupInhibitionEnabled = 'true')"!][!//
  { /* ChannelWakeUpInhibition array */
[!VAR "VarComMNoWakeup" = "0"!][!//
[!LOOP "node:order(ComMChannel/*, 'ComMChannelId')"!][!//
  [!IF "ComMNoWakeup = 'true'"!][!//
    [!VAR "VarComMNoWakeup" = "bit:or($VarComMNoWakeup,bit:shl(1,num:i(ComMChannelId mod 8)))"!][!//
  [!ENDIF!][!//
  [!IF "((ComMChannelId + 1) mod 8) = 0"!][!//
    [!"num:i($VarComMNoWakeup)"!]U,
    [!VAR "VarComMNoWakeup" = "0"!][!//
  [!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "((node:order(ComMChannel/*, 'ComMChannelId')[last()]/ComMChannelId + 1) mod 8) != 0"!]
  [!"num:i($VarComMNoWakeup)"!]U
[!ENDIF!][!//
  }
[!ENDIF!][!//
};
[!ENDIF!][!//


[!IF "as:modconf('ComM')[1]/ComMGeneral/ComMPncSupport = 'true'"!]

#if (COMM_NUM_TX_SIGNALS > 0U)
CONST(ComM_PncTxSigMapType, COMM_CONST) ComM_PncTxSignalMap[COMM_NUM_PNC] =
{
[!LOOP "node:order(ComMPnc/*, 'ComMPncId')"!]
  /* [!"node:name(.)"!] */
  {
    [!IF "num:i(count(ComMPncComSignal/*[ComMPncComSignalDirection='TX']/ComMPncComSignalRef)) != 0"!][!//
    ComM_TxSig_Pnc_[!"ComMPncId"!],      /* TxSignalList */
    [!ELSE!][!//
    NULL_PTR,
    [!ENDIF!][!//
    COMM_NUM_TX_PNC_[!"ComMPncId"!]     /* NumTxSignal */
  },
[!ENDLOOP!]
};
#endif /* (COMM_NUM_TX_SIGNALS > 0U) */

CONSTP2CONST(uint8, COMM_CONST, COMM_CONST) ComM_PncRxEiraMask[COMM_NUM_RX_EIRA_SIGNALS] =
{
[!LOOP "node:order(node:refs(ComMPnc/*/ComMPncComSignal/*[ComMPncComSignalKind='EIRA']
        [ComMPncComSignalDirection='RX']/ComMPncComSignalRef), 'ComHandleId')"!]
  /* Com Signal: [!"node:name(.)"!] */
  ComM_PncRxEiraMask_[!"node:name(.)"!],
[!ENDLOOP!]
};

#if(COMM_PNC_GW_ENABLED == STD_ON)
CONSTP2CONST(uint8, COMM_CONST, COMM_CONST) ComM_PncRxEraMask[COMM_NUM_RX_ERA_SIGNALS] =
{
[!LOOP "node:order(node:refs(ComMPnc/*/ComMPncComSignal/*[ComMPncComSignalKind='ERA']
        [ComMPncComSignalDirection='RX']/ComMPncComSignalRef), 'ComHandleId')"!]
  /* Com Signal: [!"node:name(.)"!] */
  ComM_PncRxEraMask_[!"node:name(.)"!],
[!ENDLOOP!]
};
#endif

#if (COMM_NUM_TX_SIGNALS > 0U)
CONSTP2CONST(uint8, COMM_CONST, COMM_CONST) ComM_PncTxMask[COMM_NUM_TX_SIGNALS] =
{
[!LOOP "node:order(node:refs(ComMPnc/*/ComMPncComSignal/*
        [ComMPncComSignalDirection='TX']/ComMPncComSignalRef), 'ComHandleId')"!]
  /* Com Signal: [!"node:name(.)"!] */
  ComM_PncTxMask_[!"node:name(.)"!],
[!ENDLOOP!]
};
#endif /* (COMM_NUM_TX_SIGNALS > 0U) */

[!ENDIF!]

#define COMM_STOP_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

[!ENDSELECT!][!//

/*==================[internal data]=========================================*/

/*==================[external data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/
