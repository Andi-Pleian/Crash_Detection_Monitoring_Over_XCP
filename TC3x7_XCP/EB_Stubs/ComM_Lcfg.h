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
#if (!defined COMM_LCFG_H)
#define COMM_LCFG_H

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
#define COMM_START_SEC_CONST_32
#include <MemMap.h>

/* value used to validate post build configuration against link time configuration */
extern CONST(uint32, COMM_CONST) ComM_LcfgSignature;

/* stop data section declaration */
#define COMM_STOP_SEC_CONST_32
#include <MemMap.h>

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* if !defined( COMM_LCFG_H ) */
/*==================[end of file]===========================================*/
