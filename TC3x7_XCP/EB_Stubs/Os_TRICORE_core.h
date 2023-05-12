/* Os_TRICORE_core.h - Tricore core header
 *
 * This file contains definitions for features that are common across all
 * the Tricore CPUs, including the structure of context-save areas (CSAs)
 * and the addresses of the core special-function registers (CSFRs)
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_TRICORE_core.h 1.1 2017/12/21 16:35:16CET Postolache, Alexandru (uidu6496) none  $
*/

#ifndef OS_TRICORE_CORE_H
#define OS_TRICORE_CORE_H

#include <Os_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/* We check if the architecture is defined. The Os_<DERIVATE>.h file should set it. */

#ifndef OS_TRICOREARCH
#error "OS_TRICOREARCH not defined. Check Os_<DERIVATE>.h"
#endif


/*! os_tricoremodule_t
 *
 * Data structure for peripheral module header block.
 * Most of the peripheral modules on Tricore contain one of these at the
 * start of their address space, and the module needs initialisation before
 * the device can be used. We can use common code for this.
 *
 * Some peripheral modules don't implement all the registers of the header.
 * Some peripheral modules have register in the 'reserved' location.
 * None of that is of concern to us here.
*/
#ifndef OS_ASM
typedef struct os_tricoremodule_s
{
	os_reg32_t		clc;		/* Clock control register */
	os_reg32_t		reserved;	/* Some modules use this! */
	os_reg32_t		id;			/* Module identification register */
} os_tricoremodule_t;

#endif

/* Bit definitions for CLC */
#define OS_CLC_RMC	OS_U(0x0000ff00)	/* Clock divider (Rate mode control?) */
#define OS_CLC_FSOE	OS_U(0x00000020)	/* Fast shut-off enable */
#define OS_CLC_SBWE	OS_U(0x00000010)	/* Suspend bit write enable */
#define OS_CLC_EDIS	OS_U(0x00000008)	/* External request disable */
#define OS_CLC_SPEN	OS_U(0x00000004)	/* Suspend enable bit */
#define OS_CLC_DISS	OS_U(0x00000002)	/* Disable status bit */
#define OS_CLC_DISR	OS_U(0x00000001)	/* Disable request bit */

/* Bit definitions for ID */
#define OS_ID_MOD	OS_U(0xffff0000)	/* Module identification number */
#define OS_ID_TYPE	OS_U(0x0000ff00)	/* Module type */
#define OS_ID_MOD16	OS_U(0x0000ff00)	/* Module id (used to be 16-bit register) */
#define OS_ID_MOD32	OS_U(0x0000c000)	/* Indicates 32-bit register */
#define OS_ID_REV	OS_U(0x000000ff)	/* Module revision number */


/*	Move an integer value to the appropriate field. */
#define OS_CLC_RMCval(div)	(	(os_uint32_t)							\
								( ((os_uint32_t)(div) & 0xffffu) << 8 )	\
							)

/*	Extract the module ident (shifted to LSB) using appropriate field,
 *	taking account of 16/32 bit register types.
*/
#define Os_ModuleId(v)	( (((v)&OS_ID_MOD16) == OS_ID_MOD32)	\
							? ( ((v)>>16) & OS_U(0xffff) )		\
							: ( ((v)>>8) & OS_U(0xff) )			\
						)

/*! os_tricoresrn_t
 *
 * Data type for interrupt service request node. All generation of
 * interrupts on Tricore is done through one of these SRN registers.
 * We can use common code to program the priority, enable/disable, etc.
*/
#ifndef OS_ASM
typedef os_reg32_t	 os_tricoresrn_t;
#endif

#define OS_SRN_SETR		OS_U(0x04000000)	/* Request set bit */
#define OS_SRN_CLRR		OS_U(0x02000000)	/* Request clear bit */
#define OS_SRN_SRR		OS_U(0x01000000)	/* Service request bit */
#define OS_SRN_SRE		OS_U(0x00000400)	/* Service request enable */
#define	OS_SRN_SRPN		OS_U(0x000000ff)	/* Priority */

