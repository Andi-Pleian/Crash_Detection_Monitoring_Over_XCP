/* This file is generated automatically. DO NOT EDIT!!
 * 
 * EB tresos AutoCore OS 6.0.119 TRICORE/TC39XX
 * (Build 20171121)
 * 
 * (c) 1998-2018 Elektrobit Automotive GmbH
 * Am Wolfsmantel 46
 * 91058 Erlangen
 * GERMANY
 * 
 * http://www.automotive.elektrobit.com
 * 
 * Date         : 1/23/18 5:29 PM           !!!IGNORE-LINE!!!
 */

#ifndef OS_USER_H
#define OS_USER_H
#ifdef __cplusplus
extern "C" {
#endif

#define OS_GENERATION_ID_OS_H 0x76e67e5cUL

#define OS_AUTOSAROS_VER 6

#define OS_AUTOSAROS_REV 0

#define OS_AUTOSAROS_CORE_BUILD 20171121

#define OS_AUTOSAROS_ARCH_BUILD 20171121

#ifndef OS_INTERRUPT_KEYWORD
#define OS_INTERRUPT_KEYWORD
#endif

#define OS_USE_FAST_LOCKING 0

#include <Os_api.h>
#ifndef OS_ASM
extern void StartupHook_APP_Airbag(void);
#endif  /* OS_ASM */
#ifndef OS_ASM
extern void ShutdownHook_APP_Airbag(StatusType);
#endif  /* OS_ASM */
#ifndef OS_ASM
extern void ErrorHook_APP_Airbag(StatusType);
#endif  /* OS_ASM */

/*===================================================================
 * Alarms
 *==================================================================*/

#define OsAlarm_1ms 0
#define OsAlarm_5ms 1
#define OsAlarm_10ms 2
/*===================================================================
 * Application modes
 *==================================================================*/

#define OsAppMode_0 0
/*===================================================================
 * Applications
 *==================================================================*/

#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define APP_Airbag 0
#endif
/*===================================================================
 * CPU Core configuration
 *==================================================================*/

#define OS_CORE_ID_0 0
#define OS_CORE_ID_1 1
#define OS_CORE_ID_2 2
#define OS_CORE_ID_3 3
#define OS_CORE_ID_4 4
#define OS_CORE_ID_5 5

/*===================================================================
 * Core Mapping
 *==================================================================*/

#define RES_SCHEDULER 0u
/*===================================================================
 * Counters
 *==================================================================*/

#define OSMAXALLOWEDVALUE_OsCounter_0 OS_U(4294967295)
#define OSTICKSPERBASE_OsCounter_0 OS_U(50000)
#define OSMINCYCLE_OsCounter_0 OS_U(50000)
#ifndef OS_ASM
extern void OS_CounterIsr_OsCounter_0(void);
#endif  /* OS_ASM */
#define OS_NsToTicks_OsCounter_0(x) OS_NsToTicks_STM0_T0((x))
#define OS_TicksToNs_OsCounter_0(x) OS_TicksToNs_STM0_T0((x))
#define OS_TICKS2NS_OsCounter_0(x) (OS_TicksToNs_STM0_T0((x)))
#define OS_TICKS2US_OsCounter_0(x) (OS_TicksToNs_STM0_T0((x))/1000u)
#define OS_TICKS2MS_OsCounter_0(x) (OS_TicksToNs_STM0_T0((x))/1000000u)
#define OS_TICKS2SEC_OsCounter_0(x) (OS_TicksToNs_STM0_T0((x))/1000000000u)
#define OsCounter_0 0
#define OSMAXALLOWEDVALUE OSMAXALLOWEDVALUE_OsCounter_0
#define OSTICKSPERBASE OSTICKSPERBASE_OsCounter_0
#define OSMINCYCLE OSMINCYCLE_OsCounter_0
#define OSTICKDURATION OS_TicksToNs_OsCounter_0(1u)

/*===================================================================
 * Interrupts
 *==================================================================*/

#ifndef OS_ASM
extern void OS_ISR_OsIsr_FrAbsTimer0(void);
#endif  /* OS_ASM */
#define OsIsr_FrAbsTimer0_ISR_CATEGORY 1
#define OsIsr_FrAbsTimer0_ISR_VECTOR 8
#define OsIsr_FrAbsTimer0_ISR_LEVEL 9
#ifndef OS_ASM
extern void OS_ISR_DMACH1SR_ISR(void);
#endif  /* OS_ASM */
#define DMACH1SR_ISR_ISR_CATEGORY 2
#define DMACH1SR_ISR_ISR_VECTOR 4
#define DMACH1SR_ISR_ISR_LEVEL 5
#ifndef OS_ASM
extern void OS_ISR_DMACH2SR_ISR(void);
#endif  /* OS_ASM */
#define DMACH2SR_ISR_ISR_CATEGORY 2
#define DMACH2SR_ISR_ISR_VECTOR 5
#define DMACH2SR_ISR_ISR_LEVEL 6
#ifndef OS_ASM
extern void OS_ISR_DMAERRSR_ISR(void);
#endif  /* OS_ASM */
#define DMAERRSR_ISR_ISR_CATEGORY 2
#define DMAERRSR_ISR_ISR_VECTOR 3
#define DMAERRSR_ISR_ISR_LEVEL 4
#ifndef OS_ASM
extern void OS_ISR_QSPI1ERR_ISR(void);
#endif  /* OS_ASM */
#define QSPI1ERR_ISR_ISR_CATEGORY 2
#define QSPI1ERR_ISR_ISR_VECTOR 1
#define QSPI1ERR_ISR_ISR_LEVEL 2
#ifndef OS_ASM
extern void OS_ISR_QSPI1PT_ISR(void);
#endif  /* OS_ASM */
#define QSPI1PT_ISR_ISR_CATEGORY 2
#define QSPI1PT_ISR_ISR_VECTOR 2
#define QSPI1PT_ISR_ISR_LEVEL 3
#ifndef OS_ASM
extern void OS_ISR_OsIsr_Adc_G0SR0(void);
#endif  /* OS_ASM */
#define OsIsr_Adc_G0SR0_ISR_CATEGORY 1
#define OsIsr_Adc_G0SR0_ISR_VECTOR 7
#define OsIsr_Adc_G0SR0_ISR_LEVEL 8
#ifndef OS_ASM
extern void OS_ISR_OsIsr_Adc_G8SR0(void);
#endif  /* OS_ASM */
#define OsIsr_Adc_G8SR0_ISR_CATEGORY 1
#define OsIsr_Adc_G8SR0_ISR_VECTOR 6
#define OsIsr_Adc_G8SR0_ISR_LEVEL 7
#define Os_Counter_STM0_T0_ISR_CATEGORY 2
#define Os_Counter_STM0_T0_ISR_VECTOR 1
#define Os_Counter_STM0_T0_ISR_LEVEL 2
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OsIsr_FrAbsTimer0 0
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define DMACH1SR_ISR 1
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define DMACH2SR_ISR 2
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define DMAERRSR_ISR 3
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define QSPI1ERR_ISR 4
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define QSPI1PT_ISR 5
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OsIsr_Adc_G0SR0 6
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OsIsr_Adc_G8SR0 7
#endif

/*===================================================================
 * Resources
 *==================================================================*/

#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define RES_SCHEDULER_0 0
#endif
/*===================================================================
 * Tasks
 *==================================================================*/

#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OsTask_Init 0
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OsTask_1ms 1
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OsTask_5ms 2
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OsTask_10ms 3
#endif

/*===================================================================
 * Time-stamp timer
 *==================================================================*/

#define OS_TimestampNsToTicks(ns) OS_NsToTicks_TbTimer(ns)
#define OS_TimestampTicksToNs(ticks) OS_TicksToNs_TbTimer(ticks)
#ifdef __cplusplus
}
#endif
#endif  /* OS_USER_H */
