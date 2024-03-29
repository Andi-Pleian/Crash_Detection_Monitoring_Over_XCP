#if !defined(BSWM_INT_CFG_H)
#define BSWM_INT_CFG_H

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

 /* \addtogroup Mode Management Stack
  * @{ */

/*==================[inclusions]============================================*/

/* !LINKSTO BswM0025,1, BswM0001,1, BswM0008,1 */
/* The BswM includes the the header files of all other BSW modules
 * which API functions it uses when the BSW module is enabled.
 */

//#include <Dcm.h>              /* DCM API                   */
#include <BswM_DCM.h>         /* Module public API         */

#include <BswM_EcuM.h>        /* EcuM related API          */
//#include <EcuM.h>             /* EcuM API                  */

#include <ComM.h>             /* ComM API                  */
#include <ComM_EcuMBswM.h>    /* ComM callbacks for BswM   */
#include <BswM_ComM.h>        /* BswM callbacks for ComM   */

#include <FrSM.h>             /* FrSM API                  */
#include <BswM_FrSM.h>        /* Module public API         */

#include <CanSM.h>            /* CanSM API                 */
#include <BswM_CanSM.h>       /* Module public API         */

#include <BswM_Types.h>

/* !LINKSTO BswM00954_Conf,1 */
//#include <EcuM_Cbk.h>
//#include <NvM_Api_Stc.h>

/*==================[macros]=================================================*/

#define BSWM_DEFERRED_ACTIONS_QUEUE_SIZE 0U

#define BSWM_GET_LOG_EXPR_INIT_STATUS(exprIndex) ((inst)->RunTimeContext.LogicalExprInitStatus[(exprIndex)])
#define BSWM_SET_LOG_EXPR_INIT_STATUS(exprIndex, value) ((inst)->RunTimeContext.LogicalExprInitStatus[(exprIndex)] = (value))

#define BSWM_GET_EXPR_STATE(exprIndex) ((inst)->LinkTimeContext->logicalExprGetStateFuncPtr((exprIndex)))

#define BSWM_GET_EXPR_RESULT(exprIndex) ((inst)->LinkTimeContext->logicalExprGetResultFuncPtr((exprIndex)))

#define BSWM_EXECUTE_ACTION(ActionIndex) ((inst)->LinkTimeContext->executeActionFuncPtr((ActionIndex)))

#define EXECUTE_MODE_ARBITRATION(source, channel, mode) ((void)inst->LinkTimeContext->executeModeArbitrationFuncPtr((source), (channel), (mode)))

/* All the values of the BswMModeRequestSourceType */
#define BSWM_CAN_SM_INDICATION 0U
#define BSWM_COMM_INDICATION 1U
#define BSWM_COMM_PNC_REQUEST 2U
#define BSWM_DCM_APPLICATION_UPDATED_INDICATION 3U
#define BSWM_DCM_COM_MODE_CURRENT_STATE 4U
#define BSWM_DCM_COM_MODE_REQUEST 5U
#define BSWM_DCM_RESET_MODE_REQUEST 6U
#define BSWM_DCM_SESSION_MODE_REQUEST 7U
#define BSWM_ECUM_INDICATION 8U
#define BSWM_ECUM_WAKEUP_SOURCE 9U
#define BSWM_FR_SM_INDICATION 10U
#define BSWM_GENERIC_REQUEST 11U

/*==================[type definitions]=======================================*/

typedef uint8 BswMModeRequestSourceType;

typedef P2FUNC(void, TYPEDEF, BswMExclusiveAreaFuncPtrType)(void);

/** \brief Function pointer type for a BswM action function. */
typedef P2FUNC(Std_ReturnType, TYPEDEF, BswMActionFuncPtrType)(void);

/** \brief may be assigned the values BSWM_TRUE, BSWM_FALSE or BSWM_UNDEFINED */
typedef uint8 BswMResultType;

/** \brief Function pointer type for a BswM logical expression function. */
typedef P2FUNC(BswMResultType, TYPEDEF, BswMExprResultFuncPtrType)(void);

