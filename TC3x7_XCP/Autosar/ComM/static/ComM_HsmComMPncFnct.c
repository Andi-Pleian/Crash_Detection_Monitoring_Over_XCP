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
 * ComMPnc.
 *
 * This file contains the implementation of the state functions.  It
 * is generated but must be edited to implement the real actions.  If the
 * state machine model is updated and the code generator regenerates the
 * files the user must manually merge the changes with any existing hand
 * written code.
 */

/* CHECK: RULE 301 OFF (this file is partly generated, some lines may be
 * longer then 100 characters) */

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
 */

/*==================[inclusions]============================================*/

#include <ComM_Trace.h>
#include <ComM_BSW.h>
#include <ComM_Int.h>
#include <ComM_BSW_Cfg.h>
#include <ComM.h>

#include <ComM_Hsm.h>  /* state machine driver interface */
#include <ComM_HsmComMPnc.h> /* public statechart model definitions */
#include <ComM_HsmComMPncInt.h> /* internal statechart model definitions */
#include <ComM_Cfg.h>
#include <BswM_ComM.h>
#if (COMM_PNC_SUPPORT == STD_ON)
/* !LINKSTO ComM506_Refine_Com,1 */
#include <Com.h>     /* Com API's */
#endif
#if (COMM_NUM_PNC > 0U)

/*==================[macros]================================================*/

/** \brief Instant access to Pnc Timer */
#if (defined COMM_PNC_TIMER)
#error COMM_PNC_TIMER already defined
#endif
#define COMM_PNC_TIMER(Pnc)                     \
  COMM_INST_ACCESS(ComM_PncTimer,Pnc)

#if (defined ComM_PncStartTimer)
#error ComM_PncStartTimer already defined
#endif
#if (COMM_T_PNC_PREPARE_SLEEP == 0U)
#define ComM_PncStartTimer(Pnc)       \
  (void) COMM_HSMEMITINST(&ComM_HsmScComMPnc, Pnc, COMM_HSM_COMMPNC_EV_PREPARE_SLEEP_TIMEOUT);
#else
#define ComM_PncStartTimer(Pnc)  \
  COMM_PNC_TIMER(Pnc) = COMM_T_PNC_PREPARE_SLEEP;
#endif

#if (defined ComM_PncStopTimer)
#error ComM_PncStopTimer already defined
#endif
#define ComM_PncStopTimer(Pnc)  \
  COMM_PNC_TIMER(Pnc) = 0U;

/** \brief User ID of a channel. */
#if (defined COMM_NUMCHANNELSOFPNC)
#error COMM_NUMCHANNELSOFPNC already defined
#endif
#define COMM_NUMCHANNELSOFPNC(pnc) (COMM_NUM_CHANNELS_OF_PNC(pnc))

#if (defined COMM_CHANNELSOFPNC)
#error COMM_CHANNELSOFPNC already defined
#endif
#define COMM_CHANNELSOFPNC(pnc,i) (COMM_CHANNEL_OF_PNC(pnc,i))

#if (defined COMM_PARAM_UNUSED)
#error COMM_PARAM_UNUSED already defined
#endif
#if (COMM_HSM_INST_MULTI_ENABLED == STD_ON)
#define COMM_PARAM_UNUSED(instIdx)      TS_PARAM_UNUSED(instIdx)
#else
#define COMM_PARAM_UNUSED(instIdx)      /* nothing */
#endif

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

#define COMM_START_SEC_CODE
#include <MemMap.h>

/** \brief Release/Request all channels of a PNC
 **
 ** This updates the mode requested by a PNC and emits the event RE_STATUS_CHANGED to its channels.
 **
 ** \param[in] Pnc index of PNC */
STATIC FUNC(void, COMM_CODE) ComM_PNC_RequestComMode(const uint8 pncIdx, ComM_ModeType Mode);

/** \brief Request Full com for all channels of a Pnc
 **
 ** This function requests Full communication for all channels of
 ** a Pnc.
 **
 ** \param[in] Pnc index of Pnc */
STATIC FUNC(void, COMM_CODE)
  ComM_NmNwReqAllChOfPnc (const uint8 pncIdx);

