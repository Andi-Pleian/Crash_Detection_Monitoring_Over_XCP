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
#include <ComStack_Types.h>         /* AUTOSAR communication stack types */

#include <CanSM_Int_Stc.h>          /* Module internal static header */
#include <CanSM_Cfg.h>              /* Module configuration */

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[internal function declarations]========================*/

/*==================[internal constants]====================================*/

/*==================[internal data]=========================================*/

/*==================[external constants]====================================*/


#define CANSM_START_SEC_CONFIG_DATA_8
#include <MemMap.h>

/** \brief Empty configuration structure to be passed to CanSM_Init() */
CONST(CanSM_ConfigType, CANSM_APPL_CONST) CanSM_Config_0 = 0U;


CONST(uint8, CANSM_APPL_CONST) CanSM_ControllerNetworkLut[CANSM_CONTROLLERS_ID_NUM] =
{
0U,
};


#define CANSM_STOP_SEC_CONFIG_DATA_8
#include <MemMap.h>

/*==================[external data]=========================================*/

#define CANSM_START_SEC_VAR_NO_INIT_8
#include <MemMap.h>

VAR(uint8, CANSM_VAR) CanSM_CtrlModeIndication[CANSM_CONTROLLERS_ID_NUM];

#define CANSM_STOP_SEC_VAR_NO_INIT_8
#include <MemMap.h>

#define CANSM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include <MemMap.h>

VAR(CanSM_NetworkInfoType, CANSM_VAR) CanSM_NetworkInfo[CANSM_NETWORKS_NUM];

#define CANSM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include <MemMap.h>

/*==================[external function definitions]=========================*/


/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/

