/**
 * \file
 *
 * \brief AUTOSAR CanSM
 *
 * This file contains the implementation of the AUTOSAR
 * module CanSM.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2017 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[inclusions]============================================*/

#include <CanSM_Trace.h>
#include <TSAutosar.h>              /* EB specific standard types */
#include <ComStack_Types.h>         /* AUTOSAR communication stack types */

#include <CanSM_Api_Static.h>       /* Module public API */
#include <CanSM_Cfg.h>              /* Module generated configuration */
#include <CanSM_Internal.h>         /* Module interna */
#include <ComM.h>                   /* ComM_ModeType */

/*==================[version check]=========================================*/

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[internal function declarations]========================*/

/*==================[internal constants]====================================*/

/*==================[internal data]=========================================*/

/*==================[external constants]====================================*/

/*==================[external data]=========================================*/

/*==================[external function definitions]=========================*/

#define CANSM_START_SEC_CODE
#include <MemMap.h>

FUNC(void, CANSM_CODE) CanSM_Init (
  P2CONST( CanSM_ConfigType, AUTOMATIC, CANSM_APPL_CONST ) ConfigPtr
)
{
  CanSM_NetworkIndexType nw;

  DBG_CANSM_INIT_ENTRY(ConfigPtr);

  /* The parameter is ignored because post-build configuration is not
     supported. */
  TS_PARAM_UNUSED( ConfigPtr );

  for ( nw=0U; nw<CANSM_NETWORKS_NUM; nw++)
  {
    CANSM_NW_INFO_STATE(nw) = CANSM_UNINITED;
    CANSM_NW_INFO_INTERNALSTATE(nw) = CANSM_S_NOIN;
    CANSM_NW_INFO_REQCOMMODE(nw) = COMM_NO_COMMUNICATION;
    CANSM_NW_INFO_TRANSITION_ONGOING(nw) = FALSE;
  }

  CanSM_GlobalInit = CANSM_GLOBAL_INIT;

  for ( nw=0U; nw<CANSM_NETWORKS_NUM; nw++)
  {
    CanSM_DoTransitionSequence(nw, CANSM_T_RNOCO_INITIAL, FALSE);
  }

  DBG_CANSM_INIT_EXIT(ConfigPtr);
}

#define CANSM_STOP_SEC_CODE
#include <MemMap.h>

/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/

