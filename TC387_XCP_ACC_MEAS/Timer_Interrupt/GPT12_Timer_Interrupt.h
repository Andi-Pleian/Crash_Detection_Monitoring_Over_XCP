/*
 * GPT12_Timer_Interrupt.h
 *
 *  Created on: Apr 4, 2023
 *      Author: uif47623
 */

#ifndef TIMER_INTERRUPT_GPT12_TIMER_INTERRUPT_H_
#define TIMER_INTERRUPT_GPT12_TIMER_INTERRUPT_H_

/*********************************************************************************************************************/
/*-----------------------------------------------Function Prototypes-------------------------------------------------*/
/*********************************************************************************************************************/
void GPT12_v_InitTimer  (void);                          /* Function to initialize the GPT12 Module and start the timer  */
void interruptGpt12     (void);                             /* Interrupt Service Routine of the GPT12                       */

#endif /* TIMER_INTERRUPT_GPT12_TIMER_INTERRUPT_H_ */

//END OF FILE