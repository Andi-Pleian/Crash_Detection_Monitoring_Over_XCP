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
**  FILENAME     : Can_17_McmCan.c                                            **
**                                                                            **
**  VERSION      : 3.0.1                                                      **
**                                                                            **
**  DATE         : 2017-03-14                                                 **
**                                                                            **
**  VARIANT      : Variant PB                                                 **
**                                                                            **
**  PLATFORM     : Infineon AURIX2G                                           **
**                                                                            **
**  AUTHOR       : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**  VENDOR       : Infineon Technologies                                      **
**                                                                            **
**  DESCRIPTION  : CAN Driver source file                                     **
**                                                                            **
**  SPECIFICATION(S) : Specification of CAN Driver, AUTOSAR Release 4.2.2     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Register definition file for Aurix2G target */
#include "IfxCan_regdef.h"
#include "IfxCan_reg.h"
#include "IfxSrc_reg.h"

/* MCAL header file containing global macros, type definitions and functions
needed by all MCAL drivers */
#include "McalLib.h"

/* Include the declarations of Can functions and types */
#include "Can_17_McmCan.h"

/* Include the declarations of Can functions and types */
#include "SchM_Can_17_McmCan.h"

/* Include the declarations of CanIf callback functions and types */
#include "CanIf_Cbk.h"

/* Include the declarations of EcuM callback functions and types */
#if (CAN_WAKEUP_CONFIGURED == STD_ON)
#include "EcuM_Cbk.h"
#endif

/* Include default error detection header file if DET is Enabled */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

/* Include the declarations of Dem callback functions and types */
#if (CAN_E_TIMEOUT_DEM_REPORT == CAN_ENABLE_DEM_REPORT)
#include "Dem.h"
#endif

/*******************************************************************************
**                      Version check                                         **
*******************************************************************************/

/* Check if the correct version of Can_17_McmCan.h is included */

#ifndef CAN_17_MCMCAN_AR_RELEASE_MAJOR_VERSION
#error "CAN_17_MCMCAN_AR_RELEASE_MAJOR_VERSION is not defined. "
#endif

#ifndef CAN_17_MCMCAN_AR_RELEASE_MINOR_VERSION
#error "CAN_17_MCMCAN_AR_RELEASE_MINOR_VERSION is not defined. "
#endif

#ifndef CAN_17_MCMCAN_AR_RELEASE_REVISION_VERSION
#error "CAN_17_MCMCAN_AR_RELEASE_REVISION_VERSION is not defined. "
#endif

#if ( CAN_17_MCMCAN_AR_RELEASE_MAJOR_VERSION != 4U )
#error "CAN_17_MCMCAN_AR_RELEASE_MAJOR_VERSION does not match. "
#endif

#if ( CAN_17_MCMCAN_AR_RELEASE_MINOR_VERSION != 2U )
#error "CAN_17_MCMCAN_AR_RELEASE_MINOR_VERSION does not match. "
#endif

/* Check for definition of SW version Information */
#ifndef CAN_17_MCMCAN_SW_MAJOR_VERSION
#error "CAN_17_MCMCAN_SW_MAJOR_VERSION is not defined. "
#endif

#ifndef CAN_17_MCMCAN_SW_MINOR_VERSION
#error "CAN_17_MCMCAN_SW_MINOR_VERSION is not defined. "
#endif

#ifndef CAN_17_MCMCAN_SW_PATCH_VERSION
#error "CAN_17_MCMCAN_SW_PATCH_VERSION is not defined. "
#endif

/* Check for Correct inclusion of headers */
#if ( CAN_17_MCMCAN_SW_MAJOR_VERSION != 2U )
#error "CAN_17_MCMCAN_SW_MAJOR_VERSION does not match. "
#endif
#if ( CAN_17_MCMCAN_SW_MINOR_VERSION != 0U )
#error "CAN_17_MCMCAN_SW_MINOR_VERSION does not match. "
#endif

/* Inter Module Check */

/* Check for the correct version usage in the used modules */

/* Det AUTOSAR Version Info Check */
#if ( CAN_DEV_ERROR_DETECT == STD_ON)
#ifndef DET_AR_RELEASE_MAJOR_VERSION
#error "DET_AR_RELEASE_MAJOR_VERSION is not defined. "
#endif

#ifndef DET_AR_RELEASE_MINOR_VERSION
#error "DET_AR_RELEASE_MINOR_VERSION is not defined. "
#endif

#if ( DET_AR_RELEASE_MAJOR_VERSION != CAN_17_MCMCAN_AR_RELEASE_MAJOR_VERSION )
#error "DET_AR_RELEASE_MAJOR_VERSION does not match. "
#endif
#if ( DET_AR_RELEASE_MINOR_VERSION != CAN_17_MCMCAN_AR_RELEASE_MINOR_VERSION )
#error "DET_AR_RELEASE_MINOR_VERSION does not match. "
#endif
#endif /* #if ( CAN_DEV_ERROR_DETECT == STD_ON) */

/* Dem AUTOSAR Version Info Check */
#if (CAN_E_TIMEOUT_DEM_REPORT == CAN_ENABLE_DEM_REPORT)
#ifndef DEM_AR_RELEASE_MAJOR_VERSION
#error "DEM_AR_RELEASE_MAJOR_VERSION is not defined. "
#endif

#ifndef DEM_AR_RELEASE_MINOR_VERSION
#error "DEM_AR_RELEASE_MINOR_VERSION is not defined. "
#endif

#if ( DEM_AR_RELEASE_MAJOR_VERSION != CAN_17_MCMCAN_AR_RELEASE_MAJOR_VERSION )
#error "DEM_AR_RELEASE_MAJOR_VERSION does not match. "
#endif
#if ( DEM_AR_RELEASE_MINOR_VERSION != CAN_17_MCMCAN_AR_RELEASE_MINOR_VERSION )
#error "DEM_AR_RELEASE_MINOR_VERSION does not match. "
#endif
#endif /* #if (CAN_E_TIMEOUT_DEM_REPORT == CAN_ENABLE_DEM_REPORT) */

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/* Values used by the CAN driver */
#define CAN_ZERO                                  (uint8)0
#define CAN_TWO                                   (uint8)2
#define CAN_THREE                                 (uint8)3
#define CAN_FOUR                                  (uint8)4
#define CAN_FIVE                                  (uint8)5
#define CAN_SIX                                   (uint8)6
#define CAN_EIGHT                                 (uint8)8
#define CAN_HUNDRED                               (uint8)100

#if ((CAN_PUBLIC_ICOM_SUPPORT == STD_ON) || \
     (CAN_FD_ENABLE == STD_ON))
#define CAN_SEVEN                                 (uint8)7
#endif

#if((CAN_RXFIFO1_ENABLED == STD_ON) || (CAN_FD_ENABLE == STD_ON))
#define CAN_SIXTEEN                               (uint8)16
#endif

#if (CAN_FD_ENABLE == STD_ON)
#define CAN_ELEVEN                                (uint8)11
#define CAN_FIFTEEN                               (uint8)15
/* Value used for Max FD length operation */
#define CAN_MAX_FD_LENGTH                         (uint8)64
/* Shift operation values used by the CAN driver */
#define CAN_SHIFT_TWENTYFOUR                      (uint8)24
/* Message RAM element size with FD support */
#define CAN_MSG_RAM_ELEMENT_SIZE_FD               (uint32)72
#endif

/* RAM BYTE size */
#define CAN_RAM_BYTES                             (uint32)4

/* Shift operation values used by the CAN driver */
#define CAN_SHIFT_EIGHTEEN                        (uint8)18

/* Normal DLC length */
#define CAN_MAX_DATA_LENGTH                       (uint8) (8)

/* Values for clear and Register data check */
#define CAN_DATA_ZERO                             (Ifx_UReg_32Bit) (0x00000000U)

/* Value for Address Check */
#define CAN_ADDRESS_CHECK                         (uint32) (0x00000000U)

#if(CAN_WAKEUP_CONFIGURED == STD_ON)
/*Value for  Check Wakeup is enabled */
#define CAN_CHECK_WAKEUP                           (uint32) (0x00000000U)
#endif

/* Values for clear IR register */
#define CAN_CLEAR_ALL_INTERRUPTS                  (uint32)(0x3FCFFFFFU)

/* Values for Set Global register for reject RTR and Non Match Frames */
#define CAN_GFC_REJT_RTR_NONMATCH                 (uint32)(0x0000003FU)

/* Value for clear new data register */
#define CAN_CLEAR_NEWDATA_REG                     (uint32)(0xFFFFFFFFU)

/* Value for MASK the Message RAM Offset address */
#define CAN_RAM_ADDRESS_OFFSET_MASK               (uint32) (0x0000FFFC)

/* value for Tx buffer Index */
#define CAN_TX_BUFF_MASK                          (uint32)(0x00000001U)

/* Set for identify the MsgID is extended */
#define CAN_SET_XTD_BIT_MASK                      (0x80000000U)

/* used for Mask value for identify the INIT */
#define CAN_CCCR_INIT_SET_MASK                    (uint32)(0x00000001U)

/* Value used for the CLK selection */
#define CAN_MCR_CLKSEL_SET                        (Ifx_UReg_32Bit)(0x00000003U)

/* Value used for enable the CLK configuration change */
#define CAN_CLKSEL_WRITE_ENABLE                   (0xC0000000U)

/* Value used for NDAT2 Register buffer Position access */
#define CAN_THIRTY_TWO                            (uint8)32

/* Value used for check bit is set or not */
#define CAN_BIT_CLEAR_VAL                         (Ifx_UReg_32Bit)0

/* Bit Set Value */
#define CAN_BIT_SET_VAL                           (Ifx_UReg_32Bit)1

#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
/* Message Id Mask Value */
#define CAN_MSG_MASK_VAL                          (Can_IdType)0
#endif

/* Message Id Mask Value */
#define CAN_MSG_MARKER_MASK_VAL                   (0xFFFFU)

/* Message RAM element size with FD support */
#define CAN_MSG_RAM_ELEMENT_SIZE_NFD              (uint32)16

/* Clear DRX (dedicated buffer) flag in IR register */
#define CAN_CLEAR_IE_DRX_BIT                      (uint32) (0x00080000U)

/* Clear TEFN (Tx Event FIFO New Entry) flag in IR register */
#define CAN_CLEAR_IE_TEFN_BIT                     (uint32) (0x00001000U)

/* Clear BO (Bus_Off Status) flag in IR register */
#define CAN_CLEAR_IE_BO_BIT                       (uint32) (0x02000000U)

#if(CAN_RXFIFO1_ENABLED == STD_ON)
/* Clear RF1W (Rx FIFO 1 Watermark Reached) flag in IR register */
#define CAN_CLEAR_IE_RF1W_BIT                     (uint32) (0x00000020U)
#endif

#if(CAN_RXFIFO0_ENABLED == STD_ON)
/* Clear RF1W (Rx FIFO 0 Watermark Reached) flag in IR register */
#define CAN_CLEAR_IE_RF0W_BIT                     (uint32) (0x00000002U)
#endif

/*CAN Node's hardware communication state */
#define CAN_PSR_IDLE                              (uint32) (0x01)

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/* Data type used for Driver global status */
typedef enum
{
  CAN_UNINIT = 0,
  CAN_READY = 1
} Can_17_McmCan_DriverStateType;

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#define CAN_17_MCMCAN_START_SEC_CODE_QM_GLOBAL
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
    without safegaurd. It complies to Autosar guidelines. */
#include "Can_17_McmCan_MemMap.h"

/* Function to initialize CAN Module used global variables */
LOCAL_INLINE void Can_lInitGlobalVar(void);

/* Function to initialize CAN Module clock/timing registers */
LOCAL_INLINE Std_ReturnType Can_lInitClkSetting(uint8 KernelIndx);

/* Function to initialize CAN Module Node registers */
LOCAL_INLINE Std_ReturnType Can_lInitializeController(uint8 ControllerId);

#if (CAN_TX_PROCESS_ENABLED == STD_ON)
/* Function to initialize Tx Hw message objects */
LOCAL_INLINE void Can_lInitTxMsgObj(uint8 Controller);

/* Function to cancel the pending Tx request */
LOCAL_INLINE void Can_lCancelPendingTx (uint8 ControllerId);

/* Internal function for Handling Tx write operation */
static Can_ReturnType Can_lWriteMsgObj( Can_HwHandleType HthIndex,
                                         const Can_PduType *PduInfo);

/* Function for handling Tx confirmation operation */
static void Can_lTxEventHandler (uint8 HwControllerId);

/* Function for Write request validation */
static Std_ReturnType Can_lWriteDetCheck(Can_HwHandleType Hth,const
                                          Can_PduType *PduInfo);
#endif

#if (CAN_SET_BAUDRATE_API == STD_ON)
/* Function to set the nominal baudrate */
static void Can_lSetBaudrate( uint8 Controller,uint16 BaudrateIndx );
#endif

#if (CAN_FD_ENABLE == STD_ON)
/* Function to set the FD support baudrate */
static void Can_lFDSetBaudrate(uint8 Controller,uint16 FdIndex );
#endif

/* Function to disable the Hw support interrupts */
LOCAL_INLINE void Can_lDisableInterrupts (uint8 Controller);

/* Function to enable the Hw support interrupts */
LOCAL_INLINE void Can_lEnableInterrupts (uint8 Controller);

/* Function for state changes if wakeup is disabled */
static Can_ReturnType Can_lSetModeWuSupportOff(uint8 Controller,
                                      Can_StateTransitionType Transition);

#if(CAN_WAKEUP_CONFIGURED == STD_ON)
/* Function for state changes if wakeup is enabled */
static Can_ReturnType Can_lSetModeWuSupportOn(uint8 Controller,
                                      Can_StateTransitionType Transition);
#endif

#if (CAN_RX_PROCESS_ENABLED == STD_ON)
/* Function to initialize Rx Hw message objects */
LOCAL_INLINE void Can_lInitRxMsgObj(uint8 Controller);

/* Function to clear all received messages to avoid unexpected reception
 condition */
static void  Can_lClearReceivedMsg(uint8 HwControllerId);

#if ((CAN_ID_CONFIG_TYPE == CAN_ID_STANDARD)||  \
                            (CAN_ID_CONFIG_TYPE == CAN_ID_MIXED))
/* Function to set the filter mask for standard messages */
LOCAL_INLINE void Can_lSIDFilter_Config (uint8 ControllerId);
#endif

#if ((CAN_ID_CONFIG_TYPE == CAN_ID_EXTENDED)||  \
                            (CAN_ID_CONFIG_TYPE == CAN_ID_MIXED))
/* Function to set the filter mask for Extended messages */
LOCAL_INLINE void Can_lXIDFilter_Config (uint8 ControllerId);
#endif

/* Function for Handling data reception */
static void Can_lReceiveHandler(uint8 HwControllerId,uint8 CheckBuffType);

/* Function for Handling data retrieve for the message buffer */
static void Can_lRxExtractData(uint8 HwControllerId, uint8 RxBuffIndex,
                                                  Can_RxBufferType RxBuffer);
#endif

/* Handler for Bus-Off condition */
static void Can_lBusOffHandler(uint8 HwControllerId);

#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
/* Function for Activate controller with Pretended mode */
LOCAL_INLINE void Can_lActivateIcom (uint8 Controller,
                                const IcomConfigIdType ConfigurationId);

/* Function for De-activate controller with Pretended mode */
LOCAL_INLINE void Can_lDeactivateIcom (uint8 Controller,
                                 const IcomConfigIdType ConfigurationId);

/* Function for Validate signal conditions */
static Std_ReturnType Can_lIcomValidateMsgSignal(uint16 MessageIndex,
                                         const PduInfoType* PduInfoPtr);

/* Function for Validate receive message conditions */
static void Can_lIcomValidateMsg(const Can_HwType* Mailbox,
                                          const PduInfoType* PduInfoPtr);
#endif

/* Function for mode change request validation */
LOCAL_INLINE Std_ReturnType Can_lModeDetCheck(uint8 Controller,
                                           Can_StateTransitionType Transition);

/* Function for Driver state check */
LOCAL_INLINE Std_ReturnType Can_lReportDetUninit(uint8 ServiceID);

/* Function for validate the requested controller id */
LOCAL_INLINE Std_ReturnType Can_lReportDetParamController(uint8
                                                 Controller,uint8 ServiceID);

/* Function for Hw failure time-out detection */
static Std_ReturnType Can_lTimeOut (
                           const volatile Ifx_UReg_32Bit *Can_RegAddress,
                                    uint32 Check_Val,boolean CheckStatus);

#if((CAN_RX_PROCESS_ENABLED == STD_ON) && (CAN_WAKEUP_CONFIGURED == STD_ON))
/* Function for handling wakeup events */
static void Can_lWakeupHandler (uint8 HwControllerId);
#endif

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#define CAN_17_MCMCAN_STOP_SEC_CODE_QM_GLOBAL
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
   guideline. */
 /* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
    without safegaurd. It complies to Autosar guidelines. */
#include "Can_17_McmCan_MemMap.h"

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#define CAN_17_MCMCAN_START_SEC_VAR_CLEARED_QM_GLOBAL_32
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
   guideline. */
 /* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
    without safegaurd. It complies to Autosar guidelines. */
#include "Can_17_McmCan_MemMap.h"

/* Pointer to store configuration set pointer */
static const Can_17_McmCan_ConfigType* Can_kConfigPtr;

/* The flag used to stores the CAN driver state */
static Can_17_McmCan_DriverStateType Can_17_McmCan_DriverState;

/* Variable used to store the information on Transmission requests,where 32 bits
 of each element represents the Transmit request information */
static uint32 Can_TxBufAddReq[CAN_NOOF_CONTROLLER];

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#define CAN_17_MCMCAN_STOP_SEC_VAR_CLEARED_QM_GLOBAL_32
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */
#include "Can_17_McmCan_MemMap.h"

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#define CAN_17_MCMCAN_START_SEC_VAR_CLEARED_QM_GLOBAL_16
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
   guideline. */
 /* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
    without safegaurd. It complies to Autosar guidelines. */
#include "Can_17_McmCan_MemMap.h"

#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
/* ICOM Message counter counter value */
static uint16 Can_17_McmCan_IcomMsgCntrVal[CAN_NOOF_ICOM_MSGCONFIGURATIONS];
#endif

#if(CAN_TX_PROCESS_ENABLED == STD_ON)
/* Used to store swPduHandle passed by CanIf */
static PduIdType Can_17_McmCan_SwObjectHandle [CAN_NOOF_TX_HARDWARE_OBJECTS];
#endif

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#define CAN_17_MCMCAN_STOP_SEC_VAR_CLEARED_QM_GLOBAL_16
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
    without safegaurd. It complies to Autosar guidelines. */
#include "Can_17_McmCan_MemMap.h"

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#define CAN_17_MCMCAN_START_SEC_VAR_CLEARED_QM_GLOBAL_8
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
   guideline. */
 /* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
    without safegaurd. It complies to Autosar guidelines. */
#include "Can_17_McmCan_MemMap.h"

#if(CAN_WAKEUP_CONFIGURED == STD_ON)
/* This variable stores the wakeup event status */
static boolean Can_17_McmCan_ControllerWUStatus[CAN_NOOF_CONTROLLER];
#endif

#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
/* This variable stores the wake on bus off status on ICOM configuration */
static boolean Can_17_McmCan_IcomConfgBOStatus[CAN_NOOF_CONTROLLER];
/* This variable stores the Pretended network support status */
static boolean Can_17_McmCan_IcomEnableStatus[CAN_NOOF_CONTROLLER];
/* This variable used to stores the current ICOM Configuration ID */
static uint8 Can_17_McmCan_ActiveIcomCfgId[CAN_NOOF_CONTROLLER];
#endif

#if(CAN_RX_PROCESS_ENABLED == STD_ON)
#if(CAN_FD_ENABLE == STD_OFF)
static uint8
    Can_17_McmCan_RxMessageData[CAN_NOOF_CONTROLLER][CAN_MAX_DATA_LENGTH];
#else
static uint8
    Can_17_McmCan_RxMessageData[CAN_NOOF_CONTROLLER][CAN_MAX_FD_LENGTH];
#endif
#endif

/* The flag used to stores the CAN Controller mode */
static CanIf_ControllerModeType
                         Can_17_McmCan_ControllerMode[CAN_NOOF_CONTROLLER];

/* This variable stores status of whether interrupts are enabled */
static uint8 Can_17_McmCan_InterruptStatus[CAN_NOOF_CONTROLLER];

/* This variable stores temperory status of whether interrupts are enabled */
static uint8 Can_17_McmCan_InterruptTempStatus[CAN_NOOF_CONTROLLER];

/* This variable stores count value of disable Interrupt called */
static uint8 Can_17_McmCan_DisableIntrpCount[CAN_NOOF_CONTROLLER];

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
#define CAN_17_MCMCAN_STOP_SEC_VAR_CLEARED_QM_GLOBAL_8
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
   guideline. */
 /* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
    without safegaurd. It complies to Autosar guidelines. */
