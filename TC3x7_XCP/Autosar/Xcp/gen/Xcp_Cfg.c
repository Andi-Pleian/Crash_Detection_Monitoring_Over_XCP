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

/* 
 * MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 11.3 (required)
 * A cast should not be performed between a pointer to object type and a different pointer to object type.
 *
 * Reason: The cast is required and unavoidable since there is no way of knowing what the configured memory area points to.
 */
/*==================[inclusions]============================================*/

#include <Std_Types.h>         /* AUTOSAR standard types */
#include <Xcp.h>               /* Module public API */
#if ( (XCP_DEFAULT_XCP_MODULE_STATE == STD_ON) || (XCP_ENABLE_XCP_CONTROL_API == STD_ON) )
#include <Xcp_Int.h>           /* Module internal interface */


/*==================[macros]================================================*/


/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[internal constants]====================================*/


#define XCP_START_SEC_CONST_8BIT
#include <MemMap.h>

/*  Event name of Event channel number : 0  */
STATIC CONST(uint8, XCP_CONST) Xcp_EventName_0[7] = {"BSW_1ms"};
/*  Event name of Event channel number : 1  */
STATIC CONST(uint8, XCP_CONST) Xcp_EventName_1[8] = {"BSW_10ms"};
/*  Event name of Event channel number : 2  */
STATIC CONST(uint8, XCP_CONST) Xcp_EventName_2[8] = {"BSW_20ms"};
/*  Event name of Event channel number : 3  */
STATIC CONST(uint8, XCP_CONST) Xcp_EventName_3[9] = {"BSW_100ms"};

#define XCP_STOP_SEC_CONST_8BIT
#include <MemMap.h>


#define XCP_START_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/** \brief List of Xcp Tx PDUs ordered by connection and by Xcp internal Id. */
STATIC CONST(PduIdType, XCP_CONST) Xcp_TxPduIdCfgList[XCP_NO_OF_TX_PDU_IDS] =
{
  /* Tx Pdu configuration for the XcpConnectionCfg_0 connection */
  0U,
  1U,
  2U,
  3U,
  4U,
  5U,
  6U,
  7U,
  8U,
};

#define XCP_STOP_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/*==================[external constants]====================================*/

#define XCP_START_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/** \brief Configuration placeholder for Xcp_Init() call. */
CONST( Xcp_ConfigType, XCP_CONST ) XcpConfig = { 0U };


/*----------------------------TxPduInfo--------------------------------------*/

/** \brief Tx Pdu Ids configured by the transport layer.
 **
 ** This Ids are used store information regarding:
 ** * mapping PDU toward connection
 ** * destination PDU id into transport layer configuration
 ** * start position of the PDU data inside the Tx PDU buffer area
 ** * supported Xcp communication transfer object types. */
