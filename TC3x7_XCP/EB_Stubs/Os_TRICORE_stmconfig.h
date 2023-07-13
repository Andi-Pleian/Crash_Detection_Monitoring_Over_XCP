/* Os_TRICORE_stmconfig.h - Configuration of the STM
 *
 * This file will be included by board.h. The following macros must be defined
 * in order to configure the timers:
 *
 *  OS_STM_PRESCALE	- the desired STM prescaler value (1..7) as programmed into the RMC field in STM_CLC
 *  OS_STM_CMPPOS0	- compare region for STM_T0 (0..24) as programmed into the MSTART0 field in STM_CMCON
 *  OS_STM_CMPPOS1	- compare region for STM_T1 (0..24) as programmed into the MSTART1 field in STM_CMCON
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_TRICORE_stmconfig.h 1.1 2017/12/21 16:35:17CET Postolache, Alexandru (uidu6496) none  $
*/

#ifndef OS_TRICORE_STMCONFIG_H
#define OS_TRICORE_STMCONFIG_H

#include <Os_tool.h>

/* First, some default values. If nothing else is defined we assume that the
 * STM runs at the module frequency and that the comparators compare with
 * the bottom 32 bits of the STM.
*/
#ifndef OS_STM_PRESCALE
#define OS_STM_PRESCALE	1
#endif

/* Here we define the conversion macros for the individual HW-timers that can
 * be selected in the OIL file. These are defined using the global helper
 * macro, supplying the MSTARTx value for the comparator.
 * If the prescaler macro is not defined, we don't define the conversion macros.
 * If the prescaler is out of range we emit an error message.
 * For timers 1 and 3, if the prescaler is 7 we silently ignore it.
*/
#define OS_NsToTicks_STM0_T0(ns)	(OS_NsToTicks_STM(ns))
#define OS_TicksToNs_STM0_T0(tx)	(OS_TicksToNs_STM(tx))
#define OS_NsToTicks_STM0_T1(ns)	(OS_NsToTicks_STM(ns))
#define OS_TicksToNs_STM0_T1(tx)	(OS_TicksToNs_STM(tx))

#if OS_N_STM >= 2
#define OS_NsToTicks_STM1_T0(ns)	(OS_NsToTicks_STM(ns))
#define OS_TicksToNs_STM1_T0(tx)	(OS_TicksToNs_STM(tx))
#define OS_NsToTicks_STM1_T1(ns)	(OS_NsToTicks_STM(ns))
#define OS_TicksToNs_STM1_T1(tx)	(OS_TicksToNs_STM(tx))
#endif

#if OS_N_STM >= 3
#define OS_NsToTicks_STM2_T0(ns)	(OS_NsToTicks_STM(ns))
#define OS_TicksToNs_STM2_T0(tx)	(OS_TicksToNs_STM(tx))
#define OS_NsToTicks_STM2_T1(ns)	(OS_NsToTicks_STM(ns))
#define OS_TicksToNs_STM2_T1(tx)	(OS_TicksToNs_STM(tx))
#endif

#if OS_N_STM >= 4
#define OS_NsToTicks_STM3_T0(ns)	(OS_NsToTicks_STM(ns))
#define OS_TicksToNs_STM3_T0(tx)	(OS_TicksToNs_STM(tx))
#define OS_NsToTicks_STM3_T1(ns)	(OS_NsToTicks_STM(ns))
#define OS_TicksToNs_STM3_T1(tx)	(OS_TicksToNs_STM(tx))
#endif

#if OS_N_STM >= 5
#define OS_NsToTicks_STM4_T0(ns)	(OS_NsToTicks_STM(ns))
#define OS_TicksToNs_STM4_T0(tx)	(OS_TicksToNs_STM(tx))
#define OS_NsToTicks_STM4_T1(ns)	(OS_NsToTicks_STM(ns))
#define OS_TicksToNs_STM4_T1(tx)	(OS_TicksToNs_STM(tx))
#endif

#if OS_N_STM >= 6
#define OS_NsToTicks_STM5_T0(ns)	(OS_NsToTicks_STM(ns))
#define OS_TicksToNs_STM5_T0(tx)	(OS_TicksToNs_STM(tx))
#define OS_NsToTicks_STM5_T1(ns)	(OS_NsToTicks_STM(ns))
#define OS_TicksToNs_STM5_T1(tx)	(OS_TicksToNs_STM(tx))
#endif

/*
 * Conversion macros for the Timebase Timer
 */
#define OS_NsToTicks_TbTimer(ns)	OS_NsToTicks_STM(ns)
#define OS_TicksToNs_TbTimer(ticks)	OS_TicksToNs_STM(ticks)

/* This macro converts ticks to nanoseconds and vice versa for the STM's
 * master clock (Fmod divided by RMC)
*/
#if (OS_STM_PRESCALE >= 1) && (OS_STM_PRESCALE <= 7)
#define OS_NsToTicks_STM(ns)	(OS_BoardNsToTicks(ns)/(OS_STM_PRESCALE))
#define OS_TicksToNs_STM(tx)	(OS_BoardTicksToNs(tx)*(OS_STM_PRESCALE))
#else
#error "Invalid/unsupported value for OS_STM_PRESCALE"
#endif

#endif

/* Editor settings: DO NOT DELETE
 * vi: set ts=4:
*/