#ifndef OS_ASM
#define OS_SRN_TOS_CPU	OS_SRN_TOSval(OS_TricoreGetCoreId())	/* Interrupt the CPU */
#if (OS_TRICOREARCH == OS_TRICOREARCH_162)
#define OS_SRN_TOSval(tos)	(((tos)==0u)?0u:(((os_uint32_t)(((tos) & 7u)+1u))<<11u))
#else
#define OS_SRN_TOSval(tos)	((os_uint32_t)(((os_uint32_t)(((os_uint32_t)(tos)) & 0x3u)) << 11u))
#endif
#endif

#ifndef OS_ASM

void OS_InitModule(os_tricoremodule_t *, os_uint32_t, os_uint32_t);
void OS_SetupCache(os_boolean_t, os_boolean_t);

#endif

#ifndef OS_ASM

/* os_cx_t represents a CSA.
 * Such a CSA can be interpreted as upper context (os_uppercx_t)
 * or lower context (os_lowercx_t).
*/
typedef struct os_cx_s
{
	os_reg32_t pcxi;			/* link word */
	os_uint32_t reserved[15];	/* other registers depending on lower/upper context */
} os_cx_t;

typedef struct os_uppercx_s
{
	os_reg32_t pcxi;	/* link word */
	os_reg32_t psw;		/* processor status word */
	os_reg32_t a10;		/* Stack pointer. */
	os_reg32_t a11;		/* Return address register. */
	os_reg32_t d8;
	os_reg32_t d9;
	os_reg32_t d10;
	os_reg32_t d11;
	os_reg32_t a12;
	os_reg32_t a13;
	os_reg32_t a14;
	os_reg32_t a15;
	os_reg32_t d12;
	os_reg32_t d13;
	os_reg32_t d14;
	os_reg32_t d15;
} os_uppercx_t;

typedef struct os_lowercx_s
{
	os_reg32_t pcxi;	/* link word */
	os_reg32_t a11;		/* return address register. */
	os_reg32_t a2;
	os_reg32_t a3;
	os_reg32_t d0;
	os_reg32_t d1;
	os_reg32_t d2;
	os_reg32_t d3;
	os_reg32_t a4;
	os_reg32_t a5;
	os_reg32_t a6;
	os_reg32_t a7;
	os_reg32_t d4;
	os_reg32_t d5;
	os_reg32_t d6;
	os_reg32_t d7;
} os_lowercx_t;

#endif

/*	Offsets of saved registers in CSAs.
 *	For use in assembler modules - should never be used in C
*/
#ifdef OS_ASM

#define UPPERCX_PCXI	0x00
#define UPPERCX_PSW		0x04
#define UPPERCX_A10		0x08
#define UPPERCX_A11		0x0c

#define UPPERCX_D8		0x10
#define UPPERCX_D9		0x14
#define UPPERCX_D10		0x18
#define UPPERCX_D11		0x1c
#define UPPERCX_A12		0x20
#define UPPERCX_A13		0x24
#define UPPERCX_A14		0x28
#define UPPERCX_A15		0x2c
#define UPPERCX_D12		0x30
#define UPPERCX_D13		0x34
#define UPPERCX_D14		0x38
#define UPPERCX_D15		0x3c

#define LOWERCX_PCXI	0x00
#define LOWERCX_A11		0x04
#define LOWERCX_A2		0x08
#define LOWERCX_A3		0x0c
#define LOWERCX_D0		0x10
#define LOWERCX_D1		0x14
#define LOWERCX_D2		0x18
#define LOWERCX_D3		0x1c
#define LOWERCX_A4		0x20
#define LOWERCX_A5		0x24
#define LOWERCX_A6		0x28
#define LOWERCX_A7		0x2c
#define LOWERCX_D4		0x30
#define LOWERCX_D5		0x34
#define LOWERCX_D6		0x38
#define LOWERCX_D7		0x3c

#endif

/*	CSFR offsets. These offsets can be used
 *	with the mtcr/mfcr instructions, or can be added to a base address
 *	to get the absolute address for accesses via the bus.
*/

