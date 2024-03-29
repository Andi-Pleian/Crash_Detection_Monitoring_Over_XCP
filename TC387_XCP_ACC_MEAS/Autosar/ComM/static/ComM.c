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


/* !LINKSTO ComM463_Refine_ComMc,1 */

/*
 * MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 20.7 (required)
 * Expressions resulting from the expansion of macro parameters shall be enclosed in parentheses.
 *
 * Reason:
 * The macro is used in function parameter declarations and definitions of structure member
 * where the number of parentheses matter.
 *
 * MISRAC2012-2) Deviated Rule: 8.9 (advisory)
 * An object should be defined at block scope if its identifier only appears in a single function.
 *
 * Reason:
 * The object has internal linkage for readability improvement.
 */

 /*==================[inclusions]============================================*/

#include <ComM_Trace.h>
/* !LINKSTO ComM466,1 */
#include <TSAutosar.h>          /* EB specific standard types */
#include <TSMem.h>

#include <ComM.h>               /* ComM API definitions (own interface) */
#include <ComM_BSW.h>           /* Module specific public APIs */

#if (COMM_NM_ACCESS_NEEDED == STD_ON)
#include <ComM_Nm.h>            /* NM callback APIs */
#endif

#if (COMM_DCM_ENABLED == STD_ON)
#include <ComM_Dcm.h>           /* DCM callback APIs */
#endif

#include <ComM_EcuMBswM.h>      /* ECUM and BSWM callback APIs */
#include <ComM_BusSm.h>         /* Bus State manager callback APIs */

#include <ComM_BSW_Cfg.h>      /* Module internal BSW specific interface */
#include <ComM_Int.h>           /* Internal Rte proxy function declarations */

#if (COMM_NVM_ENABLED == STD_ON)
/* !LINKSTO ComM506_Refine_NvM,1 */
#include <NvM.h>                /* Memory Access APIs */
#endif

/* !LINKSTO ComM506_Refine_CanSM,1 */
#if (COMM_CANSM_ACCESS_NEEDED == STD_ON)
#include <CanSM_ComM.h>        /* Can state manager */
#endif

/* !LINKSTO ComM506_Refine_FrSM,1 */
#if (COMM_FRSM_ACCESS_NEEDED == STD_ON)
#include <FrSM.h>              /* Flexray state manager */
#endif

/* !LINKSTO ComM506_Refine_LinSM,1 */
#if (COMM_LINSM_ACCESS_NEEDED == STD_ON)
#include <LinSM.h>             /* Lin state manager */
#endif
/* !LINKSTO ComM506_Refine_EthSM,1 */
#if (COMM_ETHSM_ACCESS_NEEDED == STD_ON)
#include <EthSM.h>             /* Eth state manager */
#endif

#if (COMM_DEV_ERROR_DETECT == STD_ON)
/* !LINKSTO ComM506_Refine_Det,1 */
#include <Det.h>                /* Det API */
#endif

#if (COMM_INCLUDE_RTE == STD_ON)
#include <ComM_Rte_Cfg.h>  /* internal Rte config dependent header */
#endif

/* for the case COMM_INCLUDE_RTE == STD_OFF these symbols are provided via
 * ComM.h. */

/*==================[macros]================================================*/

/* !LINKSTO ComM.Version.Check,1 */
/*------------------[AUTOSAR vendor identification check]-------------------*/

#if (!defined COMM_VENDOR_ID) /* configuration check */
#error COMM_VENDOR_ID must be defined
#endif

#if (COMM_VENDOR_ID != 1U) /* vendor check */
#error COMM_VENDOR_ID has wrong vendor id
#endif

/*------------------[AUTOSAR release version identification check]----------*/

#if (!defined COMM_AR_RELEASE_MAJOR_VERSION) /* configuration check */
#error COMM_AR_RELEASE_MAJOR_VERSION must be defined
#endif

/* major version check */
#if (COMM_AR_RELEASE_MAJOR_VERSION != 4U)
#error COMM_AR_RELEASE_MAJOR_VERSION wrong (!= 4U)
#endif

#if (!defined COMM_AR_RELEASE_MINOR_VERSION) /* configuration check */
#error COMM_AR_RELEASE_MINOR_VERSION must be defined
#endif

/* minor version check */
#if (COMM_AR_RELEASE_MINOR_VERSION != 0U )
#error COMM_AR_RELEASE_MINOR_VERSION wrong (!= 0U)
#endif

#if (!defined COMM_AR_RELEASE_REVISION_VERSION) /* configuration check */
#error COMM_AR_RELEASE_REVISION_VERSION must be defined
#endif

/* revision version check */
#if (COMM_AR_RELEASE_REVISION_VERSION != 3U )
#error COMM_AR_RELEASE_REVISION_VERSION wrong (!= 3U)
#endif

/*------------------[AUTOSAR module version identification check]-----------*/

#if (!defined COMM_SW_MAJOR_VERSION) /* configuration check */
#error COMM_SW_MAJOR_VERSION must be defined
#endif

/* major version check */
#if (COMM_SW_MAJOR_VERSION != 5U)
#error COMM_SW_MAJOR_VERSION wrong (!= 5U)
#endif

#if (!defined COMM_SW_MINOR_VERSION) /* configuration check */
#error COMM_SW_MINOR_VERSION must be defined
#endif

/* minor version check */
#if (COMM_SW_MINOR_VERSION < 17U)
#error COMM_SW_MINOR_VERSION wrong (< 17U)
#endif

#if (!defined COMM_SW_PATCH_VERSION) /* configuration check */
#error COMM_SW_PATCH_VERSION must be defined
#endif

/* patch version check */
#if (COMM_SW_PATCH_VERSION < 2U)
#error COMM_SW_PATCH_VERSION wrong (< 2U)
#endif

/*--------------------------------------------------------------------------*/
/* !LINKSTO ComM103_Refine,1 */
#if (defined COMM_PERS_DATA_MODIFIED)
#error COMM_PERS_DATA_MODIFIED already defined
#endif
#if ((COMM_NVM_ENABLED == STD_ON) &&                \
     ((COMM_MODE_LIMITATION_ENABLED == STD_ON) || (COMM_WAKEUP_INHIBITION_ENABLED == STD_ON)))
#define COMM_PERS_DATA_MODIFIED()                                      \
        ((void) NvM_SetRamBlockStatus(COMM_NVM_BLOCK_DESCRIPTOR, TRUE))
#else
#define COMM_PERS_DATA_MODIFIED()
#endif

/** \brief ID for the invalid event */
#if (defined COMM_EVENT_INVALID)
#error COMM_EVENT_INVALID already defined
#endif
#define COMM_EVENT_INVALID                  255U

/** \brief Set an event for a specific ComM channel */
#if (defined COMM_EMIT)
#error COMM_EMIT already defined
#endif
#define COMM_EMIT(a,b) (void)COMM_HSMEMITINST(&ComM_HsmScComM, a, b)

/** \brief Set an event for a specific ComM PN Channel */
#if (defined COMM_PNC_EMIT)
#error COMM_PNC_EMIT already defined
#endif
#define COMM_PNC_EMIT(a,b) (void)COMM_HSMEMITINST(&ComM_HsmScComMPnc, a, b)

/*--------------------------------------------------------------------------*/
#if (defined COMM_BUSSM_GET_CURRENT_COM_MODE)
#error COMM_BUSSM_GET_CURRENT_COM_MODE already defined
#endif
#if (COMM_NUM_USERS != 0U)
/** \brief Call wrapper for bus state manager function
 * <Bus>SM_GetCurrentComMode() */
#define COMM_BUSSM_GET_CURRENT_COM_MODE(channel, mode)                  \
  (ComM_BusSMGetCurrentComModeFpList[COMM_BUSTYPE_OF_CHANNEL(channel)]((channel), (mode)))
#endif

/*--------------------------------------------------------------------------*/

/* Macro for Det checks of channel identifier as function argument */
#if (defined COMM_IS_CHANNEL_INVALID)
#error COMM_IS_CHANNEL_INVALID already defined
#endif
#if ((COMM_NM_VARIANT_NONE_NEEDED == STD_ON) && (COMM_NM_VARIANT_LIGHT_NEEDED == STD_ON))
#define COMM_IS_CHANNEL_INVALID(Channel)                               \
        ((((Channel) >= COMM_NUM_CHANNELS) ||                                   \
          (COMM_NM_VARIANT_OF_CHANNEL(Channel) == COMM_NM_NONE_VARIANT)       \
         ) ||                                                                 \
         (COMM_NM_VARIANT_OF_CHANNEL(Channel) == COMM_NM_LIGHT_VARIANT)       \
        )
#elif ((COMM_NM_VARIANT_NONE_NEEDED == STD_ON) && (COMM_NM_VARIANT_LIGHT_NEEDED == STD_OFF))
#define COMM_IS_CHANNEL_INVALID(Channel)                               \
        (((Channel) >= COMM_NUM_CHANNELS) ||                                    \
         (COMM_NM_VARIANT_OF_CHANNEL(Channel) == COMM_NM_NONE_VARIANT)        \
        )
#elif ((COMM_NM_VARIANT_NONE_NEEDED == STD_OFF) && (COMM_NM_VARIANT_LIGHT_NEEDED == STD_ON))
#define COMM_IS_CHANNEL_INVALID(Channel)                               \
        (((Channel) >= COMM_NUM_CHANNELS) ||                                    \
         (COMM_NM_VARIANT_OF_CHANNEL(Channel) == COMM_NM_LIGHT_VARIANT)       \
        )
#else
#define COMM_IS_CHANNEL_INVALID(Channel) ((Channel) >= COMM_NUM_CHANNELS)
#endif

/*==================[type definitions]======================================*/

/** \brief Function pointer type for the bus state manager functions to
 ** query the current communication mode. */
typedef P2FUNC(Std_ReturnType, COMM_APPL_CODE, ComM_BusSMGetCurrentComModeType)
(
  NetworkHandleType                       Channel,
  P2VAR(uint8, AUTOMATIC, COMM_APPL_DATA) ComMode
);


/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/
#if (COMM_PNC_SUPPORT == STD_ON)
#define COMM_START_SEC_CODE
#include <MemMap.h>

/** \brief Updates Rx(EIRA/ERA) arrays
 **
 ** This functions reads the RX signal values from Com and updates RxEira or RxEra arrays
 **
 ** \param[in,out] SignalStatusPtr notification if EIRA or ERA RX signals where updated
 ** \param[in]     SignalConfigurationPtr List of EIRA or ERA RX signals
 ** \param[in,out] SignalMergedPtr received EIRA or ERA merged (RxEira, RxEra)
 ** \param[in]     MaskPtr Mask sets for every signal on each PNC
 ** \param[in]     isEira Is EIRA or ERA signal set is processed (EIRA if isEira is set to true)
 */
STATIC FUNC(void, COMM_CODE) ComM_ProcessPncComSignals
(
  CONSTP2VAR(boolean, AUTOMATIC, COMM_VAR) SignalStatusPtr,
  CONSTP2CONST(Com_SignalIdType, AUTOMATIC, COMM_VAR) SignalConfigurationPtr,
  CONSTP2VAR(uint8, AUTOMATIC, COMM_VAR) SignalMergedPtr,
  /* Deviation MISRAC2012-1 */
  CONSTP2CONST(P2CONST(uint8, COMM_CONST, COMM_CONST), COMM_CONST, COMM_CONST) MaskPtr,
  boolean isEira
);
/** \brief Handle EcuM PNC wakeup indication
 **
 ** This functions handle PNC wakeup indication following a EcuM PNC wakeup request. 
 **
 ** \param[in] Index of the PNC for which wakeup indication was received.
 */
STATIC FUNC(void,COMM_CODE) ComM_PNCWakeUpIndication_PncHandle(const uint8 pncIdx);

/** \brief Handle EcuM PNC wakeup indication.
 **
 ** This functions handle channels passive wakeup, following a EcuM PNC wakeup request. 
 **
 ** \param[in] Index of the PNC for which wakeup indication was received.
 */
STATIC FUNC(void,COMM_CODE) ComM_PNCWakeUpIndication_ChannelHandle(const uint8 pncIdx);
#define COMM_STOP_SEC_CODE
#include <MemMap.h>
#endif
/*==================[external constants]====================================*/

#define COMM_START_SEC_CONST_8
#include <MemMap.h>

#if (COMM_BUSTYPE_OF_CHANNEL_DYNAMIC == STD_ON)
CONST(uint8, COMM_CONST) ComM_BusTypeOfChannel[COMM_NUM_CHANNELS]
  = COMM_BUSTYPE_OF_CHANNEL_INIT;
#endif

#if (COMM_NM_VARIANT_OF_CHANNEL_DYNAMIC == STD_ON)
CONST(uint8, COMM_CONST) ComM_NmVariantOfChannel[COMM_NUM_CHANNELS]
  = COMM_NM_VARIANT_OF_CHANNEL_INIT;
#endif

#define COMM_STOP_SEC_CONST_8
#include <MemMap.h>

/*==================[internal constants]====================================*/
#if (COMM_NUM_USERS != 0U)

#define COMM_START_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/** \brief Stores function pointer for bus specific state managers **/
/* Deviation MISRAC2012-2 */
STATIC CONST(ComM_BusSMGetCurrentComModeType, COMM_CONST)
  ComM_BusSMGetCurrentComModeFpList[5] =
{
#if (COMM_CANSM_ACCESS_NEEDED == STD_ON)
  &CanSM_GetCurrentComMode,      /* COMM_BUS_TYPE_CAN = 0 */
#else
  NULL_PTR,                /* never accessed if no CAN channel is available */
#endif
#if (COMM_ETHSM_ACCESS_NEEDED == STD_ON)
  &EthSM_GetCurrentComMode,      /* COMM_BUS_TYPE_ETH = 1 */
#else
  NULL_PTR,                /* never accessed if no CAN channel is available */
#endif
#if (COMM_FRSM_ACCESS_NEEDED == STD_ON)
  &FrSM_GetCurrentComMode,       /* COMM_BUS_TYPE_FR = 2 */
#else
  NULL_PTR,                 /* never accessed if no FR channel is available */
#endif
  NULL_PTR,                   /* COMM_BUS_TYPE_INTERNAL = 3 */
#if (COMM_LINSM_ACCESS_NEEDED == STD_ON)
  &LinSM_GetCurrentComMode      /* COMM_BUS_TYPE_LIN = 4 */
#else
  NULL_PTR                /* never accessed if no LIN channel is available */
#endif
};

