/*
 * Task_Scheduler.c
 *
 *  Created on: Apr 3, 2023
 *      Author: uif47623
 */

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/

#include "Task_Scheduler.h"
#include "Ifx_Types.h"
#include "IfxGpt12.h"
#include "IfxPort.h"
#include "MCMCAN.h"
#include "ADC_Queued_Scan.h"
#include "CanSM.h"
#include "ComM.h"
#include "Crash_Detection.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Globals------------------------------------------------------*/
/*********************************************************************************************************************/
/**
 * Array with all tasks
 */
S_TS_Task tasks[TS_NUM_TASKS] = {
        {TS_TASK_1MS_ID,      1,     1,   TS_v_Task1ms},
        {TS_TASK_10MS_ID,     10,    10,  TS_v_Task10ms},
};

uint32 counter1ms   = 0;
uint8 counter10ms  = 0;

extern uint32 TS_G_CurrentState = TS_TASK_INVALID_TASK;

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/

/**
 * Task_Scheduler Main function
 */
void TS_v_Run (void) {
    static uint16 tickCounter = 0;

    uint8 i;

    // Loop through each task
    for (i = 0; i < TS_NUM_TASKS; i++) {
        S_TS_Task *currentTask = &tasks[i];

        // Check if task needs to be executed
        if (currentTask->remainingTime == 0) {
            // Execute task
            currentTask->function();

            // Reset remaining time to period
            currentTask->remainingTime = currentTask->period;
        }
        // Decrement remaining time
        if (tickCounter % 10 == 0) {
            currentTask->remainingTime -= 1; // Tick interval is 10 ms
        }
    }
    // Increment tick counter
    tickCounter += 1; // Assume tick interval is 10 ms
}

void led1ON() {
    IfxPort_setPinHigh(&MODULE_P20, 12);
    IfxPort_setPinHigh(&MODULE_P20, 13);
    IfxPort_setPinLow(&MODULE_P20, 11);
}

void led2ON() {
    IfxPort_setPinLow(&MODULE_P20, 12);
    IfxPort_setPinHigh(&MODULE_P20, 13);
    IfxPort_setPinHigh(&MODULE_P20, 11);
}

/**
 * Cyclic task that executes at 1ms
 */
void TS_v_Task1ms (void) {
    TS_v_ChangeState(TS_TASK_1MS_ID);

#ifdef TASK_DEBUGGING
    // LED1 => ON
    counter1ms++;

    // if 5000ms passed turn on led1
    if (counter1ms == 5000) {
        led1ON();
    }
#endif
}

/**
 * Cyclic task that executes at 10ms
 */
void TS_v_Task10ms (void) {
    TS_v_ChangeState(TS_TASK_10MS_ID);

#ifdef TASK_DEBUGGING
    // LED2 => ON
    counter10ms++;

    // if 10.000ms passed turn on led2
    if (counter10ms == 1000) {
        led2ON();
    }
#endif
    //transmitCanMessage();
    readEVADC();
    MainFunction_CrashDetection();
    CanSM_MainFunction();
    ComM_MainFunction_0();
    Xcp_MainFunction();

    counter10ms++;
}

void TS_v_ChangeState(uint32 newState) {
    TS_G_CurrentState = newState;
}

//END OF FILE