#define	OS_DPR0_L	0xc000	/* Data protection register 0, lower */
#define	OS_DPR0_U	0xc004	/* Data protection register 0, upper */
#define	OS_DPR1_L	0xc008	/* Data protection register 1, lower */
#define	OS_DPR1_U	0xc00c	/* Data protection register 1, upper */
#define	OS_DPR2_L	0xc010	/* Data protection register 2, lower */
#define	OS_DPR2_U	0xc014	/* Data protection register 2, upper */
#define	OS_DPR3_L	0xc018	/* Data protection register 3, lower */
#define	OS_DPR3_U	0xc01c	/* Data protection register 3, upper */
#define	OS_DPR4_L	0xc020	/* Data protection register 4, lower */
#define	OS_DPR4_U	0xc024	/* Data protection register 4, upper */
#define	OS_DPR5_L	0xc028	/* Data protection register 5, lower */
#define	OS_DPR5_U	0xc02c	/* Data protection register 5, upper */
#define	OS_DPR6_L	0xc030	/* Data protection register 6, lower */
#define	OS_DPR6_U	0xc034	/* Data protection register 6, upper */
#define	OS_CPR0_L	0xd000	/* Code protection register 0, lower */
#define	OS_CPR0_U	0xd004	/* Code protection register 0, upper */
#define	OS_CPR1_L	0xd008	/* Code protection register 1, lower */
#define	OS_CPR1_U	0xd00c	/* Code protection register 1, upper */
#define	OS_DPRE_0	0xe010	/* Data protection read enable set config register 0 */
#define	OS_DPRE_1	0xe014	/* Data protection read enable set config register 1 */
#define	OS_DPWE_0	0xe020	/* Data protection write enable set config register 0 */
#define	OS_DPWE_1	0xe024	/* Data protection write enable set config register 1 */
#define	OS_CPXE_0	0xe000	/* Code protection execute enable set config register 0 */
#define	OS_CPXE_1	0xe004	/* Code protection execute enable set config register 1 */

/* CSFR IDs/offsets */
#define OS_PMA0		0x8100
#define OS_PMA1		0x8104
#define OS_PCON0	0x920c
#define OS_DCON0	0x9040

#define	OS_DBGSR	0xfd00	/* Debug status register */
#define	OS_GPRWB	0xfd04	/* GPR write back trigger */
#define	OS_EXEVT	0xfd08	/* External break input event specifier */
#define	OS_CREVT	0xfd0c	/* Emulator resource protection event specifier */
#define	OS_SWEVT	0xfd10	/* Software break event specifier */
#define	OS_TR0EVT	0xfd20	/* Trigger event 0 specifier */
#define	OS_TR1EVT	0xfd24	/* Trigger event 1 specifier */

#define OS_DMS		0xfd40	/* Debug monitor start address register */
#define OS_DCX		0xfd44	/* Debug context save area pointer */

#define	OS_PCXI		0xfe00	/* Previous context information register */
#define	OS_PSW		0xfe04	/* Program status word */
#define	OS_PC		0xfe08	/* Program counter */
#define	OS_DBITEN	0xfe0c	/* Register bank dual bit enable register */
#define	OS_SYSCON	0xfe14	/* System configuration register */
#define	OS_BIV		0xfe20	/* Base address of interrupt vector table */
#define	OS_BTV		0xfe24	/* Base address of trap vector table */
#define	OS_ISP		0xfe28	/* Interrupt stack pointer */
#define	OS_ICR		0xfe2c	/* Interrupt unit control register */
#define	OS_FCX		0xfe38	/* Free CSA list head pointer */
#define	OS_LCX		0xfe3c	/* Free CSA list limit pointer */

