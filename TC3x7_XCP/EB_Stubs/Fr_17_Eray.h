/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2017)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME     : Fr_17_Eray.h                                               **
**                                                                            **
**  VERSION      : 2.0.0                                                      **
**                                                                            **
**  DATE         : 2017-03-10                                                 **
**                                                                            **
**  VARIANT      : Variant PB                                                 **
**                                                                            **
**  PLATFORM     : Infineon AURIX2G                                           **
**                                                                            **
**  AUTHOR       : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**  VENDOR       : Infineon Technologies                                      **
**                                                                            **
**  DESCRIPTION  : Fr Driver header definition file                           **
**                                                                            **
**  SPECIFICATION(S) : Specification of FlexRay Driver, AUTOSAR Release 4.2.2 **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

#ifndef FR_17_ERAY_H
#define FR_17_ERAY_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/*
  SWS_Fr_00459:Types and constants shared among Fr, FrIf and FrTrcv.
*/
#include "Fr_GeneralTypes.h"

/* Pre-compile configuration parameters for FR */
#include "Fr_17_Eray_Cfg.h"

/* MCAL header file containing global macros, type definitions and functions
  needed by all MCAL drivers. */
#include "Mcal_Compiler.h"
#include "McalLib.h"
/* Register definition file for Aurix2G target */
#include "IfxEray_reg.h"
#include "IfxSrc_reg.h"
/* DEM header file */
#include "Dem.h"

/* Conditional Inclusion of Default Error Tracer File */
#if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON) */

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*
  Published parameters
*/
/* Fr Vendor ID */
#define FR_17_ERAY_VENDOR_ID                  (17U)
/* Fr Module ID */
#define FR_17_ERAY_MODULE_ID                  ((uint16)0x51)

/* SWS_Fr_00025:API parameter timer index exceeds number of available timers */
#define FR_17_ERAY_E_INV_TIMER_IDX    ((uint8)0x01)

/* SWS_Fr_00488:Invalid pointer in parameter list */
#define FR_17_ERAY_E_PARAM_POINTER    ((uint8)0x02)

/* SWS_Fr_00489:Parameter offset exceeds bounds */
#define FR_17_ERAY_E_INV_OFFSET       ((uint8)0x03)

/* SWS_Fr_00490:Invalid controller index */
#define FR_17_ERAY_E_INV_CTRL_IDX     ((uint8)0x04)

/* SWS_Fr_00491:Invalid channel index */
#define FR_17_ERAY_E_INV_CHNL_IDX     ((uint8)0x05)

/* SWS_Fr_00492:Parameter cycle exceeds 63 */
#define FR_17_ERAY_E_INV_CYCLE        ((uint8)0x06)

/* SWS_Fr_00494:Fr module was not initialized */
#define FR_17_ERAY_E_INIT_FAILED      ((uint8)0x08)

/* SWS_Fr_00495:Fr CC is not in the expected POC state. */
#define FR_17_ERAY_E_INV_POCSTATE     ((uint8)0x09)

/* SWS_Fr_00496:Payload length parameter has an invalid value. */
#define FR_17_ERAY_E_INV_LENGTH       ((uint8)0x0A)

/* SWS_Fr_00497:Invalid LPdu index */
#define FR_17_ERAY_E_INV_LPDU_IDX     ((uint8)0x0B)

/* SWS_Fr_00633:Invalid FlexRay header CRC */
#define FR_17_ERAY_E_INV_HEADERCRC    ((uint8)0x0C)

/* SWS_Fr_00669:Invalid value passed as parameter Fr_ConfigParamIdx */
#define FR_17_ERAY_E_INV_CONFIG_IDX   ((uint8)0x0D)

/* SWS_Fr_00668:Invalid value passed as parameter Fr_ListSize */
#define FR_17_ERAY_E_INV_FRAMELIST_SIZE ((uint8)0x0E)


/* Macro for no error detection, This is for module internal use only */
#define FR_17_ERAY_E_DET_NO_ERR       ((uint32)0)

/*
  Service IDs. Used while reporting development errors.
*/
#define FR_17_ERAY_SID_INIT                         ((uint8)0x1c)
#define FR_17_ERAY_SID_CONTROLLERINIT               ((uint8)0x00)
#define FR_17_ERAY_SID_STARTCOMMUNICATION           ((uint8)0x03)
#define FR_17_ERAY_SID_ALLOWCOLDSTART               ((uint8)0x23)
#define FR_17_ERAY_SID_ALLSLOTS                     ((uint8)0x24)
#define FR_17_ERAY_SID_HALTCOMMUNICATION            ((uint8)0x04)
#define FR_17_ERAY_SID_ABORTCOMMUNICATION           ((uint8)0x05)
#define FR_17_ERAY_SID_SENDWUP                      ((uint8)0x06)
#define FR_17_ERAY_SID_SETWAKEUPCHANNEL             ((uint8)0x07)
#define FR_17_ERAY_SID_GETPOCSTATUS                 ((uint8)0x0a)
#define FR_17_ERAY_SID_TRANSMITTXLPDU               ((uint8)0x0b)
#define FR_17_ERAY_SID_CANCELTXLPDU                 ((uint8)0x2d)
#define FR_17_ERAY_SID_RECEIVERXLPDU                ((uint8)0x0c)
#define FR_17_ERAY_SID_CHECKTXLPDUSTATUS            ((uint8)0x0d)
#define FR_17_ERAY_SID_PREPARELPDU                  ((uint8)0x1f)
#define FR_17_ERAY_SID_RECONFIGLPDU                 ((uint8)0x25)
#define FR_17_ERAY_SID_DISABLELPDU                  ((uint8)0x26)
#define FR_17_ERAY_SID_GETGLOBALTIME                ((uint8)0x10)
#define FR_17_ERAY_SID_GETNMVECTOR                  ((uint8)0x22)
#define FR_17_ERAY_SID_GETNUMOFSTARTUPFRAMES        ((uint8)0x27)
#define FR_17_ERAY_SID_GETCHANNELSTATUS             ((uint8)0x28)
#define FR_17_ERAY_SID_GETCLOCKCORRECTION           ((uint8)0x29)
#define FR_17_ERAY_SID_GETSYNCFRAMELIST             ((uint8)0x2a)
#define FR_17_ERAY_SID_GETWAKEUPRXSTATUS            ((uint8)0x2b)
#define FR_17_ERAY_SID_SETABSOLUTETIMER             ((uint8)0x11)
#define FR_17_ERAY_SID_CANCELABSOLUTETIMER          ((uint8)0x13)
#define FR_17_ERAY_SID_ENABLEABSOLUTETIMERIRQ       ((uint8)0x15)
#define FR_17_ERAY_SID_ACKABSOLUTETIMERIRQ          ((uint8)0x17)
#define FR_17_ERAY_SID_DISABLEABSOLUTETIMERIRQ      ((uint8)0x19)
#define FR_17_ERAY_SID_GETABSTIMERIRQSTATUS         ((uint8)0x20)
#define FR_17_ERAY_SID_GETVERSIONINFO               ((uint8)0x1b)
#define FR_17_ERAY_SID_READCCCONFIG                 ((uint8)0x2e)


/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
/* [cover parentID=DS_AS_FR077] */
/*
  Type definition for configuration paramaters that are part of register SUCC1
*/
typedef union
{
  struct
  {
    /*
      Unused member
      Register fields corresponding to Cmd (CHI Command Vector) (4bits),
      3 reserved bits and POCBusy (POC Busy status) (1 bit)
      Reset value = 0
    */
    unsigned_int   CmdPOCBusy        : 8;

    /* Defines whether the key slot is used to transmit startup Frames */
    unsigned_int   pKeySlotUsedForStartup  : 1;

    /* Defines whether the key slot is used to transmit SYNC Frames */
    unsigned_int   pKeySlotUsedForSync  : 1;

    /*
      Reserved bit. Value is 0 always.
    */
    unsigned_int   Reserved        : 1;

    /*
      Maximum number of attempts that a cold starting node is permitted to
      try to start up the network without receiving any valid response from
      another node.
    */
    unsigned_int   gColdStartAttempts  : 5;

    /*
      Number of consecutive even / odd cycle pairs that must have valid clock
      correction terms before the CC is allowed to transit from
      "NORMAL_PASSIVE" to "NORMAL_ACTIVE" state.
    */
    unsigned_int   pAllowPassiveToActive  : 5;

    /*
      Channel on which the CC sends the Wakeup pattern.
    */
    unsigned_int   pWakeupChannel : 1;

    /*
      Selects the initial transmission slot mode.
    */
    unsigned_int   pSingleSlotEnabled : 1;

    /*
      Controls the transition to "HALT" state due to a clock synchronization
      error.
    */
    unsigned_int   pAllowHaltDueToClock : 1;

    /*
       ***** Not used for configuration *****
      Channel selection for MTS transamission
      Reset value = 0 --> No channel is selected for MTS transmission
    */
    unsigned_int   pChannelsMTS : 2;

    /*
      CC connection to channels.
    */
    unsigned_int   pChannels : 2;

  } B;

  uint32 U;

} Fr_17_Eray_RegSucc1 ;

/*
  Type definition for configuration paramaters that are part of register SUCC2
*/
typedef union
{
  struct
  {
    /*
      Upper limit for the start up listen timeout and wake up listen
      timeout [Microticks].
      Note: Bits 21-23 are reserved, they are consumed by this field but are
        not used.
    */
    unsigned_int   pdListenTimeout  : 24;

    /*
      gListenNoise:
      Upper limit for the start up listen timeout and wake up listen timeout
      in the presence of noise. It is used as a multiplier of the cluster
      parameter pdListenTimeout.
    */
    unsigned_int   gListenNoiseMinusOne  : 4;

  } B;

  uint32 U;

} Fr_17_Eray_RegSucc2 ;

/*
  Type definition for configuration paramaters that are part of register SUCC3
*/
typedef union
{
  struct
  {
    /*
      Maximum Without Clock Correction Passive.
      Note: Bits 21-23 are reserved, they are consumed by this field but are
        not used.
    */
    unsigned_int   gMaxWithoutClockCorrectionPassive  : 4;

    /*
      Maximum Without Clock Correction Fatal.
      Upper limit for the start up listen timeout and wake up listen timeout
      in the presence of noise. It is used as a multiplier of the cluster
      parameter pdListenTimeout.
    */
    unsigned_int   gMaxWithoutClockCorrectionFatal  : 4;

  } B;

  uint32 U;

} Fr_17_Eray_RegSucc3 ;

