/**
 * \file
 *
 * \brief AUTOSAR Xcp
 *
 * This file contains the implementation of the AUTOSAR
 * module Xcp.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2017 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#if (!defined XCPONCAN_CBK_H)
#define XCPONCAN_CBK_H


/*==================[includes]===============================================*/

#include <Xcp_Cfg.h>

#if ((XCP_ON_CAN_ENABLED == STD_ON) || (XCP_ON_CANFD_ENABLED == STD_ON))

#include <ComStack_Types.h>     /* AUTOSAR Com Stack header */

/*==================[macros]=================================================*/

/*------------------[error codes]--------------------------------------------*/

/*------------------[macros for service IDs]---------------------------------*/

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

#define XCP_START_SEC_CODE
#include <MemMap.h>

/** \brief XCP PDU is received
 **
 ** This function is called by the lower layer CanIf when an AUTOSAR XCP PDU has
 ** been received.
 **
 ** Precondition: ::XCP_ON_CAN_ENABLED = ::STD_ON
 **
 ** \param[in]  XcpRxPduId  PDU-ID that has been received
 ** \param[in]  XcpRxPduPtr  Contains the length (SduLength) of the received
 ** I-PDU and a pointer to a buffer (SduDataPtr) containing the I-PDU
 **
 ** \ProductionError{XCP_E_PDU_LOST, thrown\, if XCP message is received
 ** but it is dicarded by XCP as it is detected as incorrect.}
 ** \ProductionError{XCP_E_PDU_BUFFER_FULL, thrown\, if XCP message is received
 ** but it is dicarded because reception buffer is already full.}
 ** \ProductionError{XCP_E_PDU_BUFFER_LOCKED, thrown\, if the callback function
 ** was called for a PDU that is not mapped to the active connection.}
 ** \ProductionError{XCP_E_RESP_CTO_QUEUE_FULL, thrown\, if command response
 ** or event package cannot be sent to the master because internal queue is full.}
 ** \ProductionError{XCP_E_STIMULATION_DATA_LOST, thrown\, if new stimulation data
 ** received before previous data is processed.}
 **
 ** \ServiceID{::XCP_SID_IF_RX_INDICATION}
 ** \Reentrancy{Reentrant for different XcpRxPduId. Non-reentrant for the same XcpRxPduId}
 ** \Synchronicity{Synchronous} */
extern FUNC(void, XCP_CODE) Xcp_CanIfRxIndication
(
  PduIdType XcpRxPduId,
  P2VAR(PduInfoType, AUTOMATIC, XCP_APPL_DATA) XcpRxPduPtr
);

/** \brief XCP PDU transmit confirmation
 **
 ** This function is called by the lower layer CanIf when an AUTOSAR XCP PDU has
 ** been transmitted.
 **
 ** Precondition: ::XCP_ON_CAN_ENABLED = ::STD_ON
 **
 ** \param[in]  XcpTxPduId  PDU-ID that has been transmitted
 **
 ** \ProductionError{XCP_E_RETRY_FAILED, thrown\, if XCP message transmission
 ** (including configured number of retries) fails.}
 ** \ProductionError{XCP_E_PDU_BUFFER_LOCKED, thrown\, if the callback function
 ** was called for a PDU that is not mapped to the active connection.}
 **
 ** \ServiceID{::XCP_SID_IF_TX_CONFIRMATION}
 ** \Reentrancy{Reentrant for different XcpTxPduId. non-Reentrant for the same XcpTxPduId}
 ** \Synchronicity{Synchronous} */
extern FUNC(void, XCP_CODE) Xcp_CanIfTxConfirmation
(
  PduIdType XcpTxPduId
);

#define XCP_STOP_SEC_CODE
#include <MemMap.h>

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

#endif /* ((XCP_ON_CAN_ENABLED == STD_ON) || (XCP_ON_CANFD_ENABLED == STD_ON)) */

#endif /* if !defined( XCPONCAN_CBK_H ) */
/*==================[end of file]============================================*/
