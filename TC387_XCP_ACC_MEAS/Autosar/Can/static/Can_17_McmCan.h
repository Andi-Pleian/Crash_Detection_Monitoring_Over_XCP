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
**  FILENAME     : Can_17_McmCan.h                                            **
**                                                                            **
**  VERSION      : 3.0.0                                                      **
**                                                                            **
**  DATE         : 2017-03-09                                                 **
**                                                                            **
**  VARIANT      : Variant PB                                                 **
**                                                                            **
**  PLATFORM     : Infineon AURIX2G                                           **
**                                                                            **
**  AUTHOR       : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**  VENDOR       : Infineon Technologies                                      **
**                                                                            **
**  DESCRIPTION  : CAN Driver header definition file                          **
**                                                                            **
**  SPECIFICATION(S) : Specification of CAN Driver, AUTOSAR Release 4.2.2     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

#ifndef CAN_17_MCMCAN_H
#define CAN_17_MCMCAN_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Register definition file for Aurix2G target */
#include "IfxCan_regdef.h"
#include "IfxCan_reg.h"

/* Include Communication Stack Types */
#include "ComStack_Types.h"

/* Include the declarations of Can functions and types */
#include "Can_17_McmCan_Cfg.h"

/* Includes all types and constants that are shared among the
   AUTOSAR CAN modules Can, CanIf and CanTrcv */
#include "Can_GeneralTypes.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/* Published parameters */

/* CAN Vendor ID - Vendor ID of the dedicated implementation of this
module according to the AUTOSAR vendor list */
#define CAN_17_MCMCAN_VENDOR_ID                  ((uint16)17)

/* CAN Module ID - Module ID of this module from Module List */
#define CAN_17_MCMCAN_MODULE_ID                  ((uint16)80)

#if(CAN_DEV_ERROR_DETECT == STD_ON)
/* API Service called with wrong parameter: Config is a null pointer */
#define CAN_E_PARAM_POINTER                      ((uint8)1)
/* API called with wrong parameter: Handle parameter is not a
   configured Hardware Transmit Handle */
#define CAN_E_PARAM_HANDLE                       ((uint8)2)
/* API called with wrong parameter : Parameter Data length is
  more than 8 bytes   */
#define CAN_E_PARAM_DLC                          ((uint8)3)
/* API called with wrong parameter : Parameter Controller is out of range  */
#define CAN_E_PARAM_CONTROLLER                   ((uint8)4)
/* API Service used without initialization */
#define CAN_E_UNINIT                             ((uint8)5)
/* Invalid invalid transition requested OR Invalid CAN controller state for
   API service call */
#define CAN_E_TRANSITION                         ((uint8)6)
/* DET for Over write error in receive ISR */
#define CAN_E_DATALOST                           ((uint8)7)
/* API called with invalid value of Can_IdType w.r.t. configured CanIdType */
/* i.e., Can_IdType with MSB 1 for STANDARD HTH  */
/*   or  Can_IdType with MSB 0 for EXTENDED HTH  */
#define CAN_E_PARAM_MSGID                        ((uint8)20)
/* API called with invalid / unsupported baudrate */
#define CAN_E_PARAM_BAUDRATE                     ((uint8)8)
/* Invalid size of Can_IdType */
#define CAN_E_CAN_IDTYPE                         ((uint8)21)
/* Invalid ICOM configuration Id */
#define CAN_E_ICOM_CONFIG_INVALID                ((uint8)9)
/* Invalid configuration set selection */
#define CAN_E_INIT_FAILED                        ((uint8)0x0a)
#endif /* #if(CAN_DEV_ERROR_DETECT == STD_ON) */

/* Service IDs. Used while reporting development errors */
#define CAN_SID_INIT                             ((uint8)0x00)
#define CAN_SID_MAINFUNCTION_WRITE               ((uint8)0x01)
#define CAN_SID_SETCONTROLLERMODE                ((uint8)0x03)
#define CAN_SID_DISABLECONTROLLERINTERRUPTS      ((uint8)0x04)
#define CAN_SID_ENABLECONTROLLERINTERRUPTS       ((uint8)0x05)
#define CAN_SID_WRITE                            ((uint8)0x06)
#define CAN_SID_GETVERSIONINFO                   ((uint8)0x07)
#define CAN_SID_MAINFUNCTION_READ                ((uint8)0x08)
#define CAN_SID_MAINFUNCTION_BUSOFF              ((uint8)0x09)
#define CAN_SID_MAINFUNCTION_WAKEUP              ((uint8)0x0a)
#define CAN_SID_CHECKWAKEUP                      ((uint8)0x0b)
#define CAN_SID_CHECK_BAUDRATE                   ((uint8)0x0e)
#define CAN_SID_DEINIT                           ((uint8)0x65)
#define CAN_SID_SET_BAUDRATE                     ((uint8)0x0f)
#define CAN_SID_SET_ICOM_CONFIGURATION           ((uint8)0x10)
#define CAN_SID_RECEIVEHANDLER                   ((uint8)0x12)