/*
  Type definition for configuration paramaters that are part of register NEMC
*/
typedef union
{
  struct
  {
    /* Length of the Network Management vector in a cluster [bytes] */
    unsigned_int   gNetworkManagementVectorLength : 4;

  } B;

  uint32 U;

} Fr_17_Eray_RegNemc ;


/*
  Type definition for configuration paramaters that are part of register PRTC1
*/
typedef union
{
  struct
  {
    /*
      Number of bits in the Transmission Start Sequence [gdBits]
    */
    unsigned_int   gdTSSTransmitter  : 4;

    /*
      Upper limit of the CAS acceptance window [gdBit]
      Reserved bit (MSB) is consumed here
    */
    unsigned_int   gdCASRxLowMax  : 8;

    /*
      Not used. value left to reset value.
      Strobe Point Position
      Defines the sample count value for strobing. The strobed bit value is set
      to the voted value when the sample count is incremented to the value
      configured by SPP.
          00B Sample 5 (default)
          01B Sample 4
          10B Sample 6
          11B Reserved; should not be used.
    */
    unsigned_int StrobePointPosition : 2 ;

    /*
      Baud Rate Prescaler
      Derived from
        * gdSampleClockPeriod - Sample clock period  [12.5ns, 25ns, 50ns]
        * pSamplePerMicrotick - Samples per micro tick [1, 2, 4]
    */
    unsigned_int   Brp  : 2;

    /*
      The size of the window used to detect wakeups. Detection of a wakeup
      requires a low and idle period (from one WUS) and a low period (from
      another WUS) to be detected entirely within a window of this size.
      The duration is equal to gdWakeupSymbolTxIdle + 2 * gdWakeupSymbolTxLow
      plus a safe part. (Clock differences and other effects can deform the
      Tx-wakeup pattern.) [gdBit]
      Note: Bit 25 is reserved and hence not used
    */
    unsigned_int   gdWakeupSymbolRxWindow  : 10;

    /*
      Number of repetitions of the wakeup symbol that are combined to form a
      wakeup pattern when the node enters the POC:wakeup send state
    */
    unsigned_int   pWakeupPattern  : 6;

  } B;

  uint32 U;

} Fr_17_Eray_RegPrtc1 ;

/*
  Type definition for configuration paramaters that are part of register PRTC2
*/
typedef union
{
  struct
  {
    /*
      Number of bits used by the node to test the duration of the 'idle'
      portion of a received wakeup symbol. Duration is equal to
      (gdWakeupSymbolTxIdle - gdWakeupSymbolTxLow)/2 minus a safe part.
      (Collisions, clock differences, and other effects can deform the
      Tx-wakeup pattern.) [gdBit]
      Note: Bits 6-7 are reserved, they are consumed by this field but are
        not used.
    */
    unsigned_int   gdWakeupSymbolRxIdle  : 8;

    /*
      Number of bits used by the node to test the LOW portion of a received
      wakeup symbol. This lower limit of zero bits has to be received to
      detect the LOW portion by the receiver. The duration is equal to
      gdWakeupSymbolTxLow minus a safe part. (Active stars, clock differences,
      and other effects can deform the Tx-wakeup pattern.) [gdBits].
      Note: Bits 14-15 are reserved, they are consumed by this field but are
        not used.
    */
    unsigned_int   gdWakeupSymbolRxLow  : 8;

    /*
      Number of bits used by the node to transmit the 'idle' part of a wakeup
      symbol. The duration is equal to cdWakeupSymbolTxIdle [gdBit].
    */
    unsigned_int   gdWakeupSymbolTxIdle  : 8;

    /*
      Number of bits used by the node to transmit the LOW part of a wakeup
      symbol. The duration is equal to cdWakeupSymbolTxLow [gdBit].
      Note: Bits 30-31 are reserved, they are consumed by this field but are
        not used.
      This parameter maps to FlexRay Protocol 2.1 Rev. A parameter
      gdWakeupSymbolTxLow.
    */
    unsigned_int   gdWakeupTxActive  : 8;

  } B;

  uint32 U;

} Fr_17_Eray_RegPrtc2 ;

/*
  Type definition for configuration paramaters that are part of register MHDC
*/
typedef union
{
  struct
  {
    /*
      Payload length of a static frame [16 bit words]
      Note: Bits 7 to 15 are reserved, they are consumed by this field but are
        not used.
    */
    unsigned_int   gPayloadLengthStatic  : 16;

    /*
      Number of the last minislot in which a frame transmission can start in
      the dynamic segment [Minislots].
      Note: Bits 29-31 are reserved, they are consumed by this field but are
        not used.
    */
    unsigned_int   pLatestTx  : 16;

  } B;

  uint32 U;

} Fr_17_Eray_RegMhdc ;

/*
  Type definition for configuration paramaters that are part of register GTUC01
*/
typedef union
{
  struct
  {
    /*
      Nominal number of microticks in the communication cycle of the local node.
      If nodes have different microtick durations this number will differ from
      node to node [Microticks].
    */
    unsigned_int   UT  : 20;

  } B;

  uint32 U;

} Fr_17_Eray_RegGtuc01 ;

/*
  Type definition for configuration paramaters that are part of register GTUC02
*/
typedef union
{
  struct
  {
    /*
      Number of macroticks in a communication cycle.
      Bits 14-15 are reserved bits, not used.
    */
    unsigned_int   gMacroPerCycle  : 16;

    /*
      Maximum number of nodes that may send frames with the sync frame
      indicator bit set to one.
    */
    unsigned_int   gSyncNodeMax  : 4;


  } B;

  uint32 U;

} Fr_17_Eray_RegGtuc02 ;

/*
  Type definition for configuration paramaters that are part of register GTUC02
*/
typedef union
{
  struct
  {
    /*
      Number of microticks between the closest macrotick boundary described by
      pMacroInitialOffset[Ch] and the secondary time reference point. The
      parameter depends on pDelayCompensation[Ch] and therefore it has to be
      set independently for each channel [Microticks].
    */
    unsigned_int   pMicroInitialOffsetA  : 8;

    /*
      Number of microticks between the closest macrotick boundary described by
      pMacroInitialOffset[Ch] and the secondary time reference point. The
      parameter depends on pDelayCompensation[Ch] and therefore it has to be
      set independently for each channel [Microticks].
    */
    unsigned_int   pMicroInitialOffsetB  : 8;

    /*
      Integer number of macroticks between the static slot boundary and the
      following macrotick boundary of the secondary time reference point based
      on the nominal macrotick duration [Macroticks].
      Note: Bit 23 is reserved, not used.
    */
    unsigned_int   pMacroInitialOffsetA  : 8;

    /*
      Integer number of macroticks between the static slot boundary and the
      following macrotick boundary of the secondary time reference point based
      on the nominal macrotick duration [Macroticks].
      Note: Bit 31 is reserved, not used.
    */
    unsigned_int   pMacroInitialOffsetB  : 8;

  } B;

  uint32 U;

} Fr_17_Eray_RegGtuc03 ;

/*
  Type definition for configuration paramaters that are part of register GTUC04
*/
typedef union
{
  struct
  {
    /*
      NetworkIdleTimeStart = (gMacroPerCycle - gdNIT - 1)
      gMacroPerCycle  : Number of macroticks in a communication cycle.
      gdNIT           : Duration of the Network Idle Time [Macroticks]

      Note: Bit 14-15 are reserved, not used.
    */
    unsigned_int   NetworkIdleTimeStart  : 16;

    /*
      Offset Correction Start = (gOffsetCorrectionStart - 1)

      Start of the offset correction phase within the NIT, expressed as the
      number of macroticks from the start of cycle.
      Note: Bits 30-31 are reserved, they are consumed by this field but are
        not used.
    */
    unsigned_int   gOffsetCorrectionStartMinusOne  : 16;

  } B;

  uint32 U;

} Fr_17_Eray_RegGtuc04 ;

/*
  Type definition for configuration paramaters that are part of register GTUC05
*/
typedef union
{
  struct
  {
    /*
      Delay Compensation Channel A
      Value used to compensate for reception delays on the indicated channel.
      This covers assumed propagation delay up to cPropagationDelayMax for
      microticks in the range of 12.5ns to 50ns. In practice, the minimum
      of the propagation delays of all sync nodes should be applied [Microticks]
    */
    unsigned_int   pDelayCompensationA  : 8;

    /*
      Delay Compensation Channel B
    */
    unsigned_int   pDelayCompensationB  : 8;

    /*
      Local cluster drift damping factor used for rate correction [Microticks]

      Note: Bit 21-23 are reserved, not used.
    */
    unsigned_int   pClusterDriftDamping  : 8;

    /*
      Value used by the receiver to calculate the difference between primary
      time reference point and secondary time reference point [Microticks]
    */
    unsigned_int   pDecodingCorrection  : 8;

  } B;

  uint32 U;

} Fr_17_Eray_RegGtuc05 ;

/*
  Type definition for configuration paramaters that are part of register GTUC06
*/
typedef union
{
  struct
  {
    /*
      Accepted Startup Range:
      Expanded range of measured clock deviation allowed for startup frames
      during integration [Microticks]

      Note: Bit 11-15 are reserved, not used.
    */
    unsigned_int   pdAcceptedStartupRange  : 16;

    /*
      Maximum Oscillator Drift:
      Maximum drift offset between two nodes that operate with unsynchronized
      clocks over one communication cycle [Microticks].
      Note: Bits 27-31 are reserved, they are consumed by this field but are
        not used.
    */
    unsigned_int   pdMaxDrift  : 16;

  } B;

  uint32 U;

} Fr_17_Eray_RegGtuc06 ;

/*
  Type definition for configuration paramaters that are part of register GTUC07
*/
typedef union
{
  struct
  {
    /*
      Duration of a Static Slot [Macroticks].

      Note: Bit 10-15 are reserved, not used.
    */
    unsigned_int   gdStaticSlot  : 16;

    /*
      Number of static slots in the static segment.
      Note: Bits 26-31 are reserved, they are consumed by this field but are
        not used.
    */
    unsigned_int   gNumberOfStaticSlots  : 16;

  } B;

  uint32 U;

} Fr_17_Eray_RegGtuc07 ;

