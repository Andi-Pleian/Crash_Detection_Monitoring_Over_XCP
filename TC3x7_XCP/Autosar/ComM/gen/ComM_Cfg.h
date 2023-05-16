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
/* !LINKSTO ComM456,1 */
#if (!defined COMM_CFG_H)
#define COMM_CFG_H

/*
 * MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 8.5 (required)
 * An external object or function shall be declared in one and only one file.
 *
 * Reason:
 * The files SchM_ComM.h and ComM_Cfg.h contain declarations of ComM_MainFunction_x. This
 * is due to the issue reported in http://www.autosar.org/bugzilla/show_bug.cgi?id=53853
 * and should be fixed in a future version of the Rte.
 */

/*==================[includes]==============================================*/

/* !LINKSTO ComM466,1 */


/*==================[macros]================================================*/
/* *** General feature flags *** */

/* !LINKSTO ComM.PB.Impl.Hash,1 */
#if (defined COMM_CFG_SIGNATURE)
#error COMM_CFG_SIGNATURE already defined
#endif
#define COMM_CFG_SIGNATURE 2018520538U /* Compile time verification value */

#if (defined COMM_PUBLIC_INFO_SIGNATURE)
#error COMM_PUBLIC_INFO_SIGNATURE already defined
#endif
#define COMM_PUBLIC_INFO_SIGNATURE 1761272751U /* PublicInfoSignature */

#if (defined COMM_PBCFGM_SUPPORT_ENABLED)
#error COMM_PBCFGM_SUPPORT_ENABLED already defined
#endif
#define COMM_PBCFGM_SUPPORT_ENABLED STD_OFF

/* ----- Pre-processor switch to enable/diable relocateable postbuild config ----- */
/* !LINKSTO ComM.PB.Impl.Relocatable,1 */
#if (defined COMM_RELOCATABLE_CFG_ENABLE)
#error COMM_RELOCATABLE_CFG_ENABLE already defined
#endif
#if (COMM_PBCFGM_SUPPORT_ENABLED == STD_ON)
#define COMM_RELOCATABLE_CFG_ENABLE STD_OFF
#else
#define COMM_RELOCATABLE_CFG_ENABLE STD_ON
#endif

#if (defined COMM_SERVICE_API_NONE)
#error COMM_SERVICE_API_NONE already defined
#endif
/** \brief Definition that no default service API is set **/
#define COMM_SERVICE_API_NONE   0U

#if (defined COMM_SERVICE_API_ASR32)
#error COMM_SERVICE_API_ASR32 already defined
#endif
/** \brief Definition that AUTOSAR 3.2 service API is set as default **/
#define COMM_SERVICE_API_ASR32 32U

#if (defined COMM_SERVICE_API_ASR40)
#error COMM_SERVICE_API_ASR40 already defined
#endif
/** \brief Definition that AUTOSAR 4.0 service API is set as default **/
#define COMM_SERVICE_API_ASR40 40U

#if (defined COMM_ENABLE_ASR32_SERVICE_API)
#error COMM_ENABLE_ASR32_SERVICE_API already defined
#endif
/** \brief Definition whether AUTOSAR 3.2 service API for ComM is enabled **/
#define COMM_ENABLE_ASR32_SERVICE_API                   STD_OFF

#if (defined COMM_ENABLE_ASR40_SERVICE_API)
#error COMM_ENABLE_ASR40_SERVICE_API already defined
#endif
/** \brief Definition whether AUTOSAR 4.0 service API for ComM is enabled **/
#define COMM_ENABLE_ASR40_SERVICE_API                   STD_ON

#if (defined COMM_DEFAULT_ASR_SERVICE_API)
#error COMM_DEFAULT_ASR_SERVICE_API already defined
#endif
/** \brief Definition of default service API **/
#define COMM_DEFAULT_ASR_SERVICE_API                    COMM_SERVICE_API_ASR40



#if (defined ComMConf_ComMChannel_ComMChannel_CAN)
#error ComMConf_ComMChannel_ComMChannel_CAN already defined
#endif
/** \brief Symbolic name for the ComM channel "ComMChannel_CAN" */
#define ComMConf_ComMChannel_ComMChannel_CAN   0U

#if (!defined COMM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined ComMChannel_CAN)
#error ComMChannel_CAN already defined
#endif

/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) 0 */
#define ComMChannel_CAN                     0U

#if (defined ComM_ComMChannel_CAN)
#error ComM_ComMChannel_CAN already defined
#endif

/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define ComM_ComMChannel_CAN   0U
#endif /* COMM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */




#if (defined ComMConf_ComMUser_ComMUser_CanUser)
#error ComMConf_ComMUser_ComMUser_CanUser already defined
#endif

/** \brief Symbolic name for the ComM user "ComMUser_CanUser" */
#define ComMConf_ComMUser_ComMUser_CanUser   0U

#if (!defined COMM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined ComMUser_CanUser)
#error ComMUser_CanUser already defined
#endif

/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) 0 */
#define ComMUser_CanUser                     0U

#if (defined ComM_ComMUser_CanUser)
#error ComM_ComMUser_CanUser already defined
#endif

/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define ComM_ComMUser_CanUser   0U
#endif /* COMM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */



/** \brief Enable/disable development error detection */
#if (defined COMM_DEV_ERROR_DETECT)
#error COMM_DEV_ERROR_DETECT already defined
#endif
#define COMM_DEV_ERROR_DETECT             STD_ON

/** \brief Enable/disable the version info API */
#if (defined COMM_VERSION_INFO_API)
#error COMM_VERSION_INFO_API already defined
#endif
#define COMM_VERSION_INFO_API             STD_OFF

/** \brief Minimum time duration in ms, spent in the Full Communication
 * Mode */
#if (defined COMM_T_MIN_FULL_COM_MODE_DURATION)
#error COMM_T_MIN_FULL_COM_MODE_DURATION already defined
#endif
#define COMM_T_MIN_FULL_COM_MODE_DURATION 5000U

/** \brief Check if Rte is used in ComM */
#if (defined COMM_INCLUDE_RTE)
#error COMM_INCLUDE_RTE already defined
#endif
#define COMM_INCLUDE_RTE                  STD_OFF

/** \brief Check if Dcm usage is enabled in ComM */
#if (defined COMM_DCM_ENABLED)
#error COMM_DCM_ENABLED already defined
#endif
#define COMM_DCM_ENABLED                  STD_ON

/** \brief Wake up of one channel shall lead to a wake up of all channels if
 * switch is enabled. */
#if (defined COMM_SYNCHRONOUS_WAKE_UP)
#error COMM_SYNCHRONOUS_WAKE_UP already defined
#endif
#define COMM_SYNCHRONOUS_WAKE_UP          STD_ON

/** \brief mode limitation functionality for channel shall lead to limit mode changing if
 * switch is enabled. **/
#if (defined COMM_MODE_LIMITATION_ENABLED)
#error COMM_MODE_LIMITATION_ENABLED already defined
#endif
#define COMM_MODE_LIMITATION_ENABLED      STD_OFF

/** \brief mode inhibition affects the ECU or not. **/
#if (defined COMM_ECU_GROUP_CLASSIFICATION)
#error COMM_ECU_GROUP_CLASSIFICATION already defined
#endif
#define COMM_ECU_GROUP_CLASSIFICATION     3U

/** \brief wakeup inhibition functionality for channel shall limit wakeup if
 * switch is enabled. **/
#if (defined COMM_WAKEUP_INHIBITION_ENABLED)
#error COMM_WAKEUP_INHIBITION_ENABLED already defined
#endif
#define COMM_WAKEUP_INHIBITION_ENABLED    STD_OFF

/** \brief signal if the port interface ComM_CurrentChannelRequest is used */
#if (defined COMM_CURRENTCHANNELREQUEST_ENABLED)
#error COMM_CURRENTCHANNELREQUEST_ENABLED already defined
#endif
#define COMM_CURRENTCHANNELREQUEST_ENABLED  STD_OFF



/** \brief Enable/Disable NvM support */
#if (defined COMM_NVM_ENABLED)
#error COMM_NVM_ENABLED already defined
#endif
#define COMM_NVM_ENABLED                  STD_OFF



/** \brief Number of ComM communication channels */
#if (defined COMM_NUM_CHANNELS)
#error COMM_NUM_CHANNELS already defined
#endif
#define COMM_NUM_CHANNELS                 1U

/** \brief Number of ComM users */
#if (defined COMM_NUM_USERS)
#error COMM_NUM_USERS already defined
#endif
#define COMM_NUM_USERS                    1U

#if (defined USER_ARRAY_SIZE)
#error USER_ARRAY_SIZE already defined
#endif
#if (COMM_NUM_USERS == 0U)
#define USER_ARRAY_SIZE 1U
#else
#define USER_ARRAY_SIZE COMM_NUM_USERS
#endif

/** \brief Flag indicating if Nm access is needed at all.
 *
 * ComM does not need to call Nm if no ComM channel is configured to used
 * either Nm variant PASSIVE or FULL. */