CONST(Xcp_TxLPduIdConfType, XCP_CONST )  Xcp_TxLPduIdConf[XCP_NO_OF_TX_PDU_IDS] =
{
  { /* Mapping information for XcpTxPdu_dummy32bslave_T Pdu. */
    0U,  /* LPdu data start position into Tx buffer data */
    8U,  /* FrIf destination PDU id */
    0U,  /* associated internal buffer Id */
    0U,  /* Xcp connection Id(XcpConnectionCfg_0) */
    (XCP_SUPPORT_FOR_TRIGGER_TRANSMIT |
     XCP_SUPPORT_FOR_RESERR_CTO_PDU), /* Properties and supported types for this PDU */
  },
  { /* Mapping information for XcpTxPdu_xcpdynamic254_1_T Pdu. */
    20U,  /* LPdu data start position into Tx buffer data */
    19U,  /* FrIf destination PDU id */
    1U,  /* associated internal buffer Id */
    0U,  /* Xcp connection Id(XcpConnectionCfg_0) */
    (XCP_SUPPORT_FOR_TRIGGER_TRANSMIT |
     XCP_SUPPORT_FOR_DAQ_DTO_PDU), /* Properties and supported types for this PDU */
  },
  { /* Mapping information for XcpTxPdu_xcpdynamic254_2_T Pdu. */
    40U,  /* LPdu data start position into Tx buffer data */
    20U,  /* FrIf destination PDU id */
    2U,  /* associated internal buffer Id */
    0U,  /* Xcp connection Id(XcpConnectionCfg_0) */
    (XCP_SUPPORT_FOR_TRIGGER_TRANSMIT |
     XCP_SUPPORT_FOR_DAQ_DTO_PDU), /* Properties and supported types for this PDU */
  },
  { /* Mapping information for XcpTxPdu_xcpdynamic254_3_T Pdu. */
    60U,  /* LPdu data start position into Tx buffer data */
    21U,  /* FrIf destination PDU id */
    3U,  /* associated internal buffer Id */
    0U,  /* Xcp connection Id(XcpConnectionCfg_0) */
    (XCP_SUPPORT_FOR_TRIGGER_TRANSMIT |
     XCP_SUPPORT_FOR_DAQ_DTO_PDU), /* Properties and supported types for this PDU */
  },
  { /* Mapping information for XcpTxPdu_xcpdynamic254_4_T Pdu. */
    80U,  /* LPdu data start position into Tx buffer data */
    22U,  /* FrIf destination PDU id */
    4U,  /* associated internal buffer Id */
    0U,  /* Xcp connection Id(XcpConnectionCfg_0) */
    (XCP_SUPPORT_FOR_TRIGGER_TRANSMIT |
     XCP_SUPPORT_FOR_DAQ_DTO_PDU), /* Properties and supported types for this PDU */
  },
  { /* Mapping information for XcpTxPdu_xcpdynamic254_5_T Pdu. */
    100U,  /* LPdu data start position into Tx buffer data */
    23U,  /* FrIf destination PDU id */
    5U,  /* associated internal buffer Id */
    0U,  /* Xcp connection Id(XcpConnectionCfg_0) */
    (XCP_SUPPORT_FOR_TRIGGER_TRANSMIT |
     XCP_SUPPORT_FOR_DAQ_DTO_PDU), /* Properties and supported types for this PDU */
  },
  { /* Mapping information for XcpTxPdu_xcpdynamic254_6_T Pdu. */
    120U,  /* LPdu data start position into Tx buffer data */
    24U,  /* FrIf destination PDU id */
    6U,  /* associated internal buffer Id */
    0U,  /* Xcp connection Id(XcpConnectionCfg_0) */
    (XCP_SUPPORT_FOR_TRIGGER_TRANSMIT |
     XCP_SUPPORT_FOR_DAQ_DTO_PDU), /* Properties and supported types for this PDU */
  },
  { /* Mapping information for XcpTxPdu_xcpdynamic254_7_T Pdu. */
    140U,  /* LPdu data start position into Tx buffer data */
    25U,  /* FrIf destination PDU id */
    7U,  /* associated internal buffer Id */
    0U,  /* Xcp connection Id(XcpConnectionCfg_0) */
    (XCP_SUPPORT_FOR_TRIGGER_TRANSMIT |
     XCP_SUPPORT_FOR_DAQ_DTO_PDU), /* Properties and supported types for this PDU */
  },
  { /* Mapping information for XcpTxPdu_xcpdynamic254_8_T Pdu. */
    160U,  /* LPdu data start position into Tx buffer data */
    26U,  /* FrIf destination PDU id */
    8U,  /* associated internal buffer Id */
    0U,  /* Xcp connection Id(XcpConnectionCfg_0) */
    (XCP_SUPPORT_FOR_TRIGGER_TRANSMIT |
     XCP_SUPPORT_FOR_DAQ_DTO_PDU), /* Properties and supported types for this PDU */
  },
};

/*----------------------------RxPduInfo--------------------------------------*/