/*
  Type definition for configuration paramaters that are part of register GTUC08
*/
typedef union
{
  struct
  {
    /*
      Duration of a Minislot [Macroticks].

      Note: Bit 6-15 are reserved, not used.
    */
    unsigned_int   gdMinislot  : 16;

    /*
      Number of minislots in the dynamic segment.
      Note: Bits 29-31 are reserved, they are consumed by this field but are
        not used.
    */
    unsigned_int   gNumberOfMinislots  : 16;

  } B;

  uint32 U;

} Fr_17_Eray_RegGtuc08 ;

/*
  Type definition for configuration paramaters that are part of register GTUC09
*/
typedef union
{
  struct
  {
    /*
      Number of Macroticks the action point is offset from the beginning of a
      Static Slots or symbol window.

      Note: Bit 6-7 are reserved, not used.
    */
    unsigned_int   gdActionPointOffset  : 8;

    /*
      Number of Macroticks the Minislot action point is offset from the
      beginning of a Minislot [Macroticks].

      Note: Bit 13-15 are reserved, not used.
    */
    unsigned_int   gdMinislotActionPointOffset  : 8;

    /*
      Duration of the idle phase within a dynamic slot [Minislots].
      Note: Bits 18-31 are reserved, they are consumed by this field but are
        not used.
    */
    unsigned_int   gdDynamicSlotIdlePhase  : 16;

  } B;

  uint32 U;

} Fr_17_Eray_RegGtuc09 ;

/*
  Type definition for configuration paramaters that are part of register GTUC10
*/
typedef union
{
  struct
  {
    /*
      Magnitude of the maximum permissible offset correction value [Microticks].

      Note: Bit 14-15 are reserved, not used.
    */
    unsigned_int   pOffsetCorrectionOut  : 16;

    /*
      Magnitude of the maximum permissible rate correction value [Microticks].
      Note: Bits 27-31 are reserved, they are consumed by this field but are
        not used.
    */
    unsigned_int   pRateCorrectionOut  : 16;

  } B;

  uint32 U;

} Fr_17_Eray_RegGtuc10 ;

/*
  Type definition for configuration paramaters that are part of register GTUC11
*/
typedef union
{
  struct
  {
    /*
      Bits 0-1: pExternOffsetControl => Enables offset correction
      Bits 8-9: pExternRateControl => Enables rate correction
    */
    unsigned_int   UnusedMember  : 16;

    /*
      Number of microticks added or subtracted to the NIT to carry out a
      host-requested external offset correction [Microticks].

      Note: Bit 19-23 are reserved, not used.
    */
    unsigned_int   pExternOffsetCorrection  : 8;

    /*
      Number of microticks added or subtracted to the cycle to carry out a
      host-requested external rate correction [Microticks].
      Note: Bits 27-31 are reserved, they are consumed by this field but are
        not used.
    */
    unsigned_int   pExternRateCorrection  : 8;

  } B;

  uint32 U;

} Fr_17_Eray_RegGtuc11 ;

/*
  Type definition for configuration paramaters that are part of register CUST1
*/
typedef union
{
  struct
  {
    /*
      First 8 bits - unused for now.
    */
    unsigned_int   UnusedMember  : 8;

    /*
      Reserved bits. Value is 0 always.
    */
    unsigned_int   Reserved        : 2;

    /*
      Bits 10-11 : RISA - Receive Input Select Channel A
    */
    unsigned_int   pRxSelectChA  : 2;

    /*
      Bits 10-11 : RISA - Receive Input Select Channel A
    */
    unsigned_int   pRxSelectChB  : 2;

    /*
      Bits 14-15 : STPWTS - Stop Watch Trigger Input Select (unused)
    */
    unsigned_int   pStpwts  : 2;

  } B;

  uint32 U;

} Fr_17_Eray_RegCust1 ;

/*
  Type definition for configuration paramaters that are part of register MRC
*/
typedef union
{
  struct
  {
    /*
      Id of the first dynamic Message Buffers configured.
    */
    unsigned_int   FDB  : 8;

    /*
      Id of the first FIFO Message Buffers configured.
    */
    unsigned_int   FFB  : 8;

    /*
      Id of the Last Configured Message Buffer.
    */
    unsigned_int   LCB  : 8;

    /*
      Locking/Unlocking of reconfiguration of the Message Buffers.
    */
    unsigned_int   SEC  : 2;

    /*
      SYNC frame transmission with different payload data on channel A and B.
    */
    unsigned_int   SPLM  : 1;

    /*
      Reserved bits. Value is 0 always.
    */
    unsigned_int   Reserved  : 5;

  } B;

  uint32 U;

} Fr_17_Eray_RegMrc;
/* ---------------------------------------------------------------------------*/

/*
  Type definition for data structure containing configuration paramaters for
  a FlexRay communication controller.
*/
typedef struct
{
  Fr_17_Eray_RegSucc1 SUCC1 ;     /* Configuration value for register SUCC1 */
  Fr_17_Eray_RegSucc2 SUCC2 ;     /* Configuration value for register SUCC2 */
  Fr_17_Eray_RegSucc3 SUCC3 ;     /* Configuration value for register SUCC3 */

  Fr_17_Eray_RegNemc  NEMC ;      /* Configuration value for register NEMC */

  Fr_17_Eray_RegPrtc1 PRTC1 ;     /* Configuration value for register PRTC1 */
  Fr_17_Eray_RegPrtc2 PRTC2 ;     /* Configuration value for register PRTC2 */

  Fr_17_Eray_RegMhdc  MHDC ;      /* Configuration value for register MHDC */

  Fr_17_Eray_RegGtuc01 GTUC01 ;   /* Configuration value for register GTUC01 */
  Fr_17_Eray_RegGtuc02 GTUC02 ;   /* Configuration value for register GTUC02 */
  Fr_17_Eray_RegGtuc03 GTUC03 ;   /* Configuration value for register GTUC03 */
  Fr_17_Eray_RegGtuc04 GTUC04 ;   /* Configuration value for register GTUC04 */
  Fr_17_Eray_RegGtuc05 GTUC05 ;   /* Configuration value for register GTUC05 */
  Fr_17_Eray_RegGtuc06 GTUC06 ;   /* Configuration value for register GTUC06 */
  Fr_17_Eray_RegGtuc07 GTUC07 ;   /* Configuration value for register GTUC07 */
  Fr_17_Eray_RegGtuc08 GTUC08 ;   /* Configuration value for register GTUC08 */
  Fr_17_Eray_RegGtuc09 GTUC09 ;   /* Configuration value for register GTUC09 */
  Fr_17_Eray_RegGtuc10 GTUC10 ;   /* Configuration value for register GTUC10 */
  Fr_17_Eray_RegGtuc11 GTUC11 ;   /* Configuration value for register GTUC11 */
  Fr_17_Eray_RegCust1  CUST1;     /* Configuration value for register CUST1 */
  /*Fr_17_Eray_RegMrc    MRC;*/       /* Configuration value for register MRC */
} Fr_17_Eray_CCConfigType ;


/* ---------------------------------------------------------------------------*/

/*
  Type definition for configuration paramaters that are part of register WRHS1
*/
typedef union
{
  struct
  {
    /*
      Frame ID: FlexRay Slot ID used to transmit this FlexRay Frame.
      Note: Bits 11-15 are reserved, not used.
    */
    unsigned_int   SlotId  : 16;

    /*
      Cycle Code is derived out of parameters BaseCycle and CycleRepetition

      BaseCycle = 0..63
      CycleRepetition = 1, 2, 4, 8, 16, 32, 64

      CycleCode = CycleRepetition | BaseCycle

      Note: Bit 23 is reserved, not used.
    */
    unsigned_int   CycleCode : 8;

    /*
      FlexRay Channel used to transmit/receive this FlexRay Frame
      Values:
        1 (01b) - FR_17_ERAY_CHANNEL_A
        2 (10b) - FR_17_ERAY_CHANNEL_B
        3 (11b) - FR_17_ERAY_CHANNEL_AB
    */
    unsigned_int   Channel  : 2;

    /*
      Message Buffer Direction
        0 - Receive
        1 - Transmit
    */
    unsigned_int   Cfg  : 1;

    /*
      Payload Preamble Indicator Transmit
        0 - Disable
        1 - Enable
    */
    unsigned_int   Ppit  : 1;

    /*
      Transmission Mode
        0 - Continuous mode
        1 - Single shot mode
      Always set to single shot mode.
    */
    unsigned_int   TransmissionMode  : 1;

    /*
      Message Buffer Service Request
        0 - Buffer service request is disabled
        1 - Buffer service request is enabled
      Always set to 0, because interrupts are not used.
    */
    unsigned_int   MsgBufferServiceRequest  : 1;

  } B;

  uint32 U;

} Fr_17_Eray_RegWrhs1Type ;

/*
  Type definition for configuration paramaters that are part of register WRHS2
*/
typedef union
{
  struct
  {
    /*
      Header CRC: CRC over:
          - Sync frame indicator bit
          - Startup frame indicator bit
          - Frame ID
          - Payload length
      Relevant only for transmit buffer.
      Note: Bits 11-15 are reserved, not used.
    */
    unsigned_int   HeaderCRC  : 16;

    /*
      Payload Length Configured (FrIfLSduLength)
    */
    unsigned_int   PayloadLengthConfigured : 7;

    /*
      Whether LSDU length reduction allowed.
      Note: Only one bit is required. But all remaining 9 bits are consumed.
    */
    unsigned_int   AllowDynamicLSduLength : 9 ;
  } B;

  uint32 U;

} Fr_17_Eray_RegWrhs2Type ;

/*
  Type definition for data structure containing configuration paramaters for
  a message buffer.
*/
typedef struct
{

  Fr_17_Eray_RegWrhs1Type WRHS1 ;   /* Configuration value for register WRHS1 */
  Fr_17_Eray_RegWrhs2Type WRHS2 ;   /* Configuration value for register WRHS2 */
  uint8  LpduReconfigurable ; /* FrIfReconfigurable - is an Lpdu is dynamically
                                 reconfigurable */
  Dem_EventIdType FrDemFTSlotStatusErrId; /* DEM Id for FlexRay Slot Status
                                             Error. */
} Fr_17_Eray_LPduConfigType ;

/* ---------------------------------------------------------------------------*/

