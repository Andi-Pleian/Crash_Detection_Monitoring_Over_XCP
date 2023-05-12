/**
 * \file
 *
 * \brief AUTOSAR ComM
 *
 * This file contains the implementation of the AUTOSAR
 * module ComM.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2017 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[inclusions]============================================*/

#include <TSAutosar.h> /* EB specific standard types */
#include <ComM_Lcfg.h> /* Generated configuration */

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/* start data section declaration */
#define COMM_START_SEC_CONST_32
#include <MemMap.h>

/* value used to validate post build configuration against link time configuration */
CONST(uint32, COMM_CONST) ComM_LcfgSignature = [!"asc:getConfigSignature(as:modconf('ComM')[1]//*[not(child::*) and (node:configclass() = 'Link')])"!]U;

/* stop data section declaration */
#define COMM_STOP_SEC_CONST_32
#include <MemMap.h>


/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external constants]====================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/
