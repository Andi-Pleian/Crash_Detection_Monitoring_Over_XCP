/**
 * \file
 *
 * \brief AUTOSAR Xcp
 *
 * This file contains the implementation of the AUTOSAR
 * module Xcp.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2017 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
/* This file contains the generated Xcp module configuration. */

#if (!defined XCP_CFG_H)
#define XCP_CFG_H

/*==================[includes]===============================================*/

#include <Xcp_Types.h>    /* Xcp types to be published */
#include <TSAutosar.h>    /* EB specific standard types */
#include <ComStack_Types.h> /* Comstack types */
//TODO ANDI
#include <Platform_Types.h>

/*==================[macros]=================================================*/

#if (defined XCP_OVERLOAD_MSB_SUPPORT)
#error XCP_OVERLOAD_MSB_SUPPORT already defined
#endif
/** \brief Switch, indicating whether support for overload MSB 
 ** is enabled or disabled */
#define XCP_OVERLOAD_MSB_SUPPORT         STD_OFF
#if (defined XCP_WRITE_READ_MEMORY_RAM)
#error XCP_WRITE_READ_MEMORY_RAM already defined
#endif
/** \brief Switch, indicating whether user RAM memory access
 ** callouts are enabled or disabled */
#define XCP_WRITE_READ_MEMORY_RAM         STD_OFF
#if (defined XCP_ASYNCH_CRC_SUPPORT)
#error XCP_ASYNCH_CRC_SUPPORT already defined
#endif
/** \brief Enable/disable support for asynchronous calculation 
 ** of the Build Checksum on Xcp_CrcMainFunction context. */
#define XCP_ASYNCH_CRC_SUPPORT   STD_OFF
#if (defined XCP_VERSION_INFO_API)
#error XCP_VERSION_INFO_API already defined
#endif
/** \brief Switch, indicating whether API version information is
 ** activated or deactivated  for XCP */
#define XCP_VERSION_INFO_API         STD_OFF

#if (defined XCP_ON_CAN_ENABLED)
#error XCP_ON_CAN_ENABLED already defined
#endif
/** \brief Switch, indicating whether XCPonCAN functionality is available */
#define XCP_ON_CAN_ENABLED           STD_ON

#if (defined XCP_ON_CANFD_ENABLED)
#error XCP_ON_CANFD_ENABLED already defined
#endif
/** \brief Switch, indicating whether XCPonCANFD functionality is available */
#define XCP_ON_CANFD_ENABLED           STD_OFF

#if (defined XCP_ON_FLEXRAY_ENABLED)
#error XCP_ON_FLEXRAY_ENABLED already defined
#endif
/** \brief Switch, indicating whether XCPonFlexRay functionality is available */
#define XCP_ON_FLEXRAY_ENABLED       STD_OFF

#if (defined XCP_ON_ETHERNET_ENABLED)
#error XCP_ON_ETHERNET_ENABLED already defined
#endif
/** \brief Switch, indicating whether XCPonEthernet functionality is available */
#define XCP_ON_ETHERNET_ENABLED      STD_OFF

#if (defined XCP_SOAD_PROTOCOL_UDP_SUPPORT)
#error XCP_SOAD_PROTOCOL_UDP_SUPPORT already defined
#endif
/** \brief Switch, indicating whether the support for UDP protocol is enabled.
 ** If UDP is used the socket must be closed if it is not used anymore.
 ** Otherwise the socket would be locked to the initial source port,
 ** preventing further requests from other ports.
 **/
#define XCP_SOAD_PROTOCOL_UDP_SUPPORT          STD_OFF


#if (defined XCP_SOAD_PROTOCOL_TCP_SUPPORT)
#error XCP_SOAD_PROTOCOL_TCP_SUPPORT already defined
#endif
/** \brief Switch, indicating whether the support for TCP protocol is enabled.
 ** If TCP is used the connection has to be terminated in case the
 ** connection is closed at the client side.
 **/
#define XCP_SOAD_PROTOCOL_TCP_SUPPORT          STD_OFF

#if (defined XCP_EVENT_TRIGGERED_MAINFUNC )
#error XCP_EVENT_TRIGGERED_MAINFUNC  already defined
#endif
/** \brief Switch, indicating whether the processing of cyclicaly
 **        events are processed by Event MainFunctions */
#define XCP_EVENT_TRIGGERED_MAINFUNC         STD_OFF

