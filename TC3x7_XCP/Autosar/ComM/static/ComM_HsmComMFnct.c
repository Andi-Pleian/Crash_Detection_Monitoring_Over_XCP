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

/* Implementation of the state handler functions of the state machine
 * ComM.
 *
 * This file contains the implementation of the state functions.  It
 * is generated but must be edited to implement the real actions.  If the
 * state machine model is updated and the code generator regenerates the
 * files the user must manually merge the changes with any existing hand
 * written code.
 */

/*
 * MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 20.7 (required)
 * Expressions resulting from the expansion of macro parameters shall be enclosed in parentheses.
 *
 * Reason:
 * The macro is used in function parameter declarations and definitions of structure member
 * where the number of parentheses matter.
 *
 * MISRAC2012-2) Deviated Rule: 5.1 (required)
 * External identifiers shall be distinct.
 *
 * Reason:
 * The last characters of external identifiers could be significant characters.
 *
 * MISRAC2012-3) Deviated Rule: 20.10 (advisory)
 * The # and ## preprocessor operators should not be used.
 *
 * Reason:
 * Encapsulation of generic code into macros improves readability by reducing redundant code.
 *
 * MISRAC2012-4) Deviated Rule: 13.5 (required)
 * The right hand operand of a logical && or || operator shall not contain persistent side effects.
 *
 * Reason:
 * Function like macros and functions are used to read configuration settings and variables.
 * These constructs are free of side effects.
 *
 * MISRAC2012-5) Deviated Rule: 8.9 (advisory)
 * An object should be defined at block scope if its identifier only appears in a single function.
 *
 * Reason:
 * The object has internal linkage for readability improvement.
 */

/* CHECK: RULE 301 OFF (this file is partly generated, some lines may be
 * longer then 100 characters) */

/*==================[inclusions]============================================*/

/* prevent RTE symbols defined in ComM.h to be visible for ComM's .c files */
#if (defined COMM_INTERNAL_USAGE)
#error COMM_INTERNAL_USAGE already defined
#endif
#define COMM_INTERNAL_USAGE

#include <ComM_Trace.h>
#include <ComM_BSW.h>
#include <ComM_BSW_Cfg.h>
#include <ComM_Int.h>

#if (COMM_NM_ACCESS_NEEDED == STD_ON)
#include <ComM_Nm.h>             /* NM callback APIs */
#include <NmStack_Types.h> /* Nm stack specific types, includes Std_Types.h */

/* !LINKSTO ComM506_Refine_Nm,1 */
#include <Nm.h>                /* Network Management Identifiers */
#endif /* (COMM_NM_ACCESS_NEEDED == STD_ON) */

/* !LINKSTO ComM506_Refine_Dcm,1 */
#if (COMM_DCM_ENABLED == STD_ON)
#include <Dcm_Cbk.h>            /* Diagnostic communication manager */
#endif

/* !LINKSTO ComM506_Refine_BswM,1 */
#include <BswM_ComM.h>

/* !LINKSTO ComM506_Refine_CanSM,1 */
#if (COMM_CANSM_ACCESS_NEEDED == STD_ON)
#include <CanSM_ComM.h>        /* Can state manager */
#endif

/* !LINKSTO ComM506_Refine_FrSM,1 */
#if (COMM_FRSM_ACCESS_NEEDED == STD_ON)
#include <FrSM.h>              /* Flexray state manager */
#endif

/* !LINKSTO ComM506_Refine_LinSM,1 */
#if (COMM_LINSM_ACCESS_NEEDED == STD_ON)
#include <LinSM.h>             /* Lin state manager */
#endif
/* !LINKSTO ComM506_Refine_EthSM,1 */
#if (COMM_ETHSM_ACCESS_NEEDED == STD_ON)
#include <EthSM.h>             /* Eth state manager */
#endif

#if (COMM_DEV_ERROR_DETECT == STD_ON)
#include <Det.h>               /* Det API */
#endif

/*==================[macros]================================================*/

/** \brief This macro indicates, that a channel starts up 'passive',
 *         i.e. triggered by an EcuM wakeup indication, a Nm restart indication or
 *         a Nm network start indication
 */
#if (defined COMM_PASSIVE_STARTUP)
#error COMM_PASSIVE_STARTUP already defined
#endif
#define COMM_PASSIVE_STARTUP 0U

/** \brief This macro indicates, that a channel starts up 'active',
 *         i.e. triggered by a Dcm or user request.
 */
#if (defined COMM_ACTIVE_STARTUP)
#error COMM_ACTIVE_STARTUP already defined
#endif
#define COMM_ACTIVE_STARTUP  1U

#if (defined COMM_PARAM_UNUSED)
#error COMM_PARAM_UNUSED already defined
#endif

#if (defined ComM_Notify)
#error ComM_Notify already defined
#endif

#if (COMM_HSM_INST_MULTI_ENABLED == STD_ON)
#define COMM_PARAM_UNUSED(instIdx)      TS_PARAM_UNUSED(instIdx)
#define ComM_Notify(a,b)                ComM_Notify2Arg(a,b)
#else
#define COMM_PARAM_UNUSED(instIdx)      /* nothing */
#define ComM_Notify(a,b)                ComM_Notify1Arg(b)
#endif

#if (defined ComM_StartTimer)
#error ComM_StartTimer already defined
#endif
#define ComM_StartTimer(Channel,Event,StartValue) \
  do                                              \
  {                                               \
    COMM_TIMEOUT_EVENT(Channel) = (Event);        \
    COMM_TIMER(Channel)         = (StartValue);   \
  } while (0)

#if (defined ComM_StopTimer)
#error ComM_StopTimer already defined
#endif
#define ComM_StopTimer(a)  ComM_StartTimer(a, COMM_HSM_EVENT_INVALID, 0U)

/* Define wrapper to NM functions only if ComM requires Nm access */
#if (COMM_NM_ACCESS_NEEDED == STD_ON)

/* !LINKSTO ComM.EB.Dsn.ErrorHandling.Nm_PassiveStartup,1
 */
/* !LINKSTO ComM.EB.Dsn.ErrorHandling.Nm_NetworkRequest,1
 */
/* !LINKSTO ComM.EB.Dsn.ErrorHandling.Nm_NetworkRelease,1
 */
/** \brief Call wrapper to Nm_*() functions */
#if (defined COMM_NM_CALL)
#error COMM_NM_CALL already defined
#endif
/* Deviation MISRAC2012-3 */
#define COMM_NM_CALL(func,channel) ((void)Nm_##func(COMM_NM_CHANNEL_OF_CHANNEL(channel)))

/** \brief Call wrapper to call Nm_PassiveStartUp() */
#if (defined COMM_NM_PASSIVESTARTUP)
#error COMM_NM_PASSIVESTARTUP already defined
#endif
#define COMM_NM_PASSIVESTARTUP(channel) COMM_NM_CALL(PassiveStartUp,channel)
/** \brief Call wrapper to call Nm_NetworkRelease() */
#if (defined COMM_NM_NETWORKRELEASE)
#error COMM_NM_NETWORKRELEASE already defined
#endif
#define COMM_NM_NETWORKRELEASE(channel) COMM_NM_CALL(NetworkRelease,channel)
/** \brief Call wrapper to call Nm_NetworkRequest() */
#if (defined COMM_NM_NETWORKREQUEST)
#error COMM_NM_NETWORKREQUEST already defined
#endif
#define COMM_NM_NETWORKREQUEST(channel) COMM_NM_CALL(NetworkRequest,channel)
#endif  /* COMM_NM_ACCESS_NEEDED == STD_ON */

/* !LINKSTO ComM.EB.Dsn.ErrorHandling.BusSm,1 */
/** \brief Call wrapper for bus state manager function
 * <Bus>SM_GetCurrentComMode() */
#if (defined COMM_BUSSM_REQUEST_COM_MODE)
#error COMM_BUSSM_REQUEST_COM_MODE already defined
#endif
#define COMM_BUSSM_REQUEST_COM_MODE(channel, mode)                           \
  ((void) ComM_BusSMRequestComModeFpList[COMM_BUSTYPE_OF_CHANNEL(channel)]  \
  (COMM_INST(channel), (mode)))

#if (defined COMM_CHANNEL_NOCOM_INHIBITION_STATUS)
#error COMM_CHANNEL_NOCOM_INHIBITION_STATUS already defined
#endif
#if (COMM_MODE_LIMITATION_ENABLED == STD_ON)
/** \brief Evaluate NoCom Inhibition status for ComM channels
 *
 * Always FALSE if mode limitation is disabled. */
#define COMM_CHANNEL_NOCOM_INHIBITION_STATUS(a)        \
  ComM_ChannelNoComInhibitionStatus(COMM_INST(a))
#else
#define COMM_CHANNEL_NOCOM_INHIBITION_STATUS(a)  FALSE
#endif

#if (defined COMM_CHANNEL_WAKEUP_INHIBITION_STATUS)
#error COMM_CHANNEL_WAKEUP_INHIBITION_STATUS already defined
#endif
#if (COMM_WAKEUP_INHIBITION_ENABLED == STD_ON)
/** \brief WakeUp Inhibition status for ComM channels
 *
 * always FALSE if wakeup inhibition is disabled. */
#define COMM_CHANNEL_WAKEUP_INHIBITION_STATUS(a)       \
  ComM_ChannelWakeUpInhibitionStatus(COMM_INST(a))
#else
#define COMM_CHANNEL_WAKEUP_INHIBITION_STATUS(a) FALSE
#endif

/** \brief Time counter value for checking the timeouts of different states */
#if (defined COMM_TIMER)
#error COMM_TIMER already defined
#endif
#define COMM_TIMER(Channel)                     \
  COMM_INST_ACCESS(ComM_Timer,Channel)

