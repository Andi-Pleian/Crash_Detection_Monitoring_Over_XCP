/**
 * \file
 *
 * \brief AUTOSAR CanSM
 *
 * This file contains the implementation of the AUTOSAR
 * module CanSM.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2017 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#if (!defined CANSM_CFG_H)
#define CANSM_CFG_H
/*==================[includes]==============================================*/

#include <ComStack_Types.h>         /* AUTOSAR communication stack types */

#include <CanSM_Int_Stc.h>          /* Module internal static header */
#include <CanSM_Api_Static.h>       /* CanSM_ConfigType */
#include <CanSM_Det_Cfg.h>          /* CANSM_DEV_ERROR_DETECT */

#include <CanIf.h>                  /* CAN Interface */
#include <ComM.h>                   /* Communication Manager types */


/*==================[macros]================================================*/




/*------------------[Defensive programming]---------------------------------*/

#if (defined CANSM_DEFENSIVE_PROGRAMMING_ENABLED)
#error CANSM_DEFENSIVE_PROGRAMMING_ENABLED is already defined
#endif
/** \brief Defensive programming usage
 **
 ** En- or disables the usage of the defensive programming */
#define CANSM_DEFENSIVE_PROGRAMMING_ENABLED   STD_OFF

#if (defined CANSM_PRECONDITION_ASSERT_ENABLED)
#error CANSM_PRECONDITION_ASSERT_ENABLED is already defined
#endif
/** \brief Precondition assertion usage
 **
 ** En- or disables the usage of precondition assertion checks */
#define CANSM_PRECONDITION_ASSERT_ENABLED     STD_OFF

#if (defined CANSM_POSTCONDITION_ASSERT_ENABLED)
#error CANSM_POSTCONDITION_ASSERT_ENABLED is already defined
#endif
/** \brief Postcondition assertion usage
 **
 ** En- or disables the usage of postcondition assertion checks */
#define CANSM_POSTCONDITION_ASSERT_ENABLED    STD_OFF

#if (defined CANSM_UNREACHABLE_CODE_ASSERT_ENABLED)
#error CANSM_UNREACHABLE_CODE_ASSERT_ENABLED is already defined
#endif
/** \brief Unreachable code assertion usage
 **
 ** En- or disables the usage of unreachable code assertion checks */
#define CANSM_UNREACHABLE_CODE_ASSERT_ENABLED STD_OFF

#if (defined CANSM_INVARIANT_ASSERT_ENABLED)
#error CANSM_INVARIANT_ASSERT_ENABLED is already defined
#endif
/** \brief Invariant assertion usage
 **
 ** En- or disables the usage of invariant assertion checks */
#define CANSM_INVARIANT_ASSERT_ENABLED        STD_OFF

#if (defined CANSM_STATIC_ASSERT_ENABLED)
#error CANSM_STATIC_ASSERT_ENABLED is already defined
#endif
/** \brief Static assertion usage
 **
 ** En- or disables the usage of static assertion checks */
#define CANSM_STATIC_ASSERT_ENABLED           STD_OFF





#if (defined CANSM_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanSM_CanNetwork_0 )
#error CanSM_CanNetwork_0 is already defined
#endif /* #if (defined CanSM_CanNetwork_0 ) */

/** \brief Export symbolic name value */
#define CanSM_CanNetwork_0 1U

#endif /* #if (defined CANSM_PROVIDE_LEGACY_SYMBOLIC_NAMES) */



#if (defined CANSM_PROD_ERR_HANDLING_BUS_OFF)
#error CANSM_PROD_ERR_HANDLING_BUS_OFF is already defined
#endif /* #if (defined CANSM_PROD_ERR_HANDLING_BUS_OFF) */

/** \brief Switch for DEM to DET reporting */
#define CANSM_PROD_ERR_HANDLING_BUS_OFF   TS_PROD_ERR_DISABLE

