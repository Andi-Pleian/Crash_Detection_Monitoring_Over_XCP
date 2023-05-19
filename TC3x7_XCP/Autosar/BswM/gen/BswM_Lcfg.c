
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

/*  MISRA-C:2004 Deviation List
 *
 *  MISRA-1) Deviated Rule: 12.4 (required)
 *    The right hand operand of a logical && or || operator shall not contain
 *    side effects.
 *
 *   Reason:
 *   One BswM_ExprResult and BswM_ExprState function must execute another
 *   BswM_ExprResult or BswM_ExprState function when one logical expression
 *   contains one or more nested logical expressions.  These functions will
 *   never contain side effects since they only evaluate the current state of
 *   the associated mode conditions or mode request ports.
 */

/* !LINKSTO BswM0024,1 */
/* The BswM_Lcfg.c contains all link-time configuration parameters. */

/* !LINKSTO BswM.Impl.SourceFile.BswM_Partition_Lcfg_c,1 */

/*==================[inclusions]============================================*/

#include <BswM_Trace.h>       /* Dbg macros */
#include <BswM.h>
#include <BswM_Int_Cfg.h>
#include <BswM_Int.h>
#include <TSMem.h>            /* Used for TS_MemSet */
//#include <SchM_BswM.h>        /* SchM API for BswM         */

#include <BswM_Lcfg.h>

/*==================[macros]================================================*/

#define BSWM_NUM_LOGICAL_EXPRESSIONS 3U

/*==================[type definitions]======================================*/

/*==================[internal function declarations]========================*/
void   SchM_Enter_BswM_SCHM_BSWM_EXCLUSIVE_AREA(void)
{

}