/** \brief Get Eira
 **
 ** This function returns the status of EIRA (when Set TRUE is returned)
 ** of a Pnc */
/* Deviation MISRAC2012-1 */
STATIC FUNC(uint8, COMM_CODE) ComM_PncGetEIRA(
                                COMM_PDL_SF(const uint8 instIdx));

#if(COMM_PNC_GW_ENABLED == STD_ON)
/** \brief Get Era
 **
 ** This function returns the status of ERA (when Set TRUE is returned)
 ** of a Pnc
 ** \param[in]  instIdx - instance index
 */
/* Deviation MISRAC2012-1 */
STATIC FUNC(uint8, COMM_CODE) ComM_PncGetERA(COMM_PDL_SF(const uint8 instIdx));
#endif

/** \brief Send the status of PNC(s) via Com signal(s)
 **
 ** A PNC may contain references to more than one TX EIRA Com Signal.
 ** Therefore, this function sends the updated EIRA to all Com Signals
 ** which are referenced by this PNC.
 **
 ** Some PNCs may not reference a TX EIRA Com signal.
 ** Therefore, this function also masks out the bits corresponding
 ** to PNCs which do not reference this Com signal before sending.
 **/
STATIC FUNC(void, COMM_CODE) ComM_PncSendSignal
(
  /* Deviation MISRAC2012-1 */
  COMM_PDL_SF(const uint8 instIdx)
);

#define COMM_STOP_SEC_CODE
#include <MemMap.h>
/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

#define COMM_START_SEC_VAR_NO_INIT_16
#include <MemMap.h>

/** \brief Time counter value for checking the Prepare Sleep
 ** timeout for different Pnc */
STATIC VAR(uint16, COMM_VAR) ComM_PncTimer[COMM_NUM_PNC];

#define COMM_STOP_SEC_VAR_NO_INIT_16
#include <MemMap.h>

/*==================[external function definitions]=========================*/

#define COMM_START_SEC_CODE
#include <MemMap.h>

/* ************************ state functions ******************************* */

/* ************************************************************************
 * State: PncTop
 * Parent state: none
 * Init substate: PncNoCom
 * Transitions originating from this state:
 */


/* ************************************************************************
 * State: PncFullCom
 * Parent state: PncTop
 * Init substate: PncPrepareSleep
 * Transitions originating from this state:
 */


/* ************************************************************************
 * State: PncPrepareSleep
 * Parent state: PncFullCom
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) PncPrepareSleep -> PncReadySleep: COMCBK[ComM_PncGetEIRA() == 1]/ComM_PncStopTimer(PNC);
 * 2) PncPrepareSleep -> PncRequested: FULL_COM_REQ_BY_COMM_USER[]/ComM_PncStopTimer(PNC);
 * 3) PncPrepareSleep -> PncNoComNotify: PREPARE_SLEEP_TIMEOUT[]/if(COMM_NO_INTERNAL_AND_EXTERNAL_REQUESTS) ComM_PNC_RequestComMode (PNC, COMM_NO_COMMUNICATION);
 */