#if (FR_17_ERAY_FIFO_CONFIGURED == STD_ON)
/*
  Data type for FR Receive receive FIFO configuration.
*/
typedef struct
{
  /*
 Fifo Rejection Filter criteria
 FrChannels|(FrFid<<2)|((FrCycleRepetition|FrBaseCycle)<<16U)|(RSS<23)|(RNF<24)
    */
  uint32 FrFifoFrfCfg ;

  /* FIFO Rejection Filter Mask */
  uint16 FrFifoFrfm;

  /* Fifo Depth.*/
  uint8 FrFifoDepth ;

} Fr_17_Eray_RxFifoConfigType;
#endif /* #if (FR_17_ERAY_FIFO_CONFIGURED == STD_ON) */

/*
  Structure to define all the left out paramters required for Fr_ReadCCConfig */
typedef struct
{

  /* FrIfGdCycle */
  uint32 FrIfGdCycle ;

  /* FrIfGdBit */
  uint32 FrIfGdBit ;

  /* FrIfGdMacrotick */
  uint16 FrIfGdMacrotick ;

  /* FrIfGdNit */
  uint8 FrIfGdNit ;

  /* FrIfGCycleCountMax */
  uint8 FrIfGCycleCountMax ;

  /* FrIfGdSymbolWindow */
  uint8 FrIfGdSymbolWindow ;

  /* FrPKeySlotId */
  uint8 FrPKeySlotId ;

  /* FrPPayloadLengthDynMax */
  uint8 FrPPayloadLengthDynMax ;

  /* FrPdMicrotick */
  uint8 FrPdMicrotick ;

} Fr_17_ReadCCParametersType;

/*
  This is the type of FlexRay external data structure containing the
  initialization data for the individual Flexray controller.
*/
typedef struct Fr_17_Eray_CCType
{
  /* Pointer to configuration of Communication Controller */
  const Fr_17_Eray_CCConfigType *CCCfgPtr;

  /* Pointer to array of LPDU configurations */
  const Fr_17_Eray_LPduConfigType *LPduConfigPtr;

  #if (FR_17_ERAY_FIFO_CONFIGURED == STD_ON)
  /* Pointer to the configuration of Receive FIFO */
  const Fr_17_Eray_RxFifoConfigType *RxFifoConfigPtr;
  #endif

  /* Pointer to leftout Fr_readCCconfig parameter structure */
  const Fr_17_ReadCCParametersType *ConfigParamPtr;

  /* Pointer to LPDU to message buffer mapping array */
  const uint8 *LPduIdx2MsgBuffIdxPtr;

  /* Pointer to data pointer offsets of message buffers */
  const uint16 *DataPointerOffsetPtr;

  /* Number of LPDUs configured */
  uint16 LPduCount;

  /* Eray System Clock Divider */
  uint8 FrClockDivider;

  /* Flag to indicate whether the Buffer reconfiguration is ON */
  uint8 FrIsBuffReconfigOn;

  /* Dem Event Id References */
  /* DEM Id for FlexRay controller hardware test failure. */
  Dem_EventIdType FrDemCtrlTestResultId;

  /* DEM Id for FlexRay controller hardware response timeout. */
  Dem_EventIdType FrDemTimeoutId;
  
  /* Number of Message buffers configured */
  uint8 MsgBuffCountMax;

} Fr_17_Eray_CCType;

/* 
Controller and absolute timer interrupt registers
*/
typedef struct
{

  Ifx_ERAY* ERAY ;   /* Configuration value for register WRHS1 */
  Fr_17_Eray_RegWrhs2Type WRHS2 ;   /* Configuration value for register WRHS2 */
  uint8  LpduReconfigurable ; /* FrIfReconfigurable - is an Lpdu is dynamically
                                 reconfigurable */
  Dem_EventIdType FrDemFTSlotStatusErrId; /* DEM Id for FlexRay Slot Status
                                             Error. */
} Fr_17_Eray_RegMapType ;

/*
  This is the type of FlexRay external data structure containing the overall
  initialization data for the FlexRay Driver.
*/
typedef struct Fr_17_Eray_ConfigType
{
  /* Pointer to the data structure containing the
  initialization data for the individual Flexray controller */
  const Fr_17_Eray_CCType *CfgPtr ;

  /* Pointer to Physical to Logical Indexing map array */
  const uint8 *Phy2LogIdxPtr ;
  
} Fr_17_Eray_ConfigType ;


/* [/cover] */
/* [/cover] */
/* ---------------------------------------------------------------------------*/


/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/
/*
  Note: Elektrobit Automotive GmbH modified the original code provided
        by the third party supplier. The modification is provided for
        convenience.
        Please use the modification on your discretion and account, or
        use the unmodified files provided with this distribution. 
  Please see for the reasons in the file ImportantNotes.txt for tag
*/

/*EB implement workaround for ASCINFINEON-659*/
#define FR_17_ERAY_START_SEC_CONFIG_DATA_QM_UNSPECIFIED
#include "Fr_17_Eray_MemMap.h"

extern const Fr_17_Eray_ConfigType Fr_17_Eray_Config;                                                                                                                       

#define CFR_17_ERAY__STOP_SEC_CONFIG_DATA_QM_UNSPECIFIED
#include "Fr_17_Eray_MemMap.h"
/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
/* Memory Map of the FR Code */
#define FR_17_ERAY_START_SEC_CODE_QM_GLOBAL
#include "Fr_17_Eray_MemMap.h"

/*******************************************************************************
** Traceability    : [cover parentID= ]                                       **
**                                                                            **
** Syntax          : void Fr_17_Eray_Init( const Fr_17_Eray_ConfigType        **
**                                                            *Fr_ConfigPtr)  **
**                                                                            **
** Description     : Initalizes the Fr                                        **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      :  0x1c                                                    **
**                                                                            **
** Sync/Async      :  Synchronous                                             **
**                                                                            **
** Reentrancy      :  non reentrant                                           **
**                                                                            **
** Parameters (in) : Fr_ConfigPtr - Address to an Fr dependant configuration  **
**                                  structure that contains all information   **
**                                  for operating the Fr subsequently.        **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value    :  none                                                    **
**                                                                            **
*******************************************************************************/
extern void Fr_17_Eray_Init(const Fr_17_Eray_ConfigType* Fr_ConfigPtr);

