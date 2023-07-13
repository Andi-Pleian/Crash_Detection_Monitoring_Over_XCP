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

/*==================[inclusions]=============================================*/
#include <TSAutosar.h>         /* EB specific standard types */
#include <ComStack_Types.h>    /* typedefs for AUTOSAR com stack */
#include <CanIf_Lcfg.h> /* Generated configuration */

/*==================[macros]=================================================*/

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/* start data section declaration */
#define CANIF_START_SEC_CONST_32
#include <MemMap.h>

/* value used to validate post build configuration against link time configuration */
CONST(uint32, CANIF_CONST) CanIf_LcfgSignature = 2416897657U;

/* stop data section declaration */
#define CANIF_STOP_SEC_CONST_32
#include <MemMap.h>

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal function definitions]==========================*/

/*==================[end of file]============================================*/

