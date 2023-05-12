/**
 * \file
 *
 * \brief AUTOSAR Dem
 *
 * This file contains the implementation of the AUTOSAR
 * module Dem.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2017 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#if (!defined DEM_CFG_H)
#define DEM_CFG_H

/* This file contains all target independent public configuration declarations
 * for the AUTOSAR module Dem. */








/*==================[includes]==============================================*/
/* !LINKSTO dsn.Dem.IncludeStr,1 */

#include <Dem_IntErrId.h>        /* BSW Event ID symbols */
#include <Dem_IntEvtId.h>        /* SW-C Event ID symbols */

#include <NvM_Types.h>           /* NvM types */

/*==================[type definitions]======================================*/

#ifndef RTE_TYPE_Dem_EventIdType
#define RTE_TYPE_Dem_EventIdType
/**  \brief Defines the Dem Event ID which is
 **  identification of an event by assigned EventId
 **  In case the Rte is available this type is defined in Rte_Type.h.
 **/
typedef uint16 Dem_EventIdType;
#endif

/*==================[macros]================================================*/

#if (defined DEM_CFG_SIGNATURE)
#error DEM_CFG_SIGNATURE is already defined
#endif
/* !LINKSTO Dem.EB.Config.Id,1 */
/** \brief Sign a certain configuration with unique hash
 **/
#define DEM_CFG_SIGNATURE 2537245479U

/*------------------[RTE configuration]-------------------------------------*/

#if (defined DEM_INCLUDE_RTE)
#error DEM_INCLUDE_RTE already defined
#endif
/** \brief Switch, indicating if RTE is available and can be used from Dem */
#define DEM_INCLUDE_RTE              STD_OFF

#if (defined DEM_SERVICE_API_NONE)
#error DEM_SERVICE_API_NONE already defined
#endif
/** \brief Definition that no default service API is set */
#define DEM_SERVICE_API_NONE    0U

#if (defined DEM_SERVICE_API_ASR40)
#error DEM_SERVICE_API_ASR40 already defined
#endif
/** \brief Definition that AUTOSAR 4.0 service API is set as default */
#define DEM_SERVICE_API_ASR40   40U

#if (defined DEM_SERVICE_API_ASR42)
#error DEM_SERVICE_API_ASR42 already defined
#endif
/** \brief Definition that AUTOSAR 4.2 service API is set as default */
#define DEM_SERVICE_API_ASR42   42U

#if (defined DEM_ENABLE_ASR40_SERVICE_API)
#error DEM_ENABLE_ASR40_SERVICE_API already defined
#endif
/** \brief Definition whether AUTOSAR 4.0 service API is enabled */
#define DEM_ENABLE_ASR40_SERVICE_API  STD_OFF

#if (defined DEM_ENABLE_ASR42_SERVICE_API)
#error DEM_ENABLE_ASR42_SERVICE_API already defined
#endif
/** \brief Definition whether AUTOSAR 4.2 service API is enabled */
#define DEM_ENABLE_ASR42_SERVICE_API  STD_OFF

#if (defined DEM_DEFAULT_ASR_SERVICE_API)
#error DEM_DEFAULT_ASR_SERVICE_API already defined
#endif
/** \brief Definition of default service API */
#define DEM_DEFAULT_ASR_SERVICE_API DEM_SERVICE_API_NONE

#if (defined DEM_USER_CTRL_WIR_SUPPORT)
#error DEM_USER_CTRL_WIR_SUPPORT already defined
#endif
/** \brief Switch, indicating if user controlled WIR-bit is enabled */
#define DEM_USER_CTRL_WIR_SUPPORT             STD_OFF
/*------------------[DTC configuration]-------------------------------------*/

#if (defined DEM_NO_DTC)
#error DEM_NO_DTC already defined
#endif
/** \brief No DTC (neither UDS nor OBD) configured for event */
#define DEM_NO_DTC                 0U

#if (defined DEM_NO_DTC_FUNCTIONAL_UNIT)
#error DEM_NO_DTC_FUNCTIONAL_UNIT already defined
#endif
/** \brief No DTC functional unit configured for event */
#define DEM_NO_DTC_FUNCTIONAL_UNIT 0U

/*------------------[General]-----------------------------------------------*/

#if (defined DEM_VERSION_INFO_API)
#error DEM_VERSION_INFO_API already defined
#endif
/** \brief Switch, indicating if Version Info is activated for Dem */
#define DEM_VERSION_INFO_API                  STD_OFF

#if (defined DEM_CALIBRATION_SUPPORT)
#error DEM_CALIBRATION_SUPPORT already defined
#endif
/** \brief Switch for calibration support */
/* !LINKSTO dsn.Dem.Calibration.Support.Macro,1 */
#define DEM_CALIBRATION_SUPPORT               STD_OFF


#if (defined DEM_POSITIVE_RESPONSE_NO_FFCLASSES)
#error DEM_POSITIVE_RESPONSE_NO_FFCLASSES already defined
#endif
/** \brief Switch for positive response when event has no FF assigned
 ** (disabled through calibration) */
/* !LINKSTO dsn.Dem.Calibration.NoFFClass.PositiveResponse,1 */
#define DEM_POSITIVE_RESPONSE_NO_FFCLASSES   STD_OFF

#if (defined DEM_CONSISTENT_FF_SIZE_SUPPORT)
#error DEM_CONSISTENT_FF_SIZE_SUPPORT already defined
#endif
/** \brief Switch for consistent FF size */
/* !LINKSTO dsn.Dem.Storage.ConsistentFFSize.Support,1 */
#define DEM_CONSISTENT_FF_SIZE_SUPPORT   STD_OFF


#if (defined DEM_COMMON_OPERATION_CYCLE_SUPPORT)
#error DEM_COMMON_OPERATION_CYCLE_SUPPORT already defined
#endif
/** \brief Switch for common operation cycle support */
/* !LINKSTO dsn.Dem.CommonOperationCycle.Support.Macro,1 */
#define DEM_COMMON_OPERATION_CYCLE_SUPPORT    STD_OFF

#if (defined DEM_AGINGALLOWED_CONVENIENT_CALIBRATION)
#error DEM_AGINGALLOWED_CONVENIENT_CALIBRATION already defined
#endif
/** \brief Switch to enable a convenient way of aging allowed calibration */
/* !LINKSTO dsn.Dem.Calibration.AgingAllowedConvenient.Macro,1 */
#define DEM_AGINGALLOWED_CONVENIENT_CALIBRATION    STD_OFF

#if (defined DEM_AGING_REQUIRES_TESTED_CYCLE_SET_OPERATION_CYCLE_STATE)
#error DEM_AGING_REQUIRES_TESTED_CYCLE_SET_OPERATION_CYCLE_STATE already defined
#endif
/** \brief Switch, indicating whether Dem_SetOperationCycleState() will consider or not the untested cyles */
#define DEM_AGING_REQUIRES_TESTED_CYCLE_SET_OPERATION_CYCLE_STATE    STD_ON

#if (defined DEM_AGING_REQUIRES_TESTED_CYCLE_SET_AGING_CYCLE_STATE)
#error DEM_AGING_REQUIRES_TESTED_CYCLE_SET_AGING_CYCLE_STATE already defined
#endif
/** \brief Switch, indicating whether Dem_SetAgingCycleState() will consider or not the untested cyles */
#define DEM_AGING_REQUIRES_TESTED_CYCLE_SET_AGING_CYCLE_STATE        STD_OFF

#if (defined DEM_AGING_BASED_ON_HEALING_COMPLETION_SUPPORT)
#error DEM_AGING_BASED_ON_HEALING_COMPLETION_SUPPORT already defined
#endif
/** \brief Switch, indicating whether aging process should start only after healing is finished */
#define DEM_AGING_BASED_ON_HEALING_COMPLETION_SUPPORT    STD_OFF

#if (defined DEM_CB_TRIG_ON_EVDAT_ASR403)
#error DEM_CB_TRIG_ON_EVDAT_ASR403 already defined
#endif
/** \brief Switch, indicating whether EventDataChanged callback triggering behavior
 ** will be done according to ASR4.0.3 or or to ASR4.2.1 */
/* !LINKSTO dsn.Dem.CallbackEventDataChangedASR403.Macro,1 */
#define DEM_CB_TRIG_ON_EVDAT_ASR403    STD_OFF

#if (defined DEM_EVENT_DISABLING_SUPPORT)
#error DEM_EVENT_DISABLING_SUPPORT already defined
#endif
/** \brief Switch for DTC availability support */
#define DEM_EVENT_DISABLING_SUPPORT           STD_OFF

#if (defined DEM_CLEAR_DTC_OF_DISABLED_EVENTS )
#error DEM_CLEAR_DTC_OF_DISABLED_EVENTS  already defined
#endif
/** \brief Switch to support clearing of DTCs for disabled events */
#define DEM_CLEAR_DTC_OF_DISABLED_EVENTS            STD_OFF