#if (defined CANSM_E_DEMTODET_BUS_OFF)
#error CANSM_E_DEMTODET_BUS_OFF is already defined
#endif /* #if (defined CANSM_E_DEMTODET_BUS_OFF) */



#if (defined CANSM_VERSION_INFO_API)
#error CANSM_VERSION_INFO_API is already defined
#endif /* #if (defined CANSM_VERSION_INFO_API) */

/** \brief Switch for version info API */
#define CANSM_VERSION_INFO_API STD_OFF

#if (defined CANSM_SET_BAUDRATE_API)
#error CANSM_SET_BAUDRATE_API is already defined
#endif /* #if (defined CANSM_SET_BAUDRATE_API) */

/** \brief Switch for SetBaudrate API */
#define CANSM_SET_BAUDRATE_API STD_OFF

#if (defined CANSM_BUSDEACTIVATED_BUSOFF)
#error CANSM_BUSDEACTIVATED_BUSOFF is already defined
#endif /* #if (defined CANSM_BUSDEACTIVATED_BUSOFF) */

/** \brief Switch for Bus Off handling triggers No Communication or Silent Communication */
#define CANSM_BUSDEACTIVATED_BUSOFF STD_OFF

#if (defined CANSM_ENHANCED_BUSOFF_REPORTING)
#error CANSM_ENHANCED_BUSOFF_REPORTING is already defined
#endif /* #if (defined CANSM_ENHANCED_BUSOFF_REPORTING) */

/** \brief Switch enhanced bus-off reporting to BswM on or off */
#define CANSM_ENHANCED_BUSOFF_REPORTING STD_OFF

#if (defined CANSM_PNSUPPORT)
#error CANSM_PNSUPPORT is already defined
#endif /* #if (defined CANSM_PNSUPPORT) */

/** \brief Partial Networking Support */
#define CANSM_PNSUPPORT STD_OFF

#if (defined CANSM_MODEREQ_MAX)
#error CANSM_MODEREQ_MAX is already defined
#endif /* #if (defined CANSM_MODEREQ_MAX) */

/** \brief Maximum amount of mode change request repetitions */
#define CANSM_MODEREQ_MAX 0U

#if (defined CANSM_MODEREQ_REPEAT_TIME)
#error CANSM_MODEREQ_REPEAT_TIME is already defined
#endif /* #if (defined CANSM_MODEREQ_REPEAT_TIME) */

/** \brief Time duration after which a mode change request is repeated */
#define CANSM_MODEREQ_REPEAT_TIME 0U

#if (defined CANSM_USE_TRANSCEIVER)
#error CANSM_USE_TRANSCEIVER is already defined
#endif /* #if (defined CANSM_USE_TRANSCEIVER) */

/** \brief use transceiver driver calls or not */
#define CANSM_USE_TRANSCEIVER STD_OFF


#if (defined CANSM_TX_TIMEOUT_EXCEPTION_API)
#error CANSM_TX_TIMEOUT_EXCEPTION_API is already defined
#endif /* #if (defined CANSM_TX_TIMEOUT_EXCEPTION_API) */

/** \brief Switch for TxTimeoutException API */
#define CANSM_TX_TIMEOUT_EXCEPTION_API STD_OFF



#if (defined CANSM_BOR_TIME_TX_ENSURED)
#error CANSM_BOR_TIME_TX_ENSURED is already defined
#endif /* #if (defined CANSM_BOR_TIME_TX_ENSURED) */

/** \brief Duration until bus-off free communication is assumed */
#define CANSM_BOR_TIME_TX_ENSURED(nw) 500U



#if (defined CANSM_BOR_TIME_L1)
#error CANSM_BOR_TIME_L1 is already defined
#endif /* #if (defined CANSM_BOR_TIME_L1) */

/** \brief Duration to stay in level 1 check before restart of communication */
#define CANSM_BOR_TIME_L1(nw) 5U


