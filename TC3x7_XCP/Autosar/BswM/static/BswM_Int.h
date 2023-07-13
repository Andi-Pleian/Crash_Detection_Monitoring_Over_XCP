#if (!defined BSWM_INT_H)
#define BSWM_INT_H
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

/* MISRA-C:2004 Deviations
 *
 * MISRA-1) Deviated Rule: 19.6 (required)
 * "'#undef' shall not be used"
 *
 * Reason:
 * As BswM_Pbcfg.h also defines the TS_RELOCATABLE_CFG_ENABLE and TS_PB_CFG_PTR_CLASS
 * macros, these need to be undefined in order for BswM_Pbcfg.h to be safely
 * included after BswM_Int.h.
 */

/*==================[inclusions]============================================*/

#include <BswM_Types.h>
#include <BswM_CfgTypes.h>

#define TS_RELOCATABLE_CFG_ENABLE BSWM_RELOCATABLE_CFG_ENABLE
#define TS_PB_CFG_PTR_CLASS BSWM_APPL_CONST
#include <TSPBConfig.h>       /* Post-build accessor macros       */

/*==================[type definitions]=======================================*/

/** \brief BswMIndexType shall be used when accessing a BswM artifact table. */
typedef uint16 BswMIndexType;

typedef enum
{
  BSWM_OTHER_ACTION,
  BSWM_PDU_GROUP_SWITCH_ACTION,
  BSWM_DEADLINE_MONITORING_CONTROL_ACTION
} BswMActionType;

/*==================[macros]=================================================*/

/* Post-Build access macros */

#define BSWM_GET_NUM_RULES(id) (BswM_PostBuildConfig[(id)].NumRules)
#define BSWM_GET_NUM_RULES_DEFERRED(id) (BswM_PostBuildConfig[(id)].NumRulesDeferred)
#define BSWM_GET_NUM_ACTION_LISTS(id) (BswM_PostBuildConfig[(id)].NumActionLists)
#define BSWM_GET_RULE_TABLE(id) (TS_UNCHECKEDGETCFG(BswM_PostBuildConfig, BswMRuleType, BSWM, BswM_PostBuildConfig[(id)].RuleTable))
#define BSWM_GET_RULE_DEPENDENCY_TABLE(id) (TS_UNCHECKEDGETCFG(BswM_PostBuildConfig, uint16, BSWM, BswM_PostBuildConfig[(id)].RuleDependencyTable))
#define BSWM_GET_RULE_DEPENDENCY_LIST_RANGE_TABLE(id) (TS_UNCHECKEDGETCFG(BswM_PostBuildConfig, BswMRangeType, BSWM, BswM_PostBuildConfig[(id)].RuleDependencyListRangeTable))
#define BSWM_GET_ACTION_LIST_TABLE(id) (TS_UNCHECKEDGETCFG(BswM_PostBuildConfig, BswMActionListType, BSWM, BswM_PostBuildConfig[(id)].ActionListTable))
#define BSWM_GET_ACTION_LIST_ITEM_TABLE(id) (TS_UNCHECKEDGETCFG(BswM_PostBuildConfig, BswMActionListItemType, BSWM, BswM_PostBuildConfig[(id)].ActionListItemTable))
#define BSWM_GET_UINT8_INITIAL_VALUES_TABLE(id) (TS_UNCHECKEDGETCFG(BswM_PostBuildConfig, uint8, BSWM, BswM_PostBuildConfig[(id)].UInt8InitialValuesTable))
#define BSWM_GET_UINT16_INITIAL_VALUES_TABLE(id) (TS_UNCHECKEDGETCFG(BswM_PostBuildConfig, uint16, BSWM, BswM_PostBuildConfig[(id)].UInt16InitialValuesTable))
#define BSWM_GET_UINT32_INITIAL_VALUES_TABLE(id) (TS_UNCHECKEDGETCFG(BswM_PostBuildConfig, uint32, BSWM, BswM_PostBuildConfig[(id)].UInt32InitialValuesTable))
#define BSWM_GET_DEADLINE_MONITORING_CONTROL_ACTION_TABLE(id) (TS_UNCHECKEDGETCFG(BswM_PostBuildConfig, BswMDeadLineMonitoringControlActionType, BSWM, BswM_PostBuildConfig[(id)].DeadLineMonitoringControlActionTable))
#define BSWM_GET_PDU_GROUP_SWITCH_ACTION_TABLE(id) (TS_UNCHECKEDGETCFG(BswM_PostBuildConfig, BswMPduGroupSwitchActionType, BSWM, BswM_PostBuildConfig[(id)].PduGroupSwitchActionTable))
#define BSWM_GET_SWITCH_IPDU_MODE_ACTION_TABLE(id) (TS_UNCHECKEDGETCFG(BswM_PostBuildConfig, BswMSwitchIPduModeActionType, BSWM, BswM_PostBuildConfig[(id)].SwitchIPduModeActionTable))
#define BSWM_GET_TRIGGER_IPDU_SEND_ACTION_TABLE(id) (TS_UNCHECKEDGETCFG(BswM_PostBuildConfig, BswMTriggerIPduSendActionType, BSWM, BswM_PostBuildConfig[(id)].TriggerIPduSendActionTable))
#define BSWM_GET_TRIGGERED_IPDU_ID_TABLE(id) (TS_UNCHECKEDGETCFG(BswM_PostBuildConfig, uint16, BSWM, BswM_PostBuildConfig[(id)].TriggeredIPduIdTable))
#define BSWM_GET_PDU_ROUTER_CONTROL_ACTION_TABLE(id) (TS_UNCHECKEDGETCFG(BswM_PostBuildConfig, BswMPduRouterControlActionType, BSWM, BswM_PostBuildConfig[(id)].PduRouterControlActionTable))
#define BSWM_GET_PDUR_ROUTING_PATH_GROUP_ID_TABLE(id) (TS_UNCHECKEDGETCFG(BswM_PostBuildConfig, uint16, BSWM, BswM_PostBuildConfig[(id)].PduRRoutingPathGroupIdTable))
#define BSWM_GET_LIN_SCHEDULE_SWITCH_ACTION_TABLE(id) (TS_UNCHECKEDGETCFG(BswM_PostBuildConfig, BswMLinScheduleSwitchActionType, BSWM, BswM_PostBuildConfig[(id)].LinScheduleSwitchActionTable))