/** \brief Rx Pdu Ids configured by the transport layer.
 **
 ** This Ids are used store information regarding:
 ** * mapping PDU toward connection
 ** * start position of the PDU data inside the Rx PDU buffer area
 ** * supported Xcp communication transfer object types. */
CONST(Xcp_RxLPduIdConfType, XCP_CONST )  Xcp_RxLPduIdConf[XCP_NO_OF_RX_PDU_IDS] =
{
  { /* Mapping information for XcpRxPdu_dummy32bmaster_R Pdu. */
    0U,  /* LPdu data start position into Rx buffer data */
    0U,  /* associated internal buffer Id */
    0U,  /* Xcp connection Id(XcpConnectionCfg_0) */
    (XCP_SUPPORT_FOR_CMD_CTO_PDU |
     XCP_SUPPORT_FOR_STIM_DTO_PDU), /* Properties and supported types for this PDU */
  },
};

/*----------------------------XcpConnectionCfg--------------------------------------*/

/** \brief Connection configuration info */
CONST(Xcp_ConnectionCfgType, XCP_CONST) Xcp_ConnectionCfg[XCP_NO_OF_CONNECTIONS] =
{
  /* configuration information for XcpConnectionCfg_0 connection(Xcp over FLEXRAY). */
  {
    &Xcp_TxPduIdCfgList[0U], /* start position for the mapped Tx Pdu list */
    20U, /* PDU maximum length */
    3U, /* PDU header size */
    9U, /* number of mapped Tx PDUs towards connection */
    1U, /* number of mapped Rx PDUs towards connection */
    0U, /* Id of the packet counter */
    0U, /* configured NAX address for the slave */
    1U,  /* Package Alignment */
    (XCP_MULTI_PDUS_IN_FRAME_FLAG |
     XCP_SEQUENCE_CORRECTION_FLAG), /* connection flags */
    XCP_CONNECTION_OVER_FLEXRAY, /* connection type */
  },
};


/** \brief Configured event properties used to restore after a session is started */
CONST(Xcp_EventInfoType, XCP_CONST) Xcp_EventInfo[XCP_MAX_EVENT_CHANNEL] =
{
  {
    /* The event channel cycle counter maximum value */
    1U,
    /* The name of the event */
    Xcp_EventName_0,
    /* Pointer to the list of DAQ IDs of this event */
    NULL_PTR,
    /* The number of DAQ Lists of this event */
    0U,
    /* The length of the event name */
    7U,
    /* Consistency and STIM/DAQ, both direction combine configured for this event */
    XCP_EVENT_CHANNEL_DIRECTION_DAQ_STIM | XCP_EVENT_CHANNEL_CONSISTENCY_DAQ,
    /* Maximum number of DAQ supported for this event */
    1U,
    /* The priority of this event */
    0U,
    /* The sampling period of this event */
    1U,
    /* The unit of the event channel time cycle */
    XCP_TIMESTAMP_UNIT_1MS_MASK,
  },
  {
    /* The event channel cycle counter maximum value */
    10U,
    /* The name of the event */
    Xcp_EventName_1,
    /* Pointer to the list of DAQ IDs of this event */
    NULL_PTR,
    /* The number of DAQ Lists of this event */
    0U,
    /* The length of the event name */
    8U,
    /* Consistency and STIM/DAQ, both direction combine configured for this event */
    XCP_EVENT_CHANNEL_DIRECTION_DAQ_STIM | XCP_EVENT_CHANNEL_CONSISTENCY_DAQ,
    /* Maximum number of DAQ supported for this event */
    1U,
    /* The priority of this event */
    0U,
    /* The sampling period of this event */
    10U,
    /* The unit of the event channel time cycle */
    XCP_TIMESTAMP_UNIT_1MS_MASK,
  },
  {
    /* The event channel cycle counter maximum value */
    20U,
    /* The name of the event */
    Xcp_EventName_2,
    /* Pointer to the list of DAQ IDs of this event */
    NULL_PTR,
    /* The number of DAQ Lists of this event */
    0U,
    /* The length of the event name */
    8U,
    /* Consistency and STIM/DAQ, both direction combine configured for this event */
    XCP_EVENT_CHANNEL_DIRECTION_DAQ_STIM | XCP_EVENT_CHANNEL_CONSISTENCY_DAQ,
    /* Maximum number of DAQ supported for this event */
    1U,
    /* The priority of this event */
    0U,
    /* The sampling period of this event */
    20U,
    /* The unit of the event channel time cycle */
    XCP_TIMESTAMP_UNIT_1MS_MASK,
  },
  {
    /* The event channel cycle counter maximum value */
    100U,
    /* The name of the event */
    Xcp_EventName_3,
    /* Pointer to the list of DAQ IDs of this event */
    NULL_PTR,
    /* The number of DAQ Lists of this event */
    0U,
    /* The length of the event name */
    9U,
    /* Consistency and STIM/DAQ, both direction combine configured for this event */
    XCP_EVENT_CHANNEL_DIRECTION_DAQ_STIM | XCP_EVENT_CHANNEL_CONSISTENCY_DAQ,
    /* Maximum number of DAQ supported for this event */
    1U,
    /* The priority of this event */
    0U,
    /* The sampling period of this event */
    100U,
    /* The unit of the event channel time cycle */
    XCP_TIMESTAMP_UNIT_1MS_MASK,
  },
};

