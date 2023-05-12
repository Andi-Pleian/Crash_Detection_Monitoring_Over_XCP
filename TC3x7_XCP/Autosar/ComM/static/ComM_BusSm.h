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
#if (!defined COMM_BUSSM_H)
#define COMM_BUSSM_H

/*==================[inclusions]============================================*/

#include <ComStack_Types.h> /* AUTOSAR standard types */
#include <ComM_Version.h>   /* ComM module version information */

/*==================[macros]================================================*/

#if (defined COMM_SID_BUS_SM_INDICATION)
#error COMM_SID_BUS_SM_INDICATION already defined
#endif
/** \brief AUTOSAR API service ID.
 **
 ** Definition of service ID for ComM_BusSM_ModeIndication(). */
#define COMM_SID_BUS_SM_INDICATION  51U

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

#define COMM_START_SEC_CODE
#include <MemMap.h>

/** \brief Indicate that BusSM has changed its communication mode.
 **
 ** This function provides an indication that the BusSM has changed
 ** its communication mode. The new mode is supplied as a parameter.
 **
 ** \param[in] Channel Network channel on which the mode transition
 **                    has occurred.
 ** \param[in] ComMode New communication mode of the BusSM.
 **
 ** \ServiceID{::COMM_SID_BUS_SM_INDICATION}
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Asynchronous} */
extern FUNC(void, COMM_CODE) ComM_BusSM_ModeIndication
(
    NetworkHandleType Channel,
    P2VAR(uint8, AUTOMATIC, COMM_APPL_DATA) ComMode
);

#define COMM_STOP_SEC_CODE
#include <MemMap.h>

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* if !defined( COMM_BUSSM_H ) */
/*==================[end of file]===========================================*/