#if (defined CANSM_BOR_TIME_L2)
#error CANSM_BOR_TIME_L2 is already defined
#endif /* #if (defined CANSM_BOR_TIME_L2) */

/** \brief Duration to stay in level 2 check before restart of communication */
#define CANSM_BOR_TIME_L2(nw) 100U


#if (defined CANSM_BOR_COUNTER_L1_TO_L2)
#error CANSM_BOR_COUNTER_L1_TO_L2 is already defined
#endif /* #if (defined CANSM_BOR_COUNTER_L1_TO_L2) */

/** \brief bus-off recovery L1 to L2 Threshold */
#define CANSM_BOR_COUNTER_L1_TO_L2(nw) 1U

#if (defined CANSM_BOR_TX_CONFIRMATION_POLLING)
#error CANSM_BOR_TX_CONFIRMATION_POLLING is already defined
#endif /* #if (defined CANSM_BOR_TX_CONFIRMATION_POLLING) */

/** \brief BOR Tx Confirmation Polling */
#define CANSM_BOR_TX_CONFIRMATION_POLLING(nw) FALSE

#if (defined CANSM_USE_CANIF_GETTXCONFIRMATIONSTATE)
#error CANSM_USE_CANIF_GETTXCONFIRMATIONSTATE is already defined
#endif /* #if (defined CANSM_USE_CANIF_GETTXCONFIRMATIONSTATE) */

/** \brief Use CanIf_GetTxConfirmationState API */
#define CANSM_USE_CANIF_GETTXCONFIRMATIONSTATE STD_OFF

#if (defined CANSM_USE_BOR_TIME_TX_ENSURED)
#error CANSM_USE_BOR_TIME_TX_ENSURED is already defined
#endif /* #if (defined CANSM_USE_BOR_TIME_TX_ENSURED) */

/** \brief Use CanSMBorTimeTxEnsured for bus-off check */
#define CANSM_USE_BOR_TIME_TX_ENSURED STD_ON

#if (defined CANSM_NETWORKS_NUM)
#error CANSM_NETWORKS_NUM is already defined
#endif /* #if (defined CANSM_NETWORKS_NUM) */

/** \brief number of networks used */
#define CANSM_NETWORKS_NUM 1U

#if (defined CANSM_CONTROLLERS_NUM)
#error CANSM_CONTROLLERS_NUM is already defined
#endif /* #if (defined CANSM_CONTROLLERS_NUM) */

/** \brief number of controllers used */
#define CANSM_CONTROLLERS_NUM 1U

#if (defined CANSM_CONTROLLERS_ID_NUM)
#error CANSM_CONTROLLERS_ID_NUM is already defined
#endif /* #if (defined CANSM_CONTROLLERS_ID_NUM) */

/** \brief highest controller id used + 1 */
#define CANSM_CONTROLLERS_ID_NUM 1U

#if (defined CANSM_CTRLMODETYPE_RESET)
#error CANSM_CTRLMODETYPE_RESET is already defined
#endif /* #if (defined CANSM_CTRLMODETYPE_RESET) */

/** \brief special value to indicate that CanSM_ControllerModeIndication was not invoked
 *  with a meaningful value since last reset
 */
#define CANSM_CTRLMODETYPE_RESET 0U

#if (defined CANSM_CTRLMODETYPE_SLEEP)
#error CANSM_CTRLMODETYPE_SLEEP is already defined
#endif /* #if (defined CANSM_CTRLMODETYPE_SLEEP) */

/** \brief CanSM_ControllerModeIndication was last invoked with CANIF_CS_SLEEP */
#define CANSM_CTRLMODETYPE_SLEEP 1U

#if (defined CANSM_CTRLMODETYPE_STARTED)
#error CANSM_CTRLMODETYPE_STARTED is already defined
#endif /* #if (defined CANSM_CTRLMODETYPE_STARTED) */

/** \brief CanSM_ControllerModeIndication was last invoked with CANIF_CS_STARTED */
#define CANSM_CTRLMODETYPE_STARTED 2U

