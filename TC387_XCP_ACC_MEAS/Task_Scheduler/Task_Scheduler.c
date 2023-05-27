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

/*********************************************************************************************************************/
/*------------------------------------------------------Globals------------------------------------------------------*/
/*********************************************************************************************************************/
/**
 * task1 => 500ms
 * task2 => 1000ms
 * task3 => 2000ms
 *
 * the led order is: led1 - led2 - led1 - led3
 */

/**
 * Array with all tasks
 */
S_TS_Task tasks[TS_NUM_TASKS] = {
        {TS_TASK_1MS_ID,      1,     1,   TS_v_Task1ms},
        {TS_TASK_10MS_ID,     10,    10,  TS_v_Task10ms},
};
//S_TS_Task tasks[NUM_TASKS] = {
//  {TASK1_ID, 100, 100, task1},
//  {TASK2_ID, 200, 200, task2},
//  {TASK3_ID, 300, 300, task3},
//};

uint32 counter1ms   = 0;
uint32 counter10ms  = 0;

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
    // LED1 => ON
    counter1ms++;

    // if 5000ms passed turn on led1
    if (counter1ms == 5000) {
        led1ON();
    }
}

/**
 * Cyclic task that executes at 10ms
 */
void TS_v_Task10ms (void) {
//    LED2 => ON
    counter10ms++;

    // if 10.000ms passed turn on led2
    if (counter10ms == 1000) {
        led2ON();
    }
}

//END OF FILE