#if !defined(BSWM_FRSM_H)
#define BSWM_FRSM_H

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

/*==================[includes]===============================================*/

#include <FrSM.h>

/*==================[macros]=================================================*/

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

#define BSWM_START_SEC_CODE
#include <MemMap.h>

/** \brief Indicates current state (Called by FrSM).
 **
 ** This function is called by FrSM to indicate its current state.
 **
 ** Precondition: None
 **
 ** \param[in]    Network      - The FlexRay cluster that the indicated state
 **                              corresponds to.
 **               CurrentState - The current state of the FlexRay cluster.
 ** \param[inout] None.
 ** \param[out]   None.
 **
 ** \ServiceID{0x0C}
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous} */

extern FUNC(void, BSWM_CODE) BswM_FrSM_CurrentState
(
NetworkHandleType Network,
FrSM_BswM_StateType CurrentState
);

#define BSWM_STOP_SEC_CODE
#include <MemMap.h>

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

/** @} doxygen end group definition */
#endif /* !defined(BSWM_FRSM_H) */
/*==================[end of file]============================================*/

/*==================[end of file]============================================*/