#if (defined XCP_PROCESS_MULTI_MF_EVENTS )
#error XCP_PROCESS_MULTI_MF_EVENTS  already defined
#endif
/** \brief Switch, indicating if the Xcp_MainFunction is processing multiple events */
#define XCP_PROCESS_MULTI_MF_EVENTS         STD_OFF











#if (defined XCP_NON_DYNAMIC_MIRROR_SIZE)
#error XCP_NON_DYNAMIC_MIRROR_SIZE already defined
#endif
/** \brief Value indicating the ODT Mirror Size.
 **/
#define XCP_NON_DYNAMIC_MIRROR_SIZE           0U

#if (defined XCP_MAX_ODTENTRY_SIZE)
#error XCP_MAX_ODTENTRY_SIZE already defined
#endif
/** \brief Value indicating the Maximum ODT Entry Size.
 **/
#define XCP_MAX_ODTENTRY_SIZE                7U

#if (defined XCP_ENABLE_XCP_CONTROL_API)
#error XCP_ENABLE_XCP_CONTROL_API already defined
#endif
/** \brief Switch, indicating whether XCP control API functionality is available.
 **/
#define XCP_ENABLE_XCP_CONTROL_API          STD_ON

#if (defined XCP_DEFAULT_XCP_MODULE_STATE)
#error XCP_DEFAULT_XCP_MODULE_STATE already defined
#endif
/** \brief Switch, indicating whether XCP default module state is available.
 **/
#define XCP_DEFAULT_XCP_MODULE_STATE                              STD_ON
#if (defined XCP_NUMBER_OF_USERCOMMANDS)
#error XCP_NUMBER_OF_USERCOMMANDS already defined
#endif
/** \brief Number of user defined commands.
 **/
#define XCP_NUMBER_OF_USERCOMMANDS                                0U

#if (defined XCP_DYNAMIC_PDU_SUPPORTED)
#error XCP_DYNAMIC_PDU_SUPPORTED already defined
#endif
/** \brief Switch, indicating whether XCP PDU can be enabled/disabled at runtime.
 **/
#define XCP_DYNAMIC_PDU_SUPPORTED         STD_OFF
#if (defined XCP_COM_MAINFUNCTION_SUPPORT)
  
#error XCP_COM_MAINFUNCTION_SUPPORT already defined
#endif
/** \brief Switch, indicating whether Tx and Rx MainFunctions are available.
 **/
#define XCP_COM_MAINFUNCTION_SUPPORT      STD_OFF
#if (defined XCP_PDU_ROUTING_TABLE)
  
#error XCP_PDU_ROUTING_TABLE already defined
#endif
/** \brief Switch, indicating whether the PduId from lower layer are the Xcp PduIds.
 **/
#define XCP_PDU_ROUTING_TABLE             STD_OFF

#if (defined XCP_FLEXRAY_TP_COMMANDS_SUPPORTED)
#error XCP_FLEXRAY_TP_COMMANDS_SUPPORTED already defined
#endif
/** \brief Number of user defined commands.
 **/
#define XCP_FLEXRAY_TP_COMMANDS_SUPPORTED            STD_OFF

#if (defined XCP_NO_OF_FLX_BUF_CONFIGURED)
#error XCP_NO_OF_FLX_BUF_CONFIGURED already defined
#endif
/** \brief Number of Flexray hardware buffers configured.
 **/
#define XCP_NO_OF_FLX_BUF_CONFIGURED                                0U

#if (defined XCP_SUPPRESS_TX_SUPPORT)
#error XCP_SUPPRESS_TX_SUPPORT already defined
#endif
/** \brief Switch, indicating whether Xcp_SetTransmissionMode() is supported or not. */
#define XCP_SUPPRESS_TX_SUPPORT      STD_OFF
/*------------------[symbolic name values]----------------------------------*/

#if (defined XcpConf_XcpPdu_XcpTxPdu_xcpresponse_T)
#error XcpConf_XcpPdu_XcpTxPdu_xcpresponse_T already defined
#endif
/** \brief Symbolic name value of the Handle ID for receiving a TxConfirmation or a TriggerTransmit
 **
 ** This Handle ID must be used by the underlying communication layer after the Xcp requested a
 ** transmission.
 **/
#define XcpConf_XcpPdu_XcpTxPdu_xcpresponse_T        0U