/** \brief Configuration of Event Ids which  processed by the MainFunction,
 **        in the priority order */
CONST(uint16, XCP_CONST) Xcp_MFEventCfg[XCP_MAX_MF_PROCESSED_EVENTS] =
{
  0U,  /* event BSW_1ms */
  1U,  /* event BSW_10ms */
  2U,  /* event BSW_20ms */
  3U,  /* event BSW_100ms */
};

/** \brief Cyclic Events Ids which are set by MainFunction */
CONST(uint16, XCP_CONST) Xcp_MFCyclicEventCfg[XCP_MAX_CYCLIC_EVENT_CHANNEL] =
{
  0U,  /* event BSW_1ms */
  1U,  /* event BSW_10ms */
  2U,  /* event BSW_20ms */
  3U,  /* event BSW_100ms */
};


 





/** \brief Configured Flexray Buffers */
CONST(Xcp_FlxBufType, XCP_CONST) Xcp_FlxBufConfig[XCP_NO_OF_FLX_BUF_CONFIGURED] =
{
  {
    0, /* ID of the FLX_BUF */
    36, /* LPDU_ID of the FLX_BUF */
    0, /* index in either Xcp_TxLPduIdConf or Xcp_RxLPduIdConf */
    0, /* Controller ID corresponding LPDU_ID */
    XCP_FLX_BUF_VALUE_FIXED, /* MAX_FLX_LEN_BUF properties */
    32, /* MAX_FLX_LEN_BUF initial value */
    XCP_FLX_BUF_VALUE_FIXED, /* SLOT_ID properties */
    219, /* SLOT_ID initial value */
    XCP_FLX_BUF_VALUE_FIXED, /* OFFSET properties */
    0, /* OFFSET initial value */
    XCP_FLX_BUF_VALUE_FIXED, /* CYCLE_REPETITION properties */
    1, /* CYCLE_REPETITION initial value */
    XCP_FLX_BUF_VALUE_FIXED, /* CHANNEL properties */
    XCP_FLX_BUF_VALUE_CHANNEL_A, /* CHANNEL initial value */
    (XCP_BUFFER_PRECONFIGURED_MASK |
     XCP_BUFFER_FIXED_MASK), /* Buffer flags */
  },

  {
    1, /* ID of the FLX_BUF */
    80, /* LPDU_ID of the FLX_BUF */
    1, /* index in either Xcp_TxLPduIdConf or Xcp_RxLPduIdConf */
    0, /* Controller ID corresponding LPDU_ID */
    XCP_FLX_BUF_VALUE_FIXED, /* MAX_FLX_LEN_BUF properties */
    254, /* MAX_FLX_LEN_BUF initial value */
    XCP_FLX_BUF_VALUE_FIXED, /* SLOT_ID properties */
    294, /* SLOT_ID initial value */
    XCP_FLX_BUF_VALUE_FIXED, /* OFFSET properties */
    0, /* OFFSET initial value */
    XCP_FLX_BUF_VALUE_FIXED, /* CYCLE_REPETITION properties */
    1, /* CYCLE_REPETITION initial value */
    XCP_FLX_BUF_VALUE_FIXED, /* CHANNEL properties */
    XCP_FLX_BUF_VALUE_CHANNEL_A, /* CHANNEL initial value */
    (XCP_BUFFER_DIRECTION_TX_MASK |
     XCP_BUFFER_PRECONFIGURED_MASK |
     XCP_BUFFER_FIXED_MASK), /* Buffer flags */
  },

  {
    2, /* ID of the FLX_BUF */
    81, /* LPDU_ID of the FLX_BUF */
    2, /* index in either Xcp_TxLPduIdConf or Xcp_RxLPduIdConf */
    0, /* Controller ID corresponding LPDU_ID */
    XCP_FLX_BUF_VALUE_FIXED, /* MAX_FLX_LEN_BUF properties */
    254, /* MAX_FLX_LEN_BUF initial value */
    XCP_FLX_BUF_VALUE_FIXED, /* SLOT_ID properties */
    295, /* SLOT_ID initial value */
    XCP_FLX_BUF_VALUE_FIXED, /* OFFSET properties */
    0, /* OFFSET initial value */
    XCP_FLX_BUF_VALUE_FIXED, /* CYCLE_REPETITION properties */
    1, /* CYCLE_REPETITION initial value */
    XCP_FLX_BUF_VALUE_FIXED, /* CHANNEL properties */
    XCP_FLX_BUF_VALUE_CHANNEL_A, /* CHANNEL initial value */
    (XCP_BUFFER_DIRECTION_TX_MASK |
     XCP_BUFFER_PRECONFIGURED_MASK |
     XCP_BUFFER_FIXED_MASK), /* Buffer flags */
  },

  {
    3, /* ID of the FLX_BUF */
    82, /* LPDU_ID of the FLX_BUF */
    3, /* index in either Xcp_TxLPduIdConf or Xcp_RxLPduIdConf */
    0, /* Controller ID corresponding LPDU_ID */
    XCP_FLX_BUF_VALUE_FIXED, /* MAX_FLX_LEN_BUF properties */
    254, /* MAX_FLX_LEN_BUF initial value */
    XCP_FLX_BUF_VALUE_FIXED, /* SLOT_ID properties */
    296, /* SLOT_ID initial value */
    XCP_FLX_BUF_VALUE_FIXED, /* OFFSET properties */
    0, /* OFFSET initial value */
    XCP_FLX_BUF_VALUE_FIXED, /* CYCLE_REPETITION properties */
    1, /* CYCLE_REPETITION initial value */
    XCP_FLX_BUF_VALUE_FIXED, /* CHANNEL properties */
    XCP_FLX_BUF_VALUE_CHANNEL_A, /* CHANNEL initial value */
    (XCP_BUFFER_DIRECTION_TX_MASK |
     XCP_BUFFER_PRECONFIGURED_MASK |
     XCP_BUFFER_FIXED_MASK), /* Buffer flags */
  },

  {
    4, /* ID of the FLX_BUF */
    83, /* LPDU_ID of the FLX_BUF */
    4, /* index in either Xcp_TxLPduIdConf or Xcp_RxLPduIdConf */
    0, /* Controller ID corresponding LPDU_ID */
    XCP_FLX_BUF_VALUE_FIXED, /* MAX_FLX_LEN_BUF properties */
    254, /* MAX_FLX_LEN_BUF initial value */
    XCP_FLX_BUF_VALUE_FIXED, /* SLOT_ID properties */
    297, /* SLOT_ID initial value */
    XCP_FLX_BUF_VALUE_FIXED, /* OFFSET properties */
    0, /* OFFSET initial value */
    XCP_FLX_BUF_VALUE_FIXED, /* CYCLE_REPETITION properties */
    1, /* CYCLE_REPETITION initial value */
    XCP_FLX_BUF_VALUE_FIXED, /* CHANNEL properties */
    XCP_FLX_BUF_VALUE_CHANNEL_A, /* CHANNEL initial value */
    (XCP_BUFFER_DIRECTION_TX_MASK |
     XCP_BUFFER_PRECONFIGURED_MASK |
     XCP_BUFFER_FIXED_MASK), /* Buffer flags */
  },

  {
    5, /* ID of the FLX_BUF */
    84, /* LPDU_ID of the FLX_BUF */
    5, /* index in either Xcp_TxLPduIdConf or Xcp_RxLPduIdConf */
    0, /* Controller ID corresponding LPDU_ID */
    XCP_FLX_BUF_VALUE_FIXED, /* MAX_FLX_LEN_BUF properties */
    254, /* MAX_FLX_LEN_BUF initial value */
    XCP_FLX_BUF_VALUE_FIXED, /* SLOT_ID properties */
    298, /* SLOT_ID initial value */
    XCP_FLX_BUF_VALUE_FIXED, /* OFFSET properties */
    0, /* OFFSET initial value */
    XCP_FLX_BUF_VALUE_FIXED, /* CYCLE_REPETITION properties */
    1, /* CYCLE_REPETITION initial value */
    XCP_FLX_BUF_VALUE_FIXED, /* CHANNEL properties */
    XCP_FLX_BUF_VALUE_CHANNEL_A, /* CHANNEL initial value */
    (XCP_BUFFER_DIRECTION_TX_MASK |
     XCP_BUFFER_PRECONFIGURED_MASK |
     XCP_BUFFER_FIXED_MASK), /* Buffer flags */
  },

  {
    6, /* ID of the FLX_BUF */
    85, /* LPDU_ID of the FLX_BUF */
    6, /* index in either Xcp_TxLPduIdConf or Xcp_RxLPduIdConf */
    0, /* Controller ID corresponding LPDU_ID */
    XCP_FLX_BUF_VALUE_FIXED, /* MAX_FLX_LEN_BUF properties */
    254, /* MAX_FLX_LEN_BUF initial value */
    XCP_FLX_BUF_VALUE_FIXED, /* SLOT_ID properties */
    299, /* SLOT_ID initial value */
    XCP_FLX_BUF_VALUE_FIXED, /* OFFSET properties */
    0, /* OFFSET initial value */
    XCP_FLX_BUF_VALUE_FIXED, /* CYCLE_REPETITION properties */
    1, /* CYCLE_REPETITION initial value */
    XCP_FLX_BUF_VALUE_FIXED, /* CHANNEL properties */
    XCP_FLX_BUF_VALUE_CHANNEL_A, /* CHANNEL initial value */
    (XCP_BUFFER_DIRECTION_TX_MASK |
     XCP_BUFFER_PRECONFIGURED_MASK |
     XCP_BUFFER_FIXED_MASK), /* Buffer flags */
  },

  {
    7, /* ID of the FLX_BUF */
    86, /* LPDU_ID of the FLX_BUF */
    7, /* index in either Xcp_TxLPduIdConf or Xcp_RxLPduIdConf */
    0, /* Controller ID corresponding LPDU_ID */
    XCP_FLX_BUF_VALUE_FIXED, /* MAX_FLX_LEN_BUF properties */
    254, /* MAX_FLX_LEN_BUF initial value */
    XCP_FLX_BUF_VALUE_FIXED, /* SLOT_ID properties */
    300, /* SLOT_ID initial value */
    XCP_FLX_BUF_VALUE_FIXED, /* OFFSET properties */
    0, /* OFFSET initial value */
    XCP_FLX_BUF_VALUE_FIXED, /* CYCLE_REPETITION properties */
    1, /* CYCLE_REPETITION initial value */
    XCP_FLX_BUF_VALUE_FIXED, /* CHANNEL properties */
    XCP_FLX_BUF_VALUE_CHANNEL_A, /* CHANNEL initial value */
    (XCP_BUFFER_DIRECTION_TX_MASK |
     XCP_BUFFER_PRECONFIGURED_MASK |
     XCP_BUFFER_FIXED_MASK), /* Buffer flags */
  },

  {
    8, /* ID of the FLX_BUF */
    87, /* LPDU_ID of the FLX_BUF */
    8, /* index in either Xcp_TxLPduIdConf or Xcp_RxLPduIdConf */
    0, /* Controller ID corresponding LPDU_ID */
    XCP_FLX_BUF_VALUE_FIXED, /* MAX_FLX_LEN_BUF properties */
    254, /* MAX_FLX_LEN_BUF initial value */
    XCP_FLX_BUF_VALUE_FIXED, /* SLOT_ID properties */
    201, /* SLOT_ID initial value */
    XCP_FLX_BUF_VALUE_FIXED, /* OFFSET properties */
    0, /* OFFSET initial value */
    XCP_FLX_BUF_VALUE_FIXED, /* CYCLE_REPETITION properties */
    1, /* CYCLE_REPETITION initial value */
    XCP_FLX_BUF_VALUE_FIXED, /* CHANNEL properties */
    XCP_FLX_BUF_VALUE_CHANNEL_A, /* CHANNEL initial value */
    (XCP_BUFFER_DIRECTION_TX_MASK |
     XCP_BUFFER_PRECONFIGURED_MASK |
     XCP_BUFFER_FIXED_MASK), /* Buffer flags */
  },

  {
    9, /* ID of the FLX_BUF */
    37, /* LPDU_ID of the FLX_BUF */
    0, /* index in either Xcp_TxLPduIdConf or Xcp_RxLPduIdConf */
    0, /* Controller ID corresponding LPDU_ID */
    XCP_FLX_BUF_VALUE_FIXED, /* MAX_FLX_LEN_BUF properties */
    32, /* MAX_FLX_LEN_BUF initial value */
    XCP_FLX_BUF_VALUE_FIXED, /* SLOT_ID properties */
    220, /* SLOT_ID initial value */
    XCP_FLX_BUF_VALUE_FIXED, /* OFFSET properties */
    0, /* OFFSET initial value */
    XCP_FLX_BUF_VALUE_FIXED, /* CYCLE_REPETITION properties */
    1, /* CYCLE_REPETITION initial value */
    XCP_FLX_BUF_VALUE_FIXED, /* CHANNEL properties */
    XCP_FLX_BUF_VALUE_CHANNEL_A, /* CHANNEL initial value */
    (XCP_BUFFER_DIRECTION_TX_MASK |
     XCP_BUFFER_PRECONFIGURED_MASK |
     XCP_BUFFER_FIXED_MASK), /* Buffer flags */
  },

};


