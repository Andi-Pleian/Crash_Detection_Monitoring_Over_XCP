/**
 * \file
 *
 * \brief AUTOSAR FrNm
 *
 * This file contains the implementation of the AUTOSAR
 * module FrNm.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2017 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#if (!defined FRNM_LCFG_H)
#define FRNM_LCFG_H

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
#define FRNM_START_SEC_CONST_32
#include <MemMap.h>

/* value used to validate post build configuration against link time configuration */
extern CONST(uint32, FRNM_CONST) FrNm_LcfgSignature;

/* stop data section declaration */
#define FRNM_STOP_SEC_CONST_32
#include <MemMap.h>

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* if !defined( FRNM_LCFG_H ) */
/*==================[end of file]===========================================*/
