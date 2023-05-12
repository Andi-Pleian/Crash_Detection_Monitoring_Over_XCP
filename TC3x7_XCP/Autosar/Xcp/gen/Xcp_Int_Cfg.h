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
/* This file contains the generated Xcp module internal configuration. */

#if (!defined XCP_INT_CFG_H)
#define XCP_INT_CFG_H

/*==================[includes]===============================================*/

#include <Std_Types.h>      /* AUTOSAR standard types */
#include <TSAutosar.h>      /* EB specific standard types */
#include <Xcp_Int_Stc.h>    /* Internal static header file */

/*==================[macros]=================================================*/

#if (defined XCP_DEV_ERROR_DETECT)
#error XCP_DEV_ERROR_DETECT already defined
#endif
/** \brief Switch, indicating whether the detection of development errors is
** activated or deactivated for XCP */
#define XCP_DEV_ERROR_DETECT         STD_OFF
#if (defined XCP_MAIN_FUNCTION_PERIOD)
#error XCP_MAIN_FUNCTION_PERIOD already defined
#endif
/** \brief The period between successive ticks in seconds. */
#define XCP_MAIN_FUNCTION_PERIOD     0.001

#if (defined XCP_PROD_ERR_HANDLING_RETRY_FAILED)
#error XCP_PROD_ERR_HANDLING_RETRY_FAILED already defined
#endif
/** \brief Switch for DEM to DET reporting for Xcp Retry failure */
#define XCP_PROD_ERR_HANDLING_RETRY_FAILED    TS_PROD_ERR_DISABLE

#if (defined XCP_PROD_ERR_HANDLING_PDU_BUFFER_LOCKED)
#error XCP_PROD_ERR_HANDLING_PDU_BUFFER_LOCKED already defined
#endif
/** \brief Switch for DEM to DET reporting for PDU Buffer Locked */
#define XCP_PROD_ERR_HANDLING_PDU_BUFFER_LOCKED   TS_PROD_ERR_DISABLE

#if (defined XCP_PROD_ERR_HANDLING_ILLEGAL_MEMORY_ACCESS)
#error XCP_PROD_ERR_HANDLING_ILLEGAL_MEMORY_ACCESS already defined
#endif
/** \brief Switch for DEM to DET reporting for Xcp Illegal Memory Access */
#define XCP_PROD_ERR_HANDLING_ILLEGAL_MEMORY_ACCESS    TS_PROD_ERR_DISABLE

#if (defined XCP_PROD_ERR_HANDLING_RESP_CTO_QUEUE_FULL)
#error XCP_PROD_ERR_HANDLING_RESP_CTO_QUEUE_FULL already defined
#endif
/** \brief Switch for DEM to DET reporting for response CTO Queue full */
#define XCP_PROD_ERR_HANDLING_RESP_CTO_QUEUE_FULL    TS_PROD_ERR_DISABLE


#if (defined XCP_PROD_ERR_HANDLING_PDU_LOST)
#error XCP_PROD_ERR_HANDLING_PDU_LOST already defined
#endif
/** \brief Switch for DEM to DET reporting for response PDU Lost */
#define XCP_PROD_ERR_HANDLING_PDU_LOST    TS_PROD_ERR_DISABLE

#if (defined XCP_PROD_ERR_HANDLING_PDU_BUFFER_FULL)
#error XCP_PROD_ERR_HANDLING_PDU_BUFFER_FULL already defined
#endif
/** \brief Switch for DEM to DET reporting for response PDU Buffer Full */
#define XCP_PROD_ERR_HANDLING_PDU_BUFFER_FULL    TS_PROD_ERR_DISABLE


#if (defined XCP_PROD_ERR_HANDLING_STIMULATION_DATA_LOST)
#error XCP_PROD_ERR_HANDLING_STIMULATION_DATA_LOST already defined
#endif
/** \brief Switch for DEM to DET reporting for response Stimulation Data Lost */
#define XCP_PROD_ERR_HANDLING_STIMULATION_DATA_LOST    TS_PROD_ERR_DISABLE

#if (defined XCP_MEMORY_AREAS_ACCESS_SUPPORTED)
#error XCP_MEMORY_AREAS_ACCESS_SUPPORTED already defined
#endif
/** \brief Switch, indicating whether memory areas support is enabled or not  */
#define XCP_MEMORY_AREAS_ACCESS_SUPPORTED         STD_ON

