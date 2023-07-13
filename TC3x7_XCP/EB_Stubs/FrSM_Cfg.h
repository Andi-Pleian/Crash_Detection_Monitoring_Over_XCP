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

#ifndef FRSM_CFG_H
#define FRSM_CFG_H

/*==================[includes]==============================================*/

#include <Std_Types.h>
#include <TSAutosar.h>          /* TS_PROD_ERR_* defines */
#include <FrSM_Version.h>

/*==================[macros]================================================*/




/*------------------[Defensive programming]---------------------------------*/

#if (defined FRSM_DEFENSIVE_PROGRAMMING_ENABLED)
#error FRSM_DEFENSIVE_PROGRAMMING_ENABLED is already defined
#endif
/** \brief Defensive programming usage
 **
 ** En- or disables the usage of the defensive programming */
#define FRSM_DEFENSIVE_PROGRAMMING_ENABLED   STD_OFF

#if (defined FRSM_PRECONDITION_ASSERT_ENABLED)
#error FRSM_PRECONDITION_ASSERT_ENABLED is already defined
#endif
/** \brief Precondition assertion usage
 **
 ** En- or disables the usage of precondition assertion checks */
#define FRSM_PRECONDITION_ASSERT_ENABLED     STD_OFF

#if (defined FRSM_POSTCONDITION_ASSERT_ENABLED)
#error FRSM_POSTCONDITION_ASSERT_ENABLED is already defined
#endif
/** \brief Postcondition assertion usage
 **
 ** En- or disables the usage of postcondition assertion checks */
#define FRSM_POSTCONDITION_ASSERT_ENABLED    STD_OFF

#if (defined FRSM_UNREACHABLE_CODE_ASSERT_ENABLED)
#error FRSM_UNREACHABLE_CODE_ASSERT_ENABLED is already defined
#endif
/** \brief Unreachable code assertion usage
 **
 ** En- or disables the usage of unreachable code assertion checks */
#define FRSM_UNREACHABLE_CODE_ASSERT_ENABLED STD_OFF

#if (defined FRSM_INVARIANT_ASSERT_ENABLED)
#error FRSM_INVARIANT_ASSERT_ENABLED is already defined
#endif
/** \brief Invariant assertion usage
 **
 ** En- or disables the usage of invariant assertion checks */
#define FRSM_INVARIANT_ASSERT_ENABLED        STD_OFF

#if (defined FRSM_STATIC_ASSERT_ENABLED)
#error FRSM_STATIC_ASSERT_ENABLED is already defined
#endif
/** \brief Static assertion usage
 **
 ** En- or disables the usage of static assertion checks */
#define FRSM_STATIC_ASSERT_ENABLED           STD_OFF




/* standard SWS pre-compile time configuration parameters */

/** \brief Development error detection enable switch */
#define FRSM_DEV_ERROR_DETECT STD_ON

/** \brief Version info API enable switch */
#define FRSM_VERSION_INFO_API STD_OFF

/** \brief <Cdd>_SyncLossErrorIndication function enable switch */
#define FRSM_SYNC_LOSS_ERROR_INDICATION_ENABLE STD_OFF


/* vendor specific pre-compile time configuration parameters */

/** \brief EB-specific switch to disable usage of FlexRay transceiver driver */
#define FRSM_FRTRCV_CONTROL_ENABLE STD_OFF

/** \brief EB-specific switch to enable optimizations if a single FlexRay cluster is used */
#define FRSM_SINGLE_CLST_OPT_ENABLE STD_ON

/** \brief EB-specific switch to disable mode indications from FrSM to ComM */
#define FRSM_COMM_INDICATION_ENABLE STD_OFF

/** \brief EB-specific switch to disable mode indications from FrSM to BswM */
#define FRSM_REPORT_TO_BSMW_ENABLE STD_OFF

/** \brief EB-specific switch to disable API to set transceivers to passive/active mode */
#define FRSM_SETECUPASSIVE_ENABLE STD_OFF

/** \brief EB-specific switch to disable call of \a FrNm_StartupError() */
#define FRSM_FRNM_STARTUPERROR_ENABLE STD_OFF

/** \brief EB-specific switch to disable support for single slot mode */
#define FRSM_KEYSLOTONLYMODE_ENABLE STD_OFF


/** \brief Switch for DEM to DET reporting for production error FRSM_E_CLUSTER_STARTUP */
#define FRSM_PROD_ERR_HANDLING_CLUSTER_STARTUP   TS_PROD_ERR_DISABLE



/** \brief Switch for DEM to DET reporting for production error FRSM_E_CLUSTER_SYNC_LOSS */
#define FRSM_PROD_ERR_HANDLING_CLUSTER_SYNC_LOSS TS_PROD_ERR_DISABLE




#endif /* FRSM_CFG_H */

/*==================[end of file]===========================================*/