/*******************************************************************************
** Traceability    : [cover parentID= ]                                       **
**                                                                            **
** Syntax          : Std_ReturnType Fr_17_Eray_ControllerInit                 **
**                                                        (uint8 Fr_CtrlIdx)  **
**                                                                            **
** Description     : Initialzes a FlexRay CC.                                 **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      :  0x00                                                    **
**                                                                            **
** Sync/Async      :  Synchronous                                             **
**                                                                            **
** Reentrancy      :  Non reentrant for the same device                       **
**                                                                            **
** Parameters (in) : Fr_CtrlIdx - Index of FlexRay CC within the context of   **
**                                the FlexRay Driver.                         **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value    :  E_OK: API call finished successfully.                   **
**                    E_NOT_OK: API call aborted due to errors.               **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Fr_17_Eray_ControllerInit
(
  uint8 Fr_CtrlIdx
);

/*******************************************************************************
** Traceability    : [cover parentID= ]                                       **
**                                                                            **
** Syntax          : Std_ReturnType Fr_17_Eray_StartCommunication             **
**                                                        (uint8 Fr_CtrlIdx)  **
**                                                                            **
** Description     : Starts FlexRay communication.                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      :  0x03                                                    **
**                                                                            **
** Sync/Async      :  Synchronous                                             **
**                                                                            **
** Reentrancy      :  Non reentrant for the same device                       **
**                                                                            **
** Parameters (in) : Fr_CtrlIdx - Index of FlexRay CC within the context of   **
**                                the FlexRay Driver.                         **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value    :  E_OK: API call finished successfully.                   **
**                    E_NOT_OK: API call aborted due to errors.               **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Fr_17_Eray_StartCommunication( uint8 Fr_CtrlIdx );

/*******************************************************************************
** Traceability    : [cover parentID= ]                                       **
**                                                                            **
** Syntax          : Std_ReturnType Fr_17_Eray_AllowColdstart                 **
**                                                        (uint8 Fr_CtrlIdx)  **
**                                                                            **
** Description     : Invokes the CC CHI command 'ALLOW_COLDSTART'.            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      :  0x23                                                    **
**                                                                            **
** Sync/Async      :  Asynchronous                                            **
**                                                                            **
** Reentrancy      :  Non reentrant for the same device                       **
**                                                                            **
** Parameters (in) : Fr_CtrlIdx - Index of FlexRay CC within the context of   **
**                                the FlexRay Driver.                         **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value    :  E_OK: API call finished successfully.                   **
**                    E_NOT_OK: API call aborted due to errors.               **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Fr_17_Eray_AllowColdstart( uint8 Fr_CtrlIdx );

/*******************************************************************************
** Traceability    : [cover parentID= ]                                       **
**                                                                            **
** Syntax          : Std_ReturnType Fr_17_Eray_AllSlots(uint8 Fr_CtrlIdx)     **
**                                                                            **
** Description     : Invokes the CC CHI command 'ALL_SLOTS'.                  **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      :  0x24                                                    **
**                                                                            **
** Sync/Async      :  Asynchronous                                            **
**                                                                            **
** Reentrancy      :  Non reentrant for the same device                       **
**                                                                            **
** Parameters (in) : Fr_CtrlIdx - Index of FlexRay CC within the context of   **
**                                the FlexRay Driver.                         **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value    :  E_OK: API call finished successfully.                   **
**                    E_NOT_OK: API call aborted due to errors.               **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Fr_17_Eray_AllSlots( uint8 Fr_CtrlIdx );


/*******************************************************************************
** Traceability    : [cover parentID= ]                                       **
**                                                                            **
** Syntax          : Std_ReturnType Fr_17_Eray_HaltCommunication              **
**                                                        (uint8 Fr_CtrlIdx)  **
**                                                                            **
** Description     : Invokes the CC CHI command 'HALT'.                       **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      :  0x04                                                    **
**                                                                            **
** Sync/Async      :  Asynchronous                                            **
**                                                                            **
** Reentrancy      :  Non reentrant for the same device                       **
**                                                                            **
** Parameters (in) : Fr_CtrlIdx - Index of FlexRay CC within the context of   **
**                                the FlexRay Driver.                         **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value    :  E_OK: API call finished successfully.                   **
**                    E_NOT_OK: API call aborted due to errors.               **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Fr_17_Eray_HaltCommunication( uint8 Fr_CtrlIdx );

/*******************************************************************************
** Traceability    : [cover parentID= ]                                       **
**                                                                            **
** Syntax          : Std_ReturnType Fr_17_Eray_AbortCommunication             **
**                                                        (uint8 Fr_CtrlIdx)  **
**                                                                            **
** Description     : Invokes the CC CHI command 'FREEZE'.                     **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      :  0x05                                                    **
**                                                                            **
** Sync/Async      :  Synchronous                                             **
**                                                                            **
** Reentrancy      :  Non reentrant for the same device                       **
**                                                                            **
** Parameters (in) : Fr_CtrlIdx - Index of FlexRay CC within the context of   **
**                                the FlexRay Driver.                         **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value    :  E_OK: API call finished successfully.                   **
**                    E_NOT_OK: API call aborted due to errors.               **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Fr_17_Eray_AbortCommunication( uint8 Fr_CtrlIdx );

/*******************************************************************************
** Traceability    : [cover parentID= ]                                       **
**                                                                            **
** Syntax          : Std_ReturnType Fr_17_Eray_SendWUP(uint8 Fr_CtrlIdx)      **
**                                                                            **
** Description     : Invokes the CC CHI command 'WAKEUP'.                     **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      :  0x06                                                    **
**                                                                            **
** Sync/Async      :  Asynchronous                                            **
**                                                                            **
** Reentrancy      :  Non reentrant for the same device                       **
**                                                                            **
** Parameters (in) : Fr_CtrlIdx - Index of FlexRay CC within the context of   **
**                                the FlexRay Driver.                         **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value    :  E_OK: API call finished successfully.                   **
**                    E_NOT_OK: API call aborted due to errors.               **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Fr_17_Eray_SendWUP( uint8 Fr_CtrlIdx );

/*******************************************************************************
** Traceability    : [cover parentID= ]                                       **
**                                                                            **
** Syntax          : Std_ReturnType Fr_17_Eray_SetWakeupChannel               **
**                         (uint8 Fr_CtrlIdx, Fr_ChannelType Fr_ChnlIdx)      **
**                                                                            **
** Description     : Sets a wakeup channel.                                   **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      :  0x07                                                    **
**                                                                            **
** Sync/Async      :  Synchronous                                             **
**                                                                            **
** Reentrancy      :  Non reentrant for the same device                       **
**                                                                            **
** Parameters (in) : Fr_CtrlIdx - Index of FlexRay CC within the context of   **
**                                the FlexRay Driver.                         **
**                   Fr_ChnlIdx - Index of FlexRay channel within the context **
**                                of the FlexRay CC Fr_CtrlIdx. Valid values  **
**                                are FR_CHANNEL_A and FR_CHANNEL_B.          **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value    :  E_OK: API call finished successfully.                   **
**                    E_NOT_OK: API call aborted due to errors.               **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Fr_17_Eray_SetWakeupChannel
(
  uint8 Fr_CtrlIdx,
  Fr_ChannelType Fr_ChnlIdx
);

/*******************************************************************************
** Syntax : Std_ReturnType Fr_17_Eray_GetPOCStatus(                           **
**                                    uint8 Fr_CtrlIdx,                       **
**                                    Fr_POCStatusType* Fr_POCStatusPtr       **
**                         )                                                  **
**                                                                            **
** Service ID:  0x0a                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant for the same device                             **
**                                                                            **
** Parameters (in): Fr_CtrlIdx - Index of FlexRay CC within the context of    **
**                                the FlexRay Driver.                         **
**                                                                            **
** Parameters (out): Fr_POCStatusPtr - Address the output value is stored to. **
**                                                                            **
** Return value:  E_OK: API call finished successfully.                       **
**                E_NOT_OK: API call aborted due to errors.                   **
**                                                                            **
** Description : Gets the POC status.                                  **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Fr_17_Eray_GetPOCStatus
(
  uint8 Fr_CtrlIdx,
  Fr_POCStatusType* Fr_POCStatusPtr
);

/*******************************************************************************
** Traceability    : [cover parentID= ]                                       **
**                                                                            **
** Syntax          : Std_ReturnType Fr_17_Eray_TransmitTxLPdu(                **
**                                    uint8 Fr_CtrlIdx,                       **
**                                    uint16 Fr_LPduIdx,                      **
**                                    const uint8 *Fr_LSduPtr,                **
**                                    uint8 Fr_LSduLength                     **
**                         )                                                  **
**                                                                            **
** Description     : Transmits data on the FlexRay network                    **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      :  0x0b                                                    **
**                                                                            **
** Sync/Async      :  Asynchronous                                            **
**                                                                            **
** Reentrancy      :  non reentrant for the same device                       **
**                                                                            **
** Parameters (in) : Fr_CtrlIdx - Index of FlexRay CC within the context of   **
**                                the FlexRay Driver.                         **
**                   Fr_LPduIdx - This index is used to uniquely identify a   **
**                                  FlexRay frame.                            **
**                   Fr_LSduPtr - This reference points to a buffer where the **
**                                  assembled LSdu to be transmitted within   **
**                                  this LPdu is stored at.                   **
**                   Fr_LSduLength - Determines the length of the data (in    **
**                                   Bytes) to be transmitted.                **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    :  E_OK: API call finished successfully.                   **
**                    E_NOT_OK: API call aborted due to errors.               **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Fr_17_Eray_TransmitTxLPdu
(
  uint8 Fr_CtrlIdx,
  uint16 Fr_LPduIdx,
  const uint8* Fr_LSduPtr,
  uint8 Fr_LSduLength
);

/*******************************************************************************
** Traceability    : [cover parentID= ]                                       **
**                                                                            **
** Syntax          : Std_ReturnType Fr_17_Eray_CancelTxLPdu(                  **
**                                    uint8 Fr_CtrlIdx,                       **
**                                    uint16 Fr_LPduIdx,                      **
**                                   )                                        **
**                                                                            **
** Description     : Cancels the already pending transmission of a LPdu       **
                     contained in a controllers physical transmit resource    **
                     (e.g. message buffer).                                   **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      :  0x2d                                                    **
**                                                                            **
** Sync/Async      :  Asynchronous                                            **
**                                                                            **
** Reentrancy      :  non reentrant for the same device                       **
**                                                                            **
** Parameters (in) : Fr_CtrlIdx - Index of FlexRay CC within the context of   **
**                                the FlexRay Driver.                         **
**                   Fr_LPduIdx - This index is used to uniquely identify a   **
**                                  FlexRay frame.                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    :  E_OK: API call finished successfully.                   **
**                    E_NOT_OK: API call aborted due to errors.               **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Fr_17_Eray_CancelTxLPdu
(
  uint8 Fr_CtrlIdx,
  uint16 Fr_LPduIdx
);

/*******************************************************************************
** Traceability    : [cover parentID= ]                                       **
**                                                                            **
** Syntax          : Std_ReturnType Fr_17_Eray_ReceiveRxLPdu(                 **
**                                    uint8 Fr_CtrlIdx,                       **
**                                    uint16 Fr_LPduIdx,                      **
**                                    uint8 *Fr_LSduPtr,                      **
**                                    Fr_RxLPduStatusType *Fr_LPduStatusPtr,  **
**                                    uint8 *Fr_LSduLengthPtr                 **
**                         )                                                  **
**                                                                            **
** Description     : Receives data from the FlexRay network.                  **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      :  0x0c                                                    **
**                                                                            **
** Sync/Async      :  Synchronous                                             **
**                                                                            **
** Reentrancy      :  non reentrant for the same device                       **
**                                                                            **
** Parameters (in) : Fr_CtrlIdx - Index of FlexRay CC within the context of   **
**                                the FlexRay Driver.                         **
**                  Fr_LPduIdx - This index is used to uniquely identify a    **
**                                  FlexRay frame.                            **
**                                                                            **
** Parameters (out):                                                          **
**                  Fr_LSduPtr - This reference points to a buffer where the  **
**                                  LSdu to be received shall be stored       **
**                  Fr_LPduStatusPtr - This reference points to the memory    **
**                                      location where the status of the LPdu **
**                                      shall be stored                       **
**                  Fr_LSduLengthPtr - This reference points to the memory    **
**                           location where the length of the LSdu (in bytes) **
**                           shall be stored. This length represents the      **
**                           number of bytes copied to LSduPtr.               **
**                                                                            **
** Return value    :  E_OK: API call finished successfully.                   **
**                    E_NOT_OK: API call aborted due to errors.               **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Fr_17_Eray_ReceiveRxLPdu
(
  uint8 Fr_CtrlIdx,
  uint16 Fr_LPduIdx,
  uint8* Fr_LSduPtr,
  Fr_RxLPduStatusType* Fr_LPduStatusPtr,
  uint8* Fr_LSduLengthPtr
);

/*******************************************************************************
** Traceability    : [cover parentID= ]                                       **
**                                                                            **
** Syntax          : Std_ReturnType Fr_17_Eray_CheckTxLPduStatus(             **
**                                    uint8 Fr_CtrlIdx,                       **
**                                    uint16 Fr_LPduIdx,                      **
**                                    Fr_TxLPduStatusType *Fr_TxLPduStatusPtr **
**                         )                                                  **
**                                                                            **
** Description     : Checks the transmit status of the LSdu.                  **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      :  0x0d                                                    **
**                                                                            **
** Sync/Async      :  Synchronous                                             **
**                                                                            **
** Reentrancy      :  non reentrant for the same device                       **
**                                                                            **
** Parameters (in) : Fr_CtrlIdx - Index of FlexRay CC within the context of   **
**                                the FlexRay Driver.                         **
**                                                                            **
**                   Fr_LPduIdx - This index is used to uniquely identify a   **
**                                  FlexRay frame.                            **
**                                                                            **
** Parameters (out):                                                          **
**                  TxLPduStatusPtr - This reference is used to store the     **
**                                        transmit status of the LSdu         **
**                                                                            **
** Return value    :  E_OK: API call finished successfully.                   **
**                    E_NOT_OK: API call aborted due to errors.               **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Fr_17_Eray_CheckTxLPduStatus
(
  uint8 Fr_CtrlIdx,
  uint16 Fr_LPduIdx,
  Fr_TxLPduStatusType* Fr_TxLPduStatusPtr
);

#if (FR_17_ERAY_PREPARE_LPDU == STD_ON)
/*******************************************************************************
** Traceability    : [cover parentID= ]                                       **
**                                                                            **
** Syntax          : Std_ReturnType Fr_17_Eray_PrepareLPdu(                   **
**                                    uint8 Fr_CtrlIdx,                       **
**                                    uint16 Fr_LPduIdx,                      **
**                         )                                                  **
**                                                                            **
** Description     : Prepares a LPdu.                                         **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      :  0x1f                                                    **
**                                                                            **
** Sync/Async      :  Synchronous                                             **
**                                                                            **
** Reentrancy      :  non reentrant for the same device                       **
**                                                                            **
** Parameters (in) : Fr_CtrlIdx - Index of FlexRay CC within the context of   **
**                                the FlexRay Driver.                         **
**                   Fr_LPduIdx - This index is used to uniquely identify a   **
**                                  FlexRay frame.                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    :  E_OK: API call finished successfully.                   **
**                    E_NOT_OK: API call aborted due to errors.               **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Fr_17_Eray_PrepareLPdu
(
  uint8 Fr_CtrlIdx,
  uint16 Fr_LPduIdx
);
#else
#define Fr_17_Eray_PrepareLPdu( Fr_CtrlIdx, Fr_LPduIdx) \
ERROR_Fr_17_Eray_PrepareLPdu_NOT_SELECTED
#endif /* (FR_17_ERAY_PREPARE_LPDU == STD_ON) */

