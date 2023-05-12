
/**
 * \file
 *
 * \brief AUTOSAR FrIf
 *
 * This file contains the implementation of the AUTOSAR
 * module FrIf.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2017 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef FRIF_CFGTYPES_H
#define FRIF_CFGTYPES_H



/*==================[inclusions]=============================================*/

#include <Platform_Types.h>
#include <TSAutosar.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_PTR_CLASS FRIF_APPL_CONST
#include <TSPBConfig_Types.h>


/*==================[macros]=================================================*/


/*==================[type definitions]=======================================*/

typedef VAR( uint8, TYPEDEF ) FrIf_PduIdxType; /* internal type used for Pdu-HandleIds */

typedef VAR( uint8, TYPEDEF ) FrIf_LPduIdxType; /* internal type used for LPdu-HandleIds */

typedef VAR( uint8, TYPEDEF ) FrIf_ComOpIdxType; /* internal type used for ComOp-iterations */

typedef struct /* FrIf_TrcvType */ {
    VAR( uint8, TYPEDEF ) TrcvDriverIdx; /* FlexRay Transceiver Driver Index. */
    VAR( uint8, TYPEDEF ) TrcvDeviceIdx; /* FlexRay Transceiver Index (in context of FlexRay transceiver driver). */
} FrIf_TrcvType;

typedef struct /* FrIf_TxPduType */ {
    VAR( FrIf_PduIdxType, TYPEDEF ) ConfPduIdx; /* PduId for this Pdu used in UL_TriggerTransmit() and UL_TxConfirmation() */
    VAR( uint8, TYPEDEF ) isDummyPdu; /* 0 for normal Pdus / 1 for dummy Pdus */
} FrIf_TxPduType;

typedef struct /* FrIf_PduPositionType */ {
    VAR( FrIf_PduIdxType, TYPEDEF ) PduIdx; /* Pdu index (FrIf_TxPdu or FrIf_RxPdu - depending on context). */
    VAR( uint8, TYPEDEF ) PduOffset; /* Offset of the Pdu within the LPdu in units of bytes. */
    VAR( uint8, TYPEDEF ) PduLength; /* Length of the Pdu in bytes. */
    VAR( uint8, TYPEDEF ) UB_ByteOffset; /* Byte offset of the Update bit within the FlexRay frame in units of bytes. */
    VAR( uint8, TYPEDEF ) UB_BitPos_OwnerIdx; /* Bit 0-3: Bit Position of the Update bit (0-7) (Value 8 if no update bit used), Bit 4-7: Index of upper layer. */
} FrIf_PduPositionType;

typedef struct /* FrIf_CtrlType */ {
    VAR( uint32, TYPEDEF ) NanoPerCycle; /* Contains the nanoseconds per cycle configured for this FlexRay CC. */
    VAR( uint16, TYPEDEF ) MTperCycle; /* Contains the macroticks per cycle configured for this FlexRay CC. */
    VAR( uint16, TYPEDEF ) NanoPerMT; /* Contains the nanoseconds per macrotick configured for this FlexRay CC. */
    VAR( FrIf_TrcvType, TYPEDEF ) Trcv[2]; /* Configuration of the transceivers connected to this controller. */
} FrIf_CtrlType;

typedef struct /* FrIf_ComOpType */ {
    TS_REF2CFG( void )  ContainerRef; /* Reference to Pdu related information - type depends on Action. */
    VAR( FrIf_LPduIdxType, TYPEDEF ) LPduIdx; /* Index of LPdu used for communication operation. */
    VAR( uint8, TYPEDEF ) LPduLength; /* (Maximum) length of the LPdu in units of bytes. */
    VAR( uint8, TYPEDEF ) Action; /* Communication operation to execute. */
    VAR( uint8, TYPEDEF ) PduPositionNum_OwnerIdx; /* Size of array pointed to by ContainerRef. */
} FrIf_ComOpType;

typedef struct /* FrIf_JobType */ {
    TS_REF2CFG( FrIf_ComOpType )  ComOpRef; /* Reference to an array of type FrIf_ComOpType belonging to this job. */
    VAR( uint16, TYPEDEF ) Offset; /* Macrotick offset this job shall be executed at. */
    VAR( FrIf_ComOpIdxType, TYPEDEF ) ComOpNum; /* Number of operations belonging to this job. */
    VAR( uint8, TYPEDEF ) Cycle; /* Cycle count value offset ( = cycle mod (JobListCycleRepetitionMask + 1)). */
} FrIf_JobType;

typedef struct /* FrIf_ClstType */ {
    TS_REF2CFG( FrIf_JobType )  JobRef; /* Reference to an array of type FrIf_JobType. */
    VAR( uint16, TYPEDEF ) MaxISRDelay; /* Maximum ISR delay allowed . */
    VAR( uint16, TYPEDEF ) SafetyMargin; /* Safety period in macroticks considered in job-list resync mechanism of this FlexRay CC. */
    VAR( uint16, TYPEDEF ) JobNum; /* Number of jobs within this cluster (referenced by JobRef). */
    VAR( uint8, TYPEDEF ) JLE_FrIf_AbsTimerIdx; /* Index of the absolute timer which is used for the joblist execution. */
    VAR( uint8, TYPEDEF ) JobListTimeoutLimit; /* If the JobListTimeoutCounter reaches this value, we must assume that the joblist is not executed any more due to sync problems. */
    VAR( uint8, TYPEDEF ) JobListCycleRepetition; /* Cycle Repetition factor of Joblist. */
} FrIf_ClstType;

typedef struct /* FrIf_ConfigType */ {
    VAR( uint32, TYPEDEF ) PlatformSignature; /* Used to validate the platform. */
    VAR( uint32, TYPEDEF ) PublicInfoSignature; /* Used to validate the common published information against the precompile time configuration. */
    VAR( uint32, TYPEDEF ) CfgSignature; /* Used to validate the post build configuration against the precompile time configuration. */
    VAR( uint32, TYPEDEF ) LcfgSignature; /* Used to validate the post build configuration against the link time configuration. */
    TS_REF2CFG( FrIf_TxPduType )  FrIf_TxPduRef; /* Config reference to all TxPdus controlled by this FrIf Array. */
    TS_REF2CFG( FrIf_ClstType )  FrIf_ClstRef; /*  Config reference to an array of all FlexRay clusters contained in this FrIf. */
    TS_REF2CFG( FrIf_CtrlType )  FrIf_CtrlRef; /* Config reference to an array of all FlexRay controller contained in this FrIf. */
    VAR( FrIf_PduIdxType, TYPEDEF ) FrIf_TxPduNum; /* Number of Pdus referenced by FrIf_TxPduRef. */
    VAR( FrIf_PduIdxType, TYPEDEF ) FrIf_TxPduNoConfNum; /* Number of Pdus referenced by FrIf_TxPduRef without tx confirmation. */
} FrIf_ConfigType;


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

#endif /* FRIF_CFGTYPES_H */

/*==================[end of file]============================================*/