/** \brief Time counter value for checking the timeouts of different states */
#if (defined COMM_TIMEOUT_EVENT)
#error COMM_TIMEOUT_EVENT already defined
#endif
#define COMM_TIMEOUT_EVENT(Channel)             \
  COMM_INST_ACCESS(ComM_TimeoutEvent,Channel)

/** \brief Main function period in ms for each channel in ms. */
#if (defined COMM_MAINFUNCTIONPERIODMS)
#error COMM_MAINFUNCTIONPERIODMS already defined
#endif
#define COMM_MAINFUNCTIONPERIODMS(Channel)              \
  COMM_INST_ACCESS(ComM_MainFunctionPeriodMs,Channel)

/** \brief Current mode of the ComM Channel. */
#if (defined COMM_CHANNELMODE)
#error COMM_CHANNELMODE already defined
#endif
#define COMM_CHANNELMODE(Channel)               \
  COMM_INST_ACCESS(ComM_ChannelMode,Channel)

#if (COMM_MODE_LIMITATION_ENABLED == STD_ON)
/** \brief Current mode of the ComM Channel before ComM_ClearUserRequest was called. */
#if (defined COMM_CHANNELMODE_PREVIOUS)
#error COMM_CHANNELMODE_PREVIOUS already defined
#endif
#define COMM_CHANNELMODE_PREVIOUS(Channel)               \
  COMM_INST_ACCESS(ComM_ChannelModePrevious,Channel)
#endif


/** \brief Current state of the ComM Channel. */
#if (defined COMM_CHANNELSTATE)
#error COMM_CHANNELSTATE already defined
#endif
#define COMM_CHANNELSTATE(Channel)               \
  COMM_INST_ACCESS(ComM_ChanState,Channel)

/** \brief User ID of a channel. */
#if (defined COMM_USERSOFCHANNEL)
#error COMM_USERSOFCHANNEL already defined
#endif
#define COMM_USERSOFCHANNEL(Channel,i)                  \
  (COMM_USER_OF_CHANNEL( COMM_INST(Channel),i) )

/** \brief Currently requested ComM Mode. */
#if (defined COMM_REQUESTEDCOMMODE)
#error COMM_REQUESTEDCOMMODE already defined
#endif
#define COMM_REQUESTEDCOMMODE(Channel)                  \
  COMM_INST_ACCESS(ComM_RequestedComMode,Channel)

/** \brief Ready Sleep Timeout. */
#if (defined COMM_READYSLEEPNONMTIMEOUTMS)
#error COMM_READYSLEEPNONMTIMEOUTMS already defined
#endif
#define COMM_READYSLEEPNONMTIMEOUTMS(Channel)                   \
  COMM_INST_ACCESS(ComM_ReadySleepNoNmTimeoutMs,Channel)

/** \brief Full Com Mode Duration. */
#if (defined COMM_MIN_FULL_COM_MODE_DURATION)
#error COMM_MIN_FULL_COM_MODE_DURATION already defined
#endif
#define COMM_MIN_FULL_COM_MODE_DURATION(Channel)                   \
  COMM_INST_ACCESS(ComM_NetReqNoNmTimeoutMs,Channel)

/** \brief Startup mode for each channel. */
#if (defined COMM_CHANNELSTARTUPMODE)
#error COMM_CHANNELSTARTUPMODE already defined
#endif
#define COMM_CHANNELSTARTUPMODE(Channel)                   \
  COMM_INST_ACCESS(ComM_ChannelStartupMode,Channel)

/*--------------------------------------------------------------------------*/

/* Macros for the abstraction of the RTE callback functions.
 * The macros resolve to the required callback function names according to
 * the service API configuration (default, ASR40, ASR32)
 */

#if (defined COMM_EB_DEFAULT_RTE_NOTIFY)
#error COMM_EB_DEFAULT_RTE_NOTIFY already defined
#endif
#if ((COMM_INCLUDE_RTE == STD_ON) && \
    (COMM_DEFAULT_ASR_SERVICE_API != COMM_SERVICE_API_NONE))
/** \brief Signal the user the current communication mode via Rte
 *
 * The macro receives the user handle and gets the current communication mode
 * and propagates the arguments to the corresponding default RTE handle
 * function.
 *
 * If the default service API is set to NONE then the macro is defined empty.
 *
 * The return value of the RTE call is ignored on purpose because the ComM
 * does not have a strategy to handle failing SW-C calls.
 *
 * \param[in] user       the user to be notified as uint8 value
 */
#if (defined COMM_EB_DEFAULT_RTE_NOTIFY)
#error COMM_EB_DEFAULT_RTE_NOTIFY already defined
#endif
#define COMM_EB_DEFAULT_RTE_NOTIFY(user)      \
  do { \
    ComM_ASR40_ModeType CurComMMode; \
    if (E_OK == ComM_ASR40_GetCurrentComMode((user), &CurComMMode)) \
    { \
      ComM_RteNotify((user), CurComMMode); \
    } \
  } while (0)
#else
#define COMM_EB_DEFAULT_RTE_NOTIFY(user)
#endif

#if (defined COMM_EB_ASR40_RTE_NOTIFY)
#error COMM_EB_ASR40_RTE_NOTIFY already defined
#endif
#if ((COMM_INCLUDE_RTE == STD_ON) && \
     (COMM_ENABLE_ASR40_SERVICE_API == STD_ON))
/** \brief Signal the user the current communication mode via ASR40 Rte
 * callbacks
 *
 * The macro receives the user handle, gets the current communication mode and
 * propagates the arguments to the corresponding ASR40 RTE handle function.
 *
 * If the ASR40 service API is set to STD_OFF then the macro is defined empty.
 *
 * The return value of the RTE call is ignored on purpose because the ComM
 * does not have a strategy to handle failing SW-C calls.
 *
 * \param[in] user       the user to be notified as uint8 value
 */
#define COMM_EB_ASR40_RTE_NOTIFY(user)      \
  do { \
    ComM_ASR40_ModeType CurASR40ComMMode; \
    if (E_OK == ComM_ASR40_GetCurrentComMode((user), &CurASR40ComMMode)) \
    { \
      ComM_ASR40_RteNotify((user), (CurASR40ComMMode)); \
    } \
  } while (0)
#else
#define COMM_EB_ASR40_RTE_NOTIFY(user)
#endif

#if (defined COMM_EB_ASR32_RTE_NOTIFY)
#error COMM_EB_ASR32_RTE_NOTIFY already defined
#endif
#if ((COMM_INCLUDE_RTE == STD_ON) && \
     (COMM_ENABLE_ASR32_SERVICE_API == STD_ON))
/** \brief Signal the user the current communication mode via ASR32 Rte
 * callbacks
 *
 * The macro receives the user handle, gets the current communication mode and
 * propagates the arguments to the corresponding ASR32 RTE handle function.
 *
 * If the ASR32 service API is set to STD_OFF then the macro is defined empty.
 *
 * The return value of the RTE call is ignored on purpose because the ComM
 * does not have a strategy to handle failing SW-C calls.
 *
 * \param[in] user       the user to be notified as uint8 value
 */
#define COMM_EB_ASR32_RTE_NOTIFY(user)      \
  do { \
    ComM_ASR32_ModeType CurASR32ComMMode; \
    if (E_OK == ComM_ASR32_GetCurrentComMode((user), &CurASR32ComMMode)) \
    { \
      ComM_ASR32_RteNotify((user), (CurASR32ComMMode)); \
    } \
  } while (0)
#else
#define COMM_EB_ASR32_RTE_NOTIFY(user)
#endif

#if (defined COMM_EB_RTE_NOTIFY)
#error COMM_EB_RTE_NOTIFY already defined
#endif
#if (COMM_INCLUDE_RTE == STD_ON)
/** \brief Signal the user the current communication mode via ASR32 Rte
 * callbacks
 *
 * The macro receives the user handle and propagates the argument to the
 * corresponding sub-macros for the specific RTE handle functions.
 *
 * If the RTE is set to STD_OFF then the macro is defined empty.
 *
 * \param[in] user       the user to be notified as uint8 value
 */
#define COMM_EB_RTE_NOTIFY(user)      \
  do { \
      COMM_EB_ASR32_RTE_NOTIFY((user));\
      COMM_EB_ASR40_RTE_NOTIFY((user));\
      COMM_EB_DEFAULT_RTE_NOTIFY((user));\
  } while (0)
#else
#define COMM_EB_RTE_NOTIFY(user, curcommod)
#endif

/*--------------------------------------------------------------------------*/

/*==================[type definitions]======================================*/

/** \brief Function pointer type for the bus state manager functions to
 ** request a new communication mode. */
typedef P2FUNC(Std_ReturnType, COMM_APPL_CODE, ComM_BusSMRequestComModeType)(
  NetworkHandleType Channel,
  uint8             ComMode);

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

#define COMM_START_SEC_CODE
#include <MemMap.h>
/** \brief Notify Mode Transition of ComM channels to RTE ,DCM and BSWM.
 **
 ** This function notifies the mode change of all ComM channels to RTE(if RTE
 ** enabled) , DCM and BSWM.
 **
 ** \param[in] Channel Network channel on which the mode transition
 **                    has occurred.
 ** \param[in] ComMode Maximum allowed communication mode. */
STATIC FUNC(void, COMM_CODE) ComM_Notify(
  uint8               Channel,
  const ComM_ModeType ComMMode);

#if (COMM_INCLUDE_RTE == STD_ON)
/** \brief Notify Mode Transition of ComM channels to RTE
 **
 ** This function notifies the mode change of all ComM channels to RTE(if RTE
 ** enabled)
 **
 ** \param[in] Channel Channel Network channel on which the mode transition
 **                    has occurred.
 */
