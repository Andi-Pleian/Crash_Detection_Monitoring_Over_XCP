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
 * Copyright 2005 - 2017 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */


#if (!defined CANIF_CFG_H)
#define CANIF_CFG_H


/*==================[includes]===============================================*/
#include <TSAutosar.h>          /* EB specific standard types */
#include <ComStack_Types.h>     /* Autosar standard types */


/* It is required by AUTOSAR include the headerfile that contains the post-build/link-time symbolic IDs here */
/* This mixture of config classes can be omitted for module internal purposes */
#if !defined CANIF_NO_CFGCLASSMIX_REQUIRED
#include <CanIf_SymbolicNames_PBcfg.h>
#endif /* CANIF_NO_CFGCLASSMIX_REQUIRED */

#undef CANIF_NO_CFGCLASSMIX_REQUIRED

/*==================[macros]=================================================*/

/** \brief switch reports that PbcfgM uses CanIf */
   
#if (defined CANIF_PBCFGM_SUPPORT_ENABLED)
#error CANIF_PBCFGM_SUPPORT_ENABLED already defined!
#endif /* #if( defined CANIF_PBCFGM_SUPPORT_ENABLED)*/
#define CANIF_PBCFGM_SUPPORT_ENABLED     STD_OFF

/** \brief switch reports that CanIf_IsValidConfig function shall be mapped to memory section CANIF_CODE_CC_BLOCK
*/
#if (defined CANIF_ISVALIDCONFIG_MMAP_ENABLED)
#error CANIF_ISVALIDCONFIG_MMAP_ENABLED already defined!
#endif /* #if( defined CANIF_ISVALIDCONFIG_MMAP_ENABLED)*/
#define CANIF_ISVALIDCONFIG_MMAP_ENABLED STD_OFF


/** \brief Switch for DET usage */
#if (defined CANIF_DEV_ERROR_DETECT)
#error CANIF_DEV_ERROR_DETECT already defined!
#endif /* #if( defined CANIF_DEV_ERROR_DETECT)*/
#define CANIF_DEV_ERROR_DETECT   STD_ON

/** \brief Support of CanIf_GetVersionInfo()
 **
 ** This constant defines whether the CanIf_GetVersionInfo is
 ** provided.
 ** STD_ON    Function is provided
 ** STD_OFF   Function is not provided
 */
#if (defined CANIF_VERSION_INFO_API)
#error CANIF_VERSION_INFO_API already defined!
#endif /* #if( defined CANIF_VERSION_INFO_API)*/
#define CANIF_VERSION_INFO_API   STD_OFF

/** \brief support of API CanIf_SetBaudrate()
 **
 ** This constant defines whether the API function CanIf_SetBaudrate() is
 ** provided.
 ** STD_ON    Function is provided
 ** STD_OFF   Function is not provided
 */
#if (defined CANIF_SET_BAUDRATE_API)
#error CANIF_SET_BAUDRATE_API already defined!
#endif /* #if( defined CANIF_SET_BAUDRATE_API)*/
#define CANIF_SET_BAUDRATE_API   STD_OFF

/** \brief pre-compile switch defining whether CanIfPublicCanIdTypeEnum is set to UINT32 or not.
 **
 ** This constant defines whether the API function CanIf_SetBaudrate() is
 ** provided.
 ** STD_ON    CanIfPublicCanIdTypeEnum is UINT32
 ** STD_OFF   CanIfPublicCanIdTypeEnum is UINT16
 */
#if (defined CANIF_CANIDTYPE_UINT32)
#error CANIF_CANIDTYPE_UINT32 already defined!
#endif /* #if( defined CANIF_CANIDTYPE_UINT32)*/
#define CANIF_CANIDTYPE_UINT32   STD_ON

/** \brief support of API CanIf_CancelTransmit()
 **
 ** This constant defines whether the API function CanIf_CancelTransmit() is
 ** provided.
 ** STD_ON    Function is provided
 ** STD_OFF   Function is not provided
 */
#if (defined CANIF_CANCEL_TRANSMIT_SUPPORT)
#error CANIF_CANCEL_TRANSMIT_SUPPORT already defined!
#endif /* #if( defined CANIF_CANCEL_TRANSMIT_SUPPORT)*/
#define CANIF_CANCEL_TRANSMIT_SUPPORT   STD_OFF

