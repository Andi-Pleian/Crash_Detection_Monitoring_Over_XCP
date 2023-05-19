
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


/* MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 1.3 (required)
 *    The macro `offsetof' shall not be used.
 *
 *    Reason:
 *    Relocatable postbuild macro requires the usage of `offsetof'.
 *
 * MISRAC2012-2) Deviated Rule: 11.4 (advisory)
 *    A cast should not be performed between a pointer type and an integral
 *    type.
 *
 *    Reason:
 *    Relocatable postbuild macro requires the cast between pointer and
 *    integral type.
 *
 * MISRAC2012-3) Deviated Rule: 11.9 (required)
 *    The macro NULL shall be the only permitted form of integer null pointer constant.
 *
 *    Reason:
 *    Macros are used in order to check the alignment for different data types.
 *
 */

/*==================[inclusions]=============================================*/

#include <BswM_PBcfg.h>
#include <TSAutosar.h>
#include <Compiler.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_NAME BswM_ConfigLayout
#define TS_PB_CFG_LAYOUT_TYPE BswM_ConstConfigLayoutType
#include <TSPBConfig_Init.h>

/*==================[macros]=================================================*/


/*==================[type definitions]=======================================*/


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/

#define BSWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <MemMap.h>

/* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-3 <START> */
BswM_ConstConfigLayoutType BswM_ConfigLayout = {
    { /* BswM_RootConfig */
        { /* BswM_RootConfig[0] */
            UINT32_C( 2147485970 ), /* PlatformSignature */
            UINT32_C( 3958107115 ), /* LcfgSignature */
            UINT32_C( 2196035756 ), /* CfgSignature */
            UINT32_C( 3527585516 ), /* PublicInfoSignature */
            UINT16_C( 3 ), /* NumRules */
            UINT16_C( 3 ), /* NumRulesDeferred */
            UINT16_C( 3 ), /* NumActionLists */
            TS_MAKEREF2CFG( RuleTable[0] ), /* RuleTable */
            TS_MAKEREF2CFG( RuleDependencyTable[0] ), /* RuleDependencyTable */
            TS_MAKEREF2CFG( RuleDependencyListRangeTable[0] ), /* RuleDependencyListRangeTable */
            TS_MAKEREF2CFG( ActionListTable[0] ), /* ActionListTable */
            TS_MAKEREF2CFG( ActionListItemTable[0] ), /* ActionListItemTable */
            TS_MAKENULLREF2CFG, /* UInt8InitialValuesTable */
            TS_MAKENULLREF2CFG, /* UInt16InitialValuesTable */
            TS_MAKENULLREF2CFG /* UInt32InitialValuesTable */
        }
    },
    { /* RuleTable */
        { /* RuleTable[0] -- BswM_EB_Rule_BswMRule_ECUM_STATE_SHUTDOWN */
            UINT16_C( 2 ), /* ID */
            UINT8_C( 0 ), /* RuleInitState */
            UINT16_C( 2 ), /* LogicalExprIndex */
            UINT16_C( 2 ), /* TrueActionListIndex */
            UINT16_C( 65535 ) /* FalseActionListIndex */
        },
        { /* RuleTable[1] -- BswM_EB_Rule_BswMRule_ECUM_STATE_PREP_SHUTDOWN */
            UINT16_C( 1 ), /* ID */
            UINT8_C( 0 ), /* RuleInitState */
            UINT16_C( 1 ), /* LogicalExprIndex */
            UINT16_C( 1 ), /* TrueActionListIndex */
            UINT16_C( 65535 ) /* FalseActionListIndex */
        },
        { /* RuleTable[2] -- BswM_EB_Rule_BswMRule_ECUM_STATE_RUN */
            UINT16_C( 0 ), /* ID */
            UINT8_C( 0 ), /* RuleInitState */
            UINT16_C( 0 ), /* LogicalExprIndex */
            UINT16_C( 0 ), /* TrueActionListIndex */
            UINT16_C( 65535 ) /* FalseActionListIndex */
        }
    },
    { /* RuleDependencyTable */
        UINT16_C( 2 ), /* RuleDependencyTable[0] -- BswM_EB_Rule_BswMRule_ECUM_STATE_RUN */
        UINT16_C( 1 ), /* RuleDependencyTable[1] -- BswM_EB_Rule_BswMRule_ECUM_STATE_PREP_SHUTDOWN */
        UINT16_C( 0 ) /* RuleDependencyTable[2] -- BswM_EB_Rule_BswMRule_ECUM_STATE_SHUTDOWN */
    },
    { /* RuleDependencyListRangeTable */
        { /* RuleDependencyListRangeTable[0] -- BswMModeRequestPort */
            UINT16_C( 0 ), /* Head */
            UINT16_C( 3 ) /* Tail */
        }
    },
    { /* ActionListTable */
        { /* ActionListTable[0] -- BswMActionList_ECUM_STATE_RUN_True */
            UINT8_C( 1 ), /* IsTriggered */
            { /* ActionListItemSegment */
                UINT16_C( 0 ), /* Head */
                UINT16_C( 2 ) /* Tail */
            }
        },
        { /* ActionListTable[1] -- BswMActionList_ECUM_STATE_PREP_SHUTDOWN_True */
            UINT8_C( 1 ), /* IsTriggered */
            { /* ActionListItemSegment */
                UINT16_C( 2 ), /* Head */
                UINT16_C( 4 ) /* Tail */
            }
        },
        { /* ActionListTable[2] -- BswMActionList_ECUM_STATE_SHUTDOWN_True */
            UINT8_C( 1 ), /* IsTriggered */
            { /* ActionListItemSegment */
                UINT16_C( 4 ), /* Head */
                UINT16_C( 6 ) /* Tail */
            }
        }
    },
    { /* ActionListItemTable */
        { /* ActionListItemTable[0] */
            UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
            UINT8_C( 0 ), /* IsAbortOnFail */
            UINT16_C( 2 ), /* ArtifactIndex */
            UINT8_C( 0 ) /* ActionType */
        },
        { /* ActionListItemTable[1] */
            UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
            UINT8_C( 0 ), /* IsAbortOnFail */
            UINT16_C( 0 ), /* ArtifactIndex */
            UINT8_C( 0 ) /* ActionType */
        },
        { /* ActionListItemTable[2] */
            UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
            UINT8_C( 0 ), /* IsAbortOnFail */
            UINT16_C( 1 ), /* ArtifactIndex */
            UINT8_C( 0 ) /* ActionType */
        },
        { /* ActionListItemTable[3] */
            UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
            UINT8_C( 0 ), /* IsAbortOnFail */
            UINT16_C( 3 ), /* ArtifactIndex */
            UINT8_C( 0 ) /* ActionType */
        },
        { /* ActionListItemTable[4] */
            UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
            UINT8_C( 0 ), /* IsAbortOnFail */
            UINT16_C( 3 ), /* ArtifactIndex */
            UINT8_C( 0 ) /* ActionType */
        },
        { /* ActionListItemTable[5] */
            UINT8_C( 0 ), /* ActionListItemType -- BSWM_ACTION */
            UINT8_C( 0 ), /* IsAbortOnFail */
            UINT16_C( 1 ), /* ArtifactIndex */
            UINT8_C( 0 ) /* ActionType */
        }
    }
};

/* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-3 <STOP> */

#define BSWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <MemMap.h>

/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/


/*==================[end of file]============================================*/

