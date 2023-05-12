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
#if (!defined CANIF_CBK_H)
#define CANIF_CBK_H
/*==================[inclusions]=============================================*/

#include <ComStack_Types.h>     /* AUTOSAR COM types */
#include <CanIf.h>              /* CanIf configuration */
#include <Can_GeneralTypes.h>   /* AUTOSAR CAN general types */
#include <Can.h>                /* AUTOSAR CAN definitions */

/*==================[macros]=================================================*/

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

#define CANIF_START_SEC_CODE
#include <MemMap.h>



#if( CANIF_TX_CONFIRMATION_CB == STD_ON )
/** \brief Transmit confirmation callback function
 **
 ** This is the transmit confirmation callback function. It gets the PDU
 ** handle for the transmitted L-PDU, translates it for the upper layer and
 ** then calls the upper layer callback function configured for this handle.
 ** It furthermore starts the next transmission for the used HTH if there
 ** are other messages pending for transmission.
 **
 ** Preconditions:
 ** - The CAN interface must already be initialized by CanIf_Init()
 ** - The parameter \p CanTxPduId must be a valid Tx L-PDU
 **
 ** \param[in] CanTxPduId Tx L-PDU handle
 **
 ** \ServiceID{0x13}
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous}
 */
extern FUNC( void, CANIF_CODE ) CanIf_TxConfirmation( PduIdType CanTxPduId );
#endif /* CANIF_TX_CONFIRMATION_CB == STD_ON */



#if( CANIF_RX_INDICATION_CB == STD_ON )
#if(CANIF_CAN_REV422_COMPATIBILITY == STD_OFF)
/** \brief Receive indication callback function
 **
 ** This is the receive indication callback function. It calls the
 ** corresponding upper layer receive indication callback function and
 ** stores the received message if the read PDU data API is enabled.
 **
 ** Preconditions:
 ** - The CAN interface must already be initialized by CanIf_Init()
 ** - The parameter \p Hrh must be a valid HRH
 ** - The parameter \p CanId must be a valid CAN ID
 ** - The parameter \p CanDlc must be valid
 ** - The parameter \p CanSduPtr must be a valid pointer
 **
 ** \param[in] Hrh Index of the corresponding HRH
 ** \param[in] CanId CAN identifier
 ** \param[in] CanDlc Data length code
 ** \param[in] CanSduPtr Pointer to the received data
 **
 ** \ServiceID{0x14}
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous}
 */
extern FUNC( void, CANIF_CODE ) CanIf_RxIndication
  (
    Can_HwHandleType Hrh,
    Can_IdType CanId,
    uint8 CanDlc,
    P2CONST( uint8, AUTOMATIC, CANIF_APPL_DATA ) CanSduPtr
  );
#else
/** \brief Receive indication callback function
 **
 ** This is the receive indication callback function. It calls the
 ** corresponding upper layer receive indication callback function and
 ** stores the received message if the read PDU data API is enabled.
 **
 ** Preconditions:
 ** - The CAN interface must already be initialized by CanIf_Init()
 ** - The parameter \p Mailbox must be a valid HRH and a valid CAN ID
 ** - The parameter \p PduInfoPtr must be a valid pointer
 **
 ** \param[in] Mailbox identifier of the HRH and its corresponding CAN Controller
 ** \param[in] PduInfoPtr Pointer to the received data
 **
 ** \ServiceID{0x14}
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous}
 */
extern FUNC( void, CANIF_CODE ) CanIf_RxIndication
  (
    P2CONST( Can_HwType, AUTOMATIC, CANIF_APPL_DATA ) Mailbox,
    P2CONST( PduInfoType, AUTOMATIC, CANIF_APPL_DATA ) PduInfoPtr
  );
#endif /* (CANIF_CAN_REV422_COMPATIBILITY == STD_OFF) */
#endif /* CANIF_RX_INDICATION_CB == STD_ON */



#if( CANIF_CANCEL_TX_CONFIRMATION_CB == STD_ON )
/** \brief Transmit cancellation confirmation callback function
 **
 ** This is the transmit cancellation confirmation callback function. It
 ** tries to store the PDU received in \p PduInfoPtr and send the Tx L-PDU
 ** with the highest priority.
 **
 ** Preconditions:
 ** - The CAN interface must already be initialized by CanIf_Init()
 ** - The parameter \p PduInfoPtr must be a valid PDU pointer
 **
 ** \param[in] PduInfoPtr Pointer to the cancelled Tx L-PDU
 **
 ** \ServiceID{0x15}
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous}
 */
