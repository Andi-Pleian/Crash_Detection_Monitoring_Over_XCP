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
#if (!defined XCPONCDD_CBK_H)
#define XCPONCDD_CBK_H

/*==================[includes]===============================================*/

#include <ComStack_Types.h>     /* AUTOSAR Com Stack header */

#include <Xcp_Cfg.h>            /* Generated module configuration */

/*==================[macros]=================================================*/

/*------------------[error codes]--------------------------------------------*/

/*------------------[macros for service IDs]---------------------------------*/

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

#define XCP_START_SEC_CODE
#include <MemMap.h>

/** \brief XCP PDU is received.
 **
 ** This function is called by the lower layer Complex Device Driver when an
 ** AUTOSAR XCP PDU has been received.
 **
 ** Precondition: ::XCP_ON_CDD_ENABLED = ::STD_ON
 **
 ** \param[in]  XcpRxPduId  PDU-ID that has been received.
 ** \param[in]  XcpRxPduPtr  Pointer to SDU(Buffer of received payload).
 ** \ServiceID{::XCP_SID_IF_RX_INDICATION}
 ** \Reentrancy{Reentrant for different XcpRxPduId, non-Reentrant for the same
 ** XcpRxPduId}
 ** \Synchronicity{Synchronous} */
extern void Xcp_CddRxIndication
(
  PduIdType XcpRxPduId,
  P2CONST(PduInfoType, AUTOMATIC, XCP_APPL_DATA) XcpRxPduPtr
);

/** \brief XCP PDU transmit confirmation.
 **
 ** This function is called by the lower layer Complex Device Driver when an
 ** AUTOSAR XCP PDU has been transmitted.
 **
 ** Precondition: ::XCP_ON_CDD_ENABLED = ::STD_ON
 **
 ** \param[in]  XcpTxPduId  PDU-ID that has been transmitted.
 ** \ServiceID{::XCP_SID_IF_TX_CONFIRMATION}
 ** \Reentrancy{Reentrant for different XcpTxPduId, non-Reentrant for the same
 ** XcpTxPduId}
 ** \Synchronicity{Synchronous} */
extern void Xcp_CddTxConfirmation
(
  PduIdType XcpTxPduId
);

/** \brief Call when an AUTOSAR XCP PDU shall be transmitted.
 **
 ** This function is called by the lower layer Complex Device Driver when an
 ** AUTOSAR XCP PDU shall be transmitted. The function Xcp_CddTriggerTransmit
 ** is called by the Complex Device Driver for requesting the I-PDU before
 ** transmission. Whether the function Xcp_CddTriggerTransmit is called or not
 ** is statically configured for each I-PDU in the configuration.
 **
 ** Precondition: ::XCP_ON_CDD_ENABLED = ::STD_ON
 **
 ** \param[in]  XcpTxPduId  PDU-ID that has been requested to be transmitted.
 ** \param[out]  PduInfoPtr  Pointer to PduInfo SDU (pointer to SDU buffer and
 **                          SDU length).
 ** \ServiceID{::XCP_SID_IF_TRIGGER_TRANSMIT}
 ** \Reentrancy{Non-Reentrant}
 ** \Synchronicity{Synchronous} */
extern Std_ReturnType Xcp_CddTriggerTransmit
(
  PduIdType XcpTxPduId,
  P2VAR(PduInfoType, AUTOMATIC, XCP_APPL_DATA) PduInfoPtr
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

#endif /* if !defined( XCPONCDD_CBK_H ) */
/*==================[end of file]============================================*/