#define OS_D0		0xff00	/* Data Register 0 */
#define OS_D1		0xff04	/* Data Register 1 */
#define OS_D2		0xff08	/* Data Register 2 */
#define OS_D3		0xff0c	/* Data Register 3 */
#define OS_D4		0xff10	/* Data Register 4 */
#define OS_D5		0xff14	/* Data Register 5 */
#define OS_D6		0xff18	/* Data Register 6 */
#define OS_D7		0xff1c	/* Data Register 7 */
#define OS_D8		0xff20	/* Data Register 8 */
#define OS_D9		0xff24	/* Data Register 9 */
#define OS_D10		0xff28	/* Data Register 10 */
#define OS_D11		0xff2c	/* Data Register 11 */
#define OS_D12		0xff30	/* Data Register 12 */
#define OS_D13		0xff34	/* Data Register 13 */
#define OS_D14		0xff38	/* Data Register 14 */
#define OS_D15		0xff3c	/* Data Register 15 */
#define OS_A0		0xff80	/* Address Register 0 */
#define OS_A1		0xff84	/* Address Register 1 */
#define OS_A2		0xff88	/* Address Register 2 */
#define OS_A3		0xff8c	/* Address Register 3 */
#define OS_A4		0xff90	/* Address Register 4 */
#define OS_A5		0xff94	/* Address Register 5 */
#define OS_A6		0xff98	/* Address Register 6 */
#define OS_A7		0xff9c	/* Address Register 7 */
#define OS_A8		0xffa0	/* Address Register 8 */
#define OS_A9		0xffa4	/* Address Register 9 */
#define OS_A10		0xffa8	/* Address Register 10 */
#define OS_A11		0xffac	/* Address Register 11 */
#define OS_A12		0xffb0	/* Address Register 12 */
#define OS_A13		0xffb4	/* Address Register 13 */
#define OS_A14		0xffb8	/* Address Register 14 */
#define OS_A15		0xffbc	/* Address Register 15 */

#define OS_CORE_ID	0xfe1c	/* core id register */

/* Bit definitions for PSW */
#define	OS_PSW_C			OS_U(0x80000000)		/* Carry */
#define	OS_PSW_V			OS_U(0x40000000)		/* Overflow */
#define OS_PSW_SV			OS_U(0x20000000)		/* Sticky overflow */
#define OS_PSW_AV			OS_U(0x10000000)		/* Advanced overflow */
#define OS_PSW_SAV			OS_U(0x08000000)		/* Sticky advanced overflow */
#if (OS_TRICOREARCH == OS_TRICOREARCH_162)
#define OS_PSW_PRS			OS_U(0x0000B000)		/* Protection register set (mask) */
#define OS_PSW_PRS_4		OS_U(0x00008000)		/*	--- Protection register set 5 */
#define OS_PSW_PRS_5		OS_U(0x00009000)		/*	--- Protection register set 6 */
#else
#define OS_PSW_PRS			OS_U(0x00003000)		/* Protection register set (mask) */
#endif
#define OS_PSW_PRS_0		OS_U(0x00000000)		/*	--- Protection register set 1 */
#define OS_PSW_PRS_1		OS_U(0x00001000)		/*	--- Protection register set 2 */
#define OS_PSW_PRS_2		OS_U(0x00002000)		/*	--- Protection register set 3 */
#define OS_PSW_PRS_3		OS_U(0x00003000)		/*	--- Protection register set 4 */
#define OS_PSW_IO			OS_U(0x00000C00)		/* I/O privelege mode. */
#define OS_PSW_IO_U0		OS_U(0x00000000)		/*	--- User 0 */
#define OS_PSW_IO_U1		OS_U(0x00000400)		/*	--- User 1 */
#define OS_PSW_IO_SU		OS_U(0x00000800)		/*	--- Supervisor */
#define OS_PSW_IO_RES		OS_U(0x00000C00)		/*	--- Reserved */
#define OS_PSW_IS			OS_U(0x00000200)		/* Interrupt stack in use */
#define OS_PSW_GW			OS_U(0x00000100)		/* Global register write perm. */
#define OS_PSW_CDE			OS_U(0x00000080)		/* Call depth count enable */
#define OS_PSW_CDC			OS_U(0x0000007F)		/* Call depth counter */
#define OS_PSW_CDC_DIS		OS_U(0x0000007F)		/*	--- Disable call depth ctr */
#define OS_PSW_CDC_6		OS_U(0x00000000)		/*	--- 6-bit call depth counter */
#define OS_PSW_CDC_5		OS_U(0x00000040)		/*	--- 5-bit call depth counter */
#define OS_PSW_CDC_4		OS_U(0x00000060)		/*	--- 4-bit call depth counter */
#define OS_PSW_CDC_3		OS_U(0x00000070)		/*	--- 3-bit call depth counter */
#define OS_PSW_CDC_2		OS_U(0x00000078)		/*	--- 2-bit call depth counter */
#define OS_PSW_CDC_1		OS_U(0x0000007C)		/*	--- 1-bit call depth counter */
#define OS_PSW_CDC_TRA		OS_U(0x0000007E)		/*	--- Call trace */