/* Diver used values */
#define CAN_FALSE                                 (boolean)0
#define CAN_TRUE                                  (boolean)1
#define CAN_POLLING                               (uint8)0
#define CAN_INTERRUPT                             (uint8)1
#define CAN_ONE                                   (uint8)1

/* Identifier types of an L-PDU */
#define CAN_ID_STANDARD                           (0x00)
#define CAN_ID_MIXED                              (0x01)
#define CAN_ID_EXTENDED                           (0x02)

/* Values used for FD mask and Extended Id Mask */
#if(CAN_ID_CONFIG_TYPE == CAN_ID_STANDARD)
#define CAN_STANDARD_ID_MASK                      (uint16)(0x07FF)
#define CAN_ID_FD_ENABLE_SET                      (uint16)(0x4000)
#define CAN_SET_FD_MASK                           (uint16)(0x4000)
#else
#define CAN_EXTENDED_ID_SET                       (uint32)(0x80000000U)
#define CAN_EXTENDED_ID_MASK                      (uint32)(0x1FFFFFFFU)
#define CAN_STANDARD_ID_MASK                      (uint32)(0x000007FFU)
#define CAN_ID_FD_ENABLE_SET                      (uint32)(0x40000000U)
/* Value used for set the FD status for upper-layer */
#define CAN_SET_FD_MASK                           (0x40000000U)
#endif


/* Values for DEM support status */
#define CAN_DISABLE_DEM_REPORT                    (0)
#define CAN_ENABLE_DEM_REPORT                     (1)

/* CCR.INIT bit status check mask value */
#define CAN_NODE_INIT_MODE                        (0x00000001U)
#define CAN_NODE_INIT_CCE_SET                     (uint32)(0x00000001)
#define CAN_CLC_DISABLE_STATUS                    (0x00000002U)
#define CAN_CCR_CSA_STATUS                        (0x00000008U)
#define CAN_MODULE_DISABLE_STATUS                 (0x00000002U)

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/* Data type used for Tx buffer Type */
typedef enum
{
  CAN_TX_DED_BUFFER = 0,
  CAN_TX_QUEUE = 1
} Can_TxBufferType;

/* Data type used for Rx buffer Type */
typedef enum
{
  CAN_RX_DED_BUFFER = 0,
  CAN_RX_FIFO0 = 1,
  CAN_RX_FIFO1 = 2
} Can_RxBufferType;

#if(CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
/* Data type used for Icom signal operator */
typedef enum
{
  CAN_ICOM_OPER_AND,
  CAN_ICOM_OPER_EQUAL,
  CAN_ICOM_OPER_GREATER,
  CAN_ICOM_OPER_SMALLER,
  CAN_ICOM_OPER_XOR
} Can_IcomSignalOperType;
#endif

#if (CAN_LPDU_RX_CALLOUT == STD_ON)
/* Type for Receive L-PDU call-out function */
typedef boolean (*Can_LPduRxCalloutFnPtrType)(uint8 Hrh,
                                              Can_IdType CanId,
                                              uint8 CanDlc,
                                              const uint8 *CanSduPtr);
#endif

/* CAN Kernel Configuration data type */
typedef struct
{
  /* The Global Base address of Kernel module */
  Ifx_CAN* CanBaseAddress;
  /* The information of used controller configuration */
  uint8 CanUsedHwCfgIndx [4];
  /* Total number of controllers used with in the Kernel */
  uint8 NoOfActiveNodes;
} Can_McmModuleConfigType;

/* CAN Controller corresponding Message RAM Partition Configuration data type */
typedef struct
{
  /* Start Address of Each Section with in the MEssage RAM */
  uint32 ControllerMsgRAMMap[7];
  /* No of used Tx dedicated buffer */
  uint8  TxDedBuffCount;
  /* TxEvent FIFO Size */
  uint8  TxEvntFIFOSize;
#if(CAN_RXFIFO0_ENABLED == STD_ON)
  /* RXFIFO0 Size */
  uint8  RxFIFO0Size;
  /* RXFIFO0 Water Mark Level */
  uint8  RxFIFO0Threshold;
#endif
#if(CAN_RXFIFO1_ENABLED == STD_ON)
  /* RXFIFO1 Size */
  uint8  RxFIFO1Size;
  /* RXFIFO1 Water Mark Level */
  uint8  RxFIFO1Threshold;
#endif
#if(CAN_MULTIPLEXED_TRANSMISSION == STD_ON)
  /* Tx Queue buffer Size */
  uint8  TxQueueSize;
  /* Tx Configuration support status */
  boolean TxQueueStatus;
#endif
} Can_ControllerMsgRAMConfigType;