#if (defined BSWM_ACTION)
#error BSWM_ACTION is already defined
#endif
 /** \brief A BswM action shall be executed. */
#define  BSWM_ACTION 0U

#if (defined BSWM_ACTION_LIST)
#error BSWM_ACTION_LIST is already defined
#endif
 /** \brief A BswM action list shall be executed. */
#define  BSWM_ACTION_LIST 1U

#if (defined BSWM_RULE)
#error BSWM_RULE is already defined
#endif
 /** \brief A BswM rule shall be executed. */
#define  BSWM_RULE 2U

#if (defined BSWM_FALSE)
#error BSWM_FALSE is already defined
#endif
#define BSWM_FALSE 0U

#if (defined BSWM_TRUE)
#error BSWM_TRUE is already defined
#endif
#define BSWM_TRUE 1U

#if (defined BSWM_UNDEFINED)
#error BSWM_UNDEFINED is already defined
#endif
#define BSWM_UNDEFINED 2U

#if (defined BSWM_PDUR_DISABLE)
#error BSWM_PDUR_DISABLE is already defined
#endif
/** \brief The routing of the corresponding PDU should be disabled. */
#define BSWM_PDUR_DISABLE 0U

#if (defined BSWM_PDUR_ENABLE)
#error BSWM_PDUR_ENABLE is already defined
#endif
/** \brief The routing of the corresponding PDU should be enabled.*/
#define BSWM_PDUR_ENABLE 1U

/** \brief Value assigned to a BswMIndexType when the BswM artifact is not
 ** defined. Its value shall correspond to the max value of BswMIndexType. */
#define BSWM_ARTIFACT_UNDEFINED 0xFFFFU

#if (BSWM_DEV_ERROR_DETECT == STD_ON)
#if (defined BSWM_DET_REPORT_ERROR)
#error BSWM_DET_REPORT_ERROR already defined
#endif /* if (defined BSWM_DET_REPORT_ERROR) */

/** \brief Report BswM development error */
#define BSWM_DET_REPORT_ERROR(InstId, ApiId,ErrorId)                            \
        ((void)Det_ReportError(BSWM_MODULE_ID, (InstId), (ApiId), (ErrorId)))

#endif /* if (BSWM_DEV_ERROR_DETECT == STD_ON) */