/* Deviation MISRAC2012-1 */
FUNC(void, COMM_CODE) ComM_HsmComMPncSfPncPrepareSleepEntry(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* entry action 'BswM_ComM_CurrentPNCMode(PNC_ID, PNC_PREPARE_SLEEP);ComM_PncStartTimer(PNC);' */
  BswM_ComM_CurrentPNCMode(ComM_PncID[COMM_INST(instIdx)], PNC_PREPARE_SLEEP);
  ComM_PncStartTimer(COMM_INST(instIdx));
}
/* Deviation MISRAC2012-1, MISRAC2012-2 */
FUNC(boolean, COMM_CODE) ComM_HsmComMPncSfPncPrepareSleepGuard1(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* guard condition 'ComM_PncGetEIRA() == 1'
   * for COMCBK[...]/ComM_PncStopTimer(PNC);
   * external transition to state PncReadySleep */
  boolean ret = FALSE;
  /* !LINKSTO ComM942,1 */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.COMCBK_PNC_PREPARE_SLEEP,1 */
  ret = (ComM_PncGetEIRA(COMM_PL_SF(instIdx)) != 0U) ? TRUE : FALSE;
  return ret;
}
/* Deviation MISRAC2012-1, MISRAC2012-2 */
FUNC(void, COMM_CODE) ComM_HsmComMPncSfPncPrepareSleepAction1(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* action 'ComM_PncStopTimer(PNC);'
   * for COMCBK[ComM_PncGetEIRA() == 1]/...
   * external transition to state PncReadySleep */
  ComM_PncStopTimer(COMM_INST(instIdx));
}
/* Deviation MISRAC2012-1, MISRAC2012-2 */
FUNC(void, COMM_CODE) ComM_HsmComMPncSfPncPrepareSleepAction2(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* action 'ComM_PncStopTimer(PNC);'
   * for FULL_COM_REQ_BY_COMM_USER[]/...
   * external transition to state PncRequested */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.FULL_COM_REQ_BY_COMM_USER_PNC_PREPARE_SLEEP_0,1 */
  ComM_PncStopTimer(COMM_INST(instIdx));
}
/* Deviation MISRAC2012-1, MISRAC2012-2 */
FUNC(void, COMM_CODE) ComM_HsmComMPncSfPncPrepareSleepAction3(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* action 'if(COMM_NO_INTERNAL_AND_EXTERNAL_REQUESTS) ComM_PNC_RequestComMode (COMM_NO_COMMUNICATION);'
   * for PREPARE_SLEEP_TIMEOUT[]/...
   * external transition to state PncNoComNotify */
  /* !LINKSTO ComM.EB.Dsn.Algorithm.PncReleaseChannel,1 */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.PREPARE_SLEEP_TIMEOUT_PNC_PREPARE_SLEEP,1 */
#if (COMM_PNC_RELEASE_CHANNEL == COMM_NO_INTERNAL_AND_EXTERNAL_REQUESTS)
  /* !LINKSTO ComM.EB.NoComRelease,1 */
  ComM_PNC_RequestComMode(COMM_INST(instIdx), COMM_NO_COMMUNICATION);
#else
  COMM_PARAM_UNUSED(instIdx);
#endif
}

/* ************************************************************************
 * State: PncReadySleep
 * Parent state: PncFullCom
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) PncReadySleep -> PncPrepareSleep: COMCBK[ComM_PncGetEIRA() == 0]/
 * 2) PncReadySleep -> PncRequested: FULL_COM_REQ_BY_COMM_USER[]/
 */

/* Deviation MISRAC2012-1 */
FUNC(void, COMM_CODE) ComM_HsmComMPncSfPncReadySleepEntry(
  COMM_PDL_SF(const uint8 instIdx))
{
  (void)COMM_HSMEMITINST(&ComM_HsmScComMPnc, COMM_INST(instIdx), COMM_HSM_COMMPNC_EV_COMCBK);
  /* entry action 'BswM_ComM_CurrentPNCMode(PNC_ID, PNC_READY_SLEEP);' */
  BswM_ComM_CurrentPNCMode(ComM_PncID[COMM_INST(instIdx)], PNC_READY_SLEEP);
}
/* Deviation MISRAC2012-1 */
FUNC(boolean, COMM_CODE) ComM_HsmComMPncSfPncReadySleepGuard1(
  COMM_PDL_SF(const uint8 instIdx))
{
  boolean ret = FALSE;
  /* guard condition 'ComM_PncGetEIRA() == 0'
   * for COMCBK[...]/
   * external transition to state PncPrepareSleep */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.COMCBK_PNC_READY_SLEEP,1 */
  ret =  (ComM_PncGetEIRA(COMM_PL_SF(instIdx)) == 0U) ? TRUE : FALSE;
  return ret;
}

/* ************************************************************************
 * State: PncRequested
 * Parent state: PncFullCom
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) PncRequested -> PncReadySleep: NO_COM_REQ_BY_ALL_COMM_USER[ComM_PncGetERA() == 0 && NO_COM]/ComM_TxEiraEra(PNC_ID) = 0; ComM_PncSendSignal(PNC); if(COMM_NO_INTERNAL_REQUESTS) ComM_PNC_RequestComMode (COMM_NO_COMMUNICATION);
 */