/* CAN Controller Baudrate Configuration data type */
typedef struct
{
  /* Nominal Baudrate settings value */
  uint32 CanControllerBaudrate;
  /* Baudrate value configured in Kbps */
  uint16 CanBaudrateCfg;
#if(CAN_FD_ENABLE == STD_ON)
  /* Supporting FD Baudrate configuration index value */
  uint16 FDIndex;
  /* Status of FD configuration support */
  boolean FdConfigEnabled;
#endif
} Can_ControllerBaudrateConfigType;

#if(CAN_FD_ENABLE == STD_ON)
/* CAN Controller FDBaudrate Configuration data type */
typedef struct
{
  /* FD Baudrate settings value */
  uint32 CanControllerFDBaudrate;
  /* Transceiver Delay composition Register set value */
  uint32  TrcvDelyComp;
  /* BSR status value */
  boolean TxBRSEnable;
} Can_ControllerFDBaudrateConfigType;
#endif

#if (CAN_RX_PROCESS_ENABLED == STD_ON)
#if ((CAN_ID_CONFIG_TYPE == CAN_ID_STANDARD)||  \
                            (CAN_ID_CONFIG_TYPE == CAN_ID_MIXED))
/*
   Data type for CAN Receive Hardware object configuration - Standard
   Message filter.
 */
typedef struct
{
  /* Standard Filter mask value */
  uint32 SIDFilterElementS0;
  /* Hardware object Id */
  Can_HwHandleType HwObjId;
  /* configuration id of Controller to which this hardware object is assigned */
  uint8 HwControllerId;
  /* The filter settings for which type of Rx Buffer */
  Can_RxBufferType SIDBufferType;
#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
  /* The Normal message ID is supported for ICOM support or not */
  boolean SIDPretendedSupport;
#endif
} Can_SIDFilterConfigType;
#endif

#if ((CAN_ID_CONFIG_TYPE == CAN_ID_EXTENDED)||  \
                            (CAN_ID_CONFIG_TYPE == CAN_ID_MIXED))
/*
   Data type for CAN Receive Hardware object configuration - Extended
   Message filter.
 */
typedef struct
{
  /* Extended Filter mask value0 */
  uint32 XIDFilterElementF0;
  /* Extended Filter mask value1 */
  uint32 XIDFilterElementF1;
  /* Hardware object Id */
  Can_HwHandleType HwObjId;
  /* configuration id of Controller to which this hardware object is assigned */
  uint8  HwControllerId;
  /* The filter settings for which type of Rx Buffer */
  Can_RxBufferType XIDBufferType;
#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
  /* The Normal message ID is supported for ICOM support or not */
  boolean XIDPretendedSupport;
#endif
} Can_XIDFilterConfigType;
#endif
#endif

#if (CAN_TX_PROCESS_ENABLED == STD_ON)
/* Data type for CAN Transmit Hardware object configuration */
typedef struct
{
  /* Hardware object Id */
  Can_HwHandleType HwObjId;
  /* Tx Buffer index number */
  uint8 BuffIndx;
  /* configuration id of Controller to which this hardware object is assigned */
  uint8 HwControllerId;
#if(CAN_FD_ENABLE == STD_ON)
  /* The CAN FD padding Value */
  uint8 FdPaddValue;
#endif
  /* Hardware object CanIdType */
  uint8 HwObjIdType;
  /* The buffer types used by the Hardware handler */
  Can_TxBufferType TxBufferType;
  /* CAN Trigger transmit status */
  boolean TriggerTransmitStatus;
} Can_TxHwObjectConfigType;
#endif

/* CAN controller Events configuration type */
typedef struct
{
  uint8 CanEventType[4];
} Can_EventHandlingType;

#if (CAN_MULTIPLE_TX_PERIODS == STD_ON)
/* Multiple periods Transmit Hw object configuration data type */
typedef struct
{
  /* Tx buffer mask value for Tx completion status check*/
  uint32 TxBufferMaskvalue;
  /* Hardware object Id */
  Can_HwHandleType HwObjId;
  /* configuration id of Controller to which this hardware object is assigned */
  uint8 HwControllerId;
} Can_HthMaskObjectConfigType;

/* Multiple period Tx configuration index data type */
typedef struct
{
  /* Start Index of Hth associate with in the Period */
  uint8 StartIndx;
  /* No of Hth associated with in the Period */
  uint8 EndIndx;
} Can_PeriodHthMaskConfigType;
#endif

#if (CAN_MULTIPLE_RX_PERIODS == STD_ON)
/* Multiple periods Receive Hw object configuration data type */
typedef struct
{
  /* Rx buffer mask value for receive status check*/
  uint32 RxbufferMaskvalue;
  /* Hardware object Id */
  Can_HwHandleType HwObjId;
  /* configuration id of Controller to which this hardware object is assigned */
  uint8 HwControllerId;
  /* The Rx buffer Type used by Hrh */
  Can_RxBufferType BufferType;
} Can_HrhMaskObjectConfigType;

/* Multiple period Tx configuration index data type */
typedef struct
{
  /* Start Index of Hrh associate with in the Period */
  uint8 StartIndx;
  /* No of Hrh associated with in the Period */
  uint8 EndIndx;
} Can_PeriodHrhMaskConfigType;
#endif

