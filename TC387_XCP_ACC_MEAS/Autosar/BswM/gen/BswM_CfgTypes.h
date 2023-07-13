
/**
 * \file
 *
 * \brief AUTOSAR BswM
 *
 * This file contains the implementation of the AUTOSAR
 * module BswM.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2017 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef BSWM_CFGTYPES_H
#define BSWM_CFGTYPES_H



/*==================[inclusions]=============================================*/

#include <Platform_Types.h>
#include <TSAutosar.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_PTR_CLASS BSWM_APPL_CONST
#include <TSPBConfig_Types.h>


/*==================[macros]=================================================*/

#define TYPEDEF
/*==================[type definitions]=======================================*/

typedef struct /* BswMActionListItemType */ {
    VAR( uint8, TYPEDEF ) ActionListItemType;
    VAR( uint8, TYPEDEF ) IsAbortOnFail;
    VAR( uint16, TYPEDEF ) ArtifactIndex;
    VAR( uint8, TYPEDEF ) ActionType;
} BswMActionListItemType;

typedef struct /* BswMRangeType */ {
    VAR( uint16, TYPEDEF ) Head;
    VAR( uint16, TYPEDEF ) Tail;
} BswMRangeType;

typedef struct /* BswMRuleType */ {
    VAR( uint16, TYPEDEF ) ID;
    VAR( uint8, TYPEDEF ) RuleInitState;
    VAR( uint16, TYPEDEF ) LogicalExprIndex;
    VAR( uint16, TYPEDEF ) TrueActionListIndex;
    VAR( uint16, TYPEDEF ) FalseActionListIndex;
} BswMRuleType;

typedef struct /* BswMActionListType */ {
    VAR( uint8, TYPEDEF ) IsTriggered;
    VAR( BswMRangeType, TYPEDEF ) ActionListItemSegment;
} BswMActionListType;

typedef struct /* BswM_ConfigType */ {
    VAR( uint32, TYPEDEF ) PlatformSignature;
    VAR( uint32, TYPEDEF ) LcfgSignature;
    VAR( uint32, TYPEDEF ) CfgSignature;
    VAR( uint32, TYPEDEF ) PublicInfoSignature;
    VAR( uint16, TYPEDEF ) NumRules;
    VAR( uint16, TYPEDEF ) NumRulesDeferred;
    VAR( uint16, TYPEDEF ) NumActionLists;
    TS_REF2CFG( BswMRuleType )  RuleTable;
    TS_REF2CFG( uint16 )  RuleDependencyTable;
    TS_REF2CFG( BswMRangeType )  RuleDependencyListRangeTable;
    TS_REF2CFG( BswMActionListType )  ActionListTable;
    TS_REF2CFG( BswMActionListItemType )  ActionListItemTable;
    TS_REF2CFG( uint8 )  UInt8InitialValuesTable;
    TS_REF2CFG( uint16 )  UInt16InitialValuesTable;
    TS_REF2CFG( uint32 )  UInt32InitialValuesTable;
} BswM_ConfigType;


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

#endif /* BSWM_CFGTYPES_H */

/*==================[end of file]============================================*/

