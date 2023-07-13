/* Os_TRICORE_stm.h - Tricore system timer module description
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_TRICORE_stm.h 1.1 2017/12/21 16:35:17CET Postolache, Alexandru (uidu6496) none  $
*/

/* This file contains a description of Tricore's 64-bit system timer
 * module (STM). More recent implementations of Tricore ship with
 * a 64-bit timer. The wider timer register does not affect the operation in
 * any way, though; one has only a few bits more.
*/

#ifndef OS_TRICORE_STM_H
#define OS_TRICORE_STM_H

#include <TRICORE/Os_TRICORE_core.h>

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(OS_ASM)

/* Tricore 64-bit system timer, running at the system frequency.
   Reading tim0 latches bits 63..32 into the cap register, so that
   the whole 64-bit register can be read in two operations without
   rollover effects.
*/
typedef struct os_tricorestm_s
{
	os_tricoremodule_t	stm_module_hdr; /* 0x00 */
	os_reg32_t			reserved0[1];	/* 0x0C */
	os_reg32_t			stm_tim0;		/* 0x10 bits 31..0 */
	os_reg32_t			stm_tim1;		/* 0x14 bits 35..4 */
	os_reg32_t			stm_tim2;		/* 0x18 bits 39..8 */
	os_reg32_t			stm_tim3;		/* 0x1C bits 43..12 */
	os_reg32_t			stm_tim4;		/* 0c20 bits 47..16 */
	os_reg32_t			stm_tim5;		/* 0x24 bits 51..20 */
	os_reg32_t			stm_tim6;		/* 0x28 bits 55/63..32 (!!!) */
	os_reg32_t			stm_cap;		/* 0x2C capture register for bits 55/63..32 */
	os_reg32_t			stm_cmp[2];		/* 0x30 - 0x34 compare registers (1796) */
	os_reg32_t			stm_cmcon;		/* 0x38 compare control (1796) */
	os_reg32_t			stm_icr;		/* 0x3C interrupt control (1796) */
	os_reg32_t			stm_isrr;		/* 0x40 interrupt set/reset (1796) */
	os_reg32_t			reserved1[3];	/* 0x44 */
	os_reg32_t			stm_tim0sv;		/* 0x50 Timer 0 Register Second View */
	os_reg32_t			stm_capsv;		/* 0x54 Timer Capture Register Second View */
	os_reg32_t			reserved2[36];	/* 0x58 */
	os_reg32_t			stm_ocs;		/* 0xE8 OCDS Control and Status */
	os_reg32_t			stm_krstclr;	/* 0xEC Reset Status Clear */
	os_reg32_t			stm_krst1;		/* 0xF0 Reset Control 1 */
	os_reg32_t			stm_krst0;		/* 0xF4 Reset Control 0 */
	os_reg32_t			stm_accen1;		/* 0xF8 Access Enable 1 */
	os_reg32_t			stm_accen0;		/* 0xFC Access Enable 0 */
} os_tricorestm_t;

#endif

#define OS_STM_MODULE_IDENT	0

/* Offsets of selected registers for use in assembly language modules
*/
#define OS_STM_TIM0_OFFSET		0x10
#define OS_STM_TIM6_OFFSET		0x28

/* STMs whose revision is this value (or less) have their interrupt
 * connections twisted
*/
#define OS_STM_REV_BF_10		0x05

/* Bits in stm_cmcon.
*/
#define OS_STM_MSIZE0		0x0000001fu
#define OS_STM_MSTART0		0x00001f00u
#define OS_STM_MSIZE1		0x001f0000u
#define OS_STM_MSTART1		0x1f000000u
#define OS_STM_CMCON0		0x0000ffffu
#define OS_STM_CMCON1		0xffff0000u

/* Bits in stm_icr
*/
#define OS_STM_CMP0EN		0x00000001u	/* Enable CMP0 */
#define OS_STM_CMP0IR		0x00000002u	/* CMP0 IRQ pending */
#define OS_STM_CMP0OS		0x00000004u
#define OS_STM_CMP0OS_IR0	0x00000000u	/* CMP0 IRQ --> IR0 */
#define OS_STM_CMP0OS_IR1	0x00000004u	/* CMP0 IRQ --> IR1 */
#define OS_STM_CMP1EN		0x00000010u	/*	... same for CMP1 */
#define OS_STM_CMP1IR		0x00000020u
#define OS_STM_CMP1OS		0x00000040u
#define OS_STM_CMP1OS_IR0	0x00000000u
#define OS_STM_CMP1OS_IR1	0x00000040u
#define OS_STM_CMP0			0x00000007u
#define OS_STM_CMP1			0x00000070u

/* Bits in stm_iscr
*/
#define OS_STM_CMP0IRR	0x00000001u		/* Reset CMP0 irq */
#define OS_STM_CMP0IRS	0x00000002u		/* Set CMP0 irq */
#define OS_STM_CMP1IRR	0x00000004u		/* Reset CMP1 irq */
#define OS_STM_CMP1IRS	0x00000008u		/* Set CMP1 irq */

/* Constants for the OCS register.
*/
#define OS_STM_OCS_SUS_MASK			0x0F000000u
#define OS_STM_OCS_SUS_WILL_STOP	0x02000000u
#define OS_STM_OCS_SUS_WRITE_PROT	0x10000000u


#if !defined(OS_ASM)
/* The STM selected as timestamp timer.
*/
extern os_tricorestm_t * const OS_timestampStm;
#endif /* !defined(OS_ASM) */

#ifdef __cplusplus
}
#endif

#endif

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
