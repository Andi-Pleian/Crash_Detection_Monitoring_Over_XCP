
/**
 * \file
 *
 * \brief AUTOSAR FrNm
 *
 * This file contains the implementation of the AUTOSAR
 * module FrNm.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2017 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef FRNM_TYPES_H
#define FRNM_TYPES_H



/*==================[inclusions]=============================================*/

#include <Platform_Types.h>
#include <ComStack_Cfg.h>
#include <TSAutosar.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_PTR_CLASS FRNM_APPL_CONST
#include <TSPBConfig_Types.h>


/*==================[macros]=================================================*/


/*==================[type definitions]=======================================*/

typedef struct /* FrNm_PduType */ {
    VAR( uint8, TYPEDEF ) PduType; /* Type of PDU (vote or data) */
    VAR( uint8, TYPEDEF ) ChannelHandle; /* Cluster ID for this PDU */
} FrNm_PduType;

typedef struct /* FrNm_TxPduType */ {
    VAR( PduIdType, TYPEDEF ) TxPduId; /* PDU ID defined by FrIf */
    VAR( PduIdType, TYPEDEF ) TxConfPduId; /* Tx Confirmation PduId */
    VAR( PduLengthType, TYPEDEF ) PduLength; /* PDU length defined by EcuC */
    VAR( uint8, TYPEDEF ) PduType; /* Type of PDU (vote or data or mixed) */
    VAR( uint8, TYPEDEF ) ChannelHandle; /* Cluster ID for this PDU  */
} FrNm_TxPduType;

typedef struct /* FrNm_ChannelDataType */ {
    VAR( uint16, TYPEDEF ) MsgTimeoutTime; /* Timeout for the transmission of an FrNm PDU in units of communication cycles */
    VAR( PduIdType, TYPEDEF ) TxVotePduId[4]; /* Array of TX PDU for Nm vote (with or without Nm data) for a cluster */
    VAR( PduIdType, TYPEDEF ) TxDataPduId[4]; /* Array of TX PDU for Nm data which doesn't contain vote */
    VAR( PduLengthType, TYPEDEF ) PduLength; /* Length of FrNm data PDU in units of bytes */
    VAR( uint8, TYPEDEF ) NoOfTxVotePdus; /* Number of vote with or without data TX N-PDUs */
    VAR( uint8, TYPEDEF ) NoOfTxDataPdus; /* Number of data TX N-PDUs */
    VAR( uint8, TYPEDEF ) ChannelProperty; /* ScheduleVariant(0-2), Cbv(3), ReptMessageBit(4), SynchEnabled(5), VoteInhibition(6), Nm Data(7) */
    VAR( uint8, TYPEDEF ) CtrlIdx; /* Index of the first controller for the cluster referenced by this channel */
    VAR( boolean, TYPEDEF ) PnEnabled; /* PnEnabled configuration for each channel */
} FrNm_ChannelDataType;

typedef struct /* FrNm_ConfigType */ {
    VAR( uint32, TYPEDEF ) PlatformSignature; /* Used to validate the platform */
    VAR( uint32, TYPEDEF ) LcfgSignature; /* Used to validate the post build configuration against the link time configuration */
    VAR( uint32, TYPEDEF ) CfgSignature; /* Used to validate the post build configuration against the precompile time configuration */
    VAR( uint32, TYPEDEF ) PublicInfoSignature; /* Used to validate Public information */
    VAR( FrNm_ChannelDataType, TYPEDEF ) FrNm_ChannelData[1]; /* FrNm_ChannelData */
    VAR( FrNm_PduType, TYPEDEF ) RxPduMap[1]; /* Mapping between RxPdus to PduType and Cluster */
    VAR( FrNm_TxPduType, TYPEDEF ) TxPduMap[1]; /* Mapping between TxPdus to PduType and Cluster */
    VAR( uint8, TYPEDEF ) PnFilterMask[6]; /* PnFilterMask */
} FrNm_ConfigType;


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

#endif /* FRNM_TYPES_H */

/*==================[end of file]============================================*/

