
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
**  FILENAME  : Fr_17_Eray_Cfg.h                                              **
**                                                                            **
**  VERSION   : 2.0.0                                                         **
**                                                                            **
**  DATE, TIME: 2017-12-06, 13:39:52                                      **
**                                                                            **
**  GENERATOR : Build b171004-0528                                          ** 
**                                                                            **
**  BSW MODULE DECRIPTION : Fr_17_Eray.bmd                                    **
**                                                                            **
**  VARIANT   : Variant PB                                                    **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Fr configuration generated out of ECUC file                **
**                                                                            **
**  SPECIFICATION(S) : Specification of FlexRay Driver, AUTOSAR Release 4.2.2 **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

/******************************************************************************/
#ifndef  FR_17_ERAY_CFG_H
#define  FR_17_ERAY_CFG_H



/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                     Configuration options                                **
*******************************************************************************/

/*
Flexray Controller Input Selection values are used to select alternate
receive input lines
*/
#define FR_RXSEL0  (0x00)
#define FR_RXSEL1  (0x01)
#define FR_RXSEL2  (0x02)
#define FR_RXSEL3  (0x03)

#define FR_LPDU_RECONFIGURABLE     (STD_ON)
#define FR_LPDU_NOT_RECONFIGURABLE (STD_OFF)

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/


/* Fr Instance ID */
#define FR_17_ERAY_INSTANCE_ID                ((uint8)0)

/* Autosar specification version */
#define FR_17_ERAY_AR_RELEASE_MAJOR_VERSION           (4U)
#define FR_17_ERAY_AR_RELEASE_MINOR_VERSION           (2U)
#define FR_17_ERAY_AR_RELEASE_REVISION_VERSION        (2U)

/* Vendor specific implementation version information */
#define FR_17_ERAY_SW_MAJOR_VERSION           (2U)
#define FR_17_ERAY_SW_MINOR_VERSION           (0U)
#define FR_17_ERAY_SW_PATCH_VERSION           (0U)

/*
Container : FrDriverConfiguration - ECUC_Fr_00392:
General configuration (parameters) of the FlexRay Driver module.
*/

/*
Configuration: FR_17_ERAY_PREPARE_LPDU 
Adds/removes the service Fr_17_Eray_PrepapreLPdu() from the code 
- if STD_ON, Fr_17_Eray_PrepapreLPdu() can be used
- if STD_OFF, Fr_17_Eray_PrepapreLPdu() can not be used
*/
#define FR_17_ERAY_PREPARE_LPDU                    (STD_ON)

/*
Configuration: FR_17_ERAY_RECONFIG_LPDU 
Adds/removes the service Fr_17_Eray_ReconfigLPdu() from the code 
- if STD_ON, Fr_17_Eray_ReconfigLPdu() can be used
- if STD_OFF, Fr_17_Eray_ReconfigLPdu() can not be used
*/

#define FR_17_ERAY_RECONFIG_LPDU                   (STD_ON)
/*
Configuration: FR_17_ERAY_DISABLE_LPDU 
Adds/removes the service Fr_17_Eray_DisableLPdu() from the code 
- if STD_ON, Fr_17_Eray_DisableLPdu() can be used
- if STD_OFF, Fr_17_Eray_DisableLPdu() can not be used
*/
#define FR_17_ERAY_DISABLE_LPDU                    (STD_OFF)
/*
Configuration: FR_17_ERAY_CTRL_TEST_COUNT
Specifies the maximum number of iterations the FlexRay controller hardware test
is performed during controller initialization. 
*/
#define FR_17_ERAY_CTRL_TEST_COUNT                   (0U)

/*
Configuration: FR_17_ERAY_DEV_ERROR_DETECT 
Preprocessor switch to enable/disable the development error detection and 
reporting.
- if STD_ON, Enable development error detection 
- if STD_OFF, Disable development error detection
*/
#define FR_17_ERAY_DEV_ERROR_DETECT                  (STD_OFF)

/*Configuration: FR_17_ERAY_INDEX  
Specifies the InstanceId of this module instance.*/
#define FR_17_ERAY_INDEX             (0U)

