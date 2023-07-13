
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

#ifndef FRNM_PBCFG_H
#define FRNM_PBCFG_H



/*==================[inclusions]=============================================*/

#include <FrNm_SymbolicNames_PBcfg.h>
#include <TSAutosar.h>
#include <FrNm_Types.h>
#include <Compiler.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_PTR_CLASS FRNM_APPL_CONST
#include <TSPBConfig_Types.h>


/*==================[macros]=================================================*/

#if (defined FrNmChannelConfig) /* To prevent double definition */
#error FrNmChannelConfig already defined
#endif /* (defined FrNmChannelConfig) */

#define FrNmChannelConfig (FrNm_ConfigLayout.RootCfg)



/*==================[type definitions]=======================================*/

typedef struct /* FrNm_ConfigLayoutType */ {
    VAR( FrNm_ConfigType, TYPEDEF ) RootCfg;
} FrNm_ConfigLayoutType;

typedef CONST( FrNm_ConfigLayoutType, FRNM_APPL_CONST ) FrNm_ConstConfigLayoutType;


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/

#define FRNM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <MemMap.h>

extern FrNm_ConstConfigLayoutType FrNm_ConfigLayout;

#define FRNM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <MemMap.h>


/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/



#undef TS_RELOCATABLE_CFG_ENABLE

#undef TS_PB_CFG_PTR_CLASS

#endif /* FRNM_PBCFG_H */

/*==================[end of file]============================================*/

