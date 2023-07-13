/**
 * \file
 *
 * \brief AUTOSAR FrNm
 *
 * This file contains the implementation of the AUTOSAR
 * module FrNm.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2017 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
/* !LINKSTO FRNM369,1 */

/*
 * MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 8.5 (required)
 * An external object or function shall be declared in one and only one file.
 *
 * Reason:
 * The files SchM_FrNm.h and FrNm.h contain declarations of FrNm_MainFunction. This should be fixed
 * in a future version of the Rte.
 */















#if (!defined FRNM_CFG_H)
#define FRNM_CFG_H

/*------------------[Defensive programming]---------------------------------*/

#if (defined FRNM_DEFENSIVE_PROGRAMMING_ENABLED)
#error FRNM_DEFENSIVE_PROGRAMMING_ENABLED is already defined
#endif
/** \brief Defensive programming usage
 **
 ** En- or disables the usage of the defensive programming */
#define FRNM_DEFENSIVE_PROGRAMMING_ENABLED   STD_OFF

#if (defined FRNM_PRECONDITION_ASSERT_ENABLED)
#error FRNM_PRECONDITION_ASSERT_ENABLED is already defined
#endif
/** \brief Precondition assertion usage
 **
 ** En- or disables the usage of precondition assertion checks */
#define FRNM_PRECONDITION_ASSERT_ENABLED     STD_OFF

#if (defined FRNM_POSTCONDITION_ASSERT_ENABLED)
#error FRNM_POSTCONDITION_ASSERT_ENABLED is already defined
#endif
/** \brief Postcondition assertion usage
 **
 ** En- or disables the usage of postcondition assertion checks */
#define FRNM_POSTCONDITION_ASSERT_ENABLED    STD_OFF

#if (defined FRNM_UNREACHABLE_CODE_ASSERT_ENABLED)
#error FRNM_UNREACHABLE_CODE_ASSERT_ENABLED is already defined
#endif
/** \brief Unreachable code assertion usage
 **
 ** En- or disables the usage of unreachable code assertion checks */
#define FRNM_UNREACHABLE_CODE_ASSERT_ENABLED STD_OFF

#if (defined FRNM_INVARIANT_ASSERT_ENABLED)
#error FRNM_INVARIANT_ASSERT_ENABLED is already defined
#endif
/** \brief Invariant assertion usage
 **
 ** En- or disables the usage of invariant assertion checks */
#define FRNM_INVARIANT_ASSERT_ENABLED        STD_OFF

#if (defined FRNM_STATIC_ASSERT_ENABLED)
#error FRNM_STATIC_ASSERT_ENABLED is already defined
#endif
/** \brief Static assertion usage
 **
 ** En- or disables the usage of static assertion checks */
#define FRNM_STATIC_ASSERT_ENABLED           STD_OFF


/*==================[includes]==============================================*/

#include <TSAutosar.h>    /* EB specific standard types */

#if (!defined FRNM_NO_CFGCLASSMIX_REQUIRED)
#include <FrNm_SymbolicNames_PBcfg.h>
#endif /* FRNM_NO_CFGCLASSMIX_REQUIRED */

#undef FRNM_NO_CFGCLASSMIX_REQUIRED

/*==================[macros]================================================*/

#if (defined FRNM_CFG_SIGNATURE)
#error FRNM_CFG_SIGNATURE is already defined
#endif
#define FRNM_CFG_SIGNATURE 2787775741U /* Compile time verification value */

#if (defined FRNM_PUBLIC_INFO_SIGNATURE)
#error FRNM_PUBLIC_INFO_SIGNATURE is already defined
#endif
#define FRNM_PUBLIC_INFO_SIGNATURE 3479050253U /* PublicInfoSignature */

/* !LINKSTO FrNm.Impl.PbCfgM,1 */
#if (defined FRNM_PBCFGM_SUPPORT_ENABLED)
#error FRNM_PBCFGM_SUPPORT_ENABLED is already defined
#endif
#define FRNM_PBCFGM_SUPPORT_ENABLED STD_OFF