/* Deviation MISRAC2012-1 */
STATIC FUNC(void, COMM_CODE) ComM_SwitchCurrentRteMode(COMM_PDL_SF(const uint8 Channel));
#endif /* #if (COMM_INCLUDE_RTE == STD_ON) */

#if ((COMM_MODE_LIMITATION_ENABLED == STD_ON) && (COMM_NUM_USERS > 0))
 /** \brief Clears all ComM requests
 **
 ** This function clears all ComM user requests and set the state to No
 ** ComMode.
 **
 ** \param[in] instIdx index of state machine instance. */
/* Deviation MISRAC2012-1 */
STATIC FUNC(void, COMM_CODE) 
  ComM_ClearUserRequest(COMM_PDL_SF(const uint8 instIdx));
#endif

/** \brief Evaluate if the channel can be requested.
 **
 ** This function checks if the channel is requested by the Dcm or by a user and mode limitation is
 ** not active.
 **
 ** \param[in] Channel Network channel which shall be requested.
 */
/* Deviation MISRAC2012-1 */
STATIC FUNC(boolean, COMM_CODE) ComM_IsFullComAllowed(
  COMM_PDL_SF(const uint8 Channel));

/** \brief Evaluate if the channel is requested.
 **
 ** This function checks if the channel is requested by the Dcm or any user.
 **
 ** \param[in] Channel Network channel on which the mode transition shall occur.
 */
/* Deviation MISRAC2012-1 */
STATIC FUNC(boolean, COMM_CODE) ComM_IsFullComRequested(
  COMM_PDL_SF(const uint8 Channel));

/** \brief Evaluate if the channel is allowed to wake up from 'No Communication'.
 **
 ** This function checks if the channel is requested by the Dcm or by any user and no
 ** mode inhibition is active.
 **
 ** \param[in] Channel Network channel which shall be requested.
 */
/* Deviation MISRAC2012-1 */
STATIC FUNC(boolean, COMM_CODE) ComM_IsWakeupAllowed(
  COMM_PDL_SF(const uint8 Channel));

#define COMM_STOP_SEC_CODE
#include <MemMap.h>

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

#define COMM_START_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/** \brief Stores function pointer for bus specific state managers **/
STATIC CONST(ComM_BusSMRequestComModeType, COMM_CONST)
  ComM_BusSMRequestComModeFpList[5] =
{
#if (COMM_CANSM_ACCESS_NEEDED == STD_ON)
  &CanSM_RequestComMode,         /* COMM_BUS_TYPE_CAN = 0 */
#else
  NULL_PTR,                /* never accessed if no CAN channel is available */
#endif
#if (COMM_ETHSM_ACCESS_NEEDED == STD_ON)
  &EthSM_RequestComMode,         /* COMM_BUS_TYPE_ETH = 1 */
#else
  NULL_PTR,                /* never accessed if no ETH channel is available */
#endif
#if (COMM_FRSM_ACCESS_NEEDED == STD_ON)
  &FrSM_RequestComMode,          /* COMM_BUS_TYPE_FR = 2 */
#else
  NULL_PTR,                 /* never accessed if no FR channel is available */
#endif
  NULL_PTR,                 /* COMM_BUS_TYPE_INTERNAL = 3 */
#if (COMM_LINSM_ACCESS_NEEDED == STD_ON)
  &LinSM_RequestComMode         /* COMM_BUS_TYPE_LIN = 4 */
#else
  NULL_PTR                /* never accessed if no LIN channel is available */
#endif
};

#define COMM_STOP_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

#define COMM_START_SEC_VAR_NO_INIT_16
#include <MemMap.h>

/** \brief Time counter value for checking the timeouts of different states */
/* Deviation MISRAC2012-5 */
STATIC VAR(uint16, COMM_VAR) ComM_Timer[COMM_NUM_CHANNELS];

#define COMM_STOP_SEC_VAR_NO_INIT_16
#include <MemMap.h>

#define COMM_START_SEC_VAR_NO_INIT_8
#include <MemMap.h>

/** \brief Event to be sent on timeout */
/* Deviation MISRAC2012-5 */
STATIC VAR(ComM_HsmEventType, COMM_VAR) ComM_TimeoutEvent[COMM_NUM_CHANNELS];

/** \brief Return Value of last Nm request for each channel. */
STATIC VAR(Std_ReturnType, COMM_VAR) ComM_ChannelStartupMode[COMM_NUM_CHANNELS];


#define COMM_STOP_SEC_VAR_NO_INIT_8
#include <MemMap.h>


/*==================[external function definitions]=========================*/

#define COMM_START_SEC_CODE
#include <MemMap.h>

/* ************************ state functions ******************************* */

/* ************************************************************************
 * State: TOP
 * Parent state: none
 * Init substate: NO_COMMUNICATION
 * Transitions originating from this state:
 * 1) BUSSM_MODE_IND[]/ComM_Notify(ComM_ChannelMode); ComM_ClearUserRequest();
 */

/* Deviation MISRAC2012-1 */
FUNC(void, COMM_CODE) ComM_HsmComMSfTOPDo(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* do action 'ComM_SwitchCurrentRteMode();' */
#if (COMM_INCLUDE_RTE == STD_OFF)
  COMM_PARAM_UNUSED(instIdx);
#else
  ComM_SwitchCurrentRteMode(COMM_PL_SF(instIdx));
#endif
}
/* Deviation MISRAC2012-1 */
FUNC(void, COMM_CODE) ComM_HsmComMSfTOPAction1(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* action 'ComM_Notify(ComM_ChannelMode); ComM_ClearUserRequest();'
   * for BUSSM_MODE_IND[]/...
   * internal transition */
  /* !LINKSTO ComM.EB.Dsn.Algorithm.ModePropagation,1 */
  ComM_Notify(instIdx, COMM_CHANNELMODE(instIdx));
#if ((COMM_MODE_LIMITATION_ENABLED == STD_ON) && (COMM_NUM_USERS > 0))
  ComM_ClearUserRequest(COMM_PL_SF(instIdx));
#endif
}

/* ************************************************************************
 * State: FULL_COMMUNICATION
 * Parent state: TOP
 * Init substate: FULL_COM_NETWORK_REQUESTED
 * Transitions originating from this state:
 * 1) FULL_COMMUNICATION -> NO_COMMUNICATION: NM_MODE_SWITCHED[(ComM_NmGetMode() == NM_MODE_BUS_SLEEP)]/
 */

/* Deviation MISRAC2012-1 */
FUNC(void, COMM_CODE) ComM_HsmComMSfFULL_COMMUNICATIONEntry(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* entry action 'if (COMM_BUS_TYPE_INTERNAL== ComMBusType) ComM_Notify(COMM_FULL_COMMUNICATION);if (COMM_BUS_TYPE_INTERNAL!= ComMBusType) ComM_BusSmRequestComMode(COMM_FULL_COMMUNICATION);' */
#if (COMM_BUSTYPE_INTERNAL_NEEDED == STD_ON)
#if ((COMM_BUSTYPE_OF_CHANNEL_DYNAMIC == STD_ON) && (COMM_BUSTYPE_INTERNAL_NEEDED == STD_ON))
  if (COMM_BUS_TYPE_INTERNAL == COMM_BUSTYPE_OF_CHANNEL(instIdx))
#endif
  {
    ComM_Notify(instIdx, COMM_FULL_COMMUNICATION);
#if (COMM_MODE_LIMITATION_ENABLED == STD_ON)
    COMM_CHANNELMODE_PREVIOUS(instIdx) = COMM_FULL_COMMUNICATION;
#endif
  }
#endif

  if (COMM_BUS_TYPE_INTERNAL != COMM_BUSTYPE_OF_CHANNEL(instIdx))
  {
    COMM_BUSSM_REQUEST_COM_MODE(instIdx, COMM_FULL_COMMUNICATION);
  }
}
/* Deviation MISRAC2012-1, MISRAC2012-2 */
FUNC(boolean, COMM_CODE) ComM_HsmComMSfFULL_COMMUNICATIONGuard1(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* guard condition '(ComM_NmGetMode() == NM_MODE_BUS_SLEEP)'
   * for NM_MODE_SWITCHED[...]/
   * external transition to state NO_COMMUNICATION */

  boolean ret = FALSE;
#if (COMM_NM_ACCESS_NEEDED == STD_OFF)
#endif
#if (COMM_NM_ACCESS_NEEDED == STD_ON)
  Nm_StateType nmState;
  Nm_ModeType  nmMode;
  /* return value can be ignored, as the only reasons for E_NOT_OK are
   * - wrong network handles (development error, would have occurred already before)
   * - Nm is not yet initialized, but as this function is only called,
   *   when Nm has called a network indicated before, Nm must be initialized.
   */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.NM_MODE_SWITCHED_FULL_COMMUNICATION,1 */
  (void) Nm_GetState(COMM_NM_CHANNEL_OF_CHANNEL(instIdx), &nmState, &nmMode);
  ret = ((NM_MODE_BUS_SLEEP == nmMode) ? TRUE : FALSE);
#endif
  COMM_PARAM_UNUSED(instIdx);
  return ret;
}

/* ************************************************************************
 * State: FULL_COM_NETWORK_REQUESTED
 * Parent state: FULL_COMMUNICATION
 * Init substate: FULL_COM_NETWORK_REQUESTED_ENTRY
 * Transitions originating from this state:
 * 1) PNC_NM_REQUEST[]/Nm_NetworkRequest();
 * 2) FULL_COM_NETWORK_REQUESTED -> FULL_COM_READY_SLEEP: LIMIT_TO_NO_COM[!ComM_IsFullComAllowed()]/
 * 3) FULL_COM_NETWORK_REQUESTED -> SILENT_COMMUNICATION: NM_MODE_SWITCHED[(ComMNmVariant == PASSIVE) && (ComM_NmGetMode() == NM_MODE_PREPARE_BUS_SLEEP)]/
 */