#include "Can_17_McmCan_MemMap.h"

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/* Memory map of the CAN driver code */
#define CAN_17_MCMCAN_START_SEC_CODE_QM_GLOBAL
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
   guideline. */
 /* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
    without safegaurd. It complies to Autosar guidelines. */
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
void Can_17_McmCan_Init(const Can_17_McmCan_ConfigType* Config)
{
  uint8 KerIndex;
  uint8 CtrlIndex;
  Std_ReturnType ApiStatus;
  ApiStatus = E_OK;
  /* Check Config is NULL_PTR */
  if (NULL_PTR == Config)
    {

      /* Report to DET */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
      Det_ReportError(CAN_17_MCMCAN_MODULE_ID, CAN_17_MCMCAN_INSTANCE_ID,
                      CAN_SID_INIT, CAN_E_INIT_FAILED);
#endif

      ApiStatus = E_NOT_OK;
    }
    else if (CAN_UNINIT != Can_17_McmCan_DriverState)
    {

      /* Report to DET */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError(CAN_17_MCMCAN_MODULE_ID, CAN_17_MCMCAN_INSTANCE_ID,
                      CAN_SID_INIT, CAN_E_TRANSITION);
#endif

        ApiStatus = E_NOT_OK;
    }
    else
    {
      /* If CAN Controller is not in state UNINIT */
      for(CtrlIndex = CAN_ZERO; CtrlIndex < CAN_NOOF_CONTROLLER; CtrlIndex++)
      {

        if(CANIF_CS_UNINIT != Can_17_McmCan_ControllerMode[CtrlIndex])
          {

            /* Report to DET */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
            Det_ReportError(CAN_17_MCMCAN_MODULE_ID,
                 CAN_17_MCMCAN_INSTANCE_ID, CAN_SID_INIT, CAN_E_TRANSITION);
#endif

            ApiStatus = E_NOT_OK;
          }
        else
          {
            /* Do Nothing*/
          }

      }

    }

  if (E_OK == ApiStatus)
    {
      /* Store Config pointer, such that it can be used throughout CAN driver */
      Can_kConfigPtr = Config;
      /* Initialize all the Global variables */
      Can_lInitGlobalVar();
      /* Set kernel index with zero */
      KerIndex = CAN_ZERO;

      /* Initialize clock settings depends on the no of Kernels used */
      while(KerIndex < CAN_NOOF_KERNEL)
        {
          /* Invoke internal function for Clock Settings */
          ApiStatus = Can_lInitClkSetting(KerIndex);

          /* Check for each kernels activation */
          if(E_OK != ApiStatus)
            {
              /* Set condition for break loop */
              KerIndex = CAN_NOOF_KERNEL;

#if (CAN_E_TIMEOUT_DEM_REPORT == CAN_ENABLE_DEM_REPORT)
              Dem_ReportErrorStatus((Dem_EventIdType)
              CAN_E_TIMEOUT, DEM_EVENT_STATUS_FAILED);
#endif
            }
          else
            {
              /* Increment with one */
              KerIndex = KerIndex + CAN_ONE;
#if (CAN_E_TIMEOUT_DEM_REPORT == CAN_ENABLE_DEM_REPORT)
              Dem_ReportErrorStatus((Dem_EventIdType)
              CAN_E_TIMEOUT, DEM_EVENT_STATUS_PASSED);
#endif
            }

        }

      /* Set controller index with zero */
      CtrlIndex = CAN_ZERO;
      /* Initialize the CAN controller */
      while((CtrlIndex < CAN_NOOF_CONTROLLER) &&(E_OK == ApiStatus))
        {
          /* Invoke internal function for the CAN Controller Initialization */
          ApiStatus = Can_lInitializeController(CtrlIndex);
          /* Increment with one */
          CtrlIndex = CtrlIndex + CAN_ONE;
        }

    }


 /* Check all the initial settings are done successfully */
 if(E_OK == ApiStatus)
   {
     /* Set with Driver status as READY*/
     Can_17_McmCan_DriverState = CAN_READY;
   }

}

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
Std_ReturnType Can_17_McmCan_CheckBaudrate( uint8 Controller,uint16 Baudrate )
{
  Std_ReturnType ApiStatus;
  uint16 EndBaudrateCfgIndx;
  uint16 StartBaudrateCfgIndx;
  uint8 LoopBreak;
  /* Check the Driver ApiStatus as Initialized */
  ApiStatus = Can_lReportDetUninit(CAN_SID_CHECK_BAUDRATE);
  /* Set with Value ZERO */
  LoopBreak = CAN_ZERO;

  if(E_OK == ApiStatus)
    {
      /* Check the requested controllerId is Valid or not */
      ApiStatus =
        Can_lReportDetParamController(Controller,CAN_SID_CHECK_BAUDRATE);
    }
  else
    {
      /* Do nothing */
    }

  if(E_OK == ApiStatus)
    {
      /* Set Start index */
      StartBaudrateCfgIndx = Can_kConfigPtr->
                             CanControllerConfigPtr[Controller].BaudrateCfgIndx;
      /* Set with Total no of baudrate index */
      EndBaudrateCfgIndx = Can_kConfigPtr->
                             CanControllerConfigPtr[Controller].NoOfBaudrateCfg;

      while((EndBaudrateCfgIndx > CAN_ZERO) &&(LoopBreak == CAN_ZERO))
      {

        /* Check if requested baudrate is supported by the controller*/
        if(Baudrate == Can_kConfigPtr->
                     CanBaudrateConfigPtr[StartBaudrateCfgIndx].CanBaudrateCfg)
        {
          LoopBreak = CAN_ONE;
        }
        else
        {
          /* point to next baud-rate configuration */
          StartBaudrateCfgIndx++;
        }

        /* Decrement the configuration count */
        EndBaudrateCfgIndx--;
      }

       /* Check Loop break Status */
       if(LoopBreak == CAN_ZERO)
       {
#if(CAN_DEV_ERROR_DETECT == STD_ON)

         /* Report invalid baudrate to DET */
         Det_ReportError(CAN_17_MCMCAN_MODULE_ID, CAN_17_MCMCAN_INSTANCE_ID,
                         CAN_SID_CHECK_BAUDRATE, CAN_E_PARAM_BAUDRATE);
#endif
         /* Set as not supported */
         ApiStatus = E_NOT_OK;
       }

    }

    return ApiStatus;

}

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
Std_ReturnType Can_17_McmCan_SetBaudrate( uint8 Controller,
                                                       uint16 BaudRateConfigID)
{
  Std_ReturnType ApiStatus;

  /* Check the Driver ApiStatus as Initialized */
  ApiStatus = Can_lReportDetUninit(CAN_SID_SET_BAUDRATE);

  if(E_OK == ApiStatus)
    {

      /* Check the requested controllerId is Valid or not */
      ApiStatus =
        Can_lReportDetParamController(Controller,CAN_SID_SET_BAUDRATE);

    }
  else
    {
      /* Do nothing */
    }

  if(E_OK == ApiStatus)
    {

      /* Check if baudrate is supported/configured */
      if(BaudRateConfigID >=
          Can_kConfigPtr->CanControllerConfigPtr[Controller].NoOfBaudrateCfg)
        {

#if(CAN_DEV_ERROR_DETECT == STD_ON)

          /* Report invalid baudrate to DET */
          Det_ReportError(CAN_17_MCMCAN_MODULE_ID, CAN_17_MCMCAN_INSTANCE_ID,
                          CAN_SID_SET_BAUDRATE, CAN_E_PARAM_BAUDRATE);
#endif

          /* Set return value with NOT_OK */
          ApiStatus = E_NOT_OK;
        }
      else if (CANIF_CS_STOPPED != Can_17_McmCan_ControllerMode[Controller])
        {
          /* Set return value with NOT_OK */
          ApiStatus = E_NOT_OK;
        }
      else
        {
          /* do nothing */
        }

    }

  if(E_OK == ApiStatus)
    {
      /* Set Baudrate of requested controller */
      Can_lSetBaudrate(Controller,BaudRateConfigID);
    }

  return ApiStatus;

}
#endif

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
Can_ReturnType Can_17_McmCan_SetControllerMode( uint8 Controller,
                                            Can_StateTransitionType Transition)
{
  Can_ReturnType ApiStatus;
  Std_ReturnType DetStatus;
  /* Set with Not OK */
  ApiStatus = CAN_NOT_OK;
  /* Check if CAN driver is initialized */
  DetStatus = Can_lReportDetUninit(CAN_SID_SETCONTROLLERMODE);

  if(E_OK == DetStatus)
    {
      /* Check if Controller is valid */
      DetStatus =
        Can_lReportDetParamController(Controller,CAN_SID_SETCONTROLLERMODE);
    }
  else
    {
      /* Do nothing */
    }

  if(E_OK == DetStatus)
    {
      /* Check if requested state transition is valid */
      DetStatus = Can_lModeDetCheck(Controller, Transition);
    }
  else
    {
      /* Do nothing */
    }

  if(E_OK == DetStatus)
    {

#if(CAN_WAKEUP_CONFIGURED == STD_ON)

      /* Check requested controller Wakeup Support is enabled or not */
      if(CAN_CHECK_WAKEUP !=
          Can_kConfigPtr->CanControllerConfigPtr[Controller].CanWakeupSourceId)
        {
          /* Perform state transition If Wakeup is Enabled */
          ApiStatus = Can_lSetModeWuSupportOn(Controller,Transition);
        }
      else
#endif
        {
          /* Perform state transition If Wakeup is Disabled */
          ApiStatus = Can_lSetModeWuSupportOff(Controller,Transition);
        }

          /* Check The Hw Register is set properly with requested State */
      if( CAN_OK == ApiStatus)
        {
          /* Notify successful state transition to upper layer */
          CanIf_ControllerModeIndication(Controller,
                                     Can_17_McmCan_ControllerMode[Controller]);
#if (CAN_E_TIMEOUT_DEM_REPORT == CAN_ENABLE_DEM_REPORT)
      /* Report hardware errors to DEM */
      Dem_ReportErrorStatus((Dem_EventIdType)CAN_E_TIMEOUT,
                            DEM_EVENT_STATUS_PASSED);
#endif
        }
        else
        {

#if (CAN_E_TIMEOUT_DEM_REPORT == CAN_ENABLE_DEM_REPORT)
          /* Report time-out failure */
          Dem_ReportErrorStatus((Dem_EventIdType)CAN_E_TIMEOUT,
                                                   DEM_EVENT_STATUS_FAILED);
#endif

        }

    }

  /* return Api status */
  return ApiStatus;

}

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
void Can_17_McmCan_DisableControllerInterrupts(uint8 Controller)
{
  Std_ReturnType ApiStatus;
  /* Check if CAN driver is initialized */
  ApiStatus = Can_lReportDetUninit(CAN_SID_DISABLECONTROLLERINTERRUPTS);

  if(E_OK == ApiStatus)
    {

      /* Check if requested Controller is valid */
      ApiStatus = Can_lReportDetParamController(Controller,
                                       CAN_SID_DISABLECONTROLLERINTERRUPTS);

    }

  if (E_OK == ApiStatus)
    {

      /* Disable controller interrupts */
      Can_lDisableInterrupts(Controller);

    }

}

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
void Can_17_McmCan_EnableControllerInterrupts(uint8 Controller)
{
  Std_ReturnType ApiStatus;
  /* Check if CAN driver is initialized */
  ApiStatus = Can_lReportDetUninit(CAN_SID_ENABLECONTROLLERINTERRUPTS);

  if(E_OK == ApiStatus)
    {

      /* Check if Controller is valid */
      ApiStatus = Can_lReportDetParamController(Controller,
                                        CAN_SID_ENABLECONTROLLERINTERRUPTS);

    }
  if (E_OK == ApiStatus)
    {

      /* Enable Controller Interrupts */
      Can_lEnableInterrupts(Controller);

    }

}

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
Can_ReturnType Can_17_McmCan_Write( Can_HwHandleType Hth,
                                                   const Can_PduType* PduInfo )
{
#if (CAN_TX_PROCESS_ENABLED == STD_ON)
  Can_HwHandleType HthIndex;
#endif
  Std_ReturnType DetStatus;
  Can_ReturnType ApiStatus;
  /* Check if CAN driver is initialized */
  DetStatus = Can_lReportDetUninit(CAN_SID_WRITE);

  if (E_OK == DetStatus)
    {

#if (CAN_TX_PROCESS_ENABLED == STD_ON)
      /* Check for DET */
      DetStatus = Can_lWriteDetCheck(Hth, PduInfo);
#endif
    }

  if (E_NOT_OK == DetStatus)
    {
      /* Request with invalid input ,Set return value with E_NOT_OK */
      ApiStatus = CAN_NOT_OK;
    }
  else
    {

#if (CAN_TX_PROCESS_ENABLED == STD_ON)

      /* Extract HTH index for accessing corresponding configuration */
#if (CAN_RX_PROCESS_ENABLED == STD_ON)
      HthIndex = (Can_HwHandleType) (Hth - CAN_NOOF_RX_HARDWARE_OBJECTS);
#else
      HthIndex = Hth;
#endif /* #if (CAN_NOOF_RX_HARDWARE_OBJECTS != STD_OFF) */

      /* Call function for write message into Tx buffer and request for
      Transmission */
      ApiStatus = Can_lWriteMsgObj(HthIndex,PduInfo);
#else
      /* If no hardware object is configured for transmission */
      ApiStatus = CAN_NOT_OK;
      UNUSED_PARAMETER(PduInfo);
      UNUSED_PARAMETER(Hth);
#endif /* #if (CAN_NOOF_TX_HARDWARE_OBJECTS > 0U) */

    }

  return ApiStatus;

}

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
Can_ReturnType Can_17_McmCan_CheckWakeup(uint8 Controller)
{
  Can_ReturnType ApiStatus;
  Std_ReturnType DetStatus;
  ApiStatus = CAN_NOT_OK;
  /* Check if CAN driver is initialized */
  DetStatus = Can_lReportDetUninit(CAN_SID_CHECKWAKEUP);

  if(E_OK == DetStatus)
    {
      /* Check if Controller is valid */
      DetStatus =
            Can_lReportDetParamController(Controller, CAN_SID_CHECKWAKEUP);
    }
  else
    {
      /* Do Nothing */
    }

  if(E_OK == DetStatus)
    {

      /* Check if wakeup was occurred */
      if(CAN_ONE == Can_17_McmCan_ControllerWUStatus[Controller])
        {

          /* Report to EcuM with WakeupSrc*/
          EcuM_SetWakeupEvent((EcuM_WakeupSourceType)
          Can_kConfigPtr->CanControllerConfigPtr[Controller].CanWakeupSourceId);
          /* Clear wakeup status and return CAN_OK */
          Can_17_McmCan_ControllerWUStatus[Controller] = CAN_ZERO;
          /* Set with Wakeup check command is accepted */
          ApiStatus = CAN_OK;

        }

    }

  return ApiStatus;

}

#endif


/*******************************************************************************
            Scheduled functions
*******************************************************************************/

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
void Can_17_McmCan_MainFunction_Write( void )
{
#if(CAN_TX_POLLING_PROCESSING == STD_ON)

  Std_ReturnType ApiStatus;
  uint8 CtrlIndex;

  /* Check if CAN driver is initialized */
  ApiStatus = Can_lReportDetUninit(CAN_SID_MAINFUNCTION_WRITE);

  if(E_OK == ApiStatus)
    {

      /* Call transmit handler function for each of the CAN controllers
       configured as POLLING mode for transmission successful event handling */
      for(CtrlIndex = CAN_ZERO; CtrlIndex < CAN_NOOF_CONTROLLER; CtrlIndex++)
        {
          /* Check the Tx processing is configured as POLLING */
          if((CAN_POLLING == Can_kConfigPtr->
              CanEventHandlingConfigPtr[CtrlIndex].CanEventType[CAN_ZERO]) &&
              (CANIF_CS_STARTED == Can_17_McmCan_ControllerMode[CtrlIndex]))
            {

#if(CAN_TX_PROCESS_ENABLED == STD_ON)

              /* Invoke internal function to process transmit confirmation */
              Can_lTxEventHandler(CtrlIndex);

#endif
            }

        }

    }

#endif  /* #if(CAN_TX_POLLING_PROCESSING == STD_ON) */
}


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
void Can_17_McmCan_MainFunction_Read( void )
{
#if (CAN_RX_POLLING_PROCESSING == STD_ON)

  Std_ReturnType ApiStatus;
  uint8 CtrlIndex;

  /* Check if CAN driver is initialized */
  ApiStatus = Can_lReportDetUninit(CAN_SID_MAINFUNCTION_READ);

  if(E_OK == ApiStatus)
    {

    /* Call transmit handler function for each of the CAN controllers
       configured as POLLING mode for transmission successful event handling */
      for(CtrlIndex = CAN_ZERO; CtrlIndex < CAN_NOOF_CONTROLLER; CtrlIndex++)
        {

          /* Check the Rx processing is configured as POLLING */
          if((CAN_POLLING == Can_kConfigPtr->
              CanEventHandlingConfigPtr[CtrlIndex].CanEventType[CAN_ONE]) &&
              (CANIF_CS_STARTED == Can_17_McmCan_ControllerMode[CtrlIndex]))
            {

#if(CAN_RX_PROCESS_ENABLED == STD_ON)
              /* Invoke internal function to process transmit confirmation */
              Can_lReceiveHandler(CtrlIndex,CAN_ZERO);
#endif
            }

        }

    }

#endif  /* #if(CAN_RX_POLLING_PROCESSING == STD_ON) */
}

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
void Can_17_McmCan_MainFunction_BusOff(void)
{
#if(CAN_BO_POLLING_PROCESSING == STD_ON)
  uint8 CtrlIndex;
  Std_ReturnType ApiStatus;
  /* Check if CAN driver is initialized */
  ApiStatus = Can_lReportDetUninit(CAN_SID_MAINFUNCTION_BUSOFF);

  if(E_OK == ApiStatus)
    {

      /*
      Call bus-off handler function for each of the CAN controllers
      configured as POLLING mode for bus-off event handling
      */
      for(CtrlIndex = CAN_ZERO; CtrlIndex < CAN_NOOF_CONTROLLER; CtrlIndex++)
        {

          /* Check the BusOff processing mode as Polling */
          if(CAN_POLLING == Can_kConfigPtr->
            CanEventHandlingConfigPtr[CtrlIndex].CanEventType[CAN_TWO])
            {
              /* Invoke Bus-Off Handler */
              Can_lBusOffHandler(CtrlIndex);
            }

        }

    }

#endif /* #if(CAN_BO_POLLING_PROCESSING == STD_ON) */
}

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
void Can_17_McmCan_MainFunction_Wakeup(void)
{
#if(CAN_WU_POLLING_PROCESSING == STD_ON)
  uint8 CtrlIndex;
  Std_ReturnType ApiStatus;
  /* Check if CAN driver is initialized */
  ApiStatus = Can_lReportDetUninit(CAN_SID_MAINFUNCTION_WAKEUP);

  if(E_OK == ApiStatus)
    {

      /* Call wakeup handler function for each of the CAN controllers
        configured as POLLING mode for wakeup event handling */
      for(CtrlIndex = CAN_ZERO; CtrlIndex < CAN_NOOF_CONTROLLER; CtrlIndex++)
        {

          /* Check the WakeUp processing mode as Polling */
          if(CAN_POLLING ==  Can_kConfigPtr->
              CanEventHandlingConfigPtr[CtrlIndex].CanEventType[CAN_THREE])
            {

              /* Check if the controller status is SLEEP or Not */
              if(CANIF_CS_SLEEP == Can_17_McmCan_ControllerMode[CtrlIndex])
                {

#if((CAN_WAKEUP_CONFIGURED == STD_ON) && (CAN_RX_PROCESS_ENABLED == STD_ON))
                  /* Invoke WU Handler */
                  Can_lWakeupHandler(CtrlIndex);
#endif

                }

#if(CAN_PUBLIC_ICOM_SUPPORT == STD_ON)

               /* Check if the controller is activated with PN mode */
              if(CAN_TRUE == Can_17_McmCan_IcomEnableStatus[CtrlIndex])
                {
                   /* Invoke function for check the receive message wakeup
                      events
                   */
                   Can_lReceiveHandler(CtrlIndex,CAN_ZERO);
                }

#endif          /*#if(CAN_PUBLIC_ICOM_SUPPORT == STD_ON)*/

            }

        }

    }

#endif /* #if(CAN_WU_POLLING_PROCESSING == STD_ON) */

}

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
void Can_17_McmCan_MainFunction_Mode(void)
{
  /* The mode indication */
}

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
** Service ID       : 0x10                                                    **
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
Std_ReturnType Can_17_McmCan_SetIcomConfiguration (uint8 Controller,
                                        IcomConfigIdType ConfigurationId)
{
  Std_ReturnType ApiStatus;
  IcomSwitch_ErrorType IcomError;
  /* Initialize status */
  ApiStatus = E_OK;

  /* Check if configuration ID is valid */
  if(ConfigurationId > CAN_NOOF_ICOM_CONFIGURATIONS)
    {

#if (CAN_DEV_ERROR_DETECT == STD_ON)
      /* Report invalid  configuration ID to DET */
      Det_ReportError(CAN_17_MCMCAN_MODULE_ID, CAN_17_MCMCAN_INSTANCE_ID,
                 CAN_SID_SET_ICOM_CONFIGURATION, CAN_E_ICOM_CONFIG_INVALID);
#endif /* #if (CAN_DEV_ERROR_DETECT == STD_ON) */
      ApiStatus = E_NOT_OK;

    }

  /* Check the request with valid input or not */
  if (E_OK == ApiStatus)
    {

      /* Check the CAN controller status*/
      if ((CANIF_CS_STARTED == Can_17_McmCan_ControllerMode[Controller])&&
          (NULL_PTR != Can_kConfigPtr->CanIcomConfigPtr))
        {

         /* Check the configuration ID */
          if (CAN_ZERO ==(uint8) ConfigurationId)
            {
              /* De Activate ICOM settings*/
              Can_lDeactivateIcom(Controller,ConfigurationId);
            }
          else
            {
              /* Activate ICOM settings*/
              Can_lActivateIcom(Controller,ConfigurationId);
            }

          /* Set IcomError as ICOM_SWITCH_E_OK */
          IcomError = ICOM_SWITCH_E_OK;
        }
      else
        {
          /* Set ApiStatus as E_NOT_OK */
          ApiStatus = E_NOT_OK;
          /* Set IcomError as ICOM_SWITCH_E_FAILED */
          IcomError = ICOM_SWITCH_E_FAILED;
        }

      /* Notify the upper layer */
      CanIf_CurrentIcomConfiguration(Controller, ConfigurationId, IcomError);
    }

  return ApiStatus;

}
#endif

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
void Can_17_McmCan_DeInit (void)
{
 Ifx_CAN *MCMBaseAddressPtr;
 uint8 KernelIndx;
 Std_ReturnType Status;

 /* Check if CAN driver is initialized */
 Status = Can_lReportDetUninit(CAN_SID_DEINIT);

 if (E_OK == Status)
 {

  /* Change the driver state to Uninitialized */
  Can_17_McmCan_DriverState = CAN_UNINIT;

  /* Initialize all Global variable with default value */
  Can_lInitGlobalVar();

  for (KernelIndx = CAN_ZERO; KernelIndx < CAN_NOOF_KERNEL; KernelIndx++)
  {

    /* Set with Kernel base address */
    MCMBaseAddressPtr =
    Can_kConfigPtr-> CanMCMModuleConfigPtr[KernelIndx].CanBaseAddress;

    /* Disable write-protection of registers with EndInit protection */
    Mcal_ResetPeripheralEndInitProtection();
    /* Reset the bit RSTSTAT of KRST0 */
    MCMBaseAddressPtr->KRSTCLR.B.CLR = CAN_ONE;
    /* Reset the Kernel registers0 */
    MCMBaseAddressPtr->KRST0.B.RST = CAN_ONE;
    /* Reset the Kernel registers1 */
    MCMBaseAddressPtr->KRST1.B.RST = CAN_ONE;
    /* Set DISR bit in CLC register to Disable the CAN module  */
    MCMBaseAddressPtr->CLC.B.DISR = CAN_ONE;
    /* Enable write-protection of registers with EndInit protection */
    Mcal_SetPeripheralEndInitProtection();

  }

 }

}
#endif

/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : LOCAL_INLINE void Can_lInitGlobalVar                    **
**                    (                                                       **
**                     void                                                   **
**                    )                                                       **
**                                                                            **
** Description      : Initializes global variables of CAN driver              **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
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
LOCAL_INLINE void Can_lInitGlobalVar(void)
{
  uint8 CntrlIndx;
#if(CAN_RX_PROCESS_ENABLED == STD_ON)
  uint8 RxIndexSize;
  uint8 RxHwIndex;
#endif
#if (CAN_TX_PROCESS_ENABLED == STD_ON)
  uint16 TxHwIndex;
#endif

  /* Clear interrupt status and disable count */
  for (CntrlIndx = CAN_ZERO; CntrlIndx < CAN_NOOF_CONTROLLER; CntrlIndx++)
    {
      Can_17_McmCan_DisableIntrpCount[CntrlIndx] = CAN_ZERO;
      Can_17_McmCan_InterruptStatus[CntrlIndx] = CAN_ZERO;
      Can_17_McmCan_InterruptTempStatus[CntrlIndx] = CAN_ZERO;
#if (CAN_WAKEUP_CONFIGURED == STD_ON)
      /* Clear wakeup status flag */
      Can_17_McmCan_ControllerWUStatus[CntrlIndx] = CAN_ZERO;
#endif

    }

#if (CAN_TX_PROCESS_ENABLED == STD_ON)

  /* Clear software PDU handle array */
  for (TxHwIndex = CAN_ZERO; TxHwIndex < CAN_NOOF_TX_HARDWARE_OBJECTS;
       TxHwIndex++)
    {
      Can_17_McmCan_SwObjectHandle [TxHwIndex] = CAN_ZERO;
    }

#endif /* #if (CAN_NOOF_TX_HARDWARE_OBJECTS > 0U) */

#if(CAN_RX_PROCESS_ENABLED == STD_ON)

#if(CAN_FD_ENABLE == STD_OFF)
    RxIndexSize = CAN_MAX_DATA_LENGTH;
#else
    RxIndexSize = CAN_MAX_FD_LENGTH;
#endif
  for (CntrlIndx = CAN_ZERO; CntrlIndx < CAN_NOOF_CONTROLLER; CntrlIndx++)
    {

      for (RxHwIndex = CAN_ZERO; RxHwIndex < RxIndexSize;
           RxHwIndex++)
        {
          Can_17_McmCan_RxMessageData[CntrlIndx][RxHwIndex] = CAN_ZERO ;
        }

    }

#endif

}

/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : LOCAL_INLINE void Can_lInitClkSetting                   **
**                    (                                                       **
**                      uint8 KernelIndx                                      **
**                    )                                                       **
**                                                                            **
** Description      : Initializes clock control register, fractional divider  **
**                    register and module control register                    **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : KernelIndx: MCMCAN kernel configuration index           **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : E_OK/E_NOT_OK                                           **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE Std_ReturnType Can_lInitClkSetting(uint8 KernelIndx)
{
  Ifx_CAN *MCMBaseAddressPtr;
  const volatile Ifx_UReg_32Bit *RegAddressPtr;
  uint32 ClockSelConfigValue;
  uint8 TempClkSel;
  uint8 ActNodeCount;
  uint8 KernlIndx;
  Std_ReturnType DemReportStatus;

  /* Copy the MCMCAN module base address */
  MCMBaseAddressPtr =
    Can_kConfigPtr-> CanMCMModuleConfigPtr[KernelIndx].CanBaseAddress;

  /* Disable the write-protection of registers with EndInit protection */
  Mcal_ResetPeripheralEndInitProtection();
  /* Reset DISR bit in CLC register to enable the control of Can module  */
  MCMBaseAddressPtr->CLC.B.DISR = CAN_ZERO;
  /* Enable the write-protection of registers with EndInit protection */
  Mcal_SetPeripheralEndInitProtection();
  /* Set with Register address */
  RegAddressPtr = &(MCMBaseAddressPtr->CLC.U);

  /* check disable bit is set or not */
  DemReportStatus = Can_lTimeOut(RegAddressPtr,
                   (uint32)CAN_MODULE_DISABLE_STATUS, CAN_TRUE);

 /* Check Hw is set properly or not within the Time-out */
  if(E_OK == DemReportStatus)
    {

    /* Set CLK selection value with no CLK supply */
    ClockSelConfigValue = (uint32) CAN_ZERO;

    /* Read all the active node and set clock settings */
    for(ActNodeCount = CAN_ZERO; ActNodeCount < (Can_kConfigPtr->
            CanMCMModuleConfigPtr[KernelIndx].NoOfActiveNodes); ActNodeCount++)
      {

        /* Read the active node Config index */
        KernlIndx = Can_kConfigPtr->
              CanMCMModuleConfigPtr[KernelIndx].CanUsedHwCfgIndx[ActNodeCount];
        /* Set with CAN node Hw index for clock set */
        TempClkSel = Can_kConfigPtr->
                           CanControllerConfigPtr[KernlIndx].CanControllerHwId;
        /* Set configured module with clock selection as enable */
        ClockSelConfigValue |= CAN_MCR_CLKSEL_SET << (TempClkSel * CAN_TWO);
      }

        /* Set MCR.CI and MCR.CCCE to enable clock selection register write */
        MCMBaseAddressPtr->MCR.U |= CAN_CLKSEL_WRITE_ENABLE;
        /*
        Set Clock selection for both Sync and Sync of selected Nodes in the
        SubSystem.
        */
        MCMBaseAddressPtr->MCR.U |= (Ifx_UReg_32Bit)ClockSelConfigValue;
        /* Reset MCR.CI and MCR.CCCE to Clock Change disabled  */
        MCMBaseAddressPtr->MCR.U = ClockSelConfigValue;

    }
  else
    {
      /* Do Nothing */
    }

  return DemReportStatus;

}