#if (defined CANSM_CTRLMODETYPE_STOPPED)
#error CANSM_CTRLMODETYPE_STOPPED is already defined
#endif /* #if (defined CANSM_CTRLMODETYPE_STOPPED) */

/** \brief CanSM_ControllerModeIndication was last invoked with CANIF_CS_STOPPED */
#define CANSM_CTRLMODETYPE_STOPPED 3U

#if (defined CANSM_TRANSCEIVERS_NUM)
#error CANSM_TRANSCEIVERS_NUM is already defined
#endif /* #if (defined CANSM_TRANSCEIVERS_NUM) */

/** \brief number of transceivers used */
#define CANSM_TRANSCEIVERS_NUM 0U






#if (defined CANSM_PARTIALNETWORKING)
#error CANSM_PARTIALNETWORKING is already defined
#endif /* #if (defined CANSM_PARTIALNETWORKING) */

/** \brief Partial networking */
#define CANSM_PARTIALNETWORKING(nw) FALSE




#if (defined CANSM_NW_HANDLE_IS_VALID)
#error CANSM_NW_HANDLE_IS_VALID is already defined
#endif /* #if (defined CANSM_NW_HANDLE_IS_VALID) */

/** \brief check if network handle is valid */
#define CANSM_NW_HANDLE_IS_VALID(nw) ((nw) == 1U)

#if (defined CANSM_NW_HANDLE_FROM_IDX)
#error CANSM_NW_HANDLE_FROM_IDX is already defined
#endif /* #if (defined CANSM_NW_HANDLE_FROM_IDX) */

/** \brief convert network array index to handle */
#define CANSM_NW_HANDLE_FROM_IDX(nw) ((NetworkHandleType)1U)



#if (defined CANSM_NW_CONFIG_CTRL_START)
#error CANSM_NW_CONFIG_CTRL_START is already defined
#endif /* #if (defined CANSM_NW_CONFIG_CTRL_START) */

/** \brief Index of first controller of this network in controller list */
#define CANSM_NW_CONFIG_CTRL_START(nw) 0U

#if (defined CANSM_NW_CONFIG_CTRL_NUM)
#error CANSM_NW_CONFIG_CTRL_NUM is already defined
#endif /* #if (defined CANSM_NW_CONFIG_CTRL_NUM) */

/** \brief Number of controllers in this network */
#define CANSM_NW_CONFIG_CTRL_NUM(nw) 1U

#if (defined CANSM_NW_IDX_FROM_HANDLE)
#error CANSM_NW_IDX_FROM_HANDLE is already defined
#endif /* #if (defined CANSM_NW_IDX_FROM_HANDLE) */

/** \brief convert network handle to array index */
#define CANSM_NW_IDX_FROM_HANDLE(nw) 0U

#if (defined CANSM_NW_CONFIG_CTRL)
#error CANSM_NW_CONFIG_CTRL is already defined
#endif /* #if (defined CANSM_NW_CONFIG_CTRL) */


/** \brief Get controller \a ctrl from controller list */
#define CANSM_NW_CONFIG_CTRL(ctrl) 0U



 


#if (defined CANSM_NW_INFO_TIMER)
#error CANSM_NW_INFO_TIMER is already defined
#endif /* #if (defined CANSM_NW_INFO_TIMER) */

/** \brief access to bor state machine timer of network \a nw */
#define CANSM_NW_INFO_TIMER(nw) (CanSM_NetworkInfo[(nw)].BoTimer)

#if (defined CANSM_NW_INFO_BOR_COUNTER)
#error CANSM_NW_INFO_BOR_COUNTER is already defined
#endif /* #if (defined CANSM_NW_INFO_BOR_COUNTER) */

/** \brief access to bus-off counter of network \a nw */
#define CANSM_NW_INFO_BOR_COUNTER(nw) (CanSM_NetworkInfo[(nw)].BoCounter)