#if (defined DEM_USE_CLEAR_DTC_BURST_REDUCTION )
#error DEM_USE_CLEAR_DTC_BURST_REDUCTION  already defined
#endif
 /* !LINKSTO dsn.Dem.ClearDTCBurstReduction.Config,1 */
/** \brief Switch to support asynchronous Dem_ClearDTC handling */
#define DEM_USE_CLEAR_DTC_BURST_REDUCTION            STD_OFF


#if (defined DEM_EVENTCLASS_SUPPORT)
#error DEM_EVENTCLASS_SUPPORT already defined
#endif
/** \brief Switch for event class support */
#define DEM_EVENTCLASS_SUPPORT                STD_OFF

#if (defined DEM_DTC_STATUS_AVAILABILITY_MASK)
#error DEM_DTC_STATUS_AVAILABILITY_MASK already defined
#endif
/** \brief DTC status availability mask */
#define DEM_DTC_STATUS_AVAILABILITY_MASK    255U

#if (defined DEM_STATUS_BIT_STORAGE_TF)
#error DEM_STATUS_BIT_STORAGE_TF already defined
#endif
/** \brief Switch, indicating if permanent storage of the
 ** "TestFailed" status bit is activated */
#define DEM_STATUS_BIT_STORAGE_TF             STD_ON

#if (defined DEM_RESET_PENDING_BIT_ON_OVERFLOW_SUPPORT)
#error DEM_RESET_PENDING_BIT_ON_OVERFLOW_SUPPORT already defined
#endif
/** \brief Switch, indicating if the pending bit is reset or
 ** not while an event memory entry will be displaced */
#define DEM_RESET_PENDING_BIT_ON_OVERFLOW_SUPPORT     STD_OFF

#if (defined DEM_RESET_CONFIRMED_BIT_ON_OVERFLOW_SUPPORT)
#error DEM_RESET_CONFIRMED_BIT_ON_OVERFLOW_SUPPORT already defined
#endif
/** \brief Switch, indicating if the confirmed bit is reset or
 ** not while an event memory entry will be displaced */
#define DEM_RESET_CONFIRMED_BIT_ON_OVERFLOW_SUPPORT     STD_ON

#if (defined DEM_UPDATE_OCCORDER_ON_EVENTENTRY_UPDATE)
#error DEM_UPDATE_OCCORDER_ON_EVENTENTRY_UPDATE already defined
#endif
/** \brief Switch, indicating whether the OccOrder shall be updated
 ** at every event entry update */
#define DEM_UPDATE_OCCORDER_ON_EVENTENTRY_UPDATE    STD_ON

#if (defined DEM_USE_PERMANENT_STORAGE)
#error DEM_USE_PERMANENT_STORAGE already defined
#endif
/** \brief Switch, indicating if Permanent storage of event
 ** memory entries in NvM is activated for
 ** Dem */
#define DEM_USE_PERMANENT_STORAGE             STD_ON

#if (defined DEM_OPCYC_NVSTORAGE)
#error DEM_OPCYC_NVSTORAGE already defined
#endif
/** \brief Switch, indicating if permanent storage of operation cycle entries
 ** to NVRAM is enabled */
#define DEM_OPCYC_NVSTORAGE                   STD_OFF

#if (defined DEM_OPCYCLESTATE)
#error DEM_OPCYCLESTATE already defined
#endif
/** \brief Macro to get the operation cycle states based on permanent storage
 ** of operation cycle entries to NVRAM */
#define DEM_OPCYCLESTATE             Dem_OpCycleState

/* !LINKSTO Dem.OperationCyclePermStorage.FDC,1 */
#if (defined DEM_NUM_DEBOUNCE_COUNTER_PERM)
#error DEM_NUM_DEBOUNCE_COUNTER_PERM already defined
#endif
/** \brief Number of counter debounced events with permanent debounce
 ** counter storage
 **/
#define DEM_NUM_DEBOUNCE_COUNTER_PERM  0U

#if (defined DEM_NVM_BLOCK_ID_INVALID)
#error DEM_NVM_BLOCK_ID_INVALID already defined
#endif
/** \brief NvM block Id does not exist as it is not configured */
#define DEM_NVM_BLOCK_ID_INVALID      0U

#if (defined DEM_NVM_BLOCK_ID_DEFAULT)
#error DEM_NVM_BLOCK_ID_DEFAULT already defined
#endif
/** \brief NvM block Id for Dem default block */
#define DEM_NVM_BLOCK_ID_DEFAULT   NVM_BLOCK_DEM_DEFAULT

#if (defined DEM_NVM_BLOCK_ID_PRIMARY)
#error DEM_NVM_BLOCK_ID_PRIMARY already defined
#endif
/** \brief NvM block Id for Dem primary block */
#define DEM_NVM_BLOCK_ID_PRIMARY   NVM_BLOCK_DEM_PRIMARY

#if (defined DEM_NVM_BLOCK_ID_MIRROR)
#error DEM_NVM_BLOCK_ID_MIRROR already defined
#endif
/** \brief Invalid block Id for Dem mirror block as
** no event using mirror memory is configured */
#define DEM_NVM_BLOCK_ID_MIRROR    DEM_NVM_BLOCK_ID_INVALID

#if (defined DEM_NVM_BLOCK_ID_SECONDARY)
#error DEM_NVM_BLOCK_ID_SECONDARY already defined
#endif
/** \brief NvM block Id for Dem secondary block */
#define DEM_NVM_BLOCK_ID_SECONDARY NVM_BLOCK_DEM_SECONDARY

#if (defined DEM_NVM_BLOCK_ID_PERMANENT)
#error DEM_NVM_BLOCK_ID_PERMANENT already defined
#endif

  /** \brief Invalid block Id for Dem permanent block as permanent memory is not configured */
#define DEM_NVM_BLOCK_ID_PERMANENT DEM_NVM_BLOCK_ID_INVALID

/** \brief Maximum number of events over all memory sources */

#if (defined DEM_MAX_NUM_ORDERED_EVENT_IDS)
#error DEM_MAX_NUM_ORDERED_EVENT_IDS already defined
#endif
/** \brief Array size for ordered output of filtered DTCs */
#define DEM_MAX_NUM_ORDERED_EVENT_IDS 20U

#if (defined DEM_TYPE_OF_ORIGIN_SUPPORTED)
#error DEM_TYPE_OF_ORIGIN_SUPPORTED already defined
#endif
/** \brief Supported origin types
 **
 ** This macro is only exported and not used internally.
 ** It is derived from ::DEM_MAX_NUMBER_EVENT_ENTRY_PRI,
 ** ::DEM_MAX_NUMBER_EVENT_ENTRY_SEC, ::DEM_MAX_NUMBER_EVENT_ENTRY_MIR, and
 ** ::DEM_MAX_NUMBER_EVENT_ENTRY_PER.
 **
 ** \note Macro name is still existing for compatibility reasons with AR2.1.
 **/
#define DEM_TYPE_OF_ORIGIN_SUPPORTED 3U

#if (defined DEM_DEV_ERROR_DETECT)
#error DEM_DEV_ERROR_DETECT already defined
#endif
/* !LINKSTO Dem113,1 */
/** \brief Switch, indicating if development error detection is activated for
 ** Dem */
#define DEM_DEV_ERROR_DETECT         STD_ON

#if (defined DEM_TYPE_OF_DTC_SUPPORTED)
#error DEM_TYPE_OF_DTC_SUPPORTED already defined
#endif
/** \brief Returned DTC translation format by Dem_GetTranslationType()
 **
 ** \note Macro name is conform to the vague definition in chapter 10 of SWS.
 **/
#define DEM_TYPE_OF_DTC_SUPPORTED    DEM_DTC_TRANSLATION_ISO14229_1

#if (defined DEM_DCM_ENABLED)
#error DEM_DCM_ENABLED already defined
#endif
/** \brief Switch, indicating whether Dcm module should be a part of Dem */
#define DEM_DCM_ENABLED              STD_ON

#if (defined DEM_GET_DTCBYOCCURRENCETIME_SUPPORT)
#error DEM_GET_DTCBYOCCURRENCETIME_SUPPORT already defined
#endif
/** \brief Switch, indicating the existence of the functionality provided
 **  by Dem_GetDTCByOccurrenceTime() and the existence of the function itself
 **  to the Dcm module.
 **/
#define DEM_GET_DTCBYOCCURRENCETIME_SUPPORT      STD_ON

#if (defined DEM_STORE_INTERNAL_EVENTS)
#error DEM_STORE_INTERNAL_EVENTS already defined
#endif
/** \brief Switch, indicating whether DTC=0 means event storage disabled */
#define DEM_STORE_INTERNAL_EVENTS       STD_ON