#define COMM_STOP_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

#endif

/*==================[external data]=========================================*/

#define COMM_START_SEC_VAR_NO_INIT_8
#include <MemMap.h>

#if (COMM_DCM_ENABLED == STD_ON)
VAR(uint8, COMM_VAR)         ComM_DcmActiveStatus[COMM_NUM_CHANNELS_BYTES];
#endif /* if (COMM_DCM_ENABLED == STD_ON) */

VAR(uint8, COMM_VAR) ComM_Communication_Allowed[COMM_NUM_CHANNELS_BYTES];

VAR(ComM_ASR40_ModeType, COMM_VAR)   ComM_RequestedComMode[COMM_NUM_CHANNELS];

VAR(ComM_ASR40_ModeType, COMM_VAR)   ComM_ChannelMode[COMM_NUM_CHANNELS];

#if (COMM_MODE_LIMITATION_ENABLED == STD_ON)
VAR(ComM_ASR40_ModeType, COMM_VAR)   ComM_ChannelModePrevious[COMM_NUM_CHANNELS];
#endif

VAR(ComM_StateType, COMM_VAR)  ComM_ChanState[COMM_NUM_CHANNELS];

VAR(ComM_ASR40_ModeType, COMM_VAR) ComM_UserRequestedComMode[USER_ARRAY_SIZE];


#if (COMM_PNC_SUPPORT == STD_ON)

VAR(ComM_ASR40_ModeType, COMM_VAR) ComM_PNCRequestedComMode[COMM_NUM_PNC];

/* !LINKSTO ComM982,1 */
VAR(uint8, COMM_VAR) ComM_TxEiraEra[COMM_PN_INFO_LENGTH];
VAR(uint8, COMM_VAR) ComM_RxEira[COMM_PN_INFO_LENGTH];
#if(COMM_PNC_GW_ENABLED == STD_ON)
VAR(uint8, COMM_VAR) ComM_RxEra[COMM_PN_INFO_LENGTH];
#endif

VAR(boolean, COMM_VAR) ComM_RxEiraSignalStatus;
#if(COMM_PNC_GW_ENABLED == STD_ON)
VAR(boolean, COMM_VAR) ComM_RxEraSignalStatus;
VAR(ComM_PncModeType, COMM_VAR)   ComM_PncStateGWE[COMM_NUM_PNC];
#endif


#endif /* if (COMM_PNC_SUPPORT == STD_ON) */

#if (COMM_INCLUDE_RTE == STD_ON)
VAR(boolean, COMM_VAR) ComM_RteNotificationSuccessful[USER_ARRAY_SIZE];

#endif /* #if (COMM_INCLUDE_RTE == STD_ON) */

#define COMM_STOP_SEC_VAR_NO_INIT_8
#include <MemMap.h>

#define COMM_START_SEC_VAR_INIT_8
#include <MemMap.h>

VAR(ComM_InitStatusType, COMM_VAR) ComM_InitStatus = COMM_UNINIT;

#define COMM_STOP_SEC_VAR_INIT_8
#include <MemMap.h>

#define COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include <MemMap.h>

#if ((COMM_MODE_LIMITATION_ENABLED == STD_ON) \
     || (COMM_WAKEUP_INHIBITION_ENABLED == STD_ON))
VAR(ComM_NvDataType, COMM_VAR) ComM_EB_NvRAM;
#endif

P2CONST(ComM_ConfigType,AUTOMATIC,COMM_APPL_CONST) ComM_ConfigPtr;

#define COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include <MemMap.h>

/*==================[internal data]=========================================*/

#define COMM_START_SEC_VAR_NO_INIT_8
#include <MemMap.h>

#if (COMM_MODE_LIMITATION_ENABLED == STD_ON)
/** \brief Array to store NoCom Inhibition status of ComM Channels. */
STATIC VAR(uint8, COMM_VAR) ComM_ChannelNoComInhibition[COMM_NUM_BYTES_NVM];
#endif

#if (COMM_WAKEUP_INHIBITION_ENABLED == STD_ON)
/** \brief Array to store WakeUp Inhibition status of ComM Channels. */
STATIC VAR(uint8, COMM_VAR) ComM_ChannelWakeUpInhibition[COMM_NUM_BYTES_NVM];
#endif

#define COMM_STOP_SEC_VAR_NO_INIT_8
#include <MemMap.h>

/*==================[external function definitions]=========================*/

#define COMM_START_SEC_CODE
#include <MemMap.h>

/*------------------[ComM_Init]----------------------------------------------*/

FUNC(void, COMM_CODE) ComM_Init
(
  P2CONST(ComM_ConfigType, AUTOMATIC, COMM_APPL_CONST) ConfigPtr
)
{
  uint8_least i;
  P2CONST(ComM_ConfigType, AUTOMATIC, COMM_APPL_CONST) LocalConfigPtr = ConfigPtr;

  DBG_COMM_INIT_ENTRY(ConfigPtr);

  /* Post Build Initializations */
/* !LINKSTO ComM.PB.Impl.PbCfgM,1 */
#if ( COMM_PBCFGM_SUPPORT_ENABLED == STD_ON )
  if (LocalConfigPtr == NULL_PTR)
  {
    PbcfgM_ModuleConfigPtrType ModuleConfig = NULL_PTR;
    if (E_OK == PbcfgM_GetConfig( COMM_MODULE_ID, COMM_INSTANCE_ID, &ModuleConfig))
    {
      LocalConfigPtr = (P2CONST(ComM_ConfigType, AUTOMATIC, COMM_APPL_CONST)) ModuleConfig;
    }
  }
#endif

#if (COMM_DEV_ERROR_DETECT == STD_ON)
  /* Check whether parameter LocalConfigPtr is a NULL_PTR or invalid */
  if (LocalConfigPtr == NULL_PTR)
  {
    /* Found a NULL_PTR, report to DET */
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_INIT, COMM_E_WRONG_PARAMETERS);
  }
  else if (E_OK != ComM_IsValidConfig(LocalConfigPtr))
  {
    /* Check that configuration pointer is valid. */
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_INIT, COMM_E_WRONG_PARAMETERS);
  }
  else
#else
  /* !LINKSTO ComM.EB.ComM_Init_NULL_PTR,1 */
  if(ComM_IsValidConfig(LocalConfigPtr) == E_OK)
#endif /* COMM_DEV_ERROR_DETECT */
  {
    /* Initialize module */

    /* Set the pointer to the post-build configuration */
    ComM_ConfigPtr = LocalConfigPtr;

    /* Pre Compile Initializations */
    for (i = 0U; i < COMM_NUM_CHANNELS; ++i)
    {
      /* Requested communication mode for each channel */
      ComM_RequestedComMode[i]    = COMM_NO_COMMUNICATION;
      /* Initialize ComM Channel State */
      ComM_ChanState[i]          = COMM_NO_COM_NO_PENDING_REQUEST;
      /* Initialize ComM Channel Mode */
      ComM_ChannelMode[i]         = COMM_NO_COMMUNICATION;
#if (COMM_MODE_LIMITATION_ENABLED == STD_ON)
      ComM_ChannelModePrevious[i] = COMM_NO_COMMUNICATION;
#endif

      /* The persistent storage is supported we don't
       * to react on a NvM callback after the initialization as the
       * the Read All and Write All will called in EcuM_Init(). */
    }

    /* Requested communication mode of each user */
    TS_MemSet(ComM_UserRequestedComMode, COMM_NO_COMMUNICATION, USER_ARRAY_SIZE);

    /* Initialize ComM state machine, perform initial transitions */
    ComM_HsmInit(&ComM_HsmScComM);

    /* Initializing the Channel communication status and Dcm request status */
    for (i = 0U; i < COMM_NUM_CHANNELS_BYTES; ++i)
    {
      ComM_Communication_Allowed[i] = 0U;

#if (COMM_DCM_ENABLED == STD_ON)
      ComM_DcmActiveStatus[i] = 0U;
#endif
    }

#if ((COMM_MODE_LIMITATION_ENABLED == STD_ON) \
     || (COMM_WAKEUP_INHIBITION_ENABLED == STD_ON))

  /* The persistent storage is supported we don't need
   * to react on a NvM callback after the initialization as the
   * the Read All and Write All will be called in EcuM_Init().
   */

/* !LINKSTO ComM864,1 */
#if (COMM_NVM_ENABLED == STD_OFF)
    /* NvM storage disabled, re-initialize RAM data */
    ComM_EB_NvRAM = ComM_EB_NvROM;
#endif

    /* Initializing the Channel Inhibition status */
    for (i = 0U; i < COMM_NUM_BYTES_NVM; ++i)
    {

#if (COMM_MODE_LIMITATION_ENABLED == STD_ON)
      ComM_ChannelNoComInhibition[i] = ComM_ChannelInhibitionStatusInit[i];
#endif

#if (COMM_WAKEUP_INHIBITION_ENABLED == STD_ON)
      ComM_ChannelWakeUpInhibition[i] = ComM_EB_NvRAM.ChannelWakeUpInhibition[i];
#endif
    }
#endif
#if (COMM_PNC_SUPPORT == STD_ON)
    if( COMM_PNC_ENABLED )
    {
      /* Initializing the pnc */
      ComM_HsmInit(&ComM_HsmScComMPnc);

      for (i = 0U; i < COMM_PN_INFO_LENGTH; i++)
      {
#if(COMM_PNC_GW_ENABLED == STD_ON)
        ComM_RxEra[i] = 0U;
#endif
        ComM_RxEira[i] = 0U;
        ComM_TxEiraEra[i] = 0U;
      }

      ComM_RxEiraSignalStatus = FALSE;
#if(COMM_PNC_GW_ENABLED == STD_ON)
      ComM_RxEraSignalStatus = FALSE;
      for (i = 0U; i < COMM_NUM_PNC; ++i)
      {
        ComM_PncStateGWE[i] = PNC_NO_COMMUNICATION;
      }
#endif
      TS_MemSet(ComM_PNCRequestedComMode, COMM_NO_COMMUNICATION, COMM_NUM_PNC * sizeof(ComM_ASR40_ModeType));
    }
#endif

#if ((COMM_INCLUDE_RTE == STD_ON) && (COMM_NUM_USERS != 0U))
    for (i = 0U; i < USER_ARRAY_SIZE; ++i)
    {
      ComM_RteNotificationSuccessful[i] = TRUE;
#if (COMM_ENABLE_ASR32_SERVICE_API == STD_ON)
      ComM_ASR32_RteModeUser[i] = COMM_NO_COMMUNICATION;
#endif
#if (COMM_ENABLE_ASR40_SERVICE_API == STD_ON)
      ComM_ASR40_RteModeUser[i] = COMM_NO_COMMUNICATION;
#endif
#if (COMM_DEFAULT_ASR_SERVICE_API != COMM_SERVICE_API_NONE)
      ComM_RteModeUser[i] = COMM_NO_COMMUNICATION;
#endif
    }
#endif /* #if ((COMM_INCLUDE_RTE == STD_ON) && (COMM_NUM_USERS != 0U))*/

    /* Set initialization status in global variable */
    ComM_InitStatus      = COMM_INIT;
  }

  DBG_COMM_INIT_EXIT(ConfigPtr);
}

/*------------------[ComM_DeInit]--------------------------------------------*/

FUNC(void, COMM_CODE) ComM_DeInit(void)
{
  uint8_least i;

  DBG_COMM_DEINIT_ENTRY();

#if (COMM_DEV_ERROR_DETECT == STD_ON)
  if (COMM_INIT != ComM_InitStatus)
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_DEINIT, COMM_E_NOT_INITED);
  }
  else
#endif
  {
    /* Check whether all the channels are in the 'NoCommunication' state */
    for (i = 0U; i < COMM_NUM_CHANNELS; i++)
    {
      /* get locally cached com mode, the BusSm of channels of BusType=Internal
       * cannot be queried */
      if (ComM_ChanState[i] != COMM_NO_COM_NO_PENDING_REQUEST)
      {
        break;
      }
    }

    /* De-init module only if all channels are in no communication state */
    if (COMM_NUM_CHANNELS == i)
    {
      /* deinit module global init status variable */
      ComM_InitStatus = COMM_UNINIT;
    }
  }

  DBG_COMM_DEINIT_EXIT();
}

/*------------------[ComM_GetState]-----------------------------------------*/

FUNC(Std_ReturnType, COMM_CODE) ComM_GetState
(
  NetworkHandleType                                Channel,
  P2VAR(ComM_StateType, AUTOMATIC, COMM_APPL_DATA) State
)
{
  Std_ReturnType RetVal = E_NOT_OK;

  DBG_COMM_GETSTATE_ENTRY(Channel,State);

#if (COMM_DEV_ERROR_DETECT == STD_ON)
  if (COMM_INIT != ComM_InitStatus)
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_GET_STATE, COMM_E_NOT_INITED);
    RetVal = COMM_E_UNINIT;
  }
  else if ((NULL_PTR == State) || (Channel >= COMM_NUM_CHANNELS))
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_GET_STATE, COMM_E_WRONG_PARAMETERS);
  }
  else
#endif
  {
    *State = ComM_ChanState[Channel];
    RetVal = E_OK;
  }

  DBG_COMM_GETSTATE_EXIT(RetVal,Channel,State);

  return RetVal;
}

/*------------------[ComM_GetStatus]-----------------------------------------*/

FUNC(Std_ReturnType, COMM_CODE) ComM_GetStatus
(
  P2VAR(ComM_InitStatusType, AUTOMATIC, COMM_APPL_DATA) Status
)
{
  Std_ReturnType RetVal = E_NOT_OK;

  DBG_COMM_GETSTATUS_ENTRY(Status);

#if (COMM_DEV_ERROR_DETECT == STD_ON)
  if (NULL_PTR == Status)
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_GET_STATUS, COMM_E_WRONG_PARAMETERS);
  }
  else