/** \brief Support of API CanIf_GetTxConfirmationState()
 **
 ** This constant defines whether the API function CanIf_GetTxConfirmationState()
 ** is provided.
 ** STD_ON    Function is provided
 ** STD_OFF   Function is not provided
 */
#if (defined CANIF_PUBLIC_TXCONFIRM_POLLING_SUPPORT)
#error CANIF_PUBLIC_TXCONFIRM_POLLING_SUPPORT already defined!
#endif /* #if( defined CANIF_PUBLIC_TXCONFIRM_POLLING_SUPPORT)*/
#define CANIF_PUBLIC_TXCONFIRM_POLLING_SUPPORT   STD_OFF

/** \brief Support of CanIf_TxConfirmation() callback function
 **
 ** This constant defines whether the callback CanIf_TxConfirmation() is
 ** provided.
 ** STD_ON    Function is provided
 ** STD_OFF   Function is not provided
 */
#if (defined CANIF_TX_CONFIRMATION_CB)
#error CANIF_TX_CONFIRMATION_CB already defined!
#endif /* #if( defined CANIF_TX_CONFIRMATION_CB)*/
#define CANIF_TX_CONFIRMATION_CB               STD_ON


/** \brief Support of CanIf_RxIndication() callback function
 **
 ** This constant defines whether the callback CanIf_RxIndication() is
 ** provided.
 ** STD_ON    Function is provided
 ** STD_OFF   Function is not provided
 */
#if (defined CANIF_RX_INDICATION_CB)
#error CANIF_RX_INDICATION_CB already defined!
#endif /* #if( defined CANIF_RX_INDICATION_CB)*/
#define CANIF_RX_INDICATION_CB                 STD_ON


/** \brief Support of CanIf_CancelTxConfirmation() callback function
 **
 ** This constant defines whether the callback CanIf_CancelTxConfirmation()
 ** is provided.
 ** STD_ON    Function is provided
 ** STD_OFF   Function is not provided
 */
#if (defined CANIF_CANCEL_TX_CONFIRMATION_CB)
#error CANIF_CANCEL_TX_CONFIRMATION_CB already defined!
#endif /* #if( defined CANIF_CANCEL_TX_CONFIRMATION_CB)*/
#define CANIF_CANCEL_TX_CONFIRMATION_CB           STD_OFF

/** \brief Support of wakeup API
 **
 ** This constant defines whether the wakeup APIs are provided.
 ** STD_ON    Function is provided
 ** STD_OFF   Function is not provided
 */
#if (defined CANIF_WAKEUP_SUPPORT_API)
#error CANIF_WAKEUP_SUPPORT_API already defined!
#endif /* #if( defined CANIF_WAKEUP_SUPPORT_API)*/
#define CANIF_WAKEUP_SUPPORT_API   STD_OFF

/** \brief Support of wakeup validation API
 **
 ** This constant defines whether wakeup validation API is provided.
 ** STD_ON    Function is provided
 ** STD_OFF   Function is not provided
 */
#if (defined CANIF_WAKEUP_VALIDATION_API)
#error CANIF_WAKEUP_VALIDATION_API already defined!
#endif /* #if( defined CANIF_WAKEUP_VALIDATION_API)*/
#define CANIF_WAKEUP_VALIDATION_API   STD_OFF

/** \brief Support of function CanIf_SetDynamicTxId()
 **
 ** This constant defines whether CanIf_SetDynamicTxId() is supported.
 ** STD_ON    Function is provided
 ** STD_OFF   Function is not provided
 */
#if (defined CANIF_SETDYNAMICTXID_API)
#error CANIF_SETDYNAMICTXID_API already defined!
#endif /* #if( defined CANIF_SETDYNAMICTXID_API)*/
#define CANIF_SETDYNAMICTXID_API   STD_OFF

/** \brief Support of function CanIf_ReadRxPduData()
 **
 ** This constant defines whether CanIf_ReadRxPduData() is supported.
 ** STD_ON    Function is provided
 ** STD_OFF   Function is not provided
 */
#if (defined CANIF_READRXPDU_DATA_API)
#error CANIF_READRXPDU_DATA_API already defined!
#endif /* #if( defined CANIF_READRXPDU_DATA_API)*/
#define CANIF_READRXPDU_DATA_API   STD_OFF

/** \brief Support of function CanIf_ReadRxNotifStatus()
 **
 ** This constant defines whether CanIf_ReadRxNotifStatus() is supported.
 ** STD_ON    Function is provided
 ** STD_OFF   Function is not provided
 */
