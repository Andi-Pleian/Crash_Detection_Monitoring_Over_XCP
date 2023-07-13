#if (!defined NM_CFG_H)
#define NM_CFG_H
/**
 * \file
 *
 * \brief AUTOSAR Nm
 *
 * This file contains the implementation of the AUTOSAR
 * module Nm.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2017 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */



/*==================[includes]==============================================*/

#include <NmStack_Types.h>  /* Nm stack specific types, includes StdTypes.h */

/* Include header files for Generic NMs*/
#include<FrNm.h>

/*==================[macros]================================================*/

/** \brief Switch for DET usage */
#if (defined NM_DEV_ERROR_DETECT)
#error NM_DEV_ERROR_DETECT already defined
#endif
#define NM_DEV_ERROR_DETECT            STD_ON
/** \brief Provide API function Nm_GetVersionInfo() */
#if (defined NM_VERSION_INFO_API)
#error NM_VERSION_INFO_API already defined
#endif
#define NM_VERSION_INFO_API            STD_OFF/** \brief enable support of the Passive Mode. */
#if (defined NM_PASSIVE_MODE_ENABLED)
#error NM_PASSIVE_MODE_ENABLED already defined
#endif
#define NM_PASSIVE_MODE_ENABLED        STD_OFF
/** \brief Provide API for getting/setting user data of Nm messages*/
#if (defined NM_USER_DATA_ENABLED)
#error NM_USER_DATA_ENABLED already defined
#endif
#define NM_USER_DATA_ENABLED           STD_OFF
/** \brief Enable/Disable setting of NMUserData via SW-C */
#if (defined NM_COM_USER_DATA_ENABLED)
#error NM_COM_USER_DATA_ENABLED already defined
#endif
#define NM_COM_USER_DATA_ENABLED           STD_OFF
/** \brief enable the source node identifier. */
#if (defined NM_NODE_ID_ENABLED)
#error NM_NODE_ID_ENABLED already defined
#endif
#define NM_NODE_ID_ENABLED             STD_OFF
/** \brief enable the Request Repeat Message Request support. */
#if (defined NM_NODE_DETECTION_ENABLED)
#error NM_NODE_DETECTION_ENABLED already defined
#endif
#define NM_NODE_DETECTION_ENABLED      STD_OFF
/** \brief enable remote sleep indication support. This
 * feature is required for gateway nodes only */
#if (defined NM_REMOTE_SLEEP_IND_ENABLED)
#error NM_REMOTE_SLEEP_IND_ENABLED already defined
#endif
#define NM_REMOTE_SLEEP_IND_ENABLED    STD_OFF
/** \brief enable the Communication Control support. */
#if (defined NM_COM_CONTROL_ENABLED)
#error NM_COM_CONTROL_ENABLED already defined
#endif
#define NM_COM_CONTROL_ENABLED         STD_ON
/** \brief Enable bus synchronization support */
#if (defined NM_BUS_SYNCHRONIZATION_ENABLED)
#error NM_BUS_SYNCHRONIZATION_ENABLED already defined
#endif
#define NM_BUS_SYNCHRONIZATION_ENABLED STD_OFF
/** \brief Enable Nm coordinator functionality */
#if (defined NM_COORDINATOR_SUPPORT_ENABLED)
#error NM_COORDINATOR_SUPPORT_ENABLED already defined
#endif
#define NM_COORDINATOR_SUPPORT_ENABLED STD_OFF
/** \brief Enable Nm coordinator sync support */
#if (defined NM_COORDINATOR_SYNC_SUPPORT_ENABLE)
#error NM_COORDINATOR_SYNC_SUPPORT_ENABLE already defined
#endif
#define NM_COORDINATOR_SYNC_SUPPORT_ENABLE STD_OFF
/** \brief Enable optional interface Nm_StateChangeNotification() */
#if (defined NM_STATE_CHANGE_IND_ENABLED)
#error NM_STATE_CHANGE_IND_ENABLED already defined
#endif
#define NM_STATE_CHANGE_IND_ENABLED STD_ON
/** \brief Enable optional interface Nm_PduRxIndication() */
#if (defined NM_PDU_RX_INDICATION_ENABLED)
#error NM_PDU_RX_INDICATION_ENABLED already defined
#endif
#define NM_PDU_RX_INDICATION_ENABLED STD_OFF
/** \brief Enable optional interface Nm_RepeatMessageIndication() */
#if (defined NM_REPEAT_MESSAGE_INDICATION)
#error NM_REPEAT_MESSAGE_INDICATION already defined
#endif

/* !LINKSTO Nm231_ON,2, Nm231_OFF,2 */
#define NM_REPEAT_MESSAGE_INDICATION STD_OFF
/** \brief Enable optional interface Nm_RepeatMessageIndication() */
#if (defined NM_CAR_WAKEUPRX_INDICATION)
#error NM_CAR_WAKEUPRX_INDICATION already defined
#endif
#define NM_CAR_WAKEUPRX_INDICATION STD_OFF

#if (defined NM_NM_INCLUDE_BSWM_HEADER)
#error NM_NM_INCLUDE_BSWM_HEADER already defined
#endif
/** \brief Define for Car wakeup callout */
 /* as:modconf('Nm')[1]/NmGlobalConfig/NmGlobalFeatures/NmCarWakeUpRxEnabled = 'true'" */
#define NM_NM_INCLUDE_BSWM_HEADER STD_OFF