#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
/* ICOM configuration data type */
typedef struct
{
  /* ICOM Message configuration start index */
  uint16 IcomFirstMsgIndx;
  /* No of ICOM Message configuration */
  uint16 IcomNoOfMsgIndx;
  /* Bus off is configured as wakeup source */
  boolean IcomWakeOnBusOff;
} Can_IcomConfigType;

/* ICOM message configuration data type */
typedef struct
{
  /* Icom Message ID */
  Can_IdType IcomMsgId;
  /* Icom Message Mask value */
  Can_IdType IcomMaskRef;
  /* Icom Message Counter value */
  uint16 IcomCntrVal;
  /* Icom Message DLC value */
  uint8  IcomDLC;
  /* Icom Message Signal configuration Index value */
  uint8  IcomFirstSignalIndx;
  /* No of Message Signal configuration */
  uint8  IcomNoOfSignalIndx;
  /* DLC error configured as wakeup source or not */
  boolean IcomLengthErr;
} Can_IcomRxMsgConfigType;

/*ICOM message signal configuration data type */
typedef struct
{
  /* Combination of Signal Mask value */
  uint8 IcomSignalMask[8];
  /* Combination of Signal value */
  uint8 IcomSignalValue[8];
  /* Operation selected for the Signal validation */
  Can_IcomSignalOperType IcomSignalOper;
} Can_IcomRxMsgSignalConfigType;
#endif

/* Data type for CAN Controller configuration */
typedef struct
{
  /* Can controller Base Node address */
  Ifx_CAN_N* CanNodeAddress;
#if(CAN_WAKEUP_CONFIGURED == STD_ON)
  /* Wakeup source Id */
  uint32 CanWakeupSourceId;
#endif
  /* combination of Loopback and receive input pin selection setting */
  uint32 CanNPCRValue;
  /* The controller Hw object configuration mapping information */
  uint16 ControllerMOMap[4];
#if (CAN_RX_PROCESS_ENABLED == STD_ON)
#if (CAN_ID_CONFIG_TYPE != CAN_ID_STANDARD)
  /* The start index value of Extended Id filter settings */
  uint16 XIDFilterPos;
#endif
#endif
  /* Default baudrate configuration Index */
  uint16 DefaultBaudrateCfgIndx;
  /* Start index value of Baudrate configuration */
  uint16 BaudrateCfgIndx;
  /* Total no of Baudrate configuration */
  uint16 NoOfBaudrateCfg;
  /* The controller Associated Kernel configuration Index */
  uint8  CanKernelHwId;
  /* The CAN controller Hw Index */
  uint8  CanControllerHwId;
#if (CAN_RX_PROCESS_ENABLED == STD_ON)
#if (CAN_ID_CONFIG_TYPE != CAN_ID_STANDARD)
  /* Total no of Receive Hw object:Extended Filter settings */
  uint8  XIDFilterNoOfConfig;
#endif
#endif
#if(CAN_FD_ENABLE == STD_ON)
  /* FD support status of the controller */
  boolean  FDSupport;
#endif
} Can_ControllerConfigType;

/* Type of CAN external data structure containing the overall
   initialization data for the CAN Driver and SFR settings affecting
   all controllers */
typedef struct
{
  /* Pointer to CAN Kernel configuration */
  const Can_McmModuleConfigType* CanMCMModuleConfigPtr;
  /* Pointer to CAN Controller configuration */
  const Can_ControllerConfigType* CanControllerConfigPtr;
  /* Pointer to CAN controller corresponding Message RAM Mapping
  configuration
  */
  const Can_ControllerMsgRAMConfigType* CanControllerMsgRAMMapConfigPtr;
  /* Pointer to CAN Controller Handling of Events : Interrupt/Polling */
  const Can_EventHandlingType* CanEventHandlingConfigPtr;
  /* Pointer to Controller Baudrate Configuration */
  const Can_ControllerBaudrateConfigType* CanBaudrateConfigPtr;
#if(CAN_FD_ENABLE == STD_ON)
  /* Pointer to Controller FDBaudrate Configuration */
  const Can_ControllerFDBaudrateConfigType* CanFDConfigParamPtr;
#endif
#if (CAN_LPDU_RX_CALLOUT == STD_ON)
  /* Pointer to Receive callout Function function pointer */
  const Can_LPduRxCalloutFnPtrType CanLPduRxCalloutFuncPtr;
#endif
#if (CAN_TX_PROCESS_ENABLED == STD_ON)
  /* Pointer to Configuration of transmit hardware objects */
  const Can_TxHwObjectConfigType* CanTxHwObjectConfigPtr;
#endif
#if (CAN_RX_PROCESS_ENABLED == STD_ON)
#if ((CAN_ID_CONFIG_TYPE == CAN_ID_STANDARD)||  \
                            (CAN_ID_CONFIG_TYPE == CAN_ID_MIXED))
  /* Pointer to Configuration of receive hardware objects ->Standard Messages */
  const Can_SIDFilterConfigType* CanSIDFilterConfigPtr;