void  SchM_Exit_BswM_SCHM_BSWM_EXCLUSIVE_AREA(void)
{

}
/* !LINKSTO BswM.Impl.MemoryMapping.InstanceCode,1 */
#define BSWM_START_SEC_CODE
#include <MemMap.h>

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_ECUM_STATE_RUN(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_ECUM_STATE_PREP_SHUTDOWN(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_ECUM_STATE_SHUTDOWN(void);

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_ECUM_STATE_RUN(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_ECUM_STATE_PREP_SHUTDOWN(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_ECUM_STATE_SHUTDOWN(void);

STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_BswMAction_ComM_Allow_CAN(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_BswMAction_ComM_DoNotAllow_CAN(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_BswMAction_ComM_SwitchOn_CAN(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_BswMAction_ComM_SwitchOff_CAN(void);

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprGetState(uint16 exprIndex);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprGetResult(uint16 exprIndex);

STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ExecuteAction(uint16 actionIndex);

STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ExecuteModeArbitration(uint8 source, uint32 channel, uint8 mode);

#define BSWM_STOP_SEC_CODE
#include <MemMap.h>

/*==================[external function declarations]========================*/

/*==================[internal constants]====================================*/

/*==================[external constants]====================================*/

/*==================[internal data]=========================================*/

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include <MemMap.h>
/**
 * BswM_NumModeRequestPortsTable
 */
STATIC CONST( uint16 , AUTOMATIC ) BswM_NumModeRequestPortsTable[12] = 
{
  UINT16_C( 0 ), /* [0] */
  UINT16_C( 0 ), /* [1] */
  UINT16_C( 0 ), /* [2] */
  UINT16_C( 0 ), /* [3] */
  UINT16_C( 0 ), /* [4] */
  UINT16_C( 0 ), /* [5] */
  UINT16_C( 0 ), /* [6] */
  UINT16_C( 0 ), /* [7] */
  UINT16_C( 0 ), /* [8] */
  UINT16_C( 0 ), /* [9] */
  UINT16_C( 0 ), /* [10] */
  UINT16_C( 1 )  /* [11] */
};

/*
 * The logical expressions table contains both the state
 * and the result function pointers for each defined logical
 * expression configured in the current BswM instance.
 */
/**
 * BswM_LogicalExprTable
 */
STATIC CONST( BswMLogicalExprType , AUTOMATIC ) BswM_LogicalExprTable[3] = 
{
  { /* [0] */
    &BswM_ExprState_BswMLogicalExpression_ECUM_STATE_RUN, /* GetState */
    &BswM_ExprResult_BswMLogicalExpression_ECUM_STATE_RUN  /* GetResult */
  },
  { /* [1] */
    &BswM_ExprState_BswMLogicalExpression_ECUM_STATE_PREP_SHUTDOWN, /* GetState */
    &BswM_ExprResult_BswMLogicalExpression_ECUM_STATE_PREP_SHUTDOWN  /* GetResult */
  },
  { /* [2] */
    &BswM_ExprState_BswMLogicalExpression_ECUM_STATE_SHUTDOWN, /* GetState */
    &BswM_ExprResult_BswMLogicalExpression_ECUM_STATE_SHUTDOWN  /* GetResult */
  }
};

/*
 * The action table contains function pointers to all configured
 * actions within the current BswM instance.
 */
/**
 * BswM_ActionTable
 */
STATIC CONST( BswMActionFuncPtrType , AUTOMATIC ) BswM_ActionTable[4] = 
{
  &BswM_Action_BswMAction_ComM_Allow_CAN, /* [0] */
  &BswM_Action_BswMAction_ComM_DoNotAllow_CAN, /* [1] */
  &BswM_Action_BswMAction_ComM_SwitchOn_CAN, /* [2] */
  &BswM_Action_BswMAction_ComM_SwitchOff_CAN  /* [3] */
};

#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/* !LINKSTO BswM.Impl.MemoryMapping.InstanceData,1 */
#define BSWM_START_SEC_VAR_INIT_UNSPECIFIED
#include <MemMap.h>

/* Dynamically Generated Mode Request Ports */

/**
 * BswMGenericRequestPortTable
 */
BswMGenericRequestPortType BswMGenericRequestPortTable[1] = 
{
  { /* [0] */
    { /* base */
      UINT16_C( 0 ), /* id */
      UINT8_C( 0 ), /* isImmediate */
      UINT8_C( 0 ), /* isDefined */
      UINT8_C( 0 )  /* hasInitValue */
    },
    UINT16_C( 0 ), /* channel */
    UINT16_C( 0 )  /* mode */
  }
};

#define BSWM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include <MemMap.h>

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include <MemMap.h>
/**
 * BswM_PtrModeRequestPortsTable
 */
STATIC CONST( BswMModeRequestPortType *, AUTOMATIC ) BswM_PtrModeRequestPortsTable[12] = 
{
  NULL_PTR, /* [0] */
  NULL_PTR, /* [1] */
  NULL_PTR, /* [2] */
  NULL_PTR, /* [3] */
  NULL_PTR, /* [4] */
  NULL_PTR, /* [5] */
  NULL_PTR, /* [6] */
  NULL_PTR, /* [7] */
  NULL_PTR, /* [8] */
  NULL_PTR, /* [9] */
  NULL_PTR, /* [10] */
  NULL_PTR  /* [11] */
};

#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/*==================[external data]=========================================*/

#define BSWM_START_SEC_VAR_INIT_UNSPECIFIED
#include <MemMap.h>
/**
 * BswM_LinkTimeContext
 */
STATIC BswM_LinkTimeContextType BswM_LinkTimeContext = 
{
  &BswM_ExprGetState, /* logicalExprGetStateFuncPtr */
  &BswM_ExprGetResult, /* logicalExprGetResultFuncPtr */
  &BswM_ExecuteAction, /* executeActionFuncPtr */
  &BswM_ExecuteModeArbitration, /* executeModeArbitrationFuncPtr */
  &BswMGenericRequestPortTable[0], /* genericRequestPortsTablePtr */
  UINT16_C( 1 ), /* numBswMGenericRequestPorts */
  UINT16_C( 3 )  /* numBswMExpressions */
};

/**
 * BswM_Context
 */
BswM_PartitionContextType BswM_Context = 
{
  UINT8_C( 0 ), /* ID */
  &SchM_Enter_BswM_SCHM_BSWM_EXCLUSIVE_AREA, /* SchMEnter */
  &SchM_Exit_BswM_SCHM_BSWM_EXCLUSIVE_AREA, /* SchMExit */
  { /* RunTimeContext */
    UINT8_C( 0 ), /* IsInitialized */
    { /* LogicalExprInitStatus */
      UINT8_C( 0 ), /* [0] */
      UINT8_C( 0 ), /* [1] */
      UINT8_C( 0 )  /* [2] */
    },
    { /* RuleResultTable */
      UINT8_C( 0 ), /* [0] */
      UINT8_C( 0 ), /* [1] */
      UINT8_C( 0 ), /* [2] */
      UINT8_C( 0 ), /* [3] */
      UINT8_C( 0 ), /* [4] */
      UINT8_C( 0 ), /* [5] */
      UINT8_C( 0 ), /* [6] */
      UINT8_C( 0 ), /* [7] */
      UINT8_C( 0 ), /* [8] */
      UINT8_C( 0 ), /* [9] */
      UINT8_C( 0 ), /* [10] */
      UINT8_C( 0 ), /* [11] */
      UINT8_C( 0 ), /* [12] */
      UINT8_C( 0 ), /* [13] */
      UINT8_C( 0 )  /* [14] */
    }
  },
  &BswM_LinkTimeContext  /* LinkTimeContext */
};

#define BSWM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include <MemMap.h>

/*==================[external function definitions]=========================*/

#define BSWM_START_SEC_CODE
#include <MemMap.h>

FUNC(void, BSWM_CODE) BswM_LT_Init(void)
{
  BswM_IndexType i,j;

  DBG_BSWM_LT_INIT_ENTRY();

  for (i = 0U; i < 12U; i++)
  {
    BswMModeRequestPortType* arrPtr = BswM_PtrModeRequestPortsTable[i];
    if ( arrPtr != NULL_PTR)
    {
      for (j = 0U; j < BswM_NumModeRequestPortsTable[i]; j++)
      {
        arrPtr[j].base.isDefined = arrPtr[j].base.hasInitValue;
      }
    }
  }

  for (i = 0U; i < BswM_NumModeRequestPortsTable[BSWM_GENERIC_REQUEST]; i++)
  {
    BswMGenericRequestPortTable[i].base.isDefined = BswMGenericRequestPortTable[i].base.hasInitValue;
  }

  DBG_BSWM_LT_INIT_EXIT();
}

/* Executable Entities for Rte and SchM callbacks. */

/*==================[internal function definitions]=========================*/

/* INDENT:OFF */
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_ECUM_STATE_RUN(void)
{
  /* Deviation MISRA-1 <START> */
  return
  (
    (BswMGenericRequestPortTable[0U].mode == ECUM_STATE_RUN)
  ) ? BSWM_TRUE : BSWM_FALSE;
  /* Deviation MISRA-1 <STOP> */
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_ECUM_STATE_PREP_SHUTDOWN(void)
{
  /* Deviation MISRA-1 <START> */
  return
  (
    (BswMGenericRequestPortTable[0U].mode == ECUM_STATE_PREP_SHUTDOWN)
  ) ? BSWM_TRUE : BSWM_FALSE;
  /* Deviation MISRA-1 <STOP> */
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_ECUM_STATE_SHUTDOWN(void)
{
  /* Deviation MISRA-1 <START> */
  return
  (
    (BswMGenericRequestPortTable[0U].mode == ECUM_STATE_SHUTDOWN)
  ) ? BSWM_TRUE : BSWM_FALSE;
  /* Deviation MISRA-1 <STOP> */
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_ECUM_STATE_RUN(void)
{
  /* Deviation MISRA-1 <START> */
  return
  (
    (TRUE == BswMGenericRequestPortTable[0U].base.isDefined)
  ) ? TRUE : FALSE;
  /* Deviation MISRA-1 <STOP> */
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_ECUM_STATE_PREP_SHUTDOWN(void)
{
  /* Deviation MISRA-1 <START> */
  return
  (
    (TRUE == BswMGenericRequestPortTable[0U].base.isDefined)
  ) ? TRUE : FALSE;
  /* Deviation MISRA-1 <STOP> */
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_ECUM_STATE_SHUTDOWN(void)
{
  /* Deviation MISRA-1 <START> */
  return
  (
    (TRUE == BswMGenericRequestPortTable[0U].base.isDefined)
  ) ? TRUE : FALSE;
  /* Deviation MISRA-1 <STOP> */
}


/* INDENT:ON */

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_BswMAction_ComM_Allow_CAN(void)
{
  DBG_BSWM_ACTION_BSWMACTION_COMM_ALLOW_CAN_ENTRY();
  ComM_CommunicationAllowed(0,TRUE);
  DBG_BSWM_ACTION_BSWMACTION_COMM_ALLOW_CAN_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_BswMAction_ComM_DoNotAllow_CAN(void)
{
  DBG_BSWM_ACTION_BSWMACTION_COMM_DONOTALLOW_CAN_ENTRY();
  ComM_CommunicationAllowed(0,FALSE);
  DBG_BSWM_ACTION_BSWMACTION_COMM_DONOTALLOW_CAN_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_BswMAction_ComM_SwitchOn_CAN(void)
{
  Std_ReturnType result;
  DBG_BSWM_ACTION_BSWMACTION_COMM_SWITCHON_CAN_ENTRY();
  result = ComM_RequestComMode( 0, COMM_FULL_COMMUNICATION );
  DBG_BSWM_ACTION_BSWMACTION_COMM_SWITCHON_CAN_EXIT(result);
  return result;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_BswMAction_ComM_SwitchOff_CAN(void)
{
  Std_ReturnType result;
  DBG_BSWM_ACTION_BSWMACTION_COMM_SWITCHOFF_CAN_ENTRY();
  result = ComM_RequestComMode( 0, COMM_NO_COMMUNICATION );
  DBG_BSWM_ACTION_BSWMACTION_COMM_SWITCHOFF_CAN_EXIT(result);
  return result;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprGetState(uint16 exprIndex)
{
  return BswM_LogicalExprTable[exprIndex].GetState();
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprGetResult(uint16 exprIndex)
{
  return BswM_LogicalExprTable[exprIndex].GetResult();
}

STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ExecuteAction(uint16 actionIndex)
{
  return BswM_ActionTable[actionIndex]();
}

STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ExecuteModeArbitration(uint8 source, uint32 channel, uint8 mode)
{
  BswM_PartitionContextType* inst = BswM_GetInstance();
  BswMModeRequestPortType* arrPtr;
  BswM_IndexType i;

  if (TRUE == inst->RunTimeContext.IsInitialized)
  {
    arrPtr = BswM_PtrModeRequestPortsTable[source];

    if ( arrPtr != NULL_PTR)
    {
      boolean hasActivatedActionLists = FALSE;
      boolean activatedActionLists[BSWM_MAX_NUM_ACTION_LISTS];
      TS_MemSet(activatedActionLists, 0x00U, BSWM_MAX_NUM_ACTION_LISTS );

      inst->SchMEnter();
      for (i= 0U; i < BswM_NumModeRequestPortsTable[source]; i++)
      {
        if (((source != BSWM_ECUM_WAKEUP_SOURCE) && (arrPtr[i].channel == channel)) || ((source == BSWM_ECUM_WAKEUP_SOURCE) && ((((uint32)1U << arrPtr[i].channel) & channel) != 0U)))
        {
          arrPtr[i].mode = mode;
          //hasActivatedActionLists |= BswM_PortUpdated(&(arrPtr[i].base), activatedActionLists, inst);
        }
      }
      inst->SchMExit();
      if (hasActivatedActionLists == TRUE)
      {
//        BswM_ExecuteModeControl(activatedActionLists, inst);
      }
    }
  }
  return E_OK;
}

#define BSWM_STOP_SEC_CODE
#include <MemMap.h>

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