#if (defined XCP_IDENTIFICATION_FIELD_TYPE)
#error XCP_IDENTIFICATION_FIELD_TYPE already defined
#endif
/** \brief Definition of value indicating the type of Packet Identification Field the slave
** will use while transferring DAQ Packets to the master.
**/
#define XCP_IDENTIFICATION_FIELD_TYPE XCP_ABSOLUTE_IF_MASK

#if (defined XCP_IDENTIFICATION_TYPE1_LENGTH)
#error XCP_IDENTIFICATION_TYPE1_LENGTH already defined
#endif
/** \brief Definition of Length of the identification information TYPE 1
* This is the length of ASCII value of ASAM-MC2 filename without path
* and extension.
*/
#define XCP_IDENTIFICATION_TYPE1_LENGTH  0x00U


#if (defined XCP_MAX_CTO)
#error XCP_MAX_CTO already defined
#endif
/** \brief The maximum length of XCP command transfer objects (CTO) packet in bytes.*/
#define XCP_MAX_CTO                  16U

#if (defined XCP_MAX_CTO_PGM)
#error XCP_MAX_CTO_PGM already defined
#endif
/** \brief The maximum length of XCP command transfer objects (CTO) packet in bytes during a flash
** programming sequence */

#define XCP_MAX_CTO_PGM             0U

#if (defined XCP_DAQ_CONFIG_TYPE)
#error XCP_DAQ_CONFIG_TYPE already defined
#endif
/** \brief Switch, indicating whether the DAQ lists that are not PREDEFINED shall be configured
** statically or dynamically.
**/
#define XCP_DAQ_CONFIG_TYPE          XCP_DAQ_DYNAMIC_MASK

#if (defined XCP_MAX_DTO)
#error XCP_MAX_DTO already defined
#endif
/** \brief The maximum length of XCP data transfer objects (DTO) packet in bytes. */
#define XCP_MAX_DTO                  16U

#if (defined XCP_MIN_DAQ)
#error XCP_MIN_DAQ already defined
#endif
/** \brief The number of predefined, read only DAQ lists on the XCP slave. */
#define XCP_MIN_DAQ                  0U

#if (defined XCP_DAQ_COUNT)
#error XCP_DAQ_COUNT already defined
#endif
/** \brief The maximum number of configurable dynamic DAQ lists */
#define XCP_DAQ_COUNT                  1U

#if (defined XCP_ODT_COUNT)
#error XCP_ODT_COUNT already defined
#endif
/** \brief Maximum number of ODTs allowed per dynamic DAQ list. */
#define XCP_ODT_COUNT                  8U


#if (defined XCP_MAX_MF_PROCESSED_EVENTS)
#error XCP_MAX_MF_PROCESSED_EVENTS already defined
#endif
/** \brief The number of event channels processed with the XCP mainFunction. */
#define XCP_MAX_MF_PROCESSED_EVENTS        4U

#if (defined XCP_MAX_EVENT_CHANNEL)
#error XCP_MAX_EVENT_CHANNEL already defined
#endif
/** \brief The number of event channels on the XCP slave. */
#define XCP_MAX_EVENT_CHANNEL        4U

#if (defined XCP_MAX_CYCLIC_EVENT_CHANNEL)
#error XCP_MAX_CYCLIC_EVENT_CHANNEL already defined
#endif
/** \brief The number of cyclic event channels on the XCP slave. */
#define XCP_MAX_CYCLIC_EVENT_CHANNEL 4U

#if (defined XCP_PRESCALER_SUPPORTED)
#error XCP_PRESCALER_SUPPORTED already defined
#endif
/** \brief Switch, indicating whether all DAQ lists support the prescaler for reducing the
** transmission period. */
#define XCP_PRESCALER_SUPPORTED      (0U)
#if (defined XCP_TIMESTAMP_SUPPORTED)
#error XCP_TIMESTAMP_SUPPORTED already defined
#endif
/** \brief Switch, indicating whether the slave supports time stamped data acquisition and
** stimulation. */
#define XCP_TIMESTAMP_SUPPORTED      (0U)

#if (defined XCP_TIMESTAMP_TICKS)
#error XCP_TIMESTAMP_TICKS already defined
#endif
/** \brief Definition of value indicating Timestamp units per tick. */
#define XCP_TIMESTAMP_TICKS          1U