/* Deviation MISRAC2012-1 */
FUNC(void, COMM_CODE) ComM_HsmComMSfFULL_COM_NETWORK_REQUESTEDEntry(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* entry action 'ComM_ChanState = COMM_FULL_COM_NETWORK_REQUESTED;if ((ComM_IsFullComRequested == FALSE) && (ComMNmVariant == FULL|PASSIVE)) Nm_PassiveStartup(); if ((ComM_IsFullComRequested == TRUE) && (ComMNmVariant == FULL)) Nm_NetworkRequest();' */
  COMM_CHANNELSTATE(instIdx) = COMM_FULL_COM_NETWORK_REQUESTED;
  /* if NmVariant is FULL, request the network */
#if ((COMM_NM_VARIANT_FULL_NEEDED == STD_ON) || (COMM_NM_VARIANT_PASSIVE_NEEDED == STD_ON))
#if (COMM_NM_VARIANT_OF_CHANNEL_DYNAMIC == STD_ON)
  if ((ComM_IsFullComRequested(COMM_PL_SF(instIdx)) == FALSE) &&
      ((COMM_NM_FULL_VARIANT    == COMM_NM_VARIANT_OF_CHANNEL(instIdx)) ||
       (COMM_NM_PASSIVE_VARIANT == COMM_NM_VARIANT_OF_CHANNEL(instIdx))
      )
     )
#else
  if (ComM_IsFullComRequested(COMM_PL_SF(instIdx)) == FALSE)
#endif
  {
    COMM_NM_PASSIVESTARTUP(instIdx);
  }
#endif

#if (COMM_NM_VARIANT_FULL_NEEDED == STD_ON)
#if (COMM_NM_VARIANT_FULL_ONLY == STD_OFF)
  /* !LINKSTO ComM667,1 */
  if ((ComM_IsFullComRequested(COMM_PL_SF(instIdx)) == TRUE) &&
      (COMM_NM_FULL_VARIANT    == COMM_NM_VARIANT_OF_CHANNEL(instIdx)))
#else
  if (ComM_IsFullComRequested(COMM_PL_SF(instIdx)) == TRUE)
#endif
  {
    COMM_NM_NETWORKREQUEST(instIdx);
  }
#endif
}
/* Deviation MISRAC2012-1, MISRAC2012-2 */
FUNC(void, COMM_CODE) ComM_HsmComMSfFULL_COM_NETWORK_REQUESTEDAction1(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* action 'Nm_NetworkRequest();'
   * for PNC_NM_REQUEST[]/...
   * internal transition */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.FULL_COM_NETWORK_REQUESTED_NmVariantFULL,1 */
  COMM_PARAM_UNUSED(instIdx);
#if (COMM_NM_VARIANT_FULL_NEEDED == STD_ON)

  /* if NmVariant is FULL, request the network */

  /* No need to check, if the NmVariant of the current channel is FULL ,
   * because the event PNC_NM_REQUEST is only emitted for channels of NmVariant FULL.
   * This is ensured by a check in the ComM.xdm and the PNC state machine.
   */
  COMM_NM_NETWORKREQUEST(instIdx);

#endif
}
/* Deviation MISRAC2012-1, MISRAC2012-2 */
FUNC(boolean, COMM_CODE) ComM_HsmComMSfFULL_COM_NETWORK_REQUESTEDGuard2(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* guard condition '!ComM_IsFullComAllowed()'
   * for LIMIT_TO_NO_COM[...]/
   * external transition to state FULL_COM_READY_SLEEP */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.LIMIT_TO_NO_COM_FULL_COM_NETWORK_REQUESTED_0,1 */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.LIMIT_TO_NO_COM_FULL_COM_NETWORK_REQUESTED_1,1 */
  boolean ret = FALSE;
  ret = (FALSE == ComM_IsFullComAllowed(COMM_PL_SF(instIdx))) ? TRUE : FALSE;
  return ret;
}
/* Deviation MISRAC2012-1, MISRAC2012-2 */
FUNC(boolean, COMM_CODE) ComM_HsmComMSfFULL_COM_NETWORK_REQUESTEDGuard3(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* guard condition '(ComMNmVariant == PASSIVE) && (ComM_NmGetMode() == NM_MODE_PREPARE_BUS_SLEEP)'
   * for NM_MODE_SWITCHED[...]/
   * external transition to state SILENT_COMMUNICATION */
  boolean ret = FALSE;
#if (COMM_NM_ACCESS_NEEDED == STD_ON)
  Nm_StateType nmState;
  Nm_ModeType  nmMode;
  /* return value can be ignored, as the only reasons for E_NOT_OK are
   * - wrong network handles (development error, would have occurred already before)
   * - Nm is not yet initialized, but as this function is only called,
   *   when Nm has called a network indicated before, Nm must be initialized.
   */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.NM_MODE_SWITCHED_FULL_COM_NETWORK_REQUESTED,1 */
  (void) Nm_GetState(COMM_NM_CHANNEL_OF_CHANNEL(instIdx), &nmState, &nmMode);
  ret = ((NM_MODE_PREPARE_BUS_SLEEP == nmMode) ? TRUE : FALSE);
#endif
  COMM_PARAM_UNUSED(instIdx);
  return ret;
}

/* ************************************************************************
 * State: FULL_COM_NETWORK_REQUESTED_ENTRY
 * Parent state: FULL_COM_NETWORK_REQUESTED
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) FULL_COM_NETWORK_REQUESTED_ENTRY -> FULL_COM_NETWORK_REQUESTED_PENDING: REQ_STATUS_CHANGED[ComM_IsFullComRequested()]/
 * 2) FULL_COM_NETWORK_REQUESTED_ENTRY -> FULL_COM_READY_SLEEP: REQ_STATUS_CHANGED[(FULL|PASSIVE == ComMNmVariant) && (!ComM_IsFullComRequested())]/
 * 3) FULL_COM_NETWORK_REQUESTED_ENTRY -> FULL_COM_NETWORK_REQUESTED_PENDING: TIMEOUT[ComM_IsFullComRequested()]/
 * 4) FULL_COM_NETWORK_REQUESTED_ENTRY -> FULL_COM_READY_SLEEP: TIMEOUT[!ComM_IsFullComRequested()]/
 */

