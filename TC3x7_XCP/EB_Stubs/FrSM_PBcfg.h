/**
 * \file
 *
 * \brief AUTOSAR FrSM
 *
 * This file contains the implementation of the AUTOSAR
 * module FrSM.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2017 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef FRSM_PBCFG_H
#define FRSM_PBCFG_H

/*==================[includes]==============================================*/

#include <FrSM.h>      /* FrSM interface headerfile */

/*==================[macros]================================================*/

/** \brief Map name of post-build configuration to internal representation */
#define FrSMConfig_0 (FrSMConfig_0Layout.RootCfg)

/*==================[type definitions]======================================*/

/** \brief Internal post-build configuration structure type */
typedef struct
{
    /** \brief Type passed to \a FrSM_Init() */
    const FrSM_ConfigType RootCfg;
}FrSM_CfgType;

/*==================[external constants]====================================*/

#define FRSM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <MemMap.h>  /* !LINKSTO FrSm.ASR40.FrSm057,1 */

/** \brief Internal post-build configuration structure */
extern CONST(FrSM_CfgType, FRSM_APPL_CONST) FrSMConfig_0Layout;

#define FRSM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <MemMap.h>  /* !LINKSTO FrSm.ASR40.FrSm057,1 */



#endif /* FRSM_PBCFG_H */

/*==================[end of file]===========================================*/