#endif
#if ((CAN_ID_CONFIG_TYPE == CAN_ID_EXTENDED)||  \
                            (CAN_ID_CONFIG_TYPE == CAN_ID_MIXED))
  /* Pointer to Configuration of receive hardware objects ->Extended Messages */
  const Can_XIDFilterConfigType* CanXIDFilterConfigPtr;
#endif
#endif
#if (CAN_MULTIPLE_TX_PERIODS == STD_ON)
  /* Pointer to Configuration of Transmit hardware objects supported with
  multiple Periods */
  const Can_HthMaskObjectConfigType* CanHthMaskObjectConfigPtr;
  /* Pointer to Configuration of Tx hardware object with multiple periods */
  const Can_PeriodHthMaskConfigType* CanPeriodHthMaskConfigPtr;
#endif
#if (CAN_MULTIPLE_RX_PERIODS == STD_ON)
  /* Pointer to Configuration of Receive hardware objects supported with
  multiple Periods */
  const Can_HrhMaskObjectConfigType* CanHrhMaskObjectConfigPtr;
  /* Pointer to Configuration of Rx hardware object with multiple periods */
  const Can_PeriodHrhMaskConfigType* CanPeriodHrhMaskConfigPtr;
#endif
#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
  /* Pointer to the ICOM configurations set */
  const Can_IcomConfigType *CanIcomConfigPtr;
  /* Pointer to the ICOM Rx message configurations */
  const Can_IcomRxMsgConfigType *CanIcomMsgConfigPtr;
  /* Pointer to the ICOM Rx message signal configurations */
  const Can_IcomRxMsgSignalConfigType *CanIcomRxSignalConfigPtr;
#endif
} Can_17_McmCan_ConfigType;

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

#define CAN_17_MCMCAN_START_SEC_CODE_QM_GLOBAL
#include "Can_17_McmCan_MemMap.h"

/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : void Can_17_McmCan_Init                                 **
**                    (                                                       **
**                      const Can_17_McmCan_ConfigType* Config                **
**                    )                                                       **
**                                                                            **
** Description      : Driver Module Initialization function                   **
**                    * This function initializes:                            **
**                    * Static variables, including flags                     **
**                    * CAN HW Unit global hardware settings                  **
**                    * Controller specific settings for each CAN Controller  **
** All CAN Controllers will be in state CANIF_CS_STOPPED after initialization **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x00                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters(in)   : Config - Pointer to CAN driver configuration            **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
*******************************************************************************/
extern void Can_17_McmCan_Init
(
  const Can_17_McmCan_ConfigType* Config
);

#if (CAN_DEINIT_API == STD_ON)
/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : Std_ReturnType Can_17_McmCan_DeInit                     **
**                    (                                                       **
**                     void                                                   **
**                    )                                                       **
**                                                                            **
** Description      : This function for De-initializes the CAN Driver.        **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x65                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
*******************************************************************************/
extern void Can_17_McmCan_DeInit
(
  void
);
#else
#define Can_17_McmCan_DeInit() \
             (ERROR_Can_17_McmCan_DeInit_NOT_SELECTED)
#endif /* (CAN_DEINIT_API == STD_ON) */

/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : void Can_17_McmCan_GetVersionInfo                       **
**                    (                                                       **
**                      Std_VersionInfoType *versioninfo                      **
**                    )                                                       **
**                                                                            **
** Description      : - This function returns the version information of this **
**                      module.The version information include : Module ID,   **
**                      Vendor ID,Vendor specific version numbers             **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x07                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (out) : versioninfo - Pointer to store the                      **
**                    version information of this module.                     **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
*******************************************************************************/
#if( (CAN_VERSION_INFO_API == STD_ON) && (CAN_DEV_ERROR_DETECT == STD_ON ) )
/* MISRA2012_RULE_04_9_JUSTIFICATION: GetVersionInfo is declared as a function
  like macro as per AUTOSAR.*/
#define Can_17_McmCan_GetVersionInfo(versioninfo)                              \
{                                                                              \
  if ((versioninfo) == NULL_PTR)                                               \
  {                                                                            \
    Det_ReportError((uint16)CAN_17_MCMCAN_MODULE_ID,                           \
                    CAN_17_MCMCAN_INSTANCE_ID,                                 \
                    CAN_SID_GETVERSIONINFO,                                    \
                    CAN_E_PARAM_POINTER                                        \
                   );                                                          \
  }                                                                            \
  else                                                                         \
  {                                                                            \
    ((Std_VersionInfoType*)(versioninfo))->moduleID = CAN_17_MCMCAN_MODULE_ID; \
    ((Std_VersionInfoType*)(versioninfo))->vendorID = CAN_17_MCMCAN_VENDOR_ID; \
    ((Std_VersionInfoType*)(versioninfo))->sw_major_version =                  \
                                        (uint8)CAN_17_MCMCAN_SW_MAJOR_VERSION; \
    ((Std_VersionInfoType*)(versioninfo))->sw_minor_version =                  \
                                        (uint8)CAN_17_MCMCAN_SW_MINOR_VERSION; \
    ((Std_VersionInfoType*)(versioninfo))->sw_patch_version =                  \
                                        (uint8)CAN_17_MCMCAN_SW_PATCH_VERSION; \
  }                                                                            \
}
#elif( (CAN_VERSION_INFO_API == STD_ON) && (CAN_DEV_ERROR_DETECT == STD_OFF) )
/* MISRA2012_RULE_04_9_JUSTIFICATION: GetVersionInfo is declared as a function
  like macro as per AUTOSAR.*/