/* Deviation MISRAC2012-1, MISRAC2012-2 */
FUNC(void, COMM_CODE) ComM_HsmComMSfFULL_COM_NETWORK_REQUESTED_ENTRYEntry(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* entry action 'if(ComMNmVariant== LIGHT|NONE) ComM_StartTimer(ComMTMinFullComModeDuration);if(ComMNmVariant == FULL|PASSIVE) emit REQ_STATUS_CHANGED' */
#if ((COMM_NM_VARIANT_LIGHT_NEEDED == STD_ON) || (COMM_NM_VARIANT_NONE_NEEDED == STD_ON))
#if (COMM_NM_VARIANT_LIGHT_NONE_ONLY == STD_OFF)
  if ((COMM_NM_VARIANT_OF_CHANNEL(instIdx) == COMM_NM_LIGHT_VARIANT) ||
      (COMM_NM_VARIANT_OF_CHANNEL(instIdx) == COMM_NM_NONE_VARIANT)
     )
#endif
  {
    /* !LINKSTO ComM.EB.Dsn.StateDynamics.ComMTMinFullComModeDuration_TIMEOUT,1 */
    ComM_StartTimer(instIdx, COMM_HSM_COMM_EV_TIMEOUT, COMM_MIN_FULL_COM_MODE_DURATION(instIdx));
  }
#endif

#if ((COMM_NM_VARIANT_FULL_NEEDED == STD_ON) || (COMM_NM_VARIANT_PASSIVE_NEEDED == STD_ON))
#if (COMM_NM_VARIANT_OF_CHANNEL_DYNAMIC == STD_ON)
  if ((COMM_NM_VARIANT_OF_CHANNEL(instIdx) == COMM_NM_FULL_VARIANT) ||
      (COMM_NM_VARIANT_OF_CHANNEL(instIdx) == COMM_NM_PASSIVE_VARIANT)
     )
#endif
  {
    /* !LINKSTO ComM.EB.Dsn.StateDynamics.FULL_COM_NETWORK_REQUESTED_ENTRY_REQ_STATUS_CHANGED,1 */
    (void) COMM_HSMEMITINST(&ComM_HsmScComM, instIdx, COMM_HSM_COMM_EV_REQ_STATUS_CHANGED);
  }
#endif
}
/* Deviation MISRAC2012-1, MISRAC2012-2 */
FUNC(void, COMM_CODE) ComM_HsmComMSfFULL_COM_NETWORK_REQUESTED_ENTRYExit(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* exit action 'if(ComMNmVariant== LIGHT|NONE) ComM_StopTimer();' */
#if ((COMM_NM_VARIANT_LIGHT_NEEDED == STD_OFF) && (COMM_NM_VARIANT_NONE_NEEDED == STD_OFF))
  COMM_PARAM_UNUSED(instIdx);
#else
#if (COMM_NM_VARIANT_LIGHT_NONE_ONLY == STD_OFF)
  if ((COMM_NM_VARIANT_OF_CHANNEL(instIdx) == COMM_NM_LIGHT_VARIANT) ||
      (COMM_NM_VARIANT_OF_CHANNEL(instIdx) == COMM_NM_NONE_VARIANT)
     )
#endif
  {
    ComM_StopTimer(instIdx);
  }
#endif
}
/* Deviation MISRAC2012-1, MISRAC2012-2 */
FUNC(boolean, COMM_CODE) ComM_HsmComMSfFULL_COM_NETWORK_REQUESTED_ENTRYGuard1(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* guard condition 'ComM_IsFullComRequested()'
   * for REQ_STATUS_CHANGED[...]/
   * external transition to state FULL_COM_NETWORK_REQUESTED_PENDING */
  /* !LINKSTO ComM.EB.ComM_FULL_COM_NETWORK_REQUESTED_Transition_0,1 */
  /* !LINKSTO ComM.EB.ComM_FULL_COM_NETWORK_REQUESTED_Transition_1,1 */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.REQ_STATUS_CHANGED_FULL_COMM_FULL_COM_NETWORK_REQUESTED_ENTRY_0,1 */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.REQ_STATUS_CHANGED_FULL_COMM_FULL_COM_NETWORK_REQUESTED_ENTRY_1,1 */
  boolean ret = FALSE;
  ret = (TRUE == ComM_IsFullComRequested(COMM_PL_SF(instIdx))) ? TRUE : FALSE;
  return ret;
}
/* Deviation MISRAC2012-1, MISRAC2012-2 */
FUNC(boolean, COMM_CODE) ComM_HsmComMSfFULL_COM_NETWORK_REQUESTED_ENTRYGuard2(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* guard condition '(FULL|PASSIVE == ComMNmVariant) && (!ComM_IsFullComRequested())'
   * for REQ_STATUS_CHANGED[...]/
   * external transition to state FULL_COM_READY_SLEEP */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.REQ_STATUS_CHANGED_NO_COMM_FULL_COM_NETWORK_REQUESTED_ENTRY_0,1 */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.REQ_STATUS_CHANGED_NO_COMM_FULL_COM_NETWORK_REQUESTED_ENTRY_1,1 */
  boolean ret = FALSE;
  COMM_PARAM_UNUSED(instIdx);
#if ((COMM_NM_VARIANT_FULL_NEEDED == STD_ON) || (COMM_NM_VARIANT_PASSIVE_NEEDED == STD_ON))
#if (COMM_NM_VARIANT_OF_CHANNEL_DYNAMIC == STD_ON)
  ret = ( (FALSE == ComM_IsFullComRequested(COMM_PL_SF(instIdx))              ) &&
          ((COMM_NM_FULL_VARIANT    == COMM_NM_VARIANT_OF_CHANNEL(instIdx)) ||
           (COMM_NM_PASSIVE_VARIANT == COMM_NM_VARIANT_OF_CHANNEL(instIdx))
          )
        ) ? TRUE : FALSE;
#else /* #if (COMM_NM_VARIANT_OF_CHANNEL_DYNAMIC == STD_ON) */
  ret = (FALSE == ComM_IsFullComRequested(COMM_PL_SF(instIdx))) ? TRUE : FALSE;
#endif /* #if (COMM_NM_VARIANT_OF_CHANNEL_DYNAMIC == STD_ON) */
#endif
/* #if ((COMM_NM_VARIANT_FULL_NEEDED == STD_ON) || (COMM_NM_VARIANT_PASSIVE_NEEDED == STD_ON)) */
  return ret;
}
/* Deviation MISRAC2012-1, MISRAC2012-2 */
FUNC(boolean, COMM_CODE) ComM_HsmComMSfFULL_COM_NETWORK_REQUESTED_ENTRYGuard3(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* guard condition 'ComM_IsFullComRequested()'
   * for TIMEOUT[...]/
   * external transition to state FULL_COM_NETWORK_REQUESTED_PENDING */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.TIMEOUT_USER_REQUEST_FULL_COM_NETWORK_REQUESTED_ENTRY_0,1 */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.TIMEOUT_USER_REQUEST_FULL_COM_NETWORK_REQUESTED_ENTRY_1,1 */
  boolean ret = FALSE;
  ret = (TRUE == ComM_IsFullComRequested(COMM_PL_SF(instIdx))) ? TRUE : FALSE;
  return ret;
}
/* Deviation MISRAC2012-1, MISRAC2012-2 */
FUNC(boolean, COMM_CODE) ComM_HsmComMSfFULL_COM_NETWORK_REQUESTED_ENTRYGuard4(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* guard condition '!ComM_IsFullComRequested()'
   * for TIMEOUT[...]/
   * external transition to state FULL_COM_READY_SLEEP */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.TIMEOUT_NO_USER_REQUEST_FULL_COM_NETWORK_REQUESTED_ENTRY_0,1 */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.TIMEOUT_NO_USER_REQUEST_FULL_COM_NETWORK_REQUESTED_ENTRY_1,1 */
  boolean ret = FALSE;
  ret = (FALSE == ComM_IsFullComRequested(COMM_PL_SF(instIdx))) ? TRUE : FALSE;
  return ret;
}

/* ************************************************************************
 * State: FULL_COM_NETWORK_REQUESTED_PENDING
 * Parent state: FULL_COM_NETWORK_REQUESTED
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) FULL_COM_NETWORK_REQUESTED_PENDING -> FULL_COM_READY_SLEEP: REQ_STATUS_CHANGED[!ComM_IsFullComRequested()]/
 */

/* Deviation MISRAC2012-1, MISRAC2012-2 */
FUNC(boolean, COMM_CODE) ComM_HsmComMSfFULL_COM_NETWORK_REQUESTED_PENDINGGuard1(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* guard condition '!ComM_IsFullComRequested()'
   * for REQ_STATUS_CHANGED[...]/
   * external transition to state FULL_COM_READY_SLEEP */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.REQ_STATUS_CHANGED_USER_FULL_COM_NETWORK_REQUESTED_PENDING_0,1 */
  boolean ret = FALSE;
  ret = (FALSE == ComM_IsFullComRequested(COMM_PL_SF(instIdx))) ? TRUE : FALSE;
  return ret;
}

/* ************************************************************************
 * State: FULL_COM_READY_SLEEP
 * Parent state: FULL_COMMUNICATION
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) FULL_COM_READY_SLEEP -> SILENT_COMMUNICATION: NM_MODE_SWITCHED[(ComMNmVariant == FULL|PASSIVE) && (ComM_NmGetMode() == NM_MODE_PREPARE_BUS_SLEEP)]/
 * 2) FULL_COM_READY_SLEEP -> FULL_COM_NETWORK_REQUESTED: REQ_STATUS_CHANGED[ComM_IsFullComAllowed()]/
 * 3) FULL_COM_READY_SLEEP -> NO_COMMUNICATION: TIMEOUT[]/if(COMM_BUS_TYPE_INTERNAL== ComMBusType) {ComM_Notify(COMM_NO_COMMUNICATION); ComM_ClearUserRequest();}
 */

/* Deviation MISRAC2012-1 */
FUNC(void, COMM_CODE) ComM_HsmComMSfFULL_COM_READY_SLEEPEntry(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* entry action 'ComM_ChanState = COMM_FULL_COM_READY_SLEEP;if(ComMNmVariant == LIGHT) ComM_StartTimer(ComMNmLightTimeout);if(ComMNmVariant == FULL) Nm_NetworkRelease();if(NONE== ComMNmVariant) emit TIMEOUT' */
  COMM_CHANNELSTATE(instIdx) = COMM_FULL_COM_READY_SLEEP;
#if (COMM_NM_VARIANT_LIGHT_NEEDED == STD_ON)
#if (COMM_NM_VARIANT_OF_CHANNEL_DYNAMIC == STD_ON)
  if (COMM_NM_VARIANT_OF_CHANNEL(instIdx) == COMM_NM_LIGHT_VARIANT)
#endif
  {
    /* !LINKSTO ComM.EB.Dsn.StateDynamics.ComMNmLightTimeout_TIMEOUT,1 */
    ComM_StartTimer(instIdx, COMM_HSM_COMM_EV_TIMEOUT, COMM_READYSLEEPNONMTIMEOUTMS(instIdx));
  }
#endif
#if (COMM_NM_VARIANT_FULL_NEEDED == STD_ON)
#if (COMM_NM_VARIANT_FULL_ONLY == STD_OFF)
  if (COMM_NM_FULL_VARIANT == COMM_NM_VARIANT_OF_CHANNEL(instIdx))
#endif
  {
    COMM_NM_NETWORKRELEASE(instIdx);
  }
#endif
#if (COMM_NM_VARIANT_NONE_NEEDED == STD_ON)
#if (COMM_NM_VARIANT_OF_CHANNEL_DYNAMIC == STD_ON)
  if (COMM_NM_VARIANT_OF_CHANNEL(instIdx) == COMM_NM_NONE_VARIANT)
#endif
  {
    /* !LINKSTO ComM.EB.Dsn.StateDynamics.FULL_COM_READY_SLEEP_TIMEOUT,1 */
    (void)
      COMM_HSMEMITTOSELFINST(&ComM_HsmScComM, instIdx, COMM_HSM_COMM_EV_TIMEOUT);
  }
#endif
}
/* Deviation MISRAC2012-1, MISRAC2012-2 */
FUNC(void, COMM_CODE) ComM_HsmComMSfFULL_COM_READY_SLEEPExit(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* exit action 'if(ComMNmVariant == LIGHT) ComM_StopTimer();' */
#if ((COMM_NM_VARIANT_OF_CHANNEL_DYNAMIC == STD_OFF) || \
     (COMM_NM_VARIANT_LIGHT_NEEDED == STD_OFF))
  COMM_PARAM_UNUSED(instIdx);
#endif

#if (COMM_NM_VARIANT_LIGHT_NEEDED == STD_ON)
#if (COMM_NM_VARIANT_OF_CHANNEL_DYNAMIC == STD_ON)
  if (COMM_NM_VARIANT_OF_CHANNEL(instIdx) == COMM_NM_LIGHT_VARIANT)
#endif
  {
    ComM_StopTimer(instIdx);
  }
