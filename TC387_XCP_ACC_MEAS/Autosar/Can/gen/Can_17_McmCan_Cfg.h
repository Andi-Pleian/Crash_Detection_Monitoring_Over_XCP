
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
**  FILENAME  : Can_17_McmCan_Cfg.h                                           **
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

#ifndef CAN_17_MCMCAN_CFG_H
#define CAN_17_MCMCAN_CFG_H


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/*******************************************************************************
**                      Common Published Information                          **
*******************************************************************************/
#define CAN_17_MCMCAN_AR_RELEASE_MAJOR_VERSION          (4U)
#define CAN_17_MCMCAN_AR_RELEASE_MINOR_VERSION          (2U)
#define CAN_17_MCMCAN_AR_RELEASE_REVISION_VERSION       (2U)

#define CAN_17_MCMCAN_SW_MAJOR_VERSION                  (2U)
#define CAN_17_MCMCAN_SW_MINOR_VERSION                  (0U)
#define CAN_17_MCMCAN_SW_PATCH_VERSION                  (0U)
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* Maximum number of CAN Kernels configured in a ConfigSet */
#define CAN_NOOF_KERNEL                              (uint8)(1U)

/* Maximum number of CAN Controllers configured in a ConfigSet */
#define CAN_NOOF_CONTROLLER                          (uint8)(1U)

/* Number of baudrate Configuration sets */
#define CAN_NOOF_BAUDRATE_CONFIG                        (1U)

/* Maximum number of transmit hardware objects configured in a ConfigSet */
#define CAN_NOOF_TX_HARDWARE_OBJECTS                   (Can_HwHandleType) (1U)

/* Maximum number of transmit hardware objects configured in a ConfigSet */
#define CAN_NOOF_RX_HARDWARE_OBJECTS                   (Can_HwHandleType) (1U)

/* Maximum number of Icom configurations with in the ConfigSet */
#define CAN_NOOF_ICOM_CONFIGURATIONS                   (IcomConfigIdType) (0U)

/* Maximum number of Icom Message configurations with in the ConfigSet */
#define CAN_NOOF_ICOM_MSGCONFIGURATIONS                 (0U)

/* Maximum number of Icom Message configurations with in the ConfigSet */
#define CAN_NOOF_ICOM_SIGNALCONFIGURATIONS              (0U)

/* Configured Message Identifier Type */
/* CAN_ID_MIXED  : Standard and Extended Message Identifiers are configured */
/* CAN_ID_EXTENDED : Extended Message Identifier is only configured */
/* CAN_ID_STANDARD : Standard Message Identifier is only configured */
#define CAN_ID_CONFIG_TYPE                              (CAN_ID_MIXED)

/* Maximum number of Standard Id filter elements configured in a ConfigSet */
#define CAN_NOOF_SID_FILTER_CONFIG                              (1U)

/* Maximum number of Extended Id filter elements configured in a ConfigSet */
#define CAN_NOOF_XID_FILTER_CONFIG                              (0U)

/* Configuration: CAN_WAKEUP_CONFIGURED
 - STD_ON  - At least one of the CAN controllers supports wakeup
 - STD_OFF - None of the CAN controllers supports wakeup
*/
#define CAN_WAKEUP_CONFIGURED                           (STD_OFF)

/* Configuration: CAN_RX_PROCESS_ENABLED
 - STD_ON  - At least one of the HRH is configured
 - STD_OFF - None of the HRH is configured
*/
#define CAN_RX_PROCESS_ENABLED                          (STD_ON)

/* Configuration: CAN_TX_PROCESS_ENABLED
 - STD_ON  - At least one of the HTH is configured
 - STD_OFF - None of the HRH is configured
*/
#define CAN_TX_PROCESS_ENABLED                          (STD_ON)

/* Configuration: CAN_TRIGGER_TRANSMIT_SUPPORT
 - STD_ON  - Trigger Transmit support is enabled
 - STD_OFF - Trigger Transmit support is not enabled
*/
#define CAN_TRIGGER_TRANSMIT_SUPPORT                    (STD_OFF)