#if (defined XCP_TIMESTAMP_TYPE)
#error XCP_TIMESTAMP_TYPE already defined
#endif
/** \brief The timestamp type (the number of bytes that the timestamp will have)*/
#define XCP_TIMESTAMP_TYPE           XCP_NO_TIME_STAMP_TS_MASK
#if (defined XCP_TIMESTAMP_UNIT)
#error XCP_TIMESTAMP_UNIT already defined
#endif
/** \brief Definition of value indicating the unit of the time stamp. */
#define XCP_TIMESTAMP_UNIT           0U



#if (defined XCP_RESOURCE_CAL_PAG)
#error XCP_RESOURCE_CAL_PAG already defined
#endif
/** \brief Switch, indicating whether calibration/paging functionality is available. */
#define XCP_RESOURCE_CAL_PAG         (0U)
#if (defined XCP_RESOURCE_DAQ)
#error XCP_RESOURCE_DAQ already defined
#endif
/** \brief Switch, indicating whether synchronous data acquisition functionality is available. */
#define XCP_RESOURCE_DAQ             XCP_RESOURCE_DAQ_MASK
#if (defined XCP_RESOURCE_STIM)
#error XCP_RESOURCE_STIM already defined
#endif
/** \brief Switch, indicating whether synchronous data stimulation functionality is available. */
#define XCP_RESOURCE_STIM            XCP_RESOURCE_STIM_MASK
#if (defined XCP_RESOURCE_PGM)
#error XCP_RESOURCE_PGM already defined
#endif
/** \brief Value of the PGM resource as needed by the protection status (see GET_STATUS command) */
#define XCP_RESOURCE_PGM             (0U)
#if (defined XCP_PGM_SUPPORTED)
#error XCP_PGM_SUPPORTED already defined
#endif
/** \brief Switch, indicating whether programming functionality is available.*/
#define XCP_PGM_SUPPORTED             STD_OFF
#if (defined XCP_ADDRESS_GRANULARITY)
#error XCP_ADDRESS_GRANULARITY already defined
#endif
/** \brief Bit values related to the address granularity of the
** COMM_MODE_BASIC parameter in CONNECT command parameter.
**/
#define XCP_ADDRESS_GRANULARITY      XCP_BYTE_AG_MASK

#if (defined XCP_ADDRESS_GRANULARITY_SIZE)
#error XCP_ADDRESS_GRANULARITY_SIZE already defined
#endif
/** \brief The size of an element contained at a single address in the slave. */
#define XCP_ADDRESS_GRANULARITY_SIZE XCP_BYTE_AG_SIZE

#if (defined XCP_MASTER_BLOCK_MODE)
#error XCP_MASTER_BLOCK_MODE already defined
#endif
/** \brief Switch, indicating whether master block mode functionality is available. */
#define XCP_MASTER_BLOCK_MODE        XCP_MASTER_BLOCK_MODE_MASK
#if (defined XCP_MASTER_BLOCK_MODE_SUPPORTED)
#error XCP_MASTER_BLOCK_MODE_SUPPORTED already defined
#endif
/** \brief Switch, indicating whether master block mode functionality is available. */
#define XCP_MASTER_BLOCK_MODE_SUPPORTED        STD_ON
#if (defined XCP_MAX_BS)
#error XCP_MAX_BS already defined
#endif
/** \brief Definition of the maximum number of consecutive command packets in a block sequence.
**  The value represents the initial DOWNLOAD command plus the consecutive DOWNLOAD_NEXT commands.
**/
#define XCP_MAX_BS                   19U
#if (defined XCP_MIN_ST)
#error XCP_MIN_ST already defined
#endif
/** \brief The required minimum separation time between the packets of a block
** transfer from the master device to the slave device in units of 100 microseconds. */
#define XCP_MIN_ST                   200U
#if (defined XCP_MASTER_BLOCK_MODE_PGM)
#error XCP_MASTER_BLOCK_MODE_PGM already defined
#endif
/** \brief Switch, indicating whether master block mode for programming is available. */
#define XCP_MASTER_BLOCK_MODE_PGM        (0U)
#if (defined XCP_MASTER_BLOCK_MODE_PGM_SUPPORTED)
#error XCP_MASTER_BLOCK_MODE_PGM_SUPPORTED already defined
#endif
/** \brief Switch, indicating whether master block mode for programming is available. */
#define XCP_MASTER_BLOCK_MODE_PGM_SUPPORTED        STD_OFF
#if (defined XCP_MAX_BS_PGM)
#error XCP_MAX_BS_PGM already defined
#endif
/** \brief Definition of the maximum number of consecutive command packets in a block sequence
**  for flash programming.
**  The value represents the initial PROGRAM command plus the consecutive PROGRAM_NEXT commands.
**/
#define XCP_MAX_BS_PGM                   (0U)
#if (defined XCP_MIN_ST_PGM)
#error XCP_MIN_ST_PGM already defined
#endif
/** \brief The required minimum separation time, for flash programming, between the packets of a block
** transfer from the master device to the slave device in units of 100 microseconds. */
#define XCP_MIN_ST_PGM                   (0U)
#if (defined XCP_TIMESTAMP_FIXED)
#error XCP_TIMESTAMP_FIXED already defined
#endif
/** \brief Switch, indicating whether time stamp fixed functionality is available. */