#endif
}
/* Deviation MISRAC2012-1, MISRAC2012-2 */
FUNC(boolean, COMM_CODE) ComM_HsmComMSfFULL_COM_READY_SLEEPGuard1(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* guard condition '(ComMNmVariant == FULL|PASSIVE) && (ComM_NmGetMode() == NM_MODE_PREPARE_BUS_SLEEP)'
   * for NM_MODE_SWITCHED[...]/
   * external transition to state SILENT_COMMUNICATION */
  boolean ret = FALSE;
#if (COMM_NM_ACCESS_NEEDED == STD_OFF)
#endif

#if (COMM_NM_ACCESS_NEEDED == STD_ON)
  Nm_StateType nmState;
  Nm_ModeType  nmMode;

  /* return value can be ignored, as the only reasons for E_NOT_OK are
   * - wrong network handles (development error, would have occurred already before)
   * - Nm is not yet initialized, but as this function is only called,
   *   when Nm has called a network indicated before, Nm must be initialized.
   */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.NM_MODE_SWITCHED_FULL_COM_READY_SLEEP,1 */
  (void) Nm_GetState(COMM_NM_CHANNEL_OF_CHANNEL(instIdx), &nmState, &nmMode);
#if (COMM_NM_VARIANT_OF_CHANNEL_DYNAMIC == STD_ON)
  ret = (((COMM_NM_VARIANT_OF_CHANNEL(instIdx) == COMM_NM_FULL_VARIANT) ||
          (COMM_NM_VARIANT_OF_CHANNEL(instIdx) == COMM_NM_PASSIVE_VARIANT)
         ) &&
         (NM_MODE_PREPARE_BUS_SLEEP == nmMode)
        ) ? TRUE : FALSE;
#else
  ret = (NM_MODE_PREPARE_BUS_SLEEP == nmMode) ? TRUE : FALSE;
#endif /* #if (COMM_NM_VARIANT_OF_CHANNEL_DYNAMIC == STD_ON) */
#endif /* #if (COMM_NM_ACCESS_NEEDED == STD_ON) */
  COMM_PARAM_UNUSED(instIdx);
  return ret;
}
/* Deviation MISRAC2012-1, MISRAC2012-2 */
FUNC(boolean, COMM_CODE) ComM_HsmComMSfFULL_COM_READY_SLEEPGuard2(
  COMM_PDL_SF(const uint8 instIdx))
{
  boolean ret= FALSE;
  /* guard condition 'ComM_IsFullComAllowed()'
   * for REQ_STATUS_CHANGED[...]/
   * external transition to state FULL_COM_NETWORK_REQUESTED */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.REQ_STATUS_CHANGED_FULL_COM_READY_SLEEP_0,1 */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.REQ_STATUS_CHANGED_FULL_COM_READY_SLEEP_1,1 */
  ret = (ComM_IsFullComAllowed(COMM_PL_SF(instIdx))) ? TRUE : FALSE;
  return ret;
}
/* Deviation MISRAC2012-1, MISRAC2012-2 */
FUNC(void, COMM_CODE) ComM_HsmComMSfFULL_COM_READY_SLEEPAction3(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* action 'if(COMM_BUS_TYPE_INTERNAL== ComMBusType) {ComM_Notify(COMM_NO_COMMUNICATION); ComM_ClearUserRequest();}'
   * for TIMEOUT[]/...
   * external transition to state NO_COMMUNICATION */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.TIMEOUT_FULL_COM_READY_SLEEP_1,1 */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.TIMEOUT_FULL_COM_READY_SLEEP_0,1 */
#if (COMM_BUSTYPE_INTERNAL_NEEDED == STD_OFF)
  COMM_PARAM_UNUSED(instIdx);
#else
#if (COMM_BUSTYPE_OF_CHANNEL_DYNAMIC == STD_ON)
  if (COMM_BUS_TYPE_INTERNAL == COMM_BUSTYPE_OF_CHANNEL(instIdx))
#endif /* #if (COMM_BUSTYPE_OF_CHANNEL_DYNAMIC == STD_ON) */
  {
    ComM_Notify(instIdx, COMM_NO_COMMUNICATION);
#if ((COMM_MODE_LIMITATION_ENABLED == STD_ON) && (COMM_NUM_USERS > 0))
    ComM_ClearUserRequest(COMM_PL_SF(instIdx));
#endif /* #if (COMM_MODE_LIMITATION_ENABLED == STD_ON) */
  }
#endif /* #if (COMM_BUSTYPE_INTERNAL_NEEDED == STD_ON) */
}

/* ************************************************************************
 * State: NO_COMMUNICATION
 * Parent state: TOP
 * Init substate: NO_COM_NO_PENDING_REQUEST
 * Transitions originating from this state:
 */

/* Deviation MISRAC2012-1 */
FUNC(void, COMM_CODE) ComM_HsmComMSfNO_COMMUNICATIONEntry(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* entry action 'if(ComMNmVariant==FULL) Nm_NetworkRelease();if (COMM_BUS_TYPE_INTERNAL!= ComMBusType) ComM_BusSmRequestComMode(COMM_NO_COMMUNICATION);' */
#if (COMM_NM_VARIANT_FULL_NEEDED == STD_ON)
#if (COMM_NM_VARIANT_FULL_ONLY == STD_OFF)
  if (COMM_NM_FULL_VARIANT == COMM_NM_VARIANT_OF_CHANNEL(instIdx))
#endif
  {
    COMM_NM_NETWORKRELEASE(instIdx);
  }
#endif

  if (COMM_BUS_TYPE_INTERNAL != COMM_BUSTYPE_OF_CHANNEL(instIdx))
  {
    COMM_BUSSM_REQUEST_COM_MODE(instIdx, COMM_NO_COMMUNICATION);
  }
}

/* ************************************************************************
 * State: NO_COM_NO_PENDING_REQUEST
 * Parent state: NO_COMMUNICATION
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) NO_COM_NO_PENDING_REQUEST -> NO_COM_REQUEST_PENDING: PASSIVE_WAKEUP_IND[]/
 * 2) NO_COM_NO_PENDING_REQUEST -> NO_COM_REQUEST_PENDING: REQ_STATUS_CHANGED[ComM_IsWakeupAllowed()]/ComM_ChannelStartupMode = COMM_ACTIVE_STARTUP;
 */

/* Deviation MISRAC2012-1 */
FUNC(void, COMM_CODE) ComM_HsmComMSfNO_COM_NO_PENDING_REQUESTEntry(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* entry action 'ComM_ComM_ChanState = COMM_NO_COM_NO_PENDING_REQUEST;ComM_ChannelStartupMode = COMM_PASSIVE_STARTUP;' */
  COMM_CHANNELSTATE(instIdx) = COMM_NO_COM_NO_PENDING_REQUEST;
  COMM_CHANNELSTARTUPMODE(instIdx) = COMM_PASSIVE_STARTUP;
}
/* Deviation MISRAC2012-1, MISRAC2012-2 */
FUNC(boolean, COMM_CODE) ComM_HsmComMSfNO_COM_NO_PENDING_REQUESTGuard2(
  COMM_PDL_SF(const uint8 instIdx))
{
  boolean ret = FALSE;
  /* guard condition 'ComM_IsWakeupAllowed()'
   * for REQ_STATUS_CHANGED[...]/ComM_ChannelStartupMode = COMM_ACTIVE_STARTUP;
   * external transition to state NO_COM_REQUEST_PENDING */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.REQ_STATUS_CHANGED_USER_NO_COM_NO_PENDING_REQUEST_0,1 */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.REQ_STATUS_CHANGED_DCM_NO_COM_NO_PENDING_REQUEST_1,1 */
  ret = (ComM_IsWakeupAllowed(COMM_PL_SF(instIdx))) ? TRUE : FALSE;
  return ret;
}
/* Deviation MISRAC2012-1, MISRAC2012-2 */
FUNC(void, COMM_CODE) ComM_HsmComMSfNO_COM_NO_PENDING_REQUESTAction2(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* action 'ComM_ChannelStartupMode = COMM_ACTIVE_STARTUP;'
   * for REQ_STATUS_CHANGED[ComM_IsWakeupAllowed()]/...
   * external transition to state NO_COM_REQUEST_PENDING */
  COMM_CHANNELSTARTUPMODE(instIdx) = COMM_ACTIVE_STARTUP;
}

/* ************************************************************************
 * State: NO_COM_REQUEST_PENDING
 * Parent state: NO_COMMUNICATION
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) NO_COM_REQUEST_PENDING -> FULL_COMMUNICATION: COMALLOWED_CHANGED[ComM_Communication_Allowed == TRUE]/
 * 2) NO_COM_REQUEST_PENDING -> NO_COM_REQUEST_PENDING: REQ_STATUS_CHANGED[ComM_IsWakeupAllowed()]/ComM_ChannelStartupMode = COMM_ACTIVE_STARTUP;
 * 3) NO_COM_REQUEST_PENDING -> NO_COM_NO_PENDING_REQUEST: REQ_STATUS_CHANGED[(!ComM_IsWakeupAllowed()) && (COMM_ACTIVE_STARTUP == ComM_ChannelStartupMode)]/
 */

