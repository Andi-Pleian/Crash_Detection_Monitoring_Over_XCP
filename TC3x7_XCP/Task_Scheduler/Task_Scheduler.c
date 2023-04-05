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
        {TS_TASK_500MS_ID,      500,     500,   TS_v_Task500ms},
        {TS_TASK_1000MS_ID,     1000,    1000,  TS_v_Task1000ms},
        {TS_TASK_1500MS_ID,     1500,    1500,  TS_v_Task1500ms},
};
//S_TS_Task tasks[NUM_TASKS] = {
//  {TASK1_ID, 100, 100, task1},
//  {TASK2_ID, 200, 200, task2},
//  {TASK3_ID, 300, 300, task3},
//};

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
            currentTask->remainingTime -= 10; // Assume tick interval is 10 ms
        }
    }
    // Increment tick counter
    tickCounter += 10; // Assume tick interval is 10 ms
}

/**
 * Cyclic task that executes 500ms
 */
void TS_v_Task500ms (void) {
    IfxPort_setPinHigh(&MODULE_P20, 12);
    IfxPort_setPinHigh(&MODULE_P20, 13);
    IfxPort_setPinLow(&MODULE_P20, 11);
}

/**
 * Cyclic task that executes 1000ms
 */
void TS_v_Task1000ms (void) {
    IfxPort_setPinLow(&MODULE_P20, 12);
    IfxPort_setPinHigh(&MODULE_P20, 13);
    IfxPort_setPinHigh(&MODULE_P20, 11);
}

/**
 * Cyclic task that executes 1500ms
 */
void TS_v_Task1500ms (void) {
    IfxPort_setPinHigh(&MODULE_P20, 12);
    IfxPort_setPinLow(&MODULE_P20, 13);
    IfxPort_setPinHigh(&MODULE_P20, 11);
}

//END OF FILE