#if (defined DEM_GET_SIZEOFEDRBYDTC_OPTIMIZATION)
#error DEM_GET_SIZEOFEDRBYDTC_OPTIMIZATION already defined
#endif
/** \brief Switch, indicating optimization for calculating size in
 ** Dem_GetSizeOfExtendedDataRecordByDTC() provided to the Dcm */
#define DEM_GET_SIZEOFEDRBYDTC_OPTIMIZATION      STD_OFF

#if (defined DEM_TRIGGER_FIM_REPORTS)
#error DEM_TRIGGER_FIM_REPORTS already defined
#endif
/** \brief Switch, indicating if notification to FiM is activated for Dem */
#define DEM_TRIGGER_FIM_REPORTS      STD_OFF

#if (defined DEM_SUPPORT_FIM_ON_FDC_TRESHOLD)
#error DEM_SUPPORT_FIM_ON_FDC_TRESHOLD already defined
#endif
/** \brief Switch, indicating if FiM support for FDC threshold is activated for Dem */
#define DEM_SUPPORT_FIM_ON_FDC_TRESHOLD      STD_OFF

#if (defined DEM_TRIGGER_DCM_REPORTS)
#error DEM_TRIGGER_DCM_REPORTS already defined
#endif
/** \brief Switch, indicating if notification to Dcm is activated for Dem */
#define DEM_TRIGGER_DCM_REPORTS      STD_OFF


#if (defined DEM_USE_DYNAMIC_DTCS)
#error DEM_USE_DYNAMIC_DTCS already defined
#endif
/** \brief Macro for Enabling/Disabling dynamic DTC fetching */
#define DEM_USE_DYNAMIC_DTCS   STD_OFF

#if (defined DEM_EVCOMB_DISABLED)
#error DEM_EVCOMB_DISABLED already defined
#endif
/** \brief Macro used when no event combination is supported. */
#define DEM_EVCOMB_DISABLED                  0x00U

#if (defined DEM_EVCOMB_TYPE1)
#error DEM_EVCOMB_TYPE1  already defined
#endif
/** \brief Event combination is available and combined DTCs are stored/updated
    in a single event memory entry. */
#define DEM_EVCOMB_TYPE1                     0x01U

#if (defined DEM_EVENT_COMBINATION_SUPPORT)
#error DEM_EVENT_COMBINATION_SUPPORT already defined
#endif
/** \brief Macro for Enabling/Disabling event combination support. */
#define DEM_EVENT_COMBINATION_SUPPORT   DEM_EVCOMB_DISABLED

#if (defined DEM_NUM_CMB_DTCS)
#error DEM_NUM_CMB_DTCS already defined
#endif
/** \brief Define the number of combined DTCs.
 **
 ** This define will be present always in order to know if events are combined.
 ** Could be that event combination is configured and no events are combined.
 **/
#define DEM_NUM_CMB_DTCS   0U

#if (defined DEM_INIT_MONITOR_REENABLED_SUPPORT)
#error DEM_INIT_MONITOR_REENABLED_SUPPORT already defined
#endif
 /** \brief Macro for Enabling/Disabling support for InitMonitorReason DEM_INIT_MONITOR_REENABLED*/
#define DEM_INIT_MONITOR_REENABLED_SUPPORT   STD_OFF

#if (defined DEM_USE_EVENT_DISPLACEMENT)
#error DEM_USE_EVENT_DISPLACEMENT already defined
#endif
/** \brief Switch, indicating if event displacement support is activated for
 ** Dem */
#define DEM_USE_EVENT_DISPLACEMENT   STD_ON

#if (defined DEM_USE_ADVANCED_EVENT_DISPLACEMENT)
#error DEM_USE_ADVANCED_EVENT_DISPLACEMENT already defined
#endif
/** \brief advanced displacement not used **/
#define DEM_USE_ADVANCED_EVENT_DISPLACEMENT STD_OFF

#if (defined DEM_DISPLACEMENT_NONE)
#error DEM_DISPLACEMENT_NONE already defined
#endif
/** \brief Event memory entry displacement is disabled */
#define DEM_DISPLACEMENT_NONE                  0x00U

#if (defined DEM_DISPLACEMENT_PRIO_OCC)
#error DEM_DISPLACEMENT_PRIO_OCC already defined
#endif
/** \brief Event memory entry displacement is enabled, by consideration of
 ** priority and occurrence (but without active/passive status) */
#define DEM_DISPLACEMENT_PRIO_OCC              0x01U

#if (defined DEM_DISPLACEMENT_FULL)
#error DEM_DISPLACEMENT_FULL already defined
#endif
/** \brief Event memory entry displacement is enabled, by consideration of
 ** priority active/passive status, and occurrence */
#define DEM_DISPLACEMENT_FULL                  0x02U

#if (defined DEM_EVENT_DISPLACEMENT_STRATEGY)
#error DEM_EVENT_DISPLACEMENT_STRATEGY already defined
#endif
/** \brief Switch, indicating which displacement strategy is followed */
#define DEM_EVENT_DISPLACEMENT_STRATEGY DEM_DISPLACEMENT_FULL

#ifndef DEM_STATUS_BIT_AGING_AND_DISPLACEMENT
/** \brief The "TestFailedSinceLastClear" status bits are reset to 0, if
 ** aging or displacement applies (like done for the "ConfirmedDTC" status
 ** bits) */
#define DEM_STATUS_BIT_AGING_AND_DISPLACEMENT  0x00U
#endif

#ifndef DEM_STATUS_BIT_NORMAL
/** \brief The aging and displacement has no impact on the
 ** "TestFailedSinceLastClear" status bits */
#define DEM_STATUS_BIT_NORMAL                  0x01U
#endif

#if (defined DEM_STATUS_BIT_HANDLING_TESTFAILEDSINCELASTCLEAR)
#error DEM_STATUS_BIT_HANDLING_TESTFAILEDSINCELASTCLEAR already defined
#endif
/** \brief Switch, indicating if the aging and displacement mechanism shall be
 ** applied to the "TestFailedSinceLastClear" status bits */
#define DEM_STATUS_BIT_HANDLING_TESTFAILEDSINCELASTCLEAR \
  DEM_STATUS_BIT_NORMAL

#if (defined DEM_CLRRESP_VOLATILE)
#error DEM_CLRRESP_VOLATILE already defined
#endif
#define DEM_CLRRESP_VOLATILE            0U

#if (defined DEM_CLRRESP_NONVOLATILE_TRIGGER)
#error DEM_CLRRESP_NONVOLATILE_TRIGGER already defined
#endif
#define DEM_CLRRESP_NONVOLATILE_TRIGGER 1U

#if (defined DEM_CLRRESP_NONVOLATILE_FINISH)
#error DEM_CLRRESP_NONVOLATILE_FINISH already defined
#endif
#define DEM_CLRRESP_NONVOLATILE_FINISH  2U

#if (defined DEM_CLEAR_DTC_BEHAVIOR)
#error DEM_CLEAR_DTC_BEHAVIOR already defined
#endif
/** \brief Behaviour of ClearDTC */
#define DEM_CLEAR_DTC_BEHAVIOR  DEM_CLRRESP_NONVOLATILE_FINISH

#if (defined DEM_OBD_DEP_SEC_ECU)
#error DEM_OBD_DEP_SEC_ECU already defined
#endif
#define DEM_OBD_DEP_SEC_ECU      0U

#if (defined DEM_OBD_MASTER_ECU)
#error DEM_OBD_MASTER_ECU already defined
#endif
#define DEM_OBD_MASTER_ECU       1U

#if (defined DEM_OBD_NO_OBD_SUPPORT)
#error DEM_OBD_NO_OBD_SUPPORT already defined
#endif
#define DEM_OBD_NO_OBD_SUPPORT   2U

#if (defined DEM_OBD_PRIMARY_ECU)
#error DEM_OBD_PRIMARY_ECU already defined
#endif
#define DEM_OBD_PRIMARY_ECU      3U

/* !LINKSTO ECUC_Dem_00698_1,1 */
#if (defined DEM_OBD_Support_Kind)
#error DEM_OBD_Support_Kind already defined
#endif
/* !LINKSTO Dem_OBD_0080,1 */
/** \brief Switch defines OBD support and kind of OBD ECU */
#define DEM_OBD_Support_Kind    DEM_OBD_NO_OBD_SUPPORT

#if (defined DEM_NUM_FFPARTS)
#error DEM_NUM_FFPARTS already defined
#endif
/** \brief The Number of freeze frame parts of an event entry
 **   (common + individual or only individual) */
#define DEM_NUM_FFPARTS     1U


#define DEM_STATIC  STATIC
/*------------------[Event burst reduction]------------------------*/
/* !LINKSTO dsn.Dem.EventBurstReduction.MaxPassed,1 */
#if (defined DEM_MAX_HANDLED_PASSED_EVENTS_PER_SCHEDULING)
#error DEM_MAX_HANDLED_PASSED_EVENTS_PER_SCHEDULING already defined
#endif
/** \brief The number of passed events handled per Dem_MainFunction call */
#define DEM_MAX_HANDLED_PASSED_EVENTS_PER_SCHEDULING 255U