/*******************************************************************************
**                      CAN General Information                               **
*******************************************************************************/
/* Configuration: CAN_17_MCMCAN_INSTANCE_ID
 - Specifies the InstanceId of this module instance
*/
#define CAN_17_MCMCAN_INSTANCE_ID                       (0U)

/* Configuration: CAN_DEV_ERROR_DETECT
 - STD_ON  - DET is enabled
 - STD_OFF - DET is disabled
*/
#define CAN_DEV_ERROR_DETECT                            (STD_OFF)

/* Configuration: DEM event configuration
 - CAN_ENABLE_DEM_REPORT  - Dem event support is enabled
 - CAN_DISABLE_DEM_REPORT - Dem event support is disabled
*/
#define CAN_E_TIMEOUT_DEM_REPORT                    (CAN_DISABLE_DEM_REPORT)


/* Configuration: CAN_VERSION_INFO_API
 - STD_ON  - Can_17_McmCan_GetVersionInfo API is enabled
 - STD_OFF - Can_17_McmCan_GetVersionInfo API is disabled
*/
#define CAN_VERSION_INFO_API                            (STD_ON)

/* Configuration: CAN_LPDU_RX_CALLOUT
 - STD_ON  - L-PDU receive callout support enabled
 - STD_OFF - L-PDU receive callout support disabled
*/
#define CAN_LPDU_RX_CALLOUT                             (STD_OFF)

/* Configuration: CAN_MULTIPLEXED_TRANSMISSION
 - STD_ON  - Multiplexed transmission feature is enabled
 - STD_OFF - Multiplexed transmission feature is disabled
*/
#define CAN_MULTIPLEXED_TRANSMISSION                    (STD_OFF)

/* Configuration: CAN_TIMEOUT_DURATION
 - Specifies the maximum number of loops for blocking function until
   a time-out is raised in short term wait loops
*/
#define CAN_TIMEOUT_DURATION                            (10000000U)

/* Configuration: CAN_SET_BAUDRATE_API
 - STD_ON  - Can_17_McmCan_SetBaudrate API is enabled
 - STD_OFF - Can_17_McmCan_SetBaudrate API is Disabled
*/
#define CAN_SET_BAUDRATE_API                            (STD_ON)

/* Configuration: CanWakeupFunctionalityAPI
 - STD_ON  - Can_17_McmCan_CheckWakeup API is enabled
 - STD_OFF - Can_17_McmCan_CheckWakeup API is Disabled
*/
#define CAN_WU_API_SUPPORT                              (STD_OFF)

/* Configuration: CanControllerFdBaudrateConfig
 - STD_ON  - FD Operation is Enabled
 - STD_OFF - FD Operation is Disabled
*/
#define CAN_FD_ENABLE                                   (STD_OFF)

/* Configuration: CAN_DEINIT_API
 - STD_ON  - CAN De-initialization API is enabled
 - STD_OFF - CAN De-initialization API is not enabled
*/
#define CAN_DEINIT_API                                  (STD_ON)

/* Configuration: CAN_PUBLIC_ICOM_SUPPORT
 - STD_ON  - CAN Pretended networking is enabled
 - STD_OFF - CAN Pretended networking is not enabled
*/
#define CAN_PUBLIC_ICOM_SUPPORT                         (STD_OFF)

/******************************************************************************/
                    /* CAN Controller Configurations */
/******************************************************************************/
/* KERNEL0 Activation
 - STD_ON  - The controller associated with Kernel0 is used
 - STD_OFF - Not used any of the controller associated with Kernel0
*/
#define CAN_HWMCMKERNEL0_ACTIVATION                     (STD_ON)

/* KERNEL1 Activation
 - STD_ON  - The controller associated with Kernel1 is used
 - STD_OFF - Not used any of the controller associated with Kernel1
*/
#define CAN_HWMCMKERNEL1_ACTIVATION                     (STD_OFF)

/* KERNEL2 Activation
 - STD_ON  - The controller associated with Kernel2 is used
 - STD_OFF - Not used any of the controller associated with Kernel2
*/
#define CAN_HWMCMKERNEL2_ACTIVATION                     (STD_OFF)