#if (defined COMM_NM_ACCESS_NEEDED)
#error COMM_NM_ACCESS_NEEDED already defined
#endif
#define COMM_NM_ACCESS_NEEDED             STD_OFF

/** \brief Flag indicating if CanSm access is needed at all. */
#if (defined COMM_CANSM_ACCESS_NEEDED)
#error COMM_CANSM_ACCESS_NEEDED already defined
#endif
#define COMM_CANSM_ACCESS_NEEDED          STD_ON

/** \brief Flag indicating if FrSm access is needed at all. */
#if (defined COMM_FRSM_ACCESS_NEEDED)
#error COMM_FRSM_ACCESS_NEEDED already defined
#endif
#define COMM_FRSM_ACCESS_NEEDED           STD_OFF

/** \brief Flag indicating if LinSm access is needed at all. */
#if (defined COMM_LINSM_ACCESS_NEEDED)
#error COMM_LINSM_ACCESS_NEEDED already defined
#endif
#define COMM_LINSM_ACCESS_NEEDED          STD_OFF

/** \brief Flag indicating if EthSm access is needed at all. */
#if (defined COMM_ETHSM_ACCESS_NEEDED)
#error COMM_ETHSM_ACCESS_NEEDED already defined
#endif
#define COMM_ETHSM_ACCESS_NEEDED          STD_OFF

/** \brief Flag indicating if there is at least one channel of variant
 * "full" */
#if (defined COMM_NM_VARIANT_FULL_NEEDED)
#error COMM_NM_VARIANT_FULL_NEEDED already defined
#endif
#define COMM_NM_VARIANT_FULL_NEEDED       STD_OFF

/** \brief Flag indicating if there is at least one channel of variant
 * "passive" */
#if (defined COMM_NM_VARIANT_PASSIVE_NEEDED)
#error COMM_NM_VARIANT_PASSIVE_NEEDED already defined
#endif
#define COMM_NM_VARIANT_PASSIVE_NEEDED    STD_OFF

/** \brief Flag indicating if there is at least one channel of variant
 * "light" */
#if (defined COMM_NM_VARIANT_LIGHT_NEEDED)
#error COMM_NM_VARIANT_LIGHT_NEEDED already defined
#endif
#define COMM_NM_VARIANT_LIGHT_NEEDED      STD_OFF

/** \brief Flag indicating if there is at least one channel of variant
 * "none" */
#if (defined COMM_NM_VARIANT_NONE_NEEDED)
#error COMM_NM_VARIANT_NONE_NEEDED already defined
#endif
#define COMM_NM_VARIANT_NONE_NEEDED       STD_ON

/** \brief Flag indicating if only channels of variant "full" are
 * configured */
#if (defined COMM_NM_VARIANT_FULL_ONLY)
#error COMM_NM_VARIANT_FULL_ONLY already defined
#endif
#define COMM_NM_VARIANT_FULL_ONLY         STD_OFF

/** \brief Flag indicating if only channels of variant "light" ore "none" are
 * configured */
#if (defined COMM_NM_VARIANT_LIGHT_NONE_ONLY)
#error COMM_NM_VARIANT_LIGHT_NONE_ONLY already defined
#endif
#define COMM_NM_VARIANT_LIGHT_NONE_ONLY   STD_ON

/** \brief Flag indicating if there is at least one channel of bustype
 * "internal" */
#if (defined COMM_BUSTYPE_INTERNAL_NEEDED)
#error COMM_BUSTYPE_INTERNAL_NEEDED already defined
#endif
#define COMM_BUSTYPE_INTERNAL_NEEDED      STD_OFF

/** \brief Flag indicating if only channels of bustype "internal" are configured */
#if (defined COMM_BUSTYPE_INTERNAL_ONLY)
#error COMM_BUSTYPE_INTERNAL_ONLY already defined
#endif
#define COMM_BUSTYPE_INTERNAL_ONLY   STD_OFF

/** \brief NM channel connected to the ComM channel */
#if (defined COMM_NM_CHANNEL_OF_CHANNEL)
#error COMM_NM_CHANNEL_OF_CHANNEL already defined
#endif
#define COMM_NM_CHANNEL_OF_CHANNEL(idx)   0xFFU /* no NM channel associated */

/* !LINKSTO HisComM0001_Refine1,1, HisComM0002_Refine1,1, HisComM0003_Refine1,1 */
/** \brief Bus type of ComM channel */
#if (defined COMM_BUSTYPE_OF_CHANNEL)
#error COMM_BUSTYPE_OF_CHANNEL already defined
#endif
#define COMM_BUSTYPE_OF_CHANNEL(idx)      COMM_BUS_TYPE_CAN

