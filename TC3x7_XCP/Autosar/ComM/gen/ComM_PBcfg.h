
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

#ifndef COMM_PBCFG_H
#define COMM_PBCFG_H



/*==================[inclusions]=============================================*/

#include <ComM_SymbolicNames_PBcfg.h>
#include <TSAutosar.h>
#include <ComM_Types_Int.h>
#include <Platform_Types.h>
#include <Compiler.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_PTR_CLASS COMM_APPL_CONST
#include <TSPBConfig_Types.h>


/*==================[macros]=================================================*/

#if (defined ComMConfigSet_0) /* To prevent double definition */
#error ComMConfigSet_0 already defined
#endif /* (defined ComMConfigSet_0) */

#define ComMConfigSet_0 (ComM_Configuration.RootCfg)



/*==================[type definitions]=======================================*/

typedef struct /* ComM_ConfigLayoutType */ {
    VAR( ComM_ConfigType, TYPEDEF ) RootCfg;
    VAR( uint8, TYPEDEF ) aUsersOfAllChannel[1]; /* User Ids referenced by channel or PNCs of channel */
    VAR( uint8, TYPEDEF ) aChannelsOfAllUser[1]; /* Channel Ids or PNC ids referenced by user of channel */
} ComM_ConfigLayoutType;

typedef CONST( ComM_ConfigLayoutType, COMM_APPL_CONST ) ComM_ConstConfigLayoutType;


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/

#define COMM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <MemMap.h>

extern ComM_ConstConfigLayoutType ComM_Configuration;

#define COMM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <MemMap.h>


/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/



#undef TS_RELOCATABLE_CFG_ENABLE

#undef TS_PB_CFG_PTR_CLASS

#endif /* COMM_PBCFG_H */

/*==================[end of file]============================================*/