#if( CANIF_CAN_REV2_COMPATIBILITY == STD_OFF)
extern FUNC( void, CANIF_CODE ) CanIf_CancelTxConfirmation
  (
    VAR( PduIdType, AUTOMATIC ) CanTxPduId,
    P2CONST( PduInfoType, AUTOMATIC, CANIF_APPL_DATA ) PduInfoPtr
  );
#else
extern FUNC( void, CANIF_CODE ) CanIf_CancelTxConfirmation
  (
    P2CONST( Can_PduType, AUTOMATIC, CANIF_APPL_DATA ) PduInfoPtr
  );
#endif
#endif /* CANIF_CANCEL_TX_CONFIRMATION_CB == STD_ON */



/** \brief Bus-off callback function
 **
 ** This is the bus-off callback function. It changes the mode of the given
 ** controller \p Controller to STOPPED and clears the Tx buffers if
 ** necessary.
 **
 ** Preconditions:
 ** - The CAN interface must already be initialized by CanIf_Init()
 ** - The parameter \p Controller must be a valid pointer
 **
 ** \param[in] Controller Controller which went bus-off
 **
 ** \ServiceID{0x16}
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous}
 */
extern FUNC( void, CANIF_CODE ) CanIf_ControllerBusOff( uint8 Controller );



/** \brief Controller mode indication callback function
 **
 ** This is the controller mode indication callback function.
 **
 ** Preconditions:
 ** - The parameter \p controller must be a valid CanIf controller ID
 **
 ** \param[in] Controller Controller for which the mode is indicated
 ** \param[in] ControllerMode Mode to which the controller switched
 **
 ** \ServiceID{0x17}
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous}
 */
extern FUNC( void, CANIF_CODE ) CanIf_ControllerModeIndication
  (
    uint8 Controller,
    CanIf_ControllerModeType ControllerMode
  );


#if CANIF_TRCV_SUPPORT == STD_ON

/** \brief Transceiver mode indication callback function
 **
 ** This is the transceiver mode indication callback function.
 **
 ** Preconditions:
 ** - The parameter \p Transceiver must be a valid CanIf transceiver ID
 **
 ** \param[in] Transceiver Transceiver for which the mode is indicated
 ** \param[in] TransceiverMode Mode to which the transceiver switched
 **
 ** \ServiceID{0x18}
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous}
 */
extern FUNC( void, CANIF_CODE ) CanIf_TrcvModeIndication
  (
    uint8 Transceiver,
    CanTrcv_TrcvModeType TransceiverMode
  );

#if CANIF_PUBLIC_PN_SUPPORT == STD_ON
/** \brief Indicate that the transceiver is running in PN communication mode
 **
 ** \param[in] Transceiver  Transceiver for which the mode is indicated
 **
 ** \ServiceId{0x1a}
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous}
 */
extern FUNC( void, CANIF_CODE ) CanIf_ConfirmPnAvailability
  (
    uint8 Transceiver
  );


/** \brief Indicate that the transceiver has cleared the WufFlag
 **
 ** \param[in] Transceiver  Transceiver for which the mode is indicated
 **
 ** \ServiceId{0x20}
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous}
 */
extern FUNC( void, CANIF_CODE ) CanIf_ClearTrcvWufFlagIndication
  (
    uint8 Transceiver
  );

/** \brief Indicate the reason for the wake up that the CAN transceiver has detected
 **
 ** \param[in] Transceiver  Transceiver for which the mode is indicated
 **
 ** \ServiceId{0x21}
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous}
 */
extern FUNC( void, CANIF_CODE ) CanIf_CheckTrcvWakeFlagIndication
  (
    uint8 Transceiver
  );
#endif /* #if CANIF_PUBLIC_PN_SUPPORT == STD_ON */

#endif /* CANIF_TRCV_SUPPORT == STD_ON */

#define CANIF_STOP_SEC_CODE
#include <MemMap.h>

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

#endif /* if !defined( CANIF_CBK_H ) */
/*==================[end of file]============================================*/