/* KERNEL0 Configuration ID*/
#define CAN_HWMCMKERNEL0_ID                             (0U)

/* KERNEL1 Configuration ID*/
#define CAN_HWMCMKERNEL1_ID                             (255U)

/* KERNEL2 Configuration ID*/
#define CAN_HWMCMKERNEL2_ID                             (255U)

/* RxFIFO0 is used for Reception
 - STD_ON  - RXFIFO0 buffer is supported for data reception
 - STD_OFF - RXFIFO0 buffer is not configured for data reception
*/
#define CAN_RXFIFO0_ENABLED                             (STD_OFF)

/* RxFIFO1 is used for Reception
 - STD_ON  - RXFIFO0 buffer is supported for data reception
 - STD_OFF - RXFIFO1 buffer is not configured for data reception
*/
#define CAN_RXFIFO1_ENABLED                             (STD_OFF)

/*BusOff Processing Event used as Interrupt
 - STD_ON - BusOff event is notified through Interrupt mechanism by the
            configured controller
 - STD_OFF - BusOff event is notified through Interrupt mechanism by the
            configured controller
*/
#define CAN_BO_INTERRUPT_PROCESSING                     (STD_OFF)

/* Transmission Processing Event used as Interrupt
 - STD_ON - Transmission event is notified through Interrupt mechanism by the
            configured controller
 - STD_OFF - Transmission event is notified through Interrupt mechanism by the
            configured controller
*/
#define CAN_TX_INTERRUPT_PROCESSING                     (STD_OFF)

/* Reception Processing Event used as Interrupt
 - STD_ON - Reception event is notified through Interrupt mechanism by the
            configured controller
 - STD_OFF - Reception event is notified through Interrupt mechanism by the
            configured controller
*/
#define CAN_RX_INTERRUPT_PROCESSING                     (STD_OFF)

/*BusOff Processing Event used as POLLING
 - STD_ON - BusOff event is notified through Polling mechanism by the
            configured controller
 - STD_OFF - BusOff event is notified through Polling mechanism by the
            configured controller
*/
#define CAN_BO_POLLING_PROCESSING                       (STD_ON)

/* Transmission Processing Event used as POLLING
 - STD_ON - Transmission event is notified through Polling mechanism by the
            configured controller
 - STD_OFF - Transmission event is notified through Polling mechanism by the
            configured controller
*/
#define CAN_TX_POLLING_PROCESSING                       (STD_ON)

/* Reception Processing Event used as POLLING
 - STD_ON - Reception event is notified through Polling mechanism by the
            configured controller
 - STD_OFF - Reception event is notified through Polling mechanism by the
            configured controller
*/
#define CAN_RX_POLLING_PROCESSING                       (STD_ON)

/* WakeUp Processing Event used as POLLING
 - STD_ON - WakeUp event is notified through Polling mechanism by the
            configured controller
 - STD_OFF - WakeUp event is notified through Polling mechanism by the
            configured controller
*/
#define CAN_WU_POLLING_PROCESSING                       (STD_ON)

/* Multiple cyclic periods for Can_MainFunction_Write
 - STD_ON - Multiple periods are configured
 - STD_OFF - Not supported with multiple period configuration
*/
#define CAN_MULTIPLE_TX_PERIODS                         (STD_OFF)

/* Multiple cyclic periods for Can_MainFunction_Read
 - STD_ON - Multiple periods are configured
 - STD_OFF - Not supported with multiple period configuration
*/
#define CAN_MULTIPLE_RX_PERIODS                         (STD_OFF)

/* Controller Handle Id */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanController_contr_ACSM5_PS_CAN             0

/* Hardware object Handle Id */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_HOH_Rx0_contr_ACSM5_PS_CAN         0
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#define Can_17_McmCanConf_CanHardwareObject_HOH_Tx1_contr_ACSM5_PS_CAN         1
/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

#endif  /* CAN_17_MCMCAN_CFG_H */
