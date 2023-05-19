
#if !defined(BSWM_TRACE_H)
#define BSWM_TRACE_H

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

/*==================[inclusions]============================================*/

/*==================[macros]================================================*/
#ifndef DBG_BSWM_INIT_ENTRY
/** \brief Entry point of function BswM_Init */
#define DBG_BSWM_INIT_ENTRY(a)
#endif

#ifndef DBG_BSWM_INIT_EXIT
/** \brief Exit point of function BswM_Init */
#define DBG_BSWM_INIT_EXIT(a)
#endif

#ifndef DBG_BSWM_GETVERSIONINFO_ENTRY
/** \brief Entry point of function BswM_GetVersionInfo */
#define DBG_BSWM_GETVERSIONINFO_ENTRY(a)
#endif

#ifndef DBG_BSWM_GETVERSIONINFO_EXIT
/** \brief Exit point of function BswM_GetVersionInfo */
#define DBG_BSWM_GETVERSIONINFO_EXIT(a)
#endif

#ifndef DBG_BSWM_DEINIT_ENTRY
/** \brief Entry point of function BswM_Deinit */
#define DBG_BSWM_DEINIT_ENTRY()
#endif

#ifndef DBG_BSWM_DEINIT_EXIT
/** \brief Exit point of function BswM_Deinit */
#define DBG_BSWM_DEINIT_EXIT()
#endif

#ifndef DBG_BSWM_REQUESTMODE_ENTRY
/** \brief Entry point of function BswM_RequestMode */
#define DBG_BSWM_REQUESTMODE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_REQUESTMODE_EXIT
/** \brief Exit point of function BswM_RequestMode */
#define DBG_BSWM_REQUESTMODE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_COMM_CURRENTMODE_ENTRY
/** \brief Entry point of function BswM_ComM_CurrentMode */
#define DBG_BSWM_COMM_CURRENTMODE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_COMM_CURRENTMODE_EXIT
/** \brief Exit point of function BswM_ComM_CurrentMode */
#define DBG_BSWM_COMM_CURRENTMODE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_COMM_CURRENTPNCMODE_ENTRY
/** \brief Entry point of function BswM_ComM_CurrentPNCMode */
#define DBG_BSWM_COMM_CURRENTPNCMODE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_COMM_CURRENTPNCMODE_EXIT
/** \brief Exit point of function BswM_ComM_CurrentPNCMode */
#define DBG_BSWM_COMM_CURRENTPNCMODE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_DCM_REQUESTCOMMUNICATIONMODE_ENTRY
/** \brief Entry point of function BswM_Dcm_RequestCommunicationMode */
#define DBG_BSWM_DCM_REQUESTCOMMUNICATIONMODE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_DCM_REQUESTCOMMUNICATIONMODE_EXIT
/** \brief Exit point of function BswM_Dcm_RequestCommunicationMode */
#define DBG_BSWM_DCM_REQUESTCOMMUNICATIONMODE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_DCM_COMMUNICATIONMODE_CURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_Dcm_CommunicationMode_CurrentState */
#define DBG_BSWM_DCM_COMMUNICATIONMODE_CURRENTSTATE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_DCM_COMMUNICATIONMODE_CURRENTSTATE_EXIT
/** \brief Exit point of function BswM_Dcm_CommunicationMode_CurrentState */
#define DBG_BSWM_DCM_COMMUNICATIONMODE_CURRENTSTATE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_DCM_REQUESTSESSIONMODE_ENTRY
/** \brief Entry point of function BswM_Dcm_RequestSessionMode */
#define DBG_BSWM_DCM_REQUESTSESSIONMODE_ENTRY(a)
#endif

#ifndef DBG_BSWM_DCM_REQUESTSESSIONMODE_EXIT
/** \brief Exit point of function BswM_Dcm_RequestSessionMode */
#define DBG_BSWM_DCM_REQUESTSESSIONMODE_EXIT(a)
#endif

#ifndef DBG_BSWM_DCM_REQUESTRESETMODE_ENTRY
/** \brief Entry point of function BswM_Dcm_RequestResetMode */
#define DBG_BSWM_DCM_REQUESTRESETMODE_ENTRY(a)
#endif

