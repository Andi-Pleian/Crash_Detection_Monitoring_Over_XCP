/**
 * \file
 *
 * \brief AUTOSAR Xcp
 *
 * This file contains the implementation of the AUTOSAR
 * module Xcp.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2017 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[inclusions]============================================*/

#include <Xcp_Trace.h>
#include <Std_Types.h>        /* AUTOSAR standard types */
#include <TSAutosar.h>        /* EB specific standard types */

#include <Xcp.h>              /* Module public API */
#if ( (XCP_DEFAULT_XCP_MODULE_STATE == STD_ON) || (XCP_ENABLE_XCP_CONTROL_API == STD_ON) )
#include <Xcp_Int.h>          /* Internal types */
#include <TSMem.h>            /* EB memory functions */
#include <Xcp_Cbk.h>          /* Callbacks and callouts of Xcp */

#if (XCP_RESOURCE_CAL_PAG == XCP_RESOURCE_CAL_PAG_MASK)
#include <Xcp_UserCallouts.h> /* User Callout Function declarations */
#endif

#include <SchM_Xcp.h>         /* Needed for exclusive area definition */

/*==================[macros]================================================*/
[!AUTOSPACING!][!//
[!VAR "XcpEventChannelMFEnabled"="(XcpGeneral/XcpEventTriggerMainFunc = 'true') and (node:exists(XcpConfig/*[1]/XcpEventChannel)) and (num:i(count(XcpConfig/*[1]/XcpEventChannel/*)) > 0)"!]
[!VAR "EventChannelIndex" = "0"!]
[!IF "$XcpEventChannelMFEnabled"!]
  [!LOOP "XcpConfig/*[1]/XcpEventChannel/*"!]
    [!IF "XcpEventChannelTimeCycle > 0"!]
/** \brief The index of the Event MainFunction in the Xcp_IsMFEventCurrentlyProcessing flags */
#define XCP_EVENT_MAIN_FUNCTION_[!"@name"!]_INDEX      [!"num:i($EventChannelIndex)"!]U
    [!VAR "EventChannelIndex" = "$EventChannelIndex + 1"!]
    [!ENDIF!]
  [!ENDLOOP!]
[!ENDIF!]


/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[internal constants]====================================*/

/*==================[external constants]====================================*/

/*==================[internal data]=========================================*/

#define XCP_START_SEC_VAR_8BIT
#include <MemMap.h>

[!VAR "XcpCrcMFEnabled"="XcpGeneral/XcpBuildChecksumMainFunctionSupport = 'true'"!]
[!VAR "XcpComMFEnabled"="node:exists(XcpGeneral/XcpSupportComMainFunctions) = 'true'"!]

[!IF "$XcpComMFEnabled = 'true'"!]
/* Xcp_CrcMainFunction processing status */
STATIC VAR(boolean, XCP_VAR) Xcp_TxMainFunction_Running = FALSE;
/* Xcp_RxMainFunction processing status */
STATIC VAR(boolean, XCP_VAR) Xcp_RxMainFunction_Running = FALSE;
[!ENDIF!]
[!IF "$XcpCrcMFEnabled = 'true'"!]
/* Xcp_CrcMainFunction processing status */
STATIC VAR(boolean, XCP_VAR) Xcp_CrcMainFunction_Running = FALSE;
[!ENDIF!]

/*==================[external data]=========================================*/

[!IF "$XcpEventChannelMFEnabled"!]
/** \brief Flags signaling if an Event Main Function is currently executing or not */
VAR(uint8, XCP_VAR) Xcp_IsMFEventCurrentlyProcessing[XCP_EVENT_PROCESSING_FLAG_SIZE] = {0};

/** \brief Flag to disable the execution of any event main function: triggered when
 ** an autonomous disconnect is going to happen 
 **/
VAR(boolean, XCP_VAR) Xcp_EventMainFunctionsExecutionIsAllowed = TRUE;

[!ENDIF!]

#define XCP_STOP_SEC_VAR_8BIT
#include <MemMap.h>

/*==================[external function definitions]=========================*/

[!IF "($XcpEventChannelMFEnabled = 'true') or ($XcpCrcMFEnabled = 'true') or ($XcpComMFEnabled = 'true')"!]
#define XCP_START_SEC_CODE
#include <MemMap.h>
[!ENDIF!]
[!IF "$XcpEventChannelMFEnabled"!]
  [!LOOP "XcpConfig/*[1]/XcpEventChannel/*"!]
    [!IF "XcpEventChannelTimeCycle > 0"!]

/*------------------[Xcp_MainFunction_EventChannel---------------------------------------*/
FUNC(void, XCP_CODE) Xcp_MainFunction_[!"@name"!](void)
{
  boolean ExecuteMainFunction = FALSE;   /* Indicates whether main function must be continued. */
  DBG_XCP_MAINFUNCTION_[!"text:toupper(@name)"!]_ENTRY();

  if (Xcp_ControlStateOfXcpModule == XCP_STATE_ACTIVE)
  {
    /* Enter critical section */
    SchM_Enter_Xcp_SCHM_XCP_EXCLUSIVE_AREA_XCP_INTERNALS();

    /* check if the Xcp_MainFunction is already being processed */
    if ((XCP_IS_BYTE_FLAG_SET(XCP_EVENT_MAIN_FUNCTION_[!"@name"!]_INDEX,
                               Xcp_IsMFEventCurrentlyProcessing) == FALSE) &&
        (Xcp_Initialized == TRUE)
#if ((XCP_ON_FLEXRAY_ENABLED == STD_ON) && (XCP_FLEXRAY_TP_COMMANDS_SUPPORTED == STD_ON))
      /* continue processing only when the Flexray Hardware Buffers are initialized */
       && (XCP_IS_FLAG_SET(XCP_FLEXRAY_BUFFERS_READY_FLAG, Xcp_ConnectionStatus.Flags, uint8) == TRUE)
#endif
       && (Xcp_EventMainFunctionsExecutionIsAllowed == TRUE)
       )
    {
      XCP_SET_BYTE_FLAG(XCP_EVENT_MAIN_FUNCTION_[!"@name"!]_INDEX, Xcp_IsMFEventCurrentlyProcessing);
      ExecuteMainFunction = TRUE;
    }

    /* Exit critical section */
    SchM_Exit_Xcp_SCHM_XCP_EXCLUSIVE_AREA_XCP_INTERNALS();

    /* Check whether XCP is initialized  and the Xcp_MainFunction_Event
     * is not already being processed */
    if (ExecuteMainFunction == TRUE)
    {
      /* Execute Receive processor */
      Xcp_ProcessReception(XCP_SID_EVENT_MAIN_FUNCTION);

#if (XCP_MAX_DAQ > 0U)
      /* Execute Event [!"@name"!] */
      Xcp_ProcessEvents([!"XcpEventChannelNumber"!]U);
#endif /* (XCP_MAX_DAQ > 0U) */

      /* Execute Transmit processor */
      Xcp_ProcessTransmit(XCP_SID_EVENT_MAIN_FUNCTION);
    }

    /* reset the processing status of this event main function */
    XCP_CLEAR_BYTE_FLAG_ATOMIC(XCP_EVENT_MAIN_FUNCTION_[!"@name"!]_INDEX, Xcp_IsMFEventCurrentlyProcessing);

  }
  else/*(Xcp_ControlStateOfXcpModule == XCP_STATE_ACTIVE && Xcp_EventMainFunctionsExecutionIsAllowed == TRUE)*/
  {
    TS_PARAM_UNUSED(ExecuteMainFunction);
  }

  DBG_XCP_MAINFUNCTION_[!"text:toupper(@name)"!]_EXIT();
}
    [!ENDIF!]
  [!ENDLOOP!]
[!ENDIF!]

[!IF "$XcpCrcMFEnabled"!]
/*------------------[Xcp_CrcMainFunction]---------------------------------------*/
FUNC(void, XCP_CODE) Xcp_CrcMainFunction(void)
{
  boolean ExecuteMainFunction = FALSE;   /* Indicates whether main function must be continued. */
  DBG_XCP_CRCMAINFUNCTION_ENTRY();
  if (Xcp_ControlStateOfXcpModule != XCP_STATE_INACTIVE)
  {
    /* Enter critical section */
    SchM_Enter_Xcp_SCHM_XCP_EXCLUSIVE_AREA_XCP_INTERNALS();
    /* check if the Xcp_MainFunction is already being processed */
    if ((Xcp_CrcMainFunction_Running == FALSE) &&
        (Xcp_Initialized == TRUE))
    {
      Xcp_CrcMainFunction_Running = TRUE;
      ExecuteMainFunction = TRUE;
    }
    /* Exit critical section */
    SchM_Exit_Xcp_SCHM_XCP_EXCLUSIVE_AREA_XCP_INTERNALS();

    /* Check whether XCP is initialized  and the Xcp_TxMainFunction
     * is not already being processed */
    if (ExecuteMainFunction == TRUE)
    {
      if(Xcp_GetBuildChecksumReqStatus() == E_OK)
      {
        Xcp_CalculateCRC();
      }
      /* reset the processing status of Xcp_TxMainFunction */
      Xcp_CrcMainFunction_Running = FALSE;

    }
  }
  else/*(Xcp_ControlStateOfXcpModule == XCP_STATE_INACTIVE)*/
  {
    TS_PARAM_UNUSED(ExecuteMainFunction);
  }

  DBG_XCP_CRCMAINFUNCTION_EXIT();
}
[!ENDIF!]

[!IF "$XcpComMFEnabled = 'true'"!]
/*------------------[Xcp_TxMainFunction]---------------------------------------*/
FUNC(void,XCP_CODE) Xcp_TxMainFunction(void)
{
  boolean ExecuteMainFunction = FALSE;   /* Indicates whether main function must be continued. */
  DBG_XCP_TXMAINFUNCTION_ENTRY();

  if (Xcp_ControlStateOfXcpModule != XCP_STATE_INACTIVE)
  {
    /* Enter critical section */
    SchM_Enter_Xcp_SCHM_XCP_EXCLUSIVE_AREA_XCP_INTERNALS();
    /* check if the Xcp_MainFunction is already being processed */
    if (
         (Xcp_TxMainFunction_Running == FALSE) 
         && (Xcp_Initialized == TRUE)
#if ((XCP_ON_FLEXRAY_ENABLED == STD_ON) && (XCP_FLEXRAY_TP_COMMANDS_SUPPORTED == STD_ON))
         /* continue processing only when the Flexray Hardware Buffers are initialized */
         && (XCP_IS_FLAG_SET(XCP_FLEXRAY_BUFFERS_READY_FLAG, Xcp_ConnectionStatus.Flags, uint8) == TRUE)
#endif
       )
    {
      Xcp_TxMainFunction_Running = TRUE;
      ExecuteMainFunction = TRUE;
    }
    /* Exit critical section */
    SchM_Exit_Xcp_SCHM_XCP_EXCLUSIVE_AREA_XCP_INTERNALS();

    /* Check whether XCP is initialized  and the Xcp_TxMainFunction
     * is not already being processed */
    if (ExecuteMainFunction == TRUE)
    {
      /* Execute Transmit processor */
      Xcp_ProcessTransmit(XCP_SID_TX_MAIN_FUNCTION);

      /* reset the processing status of Xcp_TxMainFunction */
      Xcp_TxMainFunction_Running = FALSE;
    }
  }
  else/*(Xcp_ControlStateOfXcpModule == XCP_STATE_INACTIVE)*/
  {
    TS_PARAM_UNUSED(ExecuteMainFunction);
  }

  DBG_XCP_TXMAINFUNCTION_EXIT();
}

/*------------------[Xcp_RxMainFunction]---------------------------------------*/
FUNC(void,XCP_CODE) Xcp_RxMainFunction(void)
{
  boolean ExecuteMainFunction = FALSE;   /* Indicates whether main function must be continued. */
  DBG_XCP_RXMAINFUNCTION_ENTRY();

  if (Xcp_ControlStateOfXcpModule != XCP_STATE_INACTIVE)
  {
    /* Enter critical section */
    SchM_Enter_Xcp_SCHM_XCP_EXCLUSIVE_AREA_XCP_INTERNALS();
    /* check if the Xcp_MainFunction is already being processed */
    if (
         (Xcp_RxMainFunction_Running == FALSE) 
         && (Xcp_Initialized == TRUE)
#if ((XCP_ON_FLEXRAY_ENABLED == STD_ON) && (XCP_FLEXRAY_TP_COMMANDS_SUPPORTED == STD_ON))
         /* continue processing only when the Flexray Hardware Buffers are initialized */
         && (XCP_IS_FLAG_SET(XCP_FLEXRAY_BUFFERS_READY_FLAG, Xcp_ConnectionStatus.Flags, uint8) == TRUE)
#endif
       )
    {
      Xcp_RxMainFunction_Running = TRUE;
      ExecuteMainFunction = TRUE;
    }
    /* Exit critical section */
    SchM_Exit_Xcp_SCHM_XCP_EXCLUSIVE_AREA_XCP_INTERNALS();

    /* Check whether XCP is initialized  and the Xcp_RxMainFunction
     * is not already being processed */
    if (ExecuteMainFunction == TRUE)
    {
      /* Execute Receive processor */
      Xcp_ProcessReception(XCP_SID_RX_MAIN_FUNCTION);

      /* reset the processing status of Xcp_TxMainFunction */
      Xcp_RxMainFunction_Running = FALSE;
    }
  }
  else/*(Xcp_ControlStateOfXcpModule == XCP_STATE_INACTIVE)*/
  {
    TS_PARAM_UNUSED(ExecuteMainFunction);
  }
  DBG_XCP_RXMAINFUNCTION_EXIT();
}
[!ENDIF!]

[!IF "($XcpEventChannelMFEnabled = 'true') or ($XcpCrcMFEnabled = 'true') or ($XcpComMFEnabled = 'true')"!]
#define XCP_STOP_SEC_CODE
#include <MemMap.h>
[!ENDIF!]
/*==================[internal function definitions]=========================*/

#endif /* ( (XCP_DEFAULT_XCP_MODULE_STATE == STD_ON) || (XCP_ENABLE_XCP_CONTROL_API == STD_ON) ) */
/*==================[end of file]===========================================*/
