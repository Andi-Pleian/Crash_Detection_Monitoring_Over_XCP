/*
 * Task_Scheduler.c
 *
 *  Created on: Apr 3, 2023
 *      Author: uif47623
 */
/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "ADC.h"
#include "Task_Scheduler.h"
#include "Ifx_Types.h"
#include "IfxGpt12.h"
#include "IfxPort.h"
#include "MCMCAN.h"
#include "CanSM.h"
#include "ComM.h"
#include "Crash_Detection.h"
/*********************************************************************************************************************/
/*------------------------------------------------------Globals------------------------------------------------------*/
/*********************************************************************************************************************/
/* Array with all tasks */
S_Task tasks[NUM_TASKS] = {
        {TASK_1MS_ID,      1,     1,   task1ms},
        {TASK_10MS_ID,     10,    10,  task10ms},
};

uint32 counter1ms   = 0;
uint8 counter10ms  = 0;

extern uint32 currentState = TASK_INVALID_TASK;
/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
void MainFunction_TaskScheduler (void) {
    static uint16 tickCounter = 0;
    uint8 i;

    for (i = 0; i < NUM_TASKS; i++) {
        S_Task *currentTask = &tasks[i];

        // check if task needs to be executed
        if (currentTask->remainingTime == 0) {
            // execute task
            currentTask->function();

            // reset remaining time
            currentTask->remainingTime = currentTask->period;
        }
        // decrement remaining time
        if (tickCounter % 10 == 0) {
            currentTask->remainingTime -= 1;
        }
    }

    tickCounter += 1;
}

void task1ms (void) {
    changeState(TASK_1MS_ID);
}

void task10ms (void) {
    changeState(TASK_10MS_ID);

    readEVADC();
    MainFunction_CrashDetection();
    CanSM_MainFunction();
    ComM_MainFunction_0();
    Xcp_MainFunction();

    counter10ms++;
}

void changeState(uint32 newState) {
    currentState = newState;
}

//END OF FILE