#if (FR_17_ERAY_RECONFIG_LPDU == STD_ON)
/*******************************************************************************
** Traceability    : [cover parentID= ]                                       **
**                                                                            **
** Syntax          : Std_ReturnType Fr_17_Eray_ReconfigLPdu(                  **
**                                           uint8 Fr_CtrlIdx,                **
**                                           uint16 Fr_LPduIdx,               **
**                                           uint16 Fr_FrameId,               **
**                                           Fr_ChannelType Fr_ChnlIdx,       **
**                                           uint8 Fr_CycleRepetition,        **
**                                           uint8 Fr_CycleOffset,            **
**                                           uint8 Fr_PayloadLength,          **
**                                           uint16 Fr_HeaderCRC              **
**                                           )                                **
**                                                                            **
** Description     : Reconfigures a given LPdu according to the parameters    **
         (FrameId, Channel, CycleRepetition, CycleOffset, PayloadLength,      **
         HeaderCRC) at runtime.                                               **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      :  0x25                                                    **
**                                                                            **
** Sync/Async      :  Synchronous                                             **
**                                                                            **
** Reentrancy      :  non reentrant for the same device                       **
**                                                                            **
** Parameters (in) : Fr_CtrlIdx - Index of FlexRay CC within the context of   **
**                                the FlexRay Driver.                         **
**                   Fr_LPduIdx - This index is used to uniquely identify a   **
**                                FlexRay frame.                              **
**                   Fr_FrameId - FlexRay Frame ID the FrIf_LPdu shall be     **
**                                configured to.                              **
**                   Fr_ChnlIdx - FlexRay Channel the FrIf_LPdu shall be      **
**                                configured to.                              **
**                   Fr_CycleRepetition -Cycle Repetition part of the cycle   **
**                          filter mechanism FrIf_LPdu shall be configured to **
**                   Fr_CycleOffset - Cycle Offset part of the cycle filter   **
**                                mechanism FrIf_LPdu shall be configured to. **
**                   Fr_PayloadLength  - Payloadlength in units of bytes the  **
**                                FrIf_LPduIdx shall be configured to.        **
**                   Fr_HeaderCRC - Header CRC the FrIf_LPdu shall be         **
**                                  configured to.                            **
**                                                                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    :  E_OK: API call finished successfully.                   **
**                    E_NOT_OK: API call aborted due to errors.               **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Fr_17_Eray_ReconfigLPdu(
    uint8 Fr_CtrlIdx,
    uint16 Fr_LPduIdx,
    uint16 Fr_FrameId,
    Fr_ChannelType Fr_ChnlIdx,
    uint8 Fr_CycleRepetition,
    uint8 Fr_CycleOffset,
    uint8 Fr_PayloadLength,
    uint16 Fr_HeaderCRC
);

#else
#define Fr_17_Eray_ReconfigLPdu(CtrlIdx, Fr_LPduIdx,Fr_FrameId,Fr_ChnlIdx, \
Fr_CycleRepetition, Fr_CycleOffset, Fr_PayloadLength, Fr_HeaderCRC)\
ERROR_Fr_17_Eray_ReconfigLPdu_NOT_SELECTED
#endif /* (FR_17_ERAY_RECONFIG_LPDU == STD_ON) */

#if (FR_17_ERAY_DISABLE_LPDU == STD_ON)
/*******************************************************************************
** Traceability    : [cover parentID= ]                                       **
**                                                                            **
** Syntax          : Std_ReturnType Fr_17_Eray_DisableLPdu(                   **
**                                           uint8 Fr_CtrlIdx,                **
**                                           uint16 Fr_LPduIdx,               **
**                                           )                                **
**                                                                            **
** Description     : Disables the hardware resource of a LPdu for             **
                     transmission/reception.                                  **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      :  0x26                                                    **
**                                                                            **
** Sync/Async      :  Synchronous                                             **
**                                                                            **
** Reentrancy      :  non reentrant for the same device                       **
**                                                                            **
** Parameters (in) : Fr_CtrlIdx - Index of FlexRay CC within the context of   **
**                                the FlexRay Driver.                         **
**                                                                            **
**                   Fr_LPduIdx - This index is used to uniquely identify a   **
**                                  FlexRay frame.                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    :  E_OK: API call finished successfully.                   **
**                    E_NOT_OK: API call aborted due to errors.               **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Fr_17_Eray_DisableLPdu(
    uint8 Fr_CtrlIdx,
    uint16 Fr_LPduIdx
);

#else
#define Fr_17_Eray_DisableLPdu(CtrlIdx, Fr_LPduIdx )\
ERROR_Fr_17_Eray_DisableLPdu_NOT_SELECTED
#endif /* (FR_17_ERAY_DISABLE_LPDU == STD_ON) */

/*******************************************************************************
** Traceability    : [cover parentID= ]                                       **
**                                                                            **
** Syntax          : Std_ReturnType Fr_17_Eray_GetGlobalTime(                 **
**                                    uint8 Fr_CtrlIdx,                       **
**                                    uint8* Fr_CyclePtr,                     **
**                                    uint16* Fr_MacroTickPtr                 **
**                         )                                                  **
**                                                                            **
** Description     : Gets the current global FlexRay time.                    **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      :  0x10                                                    **
**                                                                            **
** Sync/Async      :  Synchronous                                             **
**                                                                            **
** Reentrancy      :  non reentrant for the same device                       **
**                                                                            **
** Parameters (in) : Fr_CtrlIdx - Index of FlexRay CC within the context of   **
**                                the FlexRay Driver.                         **
**                                                                            **
** Parameters (out):                                                          **
**                  Fr_CyclePtr - Address where the current FlexRay           **
**                                communication cycle value shall be stored.  **
**                  Fr_MacroTickPtr - Address where the current macrotick     **
**                                    value shall be stored.                  **
**                                                                            **
** Return value    :  E_OK: API call finished successfully.                   **
**                    E_NOT_OK: API call aborted due to errors.               **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Fr_17_Eray_GetGlobalTime
(
  uint8 Fr_CtrlIdx,
  uint8* Fr_CyclePtr,
  uint16* Fr_MacroTickPtr
);

#if (FR_17_ERAY_NMVECTOR_ENABLE == STD_ON)
/*******************************************************************************
** Traceability    : [cover parentID= ]                                       **
**                                                                            **
** Syntax          : Std_ReturnType Fr_17_Eray_GetNmVector(                   **
**                                    uint8 Fr_CtrlIdx,                       **
**                                    uint8* Fr_NmVectorPtr                   **
**                         )                                                  **
**                                                                            **
** Description     : Gets the network management vector of the last           **
**                   communication cycle.                                     **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      :  0x22                                                    **
**                                                                            **
** Sync/Async      :  Synchronous                                             **
**                                                                            **
** Reentrancy      :  non reentrant for the same device                       **
**                                                                            **
** Parameters (in) : Fr_CtrlIdx - Index of FlexRay CC within the context of   **
**                                the FlexRay Driver.                         **
**                                                                            **
** Parameters (out):                                                          **
**                  Fr_NmVectorPtr - Address where the NmVector of the last   **
**                                communication cycle shall be stored.        **
**                                                                            **
** Return value    :  E_OK: API call finished successfully.                   **
**                    E_NOT_OK: API call aborted due to errors.               **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Fr_17_Eray_GetNmVector
(
  uint8 Fr_CtrlIdx,
  uint8* Fr_NmVectorPtr
);
#else
#define Fr_17_Eray_GetNmVector(CtrlIdx, NmVectorPtr) \
ERROR_Fr_17_Eray_GetNmVector_NOT_SELECTED
#endif /* (FR_17_ERAY_NMVECTOR_ENABLE == STD_ON) */

