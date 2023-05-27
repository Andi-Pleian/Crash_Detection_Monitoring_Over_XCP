#if !defined(BSWM_CFG_H)
#define BSWM_CFG_H

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

/* !LINKSTO BswM.Impl.SourceFile.BswM_Cfg_h,1 */

/*==================[inclusions]============================================*/

#include <TSAutosar.h>        /* EB specific standard types*/
#include <Std_Types.h>        /* AUTOSAR standard types    */

#include <BswM_CfgTypes.h>

/*==================[type definitions]=======================================*/

/*==================[macros]=================================================*/

/* !LINKSTO BswM.Impl.BswMInstanceId,2 */
#if (defined BSWM_INSTANCE_ID)
#error BSWM_INSTANCE_ID already defined
#endif
/** \brief BswM Instance ID
 **
 ** Instance ID of the only BswM instance.
 */
#define BSWM_INSTANCE_ID 0U

#define BSWM_DEV_ERROR_DETECT STD_OFF
#define BSWM_VERSION_INFO_API STD_ON

#define BSWM_CANSM_API_ENABLED STD_ON
#define BSWM_COMM_API_ENABLED STD_ON
#define BSWM_DCM_API_ENABLED STD_ON
#define BSWM_ECUM_API_ENABLED STD_ON
#define BSWM_ETHIF_API_ENABLED STD_OFF
#define BSWM_ETHSM_API_ENABLED STD_OFF
#define BSWM_FRSM_API_ENABLED STD_ON
#define BSWM_GENERIC_REQUEST_API_ENABLED STD_ON
#define BSWM_LINSM_API_ENABLED STD_OFF
#define BSWM_LINTP_API_ENABLED STD_OFF
#define BSWM_NVM_API_ENABLED STD_OFF
#define BSWM_SD_API_ENABLED STD_OFF
#define BSWM_WDGM_API_ENABLED STD_OFF

#define BSWM_DCM_LEGACY_API_ENABLED STD_ON

#define BSWM_IPDU_GROUP_VECTOR_SIZE 1U

#define BSWM_RTE_ENABLED STD_OFF
#define BSWM_DEM_ENABLED STD_OFF

/* Switches related to actions */
#define BSWM_COM_ACTION_USED STD_OFF
#define BSWM_NM_ACTION_USED STD_OFF

#define BSWM_DEADLINE_MONITORING_CONTROL_ACTION_USED STD_OFF
#define BSWM_PDU_GROUP_SWITCH_ACTION_USED STD_OFF
#define BSWM_SWITCH_IPDU_MODE_ACTION_USED STD_OFF
#define BSWM_TRIGGER_IPDU_SEND_ACTION_USED STD_OFF
#define BSWM_PDU_ROUTER_CONTROL_ACTION_USED STD_OFF
#define BSWM_LIN_SCHEDULE_SWITCH_ACTION_USED STD_OFF

#if (defined BSWM_MAX_NUM_ACTION_LISTS)
#error BSWM_MAX_NUM_ACTION_LISTS is already defined
#endif
/** \brief The max number of action lists supported by this configuration. */
#define BSWM_MAX_NUM_ACTION_LISTS 15U

#if (defined BSWM_MAX_NUM_RULES)
#error BSWM_MAX_NUM_RULES is already defined
#endif
/** \brief The max number of rules supported by this configuration. */
#define BSWM_MAX_NUM_RULES 15U

#if (defined BSWM_RELOCATABLE_CFG_ENABLE)
#error BSWM_RELOCATABLE_CFG_ENABLE is already defined
#endif
/** \brief Determines if the post-build configuration is relocatable in memory. */
#define BSWM_RELOCATABLE_CFG_ENABLE STD_ON

#if (defined BSWM_PBCFGM_SUPPORT_ENABLED)
#error BSWM_PBCFGM_SUPPORT_ENABLED is already defined
#endif
/* !LINKSTO      BswM.Impl.PbCfgM,1 */
/* The PbcfgM support is only enabled only when the PbcfgM references the BswM. */
#define BSWM_PBCFGM_SUPPORT_ENABLED STD_OFF

/** \brief PreCompile time verification value */
#define BSWM_CFG_SIGNATURE 2196035756U

/** \brief PreCompile time Published information verification value */
#define BSWM_PUBLIC_INFO_SIGNATURE 3527585516U

#define BSWM_LINIF_SCHEDULE_RANGE_CHECK \
      (BSWM_FALSE)

/*------------------[Defensive programming]---------------------------------*/

#if (defined BSWM_DEFENSIVE_PROGRAMMING_ENABLED)
#error BSWM_DEFENSIVE_PROGRAMMING_ENABLED is already defined
#endif
/** \brief Defensive programming usage
 **
 ** En- or disables the usage of the defensive programming */
#define BSWM_DEFENSIVE_PROGRAMMING_ENABLED STD_OFF

#if (defined BSWM_PRECONDITION_ASSERT_ENABLED)
#error BSWM_PRECONDITION_ASSERT_ENABLED is already defined
#endif
/** \brief Precondition assertion usage
 **
 ** En- or disables the usage of precondition assertion checks */
#define BSWM_PRECONDITION_ASSERT_ENABLED STD_OFF

#if (defined BSWM_POSTCONDITION_ASSERT_ENABLED)
#error BSWM_POSTCONDITION_ASSERT_ENABLED is already defined
#endif
/** \brief Postcondition assertion usage
 **
 ** En- or disables the usage of postcondition assertion checks */
#define BSWM_POSTCONDITION_ASSERT_ENABLED STD_OFF

#if (defined BSWM_UNREACHABLE_CODE_ASSERT_ENABLED)
#error BSWM_UNREACHABLE_CODE_ASSERT_ENABLED is already defined
#endif
/** \brief Unreachable code assertion usage
 **
 ** En- or disables the usage of unreachable code assertion checks */
#define BSWM_UNREACHABLE_CODE_ASSERT_ENABLED STD_OFF

#if (defined BSWM_INVARIANT_ASSERT_ENABLED)
#error BSWM_INVARIANT_ASSERT_ENABLED is already defined
#endif
/** \brief Invariant assertion usage
 **
 ** En- or disables the usage of invariant assertion checks */
#define BSWM_INVARIANT_ASSERT_ENABLED STD_OFF

#if (defined BSWM_STATIC_ASSERT_ENABLED)
#error BSWM_STATIC_ASSERT_ENABLED is already defined
#endif
/** \brief Static assertion usage
 **
 ** En- or disables the usage of static assertion checks */
#define BSWM_STATIC_ASSERT_ENABLED STD_OFF

/** \brief The configured implementation variant */
#define BSWM_IMPLEMENTATION_CONFIG_VARIANT BSWM_VARIANT_PRE_COMPILE

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/
/** @} doxygen end group definition */
#endif /* !defined(BSWM_CFG_H) */
/*==================[end of file]============================================*/