#endif
  {
    *Status = ComM_InitStatus;
    RetVal = E_OK;
  }

  DBG_COMM_GETSTATUS_EXIT(RetVal,Status);

  return RetVal;
}

#if ((COMM_ENABLE_ASR32_SERVICE_API == STD_ON) || \
    (COMM_DEFAULT_ASR_SERVICE_API == COMM_SERVICE_API_ASR32))
/*------------------[ComM_ASR32_GetInhibitionStatus]-------------------------*/

#if ((COMM_MODE_LIMITATION_ENABLED == STD_ON) || (COMM_WAKEUP_INHIBITION_ENABLED == STD_ON))
/* !LINKSTO ComM.EB.ASR32.ComM107,1 */
FUNC(Std_ReturnType, COMM_CODE) ComM_ASR32_GetInhibitionStatus
(
  NetworkHandleType                                           Channel,
  P2VAR(ComM_ASR32_InhibitionStatusType, AUTOMATIC, COMM_APPL_DATA) Status
)
{
  Std_ReturnType RetVal;

  DBG_COMM_ASR32_GETINHIBITIONSTATUS_ENTRY(Channel,Status);

  RetVal = ComM_ASR40_GetInhibitionStatus(Channel, Status);

  DBG_COMM_ASR32_GETINHIBITIONSTATUS_EXIT(RetVal,Channel,Status);

  return RetVal;
}
#endif
#endif

/*------------------[ComM_GetInhibitionStatus]-------------------------------*/

#if ((COMM_MODE_LIMITATION_ENABLED == STD_ON) || (COMM_WAKEUP_INHIBITION_ENABLED == STD_ON))
FUNC(Std_ReturnType, COMM_CODE) ComM_ASR40_GetInhibitionStatus
(
  NetworkHandleType                                           Channel,
  P2VAR(ComM_ASR40_InhibitionStatusType, AUTOMATIC, COMM_APPL_DATA) Status
)
{
  Std_ReturnType RetVal = E_NOT_OK;
  ComM_ASR40_InhibitionStatusType ChannelInhibitionStatus = 0U;

  DBG_COMM_ASR40_GETINHIBITIONSTATUS_ENTRY(Channel,Status);

#if (COMM_DEV_ERROR_DETECT == STD_ON)
  if (COMM_INIT != ComM_InitStatus)
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_GET_INHIBITION_STATUS, COMM_E_NOT_INITED);
    RetVal = COMM_E_UNINIT;
  }
  else if ((NULL_PTR == Status) || (Channel >= COMM_NUM_CHANNELS))
  {
    COMM_DET_REPORT_ERROR(
      COMM_INSTANCE_ID, COMM_SID_GET_INHIBITION_STATUS, COMM_E_WRONG_PARAMETERS);
  }
  else
#endif
  {
#if (COMM_WAKEUP_INHIBITION_ENABLED == STD_ON)
    /* assemble bit encoded channel inhibition status */
    if (TRUE == ComM_ChannelWakeUpInhibitionStatus(Channel))
    {
      ChannelInhibitionStatus |= COMM_PREVENT_WAKEUP;
    }
#endif
#if (COMM_MODE_LIMITATION_ENABLED == STD_ON)
    if (TRUE == ComM_ChannelNoComInhibitionStatus(Channel))
    {
      ChannelInhibitionStatus |= COMM_LIMIT_NOCOMM;
    }
#endif

    *Status = ChannelInhibitionStatus;
    RetVal  = E_OK;
  }

  DBG_COMM_ASR40_GETINHIBITIONSTATUS_EXIT(RetVal,Channel,Status);

  return RetVal;
}
#endif

#if ((COMM_ENABLE_ASR32_SERVICE_API == STD_ON) || \
    (COMM_DEFAULT_ASR_SERVICE_API == COMM_SERVICE_API_ASR32))
/*------------------[ComM_ASR32_RequestComMode]------------------------------*/

/* !LINKSTO ComM.EB.ASR32.ComM107,1 */
FUNC(Std_ReturnType, COMM_CODE) ComM_ASR32_RequestComMode
(
  ComM_ASR32_UserHandleType User,
  ComM_ASR32_ModeType       ComMode
)
{
  Std_ReturnType RetVal;

  DBG_COMM_ASR32_REQUESTCOMMODE_ENTRY(User,ComMode);

  RetVal = ComM_ASR40_RequestComMode(User, ComMode);

  DBG_COMM_ASR32_REQUESTCOMMODE_EXIT(RetVal,User,ComMode);

  return RetVal;
}
#endif

/*------------------[ComM_RequestComMode]------------------------------------*/

FUNC(Std_ReturnType, COMM_CODE) ComM_ASR40_RequestComMode
(
  ComM_ASR40_UserHandleType User,
  ComM_ASR40_ModeType       ComMode
)
{
  Std_ReturnType RetVal = E_NOT_OK;
#if (COMM_NUM_USERS != 0U)
  uint8_least ChannelPos;
#if ((COMM_MODE_LIMITATION_ENABLED == STD_ON) || (COMM_WAKEUP_INHIBITION_ENABLED == STD_ON))
  uint16 InhibitionCounter;
#endif

#if (COMM_PNC_SUPPORT == STD_ON)
  uint8_least PncPos;
#endif
#endif

  DBG_COMM_ASR40_REQUESTCOMMODE_ENTRY(User,ComMode);
#if (COMM_NUM_USERS == 0U)
  TS_PARAM_UNUSED(User);
  TS_PARAM_UNUSED(ComMode);
#if (COMM_DEV_ERROR_DETECT == STD_ON)
  if (COMM_INIT != ComM_InitStatus)
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_REQUEST_COM_MODE, COMM_E_NOT_INITED);
    RetVal = COMM_E_UNINIT;
  }
  else
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_REQUEST_COM_MODE, COMM_E_WRONG_PARAMETERS);
  }
#endif
#else /* #if (COMM_NUM_USERS == 0U) */
#if (COMM_DEV_ERROR_DETECT == STD_ON)
  if (COMM_INIT != ComM_InitStatus)
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_REQUEST_COM_MODE, COMM_E_NOT_INITED);
    RetVal = COMM_E_UNINIT;
  }
  else if (User >= COMM_NUM_USERS)
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_REQUEST_COM_MODE, COMM_E_WRONG_PARAMETERS);
  }
  else if ((ComMode != COMM_NO_COMMUNICATION) && (ComMode != COMM_FULL_COMMUNICATION))
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_REQUEST_COM_MODE, COMM_E_WRONG_PARAMETERS);
  }
  else
#endif
  {
    RetVal = E_OK;
    /* The SchM functions can't be called direct because it's not possible
       to include the Rte files here. Thus the SchM wrapper functions from
       the Rte specific compilation unit must be called. */
    ComM_Enter_SCHM_COMM_EXCLUSIVE_AREA_0();
    /* store user requested mode */
    ComM_UserRequestedComMode[User] = ComMode;
    ComM_Exit_SCHM_COMM_EXCLUSIVE_AREA_0();

#if (COMM_PNC_SUPPORT == STD_ON)
    if( COMM_PNC_ENABLED )
    {
      /* Get all pnc for a specific user and set ComMode  */
      for (PncPos = 0U; PncPos < COMM_NUM_PNCS_OF_USER(User); PncPos++)
      {
        const uint8 Pnc =COMM_PNC_OF_USER(User,PncPos);
       /* !LINKSTO ComM.EB.Dsn.StateDynamics.ComM_RequestComMode_NO_COM_REQ_BY_ALL_COMM_USER,1 */
        ComM_EvaluatePnc(Pnc, ComMode);
      }
    }
#endif

    /* Get all channels for a specific user and set ComMode  */
    for (ChannelPos = 0U; ChannelPos < COMM_NUM_CHANNELS_OF_USER(User); ChannelPos++)
    {
      const uint8 Channel = COMM_CHANNEL_OF_USER(User,ChannelPos);
      boolean EmitEventReqStatusChanged = TRUE;
#if ((COMM_MODE_LIMITATION_ENABLED == STD_ON)  || (COMM_WAKEUP_INHIBITION_ENABLED == STD_ON))
      boolean InhibitionStatus = FALSE;
#endif
#if (COMM_WAKEUP_INHIBITION_ENABLED == STD_ON)
      ComM_StateType ComM_ChanState_local = ComM_ChanState[Channel];
#endif
      if (COMM_FULL_COMMUNICATION == ComM_UserRequestedComMode[User])
      {
#if (COMM_MODE_LIMITATION_ENABLED == STD_ON)
        if (TRUE == ComM_ChannelNoComInhibitionStatus(Channel))
        {
          InhibitionStatus = TRUE;
        }
#endif
#if (COMM_WAKEUP_INHIBITION_ENABLED == STD_ON)
        if ((TRUE == ComM_ChannelWakeUpInhibitionStatus(Channel)) &&
            ((COMM_FULL_COM_NETWORK_REQUESTED >  ComM_ChanState_local) ||
             (COMM_SILENT_COM                 == ComM_ChanState_local)
            )
           )
        {
          InhibitionStatus = TRUE;
        }
#endif
#if ((COMM_MODE_LIMITATION_ENABLED == STD_ON) || (COMM_WAKEUP_INHIBITION_ENABLED == STD_ON))
        /* Inhibit user request if "Limit to No Comm Mode" is on OR "Wake up
         * inhibition" is on, AND current user state is No Comm */
        if (TRUE == InhibitionStatus)
        {
          /* Return COMM_E_MODE_LIMITATION when inhibition is enabled for
           * any channel of a user */
          RetVal = COMM_E_MODE_LIMITATION;

          ComM_Enter_SCHM_COMM_EXCLUSIVE_AREA_0();
          InhibitionCounter = ComM_EB_NvRAM.InhibitionCounter;
          ComM_Exit_SCHM_COMM_EXCLUSIVE_AREA_0();
          
          if(InhibitionCounter < 0xFFFFU)
          {
            /* Count the number of FULL Communication requests ignored */
            ComM_Enter_SCHM_COMM_EXCLUSIVE_AREA_0();
            ComM_EB_NvRAM.InhibitionCounter++;
            ComM_Exit_SCHM_COMM_EXCLUSIVE_AREA_0();
            /* Set NvRAM modified */
            COMM_PERS_DATA_MODIFIED();
          }
          /* Do not emit event 'REQ_STATUS_CHANGED' if inhibition is active */
          EmitEventReqStatusChanged = FALSE;
        }
        else
#endif
        {
          ComM_EvaluateChannel(Channel);
        }
      }
      else
      {
        ComM_EvaluateChannel(Channel);
      }
      /* Emit event 'REQ_STATUS_CHANGED' if request is accepted
       * and the user is directly mapped to
       * the channel. If the user is indirectly mapped to this channel via a PNC, it is up to the
       * PNC to request the appropriate mode.
       * The channels in the array ComM_ChannelsOfUser are ordered, so that directly mapped channels
       * are located before indirectly (via PNC) mapped channels.
       */
      if ((TRUE == EmitEventReqStatusChanged) && (COMM_DIRECT_NUM_CHANNELS_OF_USER(User) > ChannelPos))
      {
        /* Set Event REQ_STATUS_CHANGED */
        /* !LINKSTO ComM.EB.Dsn.StateDynamics.ComM_RequestComMode_REQ_STATUS_CHANGED,1 */
        COMM_EMIT(Channel, COMM_HSM_COMM_EV_REQ_STATUS_CHANGED);
      }
    }
  }
#endif /* #if (COMM_NUM_USERS == 0U) */
  DBG_COMM_ASR40_REQUESTCOMMODE_EXIT(RetVal,User,ComMode);

  return RetVal;
}

#if ((COMM_ENABLE_ASR32_SERVICE_API == STD_ON) || \
    (COMM_DEFAULT_ASR_SERVICE_API == COMM_SERVICE_API_ASR32))
/*------------------[ComM_ASR32_GetMaxComMode]-------------------------------*/

/* !LINKSTO ComM.EB.ASR32.ComM107,1 */
FUNC(Std_ReturnType, COMM_CODE) ComM_ASR32_GetMaxComMode
(
  ComM_ASR32_UserHandleType                             User,
  P2VAR(ComM_ASR32_ModeType, AUTOMATIC, COMM_APPL_DATA) ComMode
)
{
  Std_ReturnType RetVal;

  DBG_COMM_ASR32_GETMAXCOMMODE_ENTRY(User,ComMode);

  RetVal = ComM_ASR40_GetMaxComMode(User, ComMode);

  DBG_COMM_ASR32_GETMAXCOMMODE_EXIT(RetVal,User,ComMode);

  return RetVal;
}
#endif

/*------------------[ComM_GetMaxComMode]-------------------------------------*/

FUNC(Std_ReturnType, COMM_CODE) ComM_ASR40_GetMaxComMode
(
  ComM_ASR40_UserHandleType                             User,
  P2VAR(ComM_ASR40_ModeType, AUTOMATIC, COMM_APPL_DATA) ComMode
)
{
  Std_ReturnType RetVal = E_NOT_OK;
#if (COMM_NUM_USERS != 0U)
  uint8_least i;
  uint8 Channel;
  boolean comAllowed = FALSE;
#endif

  DBG_COMM_ASR40_GETMAXCOMMODE_ENTRY(User,ComMode);
#if (COMM_NUM_USERS == 0U)
  TS_PARAM_UNUSED(User);
  TS_PARAM_UNUSED(ComMode);
#if (COMM_DEV_ERROR_DETECT == STD_ON)
  if (COMM_INIT != ComM_InitStatus)
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_GET_MAX_COM_MODE, COMM_E_NOT_INITED);
    RetVal = COMM_E_UNINIT;
  }
  else
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_GET_MAX_COM_MODE, COMM_E_WRONG_PARAMETERS);
  }
