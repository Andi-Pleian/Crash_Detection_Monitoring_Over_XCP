/*
 * Timer_Interrupt.c
 *
 *  Created on: Apr 4, 2023
 *      Author: uif47623
 */
/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include <Timer_Interrupt.h>
#include "Ifx_Types.h"
#include "IfxGpt12.h"
#include "IfxPort.h"
#include "Task_Scheduler.h"
/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define ISR_PRIORITY_GPT12_TIMER    6
#define ISR_PROVIDER_GPT12_TIMER    IfxSrc_Tos_cpu0

#define RELOAD_VALUE                7                       /* reload value to have an interrupt each ms */

#define LED                         &MODULE_P20,11          /* LED which toggles in the ISR              */
#define LED2                        &MODULE_P20,12
#define LED3                        &MODULE_P20,13

// macro defining the Interrupt Service Routine
IFX_INTERRUPT(interruptGpt12, 0, ISR_PRIORITY_GPT12_TIMER);
/*********************************************************************************************************************/
/*--------------------------------------------Function Implementations-----------------------------------------------*/
/*********************************************************************************************************************/
void initTimer(void) {
    // initialize the GPT12 module
    IfxGpt12_enableModule(&MODULE_GPT120);
    IfxGpt12_setGpt1BlockPrescaler(&MODULE_GPT120, IfxGpt12_Gpt1BlockPrescaler_16);

    // init the Timer T3
    IfxGpt12_T3_setMode(&MODULE_GPT120, IfxGpt12_Mode_timer);
    IfxGpt12_T3_setTimerDirection(&MODULE_GPT120, IfxGpt12_TimerDirection_down);
    IfxGpt12_T3_setTimerPrescaler(&MODULE_GPT120, IfxGpt12_TimerInputPrescaler_64);
    IfxGpt12_T3_setTimerValue(&MODULE_GPT120, RELOAD_VALUE);

    // init the Timer T2
    IfxGpt12_T2_setMode(&MODULE_GPT120, IfxGpt12_Mode_reload);
    IfxGpt12_T2_setReloadInputMode(&MODULE_GPT120,
            IfxGpt12_ReloadInputMode_bothEdgesTxOTL);
    IfxGpt12_T2_setTimerValue(&MODULE_GPT120, RELOAD_VALUE);

    // init the interrupt
    volatile Ifx_SRC_SRCR *src = IfxGpt12_T3_getSrc(&MODULE_GPT120);
    IfxSrc_init(src, ISR_PROVIDER_GPT12_TIMER, ISR_PRIORITY_GPT12_TIMER);
    IfxSrc_enable(src);

    IfxPort_setPinModeOutput(LED, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
    IfxPort_setPinModeOutput(LED2, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
    IfxPort_setPinModeOutput(LED3, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);

    // start Timer
    IfxGpt12_T3_run(&MODULE_GPT120, IfxGpt12_TimerRun_start);
}

/* ISR */
void interruptGpt12(void) {
    MainFunction_TaskScheduler();     // run task scheduler
}

//END OF FILE