#ifndef DBG_BSWM_DCM_REQUESTRESETMODE_EXIT
/** \brief Exit point of function BswM_Dcm_RequestResetMode */
#define DBG_BSWM_DCM_REQUESTRESETMODE_EXIT(a)
#endif

#ifndef DBG_BSWM_DCM_APPLICATIONUPDATED_ENTRY
/** \brief Exit point of function BswM_Dcm_ApplicationUpdated */
#define DBG_BSWM_DCM_APPLICATIONUPDATED_ENTRY()
#endif

#ifndef DBG_BSWM_DCM_APPLICATIONUPDATED_EXIT
/** \brief Exit point of function BswM_Dcm_ApplicationUpdated */
#define DBG_BSWM_DCM_APPLICATIONUPDATED_EXIT()
#endif

#ifndef DBG_BSWM_CANSM_CURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_CanSM_CurrentState */
#define DBG_BSWM_CANSM_CURRENTSTATE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_CANSM_CURRENTSTATE_EXIT
/** \brief Exit point of function BswM_CanSM_CurrentState */
#define DBG_BSWM_CANSM_CURRENTSTATE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_ETHIF_PORTGROUPLINKSTATECHG_ENTRY
/** \brief Entry point of function BswM_EthIf_PortGroupLinkStateChg */
#define DBG_BSWM_ETHIF_PORTGROUPLINKSTATECHG_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_ETHIF_PORTGROUPLINKSTATECHG_EXIT
/** \brief Exit point of function BswM_EthIf_PortGroupLinkStateChg */
#define DBG_BSWM_ETHIF_PORTGROUPLINKSTATECHG_EXIT(a,b)
#endif

#ifndef DBG_BSWM_ETHSM_CURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_EthSM_CurrentState */
#define DBG_BSWM_ETHSM_CURRENTSTATE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_ETHSM_CURRENTSTATE_EXIT
/** \brief Exit point of function BswM_EthSM_CurrentState */
#define DBG_BSWM_ETHSM_CURRENTSTATE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_FRSM_CURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_FrSM_CurrentState */
#define DBG_BSWM_FRSM_CURRENTSTATE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_FRSM_CURRENTSTATE_EXIT
/** \brief Exit point of function BswM_FrSM_CurrentState */
#define DBG_BSWM_FRSM_CURRENTSTATE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_LINSM_CURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_LinSM_CurrentState */
#define DBG_BSWM_LINSM_CURRENTSTATE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_LINSM_CURRENTSTATE_EXIT
/** \brief Exit point of function BswM_LinSM_CurrentState */
#define DBG_BSWM_LINSM_CURRENTSTATE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_ECUM_CURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_EcuM_CurrentState */
#define DBG_BSWM_ECUM_CURRENTSTATE_ENTRY(a)
#endif

#ifndef DBG_BSWM_ECUM_CURRENTSTATE_EXIT
/** \brief Exit point of function BswM_EcuM_CurrentState */
#define DBG_BSWM_ECUM_CURRENTSTATE_EXIT(a)
#endif

#ifndef DBG_BSWM_ECUM_CURRENTWAKEUP_ENTRY
/** \brief Entry point of function BswM_EcuM_CurrentWakeup */
#define DBG_BSWM_ECUM_CURRENTWAKEUP_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_ECUM_CURRENTWAKEUP_EXIT
/** \brief Exit point of function BswM_EcuM_CurrentWakeup */
#define DBG_BSWM_ECUM_CURRENTWAKEUP_EXIT(a,b)
#endif