/* Deviation MISRAC2012-1 */
FUNC(void, COMM_CODE) ComM_HsmComMSfNO_COM_REQUEST_PENDINGEntry(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* entry action 'ComM_ChanState = COMM_NO_COM_REQUEST_PENDING;emit COMALLOWED_CHANGED' */
  COMM_CHANNELSTATE(instIdx) = COMM_NO_COM_REQUEST_PENDING;
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.NO_COM_REQUEST_PENDING_COMALLOWED_CHANGED,1 */
  (void) COMM_HSMEMITTOSELFINST(&ComM_HsmScComM, instIdx, COMM_HSM_COMM_EV_COMALLOWED_CHANGED);
}
/* Deviation MISRAC2012-1, MISRAC2012-2 */
FUNC(boolean, COMM_CODE) ComM_HsmComMSfNO_COM_REQUEST_PENDINGGuard1(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* guard condition 'ComM_Communication_Allowed == TRUE'
   * for COMALLOWED_CHANGED[...]/
   * external transition to state FULL_COMMUNICATION */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.COMALLOWED_CHANGE_NO_COM_PENDING_REQUEST,1 */
  boolean ret= FALSE;
  ret = (ComM_BitArrayIsBitSet(ComM_Communication_Allowed, COMM_INST(instIdx))) ? TRUE : FALSE;
  return ret;
}
/* Deviation MISRAC2012-1, MISRAC2012-2 */
FUNC(boolean, COMM_CODE) ComM_HsmComMSfNO_COM_REQUEST_PENDINGGuard2(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* guard condition 'ComM_IsWakeupAllowed()'
   * for REQ_STATUS_CHANGED[...]/ComM_ChannelStartupMode = COMM_ACTIVE_STARTUP;
   * external transition to state NO_COM_REQUEST_PENDING */
  boolean ret = FALSE;
  ret = (TRUE == ComM_IsWakeupAllowed(COMM_PL_SF(instIdx)) ? TRUE : FALSE);
  return ret;
}
/* Deviation MISRAC2012-1, MISRAC2012-2 */
FUNC(void, COMM_CODE) ComM_HsmComMSfNO_COM_REQUEST_PENDINGAction2(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* action 'ComM_ChannelStartupMode = COMM_ACTIVE_STARTUP;'
   * for REQ_STATUS_CHANGED[ComM_IsWakeupAllowed()]/...
   * external transition to state NO_COM_REQUEST_PENDING */
   /* !LINKSTO ComM.EB.Dsn.StateDynamics.REQ_STATUS_CHANGED_USER_NO_COM_PENDING_REQUEST_2,1 */
   /* !LINKSTO ComM.EB.Dsn.StateDynamics.REQ_STATUS_CHANGED_DCM_NO_COM_PENDING_REQUEST_3,1 */
   /* !LINKSTO ComM.EB.ComM_NoComRequestPending_Re-entered_1,1 */
   /* !LINKSTO ComM.EB.ComM_NoComRequestPending_Re-entered_2,1 */
  COMM_CHANNELSTARTUPMODE(instIdx) = COMM_ACTIVE_STARTUP;
}
/* Deviation MISRAC2012-1, MISRAC2012-2 */
FUNC(boolean, COMM_CODE) ComM_HsmComMSfNO_COM_REQUEST_PENDINGGuard3(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* guard condition '(!ComM_IsWakeupAllowed()) && (COMM_ACTIVE_STARTUP == ComM_ChannelStartupMode)'
   * for REQ_STATUS_CHANGED[...]/
   * external transition to state NO_COM_NO_PENDING_REQUEST */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.REQ_STATUS_CHANGED_USER_NO_COM_PENDING_REQUEST_0,1 */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.REQ_STATUS_CHANGED_DCM_NO_COM_PENDING_REQUEST_1,1 */
  boolean ret = FALSE;
  ret = ((FALSE == ComM_IsWakeupAllowed(COMM_PL_SF(instIdx))     ) &&
         (COMM_ACTIVE_STARTUP == COMM_CHANNELSTARTUPMODE(instIdx))
        ) ? TRUE : FALSE;
  return ret;
}

/* ************************************************************************
 * State: SILENT_COMMUNICATION
 * Parent state: TOP
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) SILENT_COMMUNICATION -> FULL_COM_READY_SLEEP: NM_MODE_SWITCHED[ComM_NmGetMode() == NM_MODE_NETWORK]/
 * 2) SILENT_COMMUNICATION -> NO_COMMUNICATION: NM_MODE_SWITCHED[ComM_NmGetMode() == NM_MODE_BUS_SLEEP]/
 * 3) SILENT_COMMUNICATION -> FULL_COMMUNICATION: REQ_STATUS_CHANGED[ComM_IsWakeupAllowed()]/
 */

/* Deviation MISRAC2012-1 */
FUNC(void, COMM_CODE) ComM_HsmComMSfSILENT_COMMUNICATIONEntry(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* entry action 'ComM_ChanState = COMM_SILENT_COM;ComM_BusSmRequestComMode(COMM_SILENT_COMMUNICATION);' */
  COMM_CHANNELSTATE(instIdx) = COMM_SILENT_COM;
  
  /* Here no need to check if ComMBusType is COMM_BUS_TYPE_INTERNAL since 
   * only a channel with ComMNmVariant atribute FULL or PASSIVE
   * can indicate Silent Communication.
   * A channel with ComMBusType set to COMM_BUS_TYPE_INTERNAL
   * can only have atribute ComMNmVariant set as NONE.
   */
  COMM_BUSSM_REQUEST_COM_MODE(instIdx, COMM_SILENT_COMMUNICATION);
}
/* Deviation MISRAC2012-1, MISRAC2012-2 */
FUNC(boolean, COMM_CODE) ComM_HsmComMSfSILENT_COMMUNICATIONGuard1(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* guard condition 'ComM_NmGetMode() == NM_MODE_NETWORK'
   * for NM_MODE_SWITCHED[...]/
   * external transition to state FULL_COM_READY_SLEEP */

  boolean      ret = FALSE;
#if (COMM_NM_ACCESS_NEEDED == STD_ON)
  Nm_ModeType  nmMode;
  Nm_StateType nmState;
  /* return value can be ignored, as the only reasons for E_NOT_OK are
   * - wrong network handles (development error, would have occurred already before)
   * - Nm is not yet initialized, but as this function is only called,
   *   when Nm has called a network indicated before, Nm must be initialized.
   */
   /* !LINKSTO ComM.EB.Dsn.StateDynamics.NM_MODE_SWITCHED_SILENT_COMMUNICATION_0,1 */
   (void) Nm_GetState(COMM_NM_CHANNEL_OF_CHANNEL(instIdx), &nmState, &nmMode);
  ret = (NM_MODE_NETWORK == nmMode) ? TRUE : FALSE;
#endif
  COMM_PARAM_UNUSED(instIdx);
  return ret;
}
/* Deviation MISRAC2012-1, MISRAC2012-2 */
FUNC(boolean, COMM_CODE) ComM_HsmComMSfSILENT_COMMUNICATIONGuard2(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* guard condition 'ComM_NmGetMode() == NM_MODE_BUS_SLEEP'
   * for NM_MODE_SWITCHED[...]/
   * external transition to state NO_COMMUNICATION */
  boolean      ret = FALSE;

#if (COMM_NM_ACCESS_NEEDED == STD_ON)
  Nm_ModeType  nmMode;
  Nm_StateType nmState;
  /* return value can be ignored, as the only reasons for E_NOT_OK are
   * - wrong network handles (development error, would have occurred already before)
   * - Nm is not yet initialized, but as this function is only called,
   *   when Nm has called a network indicated before, Nm must be initialized.
   */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.NM_MODE_SWITCHED_SILENT_COMMUNICATION_1,1 */
  (void) Nm_GetState(COMM_NM_CHANNEL_OF_CHANNEL(instIdx), &nmState, &nmMode);
  ret = (NM_MODE_BUS_SLEEP == nmMode) ? TRUE : FALSE;
#endif
  COMM_PARAM_UNUSED(instIdx);
  return ret;
}
/* Deviation MISRAC2012-1, MISRAC2012-2 */
FUNC(boolean, COMM_CODE) ComM_HsmComMSfSILENT_COMMUNICATIONGuard3(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* guard condition 'ComM_IsWakeupAllowed()'
   * for REQ_STATUS_CHANGED[...]/
   * external transition to state FULL_COMMUNICATION */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.REQ_STATUS_CHANGED_SILENT_COMMUNICATION_0,1 */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.REQ_STATUS_CHANGED_SILENT_COMMUNICATION_1,1 */
  boolean ret = FALSE;
  ret = (ComM_IsWakeupAllowed(COMM_PL_SF(instIdx))) ? TRUE : FALSE;
  return ret;
}
/*------------------[Timer function]----------------------------------------*/

FUNC(void, COMM_CODE) ComM_ProcessTimers(
  const uint8 Channel)
{
#if (COMM_HSM_INST_MULTI_ENABLED == STD_OFF)
  TS_PARAM_UNUSED(Channel);
#endif

  if (COMM_TIMER(Channel) > 0U)
  {
    --COMM_TIMER(Channel);
    if (COMM_TIMER(Channel) == 0U)
    {
      /* timeout events are generated outside of transitions, therefore do not
       * use the EMITTOSELF function */
      /* !LINKSTO ComM.EB.Dsn.StateDynamics.ComMTMinFullComModeDuration_TIMEOUT,1 */
      /* !LINKSTO ComM.EB.Dsn.StateDynamics.ComMNmLightTimeout_TIMEOUT,1 */
      (void)COMM_HSMEMITINST(
        &ComM_HsmScComM, Channel, COMM_TIMEOUT_EVENT(Channel));
    }
  }
}

/*==================[internal function definitions]=========================*/

/*------------------[ComM_Notify]--------------------------------------------*/

