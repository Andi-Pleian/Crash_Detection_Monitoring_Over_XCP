
/**
 * \file
 *
 * \brief AUTOSAR CanIf
 *
 * This file contains the implementation of the AUTOSAR
 * module CanIf.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2017 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef CANIF_TYPES_INT_H
#define CANIF_TYPES_INT_H



/*==================[inclusions]=============================================*/

#include <Platform_Types.h>
#include <Can_GeneralTypes_Cfg.h>
#include <ComStack_Cfg.h>
#include <TSAutosar.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_PTR_CLASS CANIF_APPL_CONST
#include <TSPBConfig_Types.h>


/*==================[macros]=================================================*/


/*==================[type definitions]=======================================*/

/** 
 \brief Index type for Tx buffers

 This type defines the index width for Tx buffers.
 */
typedef VAR( uint16, TYPEDEF ) CanIf_TxBufferIndexType;

/** 
 \brief Index type for Rx buffers

 This type defines the index width for Rx buffers.
 */
typedef VAR( uint16, TYPEDEF ) CanIf_RxBufferIndexType;

/** 
 \brief Index type for L-PDU related data

 This type defines the index type for L-PDU related data.
 */
typedef VAR( uint16, TYPEDEF ) CanIf_LPduIndexType;

/** 
 \brief Controller configuration

 This is the type used for controller configuration.
 */
typedef struct /* CanIf_CanControllerConfigType */ {
    VAR( uint8, TYPEDEF ) controllerId; /* CAN controller ID */
} CanIf_CanControllerConfigType;

/** 
 \brief Tx L-PDU configuration type

 This type is used for configuration of Tx L-PDUs.
 */
typedef struct /* CanIf_TxLPduConfigType */ {
    VAR( Can_IdType, TYPEDEF ) canId; /* CAN ID */
    VAR( Can_HwHandleType, TYPEDEF ) hth; /* HTH */
    VAR( PduIdType, TYPEDEF ) sourcePduId_UL; /* source PDU ID of upper layer */
    VAR( uint8, TYPEDEF ) userType; /* type of callback function */
} CanIf_TxLPduConfigType;

/** 
 \brief Rx L-PDU index type

 This type is the index table to select a Rx L-Pdu.
 */
typedef struct /* CanIf_SortedRxLPduConfigType */ {
    VAR( uint32, TYPEDEF ) upperRangeCanId; /* Upper range CAN ID/no range flag */
    VAR( Can_IdType, TYPEDEF ) canId; /* CAN ID */
    VAR( CanIf_LPduIndexType, TYPEDEF ) rxLPduIndex;
} CanIf_SortedRxLPduConfigType;

/** 
 \brief Rx L-PDU configuration type

 This type defines the configuration of a Rx L-PDU.
 */
typedef struct /* CanIf_RxLPduConfigType */ {
    VAR( PduIdType, TYPEDEF ) targetPduId; /* target PDU ID */
    VAR( uint8, TYPEDEF ) limitedPduLength; /* target PDU length */
    VAR( uint8, TYPEDEF ) userType; /* type of callback function */
    VAR( uint8, TYPEDEF ) dlc; /* CAN DLC */
} CanIf_RxLPduConfigType;

/** 
 \brief HTH configuration type

 This is the data type used for HTH configuration.
 */
typedef struct /* CanIf_HthConfigType */ {
    VAR( CanIf_LPduIndexType, TYPEDEF ) firstIndex; /* index of first pending Tx request */
    VAR( uint8, TYPEDEF ) intCtrlIdx; /* CanIf internal controller index */
} CanIf_HthConfigType;

/** 
 \brief HRH configuration type

 This is the data type used for HRH configuration.
 */
typedef struct /* CanIf_HrhConfigType */ {
    VAR( CanIf_LPduIndexType, TYPEDEF ) firstIndex; /* index of first Rx L-PDU for this HRH */
    VAR( CanIf_LPduIndexType, TYPEDEF ) lastIndex; /* index of last Rx L-PDU for this HRH */
    VAR( uint8, TYPEDEF ) swFiltering;
    VAR( uint8, TYPEDEF ) intCtrlIdx; /* CanIf internal controller index */
} CanIf_HrhConfigType;

/** 
 \brief Driver configuration type

 This type defines the driver configuration used in the CAN interface.
 */
typedef struct /* CanIf_CanDriverConfigType */ {
    TS_REF2CFG( CanIf_CanControllerConfigType )  ctrlConfigPtr; /* array of controller configurations */
    TS_REF2CFG( uint16 )  hohIdToCanIfIdxPtr; /* HOH ID translation array */
    TS_REF2CFG( CanIf_HthConfigType )  hthConfigPtr; /* array of HTH configurations */
    TS_REF2CFG( CanIf_HrhConfigType )  hrhConfigPtr; /* array of HRH configurations */
    VAR( Can_HwHandleType, TYPEDEF ) upperHohIdLimit; /* maximum configured HOH ID + 1 */
    VAR( uint8, TYPEDEF ) nrOfControllers; /* Number of CAN controllers contained in this driver */
} CanIf_CanDriverConfigType;

/** 
 \brief Type for the CAN interface configuration

 This type defines the global configuration of the CAN interface.
 */
typedef struct /* CanIf_ConfigType */ {
    VAR( uint32, TYPEDEF ) PlatformSignature; /* Used to validate the platform */
    VAR( uint32, TYPEDEF ) LcfgSignature; /* Used to validate the post build configuration against the link time configuration */
    VAR( uint32, TYPEDEF ) CfgSignature; /* Used to validate the post build configuration against the precompile time configuration */
    VAR( uint32, TYPEDEF ) PublicInfoSignature; /* Used to validate the post build configuration against the precompile time published information configuration */
    TS_REF2CFG( CanIf_TxLPduConfigType )  txLPduConfigPtr; /* ptr. to array of Tx L-PDU configurations */
    TS_REF2CFG( CanIf_RxLPduConfigType )  rxLPduConfigPtr; /* ptr. to array of Rx L-PDU configurations */
    TS_REF2CFG( CanIf_SortedRxLPduConfigType )  sortedRxLPduConfigPtr; /* ptr. to array of sorted Rx L-PDU configurations */
    TS_REF2CFG( CanIf_CanDriverConfigType )  driverConfigPtr; /* pointer a driver configuration */
    VAR( CanIf_LPduIndexType, TYPEDEF ) nrOfStaticTxLPdus; /* number of static Tx L-PDUs */
    VAR( CanIf_LPduIndexType, TYPEDEF ) nrOfTxLPdus; /* number of Tx L-PDUs */
    VAR( CanIf_LPduIndexType, TYPEDEF ) nrOfRxLPdus; /* number of Rx L-PDUs */
    VAR( uint8, TYPEDEF ) maxCanControllerId; /* maximum Can controller index */
} CanIf_ConfigType;


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/


/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/



#undef TS_RELOCATABLE_CFG_ENABLE

#undef TS_PB_CFG_PTR_CLASS

#endif /* CANIF_TYPES_INT_H */

/*==================[end of file]============================================*/