#ifndef DBG_BSWM_NVM_CURRENTBLOCKMODE_ENTRY
/** \brief Entry point of function BswM_NvM_CurrentBlockMode */
#define DBG_BSWM_NVM_CURRENTBLOCKMODE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_NVM_CURRENTBLOCKMODE_EXIT
/** \brief Exit point of function BswM_NvM_CurrentBlockMode */
#define DBG_BSWM_NVM_CURRENTBLOCKMODE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_NVM_CURRENTJOBMODE_ENTRY
/** \brief Entry point of function BswM_NvM_CurrentJobMode */
#define DBG_BSWM_NVM_CURRENTJOBMODE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_NVM_CURRENTJOBMODE_EXIT
/** \brief Exit point of function BswM_NvM_CurrentJobMode */
#define DBG_BSWM_NVM_CURRENTJOBMODE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_LINSM_CURRENTSCHEDULE_ENTRY
/** \brief Entry point of function BswM_LinSM_CurrentSchedule */
#define DBG_BSWM_LINSM_CURRENTSCHEDULE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_LINSM_CURRENTSCHEDULE_EXIT
/** \brief Exit point of function BswM_LinSM_CurrentSchedule */
#define DBG_BSWM_LINSM_CURRENTSCHEDULE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_LINTP_REQUESTMODE_ENTRY
/** \brief Entry point of function BswM_LinTp_RequestMode */
#define DBG_BSWM_LINTP_REQUESTMODE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_LINTP_REQUESTMODE_EXIT
/** \brief Exit point of function BswM_LinTp_RequestMode */
#define DBG_BSWM_LINTP_REQUESTMODE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_SD_CLIENTSERVICECURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_Sd_ClientServiceCurrentState */
#define DBG_BSWM_SD_CLIENTSERVICECURRENTSTATE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_SD_CLIENTSERVICECURRENTSTATE_EXIT
/** \brief Exit point of function BswM_Sd_ClientServiceCurrentState */
#define DBG_BSWM_SD_CLIENTSERVICECURRENTSTATE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_SD_CONSUMEDEVENTGROUPCURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_Sd_ConsumedEventGroupCurrentState */
#define DBG_BSWM_SD_CONSUMEDEVENTGROUPCURRENTSTATE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_SD_CONSUMEDEVENTGROUPCURRENTSTATE_EXIT
/** \brief Exit point of function BswM_Sd_ConsumedEventGroupCurrentState */
#define DBG_BSWM_SD_CONSUMEDEVENTGROUPCURRENTSTATE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_SD_EVENTHANDLERCURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_Sd_EventHandlerCurrentState */
#define DBG_BSWM_SD_EVENTHANDLERCURRENTSTATE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_SD_EVENTHANDLERCURRENTSTATE_EXIT
/** \brief Exit point of function BswM_Sd_EventHandlerCurrentState */
#define DBG_BSWM_SD_EVENTHANDLERCURRENTSTATE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_WDGM_REQUESTPARTITIONRESET_ENTRY
/** \brief Entry point of function BswM_WdgM_RequestPartitionReset */
#define DBG_BSWM_WDGM_REQUESTPARTITIONRESET_ENTRY(a)
#endif

#ifndef DBG_BSWM_WDGM_REQUESTPARTITIONRESET_EXIT
/** \brief Exit point of function BswM_WdgM_RequestPartitionReset */
#define DBG_BSWM_WDGM_REQUESTPARTITIONRESET_EXIT(a)
#endif

#ifndef DBG_BSWM_TRIGGERSTARTUPPHASE2_ENTRY
/** \brief Entry point of function BswM_TriggerStartUpPhase2 */
#define DBG_BSWM_TRIGGERSTARTUPPHASE2_ENTRY(a)
#endif

#ifndef DBG_BSWM_TRIGGERSTARTUPPHASE2_EXIT
/** \brief Exit point of function BswM_TriggerStartUpPhase2 */
#define DBG_BSWM_TRIGGERSTARTUPPHASE2_EXIT(a,b)
#endif

#ifndef DBG_BSWM_TRIGGERSLAVERTESTOP_ENTRY
/** \brief Entry point of function BswM_TriggerSlaveRTEStop */
#define DBG_BSWM_TRIGGERSLAVERTESTOP_ENTRY(a)
#endif

#ifndef DBG_BSWM_TRIGGERSLAVERTESTOP_EXIT
/** \brief Exit point of function BswM_TriggerSlaveRTEStop */
#define DBG_BSWM_TRIGGERSLAVERTESTOP_EXIT(a,b)
#endif

#ifndef DBG_BSWM_MAINFUNCTION_ENTRY
/** \brief Entry point of function BswM_MainFunction */
#define DBG_BSWM_MAINFUNCTION_ENTRY()
#endif

#ifndef DBG_BSWM_MAINFUNCTION_EXIT
/** \brief Exit point of function BswM_MainFunction */
#define DBG_BSWM_MAINFUNCTION_EXIT()
#endif

#ifndef DBG_BSWM_CORE_INIT_ENTRY
/** \brief Entry point of function BswM_Core_Init */
#define DBG_BSWM_CORE_INIT_ENTRY()
#endif