/*******************************************************************************
** Traceability    : [cover parentID= ]                                       **
**                                                                            **
** Syntax          : Std_ReturnType Fr_17_Eray_GetNumOfStartupFrames(         **
**                                    uint8 Fr_CtrlIdx,                       **
**                                    uint8* Fr_NumOfStartupFramesPtr         **
**                                    )                                       **
**                                                                            **
** Description     : Gets the current number of startup frames seen on the    **
**                   cluster.                                                 **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      :  0x27                                                    **
**                                                                            **
** Sync/Async      :  Synchronous                                             **
**                                                                            **
** Reentrancy      :  non reentrant for the same device                       **
**                                                                            **
** Parameters (in) : Fr_CtrlIdx - Index of FlexRay CC within the context of   **
**                                the FlexRay Driver.                         **
**                                                                            **
** Parameters (out):                                                          **
**          Fr_NumOfStartupFramesPtr - Address where the number of startup    **
**          frames seen within the last even/odd cycle pair shall be stored.  **
**                                                                            **
** Return value    :  E_OK: API call finished successfully.                   **
**                    E_NOT_OK: API call aborted due to errors.               **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Fr_17_Eray_GetNumOfStartupFrames
(
    uint8 Fr_CtrlIdx,
    uint8* Fr_NumOfStartupFramesPtr
);

/*******************************************************************************
** Traceability    : [cover parentID= ]                                       **
**                                                                            **
** Syntax          : Std_ReturnType Fr_17_Eray_GetChannelStatus               **
                     (                                                        **
**                         uint8 Fr_CtrlIdx,                                  **
**                         uint16* Fr_ChannelAStatusPtr,                      **
**                         uint16* Fr_ChannelBStatusPtr                       **
**                      )                                                     **
**                                                                            **
** Description     : Gets the channel status information.                     **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service  ID     :  0x28                                                    **
**                                                                            **
** Sync/Async      :  Synchronous                                             **
**                                                                            **
** Reentrancy      :  non reentrant for the same device                       **
**                                                                            **
** Parameters (in) : Fr_CtrlIdx - Index of FlexRay CC within the context of   **
**                                the FlexRay Driver.                         **
**                                                                            **
** Parameters (out):                                                          **
**          Fr_ChannelAStatusPtr - Address where the bitcoded channel A       **
            status information shall be stored.                               **
            Fr_ChannelBStatusPtr - Address where the bitcoded channel B       **
            status information shall be stored.                               **
**                                                                            **
** Return value    :  E_OK: API call finished successfully.                   **
**                    E_NOT_OK: API call aborted due to errors.               **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Fr_17_Eray_GetChannelStatus
(
    uint8 Fr_CtrlIdx,
    uint16* Fr_ChannelAStatusPtr,
    uint16* Fr_ChannelBStatusPtr
);

/*******************************************************************************
** Traceability    : [cover parentID= ]                                       **
**                                                                            **
** Syntax          : Std_ReturnType Fr_17_Eray_GetClockCorrection             **
                          (                                                   **
                           uint8 Fr_CtrlIdx,                                  **
                           sint16* Fr_RateCorrectionPtr,                      **
                           sint32* Fr_OffsetCorrectionPtr                     **
                          )                                                   **
**                                                                            **
**                                                                            **
** Description     : Gets the current clock correction values.                **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service  ID     :  0x29                                                    **
**                                                                            **
**  Sync/Async     :  Synchronous                                             **
**                                                                            **
**  Reentrancy     :  non reentrant for the same device                       **
**                                                                            **
** Parameters (in) : Fr_CtrlIdx - Index of FlexRay CC within the context of   **
**                                the FlexRay Driver.                         **
**                                                                            **
** Parameters (out):                                                          **
**                   Fr_RateCorrectionPtr - Address where the current rate    **
**                             correction value shall be stored.              **
**                   Fr_ChannelBStatusPtr - Address where the current offset  **
**                             correction value shall be stored.              **
**                                                                            **
** Return value    :  E_OK: API call finished successfully.                   **
**                    E_NOT_OK: API call aborted due to errors.               **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Fr_17_Eray_GetClockCorrection
(
    uint8 Fr_CtrlIdx,
    sint16* Fr_RateCorrectionPtr,
    sint32* Fr_OffsetCorrectionPtr
);

/*******************************************************************************
** Traceability    : [cover parentID= ]                                       **
**                                                                            **
** Syntax          : Std_ReturnType Fr_17_Eray_GetSyncFrameList               **
                     (                                                        **
                          uint8 Fr_CtrlIdx,                                   **
                          uint8 Fr_ListSize,                                  **
                          uint16* Fr_ChannelAEvenListPtr,                     **
                          uint16* Fr_ChannelBEvenListPtr,                     **
                          uint16* Fr_ChannelAOddListPtr,                      **
                          uint16* Fr_ChannelBOddListPtr                       **
                     )                                                        **
**                                                                            **
** Description     : Gets a list of syncframes received or transmitted on     **
                     channel A and channel B via the even and odd             **
                     communication cycle                                      **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service  ID     :  0x2a                                                    **
**                                                                            **
** Sync/Async      :  Synchronous                                             **
**                                                                            **
** Reentrancy      :  non reentrant for the same device                       **
**                                                                            **
** Parameters (in) : Fr_CtrlIdx - Index of FlexRay CC within the context of   **
                     the FlexRay Driver.                                      **
                     Fr_ListSize - Size of the arrays passed via parameters:  **
                     Fr_ChannelAEvenListPtr                                   **
                     Fr_ChannelBEvenListPtr                                   **
                     Fr_ChannelAOddListPtr                                    **
                     Fr_ChannelBOddListPtr.                                   **
                     The service must ensure to not write more entries into   **
                     those arrays than granted by this parameter.             **
**                                                                            **
** Parameters (out):                                                          **
**  Fr_ChannelAEvenListPtr - Address the list of syncframes on channel        **
        A within the even communication cycle is written to. The exact number **
        of elements written to the list is limited by parameter Fr_ListSize.  **
        Unused list elements are filled with the value '0' to indicate that   **
        no more syncframe has been seen.                                      **
    Fr_ChannelBEvenListPtr - Address the list of syncframes on channel B      **
        within the even communication cycle is written to. The exact number   **
        of elements written to the list is limited by parameter Fr_ListSize.  **
        Unused list elements are filled with the value '0' to indicate that   **
        no more syncframe has been seen.                                      **
    Fr_ChannelAOddListPtr - Address the list of syncframes on channel A       **
      within the odd communication cycle is written to. The exact number of   **
      elements written to the list is limited by parameter Fr_ListSize.       **
      Unused list elements are filled with the value '0' to indicate that     **
      no more syncframe has been seen.                                        **
    Fr_ChannelBOddListPtr - Address the list of syncframes on channel B       **
      within the odd communication cycle is written to. The exact number      **
      of elements written to the list is limited by parameter Fr_ListSize.    **
      Unused list elements are filled with the value '0' to indicate that     **
      no more syncframe has been seen.                                        **
**                                                                            **
** Return value    :  E_OK: API call finished successfully.                   **
**                    E_NOT_OK: API call aborted due to errors.               **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Fr_17_Eray_GetSyncFrameList
(
    uint8 Fr_CtrlIdx,
    uint8 Fr_ListSize,
    uint16* Fr_ChannelAEvenListPtr,
    uint16* Fr_ChannelBEvenListPtr,
    uint16* Fr_ChannelAOddListPtr,
    uint16* Fr_ChannelBOddListPtr
);

/*******************************************************************************
** Traceability    : [cover parentID= ]                                       **
**                                                                            **
** Syntax          : Std_ReturnType Fr_17_Eray_GetWakeupRxStatus              **
                     (                                                        **
                         uint8 Fr_CtrlIdx,                                    **
                         uint8* Fr_WakeupRxStatusPtr                          **
                     )                                                        **
                                                                              **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Description    : Gets the wakeup received information from the FlexRay     **
**                  controller.                                               **
**                                                                            **
** Service  ID     :  0x2b                                                    **
**                                                                            **
** Sync/Async      :  Synchronous                                             **
**                                                                            **
** Reentrancy      :  non reentrant for the same device                       **
**                                                                            **
** Parameters (in) : Fr_CtrlIdx - Index of FlexRay CC within the context of   **
                     the FlexRay Driver.                                      **
**                                                                            **
** Parameters (out):                                                          **
**                   Fr_WakeupRxStatusPtr - Address where bitcoded wakeup     **
**                   reception status shall be stored.                        **
**                    Bit 0: Wakeup received on channel A indicator           **
**                    Bit 1: Wakeup received on channel B indicator           **
**                    Bit 2-7: Unused                                         **
**                                                                            **
** Return value   :  E_OK: API call finished successfully.                    **
**                   E_NOT_OK: API call aborted due to errors.                **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Fr_17_Eray_GetWakeupRxStatus
(
    uint8 Fr_CtrlIdx,
    uint8* Fr_WakeupRxStatusPtr
);

/*******************************************************************************
** Traceability    : [cover parentID= ]                                       **
**                                                                            **
** Syntax          : Std_ReturnType Fr_17_Eray_SetAbsoluteTimer(              **
**                                    uint8 Fr_CtrlIdx,                       **
**                                    uint8 Fr_AbsTimerIdx,                   **
**                                    uint8 Fr_Cycle,                         **
**                                    uint16 Fr_Offset                        **
**                         )                                                  **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      :  0x11                                                    **
**                                                                            **
** Sync/Async      :  Synchronous                                             **
**                                                                            **
** Reentrancy      :  non reentrant for the same device                       **
**                                                                            **
** Parameters (in) : Fr_CtrlIdx - Index of FlexRay CC within the context of   **
**                                the FlexRay Driver.                         **
**                  Fr_AbsTimerIdx - Index of absolute timer within the       **
**                                    context of the FlexRay CC.              **
**                  Fr_Cycle - Absolute cycle the timer shall elapse in.      **
**                  Fr_Offset - Offset within cycle Cycle in units of         **
**                              macrotick the timer shall elapse at.          **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    :  E_OK: API call finished successfully.                   **
**                    E_NOT_OK: API call aborted due to errors.               **
**                                                                            **
** Description     :  Sets the absolute FlexRay timer.                        **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Fr_17_Eray_SetAbsoluteTimer
(
  uint8 Fr_CtrlIdx,
  uint8 Fr_AbsTimerIdx,
  uint8 Fr_Cycle,
  uint16 Fr_Offset
);

/*******************************************************************************
** Traceability    : [cover parentID= ]                                       **
**                                                                            **
** Syntax          : Std_ReturnType Fr_17_Eray_CancelAbsoluteTimer(           **
**                                    uint8 Fr_CtrlIdx,                       **
**                                    uint8 Fr_AbsTimerIdx                    **
**                         )                                                  **
**                                                                            **
** Description     :  Stops an absolute timer.                                **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      :  0x13                                                    **
**                                                                            **
** Sync/Async      :  Synchronous                                             **
**                                                                            **
** Reentrancy      :  non reentrant for the same device                       **
**                                                                            **
** Parameters (in) : Fr_CtrlIdx - Index of FlexRay CC within the context of   **
**                                the FlexRay Driver.                         **
**                  Fr_AbsTimerIdx - Index of absolute timer within the       **
**                                    context of the FlexRay CC.              **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    :  E_OK: API call finished successfully.                   **
**                    E_NOT_OK: API call aborted due to errors.               **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Fr_17_Eray_CancelAbsoluteTimer
(
  uint8 Fr_CtrlIdx,
  uint8 Fr_AbsTimerIdx
);

/*******************************************************************************
** Traceability    : [cover parentID= ]                                       **
**                                                                            **
** Syntax          : Std_ReturnType Fr_17_Eray_EnableAbsoluteTimerIRQ(        **
**                                    uint8 Fr_CtrlIdx,                       **
**                                    uint8 Fr_AbsTimerIdx                    **
**                         )                                                  **
**                                                                            **
** Description     :  Enables the interrupt line of an absolute timer.        **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      :  0x15                                                    **
**                                                                            **
** Sync/Async      :  Synchronous                                             **
**                                                                            **
** Reentrancy      :  non reentrant for the same device                       **
**                                                                            **
** Parameters (in) : Fr_CtrlIdx - Index of FlexRay CC within the context of   **
**                                the FlexRay Driver.                         **
**                  Fr_AbsTimerIdx - Index of absolute timer within the       **
**                                    context of the FlexRay CC.              **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    :  E_OK: API call finished successfully.                   **
**                    E_NOT_OK: API call aborted due to errors.               **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Fr_17_Eray_EnableAbsoluteTimerIRQ
(
  uint8 Fr_CtrlIdx,
  uint8 Fr_AbsTimerIdx
);


/*******************************************************************************
** Traceability    : [cover parentID= ]                                       **
**                                                                            **
** Syntax          : Std_ReturnType Fr_17_Eray_AckAbsoluteTimerIRQ(           **
**                                    uint8 Fr_CtrlIdx,                       **
**                                    uint8 Fr_AbsTimerIdx                    **
**                         )                                                  **
**                                                                            **
** Description     :  Resets the interrupt condition of an absolute timer.    **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      :  0x17                                                    **
**                                                                            **
** Sync/Async      :  Synchronous                                             **
**                                                                            **
** Reentrancy      :  non reentrant for the same device                       **
**                                                                            **
** Parameters (in) : Fr_CtrlIdx - Index of FlexRay CC within the context of   **
**                                the FlexRay Driver.                         **
**                  Fr_AbsTimerIdx - Index of absolute timer within the       **
**                                    context of the FlexRay CC.              **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    :  E_OK: API call finished successfully.                   **
**                    E_NOT_OK: API call aborted due to errors.               **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Fr_17_Eray_AckAbsoluteTimerIRQ
(
  uint8 Fr_CtrlIdx,
  uint8 Fr_AbsTimerIdx
);

/*******************************************************************************
** Traceability    : [cover parentID= ]                                       **
**                                                                            **
** Syntax          : Std_ReturnType Fr_17_Eray_DisableAbsoluteTimerIRQ(       **
**                                    uint8 Fr_CtrlIdx,                       **
**                                    uint8 Fr_AbsTimerIdx                    **
**                         )                                                  **
**                                                                            **
** Description     :  Disables the interrupt line of an absolute timer.       **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      :  0x19                                                    **
**                                                                            **
** Sync/Async      :  Synchronous                                             **
**                                                                            **
** Reentrancy      :  non reentrant for the same device                       **
**                                                                            **
** Parameters (in) : Fr_CtrlIdx - Index of FlexRay CC within the context of   **
**                                the FlexRay Driver.                         **
**                   Fr_AbsTimerIdx - Index of absolute timer within the      **
**                                    context of the FlexRay CC.              **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    :  E_OK: API call finished successfully.                   **
**                    E_NOT_OK: API call aborted due to errors.               **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Fr_17_Eray_DisableAbsoluteTimerIRQ
(
  uint8 Fr_CtrlIdx,
  uint8 Fr_AbsTimerIdx
);


/*******************************************************************************
** Traceability    : [cover parentID= ]                                       **
**                                                                            **
**                                                                            **
** Syntax          : Std_ReturnType Fr_17_Eray_GetAbsoluteTimerIRQStatus(     **
**                                    uint8 Fr_CtrlIdx,                       **
**                                    uint8 Fr_AbsTimerIdx,                   **
**                                    boolean* Fr_IRQStatusPtr                **
**                         )                                                  **
**                                                                            **
** Description     :  Gets IRQ status of an absolute timer.                   **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      :  0x20                                                    **
**                                                                            **
** Sync/Async      :  Synchronous                                             **
**                                                                            **
** Reentrancy      :  non reentrant for the same device                       **
**                                                                            **
** Parameters (in) : Fr_CtrlIdx - Index of FlexRay CC within the context of   **
**                                the FlexRay Driver.                         **
**                   Fr_AbsTimerIdx - Index of absolute timer within the      **
**                                    context of the FlexRay CC.              **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    :  E_OK: API call finished successfully.                   **
**                    E_NOT_OK: API call aborted due to errors.               **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Fr_17_Eray_GetAbsoluteTimerIRQStatus
(
  uint8 Fr_CtrlIdx,
  uint8 Fr_AbsTimerIdx,
  boolean* Fr_IRQStatusPtr
);

/*******************************************************************************
** Traceability : [cover parentID= ]                                          **
**                                                                            **
** Syntax          : void  Fr_17_Eray_GetVersionInfo                          **
**                    (                                                       **
**                      Std_VersionInfoType *VersionInfoPtr                   **
**                    )                                                       **
**                                                                            **
** Description     : This function returns the version information of this    **
**                   module. The version information include : Module ID,     **
**                   Vendor ID,Vendor specific version numbers                **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : 0x7                                                      **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : non - reentrant                                          **
**                                                                            **
** Parameters (in) : none                                                     **
**                                                                            **
** Parameters (out): VersioninfoPtr - Pointer to where to store the           **
**                    version information of this module.                     **
**                                                                            **
** Return value    : none                                                     **
**                                                                            **
*******************************************************************************/
#if (FR_17_ERAY_VERSION_INFO_API == STD_ON)

