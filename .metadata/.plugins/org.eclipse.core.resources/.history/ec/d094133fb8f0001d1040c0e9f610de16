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
[!INCLUDE "CanSM_Macros.m"!][!//
#if (!defined CANSM_CFG_H)
#define CANSM_CFG_H
/*==================[includes]==============================================*/

#include <ComStack_Types.h>         /* AUTOSAR communication stack types */

#include <CanSM_Int_Stc.h>          /* Module internal static header */
#include <CanSM_Api_Static.h>       /* CanSM_ConfigType */
#include <CanSM_Det_Cfg.h>          /* CANSM_DEV_ERROR_DETECT */

#include <CanIf.h>                  /* CAN Interface */
#include <ComM.h>                   /* Communication Manager types */
[!IF "$useDEM = 'true'"!]
#include <Dem.h>                    /* AUTOSAR Dem */
[!ENDIF!]

/*==================[macros]================================================*/




/*------------------[Defensive programming]---------------------------------*/
[!SELECT "CanSMDefensiveProgramming"!][!//

#if (defined CANSM_DEFENSIVE_PROGRAMMING_ENABLED)
#error CANSM_DEFENSIVE_PROGRAMMING_ENABLED is already defined
#endif
/** \brief Defensive programming usage
 **
 ** En- or disables the usage of the defensive programming */
#define CANSM_DEFENSIVE_PROGRAMMING_ENABLED   [!//
[!IF "(../CanSMGeneral/CanSMDevErrorDetect  = 'true') and (CanSMDefProgEnabled = 'true')"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

#if (defined CANSM_PRECONDITION_ASSERT_ENABLED)
#error CANSM_PRECONDITION_ASSERT_ENABLED is already defined
#endif
/** \brief Precondition assertion usage
 **
 ** En- or disables the usage of precondition assertion checks */
#define CANSM_PRECONDITION_ASSERT_ENABLED     [!//
[!IF "(../CanSMGeneral/CanSMDevErrorDetect  = 'true') and (CanSMDefProgEnabled = 'true') and (CanSMPrecondAssertEnabled = 'true')"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

#if (defined CANSM_POSTCONDITION_ASSERT_ENABLED)
#error CANSM_POSTCONDITION_ASSERT_ENABLED is already defined
#endif
/** \brief Postcondition assertion usage
 **
 ** En- or disables the usage of postcondition assertion checks */
#define CANSM_POSTCONDITION_ASSERT_ENABLED    [!//
[!IF "(../CanSMGeneral/CanSMDevErrorDetect  = 'true') and (CanSMDefProgEnabled = 'true') and (CanSMPostcondAssertEnabled = 'true')"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

#if (defined CANSM_UNREACHABLE_CODE_ASSERT_ENABLED)
#error CANSM_UNREACHABLE_CODE_ASSERT_ENABLED is already defined
#endif
/** \brief Unreachable code assertion usage
 **
 ** En- or disables the usage of unreachable code assertion checks */
#define CANSM_UNREACHABLE_CODE_ASSERT_ENABLED [!//
[!IF "(../CanSMGeneral/CanSMDevErrorDetect  = 'true') and (CanSMDefProgEnabled = 'true') and (CanSMUnreachAssertEnabled = 'true')"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

#if (defined CANSM_INVARIANT_ASSERT_ENABLED)
#error CANSM_INVARIANT_ASSERT_ENABLED is already defined
#endif
/** \brief Invariant assertion usage
 **
 ** En- or disables the usage of invariant assertion checks */
#define CANSM_INVARIANT_ASSERT_ENABLED        [!//
[!IF "(../CanSMGeneral/CanSMDevErrorDetect  = 'true') and (CanSMDefProgEnabled = 'true') and (CanSMInvariantAssertEnabled = 'true')"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

#if (defined CANSM_STATIC_ASSERT_ENABLED)
#error CANSM_STATIC_ASSERT_ENABLED is already defined
#endif
/** \brief Static assertion usage
 **
 ** En- or disables the usage of static assertion checks */
#define CANSM_STATIC_ASSERT_ENABLED           [!//
[!IF "(../CanSMGeneral/CanSMDevErrorDetect  = 'true') and (CanSMDefProgEnabled = 'true') and (CanSMStaticAssertEnabled = 'true')"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

[!ENDSELECT!][!//


[!SELECT "as:modconf('CanSM')[1]"!][!//
[!LOOP "CanSMConfiguration/*[1]/CanSMManagerNetwork/*"!]

#if (defined CANSM_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanSM_[!"@name"!] )
#error CanSM_[!"@name"!] is already defined
#endif /* #if (defined CanSM_[!"@name"!] ) */

/** \brief Export symbolic name value */
#define CanSM_[!"@name"!] [!"as:ref(CanSMComMNetworkHandleRef)/ComMChannelId"!]U

#endif /* #if (defined CANSM_PROVIDE_LEGACY_SYMBOLIC_NAMES) */

[!ENDLOOP!]

#if (defined CANSM_PROD_ERR_HANDLING_BUS_OFF)
#error CANSM_PROD_ERR_HANDLING_BUS_OFF is already defined
#endif /* #if (defined CANSM_PROD_ERR_HANDLING_BUS_OFF) */

/** \brief Switch for DEM to DET reporting */
#define CANSM_PROD_ERR_HANDLING_BUS_OFF   [!//
[!IF "$useDEM = 'true'"!][!//
TS_PROD_ERR_REP_TO_DEM
[!ELSEIF "ReportToDem/CanSMBusOffReportToDem = 'DET'"!][!//
TS_PROD_ERR_REP_TO_DET
[!ELSE!][!//
TS_PROD_ERR_DISABLE
[!ENDIF!][!//

#if (defined CANSM_E_DEMTODET_BUS_OFF)
#error CANSM_E_DEMTODET_BUS_OFF is already defined
#endif /* #if (defined CANSM_E_DEMTODET_BUS_OFF) */

[!IF "ReportToDem/CanSMBusOffReportToDem = 'DET'"!][!//
/** \brief Det error ID, if DEM to DET reporting is enabled */
#define CANSM_E_DEMTODET_BUS_OFF          [!"ReportToDem/CanSMBusOffReportToDemDetErrorId"!]U
[!ENDIF!][!//

[!ENDSELECT!][!//

#if (defined CANSM_VERSION_INFO_API)
#error CANSM_VERSION_INFO_API is already defined
#endif /* #if (defined CANSM_VERSION_INFO_API) */

/** \brief Switch for version info API */
[!IF "as:modconf('CanSM')[1]/CanSMGeneral/CanSMVersionInfoApi = 'true'"!][!//
#define CANSM_VERSION_INFO_API STD_ON
[!ELSE!][!//
#define CANSM_VERSION_INFO_API STD_OFF
[!ENDIF!][!//

#if (defined CANSM_SET_BAUDRATE_API)
#error CANSM_SET_BAUDRATE_API is already defined
#endif /* #if (defined CANSM_SET_BAUDRATE_API) */

/** \brief Switch for SetBaudrate API */
[!IF "as:modconf('CanSM')[1]/CanSMGeneral/CanSMSetBaudrateApi = 'true'"!][!//
#define CANSM_SET_BAUDRATE_API STD_ON
[!ELSE!][!//
#define CANSM_SET_BAUDRATE_API STD_OFF
[!ENDIF!][!//

#if (defined CANSM_BUSDEACTIVATED_BUSOFF)
#error CANSM_BUSDEACTIVATED_BUSOFF is already defined
#endif /* #if (defined CANSM_BUSDEACTIVATED_BUSOFF) */

/** \brief Switch for Bus Off handling triggers No Communication or Silent Communication */
[!IF "as:modconf('CanSM')[1]/CanSMGeneral/CanSMBusDeactivatedBusOff = 'true'"!][!//
#define CANSM_BUSDEACTIVATED_BUSOFF STD_ON
[!ELSE!][!//
#define CANSM_BUSDEACTIVATED_BUSOFF STD_OFF
[!ENDIF!][!//

#if (defined CANSM_ENHANCED_BUSOFF_REPORTING)
#error CANSM_ENHANCED_BUSOFF_REPORTING is already defined
#endif /* #if (defined CANSM_ENHANCED_BUSOFF_REPORTING) */

/** \brief Switch enhanced bus-off reporting to BswM on or off */
[!IF "as:modconf('CanSM')[1]/CanSMGeneral/CanSMEnhancedBusOffReporting = 'true'"!][!//
#define CANSM_ENHANCED_BUSOFF_REPORTING STD_ON
[!ELSE!][!//
#define CANSM_ENHANCED_BUSOFF_REPORTING STD_OFF
[!ENDIF!][!//

#if (defined CANSM_PNSUPPORT)
#error CANSM_PNSUPPORT is already defined
#endif /* #if (defined CANSM_PNSUPPORT) */

/** \brief Partial Networking Support */
#define CANSM_PNSUPPORT [!IF "$globalPnSupport = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

#if (defined CANSM_MODEREQ_MAX)
#error CANSM_MODEREQ_MAX is already defined
#endif /* #if (defined CANSM_MODEREQ_MAX) */

/** \brief Maximum amount of mode change request repetitions */
#define CANSM_MODEREQ_MAX [!"CanSMConfiguration/*[1]/CanSMModeRequestRepetitionMax"!]U

#if (defined CANSM_MODEREQ_REPEAT_TIME)
#error CANSM_MODEREQ_REPEAT_TIME is already defined
#endif /* #if (defined CANSM_MODEREQ_REPEAT_TIME) */

/** \brief Time duration after which a mode change request is repeated */
#define CANSM_MODEREQ_REPEAT_TIME [!CALL "CalcToTicks", "time"="CanSMConfiguration/*[1]/CanSMModeRequestRepetitionTime", "maxTicks"="65534"!]U

#if (defined CANSM_USE_TRANSCEIVER)
#error CANSM_USE_TRANSCEIVER is already defined
#endif /* #if (defined CANSM_USE_TRANSCEIVER) */

/** \brief use transceiver driver calls or not */
#define CANSM_USE_TRANSCEIVER [!IF "$useTransceiver = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]


#if (defined CANSM_TX_TIMEOUT_EXCEPTION_API)
#error CANSM_TX_TIMEOUT_EXCEPTION_API is already defined
#endif /* #if (defined CANSM_TX_TIMEOUT_EXCEPTION_API) */

/** \brief Switch for TxTimeoutException API */
[!IF "as:modconf('CanSM')[1]/CanSMGeneral/CanSMTxTimeoutExceptionApi = 'true'"!][!//
#define CANSM_TX_TIMEOUT_EXCEPTION_API STD_ON
[!ELSE!][!//
#define CANSM_TX_TIMEOUT_EXCEPTION_API STD_OFF
[!ENDIF!][!//


[!IF "$useBorTimeTxEnsured = 'true'"!][!//

#if (defined CANSM_BOR_TIME_TX_ENSURED)
#error CANSM_BOR_TIME_TX_ENSURED is already defined
#endif /* #if (defined CANSM_BOR_TIME_TX_ENSURED) */

/** \brief Duration until bus-off free communication is assumed */
[!IF "$nwSpecificBorTimeTxEnsured = 'true'"!][!//
#define CANSM_BOR_TIME_TX_ENSURED(nw) (CanSM_NetworkConfig[(nw)].BorTimeTxEnsured)
[!ELSE!][!//
[!/* num:max() has the purpose to select a single value out of the identical values */!][!//
#define CANSM_BOR_TIME_TX_ENSURED(nw) [!CALL "CalcToTicks", "time"="num:max(CanSMConfiguration/*[1]/CanSMManagerNetwork/*[CanSMBorTxConfirmationPolling = 'false']/CanSMBorTimeTxEnsured)", "maxTicks"="65534"!]U
[!// maxTicks covers CanSM.Design.20092
[!ENDIF!][!//

[!ENDIF!][!//

#if (defined CANSM_BOR_TIME_L1)
#error CANSM_BOR_TIME_L1 is already defined
#endif /* #if (defined CANSM_BOR_TIME_L1) */

/** \brief Duration to stay in level 1 check before restart of communication */
[!IF "$nwSpecificBorTimeL1 = 'true'"!][!//
#define CANSM_BOR_TIME_L1(nw) (CanSM_NetworkConfig[(nw)].BorTimeL1)
[!ELSE!][!//
#define CANSM_BOR_TIME_L1(nw) [!CALL "CalcToTicks", "time"="CanSMConfiguration/*[1]/CanSMManagerNetwork/*[1]/CanSMBorTimeL1", "maxTicks"="65535"!]U
[!// maxTicks covers CanSM.Design.20092
[!ENDIF!][!//

#if (defined CANSM_BOR_TIME_L2)
#error CANSM_BOR_TIME_L2 is already defined
#endif /* #if (defined CANSM_BOR_TIME_L2) */

/** \brief Duration to stay in level 2 check before restart of communication */
[!IF "$nwSpecificBorTimeL2 = 'true'"!][!//
#define CANSM_BOR_TIME_L2(nw) (CanSM_NetworkConfig[(nw)].BorTimeL2)
[!ELSE!][!//
#define CANSM_BOR_TIME_L2(nw) [!CALL "CalcToTicks", "time"="CanSMConfiguration/*[1]/CanSMManagerNetwork/*[1]/CanSMBorTimeL2", "maxTicks"="65535"!]U
[!// maxTicks covers CanSM.Design.20092
[!ENDIF!][!//

#if (defined CANSM_BOR_COUNTER_L1_TO_L2)
#error CANSM_BOR_COUNTER_L1_TO_L2 is already defined
#endif /* #if (defined CANSM_BOR_COUNTER_L1_TO_L2) */

/** \brief bus-off recovery L1 to L2 Threshold */
[!IF "$nwSpecificBorCounterL1ToL2 = 'true'"!][!//
#define CANSM_BOR_COUNTER_L1_TO_L2(nw) (CanSM_NetworkConfig[(nw)].BorCounterL1ToL2)
[!ELSE!][!//
#define CANSM_BOR_COUNTER_L1_TO_L2(nw) [!"CanSMConfiguration/*[1]/CanSMManagerNetwork/*[1]/CanSMBorCounterL1ToL2"!]U
[!ENDIF!][!//

#if (defined CANSM_BOR_TX_CONFIRMATION_POLLING)
#error CANSM_BOR_TX_CONFIRMATION_POLLING is already defined
#endif /* #if (defined CANSM_BOR_TX_CONFIRMATION_POLLING) */

/** \brief BOR Tx Confirmation Polling */
[!IF "$nwSpecificBorTxConfirmationPolling = 'true'"!][!//
#define CANSM_BOR_TX_CONFIRMATION_POLLING(nw) (CanSM_NetworkConfig[(nw)].BorTxConfirmationPolling)
[!ELSE!][!//
#define CANSM_BOR_TX_CONFIRMATION_POLLING(nw) [!//
[!IF "CanSMConfiguration/*[1]/CanSMManagerNetwork/*[1]/CanSMBorTxConfirmationPolling = 'true'"!][!//
TRUE
[!ELSE!][!//
FALSE
[!ENDIF!][!//
[!ENDIF!][!//

#if (defined CANSM_USE_CANIF_GETTXCONFIRMATIONSTATE)
#error CANSM_USE_CANIF_GETTXCONFIRMATIONSTATE is already defined
#endif /* #if (defined CANSM_USE_CANIF_GETTXCONFIRMATIONSTATE) */

/** \brief Use CanIf_GetTxConfirmationState API */
#define CANSM_USE_CANIF_GETTXCONFIRMATIONSTATE [!//
[!IF "($nwSpecificBorTxConfirmationPolling = 'true') or (CanSMConfiguration/*[1]/CanSMManagerNetwork/*[1]/CanSMBorTxConfirmationPolling = 'true')"!][!//
STD_ON
[!ELSE!][!//
STD_OFF
[!ENDIF!][!//

#if (defined CANSM_USE_BOR_TIME_TX_ENSURED)
#error CANSM_USE_BOR_TIME_TX_ENSURED is already defined
#endif /* #if (defined CANSM_USE_BOR_TIME_TX_ENSURED) */

/** \brief Use CanSMBorTimeTxEnsured for bus-off check */
#define CANSM_USE_BOR_TIME_TX_ENSURED [!IF "$useBorTimeTxEnsured = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

#if (defined CANSM_NETWORKS_NUM)
#error CANSM_NETWORKS_NUM is already defined
#endif /* #if (defined CANSM_NETWORKS_NUM) */

/** \brief number of networks used */
#define CANSM_NETWORKS_NUM [!"$numNetworks"!]U

#if (defined CANSM_CONTROLLERS_NUM)
#error CANSM_CONTROLLERS_NUM is already defined
#endif /* #if (defined CANSM_CONTROLLERS_NUM) */

/** \brief number of controllers used */
#define CANSM_CONTROLLERS_NUM [!"$numControllers"!]U

#if (defined CANSM_CONTROLLERS_ID_NUM)
#error CANSM_CONTROLLERS_ID_NUM is already defined
#endif /* #if (defined CANSM_CONTROLLERS_ID_NUM) */

/** \brief highest controller id used + 1 */
#define CANSM_CONTROLLERS_ID_NUM [!"num:i($ctrlMax + 1)"!]U

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
#define CANSM_TRANSCEIVERS_NUM [!"$numTransceivers"!]U

[!IF "$useTransceiver = 'true'"!]

#if (defined CANSM_TRANSCEIVERS_ID_NUM)
#error CANSM_TRANSCEIVERS_ID_NUM is already defined
#endif /* #if (defined CANSM_TRANSCEIVERS_ID_NUM) */

/** \brief highest transceiver id used + 1 */
#define CANSM_TRANSCEIVERS_ID_NUM [!"num:i($trcvMax + 1)"!]U

#if (defined CANSM_TRCVMODETYPE_NORMAL)
#error CANSM_TRCVMODETYPE_NORMAL is already defined
#endif /* #if (defined CANSM_TRCVMODETYPE_NORMAL) */

/** \brief CanSM_TransceiverModeIndication was last invoked with CANTRCV_TRCVMODE_NORMAL */
#define CANSM_TRCVMODETYPE_NORMAL 0U

#if (defined CANSM_TRCVMODETYPE_RESET)
#error CANSM_TRCVMODETYPE_RESET is already defined
#endif /* #if (defined CANSM_TRCVMODETYPE_RESET) */

/** \brief special value to indicate that CanSM_TransceiverModeIndication was not
 *  invoked with a meaningful value since last reset
 */
#define CANSM_TRCVMODETYPE_RESET 1U

#if (defined CANSM_TRCVMODETYPE_STANDBY)
#error CANSM_TRCVMODETYPE_STANDBY is already defined
#endif /* #if (defined CANSM_TRCVMODETYPE_STANDBY) */

/** \brief CanSM_TransceiverModeIndication was last invoked with CANTRCV_TRCVMODE_STANDBY */
#define CANSM_TRCVMODETYPE_STANDBY 2U

[!ENDIF!]

[!IF "$numNetworks = 1"!]
[!SELECT "CanSMConfiguration/*[1]/CanSMManagerNetwork/*[1]"!]

#if (defined CANSM_PARTIALNETWORKING)
#error CANSM_PARTIALNETWORKING is already defined
#endif /* #if (defined CANSM_PARTIALNETWORKING) */

/** \brief Partial networking */
#define CANSM_PARTIALNETWORKING(nw) [!IF "CanSMActivatePN = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!][!//

[!IF "$useTransceiver = 'true'"!]
/** \brief Transceiver id for given network */
#if (defined CANSM_NW_CONFIG_TRCV_ID)
#error CANSM_NW_CONFIG_TRCV_ID is already defined
#endif /* #if (defined CANSM_NW_CONFIG_TRCV_ID) */
[!IF "node:exists(CanSMTransceiverId)"!]
#define CANSM_NW_CONFIG_TRCV_ID(nw) [!"num:i(as:ref(CanSMTransceiverId)/CanIfTrcvId)"!]U
[!ELSE!]
#define CANSM_NW_CONFIG_TRCV_ID(nw) CANSM_TRANSCEIVER_ID_NONE
[!ENDIF!]
[!ENDIF!]

[!IF "$useDEM = 'true'"!]

#if (defined CANSM_NW_CONFIG_DEM_EVENT_ID_BUS_OFF)
#error CANSM_NW_CONFIG_DEM_EVENT_ID_BUS_OFF is already defined
#endif /* #if (defined CANSM_NW_CONFIG_DEM_EVENT_ID_BUS_OFF) */

/** \brief DEM Event to report bus off error for given network */
#define CANSM_NW_CONFIG_DEM_EVENT_ID_BUS_OFF(nw) [!//
[!IF "node:exists(CanSMDemEventParameterRefs/CANSM_E_BUS_OFF)"!][!//
[!"node:value(as:ref(CanSMDemEventParameterRefs/CANSM_E_BUS_OFF)/DemEventId)"!]U
[!ELSE!][!//
CANSM_INVALID_DEM_EVENTID /* Disabled for this network */
[!ENDIF!][!//
[!ENDIF!]

#if (defined CANSM_NW_HANDLE_IS_VALID)
#error CANSM_NW_HANDLE_IS_VALID is already defined
#endif /* #if (defined CANSM_NW_HANDLE_IS_VALID) */

/** \brief check if network handle is valid */
#define CANSM_NW_HANDLE_IS_VALID(nw) ((nw) == [!"num:i(as:ref(CanSMComMNetworkHandleRef)/ComMChannelId)"!]U)

#if (defined CANSM_NW_HANDLE_FROM_IDX)
#error CANSM_NW_HANDLE_FROM_IDX is already defined
#endif /* #if (defined CANSM_NW_HANDLE_FROM_IDX) */

/** \brief convert network array index to handle */
#define CANSM_NW_HANDLE_FROM_IDX(nw) ((NetworkHandleType)[!"num:i(as:ref(CanSMComMNetworkHandleRef)/ComMChannelId)"!]U)

[!ENDSELECT!]

#if (defined CANSM_NW_CONFIG_CTRL_START)
#error CANSM_NW_CONFIG_CTRL_START is already defined
#endif /* #if (defined CANSM_NW_CONFIG_CTRL_START) */

/** \brief Index of first controller of this network in controller list */
#define CANSM_NW_CONFIG_CTRL_START(nw) 0U

#if (defined CANSM_NW_CONFIG_CTRL_NUM)
#error CANSM_NW_CONFIG_CTRL_NUM is already defined
#endif /* #if (defined CANSM_NW_CONFIG_CTRL_NUM) */

/** \brief Number of controllers in this network */
#define CANSM_NW_CONFIG_CTRL_NUM(nw) [!"$numControllers"!]U

#if (defined CANSM_NW_IDX_FROM_HANDLE)
#error CANSM_NW_IDX_FROM_HANDLE is already defined
#endif /* #if (defined CANSM_NW_IDX_FROM_HANDLE) */

/** \brief convert network handle to array index */
#define CANSM_NW_IDX_FROM_HANDLE(nw) 0U

#if (defined CANSM_NW_CONFIG_CTRL)
#error CANSM_NW_CONFIG_CTRL is already defined
#endif /* #if (defined CANSM_NW_CONFIG_CTRL) */

[!IF "$singleControllers = 'true'"!]
/** \brief Get controller \a ctrl from controller list */
#define CANSM_NW_CONFIG_CTRL(ctrl) [!"num:i(as:ref(CanSMConfiguration/*[1]/CanSMManagerNetwork/*[1]/CanSMController/*[1]/CanSMControllerId)/CanIfCtrlId)"!]U
[!ELSE!]
/** \brief Get controller \a ctrl from controller list */
#define CANSM_NW_CONFIG_CTRL(ctrl) (CanSM_CanNetworkControllersList[(ctrl)])
[!ENDIF!]


[!ELSE!] [!/* IF "$numNetworks = 1" */!]

#if (defined CANSM_PARTIALNETWORKING)
#error CANSM_PARTIALNETWORKING is already defined
#endif /* #if (defined CANSM_PARTIALNETWORKING) */

/** \brief Partial networking */
#define CANSM_PARTIALNETWORKING(nw) (CanSM_NetworkConfig[(nw)].PartialNetworking)

[!IF "$useTransceiver = 'true'"!]

#if (defined CANSM_NW_CONFIG_TRCV_ID)
#error CANSM_NW_CONFIG_TRCV_ID is already defined
#endif /* #if (defined CANSM_NW_CONFIG_TRCV_ID) */

/** \brief Transceiver id for given network */
#define CANSM_NW_CONFIG_TRCV_ID(nw) (CanSM_NetworkConfig[(nw)].TrcvId)
[!ENDIF!]

[!IF "$useDEM = 'true'"!]

#if (defined CANSM_NW_CONFIG_DEM_EVENT_ID_BUS_OFF)
#error CANSM_NW_CONFIG_DEM_EVENT_ID_BUS_OFF is already defined
#endif /* #if (defined CANSM_NW_CONFIG_DEM_EVENT_ID_BUS_OFF) */

/** \brief DEM Event to report bus off error for given network */
#define CANSM_NW_CONFIG_DEM_EVENT_ID_BUS_OFF(nw) (CanSM_NetworkConfig[(nw)].EventIdBusOff)
[!ENDIF!]

[!IF "$singleControllers = 'true'"!]

#if (defined CANSM_NW_CONFIG_CTRL_START)
#error CANSM_NW_CONFIG_CTRL_START is already defined
#endif /* #if (defined CANSM_NW_CONFIG_CTRL_START) */

/** \brief Index of controller of this network */
#define CANSM_NW_CONFIG_CTRL_START(nw) (nw)

#if (defined CANSM_NW_CONFIG_CTRL_NUM)
#error CANSM_NW_CONFIG_CTRL_NUM is already defined
#endif /* #if (defined CANSM_NW_CONFIG_CTRL_NUM) */

/** \brief Number of controllers in this network */
#define CANSM_NW_CONFIG_CTRL_NUM(nw) 1U

#if (defined CANSM_NW_CONFIG_CTRL)
#error CANSM_NW_CONFIG_CTRL is already defined
#endif /* #if (defined CANSM_NW_CONFIG_CTRL) */

/** \brief Get controller \a ctrl from controller list */
#define CANSM_NW_CONFIG_CTRL(ctrl) (CanSM_NetworkConfig[(ctrl)].ControllerId)

[!ELSE!]

#if (defined CANSM_NW_CONFIG_CTRL_START)
#error CANSM_NW_CONFIG_CTRL_START is already defined
#endif /* #if (defined CANSM_NW_CONFIG_CTRL_START) */

/** \brief Index of first controller of this network in controller list */
#define CANSM_NW_CONFIG_CTRL_START(nw) (CanSM_CanNetworkControllersStart[(nw)])

#if (defined CANSM_NW_CONFIG_CTRL_NUM)
#error CANSM_NW_CONFIG_CTRL_NUM is already defined
#endif /* #if (defined CANSM_NW_CONFIG_CTRL_NUM) */

/** \brief Number of controllers in this network */
#define CANSM_NW_CONFIG_CTRL_NUM(nw) (CanSM_CanNetworkControllersNum[(nw)])

#if (defined CANSM_NW_CONFIG_CTRL)
#error CANSM_NW_CONFIG_CTRL is already defined
#endif /* #if (defined CANSM_NW_CONFIG_CTRL) */

/** \brief Get controller \a ctrl from controller list */
#define CANSM_NW_CONFIG_CTRL(ctrl) (CanSM_CanNetworkControllersList[(ctrl)])
[!ENDIF!]

#if (defined CANSM_NW_HANDLE_IS_VALID)
#error CANSM_NW_HANDLE_IS_VALID is already defined
#endif /* #if (defined CANSM_NW_HANDLE_IS_VALID) */

#if (defined CANSM_NW_IDX_FROM_HANDLE)
#error CANSM_NW_IDX_FROM_HANDLE is already defined
#endif /* #if (defined CANSM_NW_IDX_FROM_HANDLE) */

#if (defined CANSM_NW_HANDLE_FROM_IDX)
#error CANSM_NW_HANDLE_FROM_IDX is already defined
#endif /* #if (defined CANSM_NW_HANDLE_FROM_IDX) */

[!IF "$nwHandlesConsecutive = 'true'"!]
[!IF "$nwHandleOffset > 0"!]
/** \brief check if network handle is valid */
#define CANSM_NW_HANDLE_IS_VALID(nw) (((nw) >= [!"$nwHandleOffset"!]U) && ((nw) < [!"num:i($nwHandleOffset + $numNetworks)"!]U))

/** \brief convert network handle to array index */
#define CANSM_NW_IDX_FROM_HANDLE(nw) ((nw) - [!"$nwHandleOffset"!]U)

/** \brief convert network array index to handle */
#define CANSM_NW_HANDLE_FROM_IDX(nw) ((NetworkHandleType)((nw) + [!"$nwHandleOffset"!]U))
[!ELSE!]
/** \brief check if network handle is valid */
#define CANSM_NW_HANDLE_IS_VALID(nw) ((nw) < [!"num:i($nwHandleOffset + $numNetworks)"!]U)

/** \brief convert network handle to array index */
#define CANSM_NW_IDX_FROM_HANDLE(nw) (nw)

/** \brief convert network array index to handle */
#define CANSM_NW_HANDLE_FROM_IDX(nw) ((NetworkHandleType)(nw))
[!ENDIF!][!/* IF "$nwHandleOffset > 0" */!]
[!ELSE!]
/** \brief check if network handle is valid */
#define CANSM_NW_HANDLE_IS_VALID(nw) (CanSM_NetworkHandleIsValid(nw))

/** \brief convert network handle to array index */
#define CANSM_NW_IDX_FROM_HANDLE(nw) (CanSM_GetNetworkIndexFromHandle(nw))

/** \brief convert network array index to handle */
#define CANSM_NW_HANDLE_FROM_IDX(nw) (CanSM_GetNetworkHandleFromIndex(nw))
[!ENDIF!]
[!ENDIF!] [!/* IF "$numNetworks = 1" */!]


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

[!IF "$useTransceiver = 'true'"!]
#if (defined CANSM_NW_INFO_TRCVMODEINDICATION)
#error CANSM_NW_INFO_TRCVMODEINDICATION is already defined
#endif /* #if (defined CANSM_NW_INFO_TRCVMODEINDICATION) */

/** \brief access to last transceiver mode indication of network \a nw */
#define CANSM_NW_INFO_TRCVMODEINDICATION(nw) (CanSM_NetworkInfo[(nw)].TrcvModeIndication)
[!ENDIF!]

[!IF "$globalPnSupport = 'true'"!]
#if (defined CANSM_NW_INFO_TRCVCLEARWUFINDICATION)
#error CANSM_NW_INFO_TRCVCLEARWUFINDICATION is already defined
#endif /* #if (defined CANSM_NW_INFO_TRCVCLEARWUFINDICATION) */

/** \brief access to last CanSM_ClearTrcvWufFlagIndication of network \a nw */
#define CANSM_NW_INFO_TRCVCLEARWUFINDICATION(nw) (CanSM_NetworkInfo[(nw)].TrcvClearWUFIndication)

#if (defined CANSM_NW_INFO_TRCVCHECKWAKEFLAGINDICATION)
#error CANSM_NW_INFO_TRCVCHECKWAKEFLAGINDICATION is already defined
#endif /* #if (defined CANSM_NW_INFO_TRCVCHECKWAKEFLAGINDICATION) */

/** \brief access to last CanSM_CheckTransceiverWakeFlagIndication of network \a nw */
#define CANSM_NW_INFO_TRCVCHECKWAKEFLAGINDICATION(nw) (CanSM_NetworkInfo[(nw)].TrcvCheckWakeFlagIndication)
[!ENDIF!]

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

[!IF "$useTransceiver = 'true'"!]

#if (defined CANSM_NW_IDX_FROM_TRCV)
#error CANSM_NW_IDX_FROM_TRCV is already defined
#endif /* #if (defined CANSM_NW_IDX_FROM_TRCV) */

/** \brief Convert Transceiver id to array index for internal network data
*
* \param[in] trcv Transceiver Id
*
* \return The array index of the network, CANSM_NETWORKS_NUM on lookup failure
*/
#define CANSM_NW_IDX_FROM_TRCV(trcv) \
  ( (trcv) < CANSM_TRANSCEIVERS_ID_NUM ? CanSM_TrcvNetworkLut[(trcv)] : CANSM_NETWORKS_NUM )
[!ENDIF!]

/*==================[type definitions]======================================*/

[!IF "$numNetworks > 1"!]
/** \brief configuration data for one network */
typedef struct {
[!IF "$nwSpecificBorTimeL1 = 'true'"!]
  uint16 BorTimeL1; /**< Duration to stay in level 1 check before restart of communication
                       \note Since bus-off events occur asynchronous this value is incremented by
                       one (refer to design, CanSM.Design.20085) */
[!ENDIF!]
[!IF "$nwSpecificBorTimeL2 = 'true'"!]
  uint16 BorTimeL2; /**< Duration to stay in level 2 check before restart of communication
                       \note Since bus-off events occur asynchronous this value is incremented by
                       one (refer to design, CanSM.Design.20085) */
[!ENDIF!]
[!IF "$nwSpecificBorTimeTxEnsured = 'true'"!]
  uint16 BorTimeTxEnsured; /**< Duration until bus-off free communication is assumed */
[!ENDIF!]
[!IF "$useDEM = 'true'"!]
  Dem_EventIdType EventIdBusOff; /**< Event Id to be passed to Dem */
[!ENDIF!]
[!IF "$singleControllers = 'true'"!]
  uint8 ControllerId; /**< Id of CAN controller */
[!ENDIF!]
[!IF "$useTransceiver = 'true'"!]
  uint8 TrcvId; /**< ID of Transceiver */
[!ENDIF!]
[!IF "$nwSpecificBorCounterL1ToL2 = 'true'"!]
  uint8 BorCounterL1ToL2; /**< bus-off recovery L1 to L2 Threshold */
[!ENDIF!]
[!IF "$nwSpecificBorTxConfirmationPolling = 'true'"!]
  boolean BorTxConfirmationPolling; /**< bus-off recovery Tx Confirmation Polling */
[!ENDIF!]
[!IF "$globalPnSupport = 'true'"!]
  boolean PartialNetworking; /**< partial networking activated for this network */
[!ENDIF!]
} CanSM_NetworkConfigType;
[!ENDIF!]


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
[!IF "$numNetworks > 1"!]
#define CANSM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <MemMap.h>

/** \brief configuration of all networks */
extern CONST(CanSM_NetworkConfigType, CANSM_APPL_CONST) CanSM_NetworkConfig[CANSM_NETWORKS_NUM];

#define CANSM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <MemMap.h>
[!ENDIF!]

#define CANSM_START_SEC_CONFIG_DATA_8
#include <MemMap.h>

/** \brief Empty configuration structure to be passed to CanSM_Init() */
extern CONST(CanSM_ConfigType, CANSM_APPL_CONST) [!"as:modconf('CanSM')[1]/CanSMConfiguration/*[1]/@name"!];

[!IF "$singleControllers != 'true'"!]
/**
 * \brief start index of associated controllers in controller list
 *
 * index is network id.
 */
extern CONST(uint8, CANSM_APPL_CONST) CanSM_CanNetworkControllersStart[CANSM_NETWORKS_NUM];

/**
 * \brief number of controllers associated to a network
 *
 * index is network id.
 *
 * \note extra element at end of array to determine the end of controller list
 */
extern CONST(uint8, CANSM_APPL_CONST) CanSM_CanNetworkControllersNum[CANSM_NETWORKS_NUM];

/**
 * \brief all controllers of all networks (ordered)
 *
 * \note network association is given through CanSM_CanNetworkControllersStart
 */
extern CONST(uint8, CANSM_APPL_CONST) CanSM_CanNetworkControllersList[CANSM_CONTROLLERS_NUM];
[!ENDIF!]

/**
 * \brief controller to network handle lookup table
 *
 * \note may contain holes, these have the value CANSM_NETWORKS_NUM
 */
extern CONST(uint8, CANSM_APPL_CONST) CanSM_ControllerNetworkLut[CANSM_CONTROLLERS_ID_NUM];

[!IF "$useTransceiver = 'true'"!]
/**
 * \brief transceiver to network handle lookup table
 *
 * \note may contain holes, these have the value CANSM_NETWORKS_NUM
 */
extern CONST(uint8, CANSM_APPL_CONST) CanSM_TrcvNetworkLut[CANSM_TRANSCEIVERS_ID_NUM];
[!ENDIF!]

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

[!IF "($numNetworks > 1) and ($nwHandlesConsecutive = 'false')"!]

#define CANSM_START_SEC_CODE
#include <MemMap.h>

/** \brief Convert Network Handle to array index for internal data
 *
 * \pre validity of the network handle has been checked. Otherwise the
 *      return value is undefined
 *
 * \param[in] nw A valid network handle
 *
 * \return The array index of the network
 */

extern FUNC(CanSM_NetworkIndexType, CANSM_CODE) CanSM_GetNetworkIndexFromHandle(
  NetworkHandleType nw
);

/** \brief Convert Network Handle to array inedx for internal data
 *
 * \param[in] nwidx A valid network array index (not checked here)
 *
 * \return The handle of the network
 */
extern FUNC(NetworkHandleType, CANSM_CODE) CanSM_GetNetworkHandleFromIndex(
  CanSM_NetworkIndexType nwidx
);

/** \brief Check if Network Handle is valid
 *
 * \param[in] nw A network handle
 *
 * \retval FALSE The network handle is invalid
 * \retval TRUE The network handle is valid
 */
extern FUNC(boolean, CANSM_CODE) CanSM_NetworkHandleIsValid(
  NetworkHandleType nw
);

#define CANSM_STOP_SEC_CODE
#include <MemMap.h>

[!ENDIF!]

#endif /* if !defined( CANSM_CFG_H ) */
/*==================[end of file]===========================================*/