/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : LOCAL_INLINE void Can_lInitializeController             **
**                    (                                                       **
**                      uint8 ControllerId                                    **
**                    )                                                       **
**                                                                            **
** Description      : Initializes CAN Controller Registers and Enables CAN    **
**                    Controller Interrupts                                   **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : ControllerId: Controller configuration index            **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : E_OK/E_NOT_OK                                           **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE Std_ReturnType Can_lInitializeController(uint8 ControllerId)
{
  Ifx_CAN_N *NodeRegAddressPtr;
  Ifx_CAN *MCMBaseAddressPtr;
  const Can_ControllerBaudrateConfigType *CanBaudratePtr;
  const volatile Ifx_UReg_32Bit *RegAddressPtr;
  uint16 BaudRateDefaultCfg;
  uint8 KernelIndx;
  Std_ReturnType DemReportStatus;
  DemReportStatus = E_OK;
  /* Set actual Controller configuration index */
  /* Read the exact Node Start address */
  NodeRegAddressPtr =
    Can_kConfigPtr->CanControllerConfigPtr[ControllerId].CanNodeAddress;

  /* Read Kernel index */
   KernelIndx =
    Can_kConfigPtr->CanControllerConfigPtr[ControllerId].CanKernelHwId;

  /* Copy the MCMCAN module base address */
  MCMBaseAddressPtr =
    Can_kConfigPtr-> CanMCMModuleConfigPtr[KernelIndx].CanBaseAddress;

  /* Interrupt Line assignment for BUSOFF */
  MCMBaseAddressPtr->GRINT1.B.BOFF = CAN_TWO;
  /* Interrupt Line assignment for TxEventFIFO */
  MCMBaseAddressPtr->GRINT1.B.TEFIFO = CAN_ONE;
  /* Interrupt Line assignment for RxFIFO buffer watermark level */
  MCMBaseAddressPtr->GRINT1.B.WATI = CAN_THREE;
  /* Interrupt Line assignment for dedicated receive buffer */
  MCMBaseAddressPtr->GRINT2.B.REINT = CAN_ZERO;

  /* Check Controller in Software Initialization mode with Configuration
     Change Enable.
   */
  if(CAN_BIT_CLEAR_VAL == NodeRegAddressPtr->CCCR.B.INIT)
  {
    RegAddressPtr = &(NodeRegAddressPtr->CCCR.U);
    /* Set with Initialization mode */
    NodeRegAddressPtr->CCCR.B.INIT = CAN_ONE;
    /* Wait until the INIT bits become set */
    DemReportStatus = Can_lTimeOut( RegAddressPtr, CAN_NODE_INIT_CCE_SET,
                                                                 CAN_FALSE);
  }

  /* Check Hw is set properly or not within the Time-out */
  if(E_OK == DemReportStatus)
    {
      /* Set Configuration Change Enable bit */
      NodeRegAddressPtr->CCCR.B.CCE = CAN_ONE;
      /* Set NPCR with the Rxinput/Loopback functionality */
      NodeRegAddressPtr->NPCR.U    = Can_kConfigPtr-> \
                CanControllerConfigPtr[ControllerId].CanNPCRValue;
      /* Read Baud rate configuration Index */
      CanBaudratePtr = Can_kConfigPtr->CanBaudrateConfigPtr;
      /* Select default baud rate configuration of the controller */
      BaudRateDefaultCfg = Can_kConfigPtr-> \
                CanControllerConfigPtr[ControllerId].DefaultBaudrateCfgIndx;
      /* Set NBTP with Nominal baud-rate */
      NodeRegAddressPtr->NBTP.U =
        CanBaudratePtr[BaudRateDefaultCfg].CanControllerBaudrate;

#if(CAN_FD_ENABLE == STD_ON)

      /* Check if the FD configuration is */
      if(CAN_TRUE == CanBaudratePtr[BaudRateDefaultCfg].FdConfigEnabled)
        {
          /* Invoke internal function for set FD baud-rate */
          Can_lFDSetBaudrate(ControllerId,
                            CanBaudratePtr[BaudRateDefaultCfg].FDIndex);
        }
      else
        {
          /* Do nothing */
        }

#endif

      /* Clear All pending Interrupts */
      NodeRegAddressPtr->IR.U = CAN_CLEAR_ALL_INTERRUPTS;
#if(CAN_RX_PROCESS_ENABLED == STD_ON)

#if ((CAN_ID_CONFIG_TYPE == CAN_ID_STANDARD)||  \
                            (CAN_ID_CONFIG_TYPE == CAN_ID_MIXED))
      /* Invoke function to Set standard ID filter setting */
      Can_lSIDFilter_Config(ControllerId);
#endif

#if ((CAN_ID_CONFIG_TYPE == CAN_ID_EXTENDED)||  \
                            (CAN_ID_CONFIG_TYPE == CAN_ID_MIXED))
      /* Invoke function to Set Extended ID filter setting */
      Can_lXIDFilter_Config(ControllerId);
#endif

      /* Receive Message RAM settings*/
      Can_lInitRxMsgObj(ControllerId);
#endif /* #if(CAN_NOOF_RX_HARDWARE_OBJECTS != STD_OFF) */

#if(CAN_TX_PROCESS_ENABLED == STD_ON)
      /* Transmit MSG RAM Settings */
      Can_lInitTxMsgObj(ControllerId);
#endif

      /* Check the BusOff processing mode and Enable BO Interrupt accordingly */
      if (CAN_INTERRUPT == Can_kConfigPtr->
          CanEventHandlingConfigPtr[ControllerId].CanEventType[CAN_TWO])
        {
          /* Enable BO Interrupt(Bus_Off Status Interrupt Enable)of requested
          controller
          */
          Can_17_McmCan_InterruptStatus[ControllerId] |= CAN_ONE;
        }

      /* Set Controller with STOP mode */
      Can_17_McmCan_ControllerMode[ControllerId] = CANIF_CS_STOPPED;
#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
      /* Deactivate Pretended Networking after initialization */
      Can_17_McmCan_IcomEnableStatus[ControllerId] = CAN_FALSE;
#endif

#if (CAN_E_TIMEOUT_DEM_REPORT == CAN_ENABLE_DEM_REPORT)
      /* Report hardware errors to DEM */
      Dem_ReportErrorStatus((Dem_EventIdType)CAN_E_TIMEOUT,
                            DEM_EVENT_STATUS_PASSED);
#endif
      Can_17_McmCan_InterruptTempStatus[ControllerId] =
                                    Can_17_McmCan_InterruptStatus[ControllerId];
    }
  else
    {
#if (CAN_E_TIMEOUT_DEM_REPORT == CAN_ENABLE_DEM_REPORT)
      /* Report hardware errors to DEM */
      Dem_ReportErrorStatus((Dem_EventIdType)CAN_E_TIMEOUT,
                            DEM_EVENT_STATUS_FAILED);
#endif
    }

  return DemReportStatus;

}

#if (CAN_SET_BAUDRATE_API == STD_ON)
/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : static void Can_lSetBaudrate                            **
**                    (                                                       **
**                       uint8 HwControllerId,                                **
**                       uint16 BaudrateIndx                                  **
**                    )                                                       **
**                                                                            **
** Description      : Initializes the Node Bit Timing Register                **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : ControllerId - CAN Controller Id                        **
**                    ControllerBaudrate - Register setting corresponding     **
**                                         to the baud-rate                   **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : E_OK/E_NOT_OK                                           **
**                                                                            **
*******************************************************************************/
static void Can_lSetBaudrate( uint8 Controller,uint16 BaudrateIndx )
{
  uint16 StartBaudrateCfgIndx;
  uint16 ActualBaudrateIndx;
  Ifx_CAN_N *NodeRegAddressPtr;
  const Can_ControllerBaudrateConfigType *CanBaudratePtr;
  CanBaudratePtr = Can_kConfigPtr->CanBaudrateConfigPtr;

  /* Get Node Register address */
  NodeRegAddressPtr =
    Can_kConfigPtr->CanControllerConfigPtr[Controller].CanNodeAddress;

  /* Set with Start index of Baudrate configuration */
  StartBaudrateCfgIndx = Can_kConfigPtr->
                             CanControllerConfigPtr[Controller].BaudrateCfgIndx;

  /* Set with exact Baudrate config index   */
  ActualBaudrateIndx  = BaudrateIndx + StartBaudrateCfgIndx;

  /* Set NBTP with Nominal baud-rate */
  NodeRegAddressPtr->NBTP.U =
                   CanBaudratePtr[ActualBaudrateIndx].CanControllerBaudrate;

#if(CAN_FD_ENABLE == STD_ON)

  /* Check if the FD configuration is */
  if(CAN_TRUE == CanBaudratePtr[ActualBaudrateIndx].FdConfigEnabled)
    {
      /* Invoke internal function for set FD baud-rate */
      Can_lFDSetBaudrate(Controller,CanBaudratePtr[ActualBaudrateIndx].FDIndex);
    }
  else
    {
      /* Disable FD Operation mode */
      NodeRegAddressPtr->CCCR.B.FDOE = CAN_ZERO;
    }

#endif

}
#endif

#if(CAN_FD_ENABLE == STD_ON)
/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : static void Can_lFDSetBaudrate                          **
**                    (                                                       **
**                       uint8 *Controller,                                   **
**                       uint16 FdIndex                                       **
**                    )                                                       **
**                                                                            **
** Description      : Initializes the Data Bit Timing Register                **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : Controller - CAN Controller Id                          **
**                    FdIndex - FD budrate corresponding array index          **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
*******************************************************************************/
static void Can_lFDSetBaudrate( uint8 Controller,uint16 FdIndex )
{
  Ifx_CAN_N *NodeRegAddressPtr;

  /* Get Node Register address */
  NodeRegAddressPtr = Can_kConfigPtr->
                      CanControllerConfigPtr[Controller].CanNodeAddress;

  /* Set DBTP with FD configuration set */
  NodeRegAddressPtr->DBTP.U =
    Can_kConfigPtr->CanFDConfigParamPtr[FdIndex].CanControllerFDBaudrate;

  /*Set Transmitter Delay Compensation Register with value */
  NodeRegAddressPtr->TDCR.U =
    Can_kConfigPtr->CanFDConfigParamPtr[FdIndex].TrcvDelyComp;

  /* Set FD Operation mode as Enabled */
  NodeRegAddressPtr->CCCR.B.FDOE = CAN_ONE;

  /* if BRS is enabled */
  if(CAN_TRUE == Can_kConfigPtr->CanFDConfigParamPtr[FdIndex].TxBRSEnable)
    {
      /* Enable Bit rate switching for transmission*/
      NodeRegAddressPtr->CCCR.B.BRSE = CAN_ONE;
    }
  else
    {
      /* Disable Bit rate switching for transmission*/
      NodeRegAddressPtr->CCCR.B.BRSE = CAN_ZERO;
    }

}

#endif

#if(CAN_TX_PROCESS_ENABLED == STD_ON)
/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : static void Can_lInitTxMsgObj                           **
**                    (                                                       **
**                      uint8 Controller                                      **
**                    )                                                       **
**                                                                            **
** Description    : Initializes transmit message objects                      **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : Controller - CAN Controller Id                          **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE void Can_lInitTxMsgObj(uint8 Controller)
{
  Ifx_CAN_N *NodeRegAddressPtr;
  uint32 CanTxBufferStartAddress;
  uint32 CanTxEventStartAddress;
  Ifx_CAN_N_TX  TxTempEvntReg;
  Ifx_CAN_N_TX  TxTempbuffReg;
  Ifx_CAN_N_TX  TxTempbuffSizeReg;
  /* Get Node Register address */
  NodeRegAddressPtr = Can_kConfigPtr->
                      CanControllerConfigPtr[Controller].CanNodeAddress;
  /* Set with MessageRAM Tx buffer section start address */
  CanTxBufferStartAddress = Can_kConfigPtr->
      CanControllerMsgRAMMapConfigPtr[Controller].ControllerMsgRAMMap[CAN_SIX];
  /* Set with value Zero */
  TxTempEvntReg.EFC.U = CAN_DATA_ZERO;
  /* Set with value Zero */
  TxTempbuffReg.BC.U = CAN_DATA_ZERO;
  /* Set with value Zero */
  TxTempbuffSizeReg.ESC.U = CAN_DATA_ZERO;

  /* Check Tx Event buffer is allocated or not */
 if(CAN_ADDRESS_CHECK != CanTxBufferStartAddress)
  {

    /* Set with MessageRAM Tx Event buffer section start address */
    CanTxEventStartAddress = Can_kConfigPtr->
    CanControllerMsgRAMMapConfigPtr[Controller].ControllerMsgRAMMap[CAN_FIVE];
    /* Set TX Event FIFO Size */
    TxTempEvntReg.EFC.B.EFS = Can_kConfigPtr->
            CanControllerMsgRAMMapConfigPtr[Controller].TxEvntFIFOSize;
    /* Set Tx Event FIFO Configuration register with Event FIFO Start Address*/
    TxTempEvntReg.EFC.B.EFSA = (uint16) ((CanTxEventStartAddress &
                                       CAN_RAM_ADDRESS_OFFSET_MASK)>>CAN_TWO);
    /* Set Offset for the TSBA */
    TxTempbuffReg.BC.B.TBSA = (uint16) ((CanTxBufferStartAddress &
                                      CAN_RAM_ADDRESS_OFFSET_MASK) >> CAN_TWO);

#if (CAN_MULTIPLEXED_TRANSMISSION == STD_ON)

  /*  Check if Queue is Enabled */
  if(CAN_TRUE == Can_kConfigPtr->
                  CanControllerMsgRAMMapConfigPtr[Controller].TxQueueStatus)
    {
      /* Set for Tx Queue operation */
      TxTempbuffReg.BC.B.TFQM = CAN_ONE;

      /* Set Tx Queue size */
      TxTempbuffReg.BC.B.TFQS  = Can_kConfigPtr->
                      CanControllerMsgRAMMapConfigPtr[Controller].TxQueueSize;

      /* Set No of used TX dedicated buffer */
      TxTempbuffReg.BC.B.NDTB = Can_kConfigPtr->
                   CanControllerMsgRAMMapConfigPtr[Controller].TxDedBuffCount;
    }
    else
#endif
    {
      /* Set No of used TX dedicated buffer */
      TxTempbuffReg.BC.B.NDTB = Can_kConfigPtr->
                   CanControllerMsgRAMMapConfigPtr[Controller].TxDedBuffCount;

    }

  /* Load Tx Buffer Configuration register with configuration settings */

#if (CAN_FD_ENABLE == STD_ON)

  if(CAN_TRUE == Can_kConfigPtr->
                       CanControllerConfigPtr[Controller].FDSupport)
    {
      /* Set Tx Buffer Data Field Size for FD support */
      TxTempbuffSizeReg.ESC.B.TBDS = CAN_SEVEN;
    }

#endif

  /* Check Tx processing mode and Enable Tx Interrupt accordingly */
  if (CAN_INTERRUPT == Can_kConfigPtr->
                 CanEventHandlingConfigPtr[Controller].CanEventType[CAN_ZERO])
    {
      /* Enable TxFIFO event Interrupt(Tx Event FIFO New Entry Interrupt
       Enable)of requested controller
       */
      Can_17_McmCan_InterruptStatus[Controller] |= CAN_TWO;
    }

    /* Set Event FIFO configuration Register */
    NodeRegAddressPtr->TX.EFC.U = TxTempEvntReg.EFC.U;
    /* Set Tx message buffer configuration Register */
    NodeRegAddressPtr->TX.BC.U = TxTempbuffReg.BC.U;
    /* Set Tx message buffer size configuration Register */
    NodeRegAddressPtr->TX.ESC.U = TxTempbuffSizeReg.ESC.U;
  }

}
#endif

#if(CAN_RX_PROCESS_ENABLED == STD_ON)
/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : static void Can_lInitRxMsgObj                           **
**                    (                                                       **
**                      uint8 Controller                                      **
**                    )                                                       **
**                                                                            **
** Description      : Initializes receive message objects                     **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : Controller - CAN Controller Id                          **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE void Can_lInitRxMsgObj(uint8 Controller)
{
  Ifx_CAN_N *NodeRegAddressPtr;
  Ifx_CAN_N_RX RxTempBuffSizeConfig;
#if (CAN_RXFIFO0_ENABLED == STD_ON)
  Ifx_CAN_N_RX RxTempFIFO0Config;
#endif
#if (CAN_RXFIFO1_ENABLED == STD_ON)
  Ifx_CAN_N_RX RxTempFIFO1Config;
#endif
  uint32 CanRxBufferCfgData;
#if (CAN_RXFIFO0_ENABLED == STD_ON)
  RxTempFIFO0Config.F0C.U = CAN_DATA_ZERO;
#endif
#if (CAN_RXFIFO1_ENABLED == STD_ON)
  RxTempFIFO1Config.F1C.U = CAN_DATA_ZERO;
#endif
  RxTempBuffSizeConfig.ESC.U = CAN_DATA_ZERO;
  /* Get Node Register address */
  NodeRegAddressPtr = Can_kConfigPtr->
                            CanControllerConfigPtr[Controller].CanNodeAddress;
  /* Set Filter for reject non matching and RTR message */
  NodeRegAddressPtr->GFC.U = CAN_GFC_REJT_RTR_NONMATCH;
  /* Copy Rx buffer start address */
  CanRxBufferCfgData = Can_kConfigPtr->
     CanControllerMsgRAMMapConfigPtr[Controller].ControllerMsgRAMMap[CAN_FOUR];
  if(CAN_ADDRESS_CHECK != CanRxBufferCfgData)
  {
    /* Set Offset for the RBSA */
    NodeRegAddressPtr->RX.BC.B.RBSA = (uint16)
                 ((CanRxBufferCfgData & CAN_RAM_ADDRESS_OFFSET_MASK)>>CAN_TWO);
#if (CAN_FD_ENABLE == STD_ON)
    if(CAN_TRUE == Can_kConfigPtr->
                           CanControllerConfigPtr[Controller].FDSupport)
      {
        /* Set RX Buffer Data Field Size for FD support */
        RxTempBuffSizeConfig.ESC.B.RBDS = CAN_SEVEN;
      }
#endif
  }
#if (CAN_RXFIFO0_ENABLED == STD_ON)
  /* Read FIFO0 Start Address of requested controller */
  CanRxBufferCfgData = Can_kConfigPtr->
     CanControllerMsgRAMMapConfigPtr[Controller].ControllerMsgRAMMap[CAN_TWO];
 if( CAN_ADDRESS_CHECK != CanRxBufferCfgData)
 {
  /* Set Offset for the F0SA */
  RxTempFIFO0Config.F0C.B.F0SA =(uint16)
                 ((CanRxBufferCfgData & CAN_RAM_ADDRESS_OFFSET_MASK)>>CAN_TWO);
  /* Set with the Rx FIFO0 Size*/
  RxTempFIFO0Config.F0C.B.F0S = Can_kConfigPtr->
                      CanControllerMsgRAMMapConfigPtr[Controller].RxFIFO0Size;
  /* Set with the Rx FIFO0 Threshold (WatermarkLevel)*/
  RxTempFIFO0Config.F0C.B.F0WM = Can_kConfigPtr->
                  CanControllerMsgRAMMapConfigPtr[Controller].RxFIFO0Threshold;

#if (CAN_FD_ENABLE == STD_ON)
  if(CAN_TRUE == Can_kConfigPtr->CanControllerConfigPtr[Controller].FDSupport)
    {
      /* Set RX Buffer Data Field Size for FD support */
      RxTempBuffSizeConfig.ESC.B.F0DS = CAN_SEVEN;
    }
#endif

  /* Check Rx processing mode and Enable Rx Interrupt accordingly */
  if (CAN_INTERRUPT == Can_kConfigPtr->
    CanEventHandlingConfigPtr[Controller].CanEventType[CAN_ONE])
    {
      /* Enable Receive interrupts depends on the buffer Type used */
      Can_17_McmCan_InterruptStatus[Controller] |= CAN_EIGHT;
    }
    /* Set the configuration */
    NodeRegAddressPtr->RX.F0C.U = RxTempFIFO0Config.F0C.U;
  }

#endif

#if (CAN_RXFIFO1_ENABLED == STD_ON)
  /* Read FIFO1 Start Address of requested controller */
  CanRxBufferCfgData = Can_kConfigPtr->
    CanControllerMsgRAMMapConfigPtr[Controller].ControllerMsgRAMMap[CAN_THREE];

  if(CAN_ADDRESS_CHECK != CanRxBufferCfgData)
  {

    /* Set Offset for the RXFIFO1 */
    RxTempFIFO1Config.F1C.B.F1SA  = (uint16)
                ((CanRxBufferCfgData & CAN_RAM_ADDRESS_OFFSET_MASK)>>CAN_TWO);
    /* Set with Rx FIFO 1 Size*/
    RxTempFIFO1Config.F1C.B.F1S = Can_kConfigPtr->
                       CanControllerMsgRAMMapConfigPtr[Controller].RxFIFO1Size;
    /* Set with the Rx FIFO0 Threshold (WatermarkLevel)*/
    RxTempFIFO1Config.F1C.B.F1WM = Can_kConfigPtr->
                  CanControllerMsgRAMMapConfigPtr[Controller].RxFIFO1Threshold;

#if (CAN_FD_ENABLE == STD_ON)

  if(CAN_TRUE == Can_kConfigPtr->CanControllerConfigPtr[Controller].FDSupport)
    {
      /* Set RX Buffer Data Field Size for FD support */
      RxTempBuffSizeConfig.ESC.B.F1DS = CAN_SEVEN;
    }

#endif

  /* Check Rx processing mode and Enable Rx Interrupt accordingly */
  if (CAN_INTERRUPT == Can_kConfigPtr->
      CanEventHandlingConfigPtr[Controller].CanEventType[CAN_ONE])
    {
      /* Enable Receive interrupts depends on the buffer Type used */
      Can_17_McmCan_InterruptStatus[Controller] |= CAN_SIXTEEN;
    }

    /* Set the configuration */
    NodeRegAddressPtr->RX.F1C.U = RxTempFIFO1Config.F1C.U;

  }

#endif

  /* Check Rx processing mode and Enable Rx Interrupt accordingly */
  if (CAN_INTERRUPT == Can_kConfigPtr->
      CanEventHandlingConfigPtr[Controller].CanEventType[CAN_ONE])
    {
      /* Enable Receive interrupts of dedicated buffer */
      Can_17_McmCan_InterruptStatus[Controller] |= CAN_FOUR;
    }

  /* Set Rx Message RAM data Size */
  NodeRegAddressPtr->RX.ESC.U = RxTempBuffSizeConfig.ESC.U;

}
#endif

/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           :  Can_ReturnType Can_lSetModeWuSupportOff                **
**                     (                                                      **
**                        uint8 Controller,                                   **
**                        Can_StateTransitionType Transition                  **
**                      )                                                     **
**                                                                            **
** Description      : Performs software triggered state transitions of the    **
**                    CAN Controller State machine when wakeup support is     **
**                    Disabled                                                **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : Controller - Associated CAN Controller Configuration Id **
**                    Transition - Requested transition                       **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : CAN_OK : The HW state has been changed with requested   **
**                                 Transition                                 **
**                    CAN_NOT_OK : The HW status has not been changed with    **
**                                 requested Transition                       **
**                                                                            **
*******************************************************************************/
static Can_ReturnType Can_lSetModeWuSupportOff(uint8 Controller,
                                           Can_StateTransitionType Transition)
{
  Ifx_CAN_N *NodeRegAddressPtr;
  const volatile Ifx_UReg_32Bit *RegAddressPtr;
  Can_ReturnType RetVal;
  Std_ReturnType DemReportStatus;
  /* Set Value with E_NOT_OK */
  RetVal = CAN_NOT_OK;

  /* Get Node Register address */
  NodeRegAddressPtr = Can_kConfigPtr->
                 CanControllerConfigPtr[Controller].CanNodeAddress;

  switch (Transition)
  {

    case CAN_T_START :
    {

      /* Clear receive message object to avoid older notification */
#if(CAN_RX_PROCESS_ENABLED == STD_ON)
      Can_lClearReceivedMsg(Controller);
#endif
      /* Set CAN controller with normal operation mode */
      NodeRegAddressPtr->CCCR.B.INIT = CAN_ZERO;
      /* Set with Register Address */
      RegAddressPtr = &(NodeRegAddressPtr->CCCR.U);
      /* Check the Hw status update */
      DemReportStatus = Can_lTimeOut(RegAddressPtr,(uint32) CAN_NODE_INIT_MODE,
                                                               CAN_TRUE);

    /* Hw state changes successfully then set Sw flag */
    if(E_OK == DemReportStatus)
      {
        /* Enable all interrupts */
        Can_17_McmCan_InterruptTempStatus[Controller] =
                                     Can_17_McmCan_InterruptStatus[Controller];
        /* Set current mode to STARTED */
        Can_17_McmCan_ControllerMode[Controller] = CANIF_CS_STARTED;
        /* Set return value with E_OK */
        RetVal = CAN_OK;
      }

    }
    break;

    case CAN_T_SLEEP :
    {
      /* Set CCR with Clock Stop request */
      NodeRegAddressPtr->CCCR.B.CSR = CAN_ONE;
      /* Set with Register Address */
      RegAddressPtr = &(NodeRegAddressPtr->CCCR.U);
      /* Wait for the Clock Stop Acknowledge */
      DemReportStatus = Can_lTimeOut(RegAddressPtr,(uint32)CAN_CCR_CSA_STATUS,
                                                              CAN_FALSE);

    /* Check Hw is set properly or not within the Time-out */
    if(E_OK == DemReportStatus)
      {
        /* Disable all interrupts */
        Can_17_McmCan_InterruptTempStatus[Controller] = CAN_ZERO;
        /* Set current mode to SLEEP */
        Can_17_McmCan_ControllerMode[Controller] = CANIF_CS_SLEEP;
        /* Set return value with E_OK */
        RetVal = CAN_OK;
      }

    }
    break;

    case CAN_T_STOP :
    {
#if(CAN_TX_PROCESS_ENABLED == STD_ON)
      /* Request for cancel pending request */
      Can_lCancelPendingTx(Controller);
#endif
      /* Set CAN controller with INIT mode */
      NodeRegAddressPtr->CCCR.B.INIT = CAN_ONE;
      /* Set with Register Address */
      RegAddressPtr = &(NodeRegAddressPtr->CCCR.U);
      /* Wait for the Clock Stop Acknowledge */
      DemReportStatus = Can_lTimeOut( RegAddressPtr,
                 CAN_CCCR_INIT_SET_MASK, CAN_FALSE);

    /* Hw state changes successfully then set SW flag */
    if(E_OK == DemReportStatus)
      {
        /* Disable all interrupts */
        Can_17_McmCan_InterruptTempStatus[Controller] = CAN_ZERO;
        /* Set Configuration Change Enable bit */
        NodeRegAddressPtr->CCCR.B.CCE = CAN_ONE;
        /* Set current mode to STOPPED */
        Can_17_McmCan_ControllerMode[Controller] = CANIF_CS_STOPPED;
        /* Set return value with E_OK */
        RetVal = CAN_OK;
      }

    }
    break;

    default:  /* case CAN_T_WAKEUP */
    {
      /* Reset the Clock Stop Request */
       NodeRegAddressPtr->CCCR.B.CSR = CAN_ZERO;
      /* Set with Register Address */
      RegAddressPtr = &(NodeRegAddressPtr->CCCR.U);
      /* Wait for the No clock stop acknowledge */
      DemReportStatus = Can_lTimeOut(RegAddressPtr,(uint32)CAN_CCR_CSA_STATUS,
                                                                  CAN_TRUE);

     /* Check Hw is set properly or not within the Time-out If yes
     then set Sw flag */
    if(E_OK == DemReportStatus)
      {
        /* Disable all interrupts */
        Can_17_McmCan_InterruptTempStatus[Controller] = CAN_ZERO;
        /* Set current mode to STOPPED */
        Can_17_McmCan_ControllerMode[Controller] = CANIF_CS_STOPPED;
        /* Set return value with E_OK */
        RetVal = CAN_OK;
      }

    }
    break;

  }

  if (CAN_ZERO == Can_17_McmCan_DisableIntrpCount[Controller])
  {
    /* Enable/Disable BO Interrupt(Bus_Off Status Interrupt Enable)of requested
       controller
    */
     NodeRegAddressPtr->IE.B.BOE =
     Can_17_McmCan_InterruptTempStatus[Controller] & CAN_ONE;

     /* Enable/Disable TxFIFO event Interrupt(Tx Event FIFO New Entry Interrupt
      Enable)of requested controller
      */
     NodeRegAddressPtr->IE.B.TEFNE =
       ((Can_17_McmCan_InterruptTempStatus[Controller] >> CAN_ONE)
                             & CAN_ONE);

     /* Enable/Disable Receive interrupts of dedicated buffer */
     NodeRegAddressPtr->IE.B.DRXE =
        ((Can_17_McmCan_InterruptTempStatus[Controller] >> CAN_TWO)
                             & CAN_ONE);
#if(CAN_RXFIFO0_ENABLED == STD_ON)

     /* Enable/Disable Receive interrupts depends on the buffer Type used */
     NodeRegAddressPtr->IE.B.RF0WE =
       ((Can_17_McmCan_InterruptTempStatus[Controller] >> CAN_THREE)
                             & CAN_ONE);

#endif

#if (CAN_RXFIFO1_ENABLED == STD_ON)

     /* Enable/Disable Receive interrupts depends on the buffer Type used */
     NodeRegAddressPtr->IE.B.RF1WE =
     ((Can_17_McmCan_InterruptTempStatus[Controller] >> CAN_FOUR)
                              & CAN_ONE);
#endif
  }

  return RetVal;

}

