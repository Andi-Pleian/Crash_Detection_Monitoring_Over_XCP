#if !defined(BSWM_LCFG_H)
#define BSWM_LCFG_H

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

/* !LINKSTO BswM.Impl.SourceFile.BswM_Partition_Lcfg_h,1 */
/*==================[inclusions]============================================*/

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[internal function declarations]========================*/

/*==================[external function declarations]========================*/

/*==================[internal constants]====================================*/

/*==================[external constants]====================================*/

/*==================[internal data]=========================================*/

/*==================[external data]=========================================*/

#define BSWM_START_SEC_VAR_INIT_UNSPECIFIED
#include <MemMap.h>

extern BswM_PartitionContextType BswM_Context;

#define BSWM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include <MemMap.h>

/*==================[external function definitions]=========================*/

#define BSWM_START_SEC_CODE
#include <MemMap.h>

extern FUNC(void, BSWM_CODE) BswM_LT_Init(void);

#define BSWM_STOP_SEC_CODE
#include <MemMap.h>

/*==================[internal function definitions]=========================*/
/** @} doxygen end group definition */
#endif /* !defined(BSWM_LCFG_H) */
/*==================[end of file]============================================*/