#if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
/* MISRA2012_RULE_4_9_JUSTIFICATION:GetVersionInfo is defined as
function like macro as per AUTOSAR general guideline */
#define  Fr_17_Eray_GetVersionInfo( VersionInfoPtr )                    \
{                                                                       \
  if ((VersionInfoPtr) == NULL_PTR)                                     \
  {                                                                     \
    Det_ReportError(                                                    \
                     (uint16)FR_17_ERAY_MODULE_ID,                      \
                     FR_17_ERAY_INSTANCE_ID,                            \
                     FR_17_ERAY_SID_GETVERSIONINFO,                     \
                     FR_17_ERAY_E_PARAM_POINTER                         \
                   );/* Report to  DET */                               \
  }                                                                     \
  else                                                                  \
  {                                                                     \
  /* Note that versioninfo pointer is not checked for NULL as the user  \
     is supposed to send the memory allocated pointer */                \
  /* FR Module ID */                                                    \
  ((Std_VersionInfoType*)(VersionInfoPtr))->moduleID = FR_17_ERAY_MODULE_ID; \
  /* FR vendor ID */                                                         \
  ((Std_VersionInfoType*)(VersionInfoPtr))->vendorID = FR_17_ERAY_VENDOR_ID; \
  /* major version of FR */                                                  \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_major_version =               \
                                     (uint8)FR_17_ERAY_SW_MAJOR_VERSION;     \
  /* minor version of FR */                                                  \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_minor_version =               \
                                     (uint8)FR_17_ERAY_SW_MINOR_VERSION;     \
  /* patch version of FR */                                                  \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_patch_version =               \
                                     (uint8)FR_17_ERAY_SW_PATCH_VERSION;     \
  }                                                                          \
}
#else
/* MISRA2012_RULE_4_9_JUSTIFICATION:GetVersionInfo is defined as
function like macro as per AUTOSAR general guideline */
#define  Fr_17_Eray_GetVersionInfo( VersionInfoPtr )                         \
{                                                                            \
  if ((VersionInfoPtr) != NULL_PTR)                                          \
  {                                                                          \
  /* Note that versioninfo pointer is not checked for NULL as the user       \
     is supposed to send the memory allocated pointer */                     \
  /* FR Module ID */                                                         \
  ((Std_VersionInfoType*)(VersionInfoPtr))->moduleID = FR_17_ERAY_MODULE_ID; \
  /* FR vendor ID */                                                         \
  ((Std_VersionInfoType*)(VersionInfoPtr))->vendorID = FR_17_ERAY_VENDOR_ID; \
  /* major version of FR */                                                  \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_major_version =               \
                                     (uint8)FR_17_ERAY_SW_MAJOR_VERSION;     \
  /* minor version of FR */                                                  \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_minor_version =               \
                                     (uint8)FR_17_ERAY_SW_MINOR_VERSION;     \
  /* patch version of FR */                                                  \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_patch_version =               \
                                     (uint8)FR_17_ERAY_SW_PATCH_VERSION;     \
  }                                                                          \
}
#endif
#else

#define Fr_17_Eray_GetVersionInfo(VersionInfoPtr)                            \
                               ERROR_Fr_17_Eray_VersionInfo_NOT_SELECTED

#endif /* (FR_17_ERAY_VERSION_INFO_API)*/

/*******************************************************************************
** Traceability    : [cover parentID= ]                                       **
**                                                                            **
** Syntax          : Std_ReturnType Fr_17_Eray_ReadCCConfig                   **
                     (                                                        **
                       uint8 Fr_CtrlIdx,                                      **
                       uint8 Fr_ConfigParamIdx,                               **
                       uint32* Fr_ConfigParamValuePtr                         **
                     )                                                        **
**                                                                            **
** Description     : Reads a FlexRay protocol configuration parameter for a   **
**                   particular FlexRay controller out of the module's        **
**                   configuration.                                           **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID      :  0x2e                                                    **
**                                                                            **
** Sync/Async      :  Synchronous                                             **
**                                                                            **
** Reentrancy      :  non reentrant for the same device                       **
**                                                                            **
** Parameters (in) : Fr_CtrlIdx - Index of FlexRay CC within the context of   **
**                                the FlexRay Driver.                         **
**                   Fr_ConfigParamIdx - Index that identifies the            **
                               configuration parameter to read.               **
**                                                                            **
** Parameters (out): Fr_ConfigParamValuePtr - Address the output value is     **
                     stored to.                                               **
**                                                                            **
** Return value    :  E_OK: API call finished successfully.                   **
**                    E_NOT_OK: API call aborted due to errors.               **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Fr_17_Eray_ReadCCConfig
(
    uint8 Fr_CtrlIdx,
    uint8 Fr_ConfigParamIdx,
    uint32* Fr_ConfigParamValuePtr
);

/* Memory Map of the FR Code */
#define FR_17_ERAY_STOP_SEC_CODE_QM_GLOBAL
/* MISRA2012_RULE_4_10_JUSTIFICATION: MemMap.h is used to define memory sections
of the data or code, so included multiple times from code. This violation is an
approved exception without side effects by AUTOSAR. */
#include "Fr_17_Eray_MemMap.h"

#endif /* FR_17_ERAY_H */