#if (!defined XCP_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined XcpTxPdu_xcpresponse_T)
#error XcpTxPdu_xcpresponse_T is already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define XcpTxPdu_xcpresponse_T        0U

#if (defined Xcp_XcpTxPdu_xcpresponse_T)
#error Xcp_XcpTxPdu_xcpresponse_T is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define Xcp_XcpTxPdu_xcpresponse_T        0U
#endif /* XCP_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined XcpConf_XcpPdu_XcpRxPdu_xcp_request_R)
#error XcpConf_XcpPdu_XcpRxPdu_xcp_request_R already defined
#endif
/** \brief Symbolic name value for the Handle IDs used to receive packets from the master. */
#define XcpConf_XcpPdu_XcpRxPdu_xcp_request_R        0U

#if (!defined XCP_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined XcpRxPdu_xcp_request_R)
#error XcpRxPdu_xcp_request_R is already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define XcpRxPdu_xcp_request_R        0U

#if (defined Xcp_XcpRxPdu_xcp_request_R)
#error Xcp_XcpRxPdu_xcp_request_R is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define Xcp_XcpRxPdu_xcp_request_R        0U
#endif /* XCP_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */


#if (defined XcpConf_XcpConnectionCfg_XcpConnectionCfg_0)
#error XcpConf_XcpConnectionCfg_XcpConnectionCfg_0 already defined
#endif
/** \brief The Index number of the connection configuration*/
#define XcpConf_XcpConnectionCfg_XcpConnectionCfg_0         0U

#if (!defined XCP_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined XcpConnectionCfg_0)
#error XcpConnectionCfg_0 is already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define XcpConnectionCfg_0        0U

#if (defined Xcp_XcpConnectionCfg_0)
#error Xcp_XcpConnectionCfg_0 is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define Xcp_XcpConnectionCfg_0        0U
#endif /* XCP_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */


#if (defined XcpConf_XcpEventChannel_BSW_1ms)
#error XcpConf_XcpEventChannel_BSW_1ms already defined
#endif
/** \brief The Index number of the event channel*/
#define XcpConf_XcpEventChannel_BSW_1ms         0U

#if (!defined XCP_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined BSW_1ms)
#error BSW_1ms is already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define BSW_1ms        0U

#if (defined Xcp_BSW_1ms)
#error Xcp_BSW_1ms is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define Xcp_BSW_1ms        0U
#endif /* XCP_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined XcpConf_XcpEventChannel_BSW_10ms)
#error XcpConf_XcpEventChannel_BSW_10ms already defined
#endif
/** \brief The Index number of the event channel*/
#define XcpConf_XcpEventChannel_BSW_10ms         1U

#if (!defined XCP_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined BSW_10ms)
#error BSW_10ms is already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define BSW_10ms        1U

#if (defined Xcp_BSW_10ms)
#error Xcp_BSW_10ms is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define Xcp_BSW_10ms        1U
#endif /* XCP_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined XcpConf_XcpEventChannel_BSW_20ms)
#error XcpConf_XcpEventChannel_BSW_20ms already defined
#endif
/** \brief The Index number of the event channel*/
#define XcpConf_XcpEventChannel_BSW_20ms         2U

#if (!defined XCP_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined BSW_20ms)
#error BSW_20ms is already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define BSW_20ms        2U

#if (defined Xcp_BSW_20ms)
#error Xcp_BSW_20ms is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define Xcp_BSW_20ms        2U
#endif /* XCP_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined XcpConf_XcpEventChannel_BSW_100ms)
#error XcpConf_XcpEventChannel_BSW_100ms already defined
#endif
/** \brief The Index number of the event channel*/
#define XcpConf_XcpEventChannel_BSW_100ms         3U

#if (!defined XCP_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined BSW_100ms)
#error BSW_100ms is already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define BSW_100ms        3U

#if (defined Xcp_BSW_100ms)
#error Xcp_BSW_100ms is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define Xcp_BSW_100ms        3U
#endif /* XCP_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES */



#if (defined XCP_MAX_DAQ)
#error XCP_MAX_DAQ already defined
#endif
/** \brief The maximum number of DAQ lists on the XCP slave. */
#define XCP_MAX_DAQ                  1U

#if (defined XCP_NO_OF_NON_DYNAMIC_DAQ_LISTS)
#error XCP_NO_OF_NON_DYNAMIC_DAQ_LISTS already defined
#endif
/** \brief The number of predefined/static DAQ lists */
#define XCP_NO_OF_NON_DYNAMIC_DAQ_LISTS             0U