#if (defined CANIF_READRXPDU_NOTIF_STATUS_API)
#error CANIF_READRXPDU_NOTIF_STATUS_API already defined!
#endif /* #if( defined CANIF_READRXPDU_NOTIF_STATUS_API)*/
#define CANIF_READRXPDU_NOTIF_STATUS_API   STD_OFF

/** \brief Support of function CanIf_ReadTxNotifStatus()
 **
 ** This constant defines whether CanIf_ReadTxNotifStatus() is supported.
 ** STD_ON    Function is provided
 ** STD_OFF   Function is not provided
 */
#if (defined CANIF_READTXPDU_NOTIF_STATUS_API)
#error CANIF_READTXPDU_NOTIF_STATUS_API already defined!
#endif /* #if( defined CANIF_READTXPDU_NOTIF_STATUS_API)*/
#define CANIF_READTXPDU_NOTIF_STATUS_API   STD_OFF

/** \brief Support of range reception
 **
 ** This constant defines if range reception is configured and used.
 ** STD_ON    Range reception is used
 ** STD_OFF   No reception range is used
 */
#if (defined CANIF_RANGE_RECEPTION)
#error CANIF_RANGE_RECEPTION already defined!
#endif /* #if( defined CANIF_RANGE_RECEPTION)*/
#define CANIF_RANGE_RECEPTION   STD_ON

/** \brief Support of CanTrcv
 **
 ** This constant defines if transceivers are supported
 ** this configuration.
 */
#if (defined CANIF_TRCV_SUPPORT)
#error CANIF_TRCV_SUPPORT already defined!
#endif /* #if( defined CANIF_TRCV_SUPPORT)*/
#define CANIF_TRCV_SUPPORT   STD_OFF

/** \brief CanIf partial networking support
 **
 ** This macro defines if API functions for partial networking are exported.
 */
#if (defined CANIF_PUBLIC_PN_SUPPORT)
#error CANIF_PUBLIC_PN_SUPPORT already defined!
#endif /* #if( defined CANIF_PUBLIC_PN_SUPPORT)*/
#define CANIF_PUBLIC_PN_SUPPORT   STD_OFF

/** \brief CanIfTxOfflineActiveSupport
 **
 ** This macro defines if CanIfTxOfflineActiveSupport is enabled or not.
 */
#define CANIF_TX_OFFLINE_ACTIVE_SUPPORT   STD_OFF

/** \brief CanIf tx buffering support
 **
 ** This macro defines if tx buffering is enabled or not.
 */
#if (defined CANIF_PUBLIC_TX_BUFFERING)
#error CANIF_PUBLIC_TX_BUFFERING already defined!
#endif /* #if( defined CANIF_PUBLIC_TX_BUFFERING)*/
#define CANIF_PUBLIC_TX_BUFFERING   STD_OFF

/** \brief DLC check switch
 **
 ** This constant defines whether the DLC check is used or not.
 ** STD_ON    DLC check is enabled
 ** STD_OFF   DLC check is disabled
 */
#if (defined CANIF_DLC_CHECK_ENABLED)
#error CANIF_DLC_CHECK_ENABLED already defined!
#endif /* #if( defined CANIF_DLC_CHECK_ENABLED)*/
#define CANIF_DLC_CHECK_ENABLED   STD_ON

/** \brief Single CAN controller optimization switch
 **
 ** This constant defines, if the CanIf single controller optimization is
 ** switched on.
 */
#if (defined CANIF_SINGLE_CAN_CTRL_OPT)
#error CANIF_SINGLE_CAN_CTRL_OPT already defined!
#endif /* #if( defined CANIF_SINGLE_CAN_CTRL_OPT)*/
#define CANIF_SINGLE_CAN_CTRL_OPT   STD_OFF

/** \brief HOH translation optimization
 **
 ** This constant defines, if the HOH translation optimization is enabled.
 ** It is enabled, if the HOH IDs are zero-based and consecutive and all HRH
 ** IDs are lower than the HTH IDs.
 */
#if (defined CANIF_HOH_TRANSLATION_OPT)
#error CANIF_HOH_TRANSLATION_OPT already defined!
#endif /* #if( defined CANIF_HOH_TRANSLATION_OPT)*/
#define CANIF_HOH_TRANSLATION_OPT   STD_OFF

/** \brief Switch for <UL>_RxIndication support
 **
 ** This switch defines, if CanIf uses the <UL>_RxIndcation function of any of the upper layer
 */
