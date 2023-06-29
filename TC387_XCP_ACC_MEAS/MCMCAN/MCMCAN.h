/*
 * MCMCAN.h
 *
 *  Created on: Apr 11, 2023
 *      Author: uif47623
 */

#ifndef MCMCAN_MCMCAN_H_
#define MCMCAN_MCMCAN_H_

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include <stdio.h>
#include <string.h>
#include "Ifx_Types.h"
#include "IfxCan_Can.h"
#include "IfxCan.h"
#include "IfxCpu_Irq.h"
#include "IfxPort.h"
#include "Can.h"
/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define CAN_MESSAGE_ID              (uint32)0x777
#define PIN0                        0
#define PIN1                        1
#define INVALID_RX_DATA_VALUE       0xA5
#define INVALID_ID_VALUE            (uint32)0xFFFFFFFF
#define ISR_PRIORITY_CAN_TX         2
#define ISR_PRIORITY_CAN_RX         1
#define TX_DATA_LOW_WORD            (uint32)0xC0CAC01A
#define TX_DATA_HIGH_WORD           (uint32)0xBA5EBA11
#define MAXIMUM_CAN_DATA_PAYLOAD    2

#define TX_PIN IfxCan_TXD00_P20_8_OUT
#define RX_PIN IfxCan_RXD00B_P20_7_IN
/*********************************************************************************************************************/
/*--------------------------------------------------Data Structures--------------------------------------------------*/
/*********************************************************************************************************************/
typedef struct
{
    IfxCan_Can_Config canConfig;                            /* CAN configuration structure                          */
    IfxCan_Can canModule;                                   /* CAN module handle                                    */
    IfxCan_Can_Node canSrcNode;                             /* CAN source node handle data structure                */
    IfxCan_Can_NodeConfig canNodeConfig;                    /* CAN node configuration structure                     */
    IfxCan_Filter canFilter;                                /* CAN filter configuration structure                   */
    IfxCan_Message txMsg;                                   /* Transmitted CAN message structure                    */
    IfxCan_Message rxMsg;                                   /* Received CAN message structure                       */
    uint32 txData[MAXIMUM_CAN_DATA_PAYLOAD];                /* Transmitted CAN data array                           */
    uint32 rxData[MAXIMUM_CAN_DATA_PAYLOAD];                /* Received CAN data array                              */
} McmcanType;
/*********************************************************************************************************************/
/*-----------------------------------------------Function Prototypes-------------------------------------------------*/
/*********************************************************************************************************************/
void initMcmcan(void);
void transmitCanMessage(void);
Can_ReturnType MCMCAN_Write(Can_HwHandleType, const Can_PduType*);

#endif /* MCMCAN_MCMCAN_H_ */

//END OF FILE
