
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
**  FILENAME  : Can_17_McmCan_PBCfg.c                                         **
**                                                                            **
**  VERSION   : 3.0.0                                                         **
**                                                                            **
**  DATE, TIME: 2023-03-31, 15:32:49                                      **
**                                                                            **
**  GENERATOR : Build b171004-0528                                          **
**                                                                            **
**  BSW MODULE DECRIPTION : Can_17_McmCan.bmd                                 **
**                                                                            **
**  VARIANT   : Variant PB                                                    **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Can configuration generated out of ECUC file               **
**                                                                            **
**  SPECIFICATION(S) : Specification of Can Driver, AUTOSAR Release 4.2.2     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/



/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Include CAN Driver Header File */
#include "Can_17_McmCan.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
#define CAN_17_MCMCAN_START_SEC_CONFIG_DATA_QM_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */
#include "Can_17_McmCan_MemMap.h"
/*******************************************************************************
              CAN Kernel configuration parameters
********************************************************************************
     { CAN Global Kernel Address, The activated nodes configuration index,
      The total number of active nodes with in the kernel }
********************************************************************************
           Note: If any of CAN controller is not activated then,this
                 will not be generated
                 The value of "CanUsedHwCfgIndx" is filled with 255 if the
                 associated node is not configured
*******************************************************************************/
static const Can_McmModuleConfigType Can_kMcmModuleConfig[CAN_NOOF_KERNEL] =
{
  {
  /* MISRA2012_RULE_11_6_JUSTIFICATION: The pointer cast is used to
  cast the generated address with CAN Kernel structure type */
  /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and
  integer type. Permitted for special function registers.*/
  (volatile Ifx_CAN*) 0xF0200000U,
  {0U, 255U, 255U, 255U}, 1U
  }
};
/*******************************************************************************
               Can Controller Configurations
********************************************************************************
    { Can node Base Address,[WakeupSrcId],Combination value of Rx pin select and
    Loopback mode Support,{First Tx Hardware Object, No.of Tx Hardware Objects,
    First Rx Standard Hardware Object, No.of Rx standard Hardware Objects},
    [First Rx Extended Hardware Object],Default baudrate Config index,
    First baudrate index,No.of baudrate configuration,Associated kernel Id,
    Controller Hw Id, [No.of Rx Extended Hardware Objects],[FD support status] }
********************************************************************************
       Note: [1] The configuration shall be generated only for the activated
                 controller
             [2] The Generation of Extended message information is depends on
                 the CanIdType of Rx message configuration
*******************************************************************************/
static const Can_ControllerConfigType
                                Can_kControllerConfig[CAN_NOOF_CONTROLLER] =
{
  {
  /* MISRA2012_RULE_11_6_JUSTIFICATION: The pointer cast is used to
  cast the generated address with CAN Node structure type */
  /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and
  integer type. Permitted for special function registers.*/
  (volatile Ifx_CAN_N*)0xf0208100U,
  0x1U,
  {0x0U, 0x1U, 0x0U, 0x1U}, 0x0U, 0x0U, 0x1U, 0x0U, 0x00U 
  }
};
/*******************************************************************************
              Message RAM partition configuration
********************************************************************************
      {{start address of SID section,start address of XID section,
      start address of FIFO0 section,start address of FIFO1 section,start
      address of Rx dedicated buffer section,start address of Tx Event section,
      start address of Tx dedicated buffer section},Tx_ded_Buff size,
      Tx_Evnt size,[Rx_FIFO0 size],[Rx_FIFO0 Threshold],[Rx_FIFO1 size],
      [Rx_FIFO1 Threshold],[Tx_Queue size],[Tx_Queue Enable Status]}
********************************************************************************
           Note: This shall be generated only for the activated controller
*******************************************************************************/
static const Can_ControllerMsgRAMConfigType
                    Can_kControllerMsgRAMMapConfig[CAN_NOOF_CONTROLLER] =
{
  {
  /* Start Address of each section within the Message RAM */
  {
  0xf0200000UL,
  0x00000000UL,
  0x00000000UL,
  0x00000000UL,
  0xf0200004UL,
  0xf0200014UL,
  0xf020001cUL
  },
  0x1U, 0x1U }
};