#ifndef DBG_BSWM_CORE_INIT_EXIT
/** \brief Exit point of function BswM_Core_Init */
#define DBG_BSWM_CORE_INIT_EXIT()
#endif

#ifndef DBG_BSWM_PARTITION_INIT_ENTRY
/** \brief Entry point of function BswM_Partition_Init */
#define DBG_BSWM_PARTITION_INIT_ENTRY(a)
#endif

#ifndef DBG_BSWM_PARTITION_INIT_EXIT
/** \brief Exit point of function BswM_Partition_Init */
#define DBG_BSWM_PARTITION_INIT_EXIT(a)
#endif

#ifndef DBG_BSWM_PB_INIT_ENTRY
/** \brief Entry point of function BswM_PB_Init */
#define DBG_BSWM_PB_INIT_ENTRY(a,b,c)
#endif

#ifndef DBG_BSWM_PB_INIT_EXIT
/** \brief Exit point of function BswM_PB_Init */
#define DBG_BSWM_PB_INIT_EXIT(a,b,c,d)
#endif

#ifndef DBG_BSWM_RT_INIT_ENTRY
/** \brief Entry point of function BswM_RT_Init */
#define DBG_BSWM_RT_INIT_ENTRY(a)
#endif

#ifndef DBG_BSWM_RT_INIT_EXIT
/** \brief Exit point of function BswM_RT_Init */
#define DBG_BSWM_RT_INIT_EXIT(a)
#endif

#ifndef DBG_BSWM_LT_INIT_ENTRY
/** \brief Entry point of function BswM_LT_Init */
#define DBG_BSWM_LT_INIT_ENTRY()
#endif

#ifndef DBG_BSWM_LT_INIT_EXIT
/** \brief Exit point of function BswM_LT_Init */
#define DBG_BSWM_LT_INIT_EXIT()
#endif

/* Dynamically generated macros */
#ifndef DBG_BSWM_ACTION_BSWMACTION_COMM_ALLOW_CAN_ENTRY
/** \brief Entry point of function BswM_Action_BswMAction_ComM_Allow_CAN */
#define DBG_BSWM_ACTION_BSWMACTION_COMM_ALLOW_CAN_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_COMM_ALLOW_CAN_EXIT
/** \brief Exit point of function BswM_Action_BswMAction_ComM_Allow_CAN */
#define DBG_BSWM_ACTION_BSWMACTION_COMM_ALLOW_CAN_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_COMM_DONOTALLOW_CAN_ENTRY
/** \brief Entry point of function BswM_Action_BswMAction_ComM_DoNotAllow_CAN */
#define DBG_BSWM_ACTION_BSWMACTION_COMM_DONOTALLOW_CAN_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_COMM_DONOTALLOW_CAN_EXIT
/** \brief Exit point of function BswM_Action_BswMAction_ComM_DoNotAllow_CAN */
#define DBG_BSWM_ACTION_BSWMACTION_COMM_DONOTALLOW_CAN_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_COMM_SWITCHON_CAN_ENTRY
/** \brief Entry point of function BswM_Action_BswMAction_ComM_SwitchOn_CAN */
#define DBG_BSWM_ACTION_BSWMACTION_COMM_SWITCHON_CAN_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_COMM_SWITCHON_CAN_EXIT
/** \brief Exit point of function BswM_Action_BswMAction_ComM_SwitchOn_CAN */
#define DBG_BSWM_ACTION_BSWMACTION_COMM_SWITCHON_CAN_EXIT(a)
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_COMM_SWITCHOFF_CAN_ENTRY
/** \brief Entry point of function BswM_Action_BswMAction_ComM_SwitchOff_CAN */
#define DBG_BSWM_ACTION_BSWMACTION_COMM_SWITCHOFF_CAN_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_COMM_SWITCHOFF_CAN_EXIT
/** \brief Exit point of function BswM_Action_BswMAction_ComM_SwitchOff_CAN */
#define DBG_BSWM_ACTION_BSWMACTION_COMM_SWITCHOFF_CAN_EXIT(a)
#endif

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[external data]=========================================*/

/*==================[end of file]===========================================*/
/** @} doxygen end group definition */
#endif /* !defined(BSWM_TRACE_H) */
/*==================[end of file]============================================*/