#if (defined XCP_NO_OF_NON_DYNAMIC_ODTS)
#error XCP_NO_OF_NON_DYNAMIC_ODTS already defined
#endif
/** \brief The total number of predefined/static ODTs */
#define XCP_NO_OF_NON_DYNAMIC_ODTS                   0U

#if (defined XCP_NO_OF_NON_DYNAMIC_ODTENTRIES)
#error XCP_NO_OF_NON_DYNAMIC_ODTENTRIES already defined
#endif
/** \brief The total number of predefined/static ODT entries */
#define XCP_NO_OF_NON_DYNAMIC_ODTENTRIES             0U

#if (defined XCP_MAX_ODT)
#error XCP_MAX_ODT already defined
#endif
/** \brief Total number of ODTs possible in the slave.
 **
 **/
#define XCP_MAX_ODT                                        8U

#if (defined XCP_DYNAMIC_AREA_SIZE)
#error XCP_DYNAMIC_AREA_SIZE already defined
#endif
/** \brief The size in bytes of the memory area used for dynamic DAQ list configuration.
 **
 **/
#define XCP_DYNAMIC_AREA_SIZE                             1024U

#if (defined XCP_DYNAMIC_MIRROR_SIZE)
#error XCP_DYNAMIC_MIRROR_SIZE already defined
#endif
/** \brief The size in bytes of the memory area used for Mirror of ODT data of dynamic DAQ list.
 **
 **/
#define XCP_DYNAMIC_MIRROR_SIZE                            1024U

#if (defined XCP_NUMBER_OF_BITS_IN_BYTE)
#error XCP_NUMBER_OF_BITS_IN_BYTE already defined
#endif
/** \brief The number of bits in a byte */
#define XCP_NUMBER_OF_BITS_IN_BYTE        8U

 


#if (defined XCP_STORE_DAQ_SUPPORTED)
#error XCP_STORE_DAQ_SUPPORTED already defined
#endif
/** \brief Switch, indicating whether all DAQ lists can be stored in the NV memory. **/
#define XCP_STORE_DAQ_SUPPORTED         STD_OFF

#if (defined XCP_CAL_PAG_STORE_SUPPORTED)
#error XCP_CAL_PAG_STORE_SUPPORTED already defined
#endif
/** \brief Switch, indicating whether calibration data storing to NV memory functionality is available.
 **/
#define XCP_CAL_PAG_STORE_SUPPORTED          STD_OFF
#if (defined XCP_GET_DAQ_ID_SUPPORTED)
#error XCP_GET_DAQ_ID_SUPPORTED already defined
#endif
/** \brief Switch, indicating whether GET_DAQ_ID command is supported.
 **/
#define XCP_GET_DAQ_ID_SUPPORTED          STD_OFF
#if (defined XCP_TRIGGER_TX_API_ENABLED)
#error XCP_TRIGGER_TX_API_ENABLED already defined
#endif
/** \brief Switch, indicating whether Xcp_TriggerTransmit API is supported.
 **/
#define XCP_TRIGGER_TX_API_ENABLED        STD_OFF

#if (defined XCP_NUMBER_OF_MEMORY_AREAS)
#error XCP_NUMBER_OF_MEMORY_AREAS already defined
#endif
/** \brief Number of measurement areas
 **/
#define XCP_NUMBER_OF_MEMORY_AREAS          1U

/*==================[type definitions]=======================================*/


 


/** \brief DAQ Id type */

typedef uint16 Xcp_DaqIdType;

/** \brief Odt Type */
typedef uint8 Xcp_OdtSizeType;
 
/** \brief Mirror Type */
typedef uint16 Xcp_MirrorSizeType;

/** \brief ODT Entry Type. */
typedef struct
{
  /* The address location of the ODT entry */
  P2VAR(uint8, TYPEDEF, XCP_APPL_DATA) Address;
  uint8 Length;     /* Size of the element in AG */
  uint8 BitOffset;  /* Position of the Bit to be considered */
  uint8 AddrExtn;   /* Address extension of the ODT */
} Xcp_OdtEntryType;