/* !LINKSTO dsn.Dem.EventBurstReduction.MaxFailed,1 */
#if (defined DEM_MAX_HANDLED_FAILED_EVENTS_PER_SCHEDULING)
#error DEM_MAX_HANDLED_FAILED_EVENTS_PER_SCHEDULING already defined
#endif
/** \brief The number of failed events handled per Dem_MainFunction call */
#define DEM_MAX_HANDLED_FAILED_EVENTS_PER_SCHEDULING 255U


/* !LINKSTO Dem_OBD_0001,2 */
#if (defined DEM_OBD_Support)
#error DEM_OBD_Support already defined
#endif
 /** \brief Switch, indicating if OBD functionalities are enabled */
#define DEM_OBD_Support         STD_OFF

/*------------------[Common Freeze Frame]--------------------------------*/

#if (defined DEM_COMMON_FF_CLASS_IDX)
#error DEM_COMMON_FF_CLASS_IDX already defined
#endif
/** \brief Defines the index of the regular common freeze frame class */
#define DEM_COMMON_FF_CLASS_IDX   DEM_FFCLS_NULL_IDX

#if (defined DEM_COMMON_FREEZEFRAMES_USED)
#error DEM_COMMON_FREEZEFRAMES_USED already defined
#endif
/** \brief Defines if any common freeze frame class is configured */
#define DEM_COMMON_FREEZEFRAMES_USED   STD_OFF

/*------------------[Development Freeze Frame]------------------------------*/

/* !LINKSTO dsn.Dem.DevFF.Encapsulation,1 */
#if (defined DEM_DEV_FREEZE_FRAME_USED)
#error DEM_DEV_FREEZE_FRAME_USED already defined
#endif
/** \brief Switch, indicating if Development Freeze Frames are enabled */
#define DEM_DEV_FREEZE_FRAME_USED   STD_OFF

/* !LINKSTO dsn.Dem.DevFF.DemCommonFFDataDevAClassRef,1 */
#if (defined DEM_COMMON_DEVFFA_CLASS_IDX)
#error DEM_COMMON_DEVFFA_CLASS_IDX already defined
#endif
/** \brief Switch, indicating if Development Freeze Frames are enabled */
#define DEM_COMMON_DEVFFA_CLASS_IDX   DEM_FFCLS_NULL_IDX

#if (defined DEM_DEV_FFA_MAX_CLASS_SIZE)
#error DEM_DEV_FFA_MAX_CLASS_SIZE already defined
#endif
/** \brief Size of largest configured Development Freeze Frames A class
 ** including the Common Development Freeze Frame A part
 **/
/* !LINKSTO dsn.Dem.DevFF.DemMaxNumberDevFreezeFrameAEntry, 1 */
#define DEM_DEV_FFA_MAX_CLASS_SIZE 0U

#if (defined DEM_MAX_NUMBER_DEVFFA_ENTRY)
#error DEM_MAX_NUMBER_DEVFFA_ENTRY already defined
#endif
#define DEM_MAX_NUMBER_DEVFFA_ENTRY   0U

#if (defined DEM_MAX_NUMBER_DEVFFB_ENTRY)
#error DEM_MAX_NUMBER_DEVFFB_ENTRY already defined
#endif
#define DEM_MAX_NUMBER_DEVFFB_ENTRY   0U

#if (defined DEM_DEV_FFB_MAX_CLASS_SIZE)
#error DEM_DEV_FFB_MAX_CLASS_SIZE already defined
#endif
/** \brief Size of largest configured Development Freeze Frames A class
 **/
#define DEM_DEV_FFB_MAX_CLASS_SIZE 0U

/*------------------[IUMPR function support ]----------------------------*/
/* !LINKSTO Dem.Config.IumprFunctionsEnabled,1 */
#if (defined DEM_IUMPR_FUNCTIONS_ENABLED)
#error DEM_IUMPR_FUNCTIONS_ENABLED already defined
#endif
/* Switch, indicating whether IUMPR related functions are enabled. */
#define DEM_IUMPR_FUNCTIONS_ENABLED         STD_ON

#if (defined DEM_OBD_COMPLIANCY_ENABLED)
#error DEM_OBD_COMPLIANCY_ENABLED already defined
#endif
#define DEM_OBD_COMPLIANCY_ENABLED         STD_OFF

#if (defined DEM_OBD_CENTRALIZED_PID_HANDLING)
#error DEM_OBD_CENTRALIZED_PID_HANDLING already defined
#endif
/* Switch, indicating if PID$31 is calculated Dem internally (if set to 'false')
   or returned as 0 always (if set to 'true')*/
#define DEM_OBD_CENTRALIZED_PID_HANDLING         STD_OFF




/*------------------[Indices to access PID0D and PID1F within data element class]--------------------------*/

#if (defined DEM_MAINCYCLE_TICKS_PER_SECOND)
#error DEM_MAINCYCLE_TICKS_PER_SECOND already defined
#endif
#define DEM_MAINCYCLE_TICKS_PER_SECOND 100U
/*------------------[Freeze frame configuration]----------------------------*/

/* Symbolic names of configured freeze frame data IDs */

#if (defined DEM_FFS_DID_DemDidClass_KmStand)
#error DEM_FFS_DID_DemDidClass_KmStand already defined
#endif
/** \brief Symbolic name of data ID DemDidClass_KmStand */
#define DEM_FFS_DID_DemDidClass_KmStand 5888U

#if (defined DEM_FFS_DID_DemDidClass_Systemzeit)
#error DEM_FFS_DID_DemDidClass_Systemzeit already defined
#endif
/** \brief Symbolic name of data ID DemDidClass_Systemzeit */
#define DEM_FFS_DID_DemDidClass_Systemzeit 5889U

#if (defined DEM_FFS_DID_DemDidClass_BetriebsStundenZaehler_Beginn)
#error DEM_FFS_DID_DemDidClass_BetriebsStundenZaehler_Beginn already defined
#endif
/** \brief Symbolic name of data ID DemDidClass_BetriebsStundenZaehler_Beginn */
#define DEM_FFS_DID_DemDidClass_BetriebsStundenZaehler_Beginn 16384U

#if (defined DEM_FFS_DID_DemDidClass_BetriebsStundenZaehler_Ende)
#error DEM_FFS_DID_DemDidClass_BetriebsStundenZaehler_Ende already defined
#endif
/** \brief Symbolic name of data ID DemDidClass_BetriebsStundenZaehler_Ende */
#define DEM_FFS_DID_DemDidClass_BetriebsStundenZaehler_Ende 16385U

#if (defined DEM_FFS_DID_DemDidClass_AussenTemperatur)
#error DEM_FFS_DID_DemDidClass_AussenTemperatur already defined
#endif
/** \brief Symbolic name of data ID DemDidClass_AussenTemperatur */
#define DEM_FFS_DID_DemDidClass_AussenTemperatur 16386U

#if (defined DEM_FFS_DID_DemDidClass_InnenTemperatur)
#error DEM_FFS_DID_DemDidClass_InnenTemperatur already defined
#endif
/** \brief Symbolic name of data ID DemDidClass_InnenTemperatur */
#define DEM_FFS_DID_DemDidClass_InnenTemperatur 16387U

#if (defined DEM_FFS_DID_DemDidClass_SystemZustand)
#error DEM_FFS_DID_DemDidClass_SystemZustand already defined
#endif
/** \brief Symbolic name of data ID DemDidClass_SystemZustand */
#define DEM_FFS_DID_DemDidClass_SystemZustand 16388U

#if (defined DEM_FFS_DID_DemDidClass_ZeitNachPowerOn)
#error DEM_FFS_DID_DemDidClass_ZeitNachPowerOn already defined
#endif
/** \brief Symbolic name of data ID DemDidClass_ZeitNachPowerOn */
#define DEM_FFS_DID_DemDidClass_ZeitNachPowerOn 16389U

#if (defined DEM_FFS_DID_DemDidClass_PowerOnZaehler)
#error DEM_FFS_DID_DemDidClass_PowerOnZaehler already defined
#endif
/** \brief Symbolic name of data ID DemDidClass_PowerOnZaehler */
#define DEM_FFS_DID_DemDidClass_PowerOnZaehler 16390U

#if (defined DEM_FFS_DID_DemDidClass_SgSpannung)
#error DEM_FFS_DID_DemDidClass_SgSpannung already defined
#endif
/** \brief Symbolic name of data ID DemDidClass_SgSpannung */
#define DEM_FFS_DID_DemDidClass_SgSpannung 16391U

