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
/*------------------------------------------------------Defines------------------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*------------------------------------------------------Structs------------------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*------------------------------------------------------Globals------------------------------------------------------*/
/*********************************************************************************************************************/
// Array with all tasks
S_TS_Task taskList[MAX_TASKS];

// Global var that stores the number of tasks
uint16 numOfTasks = 0;

void task1(void) {
  // Task 1 code
    IfxPort_togglePin(&MODULE_P20,11);
}

void task2(void) {
  // Task 2 code
    IfxPort_togglePin(&MODULE_P20,12);
}

void task3(void) {
  // Task 3 code
    IfxPort_togglePin(&MODULE_P20,13);
}

S_TS_Task tasks[NUM_TASKS] = {
  {TASK1_ID, 100, 100, task1},
  {TASK2_ID, 200, 200, task2},
  {TASK3_ID, 300, 300, task3},
};

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/



void TS_Create_Task(uint8 id, uint16 priority,  uint32 interval, void (*function)(void)) {
//    if (numOfTasks >= MAX_TASKS) {
//        // ERROR: too many tasks!
//    }
//
//    S_TS_Task newTask = { id, priority, interval, (uint32)0, function };
//    taskList[numOfTasks++] = newTask;
}

void TS_Main() {

}

void schedule_tasks(void) {
  static unsigned int tick_counter = 0;
  int i;

  // Loop through each task
  for (i = 0; i < NUM_TASKS; i++) {
      S_TS_Task *task = &tasks[i];

    // Check if task needs to be executed
    if (task->remainingTime == 0) {
      // Execute task
      task->function();

      // Reset remaining time to period
      task->remainingTime = task->period;
    }

    // Decrement remaining time
    if (tick_counter % 10 == 0) {
      task->remainingTime -= 10; // Assume tick interval is 10 ms
    }
  }

  // Increment tick counter
  tick_counter += 10; // Assume tick interval is 10 ms
}
