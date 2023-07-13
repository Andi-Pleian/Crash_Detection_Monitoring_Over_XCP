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
#if (!defined XCPONETH_CBK_H)
#define XCPONETH_CBK_H

/*==================[includes]===============================================*/

#include <Xcp_Cfg.h>

#if (XCP_ON_ETHERNET_ENABLED == STD_ON)

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
 ** This function is called by the lower layer Socket Adapter when an AUTOSAR
 ** XCP PDU has been received.
 **
 ** Precondition: ::XCP_ON_ETHERNET_ENABLED = ::STD_ON
 **
 ** \param[in]  XcpRxPduId  PDU-ID that has been received
 ** \param[in]  XcpRxPduPtr  Pointer to SDU(Buffer of received payload)
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
 ** \Reentrancy{Reentrant for different XcpRxPduId, non-Reentrant for the same
 ** XcpRxPduId}
 ** \Synchronicity{Synchronous} */
extern FUNC(void, XCP_CODE) Xcp_SoAdIfRxIndication
(
  PduIdType XcpRxPduId,
  P2VAR(PduInfoType, AUTOMATIC, XCP_APPL_DATA) XcpRxPduPtr
);

/** \brief XCP PDU transmit confirmation
 **
 ** This function is called by the lower layer Socket Adapter when an AUTOSAR
 ** XCP PDU has been transmitted.
 **
 ** Precondition: ::XCP_ON_ETHERNET_ENABLED = ::STD_ON
 **
 ** \param[in]  XcpTxPduId  PDU-ID that has been transmitted
 **
 ** \ProductionError{XCP_E_RETRY_FAILED, thrown\, if XCP message transmission
 ** (including configured number of retries) fails.}
 ** \ProductionError{XCP_E_PDU_BUFFER_LOCKED, thrown\, if the callback function
 ** was called for a PDU that is not mapped to the active connection.}
 *
 ** \ServiceID{::XCP_SID_IF_TX_CONFIRMATION}
 ** \Reentrancy{Reentrant for different XcpTxPduId, non-Reentrant for the same
 ** XcpTxPduId}
 ** \Synchronicity{Synchronous} */
extern FUNC(void, XCP_CODE) Xcp_SoAdIfTxConfirmation
(
  PduIdType XcpTxPduId
);

#if (XCP_SOAD_PROTOCOL_TCP_SUPPORT == STD_ON)

/** \brief Socket connection mode change notification
 **
 ** This function is called by the lower layer Socket Adapter when the socket
 ** connection mode has changed. If the socket is closed while in XCP connected
 ** state, the XCP module will perform an XCP disconnect, which means that all
 ** data acquisition will be stopped.
 **
 ** This function is available only for the TCP protocol as there is no UDP connection (UDP being
 ** a broadcasting protocol)
 **
 ** Precondition: ::XCP_ON_ETHERNET_ENABLED = ::STD_ON
 **
 ** \param[in]  SoConId  Socket connection ID of socket that has changed
 ** \param[in]  Mode  Socket connection mode (ONLINE, OFFLINE or RECONNECT)
 **
 ** \ProductionError{XCP_E_RESP_CTO_QUEUE_FULL, thrown\, if command response
 ** or event package cannot be sent to the master because internal queue is full.}
 **
 ** \ServiceID{::XCP_SID_SOAD_SO_CON_MODE_CHG}
 ** \Reentrancy{Reentrant for different SoConIds. Non reentrant for the same
 ** SoConId}
 ** \Synchronicity{Synchronous} */
extern FUNC(void, XCP_CODE) Xcp_SoAdSoConModeChg
(
  SoAd_SoConIdType SoConId,
  SoAd_SoConModeType Mode
);

#endif /* (XCP_SOAD_PROTOCOL_TCP_SUPPORT == STD_ON) */

#define XCP_STOP_SEC_CODE
#include <MemMap.h>

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

#endif /* (XCP_ON_ETHERNET_ENABLED == STD_ON) */

#endif /* if !defined( XCPONETH_CBK_H ) */
/*==================[end of file]============================================*/
