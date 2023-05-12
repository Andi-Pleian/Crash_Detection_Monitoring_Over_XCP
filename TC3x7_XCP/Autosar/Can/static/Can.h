
#ifndef _CAN_H_

#define _CAN_H_

#include "Can_17_McmCan.h"


/* Published parameters */
#define CAN_VENDOR_ID                       CAN_17_MCMCAN_VENDOR_ID
#define CAN_MODULE_ID                       CAN_17_MCMCAN_MODULE_ID
#define CAN_AS_VERSION                      CAN_17_MCMCAN_AS_VERSION
#define CAN_AR_RELEASE_MAJOR_VERSION        CAN_17_MCMCAN_AR_RELEASE_MAJOR_VERSION
#define CAN_AR_RELEASE_MINOR_VERSION        CAN_17_MCMCAN_AR_RELEASE_MINOR_VERSION
#define CAN_AR_RELEASE_REVISION_VERSION     CAN_17_MCMCAN_AR_RELEASE_REVISION_VERSION
#define CAN_SW_MAJOR_VERSION                CAN_17_MCMCAN_SW_MAJOR_VERSION
#define CAN_SW_MINOR_VERSION                CAN_17_MCMCAN_SW_MINOR_VERSION
#define CAN_SW_PATCH_VERSION                CAN_17_MCMCAN_SW_PATCH_VERSION

/* Global Type Definitions */

/* API Functions */
#define Can_Init                            Can_17_McmCan_Init
#define Can_GetVersionInfo                  Can_17_McmCan_GetVersionInfo
#define Can_CheckBaudrate                   Can_17_McmCan_CheckBaudrate
#define Can_ChangeBaudrate                  Can_17_McmCan_ChangeBaudrate
#define Can_SetControllerMode               Can_17_McmCan_SetControllerMode
#define Can_DisableControllerInterrupts     Can_17_McmCan_DisableControllerInterrupts
#define Can_EnableControllerInterrupts      Can_17_McmCan_EnableControllerInterrupts
#define Can_CheckWakeup                     Can_17_McmCan_CheckWakeup
#define Can_Write                           Can_17_McmCan_Write
#define Can_MainFunction_Write              Can_17_McmCan_MainFunction_Write
#define Can_MainFunction_Read               Can_17_McmCan_MainFunction_Read
#define Can_MainFunction_BusOff             Can_17_McmCan_MainFunction_BusOff
#define Can_MainFunction_Wakeup             Can_17_McmCan_MainFunction_Wakeup
#define Can_MainFunction_Mode               Can_17_McmCan_MainFunction_Mode
#define Can_IsrBusOffHandler                Can_17_McmCan_IsrBusOffHandler
#define Can_IsrReceiveHandler               Can_17_McmCan_IsrReceiveHandler
#define Can_IsrTransmitHandler              Can_17_McmCan_IsrTransmitHandler


#endif