/* !LINKSTO ComM.EB.Dsn.StateDynamics.FULL_COM_REQ_BY_COMM_USER_PNC_READY_SLEEP_1,1 */
/* !LINKSTO ComM.EB.ComM_PncReadySleep_PncRequested_User,1 */
/* Deviation MISRAC2012-1 */
FUNC(void, COMM_CODE) ComM_HsmComMPncSfPncRequestedEntry(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* entry action 'BswM_ComM_CurrentPNCMode(PNC_ID, PNC_REQUESTED);ComM_PNC_RequestComMode(PNC, COMM_FULL_COMMUNICATION);ComM_TxEiraEra(PNC_ID) = 1;ComM_PncSendSignal(PNC); ComM_NmNwReqAllChOfPnc(PNC);' */
  const uint8 Index = (uint8)(ComM_PncID[COMM_INST(instIdx)] >> SHIFT_3_BITS);

  BswM_ComM_CurrentPNCMode(ComM_PncID[COMM_INST(instIdx)], PNC_REQUESTED);

  /* !LINKSTO ComM.EB.Dsn.Algorithm.PncRequestChannel,1 */
  ComM_PNC_RequestComMode(COMM_INST(instIdx), COMM_FULL_COMMUNICATION);
  /* ComM930: When entering the PNC sub state PNC_REQUESTED
   * the API Com_SendSignal() shall be called with the value '1' for the bit
   * representing this PNC for the Com signal assigned to this PNC with
   * ComMPncComSignalDirection "TX".
   */

  /* First, set the bit corresponding to this PNC in the EIRA to be sent */
  TS_AtomicSetBit_8(&ComM_TxEiraEra[Index], ComM_PncID[COMM_INST(instIdx)] & MASK_3_BITS);

  /* Now, send the status via the assigned Com signal(s) */
  ComM_PncSendSignal(COMM_PL_SF(instIdx));

  /* !LINKSTO ComM.EB.Dsn.StateDynamics.PNC_NM_REQUEST,1 */
  ComM_NmNwReqAllChOfPnc(COMM_INST(instIdx));
}
/* Deviation MISRAC2012-1 */
FUNC(boolean, COMM_CODE) ComM_HsmComMPncSfPncRequestedGuard1(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* guard condition 'ComM_PncGetERA() == 0 && NO_COM'
   * for NO_COM_REQ_BY_ALL_COMM_USER[...]/ComM_TxEiraEra(PNC_ID) = 0; ComM_PncSendSignal(PNC); if(COMM_NO_INTERNAL_REQUESTS) ComM_PNC_RequestComMode (COMM_NO_COMMUNICATION);
   * external transition to state PncReadySleep */
  boolean RetVal = FALSE;
  /* !LINKSTO ComM991,1 */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.NO_COM_REQ_BY_ALL_COMM_USER_PNC_REQUESTED_1,1 */
#if(COMM_PNC_GW_ENABLED == STD_ON)
  /* !LINKSTO ComM937,1 */
  if((ComM_PncGetERA(COMM_PL_SF(instIdx)) == 0x0U) &&
     (ComM_PncStateGWE[COMM_INST(instIdx)] == PNC_NO_COMMUNICATION))
  {
    RetVal = TRUE;
  }
  else
  {
    RetVal = FALSE;
  }
#else
  RetVal = TRUE;
  COMM_PARAM_UNUSED(instIdx);
#endif
  return RetVal;
}
/* Deviation MISRAC2012-1 */
FUNC(void, COMM_CODE) ComM_HsmComMPncSfPncRequestedAction1(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* action 'ComM_TxEiraEra(PNC_ID) = 0; ComM_PncSendSignal(PNC);
   * if(COMM_NO_INTERNAL_REQUESTS) ComM_PNC_RequestComMode (COMM_NO_COMMUNICATION)'
   * for NO_COM_REQ_BY_ALL_COMM_USER[ComM_PncGetERA() == 0 && NO_COM]/...
   * external transition to state PncReadySleep */
  const uint8 Index  = (uint8)(ComM_PncID[COMM_INST(instIdx)] >> SHIFT_3_BITS);
  
  /* ComM960: When entering the PNC sub state PNC_READY_SLEEP from
   * PNC_REQUESTED, the API Com_SendSignal() shall be called with the value '0'
   * for the bit representing this PNC for all Com signals assigned to this PNC
   * with ComMPncComSignalDirection "TX".
   */

  /* First, clear the bit corresponding to this PNC in the EIRA to be sent */
  TS_AtomicClearBit_8(&ComM_TxEiraEra[Index], ComM_PncID[COMM_INST(instIdx)] & MASK_3_BITS);

  /* Now, send the status via the assigned Com signal(s) */
  ComM_PncSendSignal(COMM_PL_SF(instIdx));

#if (COMM_PNC_RELEASE_CHANNEL == COMM_NO_INTERNAL_REQUESTS)
  /* !LINKSTO ComM.EB.ReadySleepFullComRelease,1 */
  ComM_PNC_RequestComMode(COMM_INST(instIdx), COMM_NO_COMMUNICATION);
#endif

}