STATIC FUNC(void, COMM_CODE) ComM_Notify(
  uint8               Channel,
  const ComM_ModeType ComMMode)
{
#if (COMM_INCLUDE_RTE == STD_ON)
  uint8_least i;
#endif

  /* Set the current mode of the Channel */

#if (COMM_BUSTYPE_INTERNAL_NEEDED == STD_ON)
  COMM_CHANNELMODE(Channel) = ComMMode;
#endif


#if (COMM_INCLUDE_RTE == STD_ON)
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.TOPNotifyTransition_1,1 */
  for (i = 0U; i < COMM_NUM_USERS_OF_CHANNEL(COMM_INST(Channel)); i++)
  {
    const uint8 User = COMM_USERSOFCHANNEL(Channel,i);
    ComM_RteNotificationSuccessful[User] = FALSE;
  }
  ComM_SwitchCurrentRteMode(COMM_PL_SF(Channel));
#endif

  /* Report communication mode of ComM to BswM */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.TOPNotifyTransition_0,1 */
  BswM_ComM_CurrentMode(COMM_INST(Channel), ComMMode);

  /* Report communication mode of ComM to DCM */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.TOPNotifyTransition_2,1 */
#if (COMM_DCM_ENABLED == STD_ON)
  if (COMM_FULL_COMMUNICATION == COMM_CHANNELMODE(Channel))
  {
    Dcm_ComM_FullComModeEntered(COMM_INST(Channel));
  }
  else if (COMM_SILENT_COMMUNICATION == COMM_CHANNELMODE(Channel))
  {
    Dcm_ComM_SilentComModeEntered(COMM_INST(Channel));
  }
  else
  {
    Dcm_ComM_NoComModeEntered(COMM_INST(Channel));
  }
#endif
}

#if (COMM_INCLUDE_RTE == STD_ON)
/*------------------[ComM_SwitchCurrentRteMode]--------------------------------------------*/
/* Deviation MISRAC2012-1 */
STATIC FUNC(void, COMM_CODE) ComM_SwitchCurrentRteMode(COMM_PDL_SF(const uint8 Channel))
{
  uint8_least i;
  /* For all users of the channel */
  for (i = 0U; i < COMM_NUM_USERS_OF_CHANNEL(COMM_INST(Channel)); i++)
  {
    const uint8 User = COMM_USERSOFCHANNEL(Channel,i);
    if (FALSE == ComM_RteNotificationSuccessful[User])
    {
     /* Report the mode to RTE, if the current mode was not yet reported to
      * the Rte for this user */
      COMM_EB_RTE_NOTIFY(User);
    }
  }
}
#endif /* #if (COMM_INCLUDE_RTE == STD_ON) */

/*------------------[ComM_ClearUserRequest]----------------------------------*/

#if ((COMM_MODE_LIMITATION_ENABLED == STD_ON) && (COMM_NUM_USERS > 0))
/* Deviation MISRAC2012-1 */
STATIC FUNC(void, COMM_CODE) ComM_ClearUserRequest(COMM_PDL_SF(const uint8 instIdx))
{
  /* Get number of users of specific channel */
  const uint8 NumUser = COMM_NUM_USERS_OF_CHANNEL(COMM_INST(instIdx));
  uint8_least UserIdx;
  if ((TRUE                  == COMM_CHANNEL_NOCOM_INHIBITION_STATUS(instIdx)) &&
      (COMM_NO_COMMUNICATION == COMM_CHANNELMODE(instIdx)                    ) &&
      (COMM_NO_COMMUNICATION != COMM_CHANNELMODE_PREVIOUS(instIdx)           ))
  {
    /* For all users of shared channel of ComM */
    for (UserIdx = 0U; UserIdx < NumUser; ++UserIdx)
    {
      /* Get specific users of shared channel */
      const uint8 User = COMM_USERSOFCHANNEL(instIdx,UserIdx);
      boolean AllInNoCom = TRUE;
      uint8_least ChannelPos;

      /* [ComM582]: Check if all the channels that belong to the user
       * have entered COMM_NO_COMMUNICATION mode.
       */
      for (ChannelPos = 0U; ChannelPos < COMM_NUM_CHANNELS_OF_USER(User); ++ChannelPos)
      {
        const uint8 Channel = COMM_CHANNEL_OF_USER(User,ChannelPos);

        /* Check current communication mode of the channel  */
        if (COMM_NO_COMMUNICATION < ComM_ChannelMode[Channel])
        {
          /* At least one channel has not yet reached COMM_NO_COMMUNICATION.
           * Reset the flag and leave the loop.
           */
          AllInNoCom = FALSE;
          break;
        }
      }

      /* Clear the user request if all the channels that belong to the user
       * have entered COMM_NO_COMMUNICATION mode
       */
      if (TRUE == AllInNoCom)
      {
#if (COMM_NUM_PNC > 0U)
        uint8_least PncPos;
#endif /* #if (COMM_NUM_PNC > 0U) */
        /* Call the SchM wrapper functions */
        ComM_Enter_SCHM_COMM_EXCLUSIVE_AREA_0();
        ComM_UserRequestedComMode[User] = COMM_NO_COMMUNICATION;
        ComM_Exit_SCHM_COMM_EXCLUSIVE_AREA_0();

#if (COMM_NUM_PNC > 0U)
        /* Clear also the requests on the PNCs
         * - otherwise, the user request is cleared, but the PNC still requests the concerned
         *   channels, when mode limitation is lifted. and the channel would wake up, although the
         *   original user request is cleared.
         */
        for (PncPos = 0U; PncPos < COMM_NUM_PNCS_OF_USER(User); PncPos++)
        {
           const uint8 Pnc = COMM_PNC_OF_USER(User,PncPos);
           /* !LINKSTO ComM.EB.Dsn.StateDynamics.ModeLimitation_NO_COM_REQ_BY_ALL_COMM_USER,1 */
           ComM_EvaluatePnc(Pnc, COMM_NO_COMMUNICATION);
        }
#endif /* #if (COMM_NUM_PNC > 0U) */
      }
    }
  }
  COMM_CHANNELMODE_PREVIOUS(instIdx) = COMM_CHANNELMODE(instIdx);
}
#endif

/*------------------[ComM_IsFullComAllowed]--------------------------*/

/* Deviation MISRAC2012-1 */
STATIC FUNC(boolean, COMM_CODE) ComM_IsFullComAllowed(
  COMM_PDL_SF(const uint8 Channel))
{
  boolean ret = FALSE;
  /* return TRUE if communication mode is requested and Limit to No Com is
   * disabled for the channel or active diagnostic request is active */

#if (COMM_DCM_ENABLED == STD_ON)
  ret = ( ( (COMM_REQUESTEDCOMMODE(Channel) == COMM_FULL_COMMUNICATION) &&
              /* Deviation MISRAC2012-4 */
             (COMM_CHANNEL_NOCOM_INHIBITION_STATUS(Channel) == FALSE)
           ) ||
            /* Deviation MISRAC2012-4 */
           (TRUE == ComM_BitArrayIsBitSet(ComM_DcmActiveStatus, COMM_INST(Channel)))
         ) ? TRUE : FALSE;
#else
  ret =  ( (COMM_REQUESTEDCOMMODE(Channel) == COMM_FULL_COMMUNICATION) &&
             /* Deviation MISRAC2012-4 */
            (COMM_CHANNEL_NOCOM_INHIBITION_STATUS(Channel) == FALSE)
          ) ? TRUE : FALSE;
#endif
  return ret;
}

/*------------------[ComM_IsFullComRequested]--------------------------*/

/* Deviation MISRAC2012-1 */
STATIC FUNC(boolean, COMM_CODE) ComM_IsFullComRequested(
  COMM_PDL_SF(const uint8 Channel))
{
  boolean ret = FALSE;
  /* return TRUE if communication mode is requested and Limit to No Com is
   * disabled for the channel or active diagnostic request is active */

#if (COMM_DCM_ENABLED == STD_ON)
  ret = ( (TRUE == ComM_BitArrayIsBitSet(ComM_DcmActiveStatus, COMM_INST(Channel))) ||
          (COMM_REQUESTEDCOMMODE(Channel) == COMM_FULL_COMMUNICATION)
         ) ? TRUE : FALSE;
#else
  ret =  (COMM_REQUESTEDCOMMODE(Channel) == COMM_FULL_COMMUNICATION ) ? TRUE : FALSE;
#endif
  return ret;
}

/*------------------[ComM_IsWakeupAllowed]------------------------*/

/* Deviation MISRAC2012-1 */
STATIC FUNC(boolean, COMM_CODE) ComM_IsWakeupAllowed(
  COMM_PDL_SF(const uint8 Channel))
{
  boolean ret = FALSE;
  /* return TRUE if communication mode is requested and Limit to No Com is
   * disabled and WakeUp Inhibition is disabled for the channel or active
   * diagnostic request is active */

#if (COMM_DCM_ENABLED == STD_ON)
  ret = ( ( (COMM_REQUESTEDCOMMODE(Channel) == COMM_FULL_COMMUNICATION) &&
                /* Deviation MISRAC2012-4 <+2> */
             ( (COMM_CHANNEL_NOCOM_INHIBITION_STATUS(Channel) == FALSE) &&
               (COMM_CHANNEL_WAKEUP_INHIBITION_STATUS(Channel) == FALSE)
             )
           ) ||
            /* Deviation MISRAC2012-4 */
           (TRUE == ComM_BitArrayIsBitSet(ComM_DcmActiveStatus, COMM_INST(Channel)))
         ) ? TRUE : FALSE;
#else
  ret =  ( (COMM_REQUESTEDCOMMODE(Channel) == COMM_FULL_COMMUNICATION) &&
               /* Deviation MISRAC2012-4 <+2> */
            ( (COMM_CHANNEL_NOCOM_INHIBITION_STATUS(Channel) == FALSE) &&
              (COMM_CHANNEL_WAKEUP_INHIBITION_STATUS(Channel) == FALSE)
            )
          ) ? TRUE : FALSE;
#endif
  return ret;
}

#define COMM_STOP_SEC_CODE
#include <MemMap.h>

/*==================[end of file]===========================================*/