#if (defined COMM_BUSTYPE_OF_CHANNEL_DYNAMIC)
#error COMM_BUSTYPE_OF_CHANNEL_DYNAMIC already defined
#endif
#define COMM_BUSTYPE_OF_CHANNEL_DYNAMIC   STD_OFF

/** \brief Nm variant of ComM channel */
/* !LINKSTO HisComM0001_Refine1,1, HisComM0002_Refine1,1, HisComM0003_Refine1,1 */
#if (defined COMM_NM_VARIANT_OF_CHANNEL)
#error COMM_NM_VARIANT_OF_CHANNEL already defined
#endif
#define COMM_NM_VARIANT_OF_CHANNEL(idx)    COMM_NM_NONE_VARIANT
#if (defined COMM_NM_VARIANT_OF_CHANNEL_DYNAMIC)
#error COMM_NM_VARIANT_OF_CHANNEL_DYNAMIC already defined
#endif
#define COMM_NM_VARIANT_OF_CHANNEL_DYNAMIC STD_OFF


#if (defined COMM_PNC_RELEASE_CHANNEL)
#error COMM_PNC_RELEASE_CHANNEL already defined
#endif
#define COMM_PNC_RELEASE_CHANNEL    COMM_NO_INTERNAL_AND_EXTERNAL_REQUESTS


/*------------------[Pnc configuration]-------------------------------------*/
/** \brief General Support for Partial network cluster (Pnc) */
#if (defined COMM_PNC_SUPPORT)
#error COMM_PNC_SUPPORT already defined
#endif
#define COMM_PNC_SUPPORT                  STD_OFF

#if (defined COMM_PNC_GW_ENABLED)
#error COMM_PNC_GW_ENABLED already defined
#endif
/** \brief Support for Partial network cluster gateway */
#define COMM_PNC_GW_ENABLED               STD_OFF


/** \brief Number of Partial network cluster (Pnc) */
#if (defined COMM_NUM_PNC)
#error COMM_NUM_PNC already defined
#endif
#define COMM_NUM_PNC                      0U




/** \brief Number of unique Rx EIRA Signals */
#if (defined COMM_NUM_RX_EIRA_SIGNALS)
#error COMM_NUM_RX_EIRA_SIGNALS already defined
#endif
#define COMM_NUM_RX_EIRA_SIGNALS      0U

#if(COMM_PNC_GW_ENABLED == STD_ON)
/** \brief Number of unique Rx ERA Signals */
#if (defined COMM_NUM_RX_ERA_SIGNALS)
#error COMM_NUM_RX_ERA_SIGNALS already defined
#endif
#define COMM_NUM_RX_ERA_SIGNALS      0U
#endif

/** \brief Number of unique Tx EIRA Signals */
#if (defined COMM_NUM_TX_SIGNALS)
#error COMM_NUM_TX_SIGNALS already defined
#endif
#define COMM_NUM_TX_SIGNALS      0U



/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/* hide declaration in own header if included by ComM itself and RTE is
 * enabled */
#if ((!defined(COMM_INTERNAL_USAGE)) || (COMM_INCLUDE_RTE == STD_OFF))

#define COMM_START_SEC_CODE
#include <MemMap.h>

/* If Rte usage is enabled in the ComM configuration the declaration of these
 * functions are provided by Rte_ComM.h. */

/** \brief Main function for channel 0 */
/* Deviation MISRAC2012-1 */
extern FUNC(void, COMM_CODE) ComM_MainFunction_0(void);

#define COMM_STOP_SEC_CODE
#include <MemMap.h>

#endif

#if (COMM_PNC_SUPPORT == STD_ON)

#define COMM_START_SEC_CODE
#include <MemMap.h>

/** \brief COM Callback function indicates reception of an RX-EIRA
 **
 ** This function is called from the COM module in case the PDU including the
 ** eira signal is received.
 **
 ** \note called in interrupt context */


#if(COMM_PNC_GW_ENABLED == STD_ON)
/** \brief COM Callback function indicates reception of an RX-ERA
 **
 ** This function is called from the COM module in case the PDU including the
 ** eira signal is received.
 **
 ** \note called in interrupt context */

#endif

#define COMM_STOP_SEC_CODE
#include <MemMap.h>

#endif

/*==================[external constants]====================================*/

/*==================[external data]=========================================*/

#endif /* if !defined( COMM_CFG_H ) */