/* ************************************************************************
 * State: PncNoCom
 * Parent state: PncTop
 * Init substate: PncNoComInit
 * Transitions originating from this state:
 * 1) PncNoCom -> PncReadySleep: COMCBK[ComM_PncGetEIRA() == 1]/BswM_ComM_CurrentPNCMode(PNC_ID, PNC_FULL_COMMUNICATION);
 * 2) PncNoCom -> PncPrepareSleep: ECUM_PNCWAKEUP_IND[]/
 * 3) PncNoCom -> PncPrepareSleep: ECUM_WAKEUP_IND[ComMSynchronousWakeUp == TRUE]/BswM_ComM_CurrentPNCMode(PNC_ID, PNC_FULL_COMMUNICATION);
 * 4) PncNoCom -> PncRequested: FULL_COM_REQ_BY_COMM_USER[]/BswM_ComM_CurrentPNCMode(PNC_ID, PNC_FULL_COMMUNICATION);
 */

/* Deviation MISRAC2012-1 */
FUNC(boolean, COMM_CODE) ComM_HsmComMPncSfPncNoComGuard1(
  COMM_PDL_SF(const uint8 instIdx))
{
  boolean ret = FALSE;
  /* guard condition 'ComM_PncGetEIRA() == 1'
   * for COMCBK[...]/BswM_ComM_CurrentPNCMode(PNC_ID, PNC_FULL_COMMUNICATION);
   * external transition to state PncReadySleep */
  ret =  (ComM_PncGetEIRA(COMM_PL_SF(instIdx)) != 0U) ? TRUE : FALSE;

  return ret;
}
/* Deviation MISRAC2012-1 */
FUNC(void, COMM_CODE) ComM_HsmComMPncSfPncNoComAction1(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* action 'BswM_ComM_CurrentPNCMode(PNC_ID, PNC_FULL_COMMUNICATION);'
   * for COMCBK[ComM_PncGetEIRA() == 1]/...
   * external transition to state PncReadySleep */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.COMCBK_PNC_NO_COMMUNICATION,1 */
  BswM_ComM_CurrentPNCMode(ComM_PncID[COMM_INST(instIdx)], PNC_FULL_COMMUNICATION);
}
/* Deviation MISRAC2012-1 */
FUNC(boolean, COMM_CODE) ComM_HsmComMPncSfPncNoComGuard3(
  COMM_PDL_SF(const uint8 instIdx))
{
#if (COMM_SYNCHRONOUS_WAKE_UP == STD_ON)
  boolean ret = TRUE;
#else
  boolean ret = FALSE;
#endif

  /* guard condition 'ComMSynchronousWakeUp == TRUE'
   * for ECUM_WAKEUP_IND[...]/BswM_ComM_CurrentPNCMode(PNC_ID, PNC_FULL_COMMUNICATION);
   * external transition to state PncPrepareSleep */

  COMM_PARAM_UNUSED(instIdx);

  return ret;
}
/* Deviation MISRAC2012-1, MISRAC2012-2 */
FUNC(void, COMM_CODE) ComM_HsmComMPncSfPncNoComAction3(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* action 'BswM_ComM_CurrentPNCMode(PNC_ID, PNC_FULL_COMMUNICATION);'
   * for ECUM_WAKEUP_IND[ComMSynchronousWakeUp == TRUE]/...
   * external transition to state PncPrepareSleep */
  BswM_ComM_CurrentPNCMode(ComM_PncID[COMM_INST(instIdx)], PNC_FULL_COMMUNICATION);
}
/* Deviation MISRAC2012-1, MISRAC2012-2 */
FUNC(void, COMM_CODE) ComM_HsmComMPncSfPncNoComAction4(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* action 'BswM_ComM_CurrentPNCMode(PNC_ID, PNC_FULL_COMMUNICATION);'
   * for FULL_COM_REQ_BY_COMM_USER[]/...
   * external transition to state PncRequested */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.FULL_COM_REQ_BY_COMM_USER_PNC_NO_COMMUNICATION_0,1 */
  BswM_ComM_CurrentPNCMode(ComM_PncID[COMM_INST(instIdx)], PNC_FULL_COMMUNICATION);
}