#define XCP_TIMESTAMP_FIXED    0U

#if (defined XCP_GRANULARITY_ODT_ENTRY_SIZE_DAQ)
#error XCP_GRANULARITY_ODT_ENTRY_SIZE_DAQ already defined
#endif
/** \brief Definition of value indicating granularity for size of ODT entry (DIRECTION = DAQ). */
#define XCP_GRANULARITY_ODT_ENTRY_SIZE_DAQ XCP_BYTE_AG_SIZE

#if (defined XCP_MAX_ODT_ENTRY_SIZE_DAQ)
#error XCP_MAX_ODT_ENTRY_SIZE_DAQ already defined
#endif
/** \brief Definition of value indicating the maximum size of ODT entry (DIRECTION = DAQ). */
#define XCP_MAX_ODT_ENTRY_SIZE_DAQ   8U

#if (defined XCP_GRANULARITY_ODT_ENTRY_SIZE_STIM)
#error XCP_GRANULARITY_ODT_ENTRY_SIZE_STIM already defined
#endif
/** \brief Definition of value indicating granularity for size of ODT entry (DIRECTION = STIM). */
#define XCP_GRANULARITY_ODT_ENTRY_SIZE_STIM XCP_BYTE_AG_SIZE

#if (defined XCP_MAX_ODT_ENTRY_SIZE_STIM)
#error XCP_MAX_ODT_ENTRY_SIZE_STIM already defined
#endif
/** \brief Definition of value indicating maximum size of ODT entry (DIRECTION = STIM). */
#define XCP_MAX_ODT_ENTRY_SIZE_STIM  1U


#if (defined XCP_MAX_ENTRIES_PER_ODT)
#error XCP_MAX_ENTRIES_PER_ODT already defined
#endif
/** \brief The absolute maximum number of ODT Entries in an ODT
**/
#define XCP_MAX_ENTRIES_PER_ODT   8U


#if (defined XCP_MAX_ENTRIES_PER_ODT_DYN)
#error XCP_MAX_ENTRIES_PER_ODT_DYN already defined
#endif
/** \brief The absolute maximum number of ODT Entries in an ODT belonging to a dynamic DAQ list.
** The ODT does not carry the timestamp (i.e. timestamp is disabled or not the first ODT in the
** DAQ list).
**/
#define XCP_MAX_ENTRIES_PER_ODT_DYN     8U

#if (defined XCP_MAX_ENTRIES_PER_ODT_DYN_TS)
#error XCP_MAX_ENTRIES_PER_ODT_DYN_TS already defined
#endif
/** \brief The maximum number of ODT Entries in an ODT belonging to a dynamic DAQ list which carries
** the timestamp (i.e. timestamp is enabled and the first ODT in the DAQ list).
**/
#define XCP_MAX_ENTRIES_PER_ODT_DYN_TS  8U

#if (defined XCP_OVERLOAD_INDICATION_TYPE)
#error XCP_OVERLOAD_INDICATION_TYPE already defined
#endif
/** \brief Definition of value indicating the method used to indicate overload situation to
** master. */
#define XCP_OVERLOAD_INDICATION_TYPE XCP_NO_OVERLOAD_INDICATION_OL_MASK
#if (defined XCP_OPTIMISATION_TYPE)
#error XCP_OPTIMISATION_TYPE already defined
#endif
/** \brief Definition of value indicating the type of optimisation method the master preferably
** should use. */
#define XCP_OPTIMISATION_TYPE        XCP_DEFAULT_OM_MASK