/*
Configuration: FR_17_ERAY_NUM_CTRL_SUPPORTED
Determines the maximum number of communication controllers that the driver 
supports. 
*/
#define FR_17_ERAY_NUM_CTRL_SUPPORTED               (1U)

/*
Configuration: FR_17_ERAY_RX_STRINGENT_CHECK
If stringent check is enabled (true), received frames are only accepted if no 
slot status error occured.
*/
#define FR_17_ERAY_RX_STRINGENT_CHECK                (STD_OFF)


/*
Configuration: FR_17_ERAY_RX_STRINGENT_LENGTH_CHECK
If stringent check is enabled (true), received frames are only accepted the 
received payload length matches the configured payload length. 
*/
#define FR_17_ERAY_RX_STRINGENT_LENGTH_CHECK         (STD_OFF)


/*
Configuration: FR_17_ERAY_VERSION_INFO_API
Adds/removes the service Fr_17_Eray_GetVersionInfo() from the code 
- if STD_ON, Fr_17_Eray_GetVersionInfo() can be used
- if STD_OFF, Fr_17_Eray_GetVersionInfo() can not be used
*/
#define FR_17_ERAY_VERSION_INFO_API                  (STD_OFF)

/*
Configuration: FR_17_ERAY_NMVECTOR_ENABLE
Adds/removes the service Fr_17_Eray_GetNmVector() from the code 
- if STD_ON, Fr_17_Eray_GetNmVector() can be used
- if STD_OFF, Fr_17_Eray_GetNmVector() can not be used
*/
#define FR_17_ERAY_NMVECTOR_ENABLE                   (STD_OFF)

/*
Configuration: FR_17_ERAY_TIMEOUT_DURATION
Specifies the maximum time in nanoseconds for blocking function until
a timeout is raised in short term wait loops.
*/
#define FR_17_ERAY_TIMEOUT_DURATION                  (400000U)

/* Dem reporting disabled macro */
#define DEM_REPORT_DISABLED (0U)
/*****************************************************************************/
/* Symbolic name definitions */
/*****************************************************************************/
/* 
    Symbolic name definitions for FR controllers and timers.
    The symbolic names identify the controller/timers (within an ECU). 
*/

/*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters 
to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
to follow Autosar naming conventions*/
#define Fr_17_ErayConf_FrController_ACSM5_A_FlexRay       (0U) 
/*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters 
to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
to follow Autosar naming conventions*/

#define Fr_17_ErayConf_FrAbsoluteTimer_FrAbsoluteTimer       (0U)




/*****************************************************************************/

/*******************************************************************************
**                      Derived Configuration Parameters                      **
*******************************************************************************/
/*
Configuration: FR_17_ERAY_CLEAR_RAMS_TIMEOUT
Specifies the timeout duration in nanoseconds until a timeout 
is raised after initialization of the E-Ray internal RAM blocks.
The initialization of the E-Ray internal RAM blocks requires minimum 
2048 fCLC_ERAY cycles. 5 percent margin(102 cycles) added to the value.
*/
#define FR_17_ERAY_CLEAR_RAMS_TIMEOUT                (21500U)

/* 
   Flag for FrIfAllowDynamicLSduLength usage.
   STD_ON: Header CRC is calculated in Fr_17_Eray_TransmitTxLPdu API.
   STD_OFF: Header CRC is calculated in code generation level with 
   configured FrIfLSduLength.
*/
#define FR_17_ERAY_MSG_ALLOW_DYNAMICLSDULENGTH          (STD_OFF)

/* Flag for FIFO configuration */
#define FR_17_ERAY_FIFO_CONFIGURED          (STD_OFF)

/* 
   Estimated maximum number of message buffers used per controller.
  Min (128, max(LPDU count in all PB configurations))
*/
#define FR_17_ERAY_MSG_BUFF_COUNT_MAX_0 (126U)
#define FR_17_ERAY_MSG_BUFF_COUNT_MAX_1 (0U)

/* Number of ERAY Controllers available in the device */
#define FR_NUM_CONTROLLERS_IN_DEVICE  (2U)
#define FR_17_ERAY_CONTROLLER0_CONFIGURED   (STD_ON)
#define FR_17_ERAY_CONTROLLER1_CONFIGURED   (STD_OFF)

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/


#endif /* FR_17_ERAY_CFG_H */
