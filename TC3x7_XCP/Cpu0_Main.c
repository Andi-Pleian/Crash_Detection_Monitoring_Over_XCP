/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/

#include "Blinky_LED.h"
#include "Ifx_Types.h"
#include "IfxCpu.h"
#include "IfxScuWdt.h"
#include "Task_Scheduler.h"
#include "GPT12_Timer_Interrupt.h"
#include "MCMCAN.h"
#include "Bsp.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Globals------------------------------------------------------*/
/*********************************************************************************************************************/

IFX_ALIGN(4) IfxCpu_syncEvent g_cpuSyncEvent = 0;

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/

/* Waits until a timeout in milliseconds */
void wait_ms(uint32 ms)
{
    sint32 Fsys = IfxStm_getFrequency(&MODULE_STM0);
    Ifx_TickTime waitms = (Fsys / (1000 / ms));

    wait(waitms);
}

void core0_main(void) {
    IfxCpu_enableInterrupts();
    
    /* !!WATCHDOG0 AND SAFETY WATCHDOG ARE DISABLED HERE!!
     * Enable the watchdogs and service them periodically if it is required
     */
    IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());
    IfxScuWdt_disableSafetyWatchdog(IfxScuWdt_getSafetyWatchdogPassword());
    
    /* Wait for CPU sync event */
    IfxCpu_emitEvent(&g_cpuSyncEvent);
    IfxCpu_waitEvent(&g_cpuSyncEvent, 1);

    // Start GPT12 timer
    //GPT12_v_InitTimer();
    


    wait_ms(1000);
    initMcmcan();
    initLeds();
    transmitCanMessage();   //LED ON
    wait_ms(1000);
    wait_ms(1000);
    transmitCanMessage();   //LED OFF
    wait_ms(1000);
    wait_ms(1000);
    transmitCanMessage();   //LED ON
    wait_ms(1000);
    wait_ms(1000);

    while(1) {

    }
}

//END OF FILE