#if (defined XCP_ADDRESS_EXTENSION_TYPE)
#error XCP_ADDRESS_EXTENSION_TYPE already defined
#endif
/** \brief Switch, indicating whether the address extension
** of all entries within one ODT or within one DAQ must be the same. */
#define XCP_ADDRESS_EXTENSION_TYPE   XCP_FREE_AE_MASK

#if (defined XCP_MAXIMUM_ODT)
#error XCP_MAXIMUM_ODT already defined
#endif
/** \brief The number of ODTs allowed for a DAQ.
**
** \note Macro is introduced to have limit on number of ODTs allowed
** for a DAQ list.
**/
#define XCP_MAXIMUM_ODT             8U

#if (defined XCP_TX_RETRY_COUNT)
#error XCP_TX_RETRY_COUNT already defined
#endif
/** \brief The number of times the data will be retried for transmission.
** This retry mechanism is meant for the case when <TP>If_Transmit() rejects
** our transmission request.
**
** \note Macro is introduced to have limit on number of transmission retries
** when transmission fails.
**
**/
#define XCP_TX_RETRY_COUNT           5U


#if (defined XCP_TX_BUS_RETRY_COUNT)
#error XCP_TX_BUS_RETRY_COUNT already defined
#endif
/** \brief The number of times the PDU will be retried for transmission.
** Whenever we are waiting for the Tx Confirmation, if the bus timeout mechanism
** expires, we retry the entire transmission process for the configured amount of times. 
** 
** \note Not to be confused with XCP_TX_RETRY_COUNT which retries only the <TP>If_Transmit() requests
** when they are rejected.
**/
#define XCP_TX_BUS_RETRY_COUNT           5U

#if (defined XCP_TX_BUS_TO_COUNTER_MAX_VAL)
#error XCP_TX_BUS_TO_COUNTER_MAX_VAL already defined
#endif
/** \brief The number of Xcp_MainFunction calls until the XCP slave is autonomously DISCONNECTED.
**
** Macro is introduced to have the Bus Timeout limit in case the XCP TX processor remains
** stuck in one of the following states: TX Trigger/ TX Confirmation, after the pending message
** transmission was accepted by the underlying communication.
**
**/
#define XCP_TX_BUS_TO_COUNTER_MAX_VAL 2000U

#if (defined XCP_NO_DAQ_DTOS)
#error XCP_NO_DAQ_DTOS already defined
#endif
/** \brief Value indicating the number of all DTOs
**/
#define XCP_NO_DAQ_DTOS              8U

#if (defined XCP_MAX_ODT_IN_DAQ)
#error XCP_MAX_ODT_IN_DAQ already defined
#endif
/** \brief Value indicating the number of maximum ODT in a DAQ list
**/
#define XCP_MAX_ODT_IN_DAQ           8U


#if (defined XCP_NUMBER_OF_EVENT_MAIN_FUNCTIONS)
#error XCP_NUMBER_OF_EVENT_MAIN_FUNCTIONS already defined
#endif
/** \brief Value indicating the number of event main functions
**/
#define XCP_NUMBER_OF_EVENT_MAIN_FUNCTIONS           0U

/*------------------[PDU configuration options]------------------------------*/

#if (defined XCP_NO_OF_CANIF_RX_PDU_IDS)
#error XCP_NO_OF_CANIF_RX_PDU_IDS already defined
#endif
/** \brief Macro defining the maximum number of configured CanIf Rx Pdus **/
#define XCP_NO_OF_CANIF_RX_PDU_IDS                         0U

#if (defined XCP_NO_OF_CANIF_TX_PDU_IDS)
#error XCP_NO_OF_CANIF_TX_PDU_IDS already defined
#endif
/** \brief Macro defining the maximum number of configured CanIf Tx Pdus **/
#define XCP_NO_OF_CANIF_TX_PDU_IDS                         0U

#if (defined XCP_NO_OF_FRIF_RX_PDU_IDS)
#error XCP_NO_OF_FRIF_RX_PDU_IDS already defined
#endif
/** \brief Macro defining the maximum number of configured FrIf Rx Pdus **/
#define XCP_NO_OF_FRIF_RX_PDU_IDS                          1U