/* Deviation MISRAC2012-1 <START> */
/** \brief Array holding the configured memory areas */
CONST(Xcp_MemoryAreaType, XCP_CONST) Xcp_MemoryAreas[XCP_NUMBER_OF_MEMORY_AREAS] =
{
  {
   /* The memory area start address */
   (P2VAR(uint8, XCP_CONST, XCP_APPL_DATA))0,
   /* The memory area length */
   0xfffffffeU,
   /* The memory area access type (read or/and write) */
   XCP_MEMORY_AREA_TYPE_READ_WRITE,
   /* The memory area scope (calibration and/or DAQ_STIM) */
   XCP_MEMORY_AREA_SCOPE_ALL,
  },
};
/* Deviation MISRAC2012-1 <STOP> */

#define XCP_STOP_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/*==================[internal data]=========================================*/



#define XCP_START_SEC_VAR_16BIT
#include <MemMap.h>

/** \brief List of DAQ IDs in the order of events */
STATIC VAR(Xcp_DaqIdType, XCP_VAR) Xcp_DaqIdList[XCP_EVENT_CHANNEL_TOTAL_DAQ] =
{
  /* Daq list configuration for BSW_1ms. */
  XCP_DUMMY_DAQ_LIST,
  /* Daq list configuration for BSW_10ms. */
  XCP_DUMMY_DAQ_LIST,
  /* Daq list configuration for BSW_20ms. */
  XCP_DUMMY_DAQ_LIST,
  /* Daq list configuration for BSW_100ms. */
  XCP_DUMMY_DAQ_LIST,
};