#endif
#else /* #if (COMM_NUM_USERS == 0U) */
#if (COMM_DEV_ERROR_DETECT == STD_ON)
  if (COMM_INIT != ComM_InitStatus)
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_GET_MAX_COM_MODE, COMM_E_NOT_INITED);
    RetVal = COMM_E_UNINIT;
  }
  else if ((NULL_PTR == ComMode) || (User >= COMM_NUM_USERS))
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_GET_MAX_COM_MODE, COMM_E_WRONG_PARAMETERS);
  }
  else
#endif
  {
    ComM_StateType ComM_ChanState_local;
    /* Check for limitations, see extended functionality */
    *ComMode = COMM_FULL_COMMUNICATION;

    /* Get all channels for a specific user and check for
     * limitations/inhibitions */
    for (i = 0U; i < COMM_NUM_CHANNELS_OF_USER(User); i++)
    {
      boolean NoComInhibitionStatus = FALSE;
      boolean WkUpInhibitionStatus = FALSE;

      Channel = COMM_CHANNEL_OF_USER(User,i);
#if (COMM_MODE_LIMITATION_ENABLED == STD_ON)
        if (TRUE == ComM_ChannelNoComInhibitionStatus(Channel))
        {
          NoComInhibitionStatus = TRUE;
        }
#endif
#if (COMM_WAKEUP_INHIBITION_ENABLED == STD_ON)
        if (TRUE == ComM_ChannelWakeUpInhibitionStatus(Channel))
        {
          WkUpInhibitionStatus = TRUE;
        }
#endif
      ComM_ChanState_local = ComM_ChanState[Channel];
      comAllowed = ComM_BitArrayIsBitSet(ComM_Communication_Allowed, Channel);
      /* If any one channel has inhibition on and currently is in No Com
       * mode, set the lowest possible mode */
      if (((COMM_NO_COM_NO_PENDING_REQUEST == ComM_ChanState_local) ||
           (COMM_NO_COM_REQUEST_PENDING    == ComM_ChanState_local)
          ) &&
          ((TRUE  == NoComInhibitionStatus                         ) ||
           (TRUE  == WkUpInhibitionStatus                          ) ||
           (FALSE == comAllowed                                    )
          )
         )
      {
        *ComMode = COMM_NO_COMMUNICATION;
        break;
      }
      /* If current state of channel is Silent Com and inhibition is active,
       * the max available mode for user is Silent Communication */
      else if ((COMM_SILENT_COM == ComM_ChanState[Channel]                       ) &&
               ((TRUE == NoComInhibitionStatus) || (TRUE == WkUpInhibitionStatus))
              )
      {
        *ComMode = COMM_SILENT_COMMUNICATION;
      }
      else
      {
        /* do nothing */
      }
    }

    RetVal = E_OK;
  }
#endif /* #if (COMM_NUM_USERS == 0U) */
  DBG_COMM_ASR40_GETMAXCOMMODE_EXIT(RetVal,User,ComMode);

  return RetVal;
}

#if ((COMM_ENABLE_ASR32_SERVICE_API == STD_ON) || \
    (COMM_DEFAULT_ASR_SERVICE_API == COMM_SERVICE_API_ASR32))
/*------------------[ComM_ASR32_GetRequestedComMode]-------------------------*/

/* !LINKSTO ComM.EB.ASR32.ComM107,1 */
FUNC(Std_ReturnType, COMM_CODE) ComM_ASR32_GetRequestedMode
(
  ComM_ASR32_UserHandleType                             User,
  P2VAR(ComM_ASR32_ModeType, AUTOMATIC, COMM_APPL_DATA) ComMode
)
{
  Std_ReturnType RetVal;

  DBG_COMM_ASR32_GETREQUESTEDMODE_ENTRY(User,ComMode);

  RetVal = ComM_ASR40_GetRequestedComMode(User, ComMode);

  DBG_COMM_ASR32_GETREQUESTEDMODE_EXIT(RetVal,User,ComMode);

  return RetVal;
}
#endif

/*------------------[ComM_GetRequestedComMode]-------------------------------*/

FUNC(Std_ReturnType, COMM_CODE) ComM_ASR40_GetRequestedComMode
(
  ComM_ASR40_UserHandleType                             User,
  P2VAR(ComM_ASR40_ModeType, AUTOMATIC, COMM_APPL_DATA) ComMode
)
{
  Std_ReturnType RetVal = E_NOT_OK;

  DBG_COMM_ASR40_GETREQUESTEDCOMMODE_ENTRY(User,ComMode);
#if (COMM_NUM_USERS == 0U)
  TS_PARAM_UNUSED(User);
  TS_PARAM_UNUSED(ComMode);
#if (COMM_DEV_ERROR_DETECT == STD_ON)
  if (COMM_INIT != ComM_InitStatus)
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_GET_REQUESTED_COM_MODE, COMM_E_NOT_INITED);
    RetVal = COMM_E_UNINIT;
  }
  else
  {
    COMM_DET_REPORT_ERROR(
      COMM_INSTANCE_ID, COMM_SID_GET_REQUESTED_COM_MODE, COMM_E_WRONG_PARAMETERS);
  }
#endif
#else /* #if (COMM_NUM_USERS == 0U) */
#if (COMM_DEV_ERROR_DETECT == STD_ON)
  if (COMM_INIT != ComM_InitStatus)
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_GET_REQUESTED_COM_MODE, COMM_E_NOT_INITED);
    RetVal = COMM_E_UNINIT;
  }
  else if ((NULL_PTR == ComMode) || (User >= COMM_NUM_USERS))
  {
    COMM_DET_REPORT_ERROR(
      COMM_INSTANCE_ID, COMM_SID_GET_REQUESTED_COM_MODE, COMM_E_WRONG_PARAMETERS);
  }
  else
#endif
  {
    *ComMode = ComM_UserRequestedComMode[User];
    RetVal = E_OK;
  }
#endif /* #if (COMM_NUM_USERS == 0U) */
  DBG_COMM_ASR40_GETREQUESTEDCOMMODE_EXIT(RetVal,User,ComMode);

  return RetVal;
}

#if ((COMM_ENABLE_ASR32_SERVICE_API == STD_ON) || \
    (COMM_DEFAULT_ASR_SERVICE_API == COMM_SERVICE_API_ASR32))
/*------------------[ComM_ASR32_GetCurrentComMode]---------------------------*/

/* !LINKSTO ComM.EB.ASR32.ComM107,1 */
FUNC(Std_ReturnType, COMM_CODE) ComM_ASR32_GetCurrentComMode
(
  ComM_ASR32_UserHandleType                             User,
  P2VAR(ComM_ASR32_ModeType, AUTOMATIC, COMM_APPL_DATA) ComMode
)
{
  Std_ReturnType RetVal;

  DBG_COMM_ASR32_GETCURRENTCOMMODE_ENTRY(User,ComMode);

  RetVal = ComM_ASR40_GetCurrentComMode(User, ComMode);

  DBG_COMM_ASR32_GETCURRENTCOMMODE_EXIT(RetVal,User,ComMode);

  return RetVal;
}
#endif

/*------------------[ComM_GetCurrentComMode]---------------------------------*/

FUNC(Std_ReturnType, COMM_CODE) ComM_ASR40_GetCurrentComMode
(
  ComM_ASR40_UserHandleType                             User,
  P2VAR(ComM_ASR40_ModeType, AUTOMATIC, COMM_APPL_DATA) ComMode
)
{
  Std_ReturnType RetVal = E_NOT_OK;
#if (COMM_NUM_USERS != 0U)
  uint8_least    i;
#endif

  DBG_COMM_ASR40_GETCURRENTCOMMODE_ENTRY(User,ComMode);
#if (COMM_NUM_USERS == 0U)
  TS_PARAM_UNUSED(User);
  TS_PARAM_UNUSED(ComMode);
#if (COMM_DEV_ERROR_DETECT == STD_ON)
  if (COMM_INIT != ComM_InitStatus)
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_GET_CURRENT_COM_MODE, COMM_E_NOT_INITED);
    RetVal = COMM_E_UNINIT;
  }
  else
  {
    COMM_DET_REPORT_ERROR(
      COMM_INSTANCE_ID, COMM_SID_GET_CURRENT_COM_MODE, COMM_E_WRONG_PARAMETERS);
  }
#endif
#else /* #if (COMM_NUM_USERS == 0U) */
#if (COMM_DEV_ERROR_DETECT == STD_ON)
  if (COMM_INIT != ComM_InitStatus)
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_GET_CURRENT_COM_MODE, COMM_E_NOT_INITED);
    RetVal = COMM_E_UNINIT;
  }
  else if ((NULL_PTR == ComMode) || (User >= COMM_NUM_USERS))
  {
    COMM_DET_REPORT_ERROR(
      COMM_INSTANCE_ID, COMM_SID_GET_CURRENT_COM_MODE, COMM_E_WRONG_PARAMETERS);
  }
  else
#endif
  {

    ComM_ASR40_ModeType localComMode;
    ComM_ASR40_ModeType ResultComMode = COMM_FULL_COMMUNICATION;

    RetVal   = E_OK;

    /* Get all channels for a specific user and set ComMode  */
    for (i = 0U; i < COMM_NUM_CHANNELS_OF_USER(User); i++)
    {
      const uint8 channel = COMM_CHANNEL_OF_USER(User,i);

      /* get locally cached com mode, the BusSm of channels of BusType=Internal
       * cannot be queried */

#if (COMM_BUSTYPE_INTERNAL_NEEDED == STD_ON)
      if (COMM_BUSTYPE_OF_CHANNEL(channel) == COMM_BUS_TYPE_INTERNAL)
      {

        localComMode = ComM_ChannelMode[channel];
      }
      else
#endif
      {
        if (E_OK != COMM_BUSSM_GET_CURRENT_COM_MODE(channel, &localComMode))
        {
          RetVal = E_NOT_OK;
        }
      }
      /* get the lowest communication mode possible */
      if (localComMode < ResultComMode)
      {
        ResultComMode = localComMode;
      }
    }
    if (E_OK == RetVal)
    {
      *ComMode = ResultComMode;
    }
  }
#endif /* #if (COMM_NUM_USERS == 0U) */
  DBG_COMM_ASR40_GETCURRENTCOMMODE_EXIT(RetVal,User,ComMode);

  return RetVal;
}

#if ((COMM_ENABLE_ASR32_SERVICE_API == STD_ON) || \
    (COMM_DEFAULT_ASR_SERVICE_API == COMM_SERVICE_API_ASR32))
/*------------------[ComM_ASR32_PreventWakeUp]---------------------------*/

#if (COMM_WAKEUP_INHIBITION_ENABLED == STD_ON)
/* !LINKSTO ComM.EB.ASR32.ComM107,1 */
FUNC(Std_ReturnType, COMM_CODE) ComM_ASR32_PreventWakeUp
(
  NetworkHandleType Channel,
  boolean           Status
)
{
  Std_ReturnType RetVal;

  DBG_COMM_ASR32_PREVENTWAKEUP_ENTRY(Channel,Status);

  RetVal = ComM_ASR40_PreventWakeUp(Channel, Status);

  DBG_COMM_ASR32_PREVENTWAKEUP_EXIT(RetVal,Channel,Status);

  return RetVal;
}
#endif
#endif

/*------------------[ComM_PreventWakeUp]-------------------------------------*/

#if (COMM_WAKEUP_INHIBITION_ENABLED == STD_ON)
FUNC(Std_ReturnType, COMM_CODE) ComM_ASR40_PreventWakeUp
(
  NetworkHandleType Channel,
  boolean           Status
)
{
  Std_ReturnType RetVal = E_NOT_OK;

  DBG_COMM_ASR40_PREVENTWAKEUP_ENTRY(Channel,Status);

#if (COMM_DEV_ERROR_DETECT == STD_ON)
  if (COMM_INIT != ComM_InitStatus)
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_PREVENT_WAKE_UP, COMM_E_NOT_INITED);
    RetVal = COMM_E_UNINIT;
  }
  else if (Channel >= COMM_NUM_CHANNELS)
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_PREVENT_WAKE_UP, COMM_E_WRONG_PARAMETERS);
  }
  else
#endif
  {
    /* If ECU group classification has bit 0 set, allow Prevent wake up */
    if (COMM_PREVENT_WAKEUP == (ComM_EB_NvRAM.ECUGroupClassification & COMM_PREVENT_WAKEUP))
    {
      if (TRUE == Status)
      {
        if (TRUE != ComM_ChannelWakeUpInhibitionStatus(Channel))
        {
          /* Set inhibition status of channel as Wake Up Inhibition */
          ComM_SetChannelComMInhibitionStatus(Channel, COMM_PREVENT_WAKEUP, TRUE);
        }
      }
      else
      {
        /* Reset Bit 0 Request of Wake Up Inhibition */
        /* !LINKSTO ComM.EB.Dsn.StateDynamics.ComM_ComM_PreventWakeUp_REQ_STATUS_CHANGED,1 */
        ComM_SetChannelComMInhibitionStatus(Channel, COMM_PREVENT_WAKEUP, FALSE);

        /* Re-evaluate mode requests if inhibition get deactivated */
        ComM_EvaluateChannel(Channel);
      }
      /* Set return value to E_OK only if ECU group classification allowed
       * access */
      RetVal = E_OK;
    }
  }

  DBG_COMM_ASR40_PREVENTWAKEUP_EXIT(RetVal,Channel,Status);

  return RetVal;
}
#endif

#if ((COMM_ENABLE_ASR32_SERVICE_API == STD_ON) || \
    (COMM_DEFAULT_ASR_SERVICE_API == COMM_SERVICE_API_ASR32))
/*------------------[ComM_ASR32_LimitChannelToNoComMode]---------------------*/

#if (COMM_MODE_LIMITATION_ENABLED == STD_ON)
/* !LINKSTO ComM.EB.ASR32.ComM107,1 */
FUNC(Std_ReturnType, COMM_CODE) ComM_ASR32_LimitChannelToNoComMode
(
  NetworkHandleType Channel,
  boolean           Status
)
{
  Std_ReturnType RetVal;

  DBG_COMM_ASR32_LIMITCHANNELTONOCOMMODE_ENTRY(Channel,Status);

  RetVal = ComM_ASR40_LimitChannelToNoComMode(Channel, Status);

  DBG_COMM_ASR32_LIMITCHANNELTONOCOMMODE_EXIT(RetVal,Channel,Status);

  return RetVal;
}
#endif
#endif