#define Can_17_McmCan_GetVersionInfo(versioninfo)                              \
{                                                                              \
                                                                               \
  ((Std_VersionInfoType*)(versioninfo))->moduleID = CAN_17_MCMCAN_MODULE_ID;   \
  ((Std_VersionInfoType*)(versioninfo))->vendorID = CAN_17_MCMCAN_VENDOR_ID;   \
  ((Std_VersionInfoType*)(versioninfo))->sw_major_version =                    \
                                      (uint8)CAN_17_MCMCAN_SW_MAJOR_VERSION;   \
  ((Std_VersionInfoType*)(versioninfo))->sw_minor_version =                    \
                                      (uint8)CAN_17_MCMCAN_SW_MINOR_VERSION;   \
  ((Std_VersionInfoType*)(versioninfo))->sw_patch_version =                    \
                                      (uint8)CAN_17_MCMCAN_SW_PATCH_VERSION;   \
}
#else
/* MISRA2012_RULE_04_9_JUSTIFICATION: Function like macro used to generate
  compile time error in case of incorrect configuration*/
#define Can_17_McmCan_GetVersionInfo(versioninfo)                              \
                             (ERROR_Can_17_McmCan_GetVersionInfo_NOT_SELECTED)
#endif /* End for CAN_VERSION_INFO_API */


#if (CAN_SET_BAUDRATE_API == STD_ON)
/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : Std_ReturnType Can_17_McmCan_CheckBaudrate              **
**                    (                                                       **
**                      uint8 Controller,                                     **
**                      const uint16 Baudrate                                 **
**                    )                                                       **
**                                                                            **
** Description      : Checks CAN Controller Baudrate                          **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x0e                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Controller - Associated CAN Controller                  **
**                    Baudrate -  Baudrate to be checked                      **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : E_OK/E_NOT_OK                                           **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Can_17_McmCan_CheckBaudrate
(
  uint8 Controller,uint16 Baudrate
);

/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : Std_ReturnType Can_17_McmCan_SetBaudrate                **
**                    (                                                       **
**                     uint8 Controller,                                      **
**                     uint16 BaudRateConfigID                                **
**                    )                                                       **
**                                                                            **
** Description      : This service shall set the baud rate configuration of   **
**                    the CAN controller.                                     **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x0f                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Controller - Associated CAN Controller                  **
**                    BaudRateConfigID - References a baud rate configuration **
**                    by ID                                                   **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : E_OK/E_NOT_OK                                           **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Can_17_McmCan_SetBaudrate
(
  uint8 Controller,
  uint16 BaudRateConfigID
);
#else
/* MISRA2012_RULE_04_9_JUSTIFICATION: Function like macro used to generate
 compile time error in case of incorrect configuration*/
#define Can_17_McmCan_CheckBaudrate(Controller,Baudrate) \
             (ERROR_Can_17_McmCan_CheckBaudrate_NOT_SELECTED)

/* MISRA2012_RULE_04_9_JUSTIFICATION: Function like macro used to generate
 compile time error in case of incorrect configuration*/
#define Can_17_McmCan_SetBaudrate(Controller,BaudRateConfigID) \
             (ERROR_Can_17_McmCan_SetBaudrate_NOT_SELECTED)

#endif /* #if (CAN_SET_BAUDRATE_API == STD_ON) */

/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : Can_ReturnType Can_17_McmCan_SetControllerMode          **
**                    (                                                       **
**                      uint8 Controller,                                     **
**                      Can_StateTransitionType Transition                    **
**                    )                                                       **
**                                                                            **
** Description      : Performs software triggered state transitions of the    **
**                    CAN Controller State machine                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x03                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : Controller - Associated CAN Controller                  **
**                    Transition - Requested transition                       **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : CAN_OK/CAN_NOT_OK                                       **
**                                                                            **
*******************************************************************************/
extern Can_ReturnType Can_17_McmCan_SetControllerMode
(
  uint8 Controller,
  Can_StateTransitionType Transition
);