/** \brief ODT Table Type. */
typedef struct
{
  P2VAR(Xcp_OdtEntryType, TYPEDEF, XCP_VAR) OdtEntry; /* Pointer to OdtEntry
                                                         array or Object Descriptor table */
  Xcp_OdtSizeType DTODataSize;                  /* Size of data segment in DTO package. */
  Xcp_MirrorSizeType MirrorOffsetPos;           /* Position index of data in OdtMirrorDataArray. */

  uint8 NrOfOdtEntries;                               /* Number of elements in the ODT */
} Xcp_OdtType;

/** \brief DAQ List properties. */
typedef struct
{
  P2VAR(Xcp_OdtType, TYPEDEF, XCP_VAR) OdtList; /* Pointer to the ODT Array or DAQ List */
  uint16 EventId;      /* Event channel number for this DAQ */
  uint8 Mode;          /* Current  mode information of the DAQ List.
                              Bit7: Resume status,
                              Bit6: Running status,
                              Bit5: PID_OFF,
                              Bit4: Time Stamp,
                              Bit2: Selected,
                              Bit1: Direction,
                              Bit0: Alternating */
  uint8 Priority;      /* Priority of this DAQ */
  uint8 FirstPID;      /* The first PID only, when using absolute ODT number */
  uint8 MaxOdt;        /* Number of ODTs in this DAQ list */
  uint8 MaxOdtEntries; /* Maximum number of ODT entries into an Object Descriptor Table
                          of this DAQ list. */
  uint8 Prescaler;     /* Preset value of the prescaler */
  uint8 PrescalerCnt;  /* Current value of the prescaler */
  uint8 Properties;   /*  Configuration properties of the DAQ List:
                              Bit7: RESERVED,
                              Bit6: RESERVED
                              Bit5: RESERVED,
                              Bit4: RESERVED,
                              Bit3: STIM direction allowed,
                              Bit2: DAQ direction allowed,
                              Bit1: EventFixed,
                              Bit0: Predefined */
  uint8 Flags;         /* Additional configuration of the DAQ List:
                              Bit7: RESERVED,
                              Bit6: RESERVED
                              Bit5: RESERVED,
                              Bit4: RESERVED,
                              Bit3: OverloadCheckIsSkipped,
                              Bit2: SkipOverloadCheck,
                              Bit1: Configured,
                              Bit0: Ready to sample */
} Xcp_DaqType;

  


/** \brief All DAQ list related information grouped into a contiguous area
 ** Grouping them enables the DAQ lists storage in NV memory using a single NvM block. */
typedef struct
{
  /* Xcp_DynamicArea array must be the first variable of this structure due to alignment
   restrictions - the start address will be converted into a Xcp_DaqType structure. */
  uint8 Xcp_DynamicArea[XCP_DYNAMIC_AREA_SIZE];
  /* This dummy variable is added so that the entire structure is aligned to 4 bytes in order to
  prevent inconsistencies between what sizeof(Xcp_DaqLists) is providing and the actual size of
  Xcp_DaqLists in the map file after the linkage. Without this, the members of this structure are
  aligned to 2 bytes by the compiler, but the linker might align the entire structure to 4 bytes -
  thus adding extra bytes that the sizeof() will be unaware of.*/
  uint32 DummyVar;
} Xcp_AllDaqListsType;

/** \brief All Dto Data Mirror Type grouped into a contiguous area */
typedef struct
{
  /* Number of reserved bytes in Dynamic ODT Mirror */
  Xcp_MirrorSizeType DynamicMirrorReservedBytes;
  /* Array Mirror for ODTs from Dynamic DAQ */
  uint8  DynamicOdtMirrorDataArray[XCP_DYNAMIC_MIRROR_SIZE];
} Xcp_AllDtoDataMirrorType;


/** \brief Definition for Xcp LPdu lenght type. */
typedef uint8 Xcp_LPduLengthType;

/** \brief Data structure storing property information regarding transmit PDU. */
typedef struct
{
  uint32 PduCanId;                  /* CAN/CANFD Id for the selected PDU */
  Xcp_LPduLengthType LPduStartPos;  /* the start position of the PDU data inside LPDU buffer 
                                       when FLX_ASSIGN is not used on that connection */
  PduIdType DestPduId;              /* store the transport layer ID for the referenced PDU. */
  PduIdType IntPduBufId;            /* map PDU to internal buffer Id */
  uint8 IntConnectionId;            /* maps PDU internal id towards a Xcp connection Id. */
  uint8 Properties;                 /* Additional configuration properties:
                                       Bit7: Support for trigger transmit API,
                                       Bit6: Support for Tx from confirmation,
                                       Bit5: Dynamic TxPdu,
                                       Bit4: Default state of dynamic TxPdu,
                                       Bit3: RESERVED,
                                       Bit2: Support for DAQ DTO packages,
                                       Bit1: Support for EV/SERV CTO packages,
                                       Bit0: Support for RES/ERR CTO packages */
}Xcp_TxLPduIdConfType;