#if(CAN_WAKEUP_CONFIGURED == STD_ON)
/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           :  Can_ReturnType Can_lSetModeWuSupportOn                 **
**                     (                                                      **
**                        uint8 Controller,                                   **
**                        Can_StateTransitionType Transition                  **
**                      )                                                     **
**                                                                            **
** Description      : Performs software triggered state transitions of the    **
**                    CAN Controller State machine when wakeup support is     **
**                    Enabled                                                 **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : Controller - Associated CAN Controller Configuration Id **
**                    Transition - Requested transition                       **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : CAN_OK : The HW state has been changed with requested   **
**                                 Transition                                 **
**                    CAN_NOT_OK : The HW status has not been changed with    **
**                                 requested Transition                       **
**                                                                            **
*******************************************************************************/
static Can_ReturnType Can_lSetModeWuSupportOn(uint8 Controller,
                                             Can_StateTransitionType Transition)
{
  Ifx_CAN_N *NodeRegAddressPtr;
  const volatile Ifx_UReg_32Bit *RegAddressPtr;
  Can_ReturnType RetVal;
  Std_ReturnType DemReportStatus;
  /* Get Node Register address */
  NodeRegAddressPtr = Can_kConfigPtr->
                      CanControllerConfigPtr[Controller].CanNodeAddress;
   /* Set Value with E_NOT_OK */
  RetVal = CAN_NOT_OK;

  switch (Transition)
  {
    case CAN_T_START :
    {
      /* Clear receive message object to avoid older notification */
#if(CAN_RX_PROCESS_ENABLED == STD_ON)
      Can_lClearReceivedMsg(Controller);
#endif
      /* Re-Enable Tx Operation */
      NodeRegAddressPtr->CCCR.B.ASM = CAN_ZERO;
      /* Set CAN controller with normal operation mode */
      NodeRegAddressPtr->CCCR.B.INIT = CAN_ZERO;
      /* Set with Register Address */
      RegAddressPtr = &(NodeRegAddressPtr->CCCR.U);
      /* Check the Hw status update */
      DemReportStatus = Can_lTimeOut(RegAddressPtr, (uint32)CAN_NODE_INIT_MODE,
                                                                 CAN_TRUE);

    /* Hw state changes successfully then set Sw flag */
    if(E_OK == DemReportStatus)
      {
        /* Enable all interrupts */
        Can_17_McmCan_InterruptTempStatus[Controller] =
                                    Can_17_McmCan_InterruptStatus[Controller];
        /* Set current mode to STARTED */
        Can_17_McmCan_ControllerMode[Controller] = CANIF_CS_STARTED;
        /* Set return value with E_OK */
        RetVal = CAN_OK;
      }

    }
    break;

    case CAN_T_SLEEP :
    {
      /* Disable Tx Operation */
      NodeRegAddressPtr->CCCR.B.ASM = CAN_ONE;
      /* Set CAN controller with normal operation mode */
      NodeRegAddressPtr->CCCR.B.INIT = CAN_ZERO;
      /* Set with Register Address */
      RegAddressPtr = &(NodeRegAddressPtr->CCCR.U);
      /* Check the Hw status update */
      DemReportStatus = Can_lTimeOut(RegAddressPtr, (uint32)CAN_NODE_INIT_MODE,
                                                                   CAN_TRUE);

    /* Hw state changes successfully then set Sw flag */
    if(E_OK == DemReportStatus)
      {
        /* Clear wakeup status */
        Can_17_McmCan_ControllerWUStatus[Controller] = CAN_ZERO;
        /* Set current mode to SLEEP */
        Can_17_McmCan_ControllerMode[Controller] = CANIF_CS_SLEEP;

        /* Update SW Flag to enable Rx interrupts except Tx and BusOff
            interrupts */
        Can_17_McmCan_InterruptTempStatus[Controller] =
                     Can_17_McmCan_InterruptStatus[Controller] & (~CAN_THREE);
        /* Set as command is accepted */
        RetVal = CAN_OK;
      }

    }
    break;

    case CAN_T_STOP :
    {
#if(CAN_TX_PROCESS_ENABLED == STD_ON)
      /* Request for cancel pending request */
      Can_lCancelPendingTx(Controller);
#endif
      /* Set CAN controller with INIT mode */
      NodeRegAddressPtr->CCCR.B.INIT = CAN_ONE;
      /* Set with Register Address */
      RegAddressPtr = &(NodeRegAddressPtr->CCCR.U);
      /* Wait for the Clock Stop Acknowledge */
      DemReportStatus = Can_lTimeOut(RegAddressPtr, CAN_CCCR_INIT_SET_MASK,
                                                                 CAN_FALSE);

    /* Hw state changes successfully then set Sw flag */
    if(E_OK == DemReportStatus)
      {
        /* Set Configuration Change Enable bit */
        NodeRegAddressPtr->CCCR.B.CCE = CAN_ONE;
        /* Set current mode to STOPPED */
        Can_17_McmCan_ControllerMode[Controller] = CANIF_CS_STOPPED;
        /* Disable all interrupts */
        Can_17_McmCan_InterruptTempStatus[Controller] = CAN_ZERO;
        /* Set return value with E_OK */
        RetVal = CAN_OK;
      }

    }
    break;

    default:  /* case CAN_T_WAKEUP */
    {
      /* Set CAN controller with INIT mode */
      NodeRegAddressPtr->CCCR.B.INIT = CAN_ONE;
      /* Set with Register Address */
      RegAddressPtr = &(NodeRegAddressPtr->CCCR.U);
      /* Wait for the Clock Stop Acknowledge */
      DemReportStatus = Can_lTimeOut(RegAddressPtr,CAN_CCCR_INIT_SET_MASK,
                                                               CAN_FALSE);

      /* Hw state changes successfully then set Sw flag */
      if(E_OK == DemReportStatus)
        {
          /* Set current mode to STOPPED */
          Can_17_McmCan_ControllerMode[Controller] = CANIF_CS_STOPPED;
          /* Disable all interrupts */
          Can_17_McmCan_InterruptTempStatus[Controller] = CAN_ZERO;
          /* Set return value with E_OK */
          RetVal = CAN_OK;
        }

    }

    break;

  }
  if ((CAN_ZERO == Can_17_McmCan_DisableIntrpCount[Controller])||
              (CANIF_CS_SLEEP == Can_17_McmCan_ControllerMode[Controller]))
  {
    /* Enable/Disable BO Interrupt(Bus_Off Status Interrupt Enable)of requested
       controller
    */
    NodeRegAddressPtr->IE.B.BOE =
    Can_17_McmCan_InterruptTempStatus[Controller] & CAN_ONE;

    /* Enable/Disable TxFIFO event Interrupt(Tx Event FIFO New Entry Interrupt
    Enable)of requested controller
    */
    NodeRegAddressPtr->IE.B.TEFNE =
        ((Can_17_McmCan_InterruptTempStatus[Controller] >> CAN_ONE)
                             & CAN_ONE);

    /* Enable/Disable Receive interrupts of dedicated buffer */
    NodeRegAddressPtr->IE.B.DRXE =
        ((Can_17_McmCan_InterruptTempStatus[Controller] >> CAN_TWO)
                             & CAN_ONE);
#if(CAN_RXFIFO0_ENABLED == STD_ON)

    /* Enable/Disable Receive interrupts depends on the buffer Type used */
    NodeRegAddressPtr->IE.B.RF0WE =
     ((Can_17_McmCan_InterruptTempStatus[Controller] >> CAN_THREE)
                             & CAN_ONE);

#endif

#if (CAN_RXFIFO1_ENABLED == STD_ON)

    /* Enable/Disable Receive interrupts depends on the buffer Type used */
    NodeRegAddressPtr->IE.B.RF1WE =
    ((Can_17_McmCan_InterruptTempStatus[Controller] >> CAN_FOUR)
                              & CAN_ONE);
#endif
  }
  return RetVal;

}
#endif

/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           :LOCAL_INLINE void Can_lDisableInterrupts                 **
**                   (                                                        **
**                      uint8 Controller                                      **
**                   )                                                        **
**                                                                            **
** Description      : Disables CAN Controller Interrupts                      **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : Controller - Associated CAN Controller                  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE void Can_lDisableInterrupts (uint8 Controller)
{
  Ifx_CAN_N *NodeRegAddressPtr;

  /* Get Node Register address */
  NodeRegAddressPtr = Can_kConfigPtr->
                      CanControllerConfigPtr[Controller].CanNodeAddress;

    /* Enter Critical Section */
    SchM_Enter_Can_17_McmCan_CanDisInt();

  if (CAN_ZERO == Can_17_McmCan_DisableIntrpCount[Controller])
    {

      /* Disable Tx interrupt */
      NodeRegAddressPtr->IE.B.TEFNE = CAN_ZERO;
      /* Disable Rx interrupt */
      NodeRegAddressPtr->IE.B.DRXE = CAN_ZERO;
      /* Disable Bus-off interrupt */
      NodeRegAddressPtr->IE.B.BOE = CAN_ZERO;

#if(CAN_RXFIFO0_ENABLED == STD_ON)
      /* Disable FIFO0 interrupt */
      NodeRegAddressPtr->IE.B.RF0WE = CAN_ZERO;
#endif

#if(CAN_RXFIFO1_ENABLED == STD_ON)
      /* Disable FIFO1 interrupt */
      NodeRegAddressPtr->IE.B.RF1WE = CAN_ZERO;
#endif
    }

  /* Count the number of times Can_17_McmCan_DiableControllerInterrupts API
  is called */
  Can_17_McmCan_DisableIntrpCount[Controller]++;

  /* Exit Critical Section */
  SchM_Exit_Can_17_McmCan_CanDisInt();
}

/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           :LOCAL_INLINE void Can_lEnableInterrupts                  **
**                   (                                                        **
**                      uint8 Controller                                      **
**                   )                                                        **
**                                                                            **
** Description      : Enable CAN Controller Interrupts                        **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : Controller - Associated CAN Controller                  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE void Can_lEnableInterrupts (uint8 Controller)
{
  Ifx_CAN_N *NodeRegAddressPtr;
  /* Get Node Register address */
  NodeRegAddressPtr = Can_kConfigPtr->
                      CanControllerConfigPtr[Controller].CanNodeAddress;

  /* Enter Critical Section */
  SchM_Enter_Can_17_McmCan_CanEnInt();

  /* Check Can_17_McmCan_DisableControllerInterrupts has been called before,If
   no then don't perform any action. */
  if (Can_17_McmCan_DisableIntrpCount[Controller] > CAN_ZERO)
    {

      /* Incremental interrupt disable/enable count */
      Can_17_McmCan_DisableIntrpCount[Controller]-- ;

      /* Check if disable count is zero or not */
      if (CAN_ZERO == Can_17_McmCan_DisableIntrpCount[Controller] )
        {
            /* Re enable the status of Interrupt */
            /* Enable BO Interrupt(Bus_Off Status Interrupt Enable)of requested
            controller
            */
              NodeRegAddressPtr->IE.B.BOE =
              Can_17_McmCan_InterruptTempStatus[Controller] & CAN_ONE;
            /* Enable TxFIFO event Interrupt(Tx Event FIFO New Entry Interrupt
             Enable)of requested controller
             */
            NodeRegAddressPtr->IE.B.TEFNE =
                ((Can_17_McmCan_InterruptTempStatus[Controller] >> CAN_ONE)
                                      & CAN_ONE);
            /* Enable Receive interrupts of dedicated buffer */
            NodeRegAddressPtr->IE.B.DRXE =
                  ((Can_17_McmCan_InterruptTempStatus[Controller] >> CAN_TWO)
                                    & CAN_ONE);

#if(CAN_RXFIFO0_ENABLED == STD_ON)

           /* Enable Receive interrupts depends on the buffer Type used */
           NodeRegAddressPtr->IE.B.RF0WE =
             ((Can_17_McmCan_InterruptTempStatus[Controller] >> CAN_THREE)
                                     & CAN_ONE);

#endif

#if (CAN_RXFIFO1_ENABLED == STD_ON)

           /* Enable Receive interrupts depends on the buffer Type used */
          NodeRegAddressPtr->IE.B.RF1WE =
          ((Can_17_McmCan_InterruptTempStatus[Controller] >> CAN_FOUR)
                                     & CAN_ONE);
#endif

        }

    }

    /* Exit Critical Section */
    SchM_Exit_Can_17_McmCan_CanEnInt();

}

#if (CAN_TX_PROCESS_ENABLED == STD_ON)
/*CYCLOMATIC_Can_lWriteMsgObj_JUSTIFICATION: This Function has cyclomatic
Complexity of 17 because the write functionality is handling,if breaking in to
two functions will impact the readability and performance.
*/
/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : Can_ReturnType Can_lWriteMsgObj                         **
**                    (                                                       **
**                       uint8 HthIndex,                                      **
**                       const Can_PduType *PduInfo                           **
**                     )                                                      **
**                                                                            **
** Description    : Programs Message Object for transmission                  **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : HthIndex - HTH index in the configuration structure     **
**                    PduInfo - Pointer to SDU user memory, DLC and           **
**                              Identifier                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : CAN_OK - Write command has been accepted                **
**                   CAN_BUSY - No message object available or pre-emptive    **
**                              call of Can_17_McmCan_Write that can't be     **
**                              implemented re-entrant                        **
**                   CAN_NOT_OK - development error occurred                  **
**                                                                            **
*******************************************************************************/

static Can_ReturnType Can_lWriteMsgObj( Can_HwHandleType HthIndex,
                                        const Can_PduType *PduInfo)
{
  Ifx_CAN_N *NodeRegAddressPtr;
  Ifx_CAN_TXMSG *TxMsgBufferPtr;
  const Can_TxHwObjectConfigType *TxObjPtr;
  const Can_ControllerMsgRAMConfigType *MsgRamCfgPtr;

#if(CAN_TRIGGER_TRANSMIT_SUPPORT == STD_ON)
  PduInfoType *WritePduInfoPtr;
  /* PduInfoType structure variable */
  static  PduInfoType PduInfoTrigger;
#endif

  /* Can_PduType structure variable */
  static  Can_PduType PduTemp;
  Can_PduType *TempPduInfo;
  uint32 TxWriteStartAddr;
  uint32 BuffIndex;
  uint32 BuffElementIndex;
  Can_HwHandleType StartIndex;
  uint16 Temp;
  Can_ReturnType ApiStatus;
  uint8 TxMsgDLC;
  uint8 DataBytePos;
  uint8 ControllerId;

#if(CAN_TRIGGER_TRANSMIT_SUPPORT == STD_ON)
  Std_ReturnType TriggerStatus;
#endif

#if (CAN_MULTIPLEXED_TRANSMISSION == STD_ON)
  Can_TxBufferType TxBuffType;
#endif

#if (CAN_FD_ENABLE == STD_ON)
  static const uint8 DlcConvDataByte[CAN_SIXTEEN] =
                                     {0,1,2,3,4,5,6,7,8,12,16,20,24,32,48,64};
#endif

  /* Set Message RAM configuration pointer with configuration address */
  MsgRamCfgPtr = Can_kConfigPtr->CanControllerMsgRAMMapConfigPtr;
  /* Set with TX object configuration start index */
  TxObjPtr = Can_kConfigPtr->CanTxHwObjectConfigPtr;

#if (CAN_MULTIPLEXED_TRANSMISSION == STD_ON)
  /* Copy the buffer Type of requested HTH */
  TxBuffType = TxObjPtr[HthIndex].TxBufferType;
#endif

  /* Set with the associated controller of requested HTH */
  ControllerId = TxObjPtr[HthIndex].HwControllerId;

  /* Get Node Register address */
  NodeRegAddressPtr = Can_kConfigPtr->
                      CanControllerConfigPtr[ControllerId].CanNodeAddress;

  /* Set with Message RAM start address of Tx buffer */
  TxWriteStartAddr = MsgRamCfgPtr[ControllerId].ControllerMsgRAMMap[CAN_SIX];

  /* Set value with OK */
  ApiStatus = CAN_OK;

  /* Copy the buffer Index for Mask */
  BuffIndex = (uint32)(CAN_TX_BUFF_MASK << (TxObjPtr[HthIndex].BuffIndx));

  /* Enter Critical Section */
  SchM_Enter_Can_17_McmCan_CanWrMO();

#if (CAN_MULTIPLEXED_TRANSMISSION == STD_OFF)

  /* check if buffer is free or not */
  /* MISRA2012_RULE_13_5_JUSTIFICATION: This volatile regsiter check is
  required for the errata fix */
  if((CAN_DATA_ZERO != (Can_TxBufAddReq[ControllerId] & BuffIndex)) || \
    (CAN_DATA_ZERO != (NodeRegAddressPtr->TX.BRP.U & BuffIndex)))

    {
      /* Set return value as Busy */
      ApiStatus = CAN_BUSY;
      BuffElementIndex = (uint32)CAN_ZERO;
    }
    else
    {
      /* Copy the exact buffer element offset */
      BuffElementIndex = TxObjPtr[HthIndex].BuffIndx;
    }
#else
  /* Check Tx buffer Type for Start address calculation and buffer status */
  if(CAN_TX_DED_BUFFER == TxBuffType)
    {
      /* MISRA2012_RULE_13_5_JUSTIFICATION: This volatile regsiter check is
      required for the errata fix */	  
      if((CAN_DATA_ZERO != (Can_TxBufAddReq[ControllerId] & BuffIndex)) || \
         (CAN_DATA_ZERO != (NodeRegAddressPtr->TX.BRP.U & BuffIndex)))
        {
          /* Set return value as Busy */
          ApiStatus = CAN_BUSY;
          BuffElementIndex = (uint32)CAN_ZERO;
        }
        else
        {
          /* Copy the exact buffer element offset */
          BuffElementIndex = TxObjPtr[HthIndex].BuffIndx;
        }

    }
  else
    {

      /* Check TXQUEUE is Free or not */
      if(CAN_BIT_SET_VAL == NodeRegAddressPtr->TX.FQS.B.TFQF)
        {
          /* Set return value as Busy */
          ApiStatus = CAN_BUSY;
          BuffElementIndex = (uint32)CAN_ZERO;
        }
        else
        {
          /* Read put Index value from status register */
          BuffElementIndex = NodeRegAddressPtr->TX.FQS.B.TFQPI;
          /* Copy the buffer Index for Mask */
          BuffIndex = (uint32)(CAN_TX_BUFF_MASK << BuffElementIndex);
        }

    }
#endif
  /* Exit Critical Section */
  SchM_Exit_Can_17_McmCan_CanWrMO();

#if(CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
    if(CAN_TRUE == Can_17_McmCan_IcomEnableStatus[ControllerId])
    {
      /* Set return value as Busy */
      ApiStatus = CAN_BUSY;
    }
#endif

#if(CAN_TRIGGER_TRANSMIT_SUPPORT == STD_ON)
    /* initialize Pointers PduInfoPtr and TempPduInfo */
    WritePduInfoPtr = &PduInfoTrigger;
    TempPduInfo = &PduTemp;
    /* Check Trigger Transmit is Enabled */

    if(CAN_TRUE == TxObjPtr[HthIndex].TriggerTransmitStatus)
    {
      /*Store Data pointer and Data length*/
      WritePduInfoPtr->SduDataPtr = PduInfo->sdu;
      WritePduInfoPtr->SduLength =  (uint8)(PduInfo->length);
      /* CanIf_TriggerTransmit() to acquire the PDUs data */
      TriggerStatus =
                  CanIf_TriggerTransmit(PduInfo->swPduHandle,WritePduInfoPtr);

      if(E_NOT_OK == TriggerStatus)
      {

#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Report to DET */
        Det_ReportError(CAN_17_MCMCAN_MODULE_ID, CAN_17_MCMCAN_INSTANCE_ID,
                                         CAN_SID_WRITE, CAN_E_PARAM_POINTER);
#endif
        /* Set value with OK */
        ApiStatus = CAN_NOT_OK;
      }
      else
      {
        /*Store the updated Data pointer and Data length*/
        TempPduInfo->sdu = WritePduInfoPtr->SduDataPtr;
        TempPduInfo->length = (uint8)(WritePduInfoPtr->SduLength);
      }

    }
    else
#endif
    {
      /* Initialize with PduTemp */
      TempPduInfo = &PduTemp;
      /*Store the Data pointer and Data length*/
      TempPduInfo->sdu = PduInfo->sdu;
      TempPduInfo->length = PduInfo->length;
    }

  if(CAN_OK == ApiStatus)
    {
      /* Enter Critical Section */
      SchM_Enter_Can_17_McmCan_CanWrMO();

#if (CAN_FD_ENABLE == STD_ON)

    /* Check if FD support is enabled for the controller*/
    if(CAN_TRUE == Can_kConfigPtr->
                                CanControllerConfigPtr[ControllerId].FDSupport)
    {

      /* Set buffer size with FD support */
      TxWriteStartAddr = (TxWriteStartAddr + (CAN_MSG_RAM_ELEMENT_SIZE_FD *
                                                       BuffElementIndex));
    }
    else
#endif
    {
      /* Set buffer size with normal buffer */
      TxWriteStartAddr = TxWriteStartAddr + (CAN_MSG_RAM_ELEMENT_SIZE_NFD
                                                    * BuffElementIndex);
    }

    /* MISRA2012_RULE_11_6_JUSTIFICATION: The pointer cast is used to
     cast the address of Dedicated Tx buffer Type to the Tx buffer elements
     structure type */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and
       integer type. Permitted for special function registers.*/
    /* Set with Transmit message buffer0 pointer */
    TxMsgBufferPtr = (Ifx_CAN_TXMSG*) TxWriteStartAddr ;

    TxMsgBufferPtr->T0.U = (uint32)CAN_ZERO;

    /* Reset the RTR bit for avoid transmit messages triggered by
       remote transmission requests
     */
    TxMsgBufferPtr->T0.B.RTR = CAN_ZERO;

#if (CAN_ID_CONFIG_TYPE == CAN_ID_STANDARD)
    /* shift Standard Identifier to position 28..18 */
    TxMsgBufferPtr->T0.B.ID = (PduInfo->id & CAN_STANDARD_ID_MASK)
                                                   << CAN_SHIFT_EIGHTEEN;
    /* Set Id Type as Standard */
    TxMsgBufferPtr->T0.B.XTD = CAN_ZERO;

#else

    /* Check if the requested Id is extended or standard */
    if(CAN_EXTENDED_ID_SET == (PduInfo->id & CAN_EXTENDED_ID_SET))
      {
        /* Store extended Id and set XTD bit */
        TxMsgBufferPtr->T0.B.XTD = CAN_ONE;
        TxMsgBufferPtr->T0.B.ID  = ((PduInfo->id) & CAN_EXTENDED_ID_MASK);
      }
    else
      {
        /* shift Standard Identifier to position 28..18 */
        TxMsgBufferPtr->T0.B.ID = (PduInfo->id & CAN_STANDARD_ID_MASK)
                                                 << CAN_SHIFT_EIGHTEEN;
        /* Set Id Type as Standard */
        TxMsgBufferPtr->T0.B.XTD = CAN_ZERO;
      }
#endif

      /* Set DLC with requested value */
      TxMsgDLC = TempPduInfo->length;
      TxMsgBufferPtr->T1.U = (uint32)CAN_ZERO;

#if (CAN_FD_ENABLE == STD_ON)

      /* Check FD frame need to be transmit */
      if(CAN_ID_FD_ENABLE_SET == (PduInfo->id & CAN_ID_FD_ENABLE_SET))
        {
          /* Set Tx message with FD */
          TxMsgBufferPtr->T1.B.FDF = CAN_ONE;
        }
        else
        {
          /* Set Tx message with Normal */
          TxMsgBufferPtr->T1.B.FDF = CAN_ZERO;
        }

      /* Check CAN FD frames transmitted with bit rate switching */
      if(CAN_BIT_SET_VAL == NodeRegAddressPtr->CCCR.B.BRSE)
        {
          /* Enable BRS */
          TxMsgBufferPtr->T1.B.BRS = CAN_ONE;
        }
        else
        {
          /* Disable BRS */
          TxMsgBufferPtr->T1.B.BRS = CAN_ZERO;
        }

        /* Check DLC length and calculate the Hw support value if DLC > 24 */
        if (TempPduInfo->length > CAN_SHIFT_TWENTYFOUR)
        {
          /* Set DLC length with Hw Supported value */
            TxMsgDLC = (((TempPduInfo->length+CAN_FIFTEEN) >>
                                                      CAN_FOUR)+ CAN_ELEVEN);
        }
        /* Check DLC length and calculate the Hw support value if DLC > 8 */
        else if (TempPduInfo->length > CAN_EIGHT)
        {
            /* Set DLC length with Hw Supported value */
            TxMsgDLC = (((TempPduInfo->length+CAN_THREE) >>
                                                        CAN_TWO) + CAN_SIX);
        }
        else
        {
          /* Do Nothing */
        }
#endif

    /* Write DLC value to the T1 buffer */
    TxMsgBufferPtr->T1.B.DLC = TxMsgDLC;

    /* Write Event FIFO */
    TxMsgBufferPtr->T1.B.EFC = CAN_ONE;

    /* Store sPduHanlde Id for Tx confirmation process */
    Can_17_McmCan_SwObjectHandle [HthIndex] = PduInfo->swPduHandle;

    /* Copy Start index of requested controller */
    StartIndex = Can_kConfigPtr->
              CanControllerConfigPtr[ControllerId].ControllerMOMap[CAN_ZERO];

    Temp = (uint16)((HthIndex - StartIndex) & (CAN_MSG_MARKER_MASK_VAL));

    /* Write Message Marker with SwHandle Index (HTH Indx - Controller StartHTH
    Index) Index for the Tx confirmation process */
    TxMsgBufferPtr->T1.B.MM = Temp;

    /* Set data byte position with zero index */
    DataBytePos = CAN_ZERO;

#if (CAN_FD_ENABLE == STD_ON)
    /* Convert DLC length to Number of Data Bytes supported by Hw */
    TxMsgDLC = DlcConvDataByte[TxMsgDLC];
#endif
      /* Set loop for write with Number of Data Byte */
      while(TxMsgDLC > DataBytePos)
        {

#if (CAN_FD_ENABLE == STD_OFF)
          /* Store the data to the Tx Buffer */
          TxMsgBufferPtr->DB[DataBytePos].U = TempPduInfo->sdu[DataBytePos];

#else

          /* Check byte position is with in the DLC */
          if(DataBytePos < TempPduInfo->length)
          {
            /* Copy Message data to the Tx Buffer */
            TxMsgBufferPtr->DB[DataBytePos].U = TempPduInfo->sdu[DataBytePos];
          }
          else
          {
            /* Store with padding values to the Tx buffer */
            TxMsgBufferPtr->DB[DataBytePos].U = TxObjPtr[HthIndex].FdPaddValue;
          }

#endif    /* (CAN_FD_ENABLE == STD_OFF) */
          /* Set for next data byte */
          DataBytePos++;
        }

        /* Tx Buffer Add Request i
         * Each Tx Buffer has its own "Add Request" bit. Writing a �1� will set the corresponding "Add Request" bit; writing a
         * �0� has no impact. This enables the Host to set transmission requests for multiple Tx Buffers with one write to TXBAR.
         * TXBAR bits are set only for those Tx Buffers configured via TXBC. When no Tx scan is running, the bits are
         * reset immediately, else the bits remain set until the Tx scan process has completed.*/
        
      /* Check the node's hardware communication state */
        /* The following check doesn't make sense here. 
         * Why should another message transmission or reception stop the handling of current message to be transmitted?*/
        if (1)// See comment above. (CAN_PSR_IDLE == NodeRegAddressPtr->PSR.B.ACT)
        {
          /* Request for the Transmission */
          NodeRegAddressPtr->TX.BAR.U |= (Ifx_UReg_32Bit)BuffIndex;
        }
        else
        {
          /* Store the Transmission Request which shall be set in ISR */
          Can_TxBufAddReq[ControllerId] |= (Ifx_UReg_32Bit)BuffIndex;
        }

      /* Set the write operation status as successful */
      ApiStatus = CAN_OK;

      /* Exit Critical Section */
      SchM_Exit_Can_17_McmCan_CanWrMO();
    }
  else
    {
      /* Do nothing */
    }

  return ApiStatus;

}

