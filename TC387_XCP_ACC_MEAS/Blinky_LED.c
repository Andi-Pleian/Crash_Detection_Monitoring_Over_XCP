/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/

#include "IfxPort.h"
#include "Bsp.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define LED_P20_11    &MODULE_P20,11                                        /* LED D107: Port, Pin definition       */
#define LED_P20_12    &MODULE_P20,12                                        /* LED D107: Port, Pin definition       */
#define LED_P20_13    &MODULE_P20,13                                        /* LED D107: Port, Pin definition       */
#define LED_P20_14    &MODULE_P20,14                                        /* LED D107: Port, Pin definition       */

#define WAIT_TIME   500                                                     /* Wait time constant in milliseconds   */

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
/* This function initializes the port pin which drives the LED */
void initLED(void) {
    /* Initialization of the LED */
    IfxPort_setPinModeOutput(LED_P20_12, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
    /* Switch OFF the LED (low-level active) */
    IfxPort_setPinHigh(LED_P20_12);
}

/* This function toggles the port pin and wait 500 milliseconds */
void blinkLED(void) {
    IfxPort_togglePin(LED_P20_12);                                                /* Toggle the state of the LED      */
    //waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, WAIT_TIME));      /* Wait 500 milliseconds            */
}
//#include <Std_Types.h>
//#include <ComStack_Types.h>
//#include <CanSM_BswM.h>
//#include <BswM_CanSM.h>
//#include <BswM_CanSM.h>

//typedef uint8 CanSM_BswMCurrentStateType;
//typedef uint8 CanSM_BswMCurrentStateType;
//typedef uint8 NetworkHandleType;

//void BswM_CanSM_CurrentState
//(
///*NetworkHandleType*/uint8 Network,
///*CanSM_BswMCurrentStateType*/uint8 CurrentState
//);