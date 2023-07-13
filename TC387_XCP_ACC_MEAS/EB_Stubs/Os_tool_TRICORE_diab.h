/* Os_tool_TRICORE_diab.h - Tricore macros for Diab
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_tool_TRICORE_diab.h 1.1 2017/12/21 16:35:20CET Postolache, Alexandru (uidu6496) none  $
*/

/*	This file contains macros (C and assembler) for use with Tricore
 *	and the gcc compiler.
*/

#ifndef OS_TOOL_TRICORE_DIAB_H
#define OS_TOOL_TRICORE_DIAB_H

#ifndef OS_ASM
#include <diab/asm.h>
#endif

#define OS_TOOL_INLINE_KEYWORD __inline__
#define OS_TOOL_ASM_KEYWORD __asm

/* OS_PARAM_UNUSED(p) - mark parameter p as unused parameter (or variable).
 * Usage: Function-like.
 */
#define OS_PARAM_UNUSED(p)

#ifdef OS_ASM
/* CHECK: SAVE
 * CHECK: RULE 402 OFF - These macros are for the assembler, not for C
*/

/*	The Diab assembler expects registers to be called %something
*/
#define a0		%a0
#define a1		%a1
#define a2		%a2
#define a3		%a3
#define a4		%a4
#define a5		%a5
#define a6		%a6
#define a7		%a7
#define a8		%a8
#define a9		%a9
#define a10		%a10
#define a11		%a11
#define a12		%a12
#define a13		%a13
#define a14		%a14
#define a15		%a15
#define d0		%d0
#define d1		%d1
#define d2		%d2
#define d3		%d3
#define d4		%d4
#define d5		%d5
#define d6		%d6
#define d7		%d7
#define d8		%d8
#define d9		%d9
#define d10		%d10
#define d11		%d11
#define d12		%d12
#define d13		%d13
#define d14		%d14
#define d15		%d15
#define e0		%e0
#define e2		%e2
#define e4		%e4
#define e6		%e6
#define e8		%e8
#define e10		%e10
#define e12		%e12
#define e14		%e14
#define sp		%sp

/*	The Diab assembler does not expect any special prefix for
 *	immediate operands.
*/
#define _IMM(p,x)		x

/* Reference to temporary label (preceding)
*/
#define OS_TEMPLABEL_PREV(l) l##b

/* Reference to temporary label (following)
*/
#define OS_TEMPLABEL_NEXT(l) l##f

/*	The Diab assembler uses EABI syntax for the bit specification in jz.t etc.
*/
#define _REGBIT(r,b)	r, b

/*	The Diab assembler uses x@ha and x@l to extract the
 *	high and low words from a literal.
*/
#define _hiword(x)		 x@ha
#define _loword(x)		 x@l

/*	Diab assembler uses .type, .globl and .extern as normal.
*/
#define _GTYPE(s,t)	.type	s,t
#define _TTYPE(s,t)	s:
#define _GLOBAL		.globl

/* external references are created using .extern or .xref */
#define _EXTERN		.xref


/*	Diab assembler has standard .text and .data sections
*/
#define	_TEXT	.text
#define _DATA	.data

/*	The Diab assembler provides .alignn to align with the unit of bytes.
 *	We do not use .align, because its unit can be influenced by the
 *	-Xalign-value/-Xalign-power2 compiler switches, whereas .alignn always
 *	uses bytes as the unit
*/
#define _align(n,p)		.alignn n

/* The Diab assembler has the .short and .half directives for 16-bit words */
#define _HWORD .half

/* CHECK: NOPARSE */

	.macro	_mtcr	creg,reg
		dsync
		mtcr	creg,reg
		isync
	.endm

	/*	The GenIntVector macro generates an interrupt vector with the
	 *	specified symbol, BISR-level, isr-id and entry function.
	*/
	.macro	GenIntVector	name,bisrlvl,isrid,entry,exit
	.alignn	32
	.globl	name
name:
	bisr	bisrlvl
	mov		d4,isrid
	call	entry
	j		exit
	.endm

	/*	The DirectVector macro generates an interrupt vector which jumps directly to the
	 *  entry. The entry needs to use the interrupt keyword.
	*/
	.macro	DirectVector	name,entry
		.alignn	32
		.globl	name
		.xref	entry
name:
		j		entry
	.endm

/* CHECK: PARSE */
/* CHECK: RESTORE */
#else /* !OS_ASM */