/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : void Can_17_McmCan_DisableControllerInterrupts          **
**                    (                                                       **
**                      uint8 Controller,                                     **
**                    )                                                       **
**                                                                            **
** Description      : Disables CAN Controller all Interrupts                  **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x04                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Controller - Associated CAN Controller                  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
*******************************************************************************/
extern void Can_17_McmCan_DisableControllerInterrupts
(
  uint8 Controller
);

/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : void Can_17_McmCan_EnableControllerInterrupts           **
**                    (                                                       **
**                      uint8 Controller,                                     **
**                    )                                                       **
**                                                                            **
** Description      : Enable CAN Controller all Interrupts                    **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x05                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Controller - Associated CAN Controller                  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
*******************************************************************************/
extern void Can_17_McmCan_EnableControllerInterrupts
(
  uint8 Controller
);

/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : Can_ReturnType Can_17_McmCan_Write                      **
**                    (                                                       **
**                      Can_HwHandleType Hth,                                 **
**                      const Can_PduType *PduInfo                            **
**                    )                                                       **
**                                                                            **
** Description      : Service to transmit CAN frame                           **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x06                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant(thread-safe)                                  **
**                                                                            **
** Parameters (in)  : Hth - Hardware Transmit Handler                         **
**                    PduInfo - Pointer to SDU user memory, DLC and           **
**                                                            Identifier      **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : CAN_OK/CAN_BUSY/CAN_NOT_OK                              **
**                                                                            **
*******************************************************************************/
extern Can_ReturnType Can_17_McmCan_Write
(
  Can_HwHandleType Hth,
  const Can_PduType* PduInfo
);

/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : void Can_17_McmCan_MainFunction_Write                   **
**                    (                                                       **
**                      void                                                  **
**                    )                                                       **
**                                                                            **
** Description      : This function performs the polling of TX confirmation   **
**                    when CAN_TX_PROCESSING is set to POLLING                **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x01                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
*******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
extern void Can_17_McmCan_MainFunction_Write(void);

/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : void Can_17_McmCan_MainFunction_Read                    **
**                    (                                                       **
**                      void                                                  **
**                    )                                                       **
**                                                                            **
** Description      : This function performs the polling of RX indication     **
**                    when CAN_RX_PROCESSING is set to POLLING                **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x08                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
*******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
extern void Can_17_McmCan_MainFunction_Read(void);

/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : void Can_17_McmCan_MainFunction_BusOff                  **
**                    (                                                       **
**                      void                                                  **
**                    )                                                       **
**                                                                            **
** Description      : This function performs the polling of bus-off events    **
**                    that are configured statically as 'to be polled'        **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x09                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
*******************************************************************************/
extern void Can_17_McmCan_MainFunction_BusOff
(
  void
);

/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : void Can_17_McmCan_MainFunction_Wakeup                  **
**                    (                                                       **
**                      void                                                  **
**                    )                                                       **
**                                                                            **
** Description      : This function performs the polling of wake-up events    **
**                    that are configured statically as 'to be polled'        **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x0A                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
*******************************************************************************/
extern void Can_17_McmCan_MainFunction_Wakeup
(
  void
);

/*******************************************************************************
** Syntax           : void Can_17_McmCan_MainFunction_Mode                    **
**                    (                                                       **
**                      void                                                  **
**                    )                                                       **
**                                                                            **
** Description      : This function performs the polling of CAN Controller    **
**                    mode transitions                                        **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x0C                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
*******************************************************************************/
extern void Can_17_McmCan_MainFunction_Mode
(
  void
);

#if (CAN_WU_API_SUPPORT == STD_ON)
/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : Can_ReturnType Can_17_McmCan_CheckWakeup                **
**                   (                                                        **
**                     uint8 Controller                                       **
**                   )                                                        **
**                                                                            **
** Description      : This function checks if a wakeup has occurred for the   **
**                    given CAN Controller                                    **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x0B                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : Controller - Associated CAN Controller                  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : CAN_OK/CAN_NOT_OK                                       **
**                                                                            **
*******************************************************************************/
extern Can_ReturnType Can_17_McmCan_CheckWakeup
(
  uint8 Controller
);
#else
/* MISRA2012_RULE_04_9_JUSTIFICATION: Function like macro used to generate
 compile time error in case of incorrect configuration*/
#define Can_17_McmCan_CheckWakeup(Controller) \
             (ERROR_Can_17_McmCan_CheckWakeup_NOT_SELECTED)

#endif /* #if (CAN_WU_API_SUPPORT == STD_ON) */

#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : Std_ReturnType Can_17_McmCan_SetIcomConfiguration       **
**                   (                                                        **
**                     uint8 Controller,                                      **
**                     IcomConfigIdType ConfigurationId                       **
**                   )                                                        **
**                                                                            **
** Description      : This service shall change the Icom Configuration of a   **
**                    CAN controller to the requested one.                    **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x11                                                    **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : Controller - Associated CAN Controller                  **
**                    ConfigurationId  - Requested Configuration              **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : E_OK/E_NOT_OK                                           **
**                                                                            **
*******************************************************************************/
extern Std_ReturnType Can_17_McmCan_SetIcomConfiguration
(
  uint8 Controller,
  IcomConfigIdType ConfigurationId
);
#else
/* MISRA2012_RULE_04_9_JUSTIFICATION: Function like macro used to generate
 compile time error in case of incorrect configuration*/
