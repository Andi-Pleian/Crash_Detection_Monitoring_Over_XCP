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
#include "CanIf.h"
#include "Xcp.h"
#include "ADC.h"
#include "ADC_Queued_Scan.h"
#include "Base_Modules.h"
#include "ComM.h"
#include "CanSM.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Globals------------------------------------------------------*/
/*********************************************************************************************************************/

IFX_ALIGN(4) IfxCpu_syncEvent g_cpuSyncEvent = 0;

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/

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

    initMcmcan();
    CanIf_Init(&CanIf_InitCfg);

    CanSM_Init(&CanSM_Config_0);
    ComM_Init(BASE_COMM_CONFIG_PTR);

    Xcp_Init(&XcpConfig);
    initLeds();

    ComM_CommunicationAllowed(0,TRUE);
    ComM_RequestComMode( 0, COMM_FULL_COMMUNICATION );

    // Start GPT12 timer
    GPT12_v_InitTimer();

    /* Function to initialize the EVADC with default parameters */
    initEVADC();

    while(1) {
        //transmitCanMessage();
        //wait_ms(1000);
        //readEVADC();
    }
}

//END OF FILE