/* ----- Pre-processor switch to enable/diable relocateable postbuild config ----- */
/* !LINKSTO FrNm.Impl.Relocatable,1 */
#if (defined FRNM_RELOCATABLE_CFG_ENABLE)
#error FRNM_RELOCATABLE_CFG_ENABLE is already defined
#endif
#if (FRNM_PBCFGM_SUPPORT_ENABLED == STD_ON)
#define FRNM_RELOCATABLE_CFG_ENABLE STD_OFF
#else
#define FRNM_RELOCATABLE_CFG_ENABLE STD_ON
#endif

/** \brief Macro switch for version info API usage */
#if (defined FRNM_VERSION_INFO_API)
#error FRNM_VERSION_INFO_API is already defined
#endif
#define FRNM_VERSION_INFO_API            STD_OFF

/** \brief Switch for DET usage */
#if (defined FRNM_DEV_ERROR_DETECT)
#error FRNM_DEV_ERROR_DETECT is already defined
#endif
#define FRNM_DEV_ERROR_DETECT            STD_ON

#if (defined FRNM_MAIN_ACROSS_FR_CYCLE)
#error FRNM_MAIN_ACROSS_FR_CYCLE is already defined
#endif
#define FRNM_MAIN_ACROSS_FR_CYCLE            STD_OFF


#if (defined FRNM_STATE_CHANGE_INDICATION_ENABLED)
#error FRNM_STATE_CHANGE_INDICATION_ENABLED is already defined
#endif
#define FRNM_STATE_CHANGE_INDICATION_ENABLED    STD_OFF

#if (defined FRNM_PASSIVE_MODE_ENABLED)
#error FRNM_PASSIVE_MODE_ENABLED is already defined
#endif
#define FRNM_PASSIVE_MODE_ENABLED        STD_OFF

#if (defined FRNM_PDU_RX_INDICATION_ENABLED)
#error FRNM_PDU_RX_INDICATION_ENABLED is already defined
#endif
#define FRNM_PDU_RX_INDICATION_ENABLED   STD_OFF

#if (defined FRNM_USER_DATA_ENABLED)
#error FRNM_USER_DATA_ENABLED is already defined
#endif
#define FRNM_USER_DATA_ENABLED           STD_ON


#if (defined FRNM_NODE_DETECTION_ENABLED)
#error FRNM_NODE_DETECTION_ENABLED is already defined
#endif
#define FRNM_NODE_DETECTION_ENABLED      STD_OFF

#if (defined FRNM_SOURCE_NODE_IDENTIFIER_ENABLED)
#error FRNM_SOURCE_NODE_IDENTIFIER_ENABLED is already defined
#endif
#define FRNM_SOURCE_NODE_IDENTIFIER_ENABLED   STD_OFF

#if (defined FRNM_CONTROL_BIT_VECTOR_ENABLED)
#error FRNM_CONTROL_BIT_VECTOR_ENABLED is already defined
#endif
#define FRNM_CONTROL_BIT_VECTOR_ENABLED      STD_ON


#if (defined FRNM_BUS_SYNCHRONIZATION_ENABLED)
#error FRNM_BUS_SYNCHRONIZATION_ENABLED is already defined
#endif
#define FRNM_BUS_SYNCHRONIZATION_ENABLED STD_OFF

#if (defined FRNM_REPEAT_MSG_BIT_ENABLED)
#error FRNM_REPEAT_MSG_BIT_ENABLED is already defined
#endif
#define FRNM_REPEAT_MSG_BIT_ENABLED      STD_OFF

#if (defined FRNM_DUAL_CHANNEL_PDU_ENABLE)
#error FRNM_DUAL_CHANNEL_PDU_ENABLE is already defined
#endif
#define FRNM_DUAL_CHANNEL_PDU_ENABLE      STD_OFF

#if (defined FRNM_COM_USER_DATA_SUPPORT)
#error FRNM_COM_USER_DATA_SUPPORT is already defined
#endif
#define FRNM_COM_USER_DATA_SUPPORT      STD_OFF