/* ************************************************************************
 * State: PncNoComInit
 * Parent state: PncNoCom
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 */

/* ************************************************************************
 * State: PncNoComNotify
 * Parent state: PncNoCom
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 */

/* Deviation MISRAC2012-1 */
FUNC(void, COMM_CODE) ComM_HsmComMPncSfPncNoComNotifyEntry(
  COMM_PDL_SF(const uint8 instIdx))
{
  /* entry action 'BswM_ComM_CurrentPNCMode(PNC_ID, PNC_NO_COMMUNICATION);' */
  BswM_ComM_CurrentPNCMode(ComM_PncID[COMM_INST(instIdx)], PNC_NO_COMMUNICATION);
}

/*==================[internal function definitions]=========================*/

STATIC FUNC(void, COMM_CODE) ComM_NmNwReqAllChOfPnc
(
  const uint8 pncIdx
)
{
  uint8_least chIdx;

  for (chIdx = 0U; chIdx < COMM_NUMCHANNELSOFPNC(pncIdx); chIdx++)
  {
    const uint8 Channel = COMM_CHANNELSOFPNC(pncIdx,chIdx);
    if(ComM_PncNmRequest[Channel]==TRUE)
    {
      /* !LINKSTO ComM.EB.Dsn.StateDynamics.PNC_NM_REQUEST,1 */
      (void)COMM_HSMEMITINST(&ComM_HsmScComM, Channel, COMM_HSM_COMM_EV_PNC_NM_REQUEST);
    }
  }
#if (COMM_HSM_INST_MULTI_ENABLED == STD_OFF)
  TS_PARAM_UNUSED(pncIdx);
#endif
}

/* !LINKSTO ComM.EB.Dsn.Algorithm.ComM_PNC_RequestComMode,1 */
STATIC FUNC(void, COMM_CODE) ComM_PNC_RequestComMode
(
  const uint8   pncIdx,
  ComM_ModeType Mode
)
{
  uint8_least chIdx;

  /* !LINKSTO ComM.EB.Dsn.Algorithm.ComM_PNC_RequestComMode_Mode,1 */
  ComM_PNCRequestedComMode[pncIdx] = Mode;

  for (chIdx = 0U; chIdx < COMM_NUMCHANNELSOFPNC(pncIdx); chIdx++)
  {
    const uint8 Channel = COMM_CHANNELSOFPNC(pncIdx,chIdx);
    /* !LINKSTO ComM.EB.Dsn.Algorithm.ComM_PNC_RequestComMode_Mode,1 */
    ComM_EvaluateChannel(Channel);

    /* !LINKSTO ComM.EB.Dsn.Algorithm.ComM_PNC_RequestComMode_Event,1 */
    (void)COMM_HSMEMITINST(&ComM_HsmScComM, Channel, COMM_HSM_COMM_EV_REQ_STATUS_CHANGED);
  }
}

