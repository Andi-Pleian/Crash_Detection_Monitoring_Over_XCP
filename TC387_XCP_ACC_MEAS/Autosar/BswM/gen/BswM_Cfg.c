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

/* !LINKSTO BswM.Impl.SourceFile.BswM_Cfg_c,1 */

/*==================[inclusions]============================================*/
/* Internal headers */
#include <BswM.h>
#include <BswM_Int_Cfg.h>
#include <BswM_Int.h>

#include <BswM_Lcfg.h>

#if (BSWM_IMPLEMENTATION_CONFIG_VARIANT == BSWM_VARIANT_PRE_COMPILE)
#include <BswM_PBcfg.h>       /* Post build data structure        */
#endif

#include <BswM_Trace.h>

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[internal function declarations]========================*/
#define BSWM_START_SEC_CODE
#include <MemMap.h>

STATIC FUNC(void, BSWM_CODE) BswM_Core_Init(void);

STATIC FUNC(void, BSWM_CODE) BswM_Partition_Init
(
P2VAR(BswM_PartitionContextType, BSWM_VAR, BSWM_APPL_DATA) inst
);

STATIC FUNC(void, BSWM_CODE) BswM_RT_Init
(
P2VAR(BswM_PartitionContextType, BSWM_VAR, BSWM_APPL_DATA) inst
);

#define BSWM_STOP_SEC_CODE
#include <MemMap.h>

/*==================[external function declarations]========================*/

/*==================[internal constants]====================================*/

/*==================[external constants]====================================*/

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

CONST(uint32, BSWM_CONST) BswM_LcfgSignature = 3958107115U;

#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/*==================[internal data]=========================================*/

/*==================[external data]=========================================*/

#define BSWM_START_SEC_VAR_INIT_UNSPECIFIED
#include <MemMap.h>

P2CONST(BswM_ConfigType, AUTOMATIC, BSWM_APPL_CONST) BswM_PostBuildConfig;

#define BSWM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include <MemMap.h>

/*==================[external function definitions]=========================*/

/* !LINKSTO BswM.Impl.MemoryMapping.SharedCode,1 */
#define BSWM_START_SEC_CODE
#include <MemMap.h>

FUNC(Std_ReturnType, BSWM_CODE) BswM_IsValidConfig
(
P2CONST(void, AUTOMATIC, BSWM_APPL_CONST) voidPtr
)
{
  /* Assume an invalid configuration */
  Std_ReturnType result = E_NOT_OK;
  /*
   * In the current implementation all BswM_ConfigType instances from
   * the BswM_RootConfig member of the BswM_ConfigLayoutType structure
   * share the same signatures therefore only the first one is checked.
   */
  P2CONST(BswM_ConfigType, AUTOMATIC, BSWM_APPL_CONST) ConfigPtr = voidPtr;

  if (ConfigPtr != NULL_PTR)
  {
    /* Check if the configuration fits to the platform */
    if (TS_PlatformSigIsValid(ConfigPtr->PlatformSignature) == TRUE )
    {
      /* Validate the post build configuration against the compile time
       * configuration */
      if (BSWM_CFG_SIGNATURE == ConfigPtr->CfgSignature)
      {
        /* Validate the post build configuration against the link time
         * configuration */
        if (BswM_LcfgSignature == ConfigPtr->LcfgSignature)
        {
          /* Validate the post build configuration against the compile time
           * published information configuration */
          if (BSWM_PUBLIC_INFO_SIGNATURE == ConfigPtr->PublicInfoSignature)
          {
            /* Indicate that the configuration is valid */
            result = E_OK;
          }
        }
      }
    }
  }

  return result;
}

/* !LINKSTO BswM0118,1 */
FUNC(void, BSWM_CODE) BswM_Init
(
P2CONST(BswM_ConfigType, AUTOMATIC, BSWM_APPL_CONST) ConfigPtr
)
{
  P2VAR(BswM_PartitionContextType, AUTOMATIC, BSWM_APPL_DATA) inst = BswM_GetInstance();
  DBG_BSWM_INIT_ENTRY(ConfigPtr);

  /*
   * The Os application from which EcuM calls BswM_Init must be mapped
   * to a BswM configuration.
   */
  if ( inst != NULL_PTR)
  {
    /* !LINKSTO BswM.IMPLEMENTATION_CONFIG_VARIANT,1 */
    TS_PARAM_UNUSED(ConfigPtr);
    BswM_PostBuildConfig = &BswM_ConfigLayout.BswM_RootConfig[0];
    BswM_Core_Init();
  }
  else
  {
#if (BSWM_DEV_ERROR_DETECT == STD_ON)
    BSWM_DET_REPORT_ERROR(0U, BSWM_SID_INIT, BSWM_E_WRONG_CONTEXT);
#endif
  }
  DBG_BSWM_INIT_EXIT(ConfigPtr);
}

/* !LINKSTO BswM.Impl.Api.BswM_Core_Init,1 */
/* !LINKSTO BswM.Impl.Algorithm.Initialization,1 */
STATIC FUNC(void, BSWM_CODE) BswM_Core_Init(void)
{
  DBG_BSWM_CORE_INIT_ENTRY();
  BswM_Partition_Init(&BswM_Context);
  DBG_BSWM_CORE_INIT_EXIT();
}

/* !LINKSTO BswM.Impl.Api.BswM_GetInstance,1 */
FUNC(P2VAR(BswM_PartitionContextType, BSWM_VAR, BSWM_APPL_DATA), BSWM_CODE) BswM_GetInstance(void)
{
  return &BswM_Context;
}

/*==================[internal function definitions]=========================*/

/* !LINKSTO BswM.Impl.Algorithm.Initialization,1 */
STATIC FUNC(void, BSWM_CODE) BswM_Partition_Init
(
P2VAR(BswM_PartitionContextType, BSWM_VAR, BSWM_APPL_DATA) inst
)
{
  DBG_BSWM_PARTITION_INIT_ENTRY(inst);

  inst->RunTimeContext.IsInitialized = FALSE;

  BswM_LT_Init();

  BswM_RT_Init(inst);

  inst->RunTimeContext.IsInitialized = TRUE;

  DBG_BSWM_PARTITION_INIT_EXIT(inst);
}

STATIC FUNC(void, BSWM_CODE) BswM_RT_Init
(
P2VAR(BswM_PartitionContextType, BSWM_VAR, BSWM_APPL_DATA) inst
)
{
  BswMIndexType i;
  DBG_BSWM_RT_INIT_ENTRY(inst);
  for (i = 0U; i < BSWM_GET_NUM_RULES(inst->ID); i++)
  {
    /* On startup, the rule initial state corresponds to the last expression
     * result. */
    inst->RunTimeContext.RuleResultTable[BSWM_GET_RULE_TABLE(inst->ID)[i].ID] = BSWM_GET_RULE_TABLE(inst->ID)[i].RuleInitState;
  }

  for(i = 0U; i < inst->LinkTimeContext->numBswMExpressions; i++)
  {
    BSWM_SET_LOG_EXPR_INIT_STATUS(i, BSWM_GET_EXPR_STATE(i));
  }

  DBG_BSWM_RT_INIT_EXIT(inst);
}

#define BSWM_STOP_SEC_CODE
#include <MemMap.h>
