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
#if (!defined CANIF_TRACE_INTERNAL_H)
#define CANIF_TRACE_INTERNAL_H
/*==================[inclusions]============================================*/

#include <CanIf_Cfg.h>

/*==================[macros]================================================*/
/* Place internal debug instrumentation macros in this file, i.e. all
   macros that are not generated for the public api instrumentation.
*/

#if(CANIF_CAN_REV2_COMPATIBILITY == STD_ON)
#ifndef DBG_CANIF_CANCELTXCONFIRMATION_ENTRY
/** \brief Entry point of function CanIf_CancelTxConfirmation() */
#define DBG_CANIF_CANCELTXCONFIRMATION_ENTRY(PduInfoPtr)
#endif

#ifndef DBG_CANIF_CANCELTXCONFIRMATION_EXIT
/** \brief Exit point of function CanIf_CancelTxConfirmation() */
#define DBG_CANIF_CANCELTXCONFIRMATION_EXIT(PduInfoPtr)
#endif
#endif /* (CANIF_CAN_REV2_COMPATIBILITY == STD_ON) */

#ifndef DBG_CANIF_CANCONTROLLERMODE_GRP
/** \brief Change of CanIf_CanControllerMode */
#define DBG_CANIF_CANCONTROLLERMODE_GRP(a,b,c)
#endif

#ifndef DBG_CANIF_CANCONTROLLERFLAGS_GRP
/** \brief Change of CanIf_CanControllerFlags */
#define DBG_CANIF_CANCONTROLLERFLAGS_GRP(a,b,c)
#endif

#ifndef DBG_CANIF_PDUMODE_GRP
/** \brief Change of CanIf_PduMode */
#define DBG_CANIF_PDUMODE_GRP(a,b,c)
#endif

#ifndef DBG_CANIF_STATE
/** \brief Change of CanIf_State */
#define DBG_CANIF_STATE(a,b)
#endif

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[external data]=========================================*/

#endif /* (!defined CANIF_TRACE_INTERNAL_H) */
/*==================[end of file]===========================================*/