#if (defined DEM_FFS_DID_DemDidClass_FehlercodeREMALinks)
#error DEM_FFS_DID_DemDidClass_FehlercodeREMALinks already defined
#endif
/** \brief Symbolic name of data ID DemDidClass_FehlercodeREMALinks */
#define DEM_FFS_DID_DemDidClass_FehlercodeREMALinks 16392U

#if (defined DEM_FFS_DID_DemDidClass_FehlercodeREMARechts)
#error DEM_FFS_DID_DemDidClass_FehlercodeREMARechts already defined
#endif
/** \brief Symbolic name of data ID DemDidClass_FehlercodeREMARechts */
#define DEM_FFS_DID_DemDidClass_FehlercodeREMARechts 16393U

#if (defined DEM_FFS_DID_DemDidClass_DatumUhrZeit)
#error DEM_FFS_DID_DemDidClass_DatumUhrZeit already defined
#endif
/** \brief Symbolic name of data ID DemDidClass_DatumUhrZeit */
#define DEM_FFS_DID_DemDidClass_DatumUhrZeit 16395U

#if (defined DEM_FF_RECNUM_CALCULATED)
#error DEM_FF_RECNUM_CALCULATED already defined
#endif
/** \brief Freeze frame records will be numbered consecutive starting by 1 in
 ** their chronological order */
#define DEM_FF_RECNUM_CALCULATED     0x00U

#if (defined DEM_FF_RECNUM_CONFIGURED)
#error DEM_FF_RECNUM_CONFIGURED already defined
#endif
/** \brief Freeze frame records will be numbered based on the given
 ** configuration in their chronological order */
#define DEM_FF_RECNUM_CONFIGURED     0x01U

#if (defined DEM_FREEZE_FRAME_REC_NUMERATION_TYPE)
#error DEM_FREEZE_FRAME_REC_NUMERATION_TYPE already defined
#endif
/** \brief Type of assignment of freeze frame record numbers
 **
 ** This switch defines the type for assigning freeze frame record numbers for
 ** event-specific freeze frame records.
 **/
#define DEM_FREEZE_FRAME_REC_NUMERATION_TYPE  DEM_FF_RECNUM_CALCULATED

#if (defined DEM_MAX_NUMBER_PRESTORED_FF)
#error DEM_MAX_NUMBER_PRESTORED_FF already defined
#endif
/** \brief Maximum number of available prestored freeze frames
 **
 ** \note Macro name is conform to the vague definition in chapter 10 of SWS.
 **/
#define DEM_MAX_NUMBER_PRESTORED_FF 0U

#if (defined DEM_TRIGGER_EVENT_MEMORY_STORAGE)
#error DEM_TRIGGER_EVENT_MEMORY_STORAGE already defined
#endif
/** \brief Triggers the collection of freeze frame / extended data if the
 ** event is stored in the event memory */
#define DEM_TRIGGER_EVENT_MEMORY_STORAGE  0x00U

#if (defined DEM_TRIGGER_TESTFAILED)
#error DEM_TRIGGER_TESTFAILED already defined
#endif
/** \brief Triggers the collection of freeze frame / extended data if the
 ** UDS DTC status bit 0 (TestedFailed) changes from 0 to 1 */
#define DEM_TRIGGER_TESTFAILED            0x01U

#if (defined DEM_TRIGGER_ON_FDC_THRESHOLD)
#error DEM_TRIGGER_ON_FDC_THRESHOLD already defined
#endif
/** \brief Triggers the collection of freeze frame / extended data if the
 ** unconfirmedDTC threshold is reached */
#define DEM_TRIGGER_ON_FDC_THRESHOLD      0x02U

#if (defined DEM_FREEZE_FRAME_CAPTURE)
#error DEM_FREEZE_FRAME_CAPTURE already defined
#endif
/** \brief Type of freeze frame capture trigger
 **
 ** This parameter defines the point in time, when the freeze frame data
 ** collection is done for the initial event memory entry.
 **/
#define DEM_FREEZE_FRAME_CAPTURE          DEM_TRIGGER_EVENT_MEMORY_STORAGE

/*------------------[Extended data configuration]---------------------------*/

/* Symbolic names of configured extended data record numbers */

#if (defined DEM_EDS_NUM_ConditionByte)
#error DEM_EDS_NUM_ConditionByte already defined
#endif
/** \brief Symbolic name of extended data ConditionByte */
#define DEM_EDS_NUM_ConditionByte 1U

#if (defined DEM_EDS_NUM_OccurrenceCounter)
#error DEM_EDS_NUM_OccurrenceCounter already defined
#endif
/** \brief Symbolic name of extended data OccurrenceCounter */
#define DEM_EDS_NUM_OccurrenceCounter 2U

#if (defined DEM_EDS_NUM_AgingCounter)
#error DEM_EDS_NUM_AgingCounter already defined
#endif
/** \brief Symbolic name of extended data AgingCounter */
#define DEM_EDS_NUM_AgingCounter 3U

/* DEM_TRIGGER_<...> macros used for DEM_EXTENDED_DATA_CAPTURE are
 * defined in section 'Freeze frame configuration' */

#if (defined DEM_EXTENDED_DATA_CAPTURE)
#error DEM_EXTENDED_DATA_CAPTURE already defined
#endif
/** \brief Type of extended data capture trigger
 **
 ** This parameter defines the point in time, when the extended data
 ** collection is done for the initial event memory entry.
 **/
#define DEM_EXTENDED_DATA_CAPTURE     DEM_TRIGGER_EVENT_MEMORY_STORAGE

#if (defined DEM_NUM_EVENT_PRIORITIES)
#error DEM_NUM_EVENT_PRIORITIES already defined
#endif
    /** \brief Used for defining size of Dem_ExternalPrioValue array  */
#define DEM_NUM_EVENT_PRIORITIES      1

/*------------------[Fault confirmation configurations]---------------------*/

#if (defined DEM_NUM_FAILURECYCLES)
#error DEM_NUM_FAILURECYCLES already defined
#endif
/** \brief Number of fault confirmation configurations */
#define DEM_NUM_FAILURECYCLES 0U

#if (defined DEM_RESET_CONFIRMED_BIT_ON_OVERFLOW_SUPPORT_FAULT_CONFIRMATION)
#error DEM_RESET_CONFIRMED_BIT_ON_OVERFLOW_SUPPORT_FAULT_CONFIRMATION already defined
#endif
/** \brief Switch, indicating support for fault confirmation without event memory entry */
#define DEM_RESET_CONFIRMED_BIT_ON_OVERFLOW_SUPPORT_FAULT_CONFIRMATION     STD_OFF

#if (defined DEM_STATUS_COUNTER_SIZE)
#error DEM_STATUS_COUNTER_SIZE already defined
#endif
/** \brief Number of status counters in ::Dem_NvData
 ** per non-combined event with fault confirmation enabled */
#define DEM_STATUS_COUNTER_SIZE   0U

/*------------------[Memory size configuration]-----------------------------*/

/* !LINKSTO dsn.Dem.ErrorQueueOpt,1 */
#if (defined DEM_BSW_ERROR_BUFFER_SIZE)
#error DEM_BSW_ERROR_BUFFER_SIZE already defined
#endif
/** \brief Maximal number of error-queue entries
 **
 ** \note Macro name is conform to the vague definition in chapter 10 of SWS.
 **/
#define DEM_BSW_ERROR_BUFFER_SIZE 30U

  

/* DEM_DTC_ORIGIN_SECONDARY_MEMORY - Event DmTestAppl:
   aging counter value + DemExtendedDataCLassList_Default + 2
   * (DiagnosticFreezeFrameClass_Default + ) = 71 */
  

/* DEM_DTC_ORIGIN_PRIMARY_MEMORY - Event DmTestCom:
   aging counter value + DemExtendedDataCLassList_Default + 2
   * (DiagnosticFreezeFrameClass_Default + ) = 71 */
  

/* DEM_DTC_ORIGIN_PRIMARY_MEMORY - Event VsmEventOpmode:
   no internal values + DemExtendedDataCLassList_Default + 2
   * (DiagnosticFreezeFrameClass_Default + ) = 70 */
/* entry data sizes (IntVal + ED + Num * FF) of prm memory:
   71 70 */
/* entry data sizes (IntVal + ED + Num * FF) of sec memory:
   71 */
/* entry data sizes (IntVal + ED + Num * FF) of mir memory:
   */

#if (defined DEM_SIZE_GATE_ENTRY_DATA_PRIMARY)
#error DEM_SIZE_GATE_ENTRY_DATA_PRIMARY already defined
#endif
/** \brief Gate entry size for primary memory
 **
 ** If immediate storage is enabled for any of the events in primary memory
 ** then this size is maximum of the highest primary event memory size
 ** considering IntVal, extended data and freeze frames.
 ** If maximum calculated size is 0, then default 1 is used.
 */
#define DEM_SIZE_GATE_ENTRY_DATA_PRIMARY   71U