#define Can_17_McmCan_SetIcomConfiguration(Controller ,ConfigurationId) \
             (ERROR_Can_17_McmCan_SetIcomConfiguration_NOT_SELECTED)
#endif  /*(CAN_PUBLIC_ICOM_SUPPORT == STD_ON)*/

/*******************************************************************************
**                      Interrupt Service Routines                            **
*******************************************************************************/

#if(CAN_BO_INTERRUPT_PROCESSING == STD_ON)
/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : void Can_17_McmCan_IsrBusOffHandler                     **
**                    (                                                       **
**                      uint8 KernelIdIndx                                    **
**                    )                                                       **
**                                                                            **
** Description      : - This is the interrupt service routine for BusOff      **
**                    handling                                                **
**                    This function will checks any of the CAN Controller     **
**                    associated with Can Module is on BusOff state then      **
**                    calls handler function with controller information      **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : HwKernelId - Requested with associated kernelId         **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
*******************************************************************************/
extern void Can_17_McmCan_IsrBusOffHandler
(
  uint8 HwKernelId
);
#endif

#if(CAN_RX_INTERRUPT_PROCESSING == STD_ON)
/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : void Can_17_McmCan_IsrReceiveHandler                    **
**                    (                                                       **
**                      uint8 KernelIdIndx                                    **
**                    )                                                       **
**                                                                            **
** Description      : - This is the interrupt service routine for handling    **
**                      Interrupt of dedicated Rx buffer.                     **
**                      This function checks the CAN Controller is received   **
**                      any messages via Rx dedicated buffer if yes then      **
**                      calls receive handler function                        **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : HwKernelId - Requested with associated kernelId         **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
*******************************************************************************/
extern void Can_17_McmCan_IsrReceiveHandler
(
  uint8 HwKernelId
);
#endif

#if(CAN_TX_INTERRUPT_PROCESSING == STD_ON)
/*******************************************************************************
** Syntax           : void Can_17_McmCan_IsrTransmitHandler                   **
**                                                     (uint8 HwKernelId)     **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : HwKernelId - Associated CAN Controller kernel Id        **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : - This is the interrupt service routine for Transmit    **
**                    Interrupt                                               **
**                    - In case of successful transmission event, this        **
**                    function notifies the upper layer                       **
**                                                                            **
*******************************************************************************/
extern void Can_17_McmCan_IsrTransmitHandler
(
  uint8 HwKernelId
);
#endif

#if(CAN_RX_INTERRUPT_PROCESSING == STD_ON)
#if((CAN_RXFIFO0_ENABLED == STD_ON) || (CAN_RXFIFO1_ENABLED == STD_ON))
/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : void Can_17_MCMCAN_IsrRxFIFO0Handler                    **
**                    (                                                       **
**                      uint8 KernelIdIndx                                    **
**                    )                                                       **
**                                                                            **
** Description      : This is the interrupt service routine for checking      **
**                    Received messaged via RXFIFO                            **
**                    This function shall checks the CAN Controller FIFO      **
**                    status calls appropriate handler function               **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : HwKernelId - Requested with associated kernelId         **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
*******************************************************************************/
extern void Can_17_McmCan_IsrRxFIFOHandler
(
  uint8 HwKernelId
);
#endif
#endif

#if (CAN_MULTIPLE_RX_PERIODS == STD_ON)
/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : void Can_lRxPeriodHandler                               **
**                    (                                                       **
**                      uint8 HrhRefPeriods                                   **
**                    )                                                       **
**                                                                            **
** Description      : The internal fucntion is used for checking the receive  **
**                    handler is received with new data or not                **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : HrhRefPeriods - Requested with Cyclic time period index **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
*******************************************************************************/
/* Function to handle multiple period receive Hw objects */
extern void Can_lRxPeriodHandler
(
 uint8 HrhRefPeriods
);
#endif

#if (CAN_MULTIPLE_TX_PERIODS == STD_ON)
/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : void Can_lTxPeriodHandler                               **
**                    (                                                       **
**                      uint8 HthRefPeriods                                   **
**                    )                                                       **
**                                                                            **
** Description      : The internal fucntion is used for checking the transmit **
**                    handler is status as completed or not                   **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : HthRefPeriods - Requested with Cyclic time period index **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
*******************************************************************************/
/* Function for Handling multiple period Transmit Hw object */
extern void Can_lTxPeriodHandler
(
uint8 HthRefPeriods
);
#endif

#define CAN_17_MCMCAN_STOP_SEC_CODE_QM_GLOBAL
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */
#include "Can_17_McmCan_MemMap.h"
#endif  /* Header inclusion End */