/*	Bit definitions for all context pointer registers (PCXI,FCX,LCX)
*/
#define OS_CX_SEG			OS_U(0x000F0000)		/* Segment number of CSA. */
#define OS_CX_OFF			OS_U(0x0000FFFF)		/* Index of CSA. */
#define OS_CX_CX			(OS_CX_SEG|OS_CX_OFF)	/* Entire context */

/*	Additiional bit definitions for PCXI. */
#define OS_PCXI_PCPN		OS_U(0xFFC00000)	/* Previous CPU priority. */
#define OS_PCXI_PCPN_BIT	22					/* Start bit of PCPN. */
#define OS_PCXI_PIE			OS_U(0x00200000)	/* Previous interrupt enable. */
#define OS_PCXI_PIE_BIT		21					/* Previous interrupt enable (bit number for j(n)z.t instructions) */
#define OS_PCXI_UL			OS_U(0x00100000)	/* Upper/lower context flag. */


/* Bit definitions for ICR. */
#define OS_ICR_IE			OS_U(0x00008000)	/* Interrupt enable. */
#define	OS_ICR_CONEC		OS_U(0)				/* no longer present in 1.6E/P */

#define OS_ICR_PIPN			OS_U(0x00FF0000)	/* Pending interrupt priority */
#define OS_ICR_CCPN			OS_U(0x000000FF)	/* Current CPU priority number. */

/* Bit definitions for SYSCON. */
#if (OS_TRICOREARCH == OS_TRICOREARCH_162)
#define OS_SYSCON_BHALT		OS_U(0x01000000)		/* Boot halt status and release */
#endif
#define OS_SYSCON_PROTEN	OS_U(0x00000002)		/* Enable memory protection. */
#define OS_SYSCON_ENDINIT	OS_U(0x00000001)		/* End of initialisation. */

/* Bit definitions for DBGSR. */
#define OS_DBGSR_DE_MASK		OS_U(0x00000001)	/* mask to get the DE-field */
#define OS_DBGSR_HALT_MASK		OS_U(0x00000006)	/* mask to get the HALT-field */

#define OS_DBGSR_DE_DISABLE		OS_U(0x00000000)	/* disable DE flag */
#define OS_DBGSR_DE_ENABLE		OS_U(0x00000001)	/* enable DE flag */
#define OS_DBGSR_HALT_HALTED	OS_U(0x00000002)	/* processor halted */
#define OS_DBGSR_HALT_RUNNING	OS_U(0x00000000)	/* processor running */
#define OS_DBGSR_HALT_WE		OS_U(0x00000004)	/* enable change of HALT-bit on write */

#ifndef OS_ASM

void OS_FreeCxList(os_uint32_t);
void OS_FreeCxListTo(os_uint32_t, os_uint32_t);
os_uint32_t OS_Grab1Csa(void);
os_uint32_t OS_Grab2Csa(void);

#define OS_ArchGetCoreId()     OS_GetMyCoreId()

#endif

/* OS_MTCCR
 *
 * Writes a value to a CR of another core using the memory mapped mirror of the core registers
*/
#define OS_MTCCR(csfrBase, csfrId, val) (*((os_reg32_t *)(((os_uint32_t)(csfrBase))+(csfrId)))=(val))

/* OS_MFCCR
 *
 * Reads the value from a CR of another core using the memory mapped mirror of the core registers
*/
#define OS_MFCCR(csfrBase, csfrId) (*((os_reg32_t *)(((os_uint32_t)(csfrBase))+(csfrId))))

/* OS_AddrFromCx() converts a CSA link word to an address.
 * No test is made for validity!
*/
#define OS_AddrFromCx(cx) \
	((void *)( (((cx) & OS_CX_SEG) << 12) + (((cx) & OS_CX_OFF) << 6) ))

/* OS_CxFromAddr() converts an address to a CSA link word.
 * No test is made for validity!
*/
#define OS_CxFromAddr(a) \
	( ((((os_address_t)(a)) >> 6) & OS_CX_OFF) +  ((((os_address_t)(a)) >> 12) & OS_CX_SEG) )

#ifdef __cplusplus
}
#endif

#endif

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
