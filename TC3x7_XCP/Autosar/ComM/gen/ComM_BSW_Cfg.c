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

/* !LINKSTO ComM503_Refine,1 */

/*==================[inclusions]============================================*/











/* prevent RTE symbols defined in ComM.h to be visible for ComM's .c files */
#if (defined COMM_INTERNAL_USAGE)
#error COMM_INTERNAL_USAGE already defined
#endif
#define COMM_INTERNAL_USAGE

#include <ComM_BSW.h>                   /* public API symbols */
#include <ComM_BSW_Cfg.h>               /* internal BSW config dependent header */

#if (COMM_CANSM_ACCESS_NEEDED == STD_ON)
#include <CanSM_ComM.h>                 /* Can state manager */
#endif

#if (COMM_FRSM_ACCESS_NEEDED == STD_ON)
#include <FrSm.h>                       /* Flexray state manager */
#endif

#if (COMM_LINSM_ACCESS_NEEDED == STD_ON)
#include <LinSM.h>                      /* Lin state manager */
#endif

/*==================[macros]================================================*/



/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[internal constants]====================================*/

#define COMM_START_SEC_CONST_8
#include <MemMap.h>


/*---------------[Partial Network Cluster (PNC)]-----------------*/





#define COMM_STOP_SEC_CONST_8
#include <MemMap.h>


/*==================[external constants]====================================*/

#define COMM_START_SEC_CONST_8
#include <MemMap.h>


CONST(NetworkHandleType, COMM_CONST)
  ComM_NmChannelOfChannel[COMM_NUM_CHANNELS] =
{
  0U,
  /* ComM channel ComMChannel_CAN, ID=1
   * not associated with NM channel, NM never used */
  0xFFU,
};




#define COMM_STOP_SEC_CONST_8
#include <MemMap.h>

#define COMM_START_SEC_CONST_16
#include <MemMap.h>

/* Main function period in ms for each channel */
CONST(uint16, COMM_CONST) ComM_MainFunctionPeriodMs[COMM_NUM_CHANNELS] =
{
  10U, /* for channel ComMChannel_FR */
  10U, /* for channel ComMChannel_CAN */
};

#if ((COMM_NM_VARIANT_LIGHT_NEEDED == STD_ON)      \
     || (COMM_NM_VARIANT_NONE_NEEDED == STD_ON))
/* Timeout after which state "NetReqNoNm" is left when ComMNmVariant='LIGHT' or
 * 'NONE' */
CONST(uint16, COMM_CONST) ComM_NetReqNoNmTimeoutMs[COMM_NUM_CHANNELS] =
{
  /* for channel ComMChannel_FR */
  0xFFU, /* channel with real bus NM support, value never used */
  /* for channel ComMChannel_CAN */
  500U, /* Nm variant 'LIGHT' or 'NONE' */
};
#endif

#if (COMM_NM_VARIANT_LIGHT_NEEDED == STD_ON)
/* Timeout after which state "ready sleep" is left in ComMNmVariant=LIGHT */
CONST(uint16, COMM_CONST) ComM_ReadySleepNoNmTimeoutMs[COMM_NUM_CHANNELS] =
{
  /* for channel ComMChannel_FR */
  0xFFU, /* channel with real bus NM support, value never used */
  /* for channel ComMChannel_CAN */
  0U,    /* Nm variant NONE, "ready sleep" state is instantly left */
};
#endif


#define COMM_STOP_SEC_CONST_16
#include <MemMap.h>

#define COMM_START_SEC_CONST_UNSPECIFIED
#include <MemMap.h>





#define COMM_STOP_SEC_CONST_UNSPECIFIED
#include <MemMap.h>


/*==================[internal data]=========================================*/

/*==================[external data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/
