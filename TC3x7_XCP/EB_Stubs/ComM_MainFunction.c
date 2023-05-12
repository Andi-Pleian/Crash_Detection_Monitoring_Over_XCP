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

/*==================[inclusions]============================================*/

/* prevent RTE symbols defined in ComM.h to be visible for ComM's .c files */
#if (defined COMM_INTERNAL_USAGE)
#error COMM_INTERNAL_USAGE already defined
#endif
#define COMM_INTERNAL_USAGE

#include <ComM_Int.h>               /* Module public API */
#include <ComM_BSW_Cfg.h>           /* Module Internal identifiers */
#include <ComM.h>
#include <ComM_Int.h>
#if (COMM_INCLUDE_RTE == STD_ON)
/* Symbols defined by RTE: Rte_ModeType_ComMode
 * Functions declared by RTE: ComM_RequestComMode(), ComM_MainFunction_X() */
 /* !LINKSTO ComM506_Refine_Rte,1 */
#include <Rte_ComM.h>
#endif
/* for the case COMM_INCLUDE_RTE == STD_OFF these symbols are provided via
 * ComM.h. */

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

#define COMM_START_SEC_CODE
#include <MemMap.h>

[!VAR "LeastMainFnPeriodChId" = "0"!][!//
[!LOOP "node:order(ComMConfigSet/*[1]/ComMChannel/*, 'ComMMainFunctionPeriod')"!][!//
[!VAR "LeastMainFnPeriodChId" = "ComMChannelId"!]
[!BREAK!]
[!ENDLOOP!][!//

[!LOOP "ComMConfigSet/*[1]/ComMChannel/*"!][!//
/** \brief Main function for channelid [!"ComMChannelId"!] **/
FUNC(void, COMM_CODE) ComM_MainFunction_[!"ComMChannelId"!]
(
  void
)
{
  if (ComM_InitStatus != COMM_UNINIT)
  {
/* !LINKSTO ComM979,1 */
#if (COMM_PNC_SUPPORT == STD_ON)
    if( COMM_PNC_ENABLED )
    {
      [!IF "ComMChannelId = $LeastMainFnPeriodChId"!]
       ComM_PncProcessTimers();
      [!ENDIF!]
      ComM_PncMainFunction();
    }
#endif

    ComM_ProcessTimers([!"ComMChannelId"!]U);

    /* ComM channels are independent of each other and do not send events to
     * each other. Hence the return value is ignored */
    (void) COMM_HSMMAININST(
      &ComM_HsmScComM, [!"ComMChannelId"!]U);
  }
}

[!ENDLOOP!][!//

[!IF "ComMGeneral/ComMPncSupport = 'true'"!]

[!VAR "Index" = "0"!]
[!LOOP "node:order(node:refs(ComMConfigSet/*[1]/ComMPnc/*/ComMPncComSignal/*[ComMPncComSignalKind='EIRA']
        [ComMPncComSignalDirection='RX']/ComMPncComSignalRef), 'ComHandleId')"!]
FUNC(void, COMM_CODE) ComM_COMCbk_[!"node:name(.)"!](void)
{
  /* There is one bit indicating the status of each unique Com signal.
   * For easy mapping, the bits are assigned in the ascending order of
   * the signal handle ids.
   */
  ComM_Enter_SCHM_COMM_EXCLUSIVE_AREA_0();
  ComM_RxEiraSignalStatus = TRUE;
  ComM_Exit_SCHM_COMM_EXCLUSIVE_AREA_0();
}
[!VAR "Index" = "$Index + 1"!]
[!ENDLOOP!]

#if(COMM_PNC_GW_ENABLED == STD_ON)
[!VAR "Index" = "0"!]
[!LOOP "node:order(node:refs(ComMConfigSet/*[1]/ComMPnc/*/ComMPncComSignal/*[ComMPncComSignalKind='ERA']
        [ComMPncComSignalDirection='RX']/ComMPncComSignalRef), 'ComHandleId')"!]
FUNC(void, COMM_CODE) ComM_COMCbk_[!"node:name(.)"!](void)
{
  /* There is one bit indicating the status of each unique Com signal.
   * For easy mapping, the bits are assigned in the ascending order of
   * the signal handle ids.
   */
  ComM_Enter_SCHM_COMM_EXCLUSIVE_AREA_0();
  ComM_RxEraSignalStatus = TRUE;
  ComM_Exit_SCHM_COMM_EXCLUSIVE_AREA_0();
}
[!VAR "Index" = "$Index + 1"!]
[!ENDLOOP!]
#endif
[!ENDIF!]

#define COMM_STOP_SEC_CODE
#include <MemMap.h>

/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/
