
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

#ifndef COMM_TYPES_INT_H
#define COMM_TYPES_INT_H



/*==================[inclusions]=============================================*/

#include <Platform_Types.h>
#include <TSAutosar.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_PTR_CLASS COMM_APPL_CONST
#include <TSPBConfig_Types.h>


/*==================[macros]=================================================*/


/*==================[type definitions]=======================================*/

typedef struct /* ComM_ConfigType */ {
    VAR( uint32, TYPEDEF ) PlatformSignature; /* Used to validate the platform */
    VAR( uint32, TYPEDEF ) LcfgSignature; /* Used to validate the post build configuration against the link time configuration */
    VAR( uint32, TYPEDEF ) CfgSignature; /* Used to validate the post build configuration against the precompile time configuration */
    VAR( uint32, TYPEDEF ) PublicInfoSignature; /* Used to validate Public information */
    TS_REF2CFG( uint8 )  pUsersOfAllChannel; /* Reference to COMM_ConfigLayoutType.aUsersOfAllChannel */
    VAR( uint16, TYPEDEF ) NumUsersOfAllChannel[3]; /* Index of first user of a channel in COMM_ConfigLayoutType.aUsersOfAllChannel */
    TS_REF2CFG( uint8 )  pChannelsOfAllUser; /* Reference to COMM_ConfigLayoutType.aChannelsOfAllUser */
    VAR( uint16, TYPEDEF ) NumChannelsOfAllUser[3]; /* Index of first channel of a user in COMM_ConfigLayoutType.aChannelsOfAllUser */
    VAR( uint16, TYPEDEF ) DirectNumChannelsOfAllUser[3]; /* Index of first channel of a user in COMM_ConfigLayoutType.aChannelsOfAllUser */
} ComM_ConfigType;


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/


/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/



#undef TS_RELOCATABLE_CFG_ENABLE

#undef TS_PB_CFG_PTR_CLASS

#endif /* COMM_TYPES_INT_H */

/*==================[end of file]============================================*/

