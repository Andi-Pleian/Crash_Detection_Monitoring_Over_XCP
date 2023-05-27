/*
 * MCMCAN.c
 *
 *  Created on: Apr 11, 2023
 *      Author: uif47623
 */

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "MCMCAN.h"

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
McmcanType                  g_mcmcan;                       /* Global MCMCAN configuration and control structure    */
IfxPort_Pin_Config          g_led1;                         /* Global LED1 configuration and control structure      */
IfxPort_Pin_Config          g_led2;                         /* Global LED2 configuration and control structure      */

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
/* Macro to define Interrupt Service Routine.
 * This macro:
 * - defines linker section as .intvec_tc<vector number>_<interrupt priority>.
 * - defines compiler specific attribute for the interrupt functions.
 * - defines the Interrupt service routine as ISR function.
 *
 * IFX_INTERRUPT(isr, vectabNum, priority)
 *  - isr: Name of the ISR function.
 *  - vectabNum: Vector table number.
 *  - priority: Interrupt priority. Refer Usage of Interrupt Macro for more details.
 */
IFX_INTERRUPT(canIsrTxHandler, 0, ISR_PRIORITY_CAN_TX);
IFX_INTERRUPT(canIsrRxHandler, 0, ISR_PRIORITY_CAN_RX);

/* Interrupt Service Routine (ISR) called once the TX interrupt has been generated.
 * Turns on the LED1 to indicate successful CAN message transmission.
 */
void canIsrTxHandler(void)
{
    /* Clear the "Transmission Completed" interrupt flag */
    IfxCan_Node_clearInterruptFlag(g_mcmcan.canSrcNode.node, IfxCan_Interrupt_transmissionCompleted);

    /* Just to indicate that the CAN message has been transmitted by turning on LED1 */
    IfxPort_togglePin(g_led1.port, g_led1.pinIndex);
}

/* Interrupt Service Routine (ISR) called once the RX interrupt has been generated.
 * Compares the content of the received CAN message with the content of the transmitted CAN message
 * and in case of success, turns on the LED2 to indicate successful CAN message reception.
 */
void canIsrRxHandler(void)
{
    /* Clear the "Message stored to Dedicated RX Buffer" interrupt flag */
    IfxCan_Node_clearInterruptFlag(g_mcmcan.canSrcNode.node, IfxCan_Interrupt_messageStoredToDedicatedRxBuffer);

    /* Read the received CAN message */
    IfxCan_Can_readMessage(&g_mcmcan.canSrcNode, &g_mcmcan.rxMsg, g_mcmcan.rxData);

    if (g_mcmcan.rxMsg.messageId == 0x100) {
        IfxPort_togglePin(g_led2.port, g_led2.pinIndex);
    }
}

/* Function to initialize MCMCAN module and nodes related for this application use case */
void initMcmcan(void)
{
    /* ==========================================================================================
     * CAN module configuration and initialization:
     * ==========================================================================================
     *  - load default CAN module configuration into configuration structure
     *  - initialize CAN module with the default configuration
     * ==========================================================================================
     */
    IfxCan_Can_initModuleConfig(&g_mcmcan.canConfig, &MODULE_CAN0);

    IfxCan_Can_initModule(&g_mcmcan.canModule, &g_mcmcan.canConfig);

    /* ==========================================================================================
     * Source CAN node configuration and initialization:
     * ==========================================================================================
     *  - load default CAN node configuration into configuration structure
     *
     *  - set source CAN node in the "Loop-Back" mode (no external pins are used)
     *  - assign source CAN node to CAN node 0
     *
     *  - define the frame to be the transmitting one
     *
     *  - once the transmission is completed, raise the interrupt
     *  - define the transmission complete interrupt priority
     *  - assign the interrupt line 0 to the transmission complete interrupt
     *  - transmission complete interrupt service routine should be serviced by the CPU0
     *
     *  - initialize the source CAN node with the modified configuration
     * ==========================================================================================
     */
    IfxCan_Can_initNodeConfig(&g_mcmcan.canNodeConfig, &g_mcmcan.canModule);

    const IfxCan_Can_Pins pins =
    {
    &TX_PIN, IfxPort_OutputMode_pushPull,
    &RX_PIN, IfxPort_InputMode_pullUp,
    IfxPort_PadDriver_cmosAutomotiveSpeed1
    };

    g_mcmcan.canNodeConfig.busLoopbackEnabled = FALSE;
    g_mcmcan.canNodeConfig.pins = &pins;
    g_mcmcan.canNodeConfig.nodeId = IfxCan_NodeId_0;

    g_mcmcan.canNodeConfig.frame.type = IfxCan_FrameType_transmitAndReceive; //transmit doar pt src

    g_mcmcan.canNodeConfig.interruptConfig.transmissionCompletedEnabled = TRUE;
    g_mcmcan.canNodeConfig.interruptConfig.traco.priority = ISR_PRIORITY_CAN_TX;
    g_mcmcan.canNodeConfig.interruptConfig.traco.interruptLine = IfxCan_InterruptLine_0;
    g_mcmcan.canNodeConfig.interruptConfig.traco.typeOfService = IfxSrc_Tos_cpu0;


    g_mcmcan.canNodeConfig.interruptConfig.messageStoredToDedicatedRxBufferEnabled = TRUE;
    g_mcmcan.canNodeConfig.interruptConfig.reint.priority = ISR_PRIORITY_CAN_RX;
    g_mcmcan.canNodeConfig.interruptConfig.reint.interruptLine = IfxCan_InterruptLine_1;
    g_mcmcan.canNodeConfig.interruptConfig.reint.typeOfService = IfxSrc_Tos_cpu0;

    IfxCan_Can_initNode(&g_mcmcan.canSrcNode, &g_mcmcan.canNodeConfig);

    /* ==========================================================================================
     * CAN filter configuration and initialization:
     * ==========================================================================================
     *  - filter configuration is stored under the filter element number 0
     *  - store received frame in a dedicated RX Buffer
     *  - define the same message ID as defined for the TX message
     *  - assign the filter to the dedicated RX Buffer (RxBuffer0 in this case)
     *
     *  - initialize the standard filter with the modified configuration
     * ==========================================================================================
     */
    g_mcmcan.canFilter.number = 0;
    g_mcmcan.canFilter.elementConfiguration = IfxCan_FilterElementConfiguration_storeInRxBuffer;
    g_mcmcan.canFilter.id1 = 0x100;  //CAN_MESSAGE_ID;
    g_mcmcan.canFilter.rxBufferOffset = IfxCan_RxBufferId_0;

    IfxCan_Can_setStandardFilter(&g_mcmcan.canSrcNode, &g_mcmcan.canFilter);
}