/*------------------[ComM_LimitChannelToNoComMode]---------------------------*/

#if (COMM_MODE_LIMITATION_ENABLED == STD_ON)
FUNC(Std_ReturnType, COMM_CODE) ComM_ASR40_LimitChannelToNoComMode
(
  NetworkHandleType Channel,
  boolean           Status
)
{
  Std_ReturnType RetVal = E_NOT_OK;

  DBG_COMM_ASR40_LIMITCHANNELTONOCOMMODE_ENTRY(Channel,Status);

#if (COMM_DEV_ERROR_DETECT == STD_ON)
  if (COMM_INIT != ComM_InitStatus)
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_LIMIT_CHANNEL_TO_NO_COM, COMM_E_NOT_INITED);
    RetVal = COMM_E_UNINIT;
  }
  else if (Channel >= COMM_NUM_CHANNELS)
  {
    COMM_DET_REPORT_ERROR(
      COMM_INSTANCE_ID, COMM_SID_LIMIT_CHANNEL_TO_NO_COM, COMM_E_WRONG_PARAMETERS);
  }
  else
#endif
  {
    /* If ECU group classification has bit 1 set, allow Limit to No Comm */
    if (COMM_LIMIT_NOCOMM == (ComM_EB_NvRAM.ECUGroupClassification & COMM_LIMIT_NOCOMM))
    {
      if (TRUE == Status)
      {
        /* Set Event for limit to no com */

        COMM_EMIT(Channel, COMM_HSM_COMM_EV_LIMIT_TO_NO_COM);
        /* !LINKSTO ComM.EB.Dsn.StateDynamics.ComM_LimitChannelToNoComMode_LIMIT_TO_NO_COM,1 */
        ComM_SetChannelComMInhibitionStatus(Channel, COMM_LIMIT_NOCOMM, TRUE);
      }
      else
      {
        /* Reset Bit 1 Request of Limit to No Com */
        /* !LINKSTO ComM.EB.Dsn.StateDynamics.ComM_LimitChannelToNoCom_REQ_STATUS_CHANGED,1 */
        ComM_SetChannelComMInhibitionStatus(Channel, COMM_LIMIT_NOCOMM, FALSE);

        /* Re-evaluate mode requests if inhibition get deactivated */
        ComM_EvaluateChannel(Channel);
      }
      /* Set return value to E_OK only if ECU group classification allowed
       * access */
      RetVal = E_OK;
    }
  }

  DBG_COMM_ASR40_LIMITCHANNELTONOCOMMODE_EXIT(RetVal,Channel,Status);

  return RetVal;
}
#endif

#if ((COMM_ENABLE_ASR32_SERVICE_API == STD_ON) || (COMM_DEFAULT_ASR_SERVICE_API == COMM_SERVICE_API_ASR32))
/*------------------[ComM_ASR32_LimitECUToNoComMode]-------------------------*/

#if (COMM_MODE_LIMITATION_ENABLED == STD_ON)
/* !LINKSTO ComM.EB.ASR32.ComM107,1 */
FUNC(Std_ReturnType, COMM_CODE) ComM_ASR32_LimitECUToNoComMode
(
  boolean Status
)
{
  Std_ReturnType RetVal;

  DBG_COMM_ASR32_LIMITECUTONOCOMMODE_ENTRY(Status);

  RetVal = ComM_ASR40_LimitECUToNoComMode(Status);

  DBG_COMM_ASR32_LIMITECUTONOCOMMODE_EXIT(RetVal,Status);

  return RetVal;
}
#endif
#endif

/*------------------[ComM_LimitECUToNoComMode]-------------------------------*/

#if (COMM_MODE_LIMITATION_ENABLED == STD_ON)
FUNC(Std_ReturnType, COMM_CODE) ComM_ASR40_LimitECUToNoComMode
(
  boolean Status
)
{
  Std_ReturnType RetVal = E_NOT_OK;
  uint8 Channel;

  DBG_COMM_ASR40_LIMITECUTONOCOMMODE_ENTRY(Status);

#if (COMM_DEV_ERROR_DETECT == STD_ON)
  if (COMM_INIT != ComM_InitStatus)
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_LIMIT_ECU_TO_NO_COM, COMM_E_NOT_INITED);
    RetVal = COMM_E_UNINIT;
  }
  else
#endif
  {
    /* If ECU group classification has bit 1 set, allow Limit to No Comm */
    if (COMM_LIMIT_NOCOMM == (ComM_EB_NvRAM.ECUGroupClassification & COMM_LIMIT_NOCOMM))
    {
      for (Channel = 0U; Channel < COMM_NUM_CHANNELS; Channel++)
      {
        if (TRUE == Status)
        {
          /* Set Event for limit to no com */
          /* !LINKSTO ComM.EB.Dsn.StateDynamics.ComM_LimitECUToNoComMode_LIMIT_TO_NO_COM,1 */
          COMM_EMIT(Channel, COMM_HSM_COMM_EV_LIMIT_TO_NO_COM);
          ComM_SetChannelComMInhibitionStatus(Channel, COMM_LIMIT_NOCOMM, TRUE);
        }
        else
        {
          /* Reset Bit 1 Request of Limit to No Com */
          /* !LINKSTO ComM.EB.Dsn.StateDynamics.ComM_LimitECUToNoCom_REQ_STATUS_CHANGED,1 */
          ComM_SetChannelComMInhibitionStatus(Channel, COMM_LIMIT_NOCOMM, FALSE);

          /* Re-evaluate mode requests if inhibition get deactivated */
          ComM_EvaluateChannel(Channel);
        }
      }
      /* Set return value to E_OK only if ECU group classification allowed
       * access */
      RetVal = E_OK;
    }
  }

  DBG_COMM_ASR40_LIMITECUTONOCOMMODE_EXIT(RetVal,Status);

  return RetVal;
}
#endif

#if ((COMM_ENABLE_ASR32_SERVICE_API == STD_ON) || \
    (COMM_DEFAULT_ASR_SERVICE_API == COMM_SERVICE_API_ASR32))
/*------------------[ComM_ASR32_ReadInhibitCounter]--------------------------*/

#if ((COMM_MODE_LIMITATION_ENABLED == STD_ON)           \
     || (COMM_WAKEUP_INHIBITION_ENABLED == STD_ON))
/* !LINKSTO ComM.EB.ASR32.ComM107,1 */
FUNC(Std_ReturnType, COMM_CODE) ComM_ASR32_ReadInhibitCounter
(
  P2VAR(uint16, AUTOMATIC, COMM_APPL_DATA) CounterValue
)
{
  Std_ReturnType RetVal;

  DBG_COMM_ASR32_READINHIBITCOUNTER_ENTRY(CounterValue);

  RetVal = ComM_ASR40_ReadInhibitCounter(CounterValue);

  DBG_COMM_ASR32_READINHIBITCOUNTER_EXIT(RetVal,CounterValue);

  return RetVal;
}
#endif
#endif

/*------------------[ComM_ReadInhibitCounter]--------------------------------*/
#if ((COMM_MODE_LIMITATION_ENABLED == STD_ON)           \
     || (COMM_WAKEUP_INHIBITION_ENABLED == STD_ON))
FUNC(Std_ReturnType, COMM_CODE) ComM_ASR40_ReadInhibitCounter
(
  P2VAR(uint16, AUTOMATIC, COMM_APPL_DATA) CounterValue
)
{
  Std_ReturnType RetVal = E_NOT_OK;

  DBG_COMM_ASR40_READINHIBITCOUNTER_ENTRY(CounterValue);

#if (COMM_DEV_ERROR_DETECT == STD_ON)
  if (COMM_INIT != ComM_InitStatus)
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_READ_INHIBIT_COUNTER, COMM_E_NOT_INITED);
    RetVal = COMM_E_UNINIT;
  }
  else if (NULL_PTR == CounterValue)
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_READ_INHIBIT_COUNTER, COMM_E_WRONG_PARAMETERS);
  }
  else
#endif
  {
    ComM_Enter_SCHM_COMM_EXCLUSIVE_AREA_0();
    *CounterValue = ComM_EB_NvRAM.InhibitionCounter;
    ComM_Exit_SCHM_COMM_EXCLUSIVE_AREA_0();
    RetVal = E_OK;
  }

  DBG_COMM_ASR40_READINHIBITCOUNTER_EXIT(RetVal,CounterValue);

  return RetVal;
}
#endif

#if ((COMM_ENABLE_ASR32_SERVICE_API == STD_ON) || \
    (COMM_DEFAULT_ASR_SERVICE_API == COMM_SERVICE_API_ASR32))
/*------------------[ComM_ASR32_ResetInhibitCounter]-------------------------*/

#if ((COMM_MODE_LIMITATION_ENABLED == STD_ON)           \
     || (COMM_WAKEUP_INHIBITION_ENABLED == STD_ON))
/* !LINKSTO ComM.EB.ASR32.ComM107,1 */
FUNC(Std_ReturnType, COMM_CODE) ComM_ASR32_ResetInhibitCounter
(
  void
)
{
  Std_ReturnType RetVal;

  DBG_COMM_ASR32_RESETINHIBITCOUNTER_ENTRY();

  RetVal = ComM_ASR40_ResetInhibitCounter();

  DBG_COMM_ASR32_RESETINHIBITCOUNTER_EXIT(RetVal);

  return RetVal;
}
#endif
#endif

/*------------------[ComM_ResetInhibitCounter]-------------------------------*/

#if ((COMM_MODE_LIMITATION_ENABLED == STD_ON)           \
     || (COMM_WAKEUP_INHIBITION_ENABLED == STD_ON))
FUNC(Std_ReturnType, COMM_CODE) ComM_ASR40_ResetInhibitCounter
(
  void
)
{
  Std_ReturnType RetVal = E_NOT_OK;

  DBG_COMM_ASR40_RESETINHIBITCOUNTER_ENTRY();

#if (COMM_DEV_ERROR_DETECT == STD_ON)
  if (COMM_INIT != ComM_InitStatus)
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_RESET_INHIBIT_COUNTER, COMM_E_NOT_INITED);
    RetVal = COMM_E_UNINIT;
  }
  else
#endif
  {
    ComM_Enter_SCHM_COMM_EXCLUSIVE_AREA_0();
    ComM_EB_NvRAM.InhibitionCounter = 0U;
    ComM_Exit_SCHM_COMM_EXCLUSIVE_AREA_0();
    /* Set NvRAM modified */
    COMM_PERS_DATA_MODIFIED();
    RetVal = E_OK;
  }

  DBG_COMM_ASR40_RESETINHIBITCOUNTER_EXIT(RetVal);

  return RetVal;
}
#endif

#if ((COMM_ENABLE_ASR32_SERVICE_API == STD_ON) || \
    (COMM_DEFAULT_ASR_SERVICE_API == COMM_SERVICE_API_ASR32))
/*------------------[ComM_ASR32_SetECUGroupClassification]-------------------*/

#if ((COMM_MODE_LIMITATION_ENABLED == STD_ON)           \
     || (COMM_WAKEUP_INHIBITION_ENABLED == STD_ON))
/* !LINKSTO ComM.EB.ASR32.ComM107,1 */
FUNC(Std_ReturnType, COMM_CODE) ComM_ASR32_SetECUGroupClassification
(
  ComM_ASR32_InhibitionStatusType Status
)
{
  Std_ReturnType RetVal;

  DBG_COMM_ASR32_SETECUGROUPCLASSIFICATION_ENTRY(Status);

  RetVal = ComM_ASR40_SetECUGroupClassification(Status);

  DBG_COMM_ASR32_SETECUGROUPCLASSIFICATION_EXIT(RetVal,Status);

  return RetVal;
}
#endif
#endif

/*------------------[ComM_SetECUGroupClassification]-------------------------*/

#if ((COMM_MODE_LIMITATION_ENABLED == STD_ON)           \
     || (COMM_WAKEUP_INHIBITION_ENABLED == STD_ON))
FUNC(Std_ReturnType, COMM_CODE) ComM_ASR40_SetECUGroupClassification
(
  ComM_ASR40_InhibitionStatusType Status
)
{
  Std_ReturnType RetVal = E_NOT_OK;

  DBG_COMM_ASR40_SETECUGROUPCLASSIFICATION_ENTRY(Status);

#if (COMM_DEV_ERROR_DETECT == STD_ON)
  if (COMM_INIT != ComM_InitStatus)
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_SET_ECU_GROUP_CLASS, COMM_E_NOT_INITED);
    RetVal = COMM_E_UNINIT;
  }
  else
#endif
  {
    /* Change variable (in NvRAM mirror) */
    ComM_EB_NvRAM.ECUGroupClassification = Status;
    /* Set NvRAM modified */
    COMM_PERS_DATA_MODIFIED();
    RetVal = E_OK;
  }

  DBG_COMM_ASR40_SETECUGROUPCLASSIFICATION_EXIT(RetVal,Status);

  return RetVal;
}
#endif

/*------------------[ComM_GetVersionInfo]------------------------------------*/

#if (COMM_VERSION_INFO_API == STD_ON)
FUNC(void, COMM_CODE) ComM_GetVersionInfo(
  CONSTP2VAR(Std_VersionInfoType, AUTOMATIC, COMM_APPL_DATA) VersionInfoPtr)
{
  DBG_COMM_GETVERSIONINFO_ENTRY(VersionInfoPtr);

#if (COMM_DEV_ERROR_DETECT == STD_ON)
  if (NULL_PTR == VersionInfoPtr)
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_GET_VERSION_INFO, COMM_E_WRONG_PARAMETERS);
  }
  else