#if (defined CANSM_NW_INFO_STATE)
#error CANSM_NW_INFO_STATE is already defined
#endif /* #if (defined CANSM_NW_INFO_STATE) */

/** \brief access to current state of network \a nw */
#define CANSM_NW_INFO_STATE(nw) (CanSM_NetworkInfo[(nw)].NwState)

#if (defined CANSM_NW_INFO_BUSOFF)
#error CANSM_NW_INFO_BUSOFF is already defined
#endif /* #if (defined CANSM_NW_INFO_BUSOFF) */

/** \brief access to bus-off event flag of network \a nw */
#define CANSM_NW_INFO_BUSOFF(nw) (CanSM_NetworkInfo[(nw)].BusOffEvent)

#if (defined CANSM_NW_INFO_INTERNALSTATE)
#error CANSM_NW_INFO_INTERNALSTATE is already defined
#endif /* #if (defined CANSM_NW_INFO_INTERNALSTATE) */

/** \brief access to current internal state of network \a nw */
#define CANSM_NW_INFO_INTERNALSTATE(nw) (CanSM_NetworkInfo[(nw)].InternalState)

#if (CANSM_SET_BAUDRATE_API == STD_ON)

#if (defined CANSM_NW_INFO_BAUDRATEID)
#error CANSM_NW_INFO_BAUDRATEID is already defined
#endif /* #if (defined CANSM_NW_INFO_BAUDRATEID) */

/** \brief access to latest requested baudrate ID \a nw */
#define CANSM_NW_INFO_BAUDRATEID(nw) (CanSM_NetworkInfo[(nw)].BaudrateID)
#endif /* CANSM_SET_BAUDRATE_API */

#if (defined CANSM_NW_INFO_REQCOMMODE)
#error CANSM_NW_INFO_REQCOMMODE is already defined
#endif /* #if (defined CANSM_NW_INFO_REQCOMMODE) */

/** \brief access to latest requested ComMMode \a nw */
#define CANSM_NW_INFO_REQCOMMODE(nw) (CanSM_NetworkInfo[(nw)].reqComMode)

#if (defined CANSM_NW_INFO_MODE_REQUEST_REPETITION_TIMER)
#error CANSM_NW_INFO_MODE_REQUEST_REPETITION_TIMER is already defined
#endif /* #if (defined CANSM_NW_INFO_MODE_REQUEST_REPETITION_TIMER) */

/** \brief access to mode change request repetitions timer of network \a nw */
#define CANSM_NW_INFO_MODE_REQUEST_REPETITION_TIMER(nw) (CanSM_NetworkInfo[(nw)].ModeReqRepetitionTimer)





#if (defined CANSM_NW_INFO_MODE_REQUEST_REPETITION_COUNTER)
#error CANSM_NW_INFO_MODE_REQUEST_REPETITION_COUNTER is already defined
#endif /* #if (defined CANSM_NW_INFO_MODE_REQUEST_REPETITION_COUNTER) */

/** \brief access to mode change request repetitions counter of network \a nw */
#define CANSM_NW_INFO_MODE_REQUEST_REPETITION_COUNTER(nw) (CanSM_NetworkInfo[(nw)].ModeReqRepetitionCounter)

#if (defined CANSM_NW_INFO_TRANSITION_ONGOING)
#error CANSM_NW_INFO_TRANSITION_ONGOING is already defined
#endif /* #if (defined CANSM_NW_INFO_TRANSITION_ONGOING) */

/** \brief access to "transition ongoing" signal of network \a nw */
#define CANSM_NW_INFO_TRANSITION_ONGOING(nw) (CanSM_NetworkInfo[(nw)].TransitionOngoing)

#if (defined CANSM_NW_IDX_FROM_CONTROLLER)
#error CANSM_NW_IDX_FROM_CONTROLLER is already defined
#endif /* #if (defined CANSM_NW_IDX_FROM_CONTROLLER) */