#if (defined DEM_SIZE_GATE_ENTRY_DATA_SECONDARY)
#error DEM_SIZE_GATE_ENTRY_DATA_SECONDARY already defined
#endif
/** \brief Gate entry size for secondary memory
 **
 ** If immediate storage is enabled for any of the events in secondary memory
 ** then this size is maximum of the highest secondary event memory size
 ** considering IntVal, extended data and freeze frames.
 ** If maximum calculated size is 0, then default 1 is used.
 */
#define DEM_SIZE_GATE_ENTRY_DATA_SECONDARY 71U

#if (defined DEM_SIZE_GATE_ENTRY_DATA_MIRROR)
#error DEM_SIZE_GATE_ENTRY_DATA_MIRROR already defined
#endif
/** \brief Gate entry size for mirror memory
 **
 ** If immediate storage is enabled for any of the events in mirror memory
 ** then this size is maximum of the highest mirror event memory size
 ** considering IntVal, extended data and freeze frames.
 ** If maximum calculated size is 0, then default 1 is used.
 */
#define DEM_SIZE_GATE_ENTRY_DATA_MIRROR    1U

#if (defined DEM_SIZE_GATE_ENTRY_DATA_PERMANENT)
#error DEM_SIZE_GATE_ENTRY_DATA_PERMANENT already defined
#endif
/** \brief Gate entry size for permanent memory
 **
 ** As this event memory type is not supported this shall be default 1.
 */
#define DEM_SIZE_GATE_ENTRY_DATA_PERMANENT 1U

#if (defined DEM_USE_IMMEDIATE_NV_STORAGE)
#error DEM_USE_IMMEDIATE_NV_STORAGE already defined
#endif
/** \brief Switch, indicating if Immediate storage of event memory entries in
 ** NvM is activated for Dem
 **
 ** This can be the case if any DTC is configured to be stored immediately, or
 ** if ClearDTC behavior is configured to non-volatile triggered or finished.
 */
#define DEM_USE_IMMEDIATE_NV_STORAGE    STD_ON

#if (defined DEM_NV_STORAGE_EMPTY_EVMEM_ENTRIES)
#error DEM_NV_STORAGE_EMPTY_EVMEM_ENTRIES already defined
#endif
/* !LINKSTO Dem.NvStorageEmptyEvMemEntries.Config,1 */
/** \brief Switch, indicating if empty event memory entries will be
 ** initialized in NVRAM
 **
 ** If the restoration of an event memory entry from NvM was not successful,
 ** this switch controls (esp. for ::DEM_USE_IMMEDIATE_NV_STORAGE = ON) if
 ** this entry is initialized with default values during next shutdown.
 */
#define DEM_NV_STORAGE_EMPTY_EVMEM_ENTRIES    STD_ON

#if (DEM_USE_IMMEDIATE_NV_STORAGE == STD_ON)

#if (defined DEM_IMMEDIATE_CLEARED)
#error DEM_IMMEDIATE_CLEARED already defined
#endif
/** \brief Immediate storage configuration value: store CLEARED entries */
#define DEM_IMMEDIATE_CLEARED 0U

#if (defined DEM_IMMEDIATE_CHANGED)
#error DEM_IMMEDIATE_CHANGED already defined
#endif
/** \brief Immediate storage configuration value: store ALL entries */
#define DEM_IMMEDIATE_CHANGED 1U

#if (defined DEM_IMMEDIATE_NV_STORAGE_TYPE)
#error DEM_IMMEDIATE_NV_STORAGE_TYPE already defined
#endif
/** \brief Immediate storage configuration */
#define DEM_IMMEDIATE_NV_STORAGE_TYPE    DEM_IMMEDIATE_CHANGED

#endif /* (DEM_USE_IMMEDIATE_NV_STORAGE == STD_ON) */

#if (defined DEM_IMMEDIATE_NV_STORAGE_LIMIT)
#error DEM_IMMEDIATE_NV_STORAGE_LIMIT already defined
#endif
/** \brief Immediate NvM storage limit
 **
 ** Defines the maximum number of occurrences, a specific event memory entry
 ** is allowed, to be stored in NVRAM immediately.
 ** Its value is set to 0 when the immediate storage limit feature is
 ** disabled by the user. In that case, there is no limit for the storage to
 ** NVRAM and whenever the entry gets updated, it can be stored immediately
 ** to NVRAM if immediate storage is enabled for it.
 **/
#define DEM_IMMEDIATE_NV_STORAGE_LIMIT     0U

#if (defined DEM_ZERO_END)
#error DEM_ZERO_END already defined
#endif
/** \brief Zero value to be added to each size, whose involved patterns could
 ** be none */
#define DEM_ZERO_END                  0U

#if (defined DEM_SIZE_ENTRY_DATA_PRIMARY)
#error DEM_SIZE_ENTRY_DATA_PRIMARY already defined
#endif
/** \brief Size of dynamic primary entry data
 **
 ** The N (primary memory entry number) maximal sizes are added.
 **
 ** \note The DEM_ZERO_END is not necessary here, because primary event memory
 **       is always > 0.
 **/
#define DEM_SIZE_ENTRY_DATA_PRIMARY   \
  (71U + 70U + 0U + 0U + 0U + 0U + 0U + 0U + 0U + 0U + 0U + 0U + 0U + 0U + 0U + 0U + 0U + 0U + 0U + 0U  )
/* !LINKSTO dsn.Dem.Dem_EntryData.MaxSize,1 */
#if DEM_SIZE_ENTRY_DATA_PRIMARY > 0xFFFFU
#error The total size of the dynamic primary entry data exceed 65535 byte. \
  Please reduce size or remove Extended Data Recordes, Freeze Frame Classes, or \
  number of Freeze Frame Records to reduce the needed space.
#endif

#if (defined DEM_SIZE_ENTRY_DATA_SECONDARY)
#error DEM_SIZE_ENTRY_DATA_SECONDARY already defined
#endif
/** \brief Size of dynamic secondary entry data
 **
 ** The N (secondary memory entry number) maximal sizes are added.
 **/
#define DEM_SIZE_ENTRY_DATA_SECONDARY \
  (71U + 0U + 0U + 0U + 0U + 0U + 0U + 0U + 0U + 0U + 0U + 0U + 0U + 0U + 0U +   DEM_ZERO_END)
/* !LINKSTO dsn.Dem.Dem_EntryData.MaxSize,1 */
#if DEM_SIZE_ENTRY_DATA_SECONDARY > 0xFFFFU
#error The total size of the dynamic secondary entry data exceed 65535 byte. \
  Please reduce size or remove Extended Data Recordes, Freeze Frame Classes, or \
  number of Freeze Frame Records to reduce the needed space.
#endif

#if (defined DEM_SIZE_ENTRY_DATA_MIRROR)
#error DEM_SIZE_ENTRY_DATA_MIRROR already defined
#endif
/** \brief Size of dynamic mirror entry data
 **
 ** The N (mirror memory entry number) maximal sizes are added.
 **/
#define DEM_SIZE_ENTRY_DATA_MIRROR    \
  (  DEM_ZERO_END)
/* !LINKSTO dsn.Dem.Dem_EntryData.MaxSize,1 */
#if DEM_SIZE_ENTRY_DATA_MIRROR > 0xFFFFU
#error The total size of the dynamic mirror entry data exceed 65535 byte. \
  Please reduce size or remove Extended Data Recordes, Freeze Frame Classes, or \
  number of Freeze Frame Records to reduce the needed space.
#endif

#if (defined DEM_SIZE_ENTRY_DATA_PERMANENT)
#error DEM_SIZE_ENTRY_DATA_PERMANENT already defined
#endif
/** \brief Size of dynamic permanent entry data
 **
 ** The N (permanent memory entry number) maximal sizes are added.
 **/
#define DEM_SIZE_ENTRY_DATA_PERMANENT DEM_ZERO_END

/*------------------[Events configuration]----------------------------------*/

#if (defined DEM_MAX_NUMBER_EVENT_ENTRY_PRI)
#error DEM_MAX_NUMBER_EVENT_ENTRY_PRI already defined
#endif
/** \brief Maximum number of events which can be stored in the primary memory
 **
 ** \note Macro name is conform to the vague definition in chapter 10 of SWS.
 **/
#define DEM_MAX_NUMBER_EVENT_ENTRY_PRI 20U

#if (defined DEM_MAX_NUMBER_EVENT_ENTRY_SEC)
#error DEM_MAX_NUMBER_EVENT_ENTRY_SEC already defined
#endif
/** \brief Maximum number of events which can be stored in the secondary
 ** memory
 **
 ** \note Macro name is conform to the vague definition in chapter 10 of SWS.
 **/
#define DEM_MAX_NUMBER_EVENT_ENTRY_SEC 15U