#endif

#if (CAN_RX_PROCESS_ENABLED == STD_ON)
/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : LOCAL_INLINE void Can_lRxExtractData                    **
**                    (                                                       **
**                      uint8 HwControllerId,                                 **
**                      uint8 HwObjectId,                                     **
**                      uint8 RxBuffIndex                                     **
**                    )                                                       **
**                                                                            **
** Description      : This function extracts data from the message object     **
**                    and notifies upper layer                                **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : HwObjectId - Message Object Id                          **
**                    MsgIndex - MSPND Register Index                         **
**                    RxBuffIndex - Bit Position within MSPND Register        **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
*******************************************************************************/
static void Can_lRxExtractData(uint8 HwControllerId, uint8 RxBuffIndex,
                                                     Can_RxBufferType RxBuffer)
{
  const Can_ControllerMsgRAMConfigType *MsgRamCfgPtr;
  const Ifx_CAN_RXMSG *RxMsgRAMPtr;
  Can_HwType *RxMailBoxInfo;
  PduInfoType *RxPduInfoPtr;
  static Can_HwType TempMailBox;
  static PduInfoType TempPduInfo;
#if ((CAN_ID_CONFIG_TYPE == CAN_ID_STANDARD)||  \
                            (CAN_ID_CONFIG_TYPE == CAN_ID_MIXED))
  const Can_SIDFilterConfigType *CanSIDFilterPtr;
#endif

#if ((CAN_ID_CONFIG_TYPE == CAN_ID_EXTENDED)||  \
                            (CAN_ID_CONFIG_TYPE == CAN_ID_MIXED))
  const Can_XIDFilterConfigType *CanXIDFilterPtr;
#endif
  uint32 RxReadStartAddr;
  uint32 RxReadOffsetAddr;
  uint16 FiltrStartIndx;
  uint8  RxMsgDLC;
  uint8  RxMsgFilterIndx;
  uint8  RxMsgCnt;
  Can_IdType  RxMsgId;
#if (CAN_LPDU_RX_CALLOUT == STD_ON)
  Std_ReturnType RetVal;
  #endif

#if (CAN_FD_ENABLE == STD_ON)
  static const uint8 DlcConvDataByte[CAN_SIXTEEN] =
                               {0,1,2,3,4,5,6,7,8,12,16,20,24,32,48,64};
#endif

  RxMailBoxInfo = &TempMailBox;
  RxPduInfoPtr = &TempPduInfo;

  /* Set Message RAM configuration pointer with configuration address */
  MsgRamCfgPtr = Can_kConfigPtr->CanControllerMsgRAMMapConfigPtr;

  /* Check requested buffer type */
  if(CAN_RX_FIFO0 == RxBuffer)
    {
      /* Read Rx Message RAM start address of RXFIFO0 */
      RxReadStartAddr =
        MsgRamCfgPtr[HwControllerId].ControllerMsgRAMMap[CAN_TWO];

    }
  else if(CAN_RX_FIFO1 == RxBuffer)
    {
      /* Read Rx Message RAM start address of RXFIFO1 */
      RxReadStartAddr =
        MsgRamCfgPtr[HwControllerId].ControllerMsgRAMMap[CAN_THREE];
    }
  else
    {
      /* Read Rx Message RAM start address of dedicated buffer */
      RxReadStartAddr =
        MsgRamCfgPtr[HwControllerId].ControllerMsgRAMMap[CAN_FOUR];
    }

  /* Set OFFSET address with  buffer position */
  RxReadOffsetAddr = RxBuffIndex;
#if (CAN_FD_ENABLE == STD_ON)

    /* Check if FD support is enabled for the controller*/
    if(CAN_TRUE == Can_kConfigPtr->
                          CanControllerConfigPtr[HwControllerId].FDSupport)
     {
      /* Load the data receive message buffer address */
      /*IFX_MISRA_RULE_11_03_STATUS=The pointer cast is used to
      cast the address of Dedicated Rx buffer Type to the Rx buffer elements
      structure type  */
       RxReadStartAddr = RxReadStartAddr + (RxReadOffsetAddr
                            * CAN_MSG_RAM_ELEMENT_SIZE_FD);

     }
     else
#endif
     {
        /* Load the data receive message buffer address */
       RxReadStartAddr = RxReadStartAddr + (RxReadOffsetAddr
                                      * CAN_MSG_RAM_ELEMENT_SIZE_NFD);
     }

  /* MISRA2012_RULE_11_6_JUSTIFICATION: The pointer cast is used to
       cast the address of Dedicated Rx buffer Type to the Rx buffer
       elements  structure type  */
  /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and
       integer type. Permitted for special function registers.*/
  /* Load the data receive message buffer address */
  RxMsgRAMPtr = (Ifx_CAN_RXMSG*) RxReadStartAddr;

  /* Extract DLC information */
  RxMsgDLC = RxMsgRAMPtr->R1.B.DLC;
  /* Read Filter Index */
  RxMsgFilterIndx = RxMsgRAMPtr->R1.B.FIDX;

  /* Extract receive Msg.ID  and ID Type */
  if (CAN_BIT_CLEAR_VAL == RxMsgRAMPtr->R0.B.XTD)
    {
      /* Read received message Id and Message type */
      RxMsgId = RxMsgRAMPtr->R0.B.ID>>CAN_SHIFT_EIGHTEEN;
      /* First index value of standard filter set */
      FiltrStartIndx = Can_kConfigPtr->
              CanControllerConfigPtr[HwControllerId].ControllerMOMap[CAN_TWO];
      /* Set SID filter list Address */
      CanSIDFilterPtr = Can_kConfigPtr->CanSIDFilterConfigPtr;
      /* Read and store the HOH Id*/
      RxMailBoxInfo->Hoh =
                     CanSIDFilterPtr[FiltrStartIndx+RxMsgFilterIndx].HwObjId;
    }
  else
    {
      /* Set message ID type as Extended */
      RxMsgId = CAN_SET_XTD_BIT_MASK;
      /* Copy message ID  */
      RxMsgId |= (Can_IdType)RxMsgRAMPtr->R0.B.ID;
      /* First index value of Extended filter set */
      FiltrStartIndx = Can_kConfigPtr->
                      CanControllerConfigPtr[HwControllerId].XIDFilterPos;
      /* Set XID filter list Address */
      CanXIDFilterPtr = Can_kConfigPtr->CanXIDFilterConfigPtr;
      /* Read and store the HOH Id*/
      RxMailBoxInfo->Hoh =
                     CanXIDFilterPtr[FiltrStartIndx+RxMsgFilterIndx].HwObjId;
    }

  /* Read receive data information from R1 RAM element */
  /* Read FD status of received Message */
  if( CAN_BIT_SET_VAL == RxMsgRAMPtr->R1.B.FDF)
    {
      /* Set FD bit of MsgId */
      RxMsgId |= (Can_IdType)CAN_SET_FD_MASK;
    }

  /* Clear to read from Byte0 */
  RxMsgCnt = CAN_ZERO;

#if (CAN_FD_ENABLE == STD_ON)
    /* Convert DLC length to Number of Data Bytes supported by Hw */
    RxMsgDLC = DlcConvDataByte[RxMsgDLC];
#endif

  /* Copy Message from RAM section to local data buffer */
  while(RxMsgCnt < RxMsgDLC)
    {
      /* copy data from byte0 to n the buffer */
      Can_17_McmCan_RxMessageData[HwControllerId][RxMsgCnt] =
                                             RxMsgRAMPtr->DB[RxMsgCnt].U;
      /* Increment to point next byte */
      RxMsgCnt++;

    }

  /* Call CanIf_RxIndication function with receive message information */
  RxMailBoxInfo->CanId = RxMsgId;
  RxMailBoxInfo->ControllerId = HwControllerId;
  RxPduInfoPtr->SduLength = RxMsgDLC;
  RxPduInfoPtr->SduDataPtr =
                    &Can_17_McmCan_RxMessageData[HwControllerId][CAN_ZERO];

#if(CAN_PUBLIC_ICOM_SUPPORT == STD_ON)

/* Check ICOM enabled */
if(CAN_TRUE == Can_17_McmCan_IcomEnableStatus[HwControllerId])
{
  /* Call Message validate function */
  Can_lIcomValidateMsg(RxMailBoxInfo,RxPduInfoPtr);
}
else

#endif
{
#if (CAN_LPDU_RX_CALLOUT == STD_ON)

  /* Call receive L-PDU callout function if configured */
  RetVal = Can_kConfigPtr->CanLPduRxCalloutFuncPtr((uint8)RxMailBoxInfo->Hoh,
    RxMsgId, RxMsgDLC, &Can_17_McmCan_RxMessageData[HwControllerId][CAN_ZERO]);

if(E_OK == RetVal)
#endif
  {
    /* Call CanIf_RxIndication */
    CanIf_RxIndication(RxMailBoxInfo,RxPduInfoPtr);
  }
}

}
#endif

#if (CAN_RX_PROCESS_ENABLED == STD_ON)
#if ((CAN_ID_CONFIG_TYPE == CAN_ID_STANDARD)||  \
                            (CAN_ID_CONFIG_TYPE == CAN_ID_MIXED))
/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : LOCAL_INLINE void Can_lSIDFilter_Config                 **
**                    (                                                       **
**                      uint8 ControllerId                                    **
**                    )                                                       **
**                                                                            **
** Description      : Initializes receive message objects                     **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : Controller - CAN Controller Id                          **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE void Can_lSIDFilter_Config (uint8 ControllerId)
{
  Ifx_CAN_N *NodeRegAddressPtr;
  Ifx_CAN_N SIDTempCfgData;
  Ifx_CAN_STDMSG *SIDFilterDataPtr;
  const Can_SIDFilterConfigType *CanSIDPtr;
  uint32 SIDFilterStartAddr;
  uint32 SIDFilterRealAddr;
  uint32 SIDFiltrOffset;
  uint16 SIDFiltrIndx;
  uint16 SIDFiltrStartIndx;
  uint16 SIDFiltrEndIndx;
  /* Read the exact Node Start address */
  NodeRegAddressPtr = Can_kConfigPtr->
                      CanControllerConfigPtr[ControllerId].CanNodeAddress;

  /* Set SID filter list Address */
  CanSIDPtr = Can_kConfigPtr->CanSIDFilterConfigPtr;
  /* Set with first SID filter Index */
  SIDFiltrStartIndx = Can_kConfigPtr->
            CanControllerConfigPtr[ControllerId].ControllerMOMap[CAN_TWO];

  /* Set with End SID filter Index */
  SIDFiltrEndIndx = Can_kConfigPtr->
            CanControllerConfigPtr[ControllerId].ControllerMOMap[CAN_THREE];

  /* Read Standard Identifier filter Start address */
  SIDFilterStartAddr = Can_kConfigPtr->
   CanControllerMsgRAMMapConfigPtr[ControllerId].ControllerMsgRAMMap[CAN_ZERO];

  /* Load with Start address offset */
  SIDTempCfgData.SIDFC.B.FLSSA =
     ((uint16)((SIDFilterStartAddr & CAN_RAM_ADDRESS_OFFSET_MASK)>>CAN_TWO));

  /* Set with Standard section RAM size */
  SIDTempCfgData.SIDFC.B.LSS = (uint8) SIDFiltrEndIndx;
  /* Configure Standard Id filter configuration Register*/
  NodeRegAddressPtr->SIDFC.U = SIDTempCfgData.SIDFC.U;
  /* Set Offset with First element */
  SIDFiltrOffset = CAN_ZERO;

  /* Set with all standard filter configuration */
  for(SIDFiltrIndx = SIDFiltrStartIndx; SIDFiltrIndx <
                        (SIDFiltrEndIndx+SIDFiltrStartIndx); SIDFiltrIndx++)
    {
      /* Set with SID element address */
      SIDFilterRealAddr = SIDFilterStartAddr +
                                           (CAN_RAM_BYTES * SIDFiltrOffset);

      /* MISRA2012_RULE_11_6_JUSTIFICATION: The pointer cast is used to
      cast the address of Standard filter Type to the Standard filter elements
      structure type
      */
      /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and
      integer type. Permitted for special function registers.*/
      SIDFilterDataPtr = (Ifx_CAN_STDMSG*)SIDFilterRealAddr;

      /* Set Filter Data to the Filter element */
      SIDFilterDataPtr->S0.U = CanSIDPtr[SIDFiltrIndx].SIDFilterElementS0;
      /* Increment for access next element */
      SIDFiltrOffset++;

    }

}
#endif

#if ((CAN_ID_CONFIG_TYPE == CAN_ID_EXTENDED)||  \
                            (CAN_ID_CONFIG_TYPE == CAN_ID_MIXED))
/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : LOCAL_INLINE void Can_lXIDFilter_Config                 **
**                    (                                                       **
**                      uint8 ControllerId                                    **
**                    )                                                       **
**                                                                            **
** Description      : Initializes receive message objects                     **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : ControllerId - CAN Controller refernce Id               **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE void Can_lXIDFilter_Config (uint8 ControllerId)
{
  Ifx_CAN_N *NodeRegAddressPtr;
  Ifx_CAN_EXTMSG *XIDFilterPtr;
  const Can_XIDFilterConfigType *CanXIDPtr;
  uint32 XIDFilterStartAddr;
  uint32 XIDFilterRealAddr;
  uint32 XIDFilterData;
  uint16 XIDFiltrIndx;
  uint16 XIDFiltrStartIndx;
  uint16 XIDFiltrEndIndx;
  uint8 XIDOffsetIndx;

  /* Read the exact Node Start address */
  NodeRegAddressPtr = Can_kConfigPtr->
                      CanControllerConfigPtr[ControllerId].CanNodeAddress;

  /* Set with start Index */
  XIDFiltrStartIndx = Can_kConfigPtr->
                      CanControllerConfigPtr[ControllerId].XIDFilterPos;

  /* Set with end Index */
  XIDFiltrEndIndx = Can_kConfigPtr->
                    CanControllerConfigPtr[ControllerId].XIDFilterNoOfConfig;

  /* Set XID filter list Address */
  CanXIDPtr = Can_kConfigPtr->CanXIDFilterConfigPtr;

  /* Read Extended Identifier filter Start address */
  XIDFilterStartAddr = Can_kConfigPtr->
   CanControllerMsgRAMMapConfigPtr[ControllerId].ControllerMsgRAMMap[CAN_ONE];

  /* Load with Start address offset */
  NodeRegAddressPtr->XIDFC.B.FLESA =
    ((uint16)((XIDFilterStartAddr & CAN_RAM_ADDRESS_OFFSET_MASK)>>CAN_TWO));

  /* Set with Extended section RAM size */
  NodeRegAddressPtr->XIDFC.B.LSE = (uint8)XIDFiltrEndIndx;
  /* Set with first Filter Index */
  XIDOffsetIndx = CAN_ZERO;

  /* Set with all Extended filter configuration */
  for(XIDFiltrIndx = XIDFiltrStartIndx; XIDFiltrIndx <
                           (XIDFiltrStartIndx+XIDFiltrEndIndx); XIDFiltrIndx++)
    {

      /* Set element offset address F0 */
      XIDFilterRealAddr = XIDFilterStartAddr +
                                   (XIDOffsetIndx * CAN_RAM_BYTES * CAN_TWO);
      /* Read Filter F0 configuration data */
      XIDFilterData = CanXIDPtr[XIDFiltrIndx].XIDFilterElementF0;
      /* MISRA2012_RULE_11_6_JUSTIFICATION: The pointer cast is used to
      cast the address of Extended filter Type to the extended filter elements
      structure type  */
      /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and
      integer type. Permitted for special function registers.*/
      XIDFilterPtr = (Ifx_CAN_EXTMSG*) XIDFilterRealAddr;
      /* Set Filter element F0 with configuration data */
      XIDFilterPtr->F0.U = XIDFilterData;
      /* Read Filter F1 configuration data */
      XIDFilterData = CanXIDPtr[XIDFiltrIndx].XIDFilterElementF1;
      /* Set Filter element F1 with configuration data */
      XIDFilterPtr->F1.U = XIDFilterData;
      /* Increment to next offset */
      XIDOffsetIndx++;

    }

}
#endif

#endif

/*******************************************************************************
         Receive ,Transmit ,Wakeup and Bus-Off  Handler
*******************************************************************************/

#if(CAN_RX_PROCESS_ENABLED == STD_ON)
/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : static void Can_lReceiveHandler                         **
**                    (                                                       **
**                      uint8 HwControllerId                                  **
**                    )                                                       **
**                                                                            **
** Description      : - This function is the core part of the interrupt       **
**                      service routine for Receive Interrupt                 **
**                    - In case of successful reception event, this           **
**                      function calls the function Can_lRxExtractData to     **
**                      extract data from the message object and notify upper **
**                      layer                                                 **
**                    - This function is also called by the polling function  **
**                      Can_17_McmCan_MainFunction_Read for controllers       **
**                      configured with CanRxProcessing as POLLING            **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : HwControllerId - Associated CAN Controller              **
**                    CheckBuffType -  Data received buffer type              **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
*******************************************************************************/

static void Can_lReceiveHandler(uint8 HwControllerId,uint8 CheckBuffType)
{
  Ifx_CAN_N *NodeRegAddressPtr;
  uint32 RxNDATValue;
  uint32 RxNDATValue0;
  uint32 RxNDATValue1;
  uint32 RxDedMask;
  uint8 RxHandleBuffPos;
#if ((CAN_RXFIFO0_ENABLED == STD_ON)|| (CAN_RXFIFO1_ENABLED == STD_ON))
  uint8 RxFillLvlVal;
  uint8 LoopExitFlag;
#endif
  uint8 RegSet;
  /* Read the exact Node Start address */
  NodeRegAddressPtr = Can_kConfigPtr->
                      CanControllerConfigPtr[HwControllerId].CanNodeAddress;

  /* Check the Buffer Type and request from Isr or scheduled function */
  if((CheckBuffType == CAN_ONE) || (CheckBuffType == CAN_ZERO))
    {
      RxNDATValue0 = NodeRegAddressPtr->NDAT1.U;
      RxNDATValue1 = NodeRegAddressPtr->NDAT2.U;
      /* Set with first bit position*/
      RxHandleBuffPos = CAN_ZERO;
      /* Read first NDAT0 buffer value */
      RxNDATValue = RxNDATValue0;

      /* Read NDAT1 and NDAT2 */
      for(RegSet = CAN_ZERO; RegSet < CAN_TWO ; RegSet++ )
        {
          /* Set mask value */
          RxDedMask = CAN_ONE;

          /* Check any one of the Rx dedicated buffer is received with new
          data
          */
          while(CAN_DATA_ZERO != (Ifx_UReg_32Bit)RxNDATValue)
            {

              /* Check buffer with mask position is received data or not */
              if(CAN_DATA_ZERO != (Ifx_UReg_32Bit)(RxNDATValue & RxDedMask))
                {
                  /* Invoke Can_lRxExtractData function for retrieve data from
                  message
                  */
                  Can_lRxExtractData(HwControllerId,RxHandleBuffPos,
                                                             CAN_RX_DED_BUFFER);
                  /* Clear the set bit position of NDAT Reg value */
                  RxNDATValue = RxNDATValue & (~RxDedMask);
                }

              /* Set mask for check next buffer status */
              RxDedMask = RxDedMask << CAN_ONE;
              /* Increment bit position */
              RxHandleBuffPos++;

            }
          /* After completion of read NDAT1 load NDAT_value with NDAT2 register
             value */
          RxNDATValue = RxNDATValue1;
          /* Set Buffer position from value 32 for NDAT2 */
          RxHandleBuffPos = CAN_THIRTY_TWO;

        }

        /* Clear NDAT Register for receive new message */
      NodeRegAddressPtr->NDAT1.U = RxNDATValue0;
      NodeRegAddressPtr->NDAT2.U = RxNDATValue1;

    }

#if (CAN_RXFIFO0_ENABLED == STD_ON)

  if((CheckBuffType == CAN_TWO) || (CheckBuffType == CAN_ZERO))
    {

     /* Check Received CAN message is lost or not */
     if(CAN_BIT_CLEAR_VAL == NodeRegAddressPtr->RX.F0S.B.RF0L)
     {
      /* Set safety loop exit flag with value zero */
      LoopExitFlag = CAN_ZERO;
      /* Read Fill Level value */
      RxFillLvlVal = NodeRegAddressPtr->RX.F0S.B.F0FL;
      /* Check if any of the message received by RXFIFO0 */
      while(LoopExitFlag < RxFillLvlVal)
        {
          /* Read Rx FIFO 0 Get Index */
          RxHandleBuffPos = NodeRegAddressPtr->RX.F0S.B.F0GI;
          /* Invoke data retrieve function */
          Can_lRxExtractData(HwControllerId,RxHandleBuffPos,CAN_RX_FIFO0);
          /* Set read Acknowledge of buffer */
          NodeRegAddressPtr->RX.F0A.U = RxHandleBuffPos;
          /* Increment exit loop condition for safety */
          LoopExitFlag++;
        }

      }
      else
      {

#if(CAN_DEV_ERROR_DETECT == STD_ON)
       /* Report to DET */
       Det_ReportError(CAN_17_MCMCAN_MODULE_ID, CAN_17_MCMCAN_INSTANCE_ID,
                            CAN_SID_RECEIVEHANDLER, CAN_E_DATALOST);
#endif

      }

    }
#endif /*End of CAN_RXFIFO0_ENABLED */

#if (CAN_RXFIFO1_ENABLED == STD_ON)
  if((CheckBuffType == CAN_THREE) || (CheckBuffType == CAN_ZERO))
    {

     /* Check Received CAN message is lost or not */
     if(CAN_BIT_CLEAR_VAL == NodeRegAddressPtr->RX.F1S.B.RF1L)
     {
      /* Set safety loop exit flag with value zero */
      LoopExitFlag = CAN_ZERO;
      /* Read Fill Level value */
      RxFillLvlVal = NodeRegAddressPtr->RX.F1S.B.F1FL;

      /* Check if any of the message received by RXFIFO1 */
      while(LoopExitFlag < RxFillLvlVal)
        {
          /* Read Rx FIFO 1 Get Index */
          RxHandleBuffPos =NodeRegAddressPtr->RX.F1S.B.F1GI;
          /* Invoke data retrieve function */
          Can_lRxExtractData(HwControllerId,RxHandleBuffPos,CAN_RX_FIFO1);
          /* Set read Acknowledge of buffer */
          NodeRegAddressPtr->RX.F1A.U = RxHandleBuffPos;
          /* Increment exit loop condition for safety */
          LoopExitFlag++;
        }

      }
      else
      {

#if(CAN_DEV_ERROR_DETECT == STD_ON)
       /* Report to DET */
       Det_ReportError(CAN_17_MCMCAN_MODULE_ID, CAN_17_MCMCAN_INSTANCE_ID,
                            CAN_SID_RECEIVEHANDLER, CAN_E_DATALOST);
#endif

      }

    }
#endif /*End of CAN_RXFIFO1_ENABLED */

}

#endif

