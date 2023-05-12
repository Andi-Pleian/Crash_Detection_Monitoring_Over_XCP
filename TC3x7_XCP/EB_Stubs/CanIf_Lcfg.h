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
#if (!defined CANIF_LCFG_H)
#define CANIF_LCFG_H

[!AUTOSPACING!]
/*==================[includes]==============================================*/

#include <TSAutosar.h>              /* global configuration */

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/* start data section declaration */
#define CANIF_START_SEC_CONST_32
#include <CanIf_MemMap.h>

/* value used to validate post build configuration against link time configuration */
extern CONST(uint32, CANIF_CONST) CanIf_LcfgSignature;

/* stop data section declaration */
#define CANIF_STOP_SEC_CONST_32
#include <CanIf_MemMap.h>

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* if !defined( CANIF_LCFG_H ) */
/*==================[end of file]===========================================*/