/** \brief Enable State change notification callout */
#if (defined NM_STATE_CHANGE_NOTIFICATION_CALLOUT)
#error NM_STATE_CHANGE_NOTIFICATION_CALLOUT already defined
#endif
#define NM_STATE_CHANGE_NOTIFICATION_CALLOUT STD_OFF
#if (defined NM_STATE_REPORT_ENABLED)
#error NM_STATE_REPORT_ENABLED already defined
#endif
#define NM_STATE_REPORT_ENABLED STD_OFF
#if (defined NmConf_NmChannelConfig_NmChannelConfig_0)
#error NmConf_NmChannelConfig_NmChannelConfig_0 already defined
#endif
/** \brief Symbolic name for the NM channel "NmChannelConfig_0" */
#define NmConf_NmChannelConfig_NmChannelConfig_0   0U

#if (!defined NM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NmChannelConfig_0)
#error NmChannelConfig_0 already defined
#endif

/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) 0 */
#define NmChannelConfig_0                     0U

#if (defined Nm_NmChannelConfig_0)
#error Nm_NmChannelConfig_0 already defined
#endif

/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define Nm_NmChannelConfig_0   0U
#endif /* NM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/** \brief greatest value of configured Nm Channel ID */
#if (defined NM_MAX_CHANNELID)
#error NM_MAX_CHANNELID already defined
#endif
#define NM_MAX_CHANNELID 0U

/** \brief Number of Nm channels */
#if (defined NM_CHANNEL_NUM)
#error NM_CHANNEL_NUM already defined
#endif
#define NM_CHANNEL_NUM                 1U


/** \brief Number of used underlying BusNm modules */
#if (defined NM_BUSNM_NUM)
#error NM_BUSNM_NUM already defined
#endif
#define NM_BUSNM_NUM                   1U

/** \brief Flag indicating if CanNm is used */
#if (defined NM_CANNM_USED)
#error NM_CANNM_USED already defined
#endif
#define NM_CANNM_USED                  STD_OFF/** \brief Flag indicating if FrNm is used */
#if (defined NM_FRNM_USED)
#error NM_FRNM_USED already defined
#endif
#define NM_FRNM_USED                   STD_OFF/** \brief Flag indicating if UdpNm is used */
#if (defined NM_UDPNM_USED)
#error NM_UDPNM_USED already defined
#endif
#define NM_UDPNM_USED                   STD_OFF/** \brief Flag indicating the use of generic NMs */
#if (defined NM_GENERICNM_USED)
#error NM_GENERICNM_USED already defined
#endif
#define NM_GENERICNM_USED                   STD_ON
#if (defined NM_BUSNM_PASSIVE_START_UP)
#error NM_BUSNM_PASSIVE_START_UP already defined
#endif
#define NM_BUSNM_PASSIVE_START_UP(nmNetworkHandle)      \
  FrNm_PassiveStartUp(nmNetworkHandle)

#if (defined NM_BUSNM_GET_STATE)
#error NM_BUSNM_GET_STATE already defined
#endif
#define NM_BUSNM_GET_STATE(nmNetworkHandle, nmStatePtr, nmModePtr)      \
  FrNm_GetState((nmNetworkHandle), (nmStatePtr), (nmModePtr))
#if (defined NM_BUSNM_NETWORK_REQUEST)
#error NM_BUSNM_NETWORK_REQUEST already defined
#endif
#define NM_BUSNM_NETWORK_REQUEST(NetworkHandle)         \
  FrNm_NetworkRequest(NetworkHandle)

#if (defined NM_BUSNM_NETWORK_RELEASE)
#error NM_BUSNM_NETWORK_RELEASE already defined
#endif
#define NM_BUSNM_NETWORK_RELEASE(NetworkHandle)         \
  FrNm_NetworkRelease(NetworkHandle)





#if (defined NM_BUSNM_DISABLE_COMMUNICATION)
#error NM_BUSNM_DISABLE_COMMUNICATION already defined
#endif
#define NM_BUSNM_DISABLE_COMMUNICATION(NetworkHandle)   \
  FrNm_DisableCommunication(NetworkHandle)
#if (defined NM_BUSNM_ENABLE_COMMUNICATION)
#error NM_BUSNM_ENABLE_COMMUNICATION already defined
#endif
#define NM_BUSNM_ENABLE_COMMUNICATION(NetworkHandle)    \
  FrNm_EnableCommunication(NetworkHandle)


/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/


#define NM_START_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

#if ( (NM_BUSNM_NUM > 1U)                        ||     \
      (NM_COORDINATOR_SUPPORT_ENABLED == STD_ON) ||     \
      (NM_STATE_REPORT_ENABLED == STD_ON)        ||     \
      (NM_CHANNEL_NUM > 1U)                             \
    )
/** \brief Array holding the configuration of each channel */
extern CONST(Nm_ChannelConfigType, NM_CONST) Nm_ChannelConfig[NM_CHANNEL_NUM];
#endif

#define NM_STOP_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

#define NM_START_SEC_CONST_8
#include <MemMap.h>

#if ( (NM_BUSNM_NUM > 1U)                         ||    \
      (NM_COORDINATOR_SUPPORT_ENABLED == STD_ON)  ||    \
      (NM_DEV_ERROR_DETECT == STD_ON)             ||    \
      (NM_STATE_REPORT_ENABLED == STD_ON)         ||    \
      (NM_CHANNEL_NUM > 1U)                             \
    )
extern CONST(uint8, NM_CONST) Nm_ChanIdxFromNetworkHandle[NM_MAX_CHANNELID + 1U];
#endif

#define NM_STOP_SEC_CONST_8
#include <MemMap.h>

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/


/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/
#endif /* if !defined( NM_CFG_H ) */