#if (defined DEM_MAX_NUMBER_EVENT_ENTRY_MIR)
#error DEM_MAX_NUMBER_EVENT_ENTRY_MIR already defined
#endif
/** \brief Maximum number of events which can be stored in the mirror memory
 **
 ** \note Macro name is conform to the vague definition in chapter 10 of SWS.
 **/
#define DEM_MAX_NUMBER_EVENT_ENTRY_MIR 0U

#if (defined DEM_MAX_NUMBER_EVENT_ENTRY_PER)
#error DEM_MAX_NUMBER_EVENT_ENTRY_PER already defined
#endif
/** \brief Maximum number of events which can be stored in the permanent memory
 **
 ** \note Macro name is conform to the vague definition in chapter 10 of SWS.
 **/

#define DEM_MAX_NUMBER_EVENT_ENTRY_PER 0U

#if (defined DEM_NUMBER_OF_EVENT_CLASSES)
#error DEM_NUMBER_OF_EVENT_CLASSES already defined
#endif
/** \brief Number of individual event classes which are present in the system
 **
 ** If calibration is enabled the Dem combine set of this parameter to one entry in Dem_EventClass[]
 **/
#define DEM_NUMBER_OF_EVENT_CLASSES 1U

#if (defined DEM_NUMBER_OF_EVENTS)
#error DEM_NUMBER_OF_EVENTS already defined
#endif
/** \brief Number of events which are present in the system
 **
 ** Calculated by number of event IDs listed in Dem_IntErrId.h and
 ** Dem_IntEvtId.h including ::DEM_EVENT_ID_INVALID.
 **
 ** \note Macro name is still existing for compatibility reasons with AR2.1.
 **/
#define DEM_NUMBER_OF_EVENTS 4U

#if (defined DEM_NUM_SWC_EVENTS)
#error DEM_NUM_SWC_EVENTS already defined
#endif
/** \brief Number of SW-C events present in the system
 **/
#define DEM_NUM_SWC_EVENTS 3U

#if (defined DEM_NUM_OF_PIDS_IN_OBDFF)
#error DEM_NUM_OF_PIDS_IN_OBDFF already defined
#endif
/** \brief Number of PIDs to be stored in OBD freeze frame **/
#define DEM_NUM_OF_PIDS_IN_OBDFF 0U

#if (defined DEM_MAX_EVENTS_PER_READINESS_GROUP)
#error DEM_MAX_EVENTS_PER_READINESS_GROUP already defined
#endif
/** \brief Maximum number of events per readiness groups
 *
 *  If calibration is enabled, this value defines the maximum number of events
 *  which can be assigned to an OBD readiness group.
 *  If calibration is disabled, this value is set to 0 which triggers an
 *  optimized implementation of OBD readiness groups.
 */
#define DEM_MAX_EVENTS_PER_READINESS_GROUP 0U

/*------------------[DTC groups configuration]------------------------------*/

/* Symbolic names of configured DTC groups */

#if (defined DEM_EMISSION_REL_DTCS_GROUP_EXIST)
#error DEM_EMISSION_REL_DTCS_GROUP_EXIST already defined
#endif
 /** \brief Switch, indicating if emision related DTC group is enabled */
#define DEM_EMISSION_REL_DTCS_GROUP_EXIST   STD_OFF

/*------------------[Warning indicators configuration]----------------------*/

/* Symbolic names of configured warning indicator IDs */


#if (defined DEM_NUMBER_OF_INDICATORS)
#error DEM_NUMBER_OF_INDICATORS already defined
#endif
/** \brief Number of warning indicators which are present in the system
 **
 ** \note Macro name is conform to the vague definition in chapter 10 of SWS.
 **/
#define DEM_NUMBER_OF_INDICATORS                0U


#if (defined DEM_NUM_INDICATOR_LINKS)
#error DEM_NUM_INDICATOR_LINKS already defined
#endif
/** \brief Number of warning indicator links
 **        In case of calibration-support a link represents an indicator class */
#define DEM_NUM_INDICATOR_LINKS                 0U


#if (defined DEM_INDICATOR_MULTIPLICITY)
#error DEM_INDICATOR_MULTIPLICITY already defined
#endif
/** \brief Number of different warning indicator which could be assigned to an
 **        event. Without calibration support the assigned indicator can not be
 **        changed.
 **/
#if (DEM_CALIBRATION_SUPPORT == STD_OFF)
#define DEM_INDICATOR_MULTIPLICITY              1U
#else
#define DEM_INDICATOR_MULTIPLICITY              DEM_NUMBER_OF_INDICATORS
#endif


#if (defined DEM_NUM_INDICATOR_COUNTER)
#error DEM_NUM_INDICATOR_COUNTER already defined
#endif
/** \brief Number of used indicator counter in ::Dem_NvData */
#if (DEM_CALIBRATION_SUPPORT == STD_OFF)
#define DEM_NUM_INDICATOR_COUNTER               DEM_NUM_INDICATOR_LINKS
#else
#define DEM_NUM_INDICATOR_COUNTER               DEM_NUMBER_OF_EVENTS
#endif


#if (defined DEM_NUM_INDICATOR_COUNTER_BIT)
#error DEM_NUM_INDICATOR_COUNTER_BIT already defined
#endif
/** \brief Number of bytes to hold one bit for each indicator counter
 **        in ::Dem_NvData for IndicatorCycleCounterRole and
 **        IndicatorCycleCounterWIRStatus */
#define DEM_NUM_INDICATOR_COUNTER_BIT           ((DEM_NUM_INDICATOR_COUNTER + 7U) / 8U)



#if (defined DEM_NUM_BSWEVENT_INDICATOR_USED)
#error DEM_NUM_BSWEVENT_INDICATOR_USED already defined
#endif
/** \brief Number of BSW events which are configured for warning indicator */
#define DEM_NUM_BSWEVENT_INDICATOR_USED         0U

/*------------------[Enable conditions configuration]-----------------------*/

/* Symbolic names of configured enable conditions */

#if (defined DemConf_DemEnableCondition_ENERGY_SAVING_MODE_FAULT_MEMORY_LOCK)
#error DemConf_DemEnableCondition_ENERGY_SAVING_MODE_FAULT_MEMORY_LOCK already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEnableCondition_ENERGY_SAVING_MODE_FAULT_MEMORY_LOCK 0U

#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_ENERGY_SAVING_MODE_FAULT_MEMORY_LOCK)
#error Dem_ENERGY_SAVING_MODE_FAULT_MEMORY_LOCK already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
** only (AUTOSAR version <= AUTOSAR 4.0 rev2)
**/
#define Dem_ENERGY_SAVING_MODE_FAULT_MEMORY_LOCK 0U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEnableCondition_FLASH_MODE_FAULT_MEMORY_LOCK)
#error DemConf_DemEnableCondition_FLASH_MODE_FAULT_MEMORY_LOCK already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEnableCondition_FLASH_MODE_FAULT_MEMORY_LOCK    1U

#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_FLASH_MODE_FAULT_MEMORY_LOCK)
#error Dem_FLASH_MODE_FAULT_MEMORY_LOCK already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
** only (AUTOSAR version <= AUTOSAR 4.0 rev2)
**/
#define Dem_FLASH_MODE_FAULT_MEMORY_LOCK    1U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */


#if (defined DEM_NUM_ENABLECONDITIONS)
#error DEM_NUM_ENABLECONDITIONS already defined
#endif
/** \brief Number of enable conditions */
#define DEM_NUM_ENABLECONDITIONS 2U

#if (defined DEM_ENCONDITIONGROUP_UNUSED)
#error DEM_ENCONDITIONGROUP_UNUSED already defined
#endif
/** \brief Used in Dem_EventDesc and Dem_EventClassDesc if a dedicated event
 ** does not refer to any enable condition group */
#define DEM_ENCONDITIONGROUP_UNUSED         DEM_NUM_ENCONDGROUPS

/*------------------[Operation and aging cycles configuration]--------------*/

#ifndef DEM_PROCESS_OPCYC_STATE
/** \brief Operation cycle processing is triggered by START/END */
#define DEM_PROCESS_OPCYC_STATE        0x00U
#endif

#ifndef DEM_PROCESS_OPCYC_COUNTER
/** \brief Operation cycle processing is triggered by collecting an external
 ** counter value */
#define DEM_PROCESS_OPCYC_COUNTER      0x01U
#endif

#if (defined DEM_OPERATION_CYCLE_PROCESSING)
#error DEM_OPERATION_CYCLE_PROCESSING already defined
#endif
/** \brief Operation cycle processing mode
 **
 ** This processing mode defines whether the operation cycles are triggered by
 ** START/END reports via Dem_SetOperationCycleState(), or collecting an
 ** external counter value via Dem_SetOperationCycleCntValue().
 **
 ** \note Macro name is NOT present in SWS. This is as per bugzilla ticket
 ** #47189.
 **/
#define DEM_OPERATION_CYCLE_PROCESSING DEM_PROCESS_OPCYC_STATE