#endif
  {
    VersionInfoPtr->vendorID         = COMM_VENDOR_ID;
    VersionInfoPtr->moduleID         = COMM_MODULE_ID;
    VersionInfoPtr->sw_major_version = COMM_SW_MAJOR_VERSION;
    VersionInfoPtr->sw_minor_version = COMM_SW_MINOR_VERSION;
    VersionInfoPtr->sw_patch_version = COMM_SW_PATCH_VERSION;
  }

  DBG_COMM_GETVERSIONINFO_EXIT(VersionInfoPtr);
}
#endif

/*------------------[ComM_ChannelNoComInhibitionStatus]----------------------*/

#if (COMM_MODE_LIMITATION_ENABLED == STD_ON)
FUNC(boolean, COMM_CODE) ComM_ChannelNoComInhibitionStatus(
  const uint8 instIdx)
{
  boolean RetVal;

  RetVal = ComM_BitArrayIsBitSet(ComM_ChannelNoComInhibition, instIdx);

  return RetVal;
}
#endif

/*------------------[ComM_ChannelWakeUpInhibitionStatus]---------------------*/

#if (COMM_WAKEUP_INHIBITION_ENABLED == STD_ON)
FUNC(boolean, COMM_CODE) ComM_ChannelWakeUpInhibitionStatus(
  const uint8 instIdx)
{
  boolean RetVal;

  RetVal = ComM_BitArrayIsBitSet(ComM_ChannelWakeUpInhibition, instIdx);

  return RetVal;
}
#endif

/*------------------[ComM_Nm_NetworkStartIndication]-------------------------*/

#if (COMM_NM_ACCESS_NEEDED == STD_ON)
FUNC(void, COMM_CODE) ComM_Nm_NetworkStartIndication
(
  NetworkHandleType Channel
)
{
  DBG_COMM_NM_NETWORKSTARTINDICATION_ENTRY(Channel);

#if (COMM_DEV_ERROR_DETECT == STD_ON)
  if (COMM_INIT != ComM_InitStatus)
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_NM_NETWORK_START_IND, COMM_E_NOT_INITED);
  }
  else if (COMM_IS_CHANNEL_INVALID(Channel))
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_NM_NETWORK_START_IND, COMM_E_WRONG_PARAMETERS);
  }
  else
#endif
  {
    /* Set Event for network start indication */
    /* !LINKSTO ComM.EB.Dsn.StateDynamics.ComM_Nm_NetworkStartIndication_PASSIVE_WAKEUP_IND,1 */
    /* !LINKSTO ComM.EB.Dsn.StateDynamics.PASSIVE_WAKEUP_IND_NO_COM_NO_PENDING_REQUEST_0,1 */
    /* !LINKSTO ComM.EB.ComM_PASSIVE_WAKEUP_IND_NoComNoPendingReq,1 */
    COMM_EMIT(Channel, COMM_HSM_COMM_EV_PASSIVE_WAKEUP_IND);
  }

#if ((COMM_DEV_ERROR_DETECT == STD_OFF) && (COMM_HSM_INST_MULTI_ENABLED == STD_OFF))
  TS_PARAM_UNUSED(Channel);
#endif

  DBG_COMM_NM_NETWORKSTARTINDICATION_EXIT(Channel);
}

/*------------------[ComM_Nm_NetworkMode]------------------------------------*/

FUNC(void, COMM_CODE) ComM_Nm_NetworkMode
(
  NetworkHandleType Channel
)
{
  DBG_COMM_NM_NETWORKMODE_ENTRY(Channel);

#if (COMM_DEV_ERROR_DETECT == STD_ON)
  if (COMM_INIT != ComM_InitStatus)
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_NM_NETWORK_MODE, COMM_E_NOT_INITED);
  }
  else if (COMM_IS_CHANNEL_INVALID(Channel))
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_NM_NETWORK_MODE, COMM_E_WRONG_PARAMETERS);
  }
  else
#endif
  {
    /* Set Event for network mode indication */
    /* !LINKSTO ComM.EB.Dsn.StateDynamics.ComM_Nm_NetworkMode_NM_MODE_SWITCHED,1 */
    COMM_EMIT(Channel, COMM_HSM_COMM_EV_NM_MODE_SWITCHED);
  }

#if ((COMM_DEV_ERROR_DETECT == STD_OFF) && (COMM_HSM_INST_MULTI_ENABLED == STD_OFF))
  TS_PARAM_UNUSED(Channel);
#endif

  DBG_COMM_NM_NETWORKMODE_EXIT(Channel);
}

/*------------------[ComM_Nm_PrepareBusSleepMode]----------------------------*/

FUNC(void, COMM_CODE) ComM_Nm_PrepareBusSleepMode
(
  NetworkHandleType Channel
)
{
  DBG_COMM_NM_PREPAREBUSSLEEPMODE_ENTRY(Channel);

#if (COMM_DEV_ERROR_DETECT == STD_ON)
  if (COMM_INIT != ComM_InitStatus)
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_NM_PREPARE_BUS_SLEEP, COMM_E_NOT_INITED);
  }
  else if (COMM_IS_CHANNEL_INVALID(Channel))
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_NM_PREPARE_BUS_SLEEP, COMM_E_WRONG_PARAMETERS);
  }
  else
#endif
  {
    /* Set Event for prepare bus sleep mode indication */
    /* !LINKSTO ComM.EB.Dsn.StateDynamics.ComM_Nm_PrepareBusSleepMode_NM_MODE_SWITCHED,1 */
    COMM_EMIT(Channel, COMM_HSM_COMM_EV_NM_MODE_SWITCHED);
  }

#if ((COMM_DEV_ERROR_DETECT == STD_OFF) && (COMM_HSM_INST_MULTI_ENABLED == STD_OFF))
  TS_PARAM_UNUSED(Channel);
#endif

  DBG_COMM_NM_PREPAREBUSSLEEPMODE_EXIT(Channel);
}

/*------------------[ComM_Nm_BusSleepMode]-----------------------------------*/

FUNC(void, COMM_CODE) ComM_Nm_BusSleepMode
(
  NetworkHandleType Channel
)
{
  DBG_COMM_NM_BUSSLEEPMODE_ENTRY(Channel);

#if (COMM_DEV_ERROR_DETECT == STD_ON)
  if (COMM_INIT != ComM_InitStatus)
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_NM_BUS_SLEEP_MODE, COMM_E_NOT_INITED);
  }
  else if (COMM_IS_CHANNEL_INVALID(Channel))
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_NM_BUS_SLEEP_MODE, COMM_E_WRONG_PARAMETERS);
  }
  else
#endif
  {
    /* Set Event for bus sleep mode indication */
    /* !LINKSTO ComM.EB.Dsn.StateDynamics.ComM_Nm_BusSleepMode_NM_MODE_SWITCHED,1 */
    COMM_EMIT(Channel, COMM_HSM_COMM_EV_NM_MODE_SWITCHED);
  }

#if ((COMM_DEV_ERROR_DETECT == STD_OFF) && (COMM_HSM_INST_MULTI_ENABLED == STD_OFF))
  TS_PARAM_UNUSED(Channel);
#endif

  DBG_COMM_NM_BUSSLEEPMODE_EXIT(Channel);
}

/*------------------[ComM_Nm_RestartIndication]------------------------------*/

FUNC(void, COMM_CODE) ComM_Nm_RestartIndication
(
  NetworkHandleType Channel
)
{
  DBG_COMM_NM_RESTARTINDICATION_ENTRY(Channel);

#if (COMM_DEV_ERROR_DETECT == STD_ON)
  if (COMM_INIT != ComM_InitStatus)
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_NM_RESTART_IND, COMM_E_NOT_INITED);
  }
  else if (COMM_IS_CHANNEL_INVALID(Channel))
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_NM_RESTART_IND, COMM_E_WRONG_PARAMETERS);
  }
  else
#endif
  {
    /* Set Event for Nm restart indication */
    /* !LINKSTO ComM.EB.Dsn.StateDynamics.ComM_Nm_RestartIndication_PASSIVE_WAKEUP_IND,1 */
    /* !LINKSTO ComM.EB.Dsn.StateDynamics.PASSIVE_WAKEUP_IND_NO_COM_NO_PENDING_REQUEST_1,1 */
    COMM_EMIT(Channel, COMM_HSM_COMM_EV_PASSIVE_WAKEUP_IND);
  }

#if ((COMM_DEV_ERROR_DETECT == STD_OFF) && (COMM_HSM_INST_MULTI_ENABLED == STD_OFF))
  TS_PARAM_UNUSED(Channel);
#endif

  DBG_COMM_NM_RESTARTINDICATION_EXIT(Channel);
}

#endif /* (COMM_NM_ACCESS_NEEDED == STD_ON) */

#if (COMM_DCM_ENABLED == STD_ON)
/*------------------[ComM_DCM_ActiveDiagnostic]------------------------------*/

FUNC(void, COMM_CODE) ComM_DCM_ActiveDiagnostic
(
  NetworkHandleType Channel
)
{
  DBG_COMM_DCM_ACTIVEDIAGNOSTIC_ENTRY(Channel);

#if (COMM_DEV_ERROR_DETECT == STD_ON)
  if (COMM_INIT != ComM_InitStatus)
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_DCM_ACTIVE_DIAGNOSTIC, COMM_E_NOT_INITED);
  }
  else if (Channel >= COMM_NUM_CHANNELS)
  {
    COMM_DET_REPORT_ERROR(
      COMM_INSTANCE_ID, COMM_SID_DCM_ACTIVE_DIAGNOSTIC, COMM_E_WRONG_PARAMETERS);
  }
  else
#endif
  {
    /* Diagnostic session on a Passive channel is not possible.
     * See RFC #56661 */
    if (COMM_NM_VARIANT_OF_CHANNEL(Channel) != COMM_NM_PASSIVE_VARIANT)
    {
      ComM_Enter_SCHM_COMM_EXCLUSIVE_AREA_0();
      /* Set the bit (active diagnostic request) for the corresponding
       * channel in the bit array */
      ComM_BitArraySet(ComM_DcmActiveStatus, Channel);
      ComM_Exit_SCHM_COMM_EXCLUSIVE_AREA_0();
      /* notify state machine about changed diagnostics communication state */
      /* !LINKSTO ComM.EB.Dsn.StateDynamics.ComM_DCM_ActiveDiagnostic_REQ_STATUS_CHANGED,1 */
      COMM_EMIT(Channel, COMM_HSM_COMM_EV_REQ_STATUS_CHANGED);
    }
    else
    {
      /* Call has no effect */
    }
  }

  DBG_COMM_DCM_ACTIVEDIAGNOSTIC_EXIT(Channel);
}

/*------------------[ComM_DCM_InactiveDiagnostic]----------------------------*/

FUNC(void, COMM_CODE) ComM_DCM_InactiveDiagnostic
(
  NetworkHandleType Channel
)
{
  DBG_COMM_DCM_INACTIVEDIAGNOSTIC_ENTRY(Channel);

#if (COMM_DEV_ERROR_DETECT == STD_ON)
  if (COMM_INIT != ComM_InitStatus)
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_DCM_INACTIVE_DIAGNOSTIC, COMM_E_NOT_INITED);
  }
  else if (Channel >= COMM_NUM_CHANNELS)
  {
    COMM_DET_REPORT_ERROR(
      COMM_INSTANCE_ID, COMM_SID_DCM_INACTIVE_DIAGNOSTIC, COMM_E_WRONG_PARAMETERS);
  }
  else
#endif
  {
    /* Diagnostic session on a Passive channel is not possible.
     * See RFC #56661 */
    if (COMM_NM_VARIANT_OF_CHANNEL(Channel) != COMM_NM_PASSIVE_VARIANT)
    {
      ComM_Enter_SCHM_COMM_EXCLUSIVE_AREA_0();
      /* Clear the bit (active diagnostic request) for the corresponding
       * channel in the bit array */
      ComM_BitArrayClear(ComM_DcmActiveStatus, Channel);
      ComM_Exit_SCHM_COMM_EXCLUSIVE_AREA_0();
      /* notify state machine about changed diagnostics communication state */
      /* !LINKSTO ComM.EB.Dsn.StateDynamics.ComM_DCM_InactiveDiagnostic_REQ_STATUS_CHANGED,1 */
      COMM_EMIT(Channel, COMM_HSM_COMM_EV_REQ_STATUS_CHANGED);
    }
    else
    {
      /* Call has no effect */
    }
  }

  DBG_COMM_DCM_INACTIVEDIAGNOSTIC_EXIT(Channel);
}
#endif  /* (COMM_DCM_ENABLED == STD_ON) */

/*------------------[ComM_EcuM_WakeUpIndication]-----------------------------*/

/* !LINKSTO ComM.EB.Dsn.StateDynamics.PASSIVE_WAKEUP_IND_NO_COM_NO_PENDING_REQUEST_2,1 */
FUNC(void, COMM_CODE) ComM_EcuM_WakeUpIndication
(
  NetworkHandleType Channel
)
{
  DBG_COMM_ECUM_WAKEUPINDICATION_ENTRY(Channel);

#if (COMM_DEV_ERROR_DETECT == STD_ON)
  if (COMM_INIT != ComM_InitStatus)
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_ECUM_WAKE_UP_INDICATION, COMM_E_NOT_INITED);
  }
  else if (Channel >= COMM_NUM_CHANNELS)
  {
    COMM_DET_REPORT_ERROR(
      COMM_INSTANCE_ID, COMM_SID_ECUM_WAKE_UP_INDICATION, COMM_E_WRONG_PARAMETERS);
  }
  else
