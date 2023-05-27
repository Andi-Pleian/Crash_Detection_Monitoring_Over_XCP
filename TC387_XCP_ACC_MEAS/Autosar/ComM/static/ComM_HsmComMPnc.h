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

#ifndef COMM_HSMCOMMPNC_H
#define COMM_HSMCOMMPNC_H

/* Public interface for the ComMPnc
 * state machine.
 *
 * This file defines the public symbols and functions to use the
 * ComMPnc state machine.
 */

/*==================[inclusions]============================================*/

/* include state machine driver interface */
#include <ComM_Hsm.h>

/*==================[macros]================================================*/

/* Events/signal defined in the ComMPnc state machine. */
#if (defined COMM_HSM_COMMPNC_EV_PREPARE_SLEEP_TIMEOUT)
#error COMM_HSM_COMMPNC_EV_PREPARE_SLEEP_TIMEOUT already defined
#endif
#define COMM_HSM_COMMPNC_EV_PREPARE_SLEEP_TIMEOUT 0U

#if (defined COMM_HSM_COMMPNC_EV_NO_COM_REQ_BY_ALL_COMM_USER)
#error COMM_HSM_COMMPNC_EV_NO_COM_REQ_BY_ALL_COMM_USER already defined
#endif
#define COMM_HSM_COMMPNC_EV_NO_COM_REQ_BY_ALL_COMM_USER 1U

#if (defined COMM_HSM_COMMPNC_EV_COMCBK)
#error COMM_HSM_COMMPNC_EV_COMCBK already defined
#endif
#define COMM_HSM_COMMPNC_EV_COMCBK 2U

#if (defined COMM_HSM_COMMPNC_EV_ECUM_PNCWAKEUP_IND)
#error COMM_HSM_COMMPNC_EV_ECUM_PNCWAKEUP_IND already defined
#endif
#define COMM_HSM_COMMPNC_EV_ECUM_PNCWAKEUP_IND 3U

#if (defined COMM_HSM_COMMPNC_EV_ECUM_WAKEUP_IND)
#error COMM_HSM_COMMPNC_EV_ECUM_WAKEUP_IND already defined
#endif
#define COMM_HSM_COMMPNC_EV_ECUM_WAKEUP_IND 4U

#if (defined COMM_HSM_COMMPNC_EV_FULL_COM_REQ_BY_COMM_USER)
#error COMM_HSM_COMMPNC_EV_FULL_COM_REQ_BY_COMM_USER already defined
#endif
#define COMM_HSM_COMMPNC_EV_FULL_COM_REQ_BY_COMM_USER 5U

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

#define COMM_START_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/** \brief Initialization data for the statechart statechart ComMPnc */
extern CONST(ComM_HsmStatechartType, COMM_CONST)
 ComM_HsmScComMPnc;

#define COMM_STOP_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* defined COMM_HSMCOMMPNC_H */
/*==================[end of file]===========================================*/
