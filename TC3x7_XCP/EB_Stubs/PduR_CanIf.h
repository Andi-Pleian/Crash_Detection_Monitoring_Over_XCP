/**
 * \file
 *
 * \brief AUTOSAR PduR
 *
 * This file contains the implementation of the AUTOSAR
 * module PduR.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2017 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#if (!defined PDUR_CANIF_H)
#define PDUR_CANIF_H

/*==================[includes]==============================================*/
#include <TSAutosar.h> /* EB specific standard types */
#include <ComStack_Types.h> /* AUTOSAR Communication Stack types */
/* Exclude post-build-time configuration include file if requested to do so */
#if (!defined PDUR_NO_PBCFG_REQUIRED) && (!defined PDUR_NO_CFG_REQUIRED)
#include <PduR_SymbolicNames_PBcfg.h>
#endif /* PDUR_NO_PBCFG_REQUIRED */

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function declarations]========================*/
#define PDUR_START_SEC_CODE
#include <MemMap.h>

/**
 ** \brief  This service is called by the CanIf module to indicate a received I-PDU.
 **
 ** \param[in]  RxPduId      ID of the received I-PDU.
 ** \param[in]  PduInfoPtr   Contains the length (SduLength) of the received I-PDU and a pointer to a
 **                          buffer (SduDataPtr) containing the I-PDU.
 **
 ** \ServiceID{0x42}
 ** \Reentrancy{Reentrant for different PduIds. Non reentrant for the same PduId.}
 ** \Synchronicity{Synchronous}
 **/
extern FUNC(void, PDUR_CODE) PduR_CanIfRxIndication
(
    PduIdType    RxPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)   PduInfoPtr
);

/**
 ** \brief  This service is called by the CanIf module to confirm the
 ** transmission of an I-PDU.
 **
 ** \param[in]  TxPduId       ID of the I-PDU that has been transmitted.
 **
 ** \ServiceID{0x40}
 ** \Reentrancy{Reentrant for different PduIds. Non reentrant for the same PduId.}
 ** \Synchronicity{Synchronous}
 **/
extern FUNC(void,PDUR_CODE) PduR_CanIfTxConfirmation
(
    PduIdType    TxPduId
);

#define PDUR_STOP_SEC_CODE
#include <MemMap.h>

/*==================[internal function declarations]========================*/

#endif /* if !defined( PDUR_CANIF_H ) */
/*==================[end of file]===========================================*/