#if(CAN_TX_PROCESS_ENABLED == STD_ON)
/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : static void Can_lTxEventHandler                         **
**                    (                                                       **
**                      uint8 HwControllerId                                  **
**                    )                                                       **
**                                                                            **
** Description      : - This function shall read all the Tx event FIFO        **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : HwControllerId - Associated CAN Controller              **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
*******************************************************************************/
static void Can_lTxEventHandler (uint8 HwControllerId)
{
  Ifx_CAN_N *NodeRegAddressPtr;
  const Ifx_CAN_TXEVENT *TxEvntReadData;
  const Can_ControllerMsgRAMConfigType*MsgRamCfgPtr;
  uint32 TxEvntFIFOstartAddr;
  uint32 TxEvntFIFORealAddr;
  uint32 TxEvntFIFOGetIndex;
  Can_HwHandleType TxHthStartIndex;
  Can_HwHandleType TxHandleIndx;
  uint8 TxEvntFillLvlVal;
  uint8 LoopExitFlag;

  /* Set pointer variable with Message RAM Configuration structure */
  MsgRamCfgPtr = Can_kConfigPtr->CanControllerMsgRAMMapConfigPtr;

  /* Read the exact Node Start address */
  NodeRegAddressPtr =
    Can_kConfigPtr->CanControllerConfigPtr[HwControllerId].CanNodeAddress;

  /* Set Tx Event FIFO Start Address */
  TxEvntFIFOstartAddr =
    MsgRamCfgPtr[HwControllerId].ControllerMsgRAMMap[CAN_FIVE];

          /* Set safety loop exit flag with value zero */
      LoopExitFlag = CAN_ZERO;
      /* Read Fill Level value */
      TxEvntFillLvlVal =  NodeRegAddressPtr->TX.EFS.B.EFFL;

  /* Read Tx event FIFO register for read No of stored Events */
  while(LoopExitFlag < TxEvntFillLvlVal)
    {
      /* Read TxEvent buffer index */
      TxEvntFIFOGetIndex = NodeRegAddressPtr->TX.EFS.B.EFGI;

      /* Set Real Event FIFO element address */
      TxEvntFIFORealAddr = TxEvntFIFOstartAddr +
                                   (TxEvntFIFOGetIndex * (uint32)CAN_EIGHT);

      /* MISRA2012_RULE_11_6_JUSTIFICATION: The pointer cast is used to
      cast the address of Tx Event Type to the event elements  structure type */
      /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and
      integer type. Permitted for special function registers.*/

      /* Load EventFIFO element address */
      TxEvntReadData = (Ifx_CAN_TXEVENT*) TxEvntFIFORealAddr;

      /* Copy the first HTH index of the specific controller */
      TxHthStartIndex = Can_kConfigPtr->
              CanControllerConfigPtr[HwControllerId].ControllerMOMap[CAN_ZERO];

      /* Read Message Marker */
      TxHandleIndx = (Can_HwHandleType) TxEvntReadData->E1.B.MM;

      /* Set with Exact PduHandle Stored Index value */
      TxHandleIndx = TxHthStartIndex + TxHandleIndx;

      /* Call Transmission confirmation to upper-layer with L-PDU handle */
      CanIf_TxConfirmation(Can_17_McmCan_SwObjectHandle [TxHandleIndx]);
      /* Acknowledge shall set to free the Tx Event FIFO */
      NodeRegAddressPtr->TX.EFA.B.EFAI =(uint8) TxEvntFIFOGetIndex;
      /* Increment exit loop condition for safety */
      LoopExitFlag++;
    }

}

#endif

#if((CAN_RX_PROCESS_ENABLED == STD_ON) && (CAN_WAKEUP_CONFIGURED == STD_ON))
/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : static void Can_lWakeupHandler                          **
**                    (                                                       **
**                      uint8 HwControllerId                                  **
**                    )                                                       **
**                                                                            **
** Description      : This function is the core part of the interrupt         **
**                    service routine for Receive Interrupt used for detection**
**                    and reporting of wakeup event                           **
**                    - This function is also called by the polling function  **
**                    Can_17_McmCan_MainFunction_Wakeup for controllers       **
**                    configured with CanWakeupProcessing as POLLING          **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : HwControllerId - Associated CAN Controller              **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
*******************************************************************************/
static void Can_lWakeupHandler(uint8 HwControllerId)
{
  const Ifx_CAN_N *NodeRegAddressPtr;
  EcuM_WakeupSourceType WakeupSourceId;
  Std_ReturnType WakeupStatus;
  WakeupStatus = E_NOT_OK;

  /* Read the exact Node Start address */
  NodeRegAddressPtr =
    Can_kConfigPtr->CanControllerConfigPtr[HwControllerId].CanNodeAddress;

  /* Check if any of the message received by dedicated buffer NDAT1 */
  if(CAN_DATA_ZERO != (Ifx_UReg_32Bit)NodeRegAddressPtr->NDAT1.U)
    {
      /* Set Wakeup ApiStatus as OK */
      WakeupStatus = E_OK;
    }
  /* Check if any of the message received by dedicated buffer NDAT2 */
  else if(CAN_DATA_ZERO != (Ifx_UReg_32Bit)NodeRegAddressPtr->NDAT2.U)
    {
      /* Set Wakeup ApiStatus as OK */
      WakeupStatus = E_OK;
    }
  else
    {
      /* Do Nothing */
    }

#if (CAN_RXFIFO0_ENABLED == STD_ON)

  /* Check if any of the message received by RXFIFO0 */
  if(CAN_BIT_CLEAR_VAL != NodeRegAddressPtr->RX.F0S.B.F0FL)
    {
      /* Set Wakeup ApiStatus as OK */
      WakeupStatus = E_OK;
    }

#endif

#if (CAN_RXFIFO1_ENABLED == STD_ON)

  /* Check if any of the message received by RXFIFO1 */
  if(CAN_BIT_CLEAR_VAL != NodeRegAddressPtr->RX.F1S.B.F1FL)
    {
      /* Set Wakeup ApiStatus as OK */
      WakeupStatus = E_OK;
    }

#endif

   /* Check Wakeup is detected,then set with mode as stop and call
   EcuM_CheckWakeup */
   if(WakeupStatus == E_OK)
    {
      /* Set CAN controller mode to STOPPED */
      Can_17_McmCan_ControllerMode[HwControllerId] = CANIF_CS_STOPPED;
      /* Set CAN controller wakeup status */
      Can_17_McmCan_ControllerWUStatus[HwControllerId] = CAN_ONE;

      /* Check if the Wakeup Processing Mode as Interrupt */
      if(CAN_POLLING !=  Can_kConfigPtr->
            CanEventHandlingConfigPtr[HwControllerId].CanEventType[CAN_THREE])
        {

          /* Set Wakeup sourceId with configured Id */
          WakeupSourceId = (EcuM_WakeupSourceType) Can_kConfigPtr->
                      CanControllerConfigPtr[HwControllerId].CanWakeupSourceId;

          /* Call EcuM function to check for wakeup event */
          EcuM_CheckWakeup(WakeupSourceId);
        }

    }
  else
    {
      /* Do Nothing */
    }

}
#endif

/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : static void Can_lBusOffHandler                          **
**                    (                                                       **
**                      uint8 HwControllerId                                  **
**                    )                                                       **
**                                                                            **
** Description      : The function used to handle the controller while in     **
**                    bus-off state                                           **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : HwControllerId - Associated CAN Controller              **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
*******************************************************************************/
static void Can_lBusOffHandler(uint8 HwControllerId)
{
 const Ifx_CAN_N *NodeRegAddressPtr;
  Ifx_UReg_32Bit TempInitStatus;

#if((CAN_PUBLIC_ICOM_SUPPORT == STD_ON) && (CAN_WAKEUP_CONFIGURED == STD_ON))
  EcuM_WakeupSourceType WakeupSourceId;
#endif

  /* Read the exact Node Start address */
  NodeRegAddressPtr = Can_kConfigPtr->
                      CanControllerConfigPtr[HwControllerId].CanNodeAddress;

   /* Read Controller mode status */
   TempInitStatus = NodeRegAddressPtr->CCCR.B.INIT;

  /* Check the M_CAN is in BusOff state or not */
  if((CAN_BIT_SET_VAL == NodeRegAddressPtr->PSR.B.BO) &&
                     (CAN_BIT_SET_VAL == TempInitStatus))
  {

#if(CAN_TX_PROCESS_ENABLED == STD_ON)
      /* invoke function to cancel all pending request */
      Can_lCancelPendingTx(HwControllerId);
#endif

      /* Set controller mode with STOP state */
      Can_17_McmCan_ControllerMode[HwControllerId] = CANIF_CS_STOPPED;

#if(CAN_PUBLIC_ICOM_SUPPORT == STD_ON)

    if( CAN_TRUE == Can_17_McmCan_IcomEnableStatus[HwControllerId])
    {
#if(CAN_WAKEUP_CONFIGURED == STD_ON)
      /* Set CAN controller wakeup status */
      Can_17_McmCan_ControllerWUStatus[HwControllerId] = CAN_ONE;
#endif

      if (CAN_POLLING !=  Can_kConfigPtr->
             CanEventHandlingConfigPtr[HwControllerId].CanEventType[CAN_THREE])
      {
#if(CAN_WAKEUP_CONFIGURED == STD_ON)
      /* Set Wakeup sourceId with configured Id */
      WakeupSourceId = (EcuM_WakeupSourceType) Can_kConfigPtr->
                CanControllerConfigPtr[HwControllerId].CanWakeupSourceId;
      /* Call EcuM function to check for wakeup event */
      EcuM_CheckWakeup(WakeupSourceId);
#endif
      }

    }
    else
#endif

    {
      /* Call Bus_Off notification function to notify upper layer */
      CanIf_ControllerBusOff(HwControllerId);
    }

  }

}

#if (CAN_MULTIPLE_TX_PERIODS == STD_ON)
/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : static void Can_lTxPeriodHandler                        **
**                    (                                                       **
**                      uint8 HthRefPeriods                                   **
**                    )                                                       **
**                                                                            **
** Description      :  Function used for handling Tx confirmation process with**
**                     multiple write period                                  **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : HthRefPeriods - The write operation cyclic period       **
**                    configuration index                                     **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
*******************************************************************************/
void Can_lTxPeriodHandler (uint8 HthRefPeriods)
{
  const Can_PeriodHthMaskConfigType *HthPeriodInfo;
  const Can_HthMaskObjectConfigType *HthConfigInfo;
  const Ifx_CAN_N *NodeRegAddressPtr;
  uint32 HthMaskVal;
  Can_HwHandleType  HthObjId;
  uint8  HthCnt;
  uint8  HthStartIndx;
  uint8  HthEndIndx;
  uint8  HwControllerId;
  /* Set pointer with HTH period set information */
  HthPeriodInfo = Can_kConfigPtr->CanPeriodHthMaskConfigPtr;
  /* Set pointer with HTH period handler information */
  HthConfigInfo = Can_kConfigPtr->CanHthMaskObjectConfigPtr;
  /* Read the cyclic corresponding handler first index */
  HthStartIndx = HthPeriodInfo[HthRefPeriods].StartIndx;
  /* Read the cyclic corresponding handler first index */
  HthEndIndx = HthPeriodInfo[HthRefPeriods].EndIndx;

  /* Read all the HTH  status corresponding with period */
  for(HthCnt = HthStartIndx ; HthCnt < HthEndIndx ; HthCnt++)
    {

      /* Read Mask value */
      HthMaskVal = HthConfigInfo[HthCnt].TxBufferMaskvalue;
      /* Read Hw associated with HTH */
      HwControllerId = HthConfigInfo[HthCnt].HwControllerId;

      /* Read the exact Node Start address */
      NodeRegAddressPtr = Can_kConfigPtr->
                      CanControllerConfigPtr[HwControllerId].CanNodeAddress;

      /* Check if the transmission has completed */
      if(CAN_ZERO != (NodeRegAddressPtr->TX.BTO.U & HthMaskVal))
        {

          /* Read object handler Id */
          HthObjId = HthConfigInfo[HthCnt].HwObjId;
          /* Extract HTH index for accessing corresponding configuration */
#if (CAN_RX_PROCESS_ENABLED == STD_ON)
          HthObjId = (Can_HwHandleType)
                          (HthObjId - CAN_NOOF_RX_HARDWARE_OBJECTS);
#endif /* #if (CAN_NOOF_RX_HARDWARE_OBJECTS != STD_OFF) */

          /* Read swPduHandle inside the parameter PduInfo for Tx
             confirmation
           */
          /* Call Transmission confirmation to upper-layer with L-PDU handle */
          CanIf_TxConfirmation(Can_17_McmCan_SwObjectHandle [HthObjId]);

        }

    }

}
#endif

#if (CAN_MULTIPLE_RX_PERIODS == STD_ON)
/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : static void Can_lRxPeriodHandler                        **
**                    (                                                       **
**                      uint8 HrhRefPeriods                                   **
**                    )                                                       **
**                                                                            **
** Description      :  Function used for handling Rx indication process with  **
**                     multiple read period                                   **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : HrhRefPeriods - The read operation cyclic period        **
**                    configuration index                                     **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
*******************************************************************************/
void Can_lRxPeriodHandler (uint8 HrhRefPeriods)
{
  const  Can_PeriodHrhMaskConfigType *HrhPeriodInfo;
  const  Can_HrhMaskObjectConfigType *HrhConfigInfo;
  Ifx_CAN_N *NodeRegAddressPtr;
  uint32 HrhMaskVal;
  uint32 RxDedMask;
  uint8  HrhCnt;
  uint8  RxHandleBuffPos;
  uint8  HrhStartIndx;
  uint8  HrhEndIndx;
  uint8  ControllerId;
  uint8 RxFillLvlVal;
  uint8 LoopExitFlag;
  /* Set pointer with Hrh period set information */
  HrhPeriodInfo = Can_kConfigPtr->CanPeriodHrhMaskConfigPtr;
  /* Set pointer with Hrh period handler information */
  HrhConfigInfo = Can_kConfigPtr->CanHrhMaskObjectConfigPtr;
  /* Read the cyclic corresponding handler first index */
  HrhStartIndx = HrhPeriodInfo[HrhRefPeriods].StartIndx;
  /* Read the cyclic corresponding handler first index */
  HrhEndIndx = HrhPeriodInfo[HrhRefPeriods].EndIndx;

  /* Read all the Hrh  status corresponding with period */
  for(HrhCnt = CAN_ZERO ; HrhCnt < HrhEndIndx ; HrhCnt++)
    {
      /* Read Mask value */
      HrhMaskVal = HrhConfigInfo[HrhStartIndx].RxbufferMaskvalue;
      /* Read Hw associated with Hrh */
      ControllerId = HrhConfigInfo[HrhStartIndx].HwControllerId;
      /* Read the exact Node Start address */
      NodeRegAddressPtr = Can_kConfigPtr->
                          CanControllerConfigPtr[ControllerId].CanNodeAddress;
      /* Set mask value */
      RxDedMask = CAN_ONE;
      /* Set with first bit position*/
      RxHandleBuffPos = CAN_ZERO;

      /* Check the buffer Type  */
      if(CAN_RX_DED_BUFFER == HrhConfigInfo[HrhStartIndx].BufferType)
        {

          if(CAN_ONE == (NodeRegAddressPtr->NDAT1.U & HrhMaskVal))
          {

            while(CAN_ONE != (HrhMaskVal & RxDedMask))
            {
              /* Set mask for check next buffer status */
              RxDedMask = RxDedMask << CAN_ONE;
              /* Increment bit position */
              RxHandleBuffPos++;
            }

             /* Call receive data extract fucntion */
             Can_lRxExtractData(ControllerId,RxHandleBuffPos,CAN_RX_DED_BUFFER);
          }
          else if (CAN_ONE == (NodeRegAddressPtr->NDAT2.U & HrhMaskVal))
          {

            while(CAN_ONE != (HrhMaskVal & RxDedMask))
            {
              /* Set mask for check next buffer status */
              RxDedMask = RxDedMask << CAN_ONE;
              /* Increment bit position */
              RxHandleBuffPos++;
            }

            /* Set for read data from NDAT1 buffer */
            RxHandleBuffPos = RxHandleBuffPos + CAN_THIRTY_TWO;

           /* Call receive data extract fucntion */
           Can_lRxExtractData(ControllerId,RxHandleBuffPos,CAN_RX_DED_BUFFER);
          }
          else
          {
            /* Do nothing */
          }

        }

      if(CAN_RX_FIFO0 == HrhConfigInfo[HrhStartIndx].BufferType)
        {

          /* Set safety loop exit flag with value zero */
          LoopExitFlag = CAN_ZERO;
          /* Read Fill Level value */
          RxFillLvlVal = NodeRegAddressPtr->RX.F0S.B.F0FL;
          /* Check if any of the message received by RXFIFO0 */
          while(LoopExitFlag < RxFillLvlVal)
          {
            /* Read Rx FIFO 0 Get Index */
            RxHandleBuffPos = NodeRegAddressPtr->RX.F0S.B.F0GI;
            /* Invoke data retrieve function */
            Can_lRxExtractData(ControllerId,RxHandleBuffPos,CAN_RX_FIFO0);
            /* Set read Acknowledge of buffer */
            NodeRegAddressPtr->RX.F0A.U = RxHandleBuffPos;
            /* Increment exit loop condition for safety */
            LoopExitFlag++;
          }

        }

      if(CAN_RX_FIFO1 == HrhConfigInfo[HrhStartIndx].BufferType)
        {
          /* Set safety loop exit flag with value zero */
          LoopExitFlag = CAN_ZERO;
          /* Read Fill Level value */
          RxFillLvlVal = NodeRegAddressPtr->RX.F1S.B.F1FL;

          /* Check if any of the message received by RXFIFO1 */
          while(LoopExitFlag < RxFillLvlVal)
          {
            /* Read Rx FIFO 1 Get Index */
            RxHandleBuffPos = NodeRegAddressPtr->RX.F1S.B.F1GI;
            /* Invoke data retrieve function */
            Can_lRxExtractData(ControllerId,RxHandleBuffPos,CAN_RX_FIFO1);
            /* Set read Acknowledge of buffer */
            NodeRegAddressPtr->RX.F1A.U = RxHandleBuffPos;
            /* Increment exit loop condition for safety */
            LoopExitFlag++;
          }

        }
       /* Increment to next index */
       HrhStartIndx++;
    }

}
#endif

#if (CAN_TX_PROCESS_ENABLED == STD_ON)
/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : LOCAL_INLINE void Can_lCancelPendingTx                  **
**                    (                                                       **
**                      uint8 ControllerId                                    **
**                    )                                                       **
**                                                                            **
** Description      : This function is used for the cancellation of           **
**                    Transmission,If there any Tx buffer with pending        **
**                    transmission request.                                   **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : ControllerId - Associated CAN Controller                **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE void Can_lCancelPendingTx (uint8 ControllerId)
{
  Ifx_CAN_N *NodeRegAddressPtr;
  uint32 TxPendingStatus;

  /* Read the exact Node Start address */
  NodeRegAddressPtr = Can_kConfigPtr->
                      CanControllerConfigPtr[ControllerId].CanNodeAddress;

  /* Check for pending request */
  if(CAN_DATA_ZERO != NodeRegAddressPtr->TX.BRP.U)
    {

      /* Clear the previously stored info regarding Transmission requests */
      Can_TxBufAddReq[ControllerId] = CAN_DATA_ZERO;
      /* Read Pending Tx Request for buffer */
      TxPendingStatus = NodeRegAddressPtr->TX.BRP.U;
      /* Set the pending request with cancellation request */
      NodeRegAddressPtr->TX.BCR.U = TxPendingStatus;

    }

}
#endif

#if (CAN_RX_PROCESS_ENABLED == STD_ON)
/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : static void Can_lClearReceivedMsg                       **
**                    (                                                       **
**                      uint8 ControllerId                                    **
**                    )                                                       **
**                                                                            **
** Description      : Clears receive message objects to avoid any unintended  **
**                    notification                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : ControllerId - Associated CAN Controller                **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
*******************************************************************************/
static void  Can_lClearReceivedMsg(uint8 HwControllerId)
{
  Ifx_CAN_N *NodeRegAddressPtr;

#if ((CAN_RXFIFO0_ENABLED == STD_ON)|| (CAN_RXFIFO1_ENABLED == STD_ON))
  uint8 RxHandleBuffPos;
  uint8 RxFillLvlVal;
  uint8 LoopExitFlag;
#endif

  /* Read the exact Node Start address */
  NodeRegAddressPtr = Can_kConfigPtr->
                      CanControllerConfigPtr[HwControllerId].CanNodeAddress;

  /* Check if any of the message received by dedicated buffer NDAT1 */
  if(CAN_DATA_ZERO != NodeRegAddressPtr->NDAT1.U)
    {
      /* Clear the Register */
      NodeRegAddressPtr->NDAT1.U = CAN_CLEAR_NEWDATA_REG;
    }
  /* Check if any of the message received by dedicated buffer NDAT2 */
  else if(CAN_DATA_ZERO != NodeRegAddressPtr->NDAT2.U)
    {
      /* Clear the Register */
      NodeRegAddressPtr->NDAT2.U = CAN_CLEAR_NEWDATA_REG;
    }
  else
    {
      /* Do Nothing */
    }

#if (CAN_RXFIFO0_ENABLED == STD_ON)

  /* Set safety loop exit flag with value zero */
  LoopExitFlag = CAN_ZERO;
  /* Read Fill Level value */
  RxFillLvlVal = NodeRegAddressPtr->RX.F0S.B.F0FL;

  /* Check if any of the message received by RXFIFO0 */
  while(RxFillLvlVal > LoopExitFlag)
    {
      /* Read Rx FIFO 0 Get Index */
      RxHandleBuffPos = NodeRegAddressPtr->RX.F0S.B.F0GI;
      /* Set read Acknowledgement of buffer */
      NodeRegAddressPtr->RX.F0A.U = RxHandleBuffPos;
      /* Increment loop exit flag */
      LoopExitFlag++;
    }

#endif

#if (CAN_RXFIFO1_ENABLED == STD_ON)

  /* Set safety loop exit flag with value zero */
  LoopExitFlag = CAN_ZERO;
  /* Read Fill Level value */
  RxFillLvlVal = NodeRegAddressPtr->RX.F1S.B.F1FL;

  /* Check if any of the message received by RXFIFO1 */
  while(RxFillLvlVal > LoopExitFlag)
    {
      /* Read Rx FIFO 0 Get Index */
      RxHandleBuffPos = NodeRegAddressPtr->RX.F1S.B.F1GI;
      /* Set read Acknowledge of buffer */
      NodeRegAddressPtr->RX.F1A.U = RxHandleBuffPos;
      /* Increment loop exit flag */
      LoopExitFlag++;
    }

#endif

}

#endif

/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : Std_ReturnType Can_lTimeOut                             **
**                    (                                                       **
**                      uint32 *Can_RegAddress,                               **
**                      uint32 Check_Val,                                     **
**                      boolean CheckStatus                                   **
**                    )                                                       **
**                                                                            **
** Description      : This service for a time-out detection in case the       **
**                    hardware doesn't react in the expected time             **
**                    (hardware error) to prevent endless loops.              **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : Can_RegAddress- The address of register which value     **
**                    shall be check.                                         **
**                    Check_Val- The value which is used for comparing with   **
**                    Register value.                                         **
**                    CheckStatus- used for identify the comparison method    **
**                    Method.                                                 **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : E_OK: Hw written successfully                           **
**                    E_NOT_OK: Hw is not set with requested value            **
**                                                                            **
*******************************************************************************/
static Std_ReturnType Can_lTimeOut (const volatile Ifx_UReg_32Bit
                                    *Can_RegAddress,
                                    uint32 Check_Val,boolean CheckStatus
                                   )
{
  uint32 TimeOutResolution;
  uint32 TimeOutCount;
  uint32 TimeOutCountInitial;
  uint32 MeasuredTicks;
  Std_ReturnType DemReportStatus;
  uint8 count;
  boolean StatusFlag;

  StatusFlag = CAN_FALSE;
  /* Set count with zero */
  count = CAN_ZERO;
  /* Set with Dem event is reported */
  DemReportStatus = E_NOT_OK;
  /* Read the delay calibration Time */
  TimeOutResolution = Mcal_DelayTickResolution();

  /* calculate actual delay span */
  TimeOutCount =  (uint32)CAN_TIMEOUT_DURATION / TimeOutResolution ;
  /*
     Wait for Hardware Loop time-out to check  the setting status of
     status register
  */
  while( count < CAN_HUNDRED)
  {

  /* Set with initial value */
  TimeOutCountInitial = Mcal_DelayGetTick();
    do
      {
        /* Count the elapsed time */
        MeasuredTicks = Mcal_DelayGetTick()- TimeOutCountInitial;

        if(CAN_TRUE == CheckStatus)
          {

            if(Check_Val != (((uint32)*Can_RegAddress & Check_Val)))
              {
                StatusFlag = CAN_TRUE;
              }
            else
              {
                /* Do nothing */
              }

          }
        else
          {

            if(Check_Val == (((uint32)*Can_RegAddress & Check_Val)))
              {
                StatusFlag = CAN_TRUE;
              }
            else
              {
                /* Do nothing */
              }

          }

      }
    while ((CAN_FALSE == StatusFlag)&&
           (TimeOutCount >= MeasuredTicks));

    /* Check the loop exit condition */
    if(CAN_TRUE == StatusFlag)
    {
       count = CAN_HUNDRED;
       /* Set with Dem event is reported */
       DemReportStatus = E_OK;
    }
    else
    {
       /* Increment count */
       count++;
    }

  }

  return DemReportStatus;

}

#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : LOCAL_INLINE void Can_lActivateIcom                     **
**                    (                                                       **
**                       uint8 Controller ,                                   **
**                       const IcomConfigIdType  ConfigurationId              **
**                    )                                                       **
**                                                                            **
** Description      : Activates CAN pretended networking for a CAN controller **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Controller - Associated CAN Controller                  **
**                    ConfigurationId  - Requested ICOM Configuration         **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE void Can_lActivateIcom (uint8 Controller,\
                                        const IcomConfigIdType ConfigurationId)
{

#if ((CAN_ID_CONFIG_TYPE == CAN_ID_STANDARD)||  \
                                     (CAN_ID_CONFIG_TYPE == CAN_ID_MIXED))
  const Can_SIDFilterConfigType *CanSIDPtr;
  Ifx_CAN_STDMSG *SIDFilterDataPtr;
  uint32 SIDFilterStartAddr;
  uint32 SIDFilterRealAddr;
  uint16 SIDFiltrStartIndx;
  uint16 SIDFiltrEndIndx;
  uint16 SIDFiltrIndx;
  uint8  SIDOffsetIndx;
#endif

#if ((CAN_ID_CONFIG_TYPE == CAN_ID_EXTENDED)||  \
                                    (CAN_ID_CONFIG_TYPE == CAN_ID_MIXED))
  const Can_XIDFilterConfigType *CanXIDPtr;
  Ifx_CAN_EXTMSG *XIDFilterPtr;
  uint32 XIDFilterStartAddr;
  uint32 XIDFilterRealAddr;
  uint16 XIDFiltrStartIndx;
  uint16 XIDFiltrEndIndx;
  uint16 XIDFiltrIndx;
  uint8  XIDOffsetIndx;