#ifdef __cplusplus
extern "C" {
#endif

OS_TOOL_ASM_KEYWORD volatile void OS_DEBUG_BREAK(void)
{
!
	debug
}

OS_TOOL_ASM_KEYWORD volatile void OS_ISYNC(void)
{
!
	isync
}

OS_TOOL_ASM_KEYWORD volatile void OS_DSYNC(void)
{
!
	dsync
}

OS_TOOL_ASM_KEYWORD volatile void OS_NOP(void)
{
!
	nop
}

#define OS_MFCR(CSFRID)			_mfcr(CSFRID)

#define OS_MTCR(csfr, val)		\
	do {						\
		_mtcr((csfr), (val));	\
		OS_ISYNC();				\
	} while (0)

/* This combination causes DIAB to always inline the function without generating
 * a callable version of it. Note that there are some options, most notably -g,
 * which disable inlining. So this is not reliable.
 */
#define OS_QUAL_INLINE static OS_TOOL_INLINE_KEYWORD
#define OS_ATTR_INLINE __attribute__((always_inline))


/* This function attribute will prevent DIAB from inlining the function for
 * optimisations.
 */
#define OS_ATTR_NO_INLINE __attribute__((noinline))


OS_TOOL_ASM_KEYWORD volatile os_uint32_t OS_MFSP(void)
{
! "%d2"
	mov.d %d2, %a10
}

OS_TOOL_ASM_KEYWORD volatile void *OS_MFA8(void)
{
! "%a2"
	mov.aa %a2, %a8
}

OS_TOOL_ASM_KEYWORD volatile os_uint32_t OS_MFRA(void)
{
! "%d2"
	mov.d %d2, %a11
}

OS_TOOL_ASM_KEYWORD volatile void OS_MTRA(void* val)
{
%reg val
! "%a11"
	mov.aa %a11, val
}

/* This one is used to store a function pointer. We need this only when very
 * restrictive compiler settings are used that disallow us to cast a function
 * pointer to a pointer to object (void*) */
OS_TOOL_ASM_KEYWORD volatile void OS_MTRA_FUNCPTR(void (*val)(void))
{
%reg val
! "%a11"
	mov.aa %a11, val
}

#define OS_MTA8(val) \
	do { \
		register void *mta8Tmp = (val); \
		OS_MTCR(OS_PSW, OS_MFCR(OS_PSW) | OS_PSW_GW); \
		OS_MTA8Impl(mta8Tmp); \
		OS_MTCR(OS_PSW, OS_MFCR(OS_PSW) & ~OS_PSW_GW); \
	} while (0)

OS_TOOL_ASM_KEYWORD volatile void OS_MTA8Impl(void* val)
{
%reg val
! "%a8"
	mov.aa %a8, val
}

OS_TOOL_ASM_KEYWORD volatile void OS_MTD4(os_uint32_t val)
{
%reg val
! "%d4"
	mov %d4, val
}

OS_TOOL_ASM_KEYWORD volatile void OS_DISABLE(void)
{
!
	disable
}

OS_TOOL_ASM_KEYWORD volatile void OS_ENABLE(void)
{
!
	enable
}

/* Macro to restore lower context
*/
OS_TOOL_ASM_KEYWORD volatile void OS_RSLCX(void)
{
!
	rslcx
}

/* Macro to return from a JL instruction. We call it RFJL, but it is
 * really only a JI A11.
*/

OS_TOOL_ASM_KEYWORD volatile void OS_RFJL(void)
{
!
	ji %a11
}

/* Macro to return from interrupt.
*/
OS_TOOL_ASM_KEYWORD volatile void OS_RFE(void)
{
!
	rfe
}

/* Macro to count leading zeros in a word
*/
OS_TOOL_ASM_KEYWORD volatile os_int_t OS_CLZ(os_int_t wurd)
{
%reg wurd;
! "%d2"
	clz	%d2, wurd
}

/* Cache operations: flush, invalidate and flush+invalidate
*/
OS_TOOL_ASM_KEYWORD volatile void OS_ArchCacheFlushLine(volatile void *p)
{
%reg p
!
	cachea.w [p]0
}
OS_TOOL_ASM_KEYWORD volatile void OS_ArchCacheInvalidateLine(volatile void *p)
{
%reg p
!
	cachea.i [p]0
}
OS_TOOL_ASM_KEYWORD volatile void OS_ArchCacheFlushInvalidateLine(volatile void *p)
{
%reg p
!
	cachea.wi [p]0
}

/* Atomic load-modify-store operations:
 * 	AtomicModifyFlag, AtomicAndNot, AtomicOr.
 * These operations will be mapped to TriCore's LDMST instruction.
 *
 * From the WindRiver TC manual:
 * Arguments to a macro are assigned to registers following the usual calling conventions. For example, four int arguments will use registers
 * %d4, %d5, %d6, and %d7, or in non-scratch registers.
 * Hence we have to move the mask/value to d4/d5 first for the operation, but know that this may
 * be unneeded but also not destroy anything.
 */
#define OS_ArchAtomicModifyFlag(addr, mask, value) OS_ArchAtomicModifyFlagImpl((volatile void*)(addr), (value), (mask))
OS_TOOL_ASM_KEYWORD volatile void OS_ArchAtomicModifyFlagImpl(volatile void *address, os_uint32_t value, os_uint32_t mask)
{
%reg address, value, mask;
! "%d4", "%d5"
	mov		%d4, value
	mov		%d5, mask
	ldmst	[address]0, %e4
}

#define OS_ArchAtomicAndNot(address, mask) OS_ArchAtomicModifyFlag((address), (mask), 0U)

#define OS_ArchAtomicOr(address, value) \
	do {\
		os_uint32_t OS_ArchAtomicOrValue;\
		OS_ArchAtomicOrValue = (os_uint32_t)(value);\
		OS_ArchAtomicModifyFlag((address), OS_ArchAtomicOrValue, OS_ArchAtomicOrValue);\
	} while(0)

#ifdef __cplusplus
}
#endif

#endif /* ! OS_ASM */

#endif

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