/** \brief Data structure storing property information regarding receive PDU. */
typedef struct
{
  uint32 PduCanId;                 /* CAN Id for the selected PDU */
  Xcp_LPduLengthType LPduStartPos; /* the start position of the PDU data inside LPDU buffer
                                      when FLX_ASSIGN is not used on that connection */
  PduIdType IntPduBufId;           /* map PDU to internal buffer Id */
  uint8 IntConnectionId;           /* maps PDU internal id towards a Xcp connection Id. */
  uint8 Properties;                /* Additional configuration properties:
                                      Bit7: RESERVED,
                                      Bit6: Support for Rx from indication,
                                      Bit5: Dynamic RxPdu,
                                      Bit4: Default state of dynamic RxPdu,
                                      Bit3: RESERVED,
                                      Bit2: RESERVED,
                                      Bit1: Support for STIM DTO packages,
                                      Bit0: Support for CMD CTO packages */
}Xcp_RxLPduIdConfType;


/** \brief Configuration data structure for Xcp connection */
typedef struct
{
  P2CONST(PduIdType, TYPEDEF, XCP_APPL_CONST) TxPduIdList;     /* list of the Tx Pdus
                                                                 * mapped to connection*/
  PduLengthType PduLengthMax;    /* maximum size for a PDU */
  PduLengthType PduHeaderLength; /* Pdu header size */
  PduIdType TxPduMax;            /* number of mapped Tx PDUs to connection */
  PduIdType RxPduMax;            /* number of mapped Rx PDUs to connection */
  PduIdType CtoSlavePduId;       /* PDU channel, used to receive CMD data GET_SLAVE_ID. */
  PduIdType BroadcastPduId;      /* PDU channel, used to receive bradcasted GET_SLAVE_ID. */
  uint8 IntCounterId;            /* Id of internal package counter */
  uint8 Properties;              /* Additional connection configuration properties:
                                    Bit7: RESERVED,
                                    Bit6: RESERVED
                                    Bit5: RESERVED,
                                    Bit4: RESERVED,
                                    Bit3: MaxDlcRequired is enabled,
                                    Bit2: FLX_ASSIGN is supported,
                                    Bit1: Automatically open the socket connections,
                                    Bit0: Support for multiple Pdus in one frame */
  uint8 ConnectionType;          /* Xcp connection type */
}Xcp_ConnectionCfgType;

/** \brief Status information used to route lower layer Pdu Id to Xcp Internal Pdu Id. */
typedef struct
{
  PduIdType LowerLayerPduId;  /** the lower layer Pdu Id used by the lower layer to notify Xcp */
  PduIdType XcpInternalPduId; /** the internal Xcp Pdu Id mapped to the lower layer Pdu Id */
}Xcp_LPduIdRouteConfType;


/*==================[external function declarations]=========================*/






/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

#define XCP_START_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/** \brief Configuration placeholder for Xcp_Init() call. */
extern CONST( Xcp_ConfigType, XCP_CONST ) XcpConfig;

#define XCP_STOP_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/


#define XCP_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include <MemMap.h>

/** \brief All DAQ list related information grouped together. */
//TODO ANDI
extern VAR(Xcp_AllDaqListsType, XCP_VAR_NOINIT) Xcp_DaqLists;

#define XCP_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include <MemMap.h>

   


#define XCP_START_SEC_VAR_8BIT
#include <MemMap.h>

#if ( (XCP_DEFAULT_XCP_MODULE_STATE == STD_ON) || (XCP_ENABLE_XCP_CONTROL_API == STD_ON) )
/** \brief Variable to hold the current state of Xcp module */
extern VAR(uint8, XCP_VAR) Xcp_ControlStateOfXcpModule;
#endif 

#define XCP_STOP_SEC_VAR_8BIT
#include <MemMap.h>
/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

#endif /* if !defined( XCP_CFG_H ) */
/*==================[end of file]============================================*/