#endif

  /* Read the exact Node Start address */
    Ifx_CAN_N *NodeRegAddressPtr = Can_kConfigPtr->
                      CanControllerConfigPtr[Controller].CanNodeAddress;

  /* Check if Wakeup on bus off condition is configured*/
  if (CAN_FALSE == Can_kConfigPtr->
                  CanIcomConfigPtr[ConfigurationId - CAN_ONE].IcomWakeOnBusOff)
    {

      if (CAN_INTERRUPT == Can_kConfigPtr->
                  CanEventHandlingConfigPtr[Controller].CanEventType[CAN_TWO])
        {
          /* Disable Bus off interrupt of the current CAN node */
          NodeRegAddressPtr->IE.B.BOE = CAN_ZERO;
        }

      /* Set the ICOM Wake on bus off status */
      Can_17_McmCan_IcomConfgBOStatus[Controller] = CAN_FALSE;
    }
  else
    {
      /* Set the ICOM Wake on bus off status */
      Can_17_McmCan_IcomConfgBOStatus[Controller] = CAN_TRUE;
    }

    /* Set offset with first element */
    SIDOffsetIndx = CAN_ZERO;

#if ((CAN_ID_CONFIG_TYPE == CAN_ID_STANDARD)||  \
                                     (CAN_ID_CONFIG_TYPE == CAN_ID_MIXED))
  /* Set SID filter list Address */
  CanSIDPtr = Can_kConfigPtr->CanSIDFilterConfigPtr;
   /* Set with first SID filter Index */
  SIDFiltrStartIndx = Can_kConfigPtr->
                   CanControllerConfigPtr[Controller].ControllerMOMap[CAN_TWO];
  /* Set with End SID filter Index */
  SIDFiltrEndIndx = Can_kConfigPtr->
                 CanControllerConfigPtr[Controller].ControllerMOMap[CAN_THREE];
  /* Read Standard Identifier filter Start address */
  SIDFilterStartAddr = Can_kConfigPtr->
     CanControllerMsgRAMMapConfigPtr[Controller].ControllerMsgRAMMap[CAN_ZERO];

  /* Set with all standard filter configuration */
  for(SIDFiltrIndx = SIDFiltrStartIndx; SIDFiltrIndx <
                           (SIDFiltrStartIndx+SIDFiltrEndIndx); SIDFiltrIndx++)
    {
      /* Set with SID Filter element address */
      SIDFilterRealAddr = SIDFilterStartAddr +
                                      (CAN_RAM_BYTES * (uint32)SIDOffsetIndx);
      /* MISRA2012_RULE_11_6_JUSTIFICATION: The pointer cast is used to
      cast the address of Standard filter Type to the Standard filter elements
      structure type  */
      /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and
      integer type. Permitted for special function registers.*/
      /* Increment for access next filter element */
      SIDFilterDataPtr = (Ifx_CAN_STDMSG*)SIDFilterRealAddr;

      if(CAN_FALSE == CanSIDPtr[SIDFiltrIndx].SIDPretendedSupport)
      {
       /* Set to Reject Message with Filter element */
       SIDFilterDataPtr->S0.B.SFEC = CAN_ZERO;
      }

      /* Increment for access next filter element */
      SIDOffsetIndx++;

    }
#endif

#if ((CAN_ID_CONFIG_TYPE == CAN_ID_EXTENDED)||  \
                                       (CAN_ID_CONFIG_TYPE == CAN_ID_MIXED))
  /* Set with XID filter list configuration address */
  CanXIDPtr = Can_kConfigPtr->CanXIDFilterConfigPtr;
  /* Read Extended Identifier filter Start address */
  XIDFilterStartAddr = Can_kConfigPtr->
     CanControllerMsgRAMMapConfigPtr[Controller].ControllerMsgRAMMap[CAN_ONE];
    /* Set with start Index */
  XIDFiltrStartIndx = Can_kConfigPtr->
                      CanControllerConfigPtr[Controller].XIDFilterPos;
  /* Set with end Index */
  XIDFiltrEndIndx = Can_kConfigPtr->
                    CanControllerConfigPtr[Controller].XIDFilterNoOfConfig;
  /* Set OFFSET with first element */
  XIDOffsetIndx = CAN_ZERO;

  /* Set with all Extended filter configuration */
  for(XIDFiltrIndx = XIDFiltrStartIndx; XIDFiltrIndx <
                       (XIDFiltrStartIndx + XIDFiltrEndIndx); XIDFiltrIndx++)
    {
      /* Set address with XID filter element Address */
      XIDFilterRealAddr = XIDFilterStartAddr +
                                 ((uint32)CAN_EIGHT * (uint32)XIDOffsetIndx);

       /* MISRA2012_RULE_11_6_JUSTIFICATION: The pointer cast is used to
         cast the address of Extended filter Type to the extended filter
         elements  structure type */
      /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and
      integer type. Permitted for special function registers.*/
      XIDFilterPtr = (Ifx_CAN_EXTMSG*)XIDFilterRealAddr;

      if(CAN_FALSE == CanXIDPtr[XIDFiltrIndx].XIDPretendedSupport)
      {
        /* Set to Reject Message with Filter element */
        XIDFilterPtr->F0.B.EFEC = CAN_ZERO;
      }
      /* Increment for access next filter element */
      XIDOffsetIndx++;
    }
#endif

  /*Set the pretended network status for the current CAN controller */
  Can_17_McmCan_IcomEnableStatus[Controller] = CAN_TRUE;
  /* Store ICOM Configuration ID */
  Can_17_McmCan_ActiveIcomCfgId[Controller] = ConfigurationId;

}

/*CYCLOMATIC_Can_lDeactivateIcom_JUSTIFICATION: This Function has cyclomatic
Complexity of 16 because it uses both filter settings of same controller hence
the  breaking the in two functions will impact the readability.
*/
/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : LOCAL_INLINE void Can_lDeactivateIcom                   **
**                    (                                                       **
**                       uint8 Controller ,                                   **
**                       const IcomConfigIdType  ConfigurationId              **
**                    )                                                       **
**                                                                            **
** Description      : Deactivate CAN pretended networking for a CAN controller**
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Controller - Associated CAN Controller                  **
**                    ConfigurationId  - Requested ICOM Configuration         **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE void Can_lDeactivateIcom (uint8 Controller,
                                 const IcomConfigIdType ConfigurationId)
{
  Ifx_CAN_N *NodeRegAddressPtr;

#if ((CAN_ID_CONFIG_TYPE == CAN_ID_STANDARD)||  \
                                     (CAN_ID_CONFIG_TYPE == CAN_ID_MIXED))
  const Can_SIDFilterConfigType *CanSIDPtr;
  Ifx_CAN_STDMSG *SIDFilterPtr;
  uint32 SIDFilterStartAddr;
  uint32 SIDFilterRealAddr;
  uint16 SIDFiltrStartIndx;
  uint16 SIDFiltrEndIndx;
  uint16 SIDFiltrIndx;
  uint8 SIDOffsetIndx;
#endif

#if ((CAN_ID_CONFIG_TYPE == CAN_ID_EXTENDED)||  \
                                    (CAN_ID_CONFIG_TYPE == CAN_ID_MIXED))
  const Can_XIDFilterConfigType *CanXIDPtr;
  Ifx_CAN_EXTMSG *XIDFilterPtr;
  uint32 XIDFilterStartAddr;
  uint32 XIDFilterRealAddr;
  uint16 XIDFiltrStartIndx;
  uint16 XIDFiltrEndIndx;
  uint16 XIDFiltrIndx;
  uint8 XIDOffsetIndx;
#endif

  uint16 IcomMsgIndex;
  uint16 MsgIndex;
  uint16 IcomNoOfRxMsg;
  uint8 IcomConfigId;

  /* Get ICOM configuration ID*/
  IcomConfigId = Can_17_McmCan_ActiveIcomCfgId[Controller];

  /* Get the first receive configuration index */
  IcomMsgIndex =
    Can_kConfigPtr->CanIcomConfigPtr[IcomConfigId - CAN_ONE].IcomFirstMsgIndx;

  /* Get the total number of ICOM Receive messages configured*/
  IcomNoOfRxMsg =
    Can_kConfigPtr->CanIcomConfigPtr[IcomConfigId - CAN_ONE].IcomNoOfMsgIndx;

  /* Read the exact Node Start address */
  NodeRegAddressPtr = Can_kConfigPtr->
                      CanControllerConfigPtr[Controller].CanNodeAddress;
  /* Set with Initialization mode */
  NodeRegAddressPtr->CCCR.B.INIT = CAN_ONE;
  /* Enable configuration change */
  NodeRegAddressPtr->CCCR.B.CCE = CAN_ONE;

  /* Check if Wakeup on bus off condition is configured*/
  if (CAN_FALSE == Can_kConfigPtr->
                CanIcomConfigPtr[ConfigurationId - CAN_ONE].IcomWakeOnBusOff)
    {

      if (CAN_INTERRUPT == Can_kConfigPtr->
                 CanEventHandlingConfigPtr[Controller].CanEventType[CAN_TWO])
        {
          /* Re enable the Bus Off interrupt of the requested CAN node */
          NodeRegAddressPtr->IE.B.BOE = CAN_ONE;
        }

    }

#if ((CAN_ID_CONFIG_TYPE == CAN_ID_STANDARD)||  \
                                     (CAN_ID_CONFIG_TYPE == CAN_ID_MIXED))
  /* Set SID filter list Address */
  CanSIDPtr = Can_kConfigPtr->CanSIDFilterConfigPtr;

  /* Set with first SID filter Index */
  SIDFiltrStartIndx = Can_kConfigPtr->
                CanControllerConfigPtr[Controller].ControllerMOMap[CAN_TWO];

  /* Set with End SID filter Index */
  SIDFiltrEndIndx = Can_kConfigPtr->
               CanControllerConfigPtr[Controller].ControllerMOMap[CAN_THREE];

  /* Read Standard Identifier filter Start address */
  SIDFilterStartAddr = Can_kConfigPtr->
    CanControllerMsgRAMMapConfigPtr[Controller].ControllerMsgRAMMap[CAN_ZERO];

  /* Set Offset with First element*/
  SIDOffsetIndx = CAN_ZERO;

    /* Set with all standard filter configuration */
  for(SIDFiltrIndx = SIDFiltrStartIndx; SIDFiltrIndx <
                        (SIDFiltrStartIndx + SIDFiltrEndIndx); SIDFiltrIndx++)
    {
       /* Set with Address of  filter element */
       SIDFilterRealAddr = SIDFilterStartAddr +
                                      ((uint32)SIDOffsetIndx * CAN_RAM_BYTES);

      /* MISRA2012_RULE_11_6_JUSTIFICATION: The pointer cast is used to
        cast the address of Standard filter Type to the standard filter
        elements  structure type  */
      /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and
       integer type. Permitted for special function registers.*/
      /* Set with First filter element */
      SIDFilterPtr = (Ifx_CAN_STDMSG*)SIDFilterRealAddr;

       if(CAN_FALSE == CanSIDPtr[SIDFiltrIndx].SIDPretendedSupport)
       {

        if(CAN_RX_FIFO1 == CanSIDPtr[SIDFiltrIndx].SIDBufferType)
         {
           /* Set to store in RXFIO1 */
           SIDFilterPtr->S0.B.SFEC = CAN_TWO;
         }
         else if(CAN_RX_FIFO0 == CanSIDPtr[SIDFiltrIndx].SIDBufferType)
         {
            /* Set to store in RXFIO0 */
           SIDFilterPtr->S0.B.SFEC = CAN_ONE;
         }
         else
         {
            /* Set to store in RX Dedicated buffer */
           SIDFilterPtr->S0.B.SFEC = CAN_SEVEN;
         }

       }

      /* increment to access next element */
      SIDOffsetIndx++;

    }
#endif

#if ((CAN_ID_CONFIG_TYPE == CAN_ID_EXTENDED)||  \
                                       (CAN_ID_CONFIG_TYPE == CAN_ID_MIXED))
  /* Set with XID filter list configuration address */
  CanXIDPtr = Can_kConfigPtr->CanXIDFilterConfigPtr;

  /* Read Extended Identifier filter Start address */
  XIDFilterStartAddr = Can_kConfigPtr->
    CanControllerMsgRAMMapConfigPtr[Controller].ControllerMsgRAMMap[CAN_ONE];
  /* Set with start Index */
  XIDFiltrStartIndx = Can_kConfigPtr->
                      CanControllerConfigPtr[Controller].XIDFilterPos;
  /* Set with end Index */
  XIDFiltrEndIndx = Can_kConfigPtr->
                    CanControllerConfigPtr[Controller].XIDFilterNoOfConfig;
  /* Set Offset with first element */
  XIDOffsetIndx = CAN_ZERO;

    /* Set with all Extended filter configuration */
  for(XIDFiltrIndx = XIDFiltrStartIndx; XIDFiltrIndx <
                       (XIDFiltrStartIndx + XIDFiltrEndIndx); XIDFiltrIndx++)
    {
     /* Set with offset of XID filter element */
     XIDFilterRealAddr = XIDFilterStartAddr +
                                  ((uint32)CAN_EIGHT * (uint32)XIDOffsetIndx);

    /* MISRA2012_RULE_11_6_JUSTIFICATION: The pointer cast is used to
      cast the address of extended filter type to the extended filter
      elements  structure type  */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and
       integer type. Permitted for special function registers.*/
     /* Set with First filter element */
      XIDFilterPtr = (Ifx_CAN_EXTMSG*) XIDFilterRealAddr;

      if(CAN_FALSE == CanXIDPtr[XIDFiltrIndx].XIDPretendedSupport)
      {

        if(CAN_RX_FIFO1 == CanXIDPtr[XIDFiltrIndx].XIDBufferType)
        {
          /* Set to store in RXFIO1 */
          XIDFilterPtr->F0.B.EFEC = CAN_TWO;
        }
        else if(CAN_RX_FIFO0 == CanXIDPtr[XIDFiltrIndx].XIDBufferType)
        {
           /* Set to store in RXFIO0 */
          XIDFilterPtr->F0.B.EFEC = CAN_ONE;
        }
        else
        {
           /* Set to store in RX Dedicated buffer */
          XIDFilterPtr->F0.B.EFEC = CAN_SEVEN;
        }

      }

      /* increment to access next element */
      XIDOffsetIndx++;

    }
#endif
  /* Disable configuration change mode */
  NodeRegAddressPtr->CCCR.B.CCE = CAN_ZERO;
  /* Set with normal operation mode */
  NodeRegAddressPtr->CCCR.B.INIT = CAN_ZERO;

  /* Set with First index value */
  MsgIndex = IcomMsgIndex;

  while(MsgIndex < (IcomMsgIndex + IcomNoOfRxMsg))
  {
    /* Clear Msg Counter values */
    Can_17_McmCan_IcomMsgCntrVal[MsgIndex] = CAN_ZERO;
    /* Increment message counter index */
    MsgIndex++;
  }

  /* Clear the ICOM Wake on bus off status */
  Can_17_McmCan_IcomConfgBOStatus[Controller] = CAN_FALSE;
  /* Set the pretended network status for the current CAN controller */
  Can_17_McmCan_IcomEnableStatus[Controller] = CAN_FALSE;
  /* Clear ICOM Configuration ID */
  Can_17_McmCan_ActiveIcomCfgId[Controller] = CAN_ZERO;

}

/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           :  static Std_ReturnType Can_lIcomValidateMsg             **
**                     (                                                      **
**                        const Can_HwType* Mailbox,                          **
**                        const PduInfoType* PduInfoPtr                       **
**                     )                                                      **
**                                                                            **
** Description      : Validates the received message against configured       **
**                    wakeup conditions .                                     **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Mailbox    : Included Received Message ID,HOH           **
**                                 and Controller Id                          **
**                    PduInfoPtr : Included SDU length and Data pointer       **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : E_OK : The WakeUp condition is caused                   **
**                    E_NOT_OK : The WakeUp condition is not caused           **
**                                                                            **
*******************************************************************************/
static void Can_lIcomValidateMsg(const Can_HwType* Mailbox,
                                    const PduInfoType* PduInfoPtr)
{
  Can_IdType IcomRxMsgId;
  uint16 IcomMsgIndex;
  uint16 MsgIndex;
  uint16 IcomNoOfRxMsg;
  uint8 IcomConfigId;
  uint8 ControllerId;
  Std_ReturnType ApiStatus;
  Std_ReturnType WakeupCheckStatus;
  /* Set with Controller Configuration Id */
  ControllerId = Mailbox->ControllerId;
  /* Initialize the Return status */
  ApiStatus =  E_NOT_OK;
  /* Set  wakeup cause is not considered */
  WakeupCheckStatus =  E_OK;
  /* Get ICOM configuration ID*/
  IcomConfigId = Can_17_McmCan_ActiveIcomCfgId[ControllerId];
  /* Get the first receive configuration index */
  IcomMsgIndex =
    Can_kConfigPtr->CanIcomConfigPtr[IcomConfigId - CAN_ONE].IcomFirstMsgIndx;

  /* Get the total number of ICOM Receive messages configured*/
  IcomNoOfRxMsg =
    Can_kConfigPtr->CanIcomConfigPtr[IcomConfigId - CAN_ONE].IcomNoOfMsgIndx;

  /* Set with First index value */
  MsgIndex = IcomMsgIndex;

  while(MsgIndex < (IcomMsgIndex + IcomNoOfRxMsg))
    {

  /* Set with Icom Rx message Id */
#if ((CAN_ID_CONFIG_TYPE == CAN_ID_EXTENDED)||  \
                            (CAN_ID_CONFIG_TYPE == CAN_ID_MIXED))

     IcomRxMsgId = Mailbox->CanId & ~(CAN_SET_XTD_BIT_MASK);
#else
      /* Set with same receive Id */
      IcomRxMsgId = Mailbox->CanId;
#endif
      /* check if CanIcomMessageIdMask is configured */
      if(CAN_MSG_MASK_VAL != Can_kConfigPtr->
                                    CanIcomMsgConfigPtr[MsgIndex].IcomMaskRef)
        {
          /* Mask the received message ID with the ICOM Message Id mask */
          IcomRxMsgId &= (Can_kConfigPtr->
                                 CanIcomMsgConfigPtr[MsgIndex].IcomMaskRef);
        }

        /* Compare Masked id with configured Id */
        if(IcomRxMsgId == Can_kConfigPtr->
                                      CanIcomMsgConfigPtr[MsgIndex].IcomMsgId)
        {

          /* Check counter value is configured or not */
          if(CAN_ZERO !=
                   Can_kConfigPtr->CanIcomMsgConfigPtr[MsgIndex].IcomCntrVal)
          {

            /* Increment Message Counter Value */
            Can_17_McmCan_IcomMsgCntrVal[MsgIndex]++;

           /* Set wakeup cause condition check is configured */
           WakeupCheckStatus = E_NOT_OK;

            /* Check if the message with the ID is received n times on the
            communication channel.
            */
            if(Can_kConfigPtr->CanIcomMsgConfigPtr[MsgIndex].IcomCntrVal ==
                                   Can_17_McmCan_IcomMsgCntrVal[MsgIndex])
            {
              /* Set Status as Wakeup condition cause */
              ApiStatus = E_OK;
            }

          }

          /* Check payload length error is configured */
          if((CAN_TRUE == Can_kConfigPtr->
                                 CanIcomMsgConfigPtr[MsgIndex].IcomLengthErr) &&
                                 (E_OK != ApiStatus))
          {

           /* Set wakeup cause condition check is configured */
           WakeupCheckStatus = E_NOT_OK;

            /* Compare payload length(DLC)and if mismatch set as wake-up */
            if( PduInfoPtr-> SduLength != Can_kConfigPtr->
                          CanIcomMsgConfigPtr[MsgIndex].IcomDLC)
            {
              /* Set Status as Wakeup condition cause */
              ApiStatus = E_OK;
            }

          }

          /* Compare masked ID with message Id */
          if ((E_OK != ApiStatus) && (CAN_ZERO !=
           Can_kConfigPtr->CanIcomMsgConfigPtr[MsgIndex].IcomNoOfSignalIndx))
          {
           /* Set wakeup cause condition check is configured */
           WakeupCheckStatus = E_NOT_OK;
           /* Invoke function for Message signal validation */
           ApiStatus = Can_lIcomValidateMsgSignal(MsgIndex,PduInfoPtr);
          }
          /* Check any of the wakeup condition is configured */
          if(E_OK == WakeupCheckStatus)
          {
           /* The  condition is considered as wakeup caused */
           ApiStatus = E_OK;
          }

        }

        /* Set Exit condition if Wakeup Cause is enabled */
        if(E_OK == ApiStatus)
        {
          /* Call CanIf_RxIndication received message matches the wakeup */
          CanIf_RxIndication(Mailbox,PduInfoPtr);

          /* Set Exit Condition */
          MsgIndex = (IcomMsgIndex + IcomNoOfRxMsg);
        }

        /* Increment to point next Message configuration*/
        MsgIndex++;

    }

}

/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           :  static Std_ReturnType Can_lIcomValidateMsgSignal       **
**                     (                                                      **
**                        uint16 MessageIndex,                                **
**                        const PduInfoType* PduInfoPtr                       **
**                     )                                                      **
**                                                                            **
** Description      : Validates the received message Signal values against the**
**                    configured wakeup conditions.                           **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : MessageIndex : Signal Wakeup cause check corresponding  **
**                                   Message configuration index              **
**                    PduInfoPtr   : Pointer to the information of received   **
**                                   LPDU                                     **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : E_OK : The WakeUp condition is caused                   **
**                    E_NOT_OK : The WakeUp condition is not caused           **
**                                                                            **
*******************************************************************************/
static Std_ReturnType Can_lIcomValidateMsgSignal( uint16 MessageIndex,
                                           const PduInfoType* PduInfoPtr
                                                 )
{
  uint32 SignalIndex;
  uint16 FirstSignalIndex;
  uint16 NoOfMsgSignal;
  uint8 DataIndex;
  uint8 CheckIndex;
  uint8 TempData[CAN_EIGHT];
  Std_ReturnType ApiStatus;

  /* Initialize the temporary array */
  for (DataIndex=CAN_ZERO; DataIndex < CAN_EIGHT; DataIndex++)
    {
      TempData[DataIndex] = CAN_ZERO;
    }

  /* Initialize the Return status */
  ApiStatus =  E_NOT_OK;
  /* First signal index */
  FirstSignalIndex = Can_kConfigPtr->
                        CanIcomMsgConfigPtr[MessageIndex].IcomFirstSignalIndx;

  /* No of signal configuration */
  NoOfMsgSignal = Can_kConfigPtr->
                         CanIcomMsgConfigPtr[MessageIndex].IcomNoOfSignalIndx;

  /* Message signal validation */
  for (SignalIndex=FirstSignalIndex; SignalIndex <
           ((uint32)FirstSignalIndex+(uint32)NoOfMsgSignal); SignalIndex++)
    {
      /*Initialize check index */
      CheckIndex = CAN_ZERO;

      for (DataIndex=CAN_ZERO; DataIndex < CAN_EIGHT; DataIndex++)
        {
          /* Mask the received payload and signal mask value */
          TempData[DataIndex] = (PduInfoPtr->SduDataPtr[DataIndex]
          &(Can_kConfigPtr->CanIcomRxSignalConfigPtr[SignalIndex].
                                  IcomSignalMask[DataIndex]));
            /* Get the Signal operation */
            switch (Can_kConfigPtr->CanIcomRxSignalConfigPtr[SignalIndex].
                    IcomSignalOper)
            {

              case CAN_ICOM_OPER_AND:
              {
                 /* Verify the signal value and masked payload data */
                 if (CAN_ZERO != (TempData[DataIndex]&
                 (Can_kConfigPtr->CanIcomRxSignalConfigPtr[FirstSignalIndex].
                                  IcomSignalValue[DataIndex])))
                   {
                     ApiStatus = E_OK;
                   }
              }
              break;

              case CAN_ICOM_OPER_EQUAL:
              {

                 /* Verify the signal value and masked payload data */
                 if (TempData[DataIndex] ==
                   (Can_kConfigPtr->CanIcomRxSignalConfigPtr[FirstSignalIndex].
                   IcomSignalValue[DataIndex]))
                   {
                     CheckIndex++;
                   }
                 if(CheckIndex == CAN_EIGHT)
                   {
                      ApiStatus = E_OK;
                   }

              }
              break;

              case CAN_ICOM_OPER_GREATER:
              {
                 /* Verify the signal value and masked payload data */
                 if (TempData[DataIndex] >
                   (Can_kConfigPtr->CanIcomRxSignalConfigPtr[FirstSignalIndex].
                   IcomSignalValue[DataIndex]))
                   {
                     ApiStatus = E_OK;
                   }

              }
              break;

              case CAN_ICOM_OPER_SMALLER:
              {
                 /* Verify the signal value and masked payload data */
                 if (TempData[DataIndex] <
                   (Can_kConfigPtr->CanIcomRxSignalConfigPtr[FirstSignalIndex].
                    IcomSignalValue[DataIndex]))
                   {
                     ApiStatus = E_OK;
                   }

              }
              break;

              default:
              {

                 /* Verify the signal value and masked payload data */
                if (CAN_ZERO != ((uint8)(~(TempData[DataIndex]))&(uint8)
                 (~(Can_kConfigPtr->CanIcomRxSignalConfigPtr[FirstSignalIndex].
                                     IcomSignalValue[DataIndex]))))
                   {
                     ApiStatus = E_OK;
                   }
              }
              break;

            }

        }

    }
    return ApiStatus;
}
#endif

/*******************************************************************************
            DET condition check internal functions
*******************************************************************************/