#if (defined CANIF_UL_RX_INDICATION_SUPPORT)
#error CANIF_UL_RX_INDICATION_SUPPORT already defined!
#endif /* #if( defined CANIF_UL_RX_INDICATION_SUPPORT)*/
#define CANIF_UL_RX_INDICATION_SUPPORT   STD_ON

/** \brief Switch for <Cdd>_RxIndication support
 **
 ** This switch defines, if CanIf uses the <Cdd>_RxIndcation function of any of the upper layer
 */
#if (defined CANIF_CDD_RX_INDICATION_SUPPORT)
#error CANIF_CDD_RX_INDICATION_SUPPORT already defined!
#endif /* #if( defined CANIF_CDD_RX_INDICATION_SUPPORT)*/
#define CANIF_CDD_RX_INDICATION_SUPPORT   STD_OFF

/** \brief Switch for <UL>_TxConfirmation support
 **
 ** This switch defines, if CanIf uses the <UL>_TxConfirmation function of any of the upper layer
 */
#if (defined CANIF_TX_CONFIRMATION_SUPPORT)
#error CANIF_TX_CONFIRMATION_SUPPORT already defined!
#endif /* #if( defined CANIF_TX_CONFIRMATION_SUPPORT)*/
#define CANIF_TX_CONFIRMATION_SUPPORT   STD_ON

/** \brief Switch for DLC error notification support
 **
 ** This switch defines, if DLC error notification functions are supported.
 */
#if (defined CANIF_DLC_ERROR_NOTIF_SUPPORT)
#error CANIF_DLC_ERROR_NOTIF_SUPPORT already defined!
#endif /* #if( defined CANIF_DLC_ERROR_NOTIF_SUPPORT)*/
#define CANIF_DLC_ERROR_NOTIF_SUPPORT   STD_OFF

/** \brief Switch for DLC check passed notification support
 **
 ** This switch defines, if DLC check passed notification functions are
 ** supported.
 */
#if (defined CANIF_DLC_PASSED_NOTIF_SUPPORT)
#error CANIF_DLC_PASSED_NOTIF_SUPPORT already defined!
#endif /* #if( defined CANIF_DLC_PASSED_NOTIF_SUPPORT)*/
#define CANIF_DLC_PASSED_NOTIF_SUPPORT   STD_OFF

/** \brief Any callback function of any upper layer used
 **
 ** This macro defines if at least one upper layer of the CanIf
 ** shall be notified via any callback function (which are
 ** <UL>_RxIndication, <CDD>_RxIndication, <UL>_TxConfirmation,
 ** DLC error and DLC passed).
 */
#if (defined CANIF_ANY_UL_CBK_SUPPORT)
#error CANIF_ANY_UL_CBK_SUPPORT already defined!
#endif /* #if( defined CANIF_ANY_UL_CBK_SUPPORT)*/
#define CANIF_ANY_UL_CBK_SUPPORT   STD_ON

/** \brief Switch for wakeup validation by NM
 **
 ** This switch defines, if wakeup validation is allowed by each Rx PDU (value
 ** STD_OFF) or if wakeup validation is only performed for (Can)Nm PDUs (value
 ** STD_ON).
 */
#if (defined CANIF_WAKEUP_CHECK_VALID_BY_NM)
#error CANIF_WAKEUP_CHECK_VALID_BY_NM already defined!
#endif /* #if( defined CANIF_WAKEUP_CHECK_VALID_BY_NM)*/
#define CANIF_WAKEUP_CHECK_VALID_BY_NM   STD_OFF

/** \brief Index of Nm as upper layer
 **
 ** This symbol defines the index of the module CanNm as upper layer in the upper
 ** layer configuration map.
 */
#if (defined CANIF_NM_UPPER_LAYER_INDEX)
#error CANIF_NM_UPPER_LAYER_INDEX already defined!
#endif /* #if( defined CANIF_NM_UPPER_LAYER_INDEX)*/
#define CANIF_NM_UPPER_LAYER_INDEX   CANIF_NO_UPPER_LAYER_CALLBACK

/** \brief CAN controller wakeup support
 **
 ** This macro defines if wakeup by CAN controllers is supported.
 */
#if (defined CANIF_CAN_WAKEUP_SUPPORT)
#error CANIF_CAN_WAKEUP_SUPPORT already defined!
#endif /* #if( defined CANIF_CAN_WAKEUP_SUPPORT)*/
#define CANIF_CAN_WAKEUP_SUPPORT   STD_OFF

