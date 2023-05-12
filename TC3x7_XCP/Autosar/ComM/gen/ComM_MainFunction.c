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



/** \brief Main function for channelid 0 **/
FUNC(void, COMM_CODE) ComM_MainFunction_0
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
      
       ComM_PncProcessTimers();
      
      ComM_PncMainFunction();
    }
#endif

    ComM_ProcessTimers(0U);

    /* ComM channels are independent of each other and do not send events to
     * each other. Hence the return value is ignored */
    (void) COMM_HSMMAININST(
      &ComM_HsmScComM, 0U);
  }
}

/** \brief Main function for channelid 1 **/
FUNC(void, COMM_CODE) ComM_MainFunction_1
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
      
      ComM_PncMainFunction();
    }
#endif

    ComM_ProcessTimers(1U);

    /* ComM channels are independent of each other and do not send events to
     * each other. Hence the return value is ignored */
    (void) COMM_HSMMAININST(
      &ComM_HsmScComM, 1U);
  }
}




#define COMM_STOP_SEC_CODE
#include <MemMap.h>

/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/