#if (defined BSWM_NETWORK_HANDLE_MAX)
#error BSWM_NETWORK_HANDLE_MAX already defined
#endif
/** \brief Network handle Id
 **
 ** Definition of Network handle Id. */
#define BSWM_NETWORK_HANDLE_MAX        255U

#if (defined BSWM_E_PARAM_INVALID)
#error BSWM_E_PARAM_INVALID already defined
#endif
/** \brief Invalid parameter error
 **
 ** DET error for invalid parameter. */
#define BSWM_E_PARAM_INVALID 128U

/** \brief VariantPreCompile is configured. */
#define BSWM_VARIANT_PRE_COMPILE 0U

/** \brief VariantLinkTime is configured. */
#define BSWM_VARIANT_LINK_TIME 1U

/** \brief VariantPostBuild is configured. */
#define BSWM_VARIANT_POST_BUILD 2U

/*------------------------[Defensive programming]----------------------------*/

#if (defined BSWM_PRECONDITION_ASSERT)
#error BSWM_PRECONDITION_ASSERT is already defined
#endif
#if (BSWM_PRECONDITION_ASSERT_ENABLED == STD_ON)
/** \brief Report an assertion violation to Det
 **
 ** \param[in] Condition Condition which is violated
 ** \param[in] ApiId Service ID of the API function */
#define BSWM_PRECONDITION_ASSERT(InstId, Condition, ApiId) \
  DET_PRECONDITION_ASSERT((Condition), BSWM_MODULE_ID, (InstId), (ApiId))
#else
#define BSWM_PRECONDITION_ASSERT(InstId, Condition, ApiId) \
  TS_PARAM_UNUSED(InstId)
#endif

#if (defined BSWM_POSTCONDITION_ASSERT)
#error BSWM_POSTCONDITION_ASSERT is already defined
#endif
#if (BSWM_POSTCONDITION_ASSERT_ENABLED == STD_ON)
/** \brief Report an assertion violation to Det
 **
 ** \param[in] Condition Condition which is violated
 ** \param[in] ApiId Service ID of the API function */
#define BSWM_POSTCONDITION_ASSERT(InstId, Condition, ApiId) \
  DET_POSTCONDITION_ASSERT((Condition), BSWM_MODULE_ID, (InstId), (ApiId))
#else
#define BSWM_POSTCONDITION_ASSERT(InstId, Condition, ApiId)
#endif

#if (defined BSWM_INVARIANT_ASSERT)
#error BSWM_INVARIANT_ASSERT is already defined
#endif
#if (BSWM_INVARIANT_ASSERT_ENABLED == STD_ON)
/** \brief Report an assertion violation to Det
 **
 ** \param[in] Condition Condition which is violated
 ** \param[in] ApiId Service ID of the API function */
#define BSWM_INVARIANT_ASSERT(InstId, Condition, ApiId) \
  DET_INVARIANT_ASSERT((Condition), BSWM_MODULE_ID, (InstId), (ApiId))
#else
#define BSWM_INVARIANT_ASSERT(InstId, Condition, ApiId)
#endif

#if (defined BSWM_STATIC_ASSERT)
# error BSWM_STATIC_ASSERT is already defined
#endif
#if (BSWM_STATIC_ASSERT_ENABLED == STD_ON)
/** \brief Report an static assertion violation to Det
 **
 ** \param[in] Condition Condition which is violated */
# define BSWM_STATIC_ASSERT(expr) DET_STATIC_ASSERT(expr)
#else
# define BSWM_STATIC_ASSERT(expr)
#endif

#if (defined BSWM_UNREACHABLE_CODE_ASSERT)
#error BSWM_UNREACHABLE_CODE_ASSERT is already defined
#endif
#if (BSWM_UNREACHABLE_CODE_ASSERT_ENABLED == STD_ON)
/** \brief Report an unreachable code assertion violation to Det
 **
 ** \param[in] ApiId Service ID of the API function */
#define BSWM_UNREACHABLE_CODE_ASSERT(InstId, ApiId) \
  DET_UNREACHABLE_CODE_ASSERT(BSWM_MODULE_ID, (InstId), (ApiId))
#else
#define BSWM_UNREACHABLE_CODE_ASSERT(InstId, ApiId)
#endif

#if (defined BSWM_INTERNAL_API_ID)
#error BSWM_INTERNAL_API_ID is already defined
#endif
/** \brief API ID of module internal functions to be used in assertions */
#define BSWM_INTERNAL_API_ID DET_INTERNAL_API_ID