/** \brief CAN transceiver wakeup support
 **
 ** This macro defines if wakeup by CAN transceivers is supported.
 */
#if (defined CANIF_CANTRCV_WAKEUP_SUPPORT)
#error CANIF_CANTRCV_WAKEUP_SUPPORT already defined!
#endif /* #if( defined CANIF_CANTRCV_WAKEUP_SUPPORT)*/
#define CANIF_CANTRCV_WAKEUP_SUPPORT   STD_OFF

/** \brief CAN ASR 4.0 rev 2 compatibility
 **
 ** This macro defines if CanIf supports CAN ASR 4.0 rev 2.
 */
#if (defined CANIF_CAN_REV2_COMPATIBILITY)
#error CANIF_CAN_REV2_COMPATIBILITY already defined!
#endif /* #if( defined CANIF_CAN_REV2_COMPATIBILITY)*/
#define CANIF_CAN_REV2_COMPATIBILITY   STD_OFF

 /** \brief CAN ASR 4.2 rev 2 compatibility
  **
  ** This macro defines if CanIf supports CAN ASR 4.2 rev 2.
  */
#if (defined CANIF_CAN_REV422_COMPATIBILITY)
#error CANIF_CAN_REV422_COMPATIBILITY already defined!
#endif /* #if( defined CANIF_CAN_REV422_COMPATIBILITY)*/
#define CANIF_CAN_REV422_COMPATIBILITY   STD_ON

/** \brief Macro for bus-off callback function
 **
 ** This macro shall be used for calling the bus-off notification function.
 */
#if (defined CANIF_BUSOFF_CALLBACK)
#error CANIF_BUSOFF_CALLBACK already defined!
#endif /* #if( defined CANIF_BUSOFF_CALLBACK)*/
#define CANIF_BUSOFF_CALLBACK( Controller ) \
    CanSM_ControllerBusOff( (Controller) )


/** \brief Macro for controller mode indication callback function
**
** This macro shall be used for calling the controller mode indication function.
*/
#if (defined CANIF_CTRLMODEINDICATION_CALLBACK)
#error CANIF_CTRLMODEINDICATION_CALLBACK already defined!
#endif /* #if( defined CANIF_CTRLMODEINDICATION_CALLBACK)*/
#define CANIF_CTRLMODEINDICATION_CALLBACK( Controller , ControllerMode) \
    CanSM_ControllerModeIndication( (Controller), (ControllerMode) )


/** \brief Macro for transceiver mode indication callback function
**
** This macro shall be used for calling the transceiver mode indication function.
*/
#if (defined CANIF_TRCVMODEINDICATION_CALLBACK)
#error CANIF_TRCVMODEINDICATION_CALLBACK already defined!
#endif /* #if( defined CANIF_TRCVMODEINDICATION_CALLBACK)*/
#define CANIF_TRCVMODEINDICATION_CALLBACK( Transceiver , TransceiverMode) \
    CanSM_TransceiverModeIndication( (Transceiver), (TransceiverMode) )


#if CANIF_PUBLIC_PN_SUPPORT == STD_ON
/** \brief Macro for confirm PN availability callback function
**
** This macro shall be used for calling the confirm PN availability function.
*/
#if (defined CANIF_CONFIRMPNAVAILABILITY_CALLBACK)
#error CANIF_CONFIRMPNAVAILABILITY_CALLBACK already defined!
#endif /* #if( defined CANIF_CONFIRMPNAVAILABILITY_CALLBACK)*/
#define CANIF_CONFIRMPNAVAILABILITY_CALLBACK( Transceiver) \
    CanSM_ConfirmPnAvailability( Transceiver )




#endif /* CANIF_PUBLIC_PN_SUPPORT */


/** \brief Macro for calling the upper layer wakeup notification function
 **
 ** This macro shall be used for calling the configured upper layer wakeup
 ** notification function.
 */

#if (defined CANIF_SET_WAKEUP_EVENT)
#error CANIF_SET_WAKEUP_EVENT already defined!
#endif /* #if( defined CANIF_SET_WAKEUP_EVENT)*/
#define CANIF_SET_WAKEUP_EVENT( Sources )


/** \brief Macro for calling the upper layer wakeup validation function
 **
 ** This macro shall be used for calling the configured upper layer wakeup
 ** validation function.
 */