#endif
  {
    /* If COMM_SYNCHRONOUS_WAKE_UP is enabled, indicate all channels
     * a passive wakeup */
#if (COMM_SYNCHRONOUS_WAKE_UP == STD_ON)
    /* Set Event for EcuM wakeup indication */
    /* !LINKSTO ComM.EB.Dsn.StateDynamics.ComM_EcuM_WakeUpIndication_syncWU_PASSIVE_WAKEUP_IND,1 */
    (void)ComM_HsmEmit(&ComM_HsmScComM, COMM_HSM_COMM_EV_PASSIVE_WAKEUP_IND);
    TS_PARAM_UNUSED(Channel);
#if (COMM_PNC_SUPPORT == STD_ON)
    if( COMM_PNC_ENABLED )
    {
      /* !LINKSTO ComM.EB.Dsn.StateDynamics.ECUM_WAKEUP_IND_PNC_NO_COMMUNICATION,1 */
      /* !LINKSTO ComM.EB.Dsn.StateDynamics.ECUM_WAKEUP_IND,1 */
      (void)ComM_HsmEmit(&ComM_HsmScComMPnc, COMM_HSM_COMMPNC_EV_ECUM_WAKEUP_IND);
    }
#endif
#else
    /* Set Event for EcuM wakeup indication */
    /* !LINKSTO ComM.EB.Dsn.StateDynamics.ComM_EcuM_WakeUpIndication_PASSIVE_WAKEUP_IND,1 */
    COMM_EMIT(Channel, COMM_HSM_COMM_EV_PASSIVE_WAKEUP_IND);
#if ((COMM_DEV_ERROR_DETECT == STD_OFF) && (COMM_HSM_INST_MULTI_ENABLED == STD_OFF))
  TS_PARAM_UNUSED(Channel);
#endif
#endif
  }
  DBG_COMM_ECUM_WAKEUPINDICATION_EXIT(Channel);
}

/* !LINKSTO SWS_ComM_91001,1 */
FUNC(void, COMM_CODE) ComM_EcuM_PNCWakeUpIndication
(
  PNCHandleType PNCid
)
{
#if (COMM_PNC_SUPPORT == STD_ON)
  uint8 PncIDIdx = 0U;
  DBG_COMM_ECUM_PNCWAKEUPINDICATION_ENTRY(PNCid);
  
  /* Find index from PNCIDs, since PNCIDs are generated in
     sorted order */
  for (PncIDIdx = 0U; PncIDIdx < COMM_NUM_PNC; PncIDIdx++)
  {
    if(PNCid == ComM_PncID[PncIDIdx])
    {
      break;
    }
  }
  
#if (COMM_DEV_ERROR_DETECT == STD_ON)
  if (COMM_INIT != ComM_InitStatus)
  {
    /* !LINKSTO SWS_ComM_00965,1 */
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_ECUM_PNC_WAKE_UP_INDICATION, COMM_E_NOT_INITED);
  }
  else if (PncIDIdx >= COMM_NUM_PNC)
  {
    COMM_DET_REPORT_ERROR(
      COMM_INSTANCE_ID, COMM_SID_ECUM_PNC_WAKE_UP_INDICATION, COMM_E_WRONG_PARAMETERS);
  }
  else
#endif
  {
    
    /* !LINKSTO ComM.EB.ComM_EcuM_PNCWakeUpIndication_ComMPncEnable_FALSE,1 */
    if(COMM_PNC_ENABLED)
    {
      ComM_PNCWakeUpIndication_PncHandle(PncIDIdx);
      ComM_PNCWakeUpIndication_ChannelHandle(PncIDIdx);
    }
  }
  DBG_COMM_ECUM_PNCWAKEUPINDICATION_EXIT(PNCid);
#else
  /* !LINKSTO ComM.EB.ComM_EcuM_PNCWakeUpIndication_No_PNCs,1 */
  TS_PARAM_UNUSED(PNCid);
#endif
}

/*------------------[ComM_CommunicationAllowed]-----------------------------*/

FUNC(void, COMM_CODE) ComM_CommunicationAllowed
(
  NetworkHandleType Channel,
  boolean           Allowed
)
{
  DBG_COMM_COMMUNICATIONALLOWED_ENTRY(Channel,Allowed);

#if (COMM_DEV_ERROR_DETECT == STD_ON)
  if (COMM_INIT != ComM_InitStatus)
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_COMMUNICATIONALLOWED, COMM_E_NOT_INITED);
  }
  else if (Channel >= COMM_NUM_CHANNELS)
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_COMMUNICATIONALLOWED, COMM_E_WRONG_PARAMETERS);
  }
  else
#endif
  {
    if(TRUE == Allowed)
    {
      ComM_Enter_SCHM_COMM_EXCLUSIVE_AREA_0();
      /* Set the bit for the corresponding channel */
      ComM_BitArraySet(ComM_Communication_Allowed, Channel);
      ComM_Exit_SCHM_COMM_EXCLUSIVE_AREA_0();
    }
    else
    {
      ComM_Enter_SCHM_COMM_EXCLUSIVE_AREA_0();
      /* Clear the bit for the corresponding channel */
      ComM_BitArrayClear(ComM_Communication_Allowed, Channel);
      ComM_Exit_SCHM_COMM_EXCLUSIVE_AREA_0();
    }
    /* Set Event for communication allowed */
    /* !LINKSTO ComM.EB.Dsn.StateDynamics.ComM_CommunicationAllowed_COMALLOWED_CHANGED,1 */
    COMM_EMIT(Channel, COMM_HSM_COMM_EV_COMALLOWED_CHANGED);
  }

  DBG_COMM_COMMUNICATIONALLOWED_EXIT(Channel,Allowed);
}

/*------------------[ComM_BusSM_ModeIndication]------------------------------*/

FUNC(void, COMM_CODE) ComM_BusSM_ModeIndication
(
  NetworkHandleType                                     Channel,
  P2VAR(ComM_ASR40_ModeType, AUTOMATIC, COMM_APPL_DATA) ComMode
)
{
  DBG_COMM_BUSSM_MODEINDICATION_ENTRY(Channel,ComMode);

#if (COMM_DEV_ERROR_DETECT == STD_ON)
  if (COMM_INIT != ComM_InitStatus)
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_BUS_SM_INDICATION, COMM_E_NOT_INITED);
  }
  else if ((NULL_PTR == ComMode) || (Channel >= COMM_NUM_CHANNELS))
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_BUS_SM_INDICATION, COMM_E_WRONG_PARAMETERS);
  }
#if (COMM_BUSTYPE_INTERNAL_NEEDED == STD_ON)
  else if (COMM_BUSTYPE_OF_CHANNEL(Channel) == COMM_BUS_TYPE_INTERNAL)
  {
    COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID, COMM_SID_BUS_SM_INDICATION, COMM_E_WRONG_PARAMETERS);
  }
#endif
  else
#endif
  {
    /* !LINKSTO ComM.EB.Dsn.Algorithm.BusSMModeIndication,1 */
    ComM_ChannelMode[Channel] = *ComMode;

    /* Set Bus Mode indication for corresponding channel */
    /* !LINKSTO ComM.EB.Dsn.StateDynamics.BUSSM_MODE_IND,1 */
    COMM_EMIT(Channel, COMM_HSM_COMM_EV_BUSSM_MODE_IND);
  }

  DBG_COMM_BUSSM_MODEINDICATION_EXIT(Channel,ComMode);
}

/*==================[internal function definitions]=========================*/

/*------------------[ComM_EB_GetUserRequestedComMode]----------------------------------*/
FUNC(ComM_ASR40_ModeType, COMM_CODE) ComM_EB_GetUserRequestedComMode
(
  const uint8 User
)
{
  ComM_ASR40_ModeType ret;
  ret = ComM_UserRequestedComMode[User];
  return ret;
}

/*------------------[ComM_EB_SetRequestedComMode]----------------------------------*/
FUNC(void, COMM_CODE) ComM_EB_SetRequestedComMode
(
  const uint8 Channel,
  ComM_ASR40_ModeType ComMode
)
{
  ComM_RequestedComMode[Channel] = ComMode;
}

/*------------------[ComM_EvaluatePnc]----------------------------------*/

#if (COMM_PNC_SUPPORT == STD_ON)
FUNC(void, COMM_CODE) ComM_EvaluatePnc
(
  const uint8 Pnc,
  ComM_ASR40_ModeType ComMode
)
{
  const uint8_least NumUser = COMM_NUM_USERS_OF_PNC(Pnc);
  uint8_least       UserPos;

  ComM_Enter_SCHM_COMM_EXCLUSIVE_AREA_0();

  /* Search highest mode requested by users of a PNC */
  for (UserPos = 0U; UserPos < NumUser; UserPos++)
  {
    const uint8 UserOfPnc = COMM_USER_OF_PNC(Pnc,UserPos);

    if (ComMode < ComM_UserRequestedComMode[UserOfPnc])
    {
      ComMode = ComM_UserRequestedComMode[UserOfPnc];
    }
  }

  ComM_Exit_SCHM_COMM_EXCLUSIVE_AREA_0();

  /* if users request full communication mode or diagnostics request full
  * com */
  if (COMM_FULL_COMMUNICATION == ComMode)
  {
#if(COMM_PNC_GW_ENABLED == STD_ON)
    ComM_Enter_SCHM_COMM_EXCLUSIVE_AREA_0();
    ComM_PncStateGWE[Pnc] = PNC_REQUESTED;
    ComM_Exit_SCHM_COMM_EXCLUSIVE_AREA_0();
#endif
    /* Set Event for full communication mode */
    /* !LINKSTO ComM.EB.Dsn.StateDynamics.FULL_COM_REQ_BY_COMM_USER,1 */
    COMM_PNC_EMIT(Pnc, COMM_HSM_COMMPNC_EV_FULL_COM_REQ_BY_COMM_USER);
  }
  else /* no user needs full com */
  {
#if(COMM_PNC_GW_ENABLED == STD_ON)
    ComM_Enter_SCHM_COMM_EXCLUSIVE_AREA_0();
    ComM_PncStateGWE[Pnc] = PNC_NO_COMMUNICATION;
    ComM_Exit_SCHM_COMM_EXCLUSIVE_AREA_0();
#endif
    /* Set Event for ready sleep mode */
    /* !LINKSTO ComM.EB.Dsn.StateDynamics.ComM_RequestComMode_NO_COM_REQ_BY_ALL_COMM_USER,1 */
    /* !LINKSTO ComM.EB.Dsn.StateDynamics.ModeLimitation_NO_COM_REQ_BY_ALL_COMM_USER,1 */
    COMM_PNC_EMIT(Pnc, COMM_HSM_COMMPNC_EV_NO_COM_REQ_BY_ALL_COMM_USER);
  }
}
#endif

/*------------------[ComM_SetChannelComMInhibitionStatus]--------------------*/

#if ((COMM_MODE_LIMITATION_ENABLED == STD_ON) || (COMM_WAKEUP_INHIBITION_ENABLED == STD_ON))
FUNC(void, COMM_CODE) ComM_SetChannelComMInhibitionStatus
(
  const uint8                           instIdx,
  const ComM_ASR40_InhibitionStatusType Inhibitiontype,
  const boolean                         Status
)
{

/* CHECK: NOPARSE */
#if (COMM_MODE_LIMITATION_ENABLED == STD_OFF)
  TS_PARAM_UNUSED(Inhibitiontype);
#endif
/* CHECK: PARSE */
  
/* !LINKSTO ComM690,1 */
#if (COMM_MODE_LIMITATION_ENABLED == STD_ON)
  if (COMM_LIMIT_NOCOMM == Inhibitiontype)
  {
    if (TRUE == Status)
    {
      /* Set inhibition status of channel as Limit to No Com */
      ComM_Enter_SCHM_COMM_EXCLUSIVE_AREA_0();
      ComM_BitArraySet(ComM_ChannelNoComInhibition, instIdx);
      ComM_Exit_SCHM_COMM_EXCLUSIVE_AREA_0();
    }
    else
    {
      /* Reset Bit Request of Limit to No Com */
      ComM_Enter_SCHM_COMM_EXCLUSIVE_AREA_0();
      ComM_BitArrayClear(ComM_ChannelNoComInhibition, instIdx);
      ComM_Exit_SCHM_COMM_EXCLUSIVE_AREA_0();

      /* [ComM839,ComM840]
       * emit event 'REQ_STATUS_CHANGED'. This triggers the required
       * transitions if there are user requests when inhibition was active */
      /* !LINKSTO ComM.EB.Dsn.StateDynamics.ComM_LimitChannelToNoCom_REQ_STATUS_CHANGED,1 */
      /* !LINKSTO ComM.EB.Dsn.StateDynamics.ComM_LimitECUToNoCom_REQ_STATUS_CHANGED,1 */
      COMM_EMIT(instIdx, COMM_HSM_COMM_EV_REQ_STATUS_CHANGED);
    }
  }
  else
#endif
  {
#if (COMM_WAKEUP_INHIBITION_ENABLED == STD_ON)
    /* Find out if storing in NvRAM is allowed */
    const boolean changeNvRamAllowed = ComM_BitArrayIsBitSet(ComM_EB_NoWakeupNvStorage, instIdx);

    /* Modify Wakeup inhibition */
    if (TRUE == Status)
    {
      /* Enable inhibition */

      /* Set runtime variable */
      ComM_Enter_SCHM_COMM_EXCLUSIVE_AREA_0();
      ComM_BitArraySet(ComM_ChannelWakeUpInhibition, instIdx);
      ComM_Exit_SCHM_COMM_EXCLUSIVE_AREA_0();

      /* Check setting NvRAM */
      if (TRUE == changeNvRamAllowed)
      {
        /* Set value in NvRAM */
        ComM_Enter_SCHM_COMM_EXCLUSIVE_AREA_0();
        ComM_BitArraySet(ComM_EB_NvRAM.ChannelWakeUpInhibition, instIdx);
        ComM_Exit_SCHM_COMM_EXCLUSIVE_AREA_0();
        /* Set NvRAM modified */
        COMM_PERS_DATA_MODIFIED();
      }
    }
    else
    {
      /* Take back inhibition */

      /* Clear runtime value */
      ComM_Enter_SCHM_COMM_EXCLUSIVE_AREA_0();
      ComM_BitArrayClear(ComM_ChannelWakeUpInhibition, instIdx);
      ComM_Exit_SCHM_COMM_EXCLUSIVE_AREA_0();

      /* Check setting NvRAM */
      if (TRUE == changeNvRamAllowed)
      {
        /* Clear value in NvRAM */
        ComM_Enter_SCHM_COMM_EXCLUSIVE_AREA_0();
        ComM_BitArrayClear(ComM_EB_NvRAM.ChannelWakeUpInhibition, instIdx);
        ComM_Exit_SCHM_COMM_EXCLUSIVE_AREA_0();
        /* Set NvRAM modified */
        COMM_PERS_DATA_MODIFIED();
      }

      /* [ComM839,ComM840]
       * emit event 'REQ_STATUS_CHANGED'. This triggers the required
       * transitions if there are user requests when inhibition was active */
      /* !LINKSTO ComM.EB.Dsn.StateDynamics.ComM_ComM_PreventWakeUp_REQ_STATUS_CHANGED,1 */
      COMM_EMIT(instIdx, COMM_HSM_COMM_EV_REQ_STATUS_CHANGED);
    }
#endif
  }
}
#endif

