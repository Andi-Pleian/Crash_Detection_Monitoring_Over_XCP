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
#if (!defined CANIF_TYPES_H)
#define CANIF_TYPES_H


/*==================[inclusions]=============================================*/

#include <TSAutosar.h>
#include <CanIf_Cfg.h>
#include <Can.h>

#if( CANIF_WAKEUP_SUPPORT_API == STD_ON )
#include <EcuM_Cbk.h>
#endif

/*==================[macros]=================================================*/

/** \brief Maximum DLC of a CAN 2.0 frame */
#if (defined CANIF_MAXIMUM_CAN_20_DLC)
#error CANIF_MAXIMUM_CAN_20_DLC already defined!
#endif /* #if( defined CANIF_MAXIMUM_CAN_20_DLC)*/
#define CANIF_MAXIMUM_CAN_20_DLC            8U

/** \brief Maximum DLC of a CAN FD frame */
#if (defined CANIF_MAXIMUM_CAN_FD_DLC)
#error CANIF_MAXIMUM_CAN_FD_DLC already defined!
#endif /* #if( defined CANIF_MAXIMUM_CAN_FD_DLC)*/
#define CANIF_MAXIMUM_CAN_FD_DLC           64U

/*==================[type definitions]=======================================*/

/* --- general types --------------------------------------------------- */

/* --- CAN Transceiver Configuration ----------------------------------- */

#if (CANIF_TRCV_SUPPORT == STD_ON)
/** \brief Pointer to function CanTrcv_SetOpMode()
 **
 ** This is a function pointer type for the CAN transceiver function
 ** CanTrcv_SetOpMode().
 */
typedef P2FUNC( Std_ReturnType, CANTRCV_CODE, CanIf_TrcvSetOpModeFctPtrType )
  (
    uint8 Transceiver,
    CanTrcv_TrcvModeType OpMode
  );


/** \brief Pointer to function CanTrcv_GetOpMode()
 **
 ** This is a function pointer type for the CAN transceiver function
 ** CanTrcv_GetOpMode().
 */
typedef P2FUNC( Std_ReturnType, CANTRCV_CODE, CanIf_TrcvGetOpModeFctPtrType )
  (
    uint8 Transceiver,
    P2VAR( CanTrcv_TrcvModeType, AUTOMATIC, CANTRCV_APPL_DATA ) OpMode
  );


#if (CANIF_CANTRCV_WAKEUP_SUPPORT == STD_ON)
/** \brief Pointer to function CanTrcv_GetBusWuReason()
 **
 ** This is a function pointer type for the CAN transceiver function
 ** CanTrcv_GetBusWuReason().
 */
typedef P2FUNC( Std_ReturnType, CANTRCV_CODE, CanIf_TrcvGetBusWuRFctPtrType )
  (
    uint8 Transceiver,
    P2VAR( CanTrcv_TrcvWakeupReasonType, AUTOMATIC, CANTRCV_APPL_DATA ) Reason
  );


/** \brief Pointer to function CanTrcv_SetWakeupMode()
 **
 ** This is a function pointer type for the CAN transceiver function
 ** CanTrcv_SetWakeupMode().
 */
typedef P2FUNC( Std_ReturnType, CANTRCV_CODE, CanIf_TrcvSetWuModeFctPtrType )
  (
    uint8 Transceiver,
    CanTrcv_TrcvWakeupModeType TrcvWakeupMode
  );


/** \brief Pointer to function CanTrcv_CB_WakeupByBus()
 **
 ** This is a function pointer type for the CAN transceiver function
 ** CanTrcv_CB_WakeupByBus().
 */
typedef P2FUNC( Std_ReturnType, CANTRCV_CODE, CanIf_CBWakeupByBusFctPtrType )
  (
    uint8 Transceiver
  );
#endif /* CANIF_CANTRCV_WAKEUP_SUPPORT == STD_ON */


#if CANIF_PUBLIC_PN_SUPPORT == STD_ON
/** \brief Pointer to function CanTrcv_ClearTrcvWufFlag()
 **
 ** This is a function pointer type for the CAN transceiver function
 ** CanTrcv_ClearTrcvWufFlag().
 */
typedef P2FUNC( Std_ReturnType, CANTRCV_CODE, CanIf_ClearTrcvWufFlagFctPtrType )
  (
    uint8 Transceiver
  );


/** \brief Pointer to function CanTrcv_CheckWakeup()
 **
 ** This is a function pointer type for the CAN transceiver function
 ** CanTrcv_CheckWakeup().
 */
typedef P2FUNC( Std_ReturnType, CANTRCV_CODE, CanIf_CheckTrcvWakeFlagFctPtrType )
  (
    uint8 Transceiver
  );
#endif /* CANIF_PUBLIC_PN_SUPPORT == STD_ON */
#endif /* CANIF_TRCV_SUPPORT == STD_ON */



/* --- upper layer callbacks and notifications ------------------------- */


