#if !defined(BSWM_COMM_H)
#define BSWM_COMM_H

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

#include <ComM.h>           /* ComM API                  */
#include <ComStack_Types.h> /* ComStack types            */

/*==================[macros]=================================================*/

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

#define BSWM_START_SEC_CODE
#include <MemMap.h>

/** \brief Indicates current communication mode of a ComM channel
 **        (Called by ComM)
 ** This function is called by ComM to indicate the current communication
 ** mode of a ComM channel.
 **
 ** Precondition: None
 **
 ** \param[in]     Network       - The ComM communication channel that the indicated
 **                                state corresponds to.
 **                RequestedMode - The current state of the ComM communication channel.
 ** \param[inout]  None.
 ** \param[out]    None.
 **
 ** \ServiceID{0x0E}
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous} */
extern FUNC(void, BSWM_CODE) BswM_ComM_CurrentMode
(
NetworkHandleType Network,
ComM_ModeType RequestedMode
);

/** \brief Indicates current mode of a PNC channel (called by ComM)
 ** This function is called by ComM to indicate the mode of a PNC channel
 **
 ** Precondition: None
 **
 ** \param[in]     PNC           - The ComM PNC that the indicated
 **                                state corresponds to.
 **                RequestedMode - The current state of the PNC.
 ** \param[inout]  None.
 ** \param[out]    None.
 **
 ** \ServiceID{0x0F}
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous} */

FUNC(void, BSWM_CODE) BswM_ComM_CurrentPNCMode
(
PNCHandleType PNC,
ComM_PncModeType RequestedMode
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
#endif /* !defined(BSWM_COMM_H) */
/*==================[end of file]============================================*/

/*==================[end of file]============================================*/