/* Function to initialize both TX and RX messages with the default data values.
 * After initialization of the messages, the TX message is transmitted.
 */
void transmitCanMessage(void)
{
//    /* Initialization of the RX message with the default configuration */
//    IfxCan_Can_initMessage(&g_mcmcan.rxMsg);
//
//    /* Invalidation of the RX message data content */
//    memset((void *)(&g_mcmcan.rxData[0]), INVALID_RX_DATA_VALUE, MAXIMUM_CAN_DATA_PAYLOAD * sizeof(uint32));

    /* Initialization of the TX message with the default configuration */
    IfxCan_Can_initMessage(&g_mcmcan.txMsg);

    /* Define the content of the data to be transmitted */
    g_mcmcan.txData[0] = TX_DATA_LOW_WORD;
    g_mcmcan.txData[1] = TX_DATA_HIGH_WORD;

    /* Set the message ID that is used during the receive acceptance phase */
    g_mcmcan.txMsg.messageId = CAN_MESSAGE_ID;

    /* Send the CAN message with the previously defined TX message content */
    while( IfxCan_Status_notSentBusy ==
           IfxCan_Can_sendMessage(&g_mcmcan.canSrcNode, &g_mcmcan.txMsg, &g_mcmcan.txData[0]) )
    {
    }

    //IfxPort_togglePin(g_led1.port, g_led1.pinIndex);
}

/* Function to initialize the LEDs */
void initLeds(void)
{
    /* ======================================================================
     * Configuration of the pins connected to the LEDs:
     * ======================================================================
     *  - define the GPIO port
     *  - define the GPIO pin that is connected to the LED
     *  - define the general GPIO pin usage (no alternate function used)
     *  - define the pad driver strength
     * ======================================================================
     */
    g_led1.port      = &MODULE_P20;//&MODULE_P13;
    g_led1.pinIndex  = 11;//PIN0;
    g_led1.mode      = IfxPort_OutputIdx_general;
    //g_led1.padDriver = IfxPort_PadDriver_cmosAutomotiveSpeed1;

    g_led2.port      = &MODULE_P20;//&MODULE_P13;
    g_led2.pinIndex  = 13;//PIN1;
    g_led2.mode      = IfxPort_OutputIdx_general;
    //g_led2.padDriver = IfxPort_PadDriver_cmosAutomotiveSpeed1;

    /* Set the pin input/output mode for both pins connected to the LEDs */
    IfxPort_setPinModeOutput(g_led1.port, g_led1.pinIndex, IfxPort_OutputMode_pushPull, g_led1.mode);
    IfxPort_setPinModeOutput(g_led2.port, g_led2.pinIndex, IfxPort_OutputMode_pushPull, g_led2.mode);

    /* Initialize the pins connected to LEDs to level "HIGH", which keep the LEDs turned off as default state */
    IfxPort_setPinHigh(g_led1.port, g_led1.pinIndex);
    IfxPort_setPinHigh(g_led2.port, g_led2.pinIndex);

//    /* Set the pad driver mode for both pins connected to the LEDs */
//    IfxPort_setPinPadDriver(g_led1.port, g_led1.pinIndex, g_led1.padDriver);
//    IfxPort_setPinPadDriver(g_led2.port, g_led2.pinIndex, g_led2.padDriver);
}