/* Deviation MISRAC2012-1 */
STATIC FUNC(uint8, COMM_CODE) ComM_PncGetEIRA
(
  COMM_PDL_SF(const uint8 instIdx)
)
{
  const uint8 Index  = (uint8) (ComM_PncID[COMM_INST(instIdx)] >> SHIFT_3_BITS);
  const uint8 EiraMask = (uint8)(0x01U << (ComM_PncID[COMM_INST(instIdx)] & MASK_3_BITS));
  boolean ret;

  ret = ((uint8)(ComM_RxEira[Index] & EiraMask));
  return ret;
}

#if(COMM_PNC_GW_ENABLED == STD_ON)
/* Deviation MISRAC2012-1 */
STATIC FUNC(uint8, COMM_CODE) ComM_PncGetERA(COMM_PDL_SF(const uint8 instIdx))
{
  const uint8 Index  = (uint8) (ComM_PncID[COMM_INST(instIdx)] >> SHIFT_3_BITS);
  const uint8 EraMask = (uint8)(0x01U << (ComM_PncID[COMM_INST(instIdx)] & MASK_3_BITS));
  boolean ret;

  ret = ((uint8)(ComM_RxEra[Index] & EraMask));

  return ret;
}
#endif

/* Deviation MISRAC2012-1 */
STATIC FUNC(void, COMM_CODE) ComM_PncSendSignal
(
  COMM_PDL_SF(const uint8 instIdx)
)

{

#if (COMM_NUM_TX_SIGNALS > 0U)
  uint8 i;
  uint8 TxEiraEra[COMM_PN_INFO_LENGTH];

  /* A PNC may contain references to more than one TX EIRA Com Signal.
   * Therefore, the updated EIRA has to be sent to all Com Signals
   * which are referenced by this PNC.
   */
  for (i = 0U; i < ComM_PncTxSignalMap[COMM_INST(instIdx)].NumTxSignal; i++)
  {
    /* Get the index of this signal in the list of Tx EIRA signals
     * assigned to this PNC */
    const uint8 SigIndex = ComM_PncTxSignalMap[COMM_INST(instIdx)].TxSignalList[i];
    uint8 j;

    /* Some PNCs may not reference this TX EIRA Com signal.
     * Therefore, the bits corresponding to PNCs which do not
     * reference this Com signal have to be masked out before sending.
     */
    for (j = 0U; j < COMM_PN_INFO_LENGTH; j++)
    {
      /* !LINKSTO ComM966,1, ComM955,1, ComM959,1 */
      TxEiraEra[j] = ComM_TxEiraEra[j] & ComM_PncTxMask[SigIndex][j];
    }
    /* !LINKSTO ComM946,1, ComM930,1, ComM992,1, ComM960,1 */
    (void)Com_SendSignal(ComM_TxComSignalCfg[SigIndex], TxEiraEra);
  }
#else
  COMM_PARAM_UNUSED(instIdx);
#endif
}

FUNC(void, COMM_CODE) ComM_PncProcessTimers(void)
{
  /* No *_least type for a loop variable as the variable is also used as
     an argument whose underlying type is uint8  */
  uint8 PncIdx;
  boolean emitEvent = FALSE;
  for (PncIdx = 0U ; PncIdx < COMM_NUM_PNC ; PncIdx++)
  {
    emitEvent = FALSE;
    ComM_Enter_SCHM_COMM_EXCLUSIVE_AREA_0();
    if (COMM_PNC_TIMER(PncIdx) > 0U)
    {
      --COMM_PNC_TIMER(PncIdx);
      if (COMM_PNC_TIMER(PncIdx) == 0U)
      {
        emitEvent = TRUE;
      }
    }
    ComM_Exit_SCHM_COMM_EXCLUSIVE_AREA_0();
    if (emitEvent == TRUE)
    {
      /* timeout events are generated outside of transitions, therefore do
       * not use the EMITTOSELF function */
      /* !LINKSTO ComM.EB.Dsn.StateDynamics.PREPARE_SLEEP_TIMEOUT,1 */
      (void)COMM_HSMEMITINST(
        &ComM_HsmScComMPnc, PncIdx, COMM_HSM_COMMPNC_EV_PREPARE_SLEEP_TIMEOUT);      
    }
  }
}

#define COMM_STOP_SEC_CODE
#include <MemMap.h>
#endif /* (COMM_NUM_PNC > 0U) */
/*==================[end of file]===========================================*/