#if (defined FRNM_CYCLE_COUNTER_EMULATION)
#error FRNM_CYCLE_COUNTER_EMULATION is already defined
#endif
#define FRNM_CYCLE_COUNTER_EMULATION      STD_ON

#if (defined FRNM_HW_VOTE_ENABLE)
#error FRNM_HW_VOTE_ENABLE is already defined
#endif
#define FRNM_HW_VOTE_ENABLE      STD_OFF

#if (defined FRNM_REMOTE_SLEEP_INDICATION_ENABLED)
#error FRNM_REMOTE_SLEEP_INDICATION_ENABLED is already defined
#endif
#define FRNM_REMOTE_SLEEP_INDICATION_ENABLED      STD_OFF

#if (defined FRNM_COORDINATOR_SYNC_SUPPORT)
#error FRNM_COORDINATOR_SYNC_SUPPORT is already defined
#endif
#define FRNM_COORDINATOR_SYNC_SUPPORT  STD_OFF

/** FrNmVoteBitValue **/

#if (defined FRNM_FORCE_VOTE_BIT)
#error FRNM_FORCE_VOTE_BIT is already defined
#endif
#define FRNM_FORCE_VOTE_BIT      STD_OFF


#if (defined FRNM_SYNCH_ERR_EXTENDED)
#error FRNM_SYNCH_ERR_EXTENDED is already defined
#endif
#define FRNM_SYNCH_ERR_EXTENDED  STD_OFF


#if (defined FRNM_SYNCHRONIZATIONPOINT_ENABLED)
#error FRNM_SYNCHRONIZATIONPOINT_ENABLED is already defined
#endif
#define FRNM_SYNCHRONIZATIONPOINT_ENABLED   STD_OFF

#if (defined FRNM_REPEAT_MESSAGE_BIT_ACTIVE)
#error FRNM_REPEAT_MESSAGE_BIT_ACTIVE is already defined
#endif
#define FRNM_REPEAT_MESSAGE_BIT_ACTIVE  STD_OFF

#if (defined FRNM_NUMBER_OF_CLUSTERS)
#error FRNM_NUMBER_OF_CLUSTERS is already defined
#endif
#define FRNM_NUMBER_OF_CLUSTERS   1U


/** \brief Maximum number of Active channels */
#if (defined FRNM_NUMBER_OF_CHANNELS)
#error FRNM_NUMBER_OF_CHANNELS is already defined
#endif
#define FRNM_NUMBER_OF_CHANNELS               1U

#if (defined FRNM_NUMBER_OF_RX_PDUS)
#error FRNM_NUMBER_OF_RX_PDUS is already defined
#endif
#define FRNM_NUMBER_OF_RX_PDUS   1U

#if (defined FRNM_NUMBER_OF_TX_PDUS)
#error FRNM_NUMBER_OF_TX_PDUS is already defined
#endif
#define FRNM_NUMBER_OF_TX_PDUS   1U


/* Maximum size of associated Pdus. This size is used to define local buffer when sending data */
#if (defined FRNM_TX_BUFFER_SIZE)
#error FRNM_TX_BUFFER_SIZE is already defined
#endif
#define FRNM_TX_BUFFER_SIZE  8U



#if (defined FrNmConf_FrNmRxPdu_FrNmRxPdu_0)
#error FrNmConf_FrNmRxPdu_FrNmRxPdu_0 already defined
#endif

/** \brief Symbolic name of FrNmRxPdu with Id "0" for
 *  the channel FrNmChannel_0 */
#define FrNmConf_FrNmRxPdu_FrNmRxPdu_0   0U

#if (!defined FRNM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined FrNmRxPdu_0)
#error FrNmRxPdu_0 already defined
#endif

/** \brief Export symbolic name value without prefix
 * (AUTOSAR version <= 3.1 rev4) 0 */
#define FrNmRxPdu_0                     0U

#if (defined FrNm_FrNmRxPdu_0)
#error FrNm_FrNmRxPdu_0 already defined
#endif

/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define FrNm_FrNmRxPdu_0   0U
#endif /* FRNM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */




#if (defined FrNmConf_FrNmTxPdu_FrNmTxPdu_0)
#error FrNmConf_FrNmTxPdu_FrNmTxPdu_0 already defined
#endif

/** \brief Symbolic name of FrNmRxPdu with Id "0"
 *  for the channel FrNmChannel_0 */
#define FrNmConf_FrNmTxPdu_FrNmTxPdu_0   0U

#if (!defined FRNM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined FrNmTxPdu_0)
#error FrNmTxPdu_0 already defined
#endif

/** \brief Export symbolic name value without prefix
 * (AUTOSAR version <= 3.1 rev4) 0 */
#define FrNmTxPdu_0                     0U

#if (defined FrNm_FrNmTxPdu_0)
#error FrNm_FrNmTxPdu_0 already defined
#endif

/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define FrNm_FrNmTxPdu_0   0U
#endif /* FRNM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */






#if (defined FRNM_ACTIVE_WAKEUP_BIT_ENABLED)
#error FRNM_ACTIVE_WAKEUP_BIT_ENABLED is already defined
#endif
#define FRNM_ACTIVE_WAKEUP_BIT_ENABLED STD_OFF

#if (defined FRNM_CARWAKEUP_RX_ENABLED)
#error FRNM_CARWAKEUP_RX_ENABLED is already defined
#endif

#define FRNM_CARWAKEUP_RX_ENABLED        STD_OFF

/*------------------[PN Extensions]-------------------------------------*/


/** FrNmPnInfoLength **/
#if (defined FRNM_PN_INFO_LENGTH)
#error FRNM_PN_INFO_LENGTH is already defined
#endif
#define FRNM_PN_INFO_LENGTH                   6U

#if (defined FRNM_PN_EIRA_TIMER_SIZE)
#error FRNM_PN_EIRA_TIMER_SIZE is already defined
#endif
#define FRNM_PN_EIRA_TIMER_SIZE  (FRNM_PN_INFO_LENGTH * 8U)

#if (defined FRNM_PN_INFO_OFFSET)
#error FRNM_PN_INFO_OFFSET is already defined
#endif
#define FRNM_PN_INFO_OFFSET                   2U

/** FrNmPnEiraCalcEnabled **/
#if (defined FRNM_PN_EIRA_CALC_ENABLED)
#error FRNM_PN_EIRA_CALC_ENABLED is already defined
#endif
#define FRNM_PN_EIRA_CALC_ENABLED             STD_OFF

/** FrNmPnEraCalcEnabled **/
#if (defined FRNM_PN_ERA_CALC_ENABLED)
#error FRNM_PN_ERA_CALC_ENABLED is already defined
#endif
#define FRNM_PN_ERA_CALC_ENABLED             STD_OFF

/** FrNmPnResetTime **/
#if (defined FRNM_PN_RESET_TIME)
#error FRNM_PN_RESET_TIME is already defined
#endif
#define FRNM_PN_RESET_TIME     384U



#if (defined FRNM_PN_SUPPORTED)
#error FRNM_PN_SUPPORTED is already defined
#endif
#define FRNM_PN_SUPPORTED  STD_ON





/*------------------[Hsm configuration]-------------------------------------*/

#if (defined FRNM_HSM_INST_MULTI_ENABLED)
#error FRNM_HSM_INST_MULTI_ENABLED is already defined
#endif
#if (FRNM_NUMBER_OF_CHANNELS > 1U)
#define FRNM_HSM_INST_MULTI_ENABLED STD_ON
#else
#define FRNM_HSM_INST_MULTI_ENABLED STD_OFF
#endif

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/
#define FRNM_START_SEC_CODE
#include <MemMap.h>
/* Deviation MISRAC2012-1 */

  FUNC(void, FRNM_CODE) FrNm_MainFunction_0(void);


#define FRNM_STOP_SEC_CODE
#include <MemMap.h>
/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/



/*==================[internal function definitions]=========================*/

#endif /* if !defined( FRNM_CFG_H ) */
/*==================[end of file]===========================================*/