/** \brief Pointer to <UpperLayer>_RxIndication
 **
 ** This is a function pointer type for the RxIndication function
 ** of all well-known upper layers and for all CDDs where parameter
 ** CanIfUpperLayerUseCanId is false.
 */
typedef P2FUNC( void, CANIF_APPL_CODE, CanIf_UlRxIndFctPtrType )
  (
    PduIdType CanIfRxPduId,
    P2VAR(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) CanIfRxPduPtr
  );


/** \brief Pointer to <CDD>_RxIndication
 **
 ** This is a function pointer type for the RxIndication function
 ** of all CDD upper layers where parameter CanIfUpperLayerUseCanId is true.
 */
typedef P2FUNC( void, CANIF_APPL_CODE, CanIf_CddRxIndFctPtrType )
  (
    PduIdType CanIfRxPduId,
    P2VAR(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) CanIfRxPduPtr,
    Can_IdType CanIfRxCanId
  );


/** \brief Pointer to <UpperLayer>_TxConfirmation
 **
 ** This is a function pointer type for the TxConfirmation function
 ** of all upper layers of CanIf.
 */
typedef P2FUNC( void, CANIF_APPL_CODE, CanIf_TxConfFctPtrType )
  (
    PduIdType CanIfTxPduId
  );


/** \brief Pointer to DLC check notification functions
 **
 ** This is a function pointer type for the upper layer DLC check notification
 ** functions.
 */
typedef P2FUNC( void, CANIF_APPL_CODE, CanIf_DlcCheckNotifFctPtrType )
  (
    PduIdType CanRxPduId
  );


/** \brief Pointer to ActMainFunction functions
 **
 ** This is a function pointer type for the SchM decoupled processing
 ** activation functions.
 */
typedef P2FUNC( void, CANIF_APPL_CODE, CanIf_ActMainFctPtrType )
  (
    void
  );


/* --- CAN Transceiver Configuration ----------------------------------- */

#if (CANIF_TRCV_SUPPORT == STD_ON)
/** \brief CAN Transceiver Driver function configuration
 **
 ** This type is used for configuring the CAN Transceiver Driver functions.
 */
typedef struct
{
  CanIf_TrcvSetOpModeFctPtrType setOpMode;        /**< set operation mode */
  CanIf_TrcvGetOpModeFctPtrType getOpMode;        /**< get operation mode */
#if CANIF_CANTRCV_WAKEUP_SUPPORT == STD_ON
  CanIf_TrcvGetBusWuRFctPtrType getBusWuReason;   /**< get wakeup reason */
  CanIf_TrcvSetWuModeFctPtrType setWakeupMode;    /**< set wakeup mode */
  CanIf_CBWakeupByBusFctPtrType chkWakeupByBus;   /**< wakeup polling */
#endif /* CANIF_CANTRCV_WAKEUP_SUPPORT */
#if CANIF_PUBLIC_PN_SUPPORT == STD_ON
  CanIf_ClearTrcvWufFlagFctPtrType clearWufFlag;  /**< clear wake flag */
  CanIf_CheckTrcvWakeFlagFctPtrType checkWakeFlag;/**< check wake flag */
#endif /* CANIF_PUBLIC_PN_SUPPORT */
} CanIf_CanTrcvConfigType;
#endif /* CANIF_TRCV_SUPPORT == STD_ON */


/* --- Upper Layer Configuration --------------------------------------- */

#if (CANIF_ANY_UL_CBK_SUPPORT == STD_ON)
/** \brief Upper layer callback function configuration
 **
 ** This type contains the function pointer of the API functions
 ** <UL>_RxIndication, <CDD>_RxIndication, <UL>_TxConfirmation,
 ** <UL>_DlcErrorNotification and <UL>_DlcPassedNotification of all
 ** upper layers of the CanIf.
 */
typedef struct
{
#if (CANIF_UL_RX_INDICATION_SUPPORT == STD_ON)
  VAR(CanIf_UlRxIndFctPtrType, TYPEDEF)       UlRxIndFctPtr;         /**< <UL>_RxIndication */
#endif /* CANIF_UL_RX_INDICATION_SUPPORT == STD_ON */

#if (CANIF_CDD_RX_INDICATION_SUPPORT == STD_ON)
  VAR(CanIf_CddRxIndFctPtrType, TYPEDEF)      CddRxIndFctPtr;        /**< <Cdd>_RxIndication */
#endif /* CANIF_CDD_RX_INDICATION_SUPPORT == STD_ON */

#if (CANIF_TX_CONFIRMATION_SUPPORT == STD_ON)
  VAR(CanIf_TxConfFctPtrType, TYPEDEF)        TxConfFctPtr;          /**< <UL>_TxConfirmation */
#endif /* CANIF_TX_CONFIRMATION_SUPPORT == STD_ON */

#if (CANIF_DLC_ERROR_NOTIF_SUPPORT == STD_ON)
  VAR(CanIf_DlcCheckNotifFctPtrType, TYPEDEF) DlcErrorNotifFctPtr;   /**< <UL>_DlcFailedNotif */
#endif /* CANIF_DLC_ERROR_NOTIF_SUPPORT == STD_ON */

#if (CANIF_DLC_PASSED_NOTIF_SUPPORT == STD_ON)
  VAR(CanIf_DlcCheckNotifFctPtrType, TYPEDEF) DlcPassedNotifFctPtr;  /**< <UL>_DlcPassedNotif */
#endif /* CANIF_DLC_PASSED_NOTIF_SUPPORT == STD_ON */
} CanIf_CbkFctPtrTblType;
#endif /* CANIF_ANY_UL_CBK_SUPPORT == STD_ON */