#ifndef DEM_PROCESS_AGINGCTR_INTERN
/** \brief Aging counter processing is triggered internally */
#define DEM_PROCESS_AGINGCTR_INTERN      0x00U
#endif

#ifndef DEM_PROCESS_AGINGCTR_EXTERN
/** \brief Aging counter processing is triggered by collecting an external
 ** counter value */
#define DEM_PROCESS_AGINGCTR_EXTERN      0x01U
#endif

#if (defined DEM_AGINGCYCLE_COUNTER_PROCESSING)
#error DEM_AGINGCYCLE_COUNTER_PROCESSING already defined
#endif
/** \brief Aging counter processing mode
 **
 ** This processing mode defines whether aging is triggered via
 ** Dem_SetOperationCycleState() and Dem_SetAgingCycleState(), or via an
 ** external counter value reported by Dem_SetAgingCycleCounterValue().
 **/
#define DEM_AGINGCYCLE_COUNTER_PROCESSING DEM_PROCESS_AGINGCTR_INTERN

#if (defined DEM_PROCESS_OCCCTR_CDTC)
#error DEM_PROCESS_OCCCTR_CDTC already defined
#endif
/** \brief Occurrence counter processing is triggered
 ** after the fault confirmation was successfull
 **/
#define DEM_PROCESS_OCCCTR_CDTC    0x00U

#if (defined DEM_PROCESS_OCCCTR_TF)
#error DEM_PROCESS_OCCCTR_TF already defined
#endif
/** \brief Occurrence counter processing is triggered
 **  by the TestFailed bit only
 **/
#define DEM_PROCESS_OCCCTR_TF      0x01U

#if (defined DEM_OCCURRENCE_COUNTER_PROCESSING)
#error DEM_OCCURRENCE_COUNTER_PROCESSING already defined
#endif
/** \brief Occurrence counter processing mode
 **
 ** This switch defines the consideration of the fault confirmation
 ** process for the occurrence counter.
 **/
#define DEM_OCCURRENCE_COUNTER_PROCESSING  DEM_PROCESS_OCCCTR_CDTC

/* Symbolic names of configured operation cycle types */

#if (defined DEM_OPCYCLE_POWER_TYPE)
#error DEM_OPCYCLE_POWER_TYPE already defined
#endif
/** \brief Symbolic name of configured operation cycle type
** DEM_OPCYC_POWER for DEM_OPCYCLE_POWER.
 ** Not used in the current implementation
**/
#define DEM_OPCYCLE_POWER_TYPE               2U

 /* Symbolic names of configured operation cycles and failure cycles */

#if (defined DEM_OPCYCLE_POWER)
#error DEM_OPCYCLE_POWER already defined
#endif
/** \brief Symbolic name of operation cycle
** DEM_OPCYCLE_POWER
**/
#define DEM_OPCYCLE_POWER               0U

/* !LINKSTO dsn.Dem.OBD.OPCYC.WARMUP.Id,1 */

#if (defined DEM_NUM_OPCYCLES)
#error DEM_NUM_OPCYCLES already defined
#endif
/** \brief Number of operation cycles */
#define DEM_NUM_OPCYCLES 1U


#if (defined DEM_OPCYC_AUTO_END_ENABLED)
#error DEM_OPCYC_AUTO_END_ENABLED already defined
#endif
/** \brief automatic end of opcycle not configured for at least 1 opcycle */
#define DEM_OPCYC_AUTO_END_ENABLED STD_OFF

/* compile switch for OBD DCY */
/* !LINKSTO dsn.Dem.OBD.OPCYC.DCY.CompileSwitch,1 */
#if (defined DEM_OPCYC_OBD_DCY_USED)
#error DEM_OPCYC_OBD_DCY_USED already defined
#endif

/** \brief OBD DCY not used */
#define DEM_OPCYC_OBD_DCY_USED STD_OFF

/* !LINKSTO dsn.Dem.OBD.OPCYC.DCY.0001,1 */

/* !LINKSTO dsn.Dem.OBD.OPCYC.IGNITION.0001,1 */

/* Symbolic names of configured aging cycles */

#if (defined DEM_NUM_AGINGCYCLES)
#error DEM_NUM_AGINGCYCLES already defined
#endif
/** \brief Number of aging cycles
 **
 ** For these cycles, aging will not be performed based on the operation cycle
 ** of the respective event.
 **
 ** The value is always 0, if ::DEM_USE_AGING is switched off. */
#define DEM_NUM_AGINGCYCLES 0U

/*------------------[OCC5 Configuration]------------------------------------*/
/* !LINKSTO dsn.Dem.OBD.OCC5.VccOcc5Used,1 */
#if (defined DEM_VCC_OCC5_USED)
#error DEM_VCC_OCC5_USED already defined
#endif
          /* !LINKSTO dsn.Dem.OBD.OCC5.DemInternalDataElement,1,VCC_DEM_006_Req171v1_Implicit1,1 */
          /* !LINKSTO dsn.Dem.OBD.OCC5.DemInternalDataElement,1,VCC_DEM_006_Req171v1_Implicit1,1 */
          /* !LINKSTO dsn.Dem.OBD.OCC5.DemInternalDataElement,1,VCC_DEM_006_Req171v1_Implicit1,1 */
          /* !LINKSTO dsn.Dem.OBD.OCC5.DemInternalDataElement,1,VCC_DEM_006_Req171v1_Implicit1,1 */
          /* !LINKSTO dsn.Dem.OBD.OCC5.DemInternalDataElement,1,VCC_DEM_006_Req171v1_Implicit1,1 */
          /* !LINKSTO dsn.Dem.OBD.OCC5.DemInternalDataElement,1,VCC_DEM_006_Req171v1_Implicit1,1 */
          /* !LINKSTO dsn.Dem.OBD.OCC5.DemInternalDataElement,1,VCC_DEM_006_Req171v1_Implicit1,1 */
          /* !LINKSTO dsn.Dem.OBD.OCC5.DemInternalDataElement,1,VCC_DEM_006_Req171v1_Implicit1,1 */
          /* !LINKSTO dsn.Dem.OBD.OCC5.DemInternalDataElement,1,VCC_DEM_006_Req171v1_Implicit1,1 */
/* !LINKSTO dsn.Dem.OBD.OCC5.Encapsulation,1 */
#define DEM_VCC_OCC5_USED          STD_OFF

/*------------------[Operation Cycle Counters Configuration]----------------*/

#if (defined DEM_OPCYCLE_CTR_CSLF_SUPPORT)
#error DEM_OPCYCLE_CTR_CSLF_SUPPORT already defined
#endif
/** \brief Macro for availability of feature cycles since last failed */
#define DEM_OPCYCLE_CTR_CSLF_SUPPORT          STD_OFF

#if (defined DEM_OPCYCLE_CTR_CSFF_SUPPORT)
#error DEM_OPCYCLE_CTR_CSFF_SUPPORT already defined
#endif
/** \brief Macro for availability of feature cycles since first failed */
#define DEM_OPCYCLE_CTR_CSFF_SUPPORT          STD_OFF

#if (defined DEM_OPCYCLE_CTRS_SUPPORT)
#error DEM_OPCYCLE_CTRS_SUPPORT already defined
#endif
/** \brief Macro for availability of any of the cycle counters as specified by AUTOSAR */
#if ( (DEM_OPCYCLE_CTR_CSLF_SUPPORT == STD_ON) || (DEM_OPCYCLE_CTR_CSFF_SUPPORT == STD_ON) )
#define DEM_OPCYCLE_CTRS_SUPPORT          STD_ON
#else
#define DEM_OPCYCLE_CTRS_SUPPORT          STD_OFF
#endif


/*==================[type definitions]======================================*/

/*------------------[Dem_ConfigType]----------------------------------------*/

/** \brief This type of the external data structure shall contain the post
 **  build initialization data for the Dem.
 **
 ** \note Type is unused, as only pre-compile time support is implemented. */
typedef uint8 Dem_ConfigType;

/*------------------[Dem_FFSegIdxType]----------------------------------------*/

/** \brief Index of freeze frame segment type
 **
 ** Index concerning ::Dem_FFSegments[].
 **
 ** Note: The range (maximum of 65500) of this type is limited by the
 ** configuration (multiplicity of parameter DemDidClass).
 */
typedef uint16 Dem_FFSegIdxType;

/*==================[external function declarations]========================*/

extern void Appl_TriggerMemoryStack(const NvM_BlockIdType BlockId);


/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

#define DEM_START_SEC_CONST_UNSPECIFIED
#include <MemMap.h>


/** \brief Configuration structure */
extern CONST(Dem_ConfigType, DEM_CONST) DemConfigSet;

/* !LINKSTO Dem.Dem_FFSegId.External,1 */

#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* if !defined( DEM_CFG_H ) */
/*==================[end of file]===========================================*/