#if (defined XCP_NO_OF_FRIF_TX_PDU_IDS)
#error XCP_NO_OF_FRIF_TX_PDU_IDS already defined
#endif
/** \brief Macro defining the maximum number of configured FrIf Tx Pdus **/
#define XCP_NO_OF_FRIF_TX_PDU_IDS                          9U


#if (defined XCP_NO_OF_RX_PDU_IDS)
#error XCP_NO_OF_RX_PDU_IDS already defined
#endif
/** \brief Macro defining the maximum number of configured Rx Pdus **/
#define XCP_NO_OF_RX_PDU_IDS                               1U

#if (defined XCP_NO_OF_TX_PDU_IDS)
#error XCP_NO_OF_TX_PDU_IDS already defined
#endif
/** \brief Macro defining the maximum number of configured Tx Pdus **/
#define XCP_NO_OF_TX_PDU_IDS                               9U

#if (defined XCP_TX_BUFFER_SIZE)
#error XCP_TX_BUFFER_SIZE already defined
#endif
/** \brief Macro defining the size of transmit buffer */
#define XCP_TX_BUFFER_SIZE                                 2064U

#if (defined XCP_RX_BUFFER_SIZE)
#error XCP_RX_BUFFER_SIZE already defined
#endif
/** \brief Macro defining the size of receive buffer */
#define XCP_RX_BUFFER_SIZE                                 32U

#if (defined XCP_MAX_TX_PDU_PER_CON)
#error XCP_MAX_TX_PDU_PER_CON already defined
#endif
/** \brief Macro defining the maximum tx pdus per Xcp connection */
#define XCP_MAX_TX_PDU_PER_CON                             9U

#if (defined XCP_MAX_RX_PDU_PER_CON)
#error XCP_MAX_RX_PDU_PER_CON already defined
#endif
/** \brief Macro defining the maximum Rx pdus per Xcp connection */
#define XCP_MAX_RX_PDU_PER_CON                             1U

#if (defined XCP_NO_OF_CONNECTIONS)
#error XCP_NO_OF_CONNECTIONS already defined
#endif
/** \brief Macro defining the maximum number of configured Xcp connections */
#define XCP_NO_OF_CONNECTIONS                              1U


#if (defined XCP_NO_OF_FLEXRAY_CONN_WITH_SEQ_CORR)
#error XCP_NO_OF_FLEXRAY_CONN_WITH_SEQ_CORR already defined
#endif
/** \brief Macro defining the number of configured Xcp connections over the FlexRay that have
** Sequence correction enabled. */
#define XCP_NO_OF_FLEXRAY_CONN_WITH_SEQ_CORR               1U


#if (defined XCP_NO_OF_ETHERNET_CONN)
#error XCP_NO_OF_ETHERNET_CONN already defined
#endif
/** \brief Macro defining the number of configured Xcp connections over the Ethernet. */
#define XCP_NO_OF_ETHERNET_CONN                            0U


#if (defined XCP_SOAD_AUTO_OPEN_SO_CON)
#error XCP_SOAD_AUTO_OPEN_SO_CON already defined
#endif
/** \brief Switch, indicating whether SoAd_OpenSoCon() will be called during Xcp_Init() */
#define XCP_SOAD_AUTO_OPEN_SO_CON        STD_OFF

#if (defined XCP_SEED_AND_KEY_ENABLED)
#error XCP_SEED_AND_KEY_ENABLED already defined
#endif
/** \brief Switch, indicating whether resource protection with Seed & Key mechanism
** is activated or deactivated for XCP */
#define XCP_SEED_AND_KEY_ENABLED         STD_OFF
#if (defined XCP_EVENT_PACKET_ENABLED)
#error XCP_EVENT_PACKET_ENABLED already defined
#endif
/** \brief Switch, indicating whether the transmission of Event packets from the slave device to
** the master device is activated or deactivated */
#define XCP_EVENT_PACKET_ENABLED         STD_OFF

#if (defined XCP_EV_CTO_QUEUE_SIZE)
#error XCP_EV_CTO_QUEUE_SIZE already defined
#endif
/** \brief Macro to hold the size of the Event CTO queue based on the value of maximum DAQ list
** allocated per Event Channel when STIM is supported else the Event CTO packets will be processed
** in a single cyclic function, so size of the Event CTO queue shall be considered as 2 */
#define XCP_EV_CTO_QUEUE_SIZE            2U