/** \brief Function point type for access to the initialized state of a logical
 ** expression. */
typedef P2FUNC(boolean, TYPEDEF, BswMExprStateFuncPtrType)(void);

/** \brief Data structure type for a BswM logical expression */
typedef struct
{
  /* A pointer to a function which will return TRUE when the corresponding mode
   * request port and nested logical expressions are all initialized.
   * Otherwise, the function will return false. */
  BswMExprStateFuncPtrType GetState;
  /* A pointer to the function which will evaluate the expression. */
  BswMExprResultFuncPtrType GetResult;
} BswMLogicalExprType;

 /**
 * BswM_IndexType
 */
typedef uint16 BswM_IndexType;
/**
 * BswM_RunTimeContextType
 */
typedef struct 
{
  uint8 IsInitialized; /* IsInitialized */
  uint8 LogicalExprInitStatus[3]; /* LogicalExprInitStatus */
  VAR( BswMResultType , BSWM_VAR_NOINIT ) RuleResultTable[15]; /* RuleResultTable */
} BswM_RunTimeContextType;

/**
 * BswMBasicPortType
 */
typedef struct 
{
  uint16 id; /* id */
  uint8 isImmediate; /* isImmediate */
  uint8 isDefined; /* isDefined */
  uint8 hasInitValue; /* hasInitValue */
} BswMBasicPortType;

/**
 * BswMGenericRequestPortType
 */
typedef struct 
{
  BswMBasicPortType base; /* base */
  uint16 channel; /* channel */
  uint16 mode; /* mode */
} BswMGenericRequestPortType;

/**
 * BswM_LinkTimeContextType
 */
typedef struct 
{
  BswMResultType ( *logicalExprGetStateFuncPtr )( uint16 ); /* logicalExprGetStateFuncPtr */
  BswMResultType ( *logicalExprGetResultFuncPtr )( uint16 ); /* logicalExprGetResultFuncPtr */
  Std_ReturnType ( *executeActionFuncPtr )( uint16 ); /* executeActionFuncPtr */
  Std_ReturnType ( *executeModeArbitrationFuncPtr )( uint8, uint32, uint8 ); /* executeModeArbitrationFuncPtr */
  BswMGenericRequestPortType *genericRequestPortsTablePtr; /* genericRequestPortsTablePtr */
  uint16 numBswMGenericRequestPorts; /* numBswMGenericRequestPorts */
  uint16 numBswMExpressions; /* numBswMExpressions */
} BswM_LinkTimeContextType;

/**
 * BswM_PartitionContextType
 */
typedef struct 
{
  CONST( uint8, AUTOMATIC ) ID; /* ID */
  BswMExclusiveAreaFuncPtrType SchMEnter; /* SchMEnter */
  BswMExclusiveAreaFuncPtrType SchMExit; /* SchMExit */
  BswM_RunTimeContextType RunTimeContext; /* RunTimeContext */
  BswM_LinkTimeContextType *LinkTimeContext; /* LinkTimeContext */
} BswM_PartitionContextType;

/**
 * UInt8SymbolicValue
 */
typedef uint8 UInt8SymbolicValue;

/**
 * BswMModeRequestPortType
 */
typedef struct 
{
  BswMBasicPortType base; /* base */
  UInt8SymbolicValue channel; /* channel */
  uint8 mode; /* mode */
} BswMModeRequestPortType;

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function declarations]==========================*/

#define BSWM_START_SEC_CODE
#include <MemMap.h>

/*
 * This prototype is defined only for internal usage (not part of the public API).
 * The actual declaration will be provided by the Rte.
 */
extern FUNC(void, BSWM_CODE) BswM_MainFunction(void);

extern FUNC(P2VAR(BswM_PartitionContextType, BSWM_VAR, BSWM_APPL_DATA), BSWM_CODE) BswM_GetInstance(void);

#define BSWM_STOP_SEC_CODE
#include <MemMap.h>

/*==================[internal function declarations]==========================*/
/** @} doxygen end group definition */
#endif /* !defined(BSWM_INT_CFG_H) */
/*==================[end of file]============================================*/