#if (defined CANIF_VALIDATE_WAKEUP_EVENT)
#error CANIF_VALIDATE_WAKEUP_EVENT already defined!
#endif /* #if( defined CANIF_VALIDATE_WAKEUP_EVENT)*/
#define CANIF_VALIDATE_WAKEUP_EVENT( Sources )


/** \def CANIF_TL_TX_CAN_ID_SUPPORT
 **
 ** \brief Switch for Tx CAN ID translation
 **
 ** This switch defines, if Tx CAN ID translation is supported.
 */

/** \def CANIF_TRANSLATE_TX_CAN_ID(CanId)
 **
 ** \brief Translate Tx CAN ID
 **
 ** This macro is used to translate the configured CAN ID of a Tx PDU into the
 ** CAN ID that shall really be used for the transmission.
 **
 ** \param[in] CanId CAN ID to be translated
 **
 ** \return Translated CAN ID
 */


#if (defined CANIF_TL_TX_CAN_ID_SUPPORT)
#error CANIF_TL_TX_CAN_ID_SUPPORT already defined!
#endif /* #if( defined CANIF_TL_TX_CAN_ID_SUPPORT)*/
#define CANIF_TL_TX_CAN_ID_SUPPORT        STD_OFF

#if (defined CANIF_TRANSLATE_TX_CAN_ID)
#error CANIF_TRANSLATE_TX_CAN_ID already defined!
#endif /* #if( defined CANIF_TRANSLATE_TX_CAN_ID)*/
#define CANIF_TRANSLATE_TX_CAN_ID(CanId)  (CanId)



/** \def CANIF_TL_RX_CAN_ID_SUPPORT
 **
 ** \brief Switch for Rx CAN ID translation
 **
 ** This switch defines, if Rx CAN ID translation is supported.
 */

/** \def CANIF_TRANSLATE_RX_CAN_ID(CanId)
 **
 ** \brief Translate Rx CAN ID
 **
 ** This macro is used to translate the CAN ID of a received message into the
 ** CAN ID, that was previously configured for the associated Rx PDU.
 **
 ** \param[in] CanId CAN ID to be translated
 **
 ** \return Translated CAN ID
 */


#if (defined CANIF_TL_RX_CAN_ID_SUPPORT)
#error CANIF_TL_RX_CAN_ID_SUPPORT already defined!
#endif /* #if( defined CANIF_TL_RX_CAN_ID_SUPPORT)*/
#define CANIF_TL_RX_CAN_ID_SUPPORT        STD_OFF

#if (defined CANIF_TRANSLATE_RX_CAN_ID)
#error CANIF_TRANSLATE_RX_CAN_ID already defined!
#endif /* #if( defined CANIF_TRANSLATE_RX_CAN_ID)*/
#define CANIF_TRANSLATE_RX_CAN_ID(CanId)  (CanId)


/* ----- Pre-processor switch to enable/diable relocatable postbuild config ----- */
#if (CANIF_PBCFGM_SUPPORT_ENABLED == STD_ON)
#if (defined CANIF_RELOCATABLE_CFG_ENABLE)
#error CANIF_RELOCATABLE_CFG_ENABLE already defined!
#endif /* #if( defined CANIF_RELOCATABLE_CFG_ENABLE)*/
#define CANIF_RELOCATABLE_CFG_ENABLE   STD_OFF
#else
#if (defined CANIF_RELOCATABLE_CFG_ENABLE)
#error CANIF_RELOCATABLE_CFG_ENABLE already defined!
#endif /* #if( defined CANIF_RELOCATABLE_CFG_ENABLE)*/
#define CANIF_RELOCATABLE_CFG_ENABLE   STD_ON
#endif

/** \brief Compile time verification value */
#if (defined CANIF_CFG_SIGNATURE)
#error CANIF_CFG_SIGNATURE already defined!
#endif /* #if( defined CANIF_CFG_SIGNATURE)*/
#define CANIF_CFG_SIGNATURE 1323124628U

/** \brief Compile time Published information verfication value */
#if (defined CANIF_PUBLIC_INFO_SIGNATURE)
#error CANIF_PUBLIC_INFO_SIGNATURE already defined!
#endif /* #if( defined CANIF_PUBLIC_INFO_SIGNATURE)*/
#define CANIF_PUBLIC_INFO_SIGNATURE  3410186675U

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

#endif /* if !defined( CANIF_CFG_H ) */
/*==================[end of file]============================================*/