/*******************************************************************************
                 CAN Controller Baudrate Configurations
********************************************************************************
           { CANx_NBTP value, Configured Baudrate ,FDBaudrate config Index ,
             FD Support Status  }
********************************************************************************
                           Baudrate Setting
    (uint32)((NSJW << 25)|(NBRP << 16)|(TSEG1 << 8)|(TSEG2))
    NSJW   -> CanControllerSyncJumpWidth - 1
    NTSEG1 -> CanControllerPropSeg + CanControllerSeg1 - 1
    NTSEG2 -> CanControllerSeg2 - 1
*******************************************************************************/
static const Can_ControllerBaudrateConfigType
                             Can_kBaudrateConfig[CAN_NOOF_BAUDRATE_CONFIG] =
{

  {
    /* Configured Baudrate -> 500 kbps */
    /* Actual Baudrate     -> 500.0 kbps */
    /* NBRP   -> 4 */
    /* NSJW   -> 0  */
    /* NTSEG1 -> 10  */
    /* NTSEG2 -> 3  */
    0x40a03U,
    500U  }
};

/*******************************************************************************
              CAN Controller Handling of Events : Interrupt/Polling
********************************************************************************
        { CanTxProcessing Mode, CanRxProcessing Mode,
          CanBusoffProcessing Mode, CanWakeupProcessing Mode }
********************************************************************************
           Note: If the CAN controller is not activated then,
                 { 0U, 0U, 0U, 0U } will be generated
*******************************************************************************/
/* CanConfigSet -> CAN Controller - Handling of Events */
static const Can_EventHandlingType
                              Can_kEventHandlingConfig[CAN_NOOF_CONTROLLER] =
{
 { { (CAN_POLLING),(CAN_POLLING),(CAN_POLLING),(CAN_POLLING)} }
};

/*******************************************************************************
               Receive Hardware Object Configurations
********************************************************************************
        This is the combination of SID filter elements
        Rx Object -> { Combination of Mask and filter value S0, HRH HwObject Id,
        Hw Controller Id, Rx BufferType, [Pretended Support Status] }
********************************************************************************
       Note: [1] If the associated CAN Controller is not activated then,
                   Hw Controller Id -> 255
             [2] If CanFilterMaskRef is not configured then,
                   Mask -> 0x7ff - for STANDARD Msg Id Type
*******************************************************************************/
static const Can_SIDFilterConfigType
                      Can_kSIDFilterConfig[CAN_NOOF_SID_FILTER_CONFIG] =
{
 {0xbff10000U, 0U, 0U, CAN_RX_DED_BUFFER }
};

/*******************************************************************************
               Transmit Hardware Object Configurations
********************************************************************************
 Tx Object -> { HTH HwObject Id, BufferIndex, HwControllerId, [FdPaddValue],
               Hardware ObjectType , Tx BufferType, TriggerTransmitStatus}
********************************************************************************
       Note: [1] If the associated CAN Controller is not activated then,
                   this shall not be generated.
*******************************************************************************/
static const Can_TxHwObjectConfigType
                        Can_kTxHwObjectConfig[CAN_NOOF_TX_HARDWARE_OBJECTS] =
{
 {1U, 0U, 0U, CAN_ID_STANDARD, CAN_TX_DED_BUFFER, CAN_FALSE}
};


/******************************************************************************/
                      /* CAN Configuration Pointer */
/******************************************************************************/
      /* Over all CAN configurations in the array, pointer to one of the
           configuration is passed as parameter to Can_Init API */
/******************************************************************************/

/* MISRA2012_RULE_8_7_JUSTIFICATION: Module configuration data structure
   declaration as per Autosar guidelines. This data structure may be needed
   by SW units using CAN Driver APIs */
/* MISRA2012_RULE_8_4_JUSTIFICATION: Definition is as per Autosar guidelines */
const Can_17_McmCan_ConfigType Can_17_McmCan_Config =
{
    /* Pointer to MCMCAN Kernel configuration */
    &Can_kMcmModuleConfig[0],
    /* Pointer to CAN controller configuration settings */
    &Can_kControllerConfig[0],
    /* Pointer to Message RAM configuration settings */
    &Can_kControllerMsgRAMMapConfig[0],
    /* Pointer to CAN Controller Handling of Events : Interrupt/Polling */
    &Can_kEventHandlingConfig[0],
    /* Pointer to Baudrate configuration settings */
    &Can_kBaudrateConfig[0],
    /* Pointer to CAN Controller <-> Tx Hardware Objects Mapping */
    &Can_kTxHwObjectConfig[0],
    /* Pointer to CAN Controller <-> Rx Hardware Objects Mapping for Standard
       messages */
    &Can_kSIDFilterConfig[0]};
#define CAN_17_MCMCAN_STOP_SEC_CONFIG_DATA_QM_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */
#include "Can_17_McmCan_MemMap.h"

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