/** \brief Convert Controller id to array index for internal network data
 *
 * \param[in] ctrl Controller Id
 *
 * \return The array index of the network, CANSM_NETWORKS_NUM on lookup failure
 */
#define CANSM_NW_IDX_FROM_CONTROLLER(ctrl) \
  ( (ctrl) < CANSM_CONTROLLERS_ID_NUM ? CanSM_ControllerNetworkLut[(ctrl)] : CANSM_NETWORKS_NUM )



/*==================[type definitions]======================================*/




/** \brief runtime information for one network */
typedef struct {
  /* enumerations */
  ComM_ModeType reqComMode;              /**< stores mode requested by ComM */
  ComM_ModeType NwState;                 /**< current ComM mode */
  CanSM_InternalStateType InternalState; /**< current internal state */
  /* uint16 */
  uint16 BoTimer;                        /**< timer for bus-off recovery state machine */
  uint16 ModeReqRepetitionTimer;         /**< timer for mode change request repetitions */
#if (CANSM_SET_BAUDRATE_API == STD_ON)
  uint16 BaudrateID;                     /**< baudrate ID of latest CanSM_SetBaudrate() call */
#endif /* CANSM_SET_BAUDRATE_API */
  /* uint8 */
  uint8 BusOffEvent;                     /**< indicates that a bus-off event has occured */
  uint8 BoCounter;                       /**< bus-off counter */
  uint8 ModeReqRepetitionCounter;        /**< mode change request repetition counter */
#if (CANSM_USE_TRANSCEIVER == STD_ON)
  uint8 TrcvModeIndication;              /**< stores trcv mode indication event */
#endif /* CANSM_USE_TRANSCEIVER == STD_ON */
  /* boolean */
  boolean TransitionOngoing;             /**< signalizes a triggered and not finished transition */
#if ( (CANSM_PNSUPPORT == STD_ON) && (CANSM_USE_TRANSCEIVER == STD_ON) )
  boolean TrcvClearWUFIndication;        /**< stores trcv clear wakeup flag indication event */
  boolean TrcvCheckWakeFlagIndication;   /**< stores trcv check wakeup flag indication event */
#endif /* ( (CANSM_PNSUPPORT == STD_ON) && (CANSM_USE_TRANSCEIVER == STD_ON) ) */
} CanSM_NetworkInfoType;

/*==================[external constants]====================================*/


#define CANSM_START_SEC_CONFIG_DATA_8
#include <MemMap.h>

/** \brief Empty configuration structure to be passed to CanSM_Init() */
extern CONST(CanSM_ConfigType, CANSM_APPL_CONST) CanSM_Config_0;



/**
 * \brief controller to network handle lookup table
 *
 * \note may contain holes, these have the value CANSM_NETWORKS_NUM
 */
extern CONST(uint8, CANSM_APPL_CONST) CanSM_ControllerNetworkLut[CANSM_CONTROLLERS_ID_NUM];



#define CANSM_STOP_SEC_CONFIG_DATA_8
#include <MemMap.h>

/*==================[external data]=========================================*/

#define CANSM_START_SEC_VAR_NO_INIT_8
#include <MemMap.h>

/** \brief Contains indication by last CanSM_ControllerModeIndication (CanSM specific
 *  representation), or CANSM_CTRLMODETYPE_RESET
 */
extern VAR(uint8, CANSM_VAR) CanSM_CtrlModeIndication[CANSM_CONTROLLERS_ID_NUM];

#define CANSM_STOP_SEC_VAR_NO_INIT_8
#include <MemMap.h>

#define CANSM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include <MemMap.h>

/** \brief run-time information for all networks */
extern VAR(CanSM_NetworkInfoType, CANSM_VAR) CanSM_NetworkInfo[CANSM_NETWORKS_NUM];

#define CANSM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include <MemMap.h>

/*==================[external function declarations]========================*/



#endif /* if !defined( CANSM_CFG_H ) */
/*==================[end of file]===========================================*/