FUNC(void, COMM_CODE) ComM_BitArraySet
(
  CONSTP2VAR(uint8, AUTOMATIC, COMM_VAR) arr,
  const uint16                           idx
)
{
  arr[idx / 8U] |= (uint8)(1U << (idx % 8U));
}

FUNC(void, COMM_CODE) ComM_BitArrayClear
(
  CONSTP2VAR(uint8, AUTOMATIC, COMM_VAR) arr,
  const uint16                           idx
)
{
  arr[idx / 8U] &= (uint8)(~(uint8)(1U << (idx % 8U)));
}

FUNC(boolean, COMM_CODE) ComM_BitArrayIsBitSet
(
  CONSTP2CONST(uint8, AUTOMATIC, COMM_VAR) arr,
  const uint16                             idx
)
{
  boolean RetVal;

  RetVal = ((((uint8)(arr[idx / 8U] >> (idx % 8U))) & 1U) != 0U) ? TRUE : FALSE;

  return RetVal;
}

#if (COMM_PNC_SUPPORT == STD_ON)
#if (COMM_NUM_PNC > 0)
/*------------------[ComM_EB_GetPncRequestedComMode]----------------------------------*/
FUNC(ComM_ASR40_ModeType, COMM_CODE) ComM_EB_GetPncRequestedComMode
(
  const uint8 Channel,
  const uint8 PncPos
)
{
  ComM_ASR40_ModeType reqMode;
  uint8 Idx;
  uint8 PncIDIdx = 0U;
  /* Find index from PNCIDs, since PNCIDs are generated in
     sorted order */
  for (Idx = 0U; Idx < COMM_NUM_PNC; ++Idx)
  {
    if( COMM_PNC_OF_CHANNEL(Channel,PncPos) == ComM_PncID[Idx] )
    {
      PncIDIdx = Idx;
    }
  }
  reqMode = ComM_PNCRequestedComMode[PncIDIdx];
  return reqMode;
}

#endif /* (COMM_NUM_PNC > 0) */

STATIC FUNC(void, COMM_CODE) ComM_ProcessPncComSignals
(
  CONSTP2VAR(boolean, AUTOMATIC, COMM_VAR) SignalStatusPtr,
  CONSTP2CONST(Com_SignalIdType, AUTOMATIC, COMM_VAR) SignalConfigurationPtr,
  CONSTP2VAR(uint8, AUTOMATIC, COMM_VAR) SignalMergedPtr,
  /* Deviation MISRAC2012-1 */
  CONSTP2CONST(P2CONST(uint8, COMM_CONST, COMM_CONST), COMM_CONST, COMM_CONST) MaskPtr,
  boolean isEira
)
{
  /* No *_least type for a loop variable as the variable is also used as
     an argument whose underlying type is uint8  */
  uint8 PncIdx;
  uint8 Index;
  uint8 i;
  uint8 RxEiraMerged[COMM_PN_INFO_LENGTH];
  /* Flag to indicate if at least one signal is received successfully */
  boolean EiraStatus = FALSE;
#if(COMM_PNC_GW_ENABLED == STD_ON)
  uint8 signalCount = 0U;
#else
  uint8 signalCount = COMM_NUM_RX_EIRA_SIGNALS;
#endif
  /* Initialise RxEiraMerged */
  TS_MemSet(RxEiraMerged, 0U, COMM_PN_INFO_LENGTH * sizeof(uint8));

#if(COMM_PNC_GW_ENABLED == STD_ON)
  if(isEira)
  {
    signalCount = COMM_NUM_RX_EIRA_SIGNALS;
  }
  else
  {
    signalCount = COMM_NUM_RX_ERA_SIGNALS;
  }
#endif
  if (*SignalStatusPtr == TRUE)
  {
    ComM_Enter_SCHM_COMM_EXCLUSIVE_AREA_0();
    /* EIRA change has been notified by Com, reset flag */
    *SignalStatusPtr = FALSE;
    ComM_Exit_SCHM_COMM_EXCLUSIVE_AREA_0();
    for (Index = 0U; Index < signalCount; Index++)
    {
      uint8 RxEiraReceived[COMM_PN_INFO_LENGTH];
      /* Read EIRA signal into a temporary buffer */
      if (E_OK == Com_ReceiveSignal(SignalConfigurationPtr[Index], RxEiraReceived))
      {
        /* Update the flag if at least one signal is received */
        EiraStatus = TRUE;
        /* Data from multiple signals may be available at the same time;
         * So, merge the contents of the newly received signal into
         * another buffer.
         */
        for (i = 0U; i < COMM_PN_INFO_LENGTH; i++)
        {
          /* Some PNCs may not reference this RX EIRA Com signal.
           * Therefore, the bits corresponding to PNCs which do not
           * reference this Com signal have to be masked out before
           * copying into the global EIRA bit vector.
           */
          /* !LINKSTO ComM944,1, ComM945,1 */
          RxEiraMerged[i] |= (uint8)(RxEiraReceived[i] & MaskPtr[Index][i]);
        }
      }
    }
  }
  /* If at least one signal is received */
  if (TRUE == EiraStatus)
  {
    for (PncIdx = 0U; PncIdx < COMM_NUM_PNC; PncIdx++)
    {
      uint8 EiraMask;

      /* Each bit of EIRA stands for one PNC.
      * For example bit 0 of Byte 0 stands for PNC_0 and bit 0 of Byte 1
      * stands for PNC_8
      */
      /* Calculate the byte index from PncID */
      Index = (uint8)(ComM_PncID[PncIdx] >> SHIFT_3_BITS);
      /* Calculate the byte mask based on bit position of this Pnc */
      EiraMask = (uint8)(1U << (ComM_PncID[PncIdx] & MASK_3_BITS));
      if((SignalMergedPtr[Index] & EiraMask) != (RxEiraMerged[Index] & EiraMask))
      {
        if (isEira)
        {
          /* There is a change in EIRA, append the EIRA event to the queue */
          /* !LINKSTO ComM.EB.Dsn.StateDynamics.COMCBK,1, ComM950,1 */
          COMM_PNC_EMIT(PncIdx, COMM_HSM_COMMPNC_EV_COMCBK);
        }
        else
        {
          if ((RxEiraMerged[Index] & EiraMask) != 0U)
          {
            /* There is a change in ERA to 1 */
            /* !LINKSTO ComM964,1, ComM934,1, ComM951,1 */
            /* !LINKSTO ComM.EB.Dsn.StateDynamics.FULL_COM_REQ_BY_COMM_USER_PNC_PREPARE_SLEEP_1,1 */
            /* !LINKSTO ComM.EB.Dsn.StateDynamics.FULL_COM_REQ_BY_COMM_USER_PNC_READY_SLEEP_0,1 */
            /* !LINKSTO ComM.EB.Dsn.StateDynamics.FULL_COM_REQ_BY_COMM_USER_PNC_NO_COMMUNICATION_1,1 */
            /* !LINKSTO ComM.EB.ComM_PncReadySleep_PncRequested,1 */
            COMM_PNC_EMIT(PncIdx, COMM_HSM_COMMPNC_EV_FULL_COM_REQ_BY_COMM_USER);
          }
          else
          {
            /* There is a change in ERA to 0 */
            /* !LINKSTO ComM964,1 */
            /* !LINKSTO ComM.EB.Dsn.StateDynamics.NO_COM_REQ_BY_ALL_COMM_USER_PNC_REQUESTED_0,1 */
            COMM_PNC_EMIT(PncIdx, COMM_HSM_COMMPNC_EV_NO_COM_REQ_BY_ALL_COMM_USER);
          }
        }
      }
    }
    /* Copy new EIRA to old EIRA for next evaluation */
    for (Index = 0U; Index < COMM_PN_INFO_LENGTH; Index++)
    {
      SignalMergedPtr[Index] = RxEiraMerged[Index];
    }
  }
}
FUNC(void, COMM_CODE) ComM_PncMainFunction
(
void
)
{
  /* No *_least type for a loop variable as the variable is also used as
     an argument whose underlying type is uint8  */
  uint8 PncIdx;
  static volatile boolean ComMPncMainfunctionRunning = FALSE;
  boolean ComMExecutePncMainFunction = FALSE;
  ComM_Enter_SCHM_COMM_EXCLUSIVE_AREA_0();
  /* CHECK: NOPARSE */
  if (ComMPncMainfunctionRunning == FALSE)
  {
    ComMPncMainfunctionRunning = TRUE;
    ComMExecutePncMainFunction = TRUE;
  }
  ComM_Exit_SCHM_COMM_EXCLUSIVE_AREA_0();
  if (ComMExecutePncMainFunction == TRUE)
  {
#if(COMM_PNC_GW_ENABLED == STD_ON)
    ComM_ProcessPncComSignals(&ComM_RxEraSignalStatus,
                            ComM_RxComSignalEraCfg,
                            ComM_RxEra,
                            ComM_PncRxEraMask,
                            FALSE
                            );
#endif
    ComM_ProcessPncComSignals(&ComM_RxEiraSignalStatus,
                            ComM_RxComSignalEiraCfg,
                            ComM_RxEira,
                            ComM_PncRxEiraMask,
                            TRUE
                            );
    for (PncIdx = 0U; PncIdx < COMM_NUM_PNC; PncIdx++)
    {
      /* Schedule the pnc state machine */
      (void) COMM_HSMMAININST(&ComM_HsmScComMPnc, PncIdx);
    }
    ComMPncMainfunctionRunning = FALSE;
  }
  /* CHECK: PARSE */
}
#endif

FUNC(Std_ReturnType, COMM_CODE) ComM_IsValidConfig
(
  P2CONST(void, AUTOMATIC, COMM_APPL_CONST) voidConfigPtr
)
{
  /* Assume an invalid configuration */
  Std_ReturnType result = E_NOT_OK;
  P2CONST(ComM_ConfigType, AUTOMATIC, COMM_APPL_CONST) ConfigPtr = voidConfigPtr;

  if(ConfigPtr != NULL_PTR)
  {
    /* Check if the configuration fits to the platform */
    if(TS_PlatformSigIsValid(ConfigPtr->PlatformSignature) == TRUE )
    {
      /* Validate the post build configuration against the compile time configuration */
      if(COMM_CFG_SIGNATURE == ConfigPtr->CfgSignature)
      {
        /* Validate the post build configuration against the link time configuration */
        if(ComM_LcfgSignature == ConfigPtr->LcfgSignature)
        {
          /* Validate the Published information in post build configuration against the
           * Published information in compile time configuration
           */
          if(COMM_PUBLIC_INFO_SIGNATURE == ConfigPtr->PublicInfoSignature)
          {
            /* Indicate that the configuration is valid */
            result = E_OK;
          }
        }
      }
    }
  }
  return result;
}
#if(COMM_PNC_SUPPORT == STD_ON)
STATIC FUNC(void,COMM_CODE) ComM_PNCWakeUpIndication_PncHandle(const uint8 pncIdx)
{

#if(COMM_SYNCHRONOUS_WAKE_UP == STD_ON)
    /* !LINKSTO SWS_ComM_PNC_ComMSynchronousWakeUp_true,1 */
    (void)ComM_HsmEmit(&ComM_HsmScComMPnc, COMM_HSM_COMMPNC_EV_ECUM_PNCWAKEUP_IND);
    TS_PARAM_UNUSED(pncIdx);
#else /*COMM_SYNCHRONOUS_WAKE_UP*/
#if (COMM_HSM_INST_MULTI_ENABLED == STD_OFF)
    TS_PARAM_UNUSED(pncIdx);
#endif /* (COMM_HSM_INST_MULTI_ENABLED == STD_OFF) */
    /* !LINKSTO SWS_ComM_00964,1 */
    /* !LINKSTO SWS_ComM_00964_Refine,1 */
    COMM_PNC_EMIT(pncIdx, COMM_HSM_COMMPNC_EV_ECUM_PNCWAKEUP_IND); 
#endif /*COMM_SYNCHRONOUS_WAKE_UP*/
}

STATIC FUNC(void,COMM_CODE) ComM_PNCWakeUpIndication_ChannelHandle(const uint8 pncIdx)
{
#if(COMM_SYNCHRONOUS_WAKE_UP == STD_ON)
     /* !LINKSTO SWS_ComM_Channel_ComMSynchronousWakeUp_true,1 */
     (void)ComM_HsmEmit(&ComM_HsmScComM, COMM_HSM_COMM_EV_PASSIVE_WAKEUP_IND);
     TS_PARAM_UNUSED(pncIdx);

#else
    uint8 chIdx;
    for (chIdx = 0U; chIdx < COMM_NUM_CHANNELS_OF_PNC(pncIdx); chIdx++)
    {
#if (COMM_HSM_INST_MULTI_ENABLED == STD_ON)      
      const uint8 Channel = COMM_CHANNEL_OF_PNC(pncIdx,chIdx);
#endif  
      /* !LINKSTO SWS_ComM_Channel_ComMSynchronousWakeUp_false,1 */
      /* !LINKSTO ComM.EB.Dsn.StateDynamics.ECUM_PNCWAKEUP_IND_PNC_NO_COMMUNICATION,1 */
      (void)COMM_HSMEMITINST(&ComM_HsmScComM, Channel, COMM_HSM_COMM_EV_PASSIVE_WAKEUP_IND);
    }
#endif
}
#endif /*(COMM_PNC_SUPPORT == STD_ON)*/




#define COMM_STOP_SEC_CODE
#include <MemMap.h>

/*==================[end of file]===========================================*/