#if (CANIF_DECOUPLED_TXPROCESSING_SUPPORT == STD_ON)
/** \brief Tx decoupled main function transmission configuration
 **
 ** This type contains the function pointer of the SchM ActMainFunction API functions,
 ** the queue offset and the size of the queue of all TxPdus that support decoupled transmission.
 */
typedef struct
{
  VAR(CanIf_ActMainFctPtrType, TYPEDEF) ActMainTxFctPtr;  /**< SchM_ActMainFunctionTx */
#if (CANIF_MAX_QUEUED_TXPDUS_SIZE > 0xFFU)
  VAR(uint16, TYPEDEF) TxQueueOffset;                     /**< Queue offset of the Main Function */
#else
  VAR(uint8, TYPEDEF) TxQueueOffset;                      /**< Queue offset of the Main Function */
#endif
  VAR(uint8, TYPEDEF) TxQueueSize;                        /**< Queue size of the Main Function */
} CanIf_MfTxPtrTblType;
#endif /* CANIF_DECOUPLED_TXPROCESSING_SUPPORT == STD_ON */

#if (CANIF_DECOUPLED_RXPROCESSING_SUPPORT == STD_ON)
/** \brief Rx decoupled main function reception configuration
 **
 ** This type contains the function pointer of the SchM ActMainFunction API functions,
 ** the queue offset and the size of the queue of all RxPdus that support decoupled reception.
 */
typedef struct
{
  VAR(CanIf_ActMainFctPtrType, TYPEDEF) ActMainRxFctPtr;  /**< SchM_ActMainFunctionRx */
  VAR(uint16, TYPEDEF) PayloadQueueSize;                  /**< Queue payload data size of the Main Function */
  VAR(uint16, TYPEDEF) PayloadQueueOffset;                /**< Queue payload data offset of the Main Function */
#if (CANIF_MAX_QUEUED_RXPDUS_SIZE > 0xFFU)
  VAR(uint16, TYPEDEF) RxQueueOffset;                     /**< Queue offset of the Main Function */
#else
  VAR(uint8, TYPEDEF) RxQueueOffset;                      /**< Queue offset of the Main Function */
#endif
  VAR(uint8, TYPEDEF) RxQueueSize;                        /**< Queue size of the Main Function */
} CanIf_MfRxPtrTblType;
#endif /* CANIF_DECOUPLED_RXPROCESSING_SUPPORT == STD_ON */

/* --- Tx buffering ---------------------------------------------------- */

/** \brief Type for Tx buffers
 **
 ** This type is used for the transmit buffers.
 */
typedef struct
{
#if CANIF_SETDYNAMICTXID_API == STD_ON
  Can_IdType id;                        /**< CAN ID */
#endif /* CANIF_SETDYNAMICTXID_API */
  uint8 length;                         /**< DLC */
} CanIf_TxBufferType;


#if (CANIF_DECOUPLED_TXPROCESSING_SUPPORT == STD_ON)
/* --- Tx Pdu control queueing  ---------------------------------------- */

/** \brief Type for Tx control queue
 **
 ** This type is used for the transmit queue.
 */
typedef struct
{
  PduIdType PduId;                     /**< Pdu ID */
  uint8 MFIdx;                         /**< associated Main Function index */
} CanIf_TxQueueType;
#endif /* CANIF_DECOUPLED_TXPROCESSING_SUPPORT */


#if (CANIF_DECOUPLED_RXPROCESSING_SUPPORT == STD_ON)
/* --- Rx Pdu control queueing  ---------------------------------------- */

/** \brief Type for Rx control queue
 **
 ** This type is used for the receive queue.
 */
typedef struct
{
  Can_IdType CanId;              /**< Can ID needed for CDD upper layers */
  PduIdType PduId;               /**< Pdu ID */
  uint16 PreviousQueuePos;       /**< position of the previous entry in queue */
  uint8 ControllerId;            /**< Id of the associated Controller */
  uint8 MFIdx;                   /**< associated Main Function index */
} CanIf_RxQueueType;
#endif /* CANIF_DECOUPLED_RXPROCESSING_SUPPORT */

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

#endif /* if !defined( CANIF_TYPES_H ) */
/*==================[end of file]============================================*/