/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : LOCAL_INLINE Std_ReturnType Can_lModeDetCheck           **
**                    (                                                       **
**                       uint8 Controller,                                    **
**                       Can_StateTransitionType Transition                   **
**                     )                                                      **
**                                                                            **
** Description      : Checks the validity of software triggered CAN           **
**                    Controller state transition                             **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : Controller - Associated CAN Controller Id               **
**                    Transition - Requested transition                       **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : E_OK - Valid transition                                 **
**                    E_NOT_OK - Invalid transition                           **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE Std_ReturnType Can_lModeDetCheck(uint8 Controller,
                                        Can_StateTransitionType Transition)
{
  Std_ReturnType ApiStatus;
  ApiStatus = E_OK;

  switch (Transition)
    {

      case CAN_T_START :
      {
        /* Check if current mode is not STOPPED */
        if (Can_17_McmCan_ControllerMode[Controller] != CANIF_CS_STOPPED)
          {
            ApiStatus = E_NOT_OK;
          }
      }
      break;

      case CAN_T_SLEEP :
      {
        /* if current mode is neither SLEEP nor STOPPED */
        if((Can_17_McmCan_ControllerMode[Controller] != CANIF_CS_SLEEP) &&
            (Can_17_McmCan_ControllerMode[Controller] != CANIF_CS_STOPPED))
          {
            ApiStatus = E_NOT_OK;
          }
      }
      break;

      case CAN_T_STOP :
      {
        /* if current mode is neither STARTED nor STOPPED */
        if((Can_17_McmCan_ControllerMode[Controller] != CANIF_CS_STARTED) &&
            (Can_17_McmCan_ControllerMode[Controller] != CANIF_CS_STOPPED))
          {
            ApiStatus = E_NOT_OK;
          }

      }
      break;

      case CAN_T_WAKEUP :
      {
        /* if current mode is neither SLEEP nor STOPPED */
        if((Can_17_McmCan_ControllerMode[Controller] != CANIF_CS_SLEEP) &&
            (Can_17_McmCan_ControllerMode[Controller] != CANIF_CS_STOPPED))
          {
            ApiStatus = E_NOT_OK;
          }
      }
      break;

      default:
      {
        /* Invalid state is requested */
        ApiStatus = E_NOT_OK;
      }
      break;

    }

#if(CAN_DEV_ERROR_DETECT == STD_ON)

  if(E_NOT_OK == ApiStatus)
    {


      /* Report invalid transition request to DET */
      Det_ReportError(CAN_17_MCMCAN_MODULE_ID, CAN_17_MCMCAN_INSTANCE_ID,
                      CAN_SID_SETCONTROLLERMODE, CAN_E_TRANSITION);
    }

#endif

  return ApiStatus;
}

#if (CAN_TX_PROCESS_ENABLED == STD_ON)
/*CYCLOMATIC_Can_lWriteDetCheck_JUSTIFICATION: This Function has cyclomatic
Complexity of 19 which is handling only the DET check related with write
function so this will never affect functionality.
*/
/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : Std_ReturnType Can_lWriteDetCheck                       **
**                    (                                                       **
**                       Can_HwHandleType Hth,                                **
**                       const Can_PduType *PduInfo                           **
**                    )                                                       **
**                                                                            **
** Description      : Handles DET checks for Can_17_McmCan_Write API          **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : Hth - Hardware Transmit Handler                         **
**                    PduInfo - Pointer to SDU user memory, DLC and Identifier**
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : E_OK - No Development Error                             **
**                    E_NOT_OK - Development Error detected and reported      **
**                                                                            **
*******************************************************************************/
static Std_ReturnType Can_lWriteDetCheck(Can_HwHandleType Hth,
                                                 const Can_PduType *PduInfo)
{

#if (CAN_FD_ENABLE == STD_ON)
 const Ifx_CAN_N *NodeRegAddressPtr;
 const Can_TxHwObjectConfigType *TxObjPtr;
#endif

  Can_HwHandleType HthIndex;

#if (CAN_FD_ENABLE== STD_ON)
  uint8 ControllerId;
#endif

  Std_ReturnType ApiStatus = E_OK;

  boolean TrigStatus;

#if (CAN_FD_ENABLE == STD_ON)
  /* Set with TX object configuration start index */
  TxObjPtr = Can_kConfigPtr->CanTxHwObjectConfigPtr;
#endif

  /* Extract HTH index for accessing corresponding configuration */
#if (CAN_RX_PROCESS_ENABLED == STD_ON)

  if((Hth <(Can_HwHandleType) CAN_NOOF_RX_HARDWARE_OBJECTS ) ||(Hth >=
  (Can_HwHandleType)(CAN_NOOF_TX_HARDWARE_OBJECTS +
                                        CAN_NOOF_RX_HARDWARE_OBJECTS)))
  {
    ApiStatus = E_NOT_OK;
  }
#else
  if(Hth >= CAN_NOOF_TX_HARDWARE_OBJECTS)
  {
     ApiStatus = E_NOT_OK;
  }
#endif /* #if (CAN_NOOF_RX_HARDWARE_OBJECTS != STD_OFF) */

 if(E_NOT_OK == ApiStatus)
 {
 #if(CAN_DEV_ERROR_DETECT == STD_ON)
       /* Report to DET */
       Det_ReportError(CAN_17_MCMCAN_MODULE_ID, CAN_17_MCMCAN_INSTANCE_ID,
                       CAN_SID_WRITE, CAN_E_PARAM_HANDLE);
 #endif
 }
  /* Check if PduInfo is a null pointer */
 else if (PduInfo == NULL_PTR)
 {
#if(CAN_DEV_ERROR_DETECT == STD_ON)
      /* Report to DET */
      Det_ReportError(CAN_17_MCMCAN_MODULE_ID, CAN_17_MCMCAN_INSTANCE_ID,
                      CAN_SID_WRITE, CAN_E_PARAM_POINTER);
#endif

      ApiStatus = E_NOT_OK;
 }
#if (CAN_FD_ENABLE == STD_OFF)
  /* check if DLC is greater than 8 */
 else if (PduInfo->length > CAN_MAX_DATA_LENGTH )
 {
#if(CAN_DEV_ERROR_DETECT == STD_ON)
      /* Report to DET */
      Det_ReportError(CAN_17_MCMCAN_MODULE_ID, CAN_17_MCMCAN_INSTANCE_ID,
                                            CAN_SID_WRITE, CAN_E_PARAM_DLC);
#endif

      /* The DLC length is > 8 */
      ApiStatus = E_NOT_OK;
 }
#else
 else if (PduInfo->length > CAN_MAX_FD_LENGTH)
 {
#if(CAN_DEV_ERROR_DETECT == STD_ON)
      /* Report to DET */
      Det_ReportError(CAN_17_MCMCAN_MODULE_ID, CAN_17_MCMCAN_INSTANCE_ID,
                      CAN_SID_WRITE, CAN_E_PARAM_DLC);
#endif
      /* The DLC length is > 64 */
      ApiStatus = E_NOT_OK;
 }
#endif

 else
 {
#if (CAN_FD_ENABLE == STD_ON)

   if (PduInfo->length > CAN_MAX_DATA_LENGTH)
        {

      /* Extract HTH index for accessing corresponding configuration */
#if (CAN_RX_PROCESS_ENABLED == STD_ON)
      HthIndex = Hth - CAN_NOOF_RX_HARDWARE_OBJECTS;
#else
      HthIndex = Hth;
#endif /* #if (CAN_NOOF_RX_HARDWARE_OBJECTS != STD_OFF) */

          /* Set with the associated controller of requested HTH */
          ControllerId = TxObjPtr[HthIndex].HwControllerId;

          /* Controller Node Address */
          NodeRegAddressPtr = Can_kConfigPtr->
                     CanControllerConfigPtr[ControllerId].CanNodeAddress;

          /* Check the controller with FD mode */
          if( CAN_BIT_SET_VAL != NodeRegAddressPtr->CCCR.B.FDOE)
            {

#if(CAN_DEV_ERROR_DETECT == STD_ON)
              /* Report to DET */
              Det_ReportError(CAN_17_MCMCAN_MODULE_ID,
              CAN_17_MCMCAN_INSTANCE_ID, CAN_SID_WRITE, CAN_E_PARAM_DLC);
#endif
              /* Set controller without FD mode while FD request */
              ApiStatus = E_NOT_OK;
            }
          else
            {

              if(CAN_ID_FD_ENABLE_SET != (PduInfo->id & CAN_ID_FD_ENABLE_SET))
                {

#if(CAN_DEV_ERROR_DETECT == STD_ON)
                  /* Report to DET */
                  Det_ReportError(CAN_17_MCMCAN_MODULE_ID,
                  CAN_17_MCMCAN_INSTANCE_ID, CAN_SID_WRITE, CAN_E_PARAM_DLC);
#endif

                  /* Set when controller in FD mode and DLC>8,but Id flag is
                  not set properly
                  */
                  ApiStatus = E_NOT_OK;
                }

            }

        }
        else
        {
          /* Do nothing */
        }

#endif
 }

      /* Check if sdu is a null pointer */
  if (E_OK == ApiStatus)
    {
      /* Extract HTH index for accessing corresponding configuration */
#if (CAN_RX_PROCESS_ENABLED == STD_ON)
      HthIndex = (Can_HwHandleType)(Hth - CAN_NOOF_RX_HARDWARE_OBJECTS);
#else
      HthIndex = Hth;
#endif /* #if (CAN_NOOF_RX_HARDWARE_OBJECTS != STD_OFF) */


        /* Check requested Id Type is same as with HTH CanIdType */
        if((uint8)CAN_ID_EXTENDED == Can_kConfigPtr->
                         CanTxHwObjectConfigPtr[HthIndex].HwObjIdType)
        {
          /* Check Id type is extended or not */
          if(CAN_SET_XTD_BIT_MASK != (PduInfo->id & CAN_SET_XTD_BIT_MASK))
          {

#if(CAN_DEV_ERROR_DETECT == STD_ON)
          /* Report to DET */
          Det_ReportError(CAN_17_MCMCAN_MODULE_ID, CAN_17_MCMCAN_INSTANCE_ID,
                          CAN_SID_WRITE, CAN_E_PARAM_MSGID);
#endif
          /* Requested with not supported CanId Type message  */
          ApiStatus = E_NOT_OK;
          }

        }
        else if((uint8)CAN_ID_STANDARD == Can_kConfigPtr->
                            CanTxHwObjectConfigPtr[HthIndex].HwObjIdType)
        {
          /* Check Id type is extended or not */
          if(CAN_SET_XTD_BIT_MASK == (PduInfo->id & CAN_SET_XTD_BIT_MASK))
          {

#if(CAN_DEV_ERROR_DETECT == STD_ON)
          /* Report to DET */
          Det_ReportError(CAN_17_MCMCAN_MODULE_ID, CAN_17_MCMCAN_INSTANCE_ID,
                          CAN_SID_WRITE, CAN_E_PARAM_MSGID);
#endif
          /* Requested with not supported CanId Type message  */
          ApiStatus = E_NOT_OK;
          }

        }
        else
        {
          /* Do nothing */
        }
        if(E_OK == ApiStatus)
        {
          /* Read requested HTH is with trigger transmit API is enabled  */
           TrigStatus = Can_kConfigPtr->
                   CanTxHwObjectConfigPtr[HthIndex].TriggerTransmitStatus;

          /* Check Trigger status */
          if((CAN_FALSE == TrigStatus) && (NULL_PTR == PduInfo->sdu))
          {

#if(CAN_DEV_ERROR_DETECT == STD_ON)
            /* Report to DET */
            Det_ReportError(CAN_17_MCMCAN_MODULE_ID, CAN_17_MCMCAN_INSTANCE_ID,
                            CAN_SID_WRITE, CAN_E_PARAM_POINTER);
#endif
            /* Trigger transmit API is disabled for the requested HTH */
            ApiStatus = E_NOT_OK;
          }

        }

    }

  return ApiStatus;

}
#endif

/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : LOCAL_INLINE Std_ReturnType Can_lReportDetUninit        **
**                    (                                                       **
**                      uint8 ServiceId                                       **
**                    )                                                       **
**                                                                            **
** Description      : Checks the status of CAN driver initialization          **
**                    If CAN driver is not initialized, reports to DET and    **
**                    return with E_NOT_OK                                    **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : ServiceId - Service Id of the calling API               **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : Std_ReturnType                                          **
**                  - E_OK: CAN Driver is initialized                         **
**                  - E_NOT_OK: CAN Driver is not initialized                 **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE Std_ReturnType Can_lReportDetUninit(uint8 ServiceID)
{
  Std_ReturnType ApiStatus;

  /* Check if CAN driver is un-initialized */
  if(CAN_UNINIT == Can_17_McmCan_DriverState)
    {

#if(CAN_DEV_ERROR_DETECT == STD_ON)
      /* Report to DET */
      Det_ReportError(CAN_17_MCMCAN_MODULE_ID, CAN_17_MCMCAN_INSTANCE_ID,
                      ServiceID, CAN_E_UNINIT);
#else
     /* Invoke Warning avoid function */
     UNUSED_PARAMETER(ServiceID);
#endif

      /* Set as Drv state is not Initialized*/
      ApiStatus = E_NOT_OK;

    }
  else
    {
      /* Set as Drv state as Initialized*/
      ApiStatus = E_OK;
    }

  return ApiStatus;

}

/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : static Std_ReturnType Can_lReportDetParamController     **
**                    (                                                       **
**                      uint8 ControllerId,                                   **
**                      uint8 ServiceId                                       **
**                    )                                                       **
**                                                                            **
** Description      : Checks if ControllerId is a valid CAN Controller Id     **
**                    If ControllerId is not valid, then report to DET and    **
**                    return with E_NOT_OK                                    **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : ControllerId - Associated CAN Controller Id             **
**                    ServiceId - Service Id of the calling API               **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : Std_ReturnType                                          **
**                   - E_OK: ControllerId is valid                            **
**                   - E_NOT_OK: ControllerId is invalid                      **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE Std_ReturnType Can_lReportDetParamController(uint8 Controller,
                                                               uint8 ServiceID)
{
  Std_ReturnType ApiStatus;

  /* Check 'ControllerId' is out of range */
  if(Controller >= CAN_NOOF_CONTROLLER)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)

      /* Report to DET */
      Det_ReportError(CAN_17_MCMCAN_MODULE_ID, CAN_17_MCMCAN_INSTANCE_ID,
                                      ServiceID, CAN_E_PARAM_CONTROLLER);

#else

     /* Invoke Warning avoid function */
     UNUSED_PARAMETER(ServiceID);

#endif

      /* Set as requested controller ID is Invalid */
      ApiStatus = E_NOT_OK ;

    }
  else
    {
      /* Set as controllerID is valid*/
      ApiStatus = E_OK;
    }

  return ApiStatus;

}

/*******************************************************************************
            Interrupt Handler
*******************************************************************************/

#if(CAN_TX_INTERRUPT_PROCESSING == STD_ON)
/*******************************************************************************
** Traceability: [cover parentID]                                             **
**                                                                            **
** Syntax           : void Can_17_McmCan_IsrTransmitHandler                   **
**                    (                                                       **
**                      uint8 KernelIdIndx                                    **
**                    )                                                       **
**                                                                            **
** Description      : - This is the interrupt service routine for Handling    **
**                      transmit interrupt by dedicated or Tx Queue.          **
**                      This function checks the CAN Controller Tx interrupt  **
**                      status and and if available then call appropriate     **
**                      handler function                                      **
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
void Can_17_McmCan_IsrTransmitHandler(uint8 HwKernelId)
{
  Ifx_CAN_N *NodeRegAddressPtr;
  uint8 NodeIndx;
  uint8 CntrlIndx;

  /* Read no of Activated nodes and set loop with it */
  for(NodeIndx = CAN_ZERO; NodeIndx <
      (Can_kConfigPtr-> CanMCMModuleConfigPtr[HwKernelId].NoOfActiveNodes);
                                                   NodeIndx++)
    {

      /* Set Controller Index */
      CntrlIndx = Can_kConfigPtr->
               CanMCMModuleConfigPtr[HwKernelId].CanUsedHwCfgIndx[NodeIndx];

      /* Check the controller mode is Interrupt or not */
      if(CAN_POLLING != Can_kConfigPtr->
          CanEventHandlingConfigPtr[CntrlIndx].CanEventType[CAN_ZERO])
        {

          /* Set with Node Register Start address */
          NodeRegAddressPtr = Can_kConfigPtr->
                             CanControllerConfigPtr[CntrlIndx].CanNodeAddress;

          /* Check if Tx Event FIFO New Entry is stored */
          if(CAN_BIT_SET_VAL == NodeRegAddressPtr->IR.B.TEFN)
            {

#if(CAN_TX_PROCESS_ENABLED == STD_ON)

              /* Enter Critical Section */
              SchM_Enter_Can_17_McmCan_CanWrMO();
              /* Request for the Transmission from the prviously store info */
              NodeRegAddressPtr->TX.BAR.U |= Can_TxBufAddReq[CntrlIndx];
              /* Clear the previously stored info regarding Transmission
              requests */
              Can_TxBufAddReq[CntrlIndx] = CAN_DATA_ZERO;
              /* Exit Critical Section */
              SchM_Exit_Can_17_McmCan_CanWrMO();

              /* If New Event Entry is present then invoke Tx handler */
              Can_lTxEventHandler(CntrlIndx);
#endif

              /* Reset flag for next TxEvent Entry */
              NodeRegAddressPtr->IR.U = CAN_CLEAR_IE_TEFN_BIT;
            }

        }

    }

}
#endif

#if(CAN_RX_INTERRUPT_PROCESSING == STD_ON)
#if(CAN_RX_PROCESS_ENABLED == STD_ON)
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
void Can_17_McmCan_IsrReceiveHandler(uint8 HwKernelId)
{
  Ifx_CAN_N *NodeRegAddressPtr;
  uint8 NodeIndx;
  uint8 CntrlIndx;

  /* Read no of Activated nodes and set loop with it */
  for(NodeIndx = CAN_ZERO; NodeIndx <
      (Can_kConfigPtr-> CanMCMModuleConfigPtr[HwKernelId].NoOfActiveNodes);
      NodeIndx++)
    {
      /* Set Controller Index */
      CntrlIndx = Can_kConfigPtr->
                 CanMCMModuleConfigPtr[HwKernelId].CanUsedHwCfgIndx[NodeIndx];

      /* Check the controller mode is Interrupt or not */
      if(CAN_POLLING != Can_kConfigPtr->
                    CanEventHandlingConfigPtr[CntrlIndx].CanEventType[CAN_ONE])
        {
          /* Set with Node Register Start address */
          NodeRegAddressPtr = Can_kConfigPtr->
                              CanControllerConfigPtr[CntrlIndx].CanNodeAddress;

          /* Check if any of the Message stored to Dedicated Rx Buffer */
          if(CAN_BIT_SET_VAL == NodeRegAddressPtr->IR.B.DRX)
            {

              /* If current state is START Invoke receive handler function */
              if(CANIF_CS_STARTED == Can_17_McmCan_ControllerMode[CntrlIndx])
                {
                  /* Enter Critical Section */
                  SchM_Enter_Can_17_McmCan_CanWrMO();
                  /* Request for the Transmission from the prviously store
                  info */
                  NodeRegAddressPtr->TX.BAR.U |= Can_TxBufAddReq[CntrlIndx];
                  /* Clear the previously stored info regarding Transmission
                  requests */
                  Can_TxBufAddReq[CntrlIndx] = CAN_DATA_ZERO;
                  /* Exit Critical Section */
                  SchM_Exit_Can_17_McmCan_CanWrMO();
                  /* Call receive handler with buffer type as dedicated */
                  Can_lReceiveHandler(CntrlIndx,CAN_ONE);
                }

#if(CAN_WAKEUP_CONFIGURED == STD_ON)
              /* If SLEEP state invoke function wakeup handler for wakeup
              processing */
              if(CANIF_CS_SLEEP == Can_17_McmCan_ControllerMode[CntrlIndx])
                {
                  Can_lWakeupHandler(CntrlIndx);
                }
#endif

              /* Reset flag for next message reception */
             NodeRegAddressPtr->IR.U = CAN_CLEAR_IE_DRX_BIT;
            }

        }

    }

}

#endif
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
void Can_17_McmCan_IsrRxFIFOHandler (uint8 HwKernelId)
{
  Ifx_CAN_N *NodeRegAddressPtr;
  uint8 NodeIndx;
  uint8 CntrlIndx;
#if(CAN_WAKEUP_CONFIGURED == STD_ON)
  Std_ReturnType WakeUpFlag;
  /* Set Wakeup flag with not wakeup indication */
  WakeUpFlag = E_NOT_OK;
#endif

  /* Read no of Activated nodes and set loop with it */
  for(NodeIndx = CAN_ZERO; NodeIndx <
        (Can_kConfigPtr-> CanMCMModuleConfigPtr[HwKernelId].NoOfActiveNodes);
                                                              NodeIndx++)
    {
      /* Set Controller Index */
      CntrlIndx = Can_kConfigPtr->
               CanMCMModuleConfigPtr[HwKernelId].CanUsedHwCfgIndx[NodeIndx];

      /* Check the controller mode is Interrupt or not */
      if(CAN_POLLING != Can_kConfigPtr->
                   CanEventHandlingConfigPtr[CntrlIndx].CanEventType[CAN_ONE])
        {
          /* Set with Node Register Start address */
          NodeRegAddressPtr = Can_kConfigPtr->
                              CanControllerConfigPtr[CntrlIndx].CanNodeAddress;

#if(CAN_RXFIFO0_ENABLED == STD_ON)
          /* Check if any of the New message written to Rx FIFO 0 */
          if(CAN_BIT_SET_VAL == NodeRegAddressPtr->IR.B.RF0W)
            {

              /* If current state is STARTED Invoke receive handler function */
              if(CANIF_CS_STARTED == Can_17_McmCan_ControllerMode[CntrlIndx])
                {

                  /* Enter Critical Section */
                  SchM_Enter_Can_17_McmCan_CanWrMO();
                  /* Request for the Transmission from the prviously store
                  info */
                  NodeRegAddressPtr->TX.BAR.U |= Can_TxBufAddReq[CntrlIndx];
                  /* Clear the previously stored info regarding Transmission
                  requests */
                  Can_TxBufAddReq[CntrlIndx] = CAN_DATA_ZERO;
                  /* Exit Critical Section */
                  SchM_Exit_Can_17_McmCan_CanWrMO();
                  /* Call receive handler with buffer type as RXFIFO0 */
                  Can_lReceiveHandler(CntrlIndx,CAN_TWO);
                }
#if(CAN_WAKEUP_CONFIGURED == STD_ON)
                else
                {
                  /* Set Wakeup Flag as True */
                  WakeUpFlag = E_OK;
                }
#endif
              /* Reset flag for New message to RXFIFO0 */
              NodeRegAddressPtr->IR.U = CAN_CLEAR_IE_RF0W_BIT;
            }

#endif /* #if(CAN_RXFIFO1_ENABLED == STD_ON) */

#if(CAN_RXFIFO1_ENABLED == STD_ON)
          /* Check if any of the New message written to Rx FIFO 1 */
          if(CAN_BIT_SET_VAL == NodeRegAddressPtr->IR.B.RF1W)
            {

              /* If current state is STARTED Invoke receive handler function */
              if(CANIF_CS_STARTED == Can_17_McmCan_ControllerMode[CntrlIndx])
                {

                  /* Enter Critical Section */
                  SchM_Enter_Can_17_McmCan_CanWrMO();
                  /* Request for the Transmission from the prviously store
                  info */
                  NodeRegAddressPtr->TX.BAR.U |= Can_TxBufAddReq[CntrlIndx];
                  /* Clear the previously stored info regarding Transmission
                  requests */
                  Can_TxBufAddReq[CntrlIndx] = CAN_DATA_ZERO;
                  /* Exit Critical Section */
                  SchM_Exit_Can_17_McmCan_CanWrMO();
                  /* Call receive handler with buffer type as RXFIFO1 */
                  Can_lReceiveHandler(CntrlIndx,CAN_THREE);

                }
#if(CAN_WAKEUP_CONFIGURED == STD_ON)
                else
                {
                  /* Set Wakeup Flag as True */
                  WakeUpFlag = E_OK;
                }
#endif

              /* Reset flag for New message to RXFIFO1 */
              NodeRegAddressPtr->IR.U = CAN_CLEAR_IE_RF1W_BIT;
            }

#endif /* #if(CAN_RXFIFO1_ENABLED == STD_ON) */

#if(CAN_WAKEUP_CONFIGURED == STD_ON)
          /* If SLEEP state invoke function wakeup handler for wakeup
                                            processing */
            if((CANIF_CS_SLEEP == Can_17_McmCan_ControllerMode[CntrlIndx]) &&
               (E_OK == WakeUpFlag))
              {
                /* Invoke wakeup handler function */
                Can_lWakeupHandler(CntrlIndx);
              }
#endif

        }

    }

}
#endif
#endif

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
void Can_17_McmCan_IsrBusOffHandler (uint8 HwKernelId)
{
  Ifx_CAN_N *NodeRegAddressPtr;
  uint8 NodeIndx;
  uint8 CntrlIndx;

  /* Read no of Activated nodes and set loop with it */
  for(NodeIndx = CAN_ZERO; NodeIndx <
      (Can_kConfigPtr-> CanMCMModuleConfigPtr[HwKernelId].NoOfActiveNodes);
      NodeIndx++)
    {
      /* Set Controller Index */
      CntrlIndx = Can_kConfigPtr->
                  CanMCMModuleConfigPtr[HwKernelId].CanUsedHwCfgIndx[NodeIndx];

      /* Check the BusOff for the controller mode is Interrupt or not */
      if(CAN_POLLING != Can_kConfigPtr->
          CanEventHandlingConfigPtr[CntrlIndx].CanEventType[CAN_TWO])
        {
          /* Set with Node Register Start address */
          NodeRegAddressPtr = Can_kConfigPtr->
                              CanControllerConfigPtr[CntrlIndx].CanNodeAddress;

          /* Check if BusOff status is changed */
          if( CAN_BIT_SET_VAL == NodeRegAddressPtr->IR.B.BO)
            {

#if(CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
              if((CAN_FALSE == Can_17_McmCan_IcomConfgBOStatus[CntrlIndx]) &&
              (CAN_TRUE == Can_17_McmCan_IcomEnableStatus[CntrlIndx]))
              {
                /* Do nothing */
              }
              else
              {
              /* If current state is STARTED Invoke BusOff handler function */
              Can_lBusOffHandler(CntrlIndx);
              /* Reset BO flag */
              NodeRegAddressPtr->IR.U = CAN_CLEAR_IE_BO_BIT;
              }

#else
              /* If current state is STARTED Invoke BusOff handler function */
              Can_lBusOffHandler(CntrlIndx);
              /* Reset BO flag */
              NodeRegAddressPtr->IR.U = CAN_CLEAR_IE_BO_BIT;
#endif

            }

        }

    }

}
#endif   /* #if(CAN_BO_INTERRUPT_PROCESSING == STD_ON) */

#define CAN_17_MCMCAN_STOP_SEC_CODE_QM_GLOBAL
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
   guideline. */
 /* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
    without safegaurd. It complies to Autosar guidelines. */
#include "Can_17_McmCan_MemMap.h"