#if (defined XCP_EVENT_CHANNEL_TOTAL_DAQ)
#error XCP_EVENT_CHANNEL_TOTAL_DAQ already defined
#endif
/** \brief The total number of DaqLists that can be associated to events channels on the XCP slave. */
#define XCP_EVENT_CHANNEL_TOTAL_DAQ        4U

#if (defined XCP_NUM_EVENT_CHANNEL_PRECFG)
#error XCP_NUM_EVENT_CHANNEL_PRECFG already defined
#endif
/** \brief The total number of preconfigured DaqLists that are associated to events channels */
#define XCP_NUM_EVENT_CHANNEL_PRECFG       0U

#if (defined XCP_MODIFY_BITS_SUPPORTED)
#error XCP_MODIFY_BITS_SUPPORTED already defined
#endif
/** \brief MODIFY_BITS supported */
#define XCP_MODIFY_BITS_SUPPORTED         STD_OFF
#if (defined XCP_WRITE_DAQ_MULTIPLE_SUPPORT)
#error XCP_WRITE_DAQ_MULTIPLE_SUPPORT already defined
#endif
/** \brief Enable/disable the WRITE_DAQ_MULTIPLE feature. */
#define XCP_WRITE_DAQ_MULTIPLE_SUPPORT   STD_OFF
#if (defined XCP_BUILD_CHECKSUM_SUPPORT)
#error XCP_BUILD_CHECKSUM_SUPPORT already defined
#endif
/** \brief Enable/disable the BUILD_CHECKSUM feature. */
#define XCP_BUILD_CHECKSUM_SUPPORT   STD_OFF
#if (defined XCP_BUILD_CHECKSUM_TYPE)
#error XCP_BUILD_CHECKSUM_TYPE already defined
#endif

#if (defined XCP_USER_TIMESTAMP_SUPPORTED)
#error XCP_USER_TIMESTAMP_SUPPORTED already defined
#endif
/** \brief Enable/Disable the Xcp User Timestamp */
#define XCP_USER_TIMESTAMP_SUPPORTED  STD_OFF
#if (defined XCP_SLAVE_BLOCK_MODE)
#error XCP_SLAVE_BLOCK_MODE already defined
#endif
/** \brief Switch, indicating whether slave block mode functionality is available. */
#define XCP_SLAVE_BLOCK_MODE             XCP_SLAVE_BLOCK_MODE_MASK
#if (defined XCP_MULTI_PDUS_IN_FRAME_SUPPORT)
#error XCP_MULTI_PDUS_IN_FRAME_SUPPORT already defined
#endif
/** \brief Switch for enabling support of multiple XCP messages in one frame */
#define XCP_MULTI_PDUS_IN_FRAME_SUPPORT  STD_ON
#if (defined XCP_FLEXRAY_SEQUENCE_CORRECTION_SUPPORT)
#error XCP_FLEXRAY_SEQUENCE_CORRECTION_SUPPORT already defined
#endif
/** \brief Switch for enabling support of multiple XCP messages in one frame */
#define XCP_FLEXRAY_SEQUENCE_CORRECTION_SUPPORT  STD_ON
#if (defined XCP_TRANSMIT_FROM_CONFIRMATION)
#error XCP_TRANSMIT_FROM_CONFIRMATION already defined
#endif
/** \brief Switch indicating whether transmission from TxConfirmation is enabled. */
#define XCP_TRANSMIT_FROM_CONFIRMATION           STD_OFF
#if (defined XCP_RECEIVE_FROM_INDICATION)
#error XCP_RECEIVE_FROM_INDICATION already defined
#endif
/** \brief Switch indicating whether reception from RxIndication is enabled. */
#define XCP_RECEIVE_FROM_INDICATION           STD_OFF
/*==================[type definitions]=======================================*/

/** \brief Definition for the Bus Timeout Counter value data type used to count the amount of
** Xcp_MainFunction cycles until the TX pending message is send by the underlying communication
** from the moment the transmission was accepted. */
typedef uint16 Xcp_BusTimeoutCounterValueType;

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

#endif /* if !defined( XCP_INT_CFG_H ) */
/*==================[end of file]============================================*/