/*==================[internal function declarations]=========================*/

#define BSWM_START_SEC_CODE
#include <MemMap.h>

#if (BSWM_DEADLINE_MONITORING_CONTROL_ACTION_USED == STD_ON)
/** \brief Pushes the result of the DeadLineMonitoringControl action into the
 ** BswM's Com_IpduGroupVector for DMControl and executes the action.
 **
 ** \param pbIndex The index of the DMControl action within the post-build
 ** BswM_PB_DeadLineMonitoringControlActionTable. */
extern FUNC(void, BSWM_CODE) BswM_ExecuteDeadLineMonitoringControlAction
(
  BswMIndexType pbIndex,
  P2VAR(BswM_PartitionContextType, BSWM_VAR, BSWM_APPL_DATA) inst
);
#endif

#if (BSWM_PDU_GROUP_SWITCH_ACTION_USED)
/** \brief Pushes the result of the PduGroupSwitch action into the BswM's
 ** Com_IpduGroupVectors
 **
 ** \param pbIndex The index of the PduGroupSwitch action within the post-build
 ** BswM_PB_PduGroupSwitchActionTable. */
extern FUNC(void, BSWM_CODE) BswM_ExecutePduGroupSwitchAction
(
  BswMIndexType pbIndex,
  P2VAR(BswM_PartitionContextType, BSWM_VAR, BSWM_APPL_DATA) inst
);
#endif

#if (BSWM_PDU_ROUTER_CONTROL_ACTION_USED == STD_ON)
/** \brief Executes a PduRouterControl action defined within the post-build
 ** data structure.
 **
 ** \param pbIndex The index of the PduRouterControl action defined within the
 ** post-build BswM_PB_PduRouterControlActionTable. */
extern FUNC(void, BSWM_CODE) BswM_ExecutePduRouterControlAction
(
  BswMIndexType pbIndex,
  P2VAR(BswM_PartitionContextType, BSWM_VAR, BSWM_APPL_DATA) inst
);
#endif

/** \brief Carries out the general actions required when a port is updated.
 **
 ** Note: This function must be exported to the BswM_Lcfg.c since the Rte/SchM
 ** mode request ports will execute this function.
 **
 ** \param rule A pointer to the mode request port data structure that has been
 **        updated.
 **/
extern FUNC(boolean, BSWM_CODE) BswM_PortUpdated
(
  P2VAR(BswMBasicPortType, AUTOMATIC, BSWM_APPL_DATA) portPtr,
  P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) activatedActionLists,
  P2VAR(BswM_PartitionContextType, BSWM_VAR, BSWM_APPL_DATA) inst
);

/** \brief Executes the actions of the mode control phase.
 **
 ** \param activatedActionLists A boolean array of size
 ** BSWM_MAX_NUM_ACTION_LISTS.  For each index i set to TRUE, the corresponding
 ** action list within the BswM_PB_ActionListTable[i] will be executed.
 **/
extern FUNC(void, BSWM_CODE) BswM_ExecuteModeControl
(
  P2CONST(boolean, AUTOMATIC, BSWM_APPL_DATA) activatedActionLists,
  P2VAR(BswM_PartitionContextType, BSWM_VAR, BSWM_APPL_DATA) inst
);

#define BSWM_STOP_SEC_CODE
#include <MemMap.h>

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

#define BSWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include <MemMap.h>

/** \ brief A pointer to the PostBuild data of BswM
 **
 ** This is set by the BswM_Init function and it can point
 ** to the internal BswM_ConfigLayout variable in case of
 ** VariantPreCompile or to the structure provided by the
 ** PbcfgM in case of VariantPostBuild.
 **/
extern P2CONST(BswM_ConfigType, AUTOMATIC, BSWM_APPL_CONST) BswM_PostBuildConfig;

#define BSWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include <MemMap.h>

/*==================[internal data]==========================================*/

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/** \brief  The signature value is used to validate post build configuration
 ** against link time configuration's signature. */
extern CONST(uint32, BSWM_CONST) BswM_LcfgSignature;

#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

/* Deviation MISRA-1 */
#undef TS_RELOCATABLE_CFG_ENABLE
/* Deviation MISRA-1 */
#undef TS_PB_CFG_PTR_CLASS

#endif /* if !defined( BSWM_INT_H ) */
/*==================[end of file]============================================*/