#define XCP_STOP_SEC_VAR_16BIT
#include <MemMap.h>

/*==================[external data]=========================================*/
#define XCP_START_SEC_VAR_UNSPECIFIED
#include <MemMap.h>

#define XCP_STOP_SEC_VAR_UNSPECIFIED
#include <MemMap.h>

#define XCP_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include <MemMap.h>

/** \brief All runtime DAQ lists together with ODTs and ODT entries and admin data*/
VAR(Xcp_AllDaqListsType, XCP_VAR_NOINIT) Xcp_DaqLists;

#define XCP_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include <MemMap.h>

#define XCP_START_SEC_VAR_UNSPECIFIED
#include <MemMap.h>

/** \brief Event */
VAR(Xcp_EventType, XCP_VAR) Xcp_Event[XCP_MAX_EVENT_CHANNEL] =
{
  {
    /* Time Cycle Counter */
    1U,
    /* Pointer to the list of DAQ IDs of this event */
    &Xcp_DaqIdList[0],
    /* Next DAQ index to be sampled */
    0U,
    /* Next ODT to be sampled */
    0U,
    /* The number of DAQ Lists of this event */
    0,
    /* Flag signaling whether this event was set (cyclically or via Xcp_SetEvent()) */
    FALSE,
  },
  {
    /* Time Cycle Counter */
    1U,
    /* Pointer to the list of DAQ IDs of this event */
    &Xcp_DaqIdList[1],
    /* Next DAQ index to be sampled */
    0U,
    /* Next ODT to be sampled */
    0U,
    /* The number of DAQ Lists of this event */
    0,
    /* Flag signaling whether this event was set (cyclically or via Xcp_SetEvent()) */
    FALSE,
  },
  {
    /* Time Cycle Counter */
    1U,
    /* Pointer to the list of DAQ IDs of this event */
    &Xcp_DaqIdList[2],
    /* Next DAQ index to be sampled */
    0U,
    /* Next ODT to be sampled */
    0U,
    /* The number of DAQ Lists of this event */
    0,
    /* Flag signaling whether this event was set (cyclically or via Xcp_SetEvent()) */
    FALSE,
  },
  {
    /* Time Cycle Counter */
    1U,
    /* Pointer to the list of DAQ IDs of this event */
    &Xcp_DaqIdList[3],
    /* Next DAQ index to be sampled */
    0U,
    /* Next ODT to be sampled */
    0U,
    /* The number of DAQ Lists of this event */
    0,
    /* Flag signaling whether this event was set (cyclically or via Xcp_SetEvent()) */
    FALSE,
  },
};

#define XCP_STOP_SEC_VAR_UNSPECIFIED
#include <MemMap.h>

#define XCP_START_SEC_VAR_8BIT
#include <MemMap.h>

VAR(uint8, XCP_VAR) Xcp_ControlStateOfXcpModule =          XCP_STATE_ACTIVE;

#define XCP_STOP_SEC_VAR_8BIT
#include <MemMap.h>
/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/
#endif /*( (XCP_DEFAULT_XCP_MODULE_STATE == STD_ON) || (XCP_ENABLE_XCP_CONTROL_API == STD_ON) )*/
/*==================[end of file]===========================================*/
