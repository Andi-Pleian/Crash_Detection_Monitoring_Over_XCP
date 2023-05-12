/* $Id: board.h 1.1 2017/12/21 16:50:38CET Postolache, Alexandru (uidu6496) none  $
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
*/

#ifndef BOARD_H
#define BOARD_H

#include <Os_timeconversion.h>
#include <TRICORE/Os_TRICORE_cpu.h>
#include <TRICORE/Os_TRICORE_stm.h>
#include <TRICORE/Os_tool_TRICORE.h>


/*AlPo stub*/
#define OS_TRICORE_XCORESRCS {(os_tricoresrn_t *)0xF0038000u,(os_tricoresrn_t *)0xF0038004u,(os_tricoresrn_t *)0xF0038008u,(os_tricoresrn_t *)0xF003800Bu,(os_tricoresrn_t *)0xF003800Fu,(os_tricoresrn_t *)0xF0038014u}


/* The next few lines contain the initialization of the user LEDs on the board. */
/* 8 toogle LEDs connected to P33.4 ... P33.7 and P20.11 ... P20.14 */
#define BOARD_P20_BASE   0xf003b400U
#define BOARD_P33_BASE   0xf003c100U

#define BOARD_P20_OUT    OS_REG32(BOARD_P20_BASE+0x0U)
#define BOARD_P20_IOCR0  OS_REG32(BOARD_P20_BASE+0x10U)
#define BOARD_P20_IOCR4  OS_REG32(BOARD_P20_BASE+0x14U)
#define BOARD_P20_IOCR8  OS_REG32(BOARD_P20_BASE+0x18U)
#define BOARD_P20_IOCR12 OS_REG32(BOARD_P20_BASE+0x1cU)

#define BOARD_P33_OUT    OS_REG32(BOARD_P33_BASE+0x0U)
#define BOARD_P33_IOCR0  OS_REG32(BOARD_P33_BASE+0x10U)
#define BOARD_P33_IOCR4  OS_REG32(BOARD_P33_BASE+0x14U)
#define BOARD_P33_IOCR8  OS_REG32(BOARD_P33_BASE+0x18U)
#define BOARD_P33_IOCR12 OS_REG32(BOARD_P33_BASE+0x1cU)

#define	LEDS_SET(x)\
		do {\
			BOARD_P33_OUT = (BOARD_P33_OUT & ~0x00f0U) | (((~(x))&0x0fU) << 4U);\
			BOARD_P20_OUT = (BOARD_P20_OUT & ~0x7800U) | (((~(x))&0xf0U) << 7U);\
		}	while (0)

#define	LEDS_GET()  (((BOARD_P20_OUT>>7U) & 0xf0U) | ((BOARD_P33_OUT>>4U) & 0x0fU))

#define	LEDS_INIT()\
		do {\
			BOARD_P33_IOCR4  = 0x80808080u;\
			BOARD_P20_IOCR8  = 0x80101010u;\
			BOARD_P20_IOCR12 = 0x10808080u;\
		} while (0)

#define BOARD_USE_BACKUP_CLOCK 0
#define BOARD_BACKUP_CLOCK_MHZ 100u

#if BOARD_USE_BACKUP_CLOCK==1

#define BOARD_SYS_FREQ			100000000U			/* SRI clock [Hz] */

#else

/* 20 MHz crystal frequency.
 */
#define BOARD_XTAL_FREQ			20000000U

/* Select the desired SRI frequency from one of the available values
 *
 * The PLL must be programmed to achieve these frequencies.
 *
 * If any other frequency is required the correct PLL settings will need to be determined.
 * If you change the running frequency of the board, you must
 * also change the NsToTicks and TicksToNs macros below.
*/
#define BOARD_SYS_FREQ			200000000U			/* SRI clock [Hz] */
#define BOARD_CPU_FREQ_HZ		200000000			/* Just here for performance tests */

#if (BOARD_XTAL_FREQ==20000000U) && (BOARD_SYS_FREQ==180000000U)
/*
 * P    = 1; N    = 36; K2    = 4;
 * PDIV = 1; NDIV = 71; K2DIV = 3;
 *
 * Input to VCO is 20MHz/1 = 20 MHz.
 * PLL runs at 20MHz*36 = 720 MHz, which is within the 400 - 800MHz operating range.
 * Output is 720MHz/4 = 180 MHz.
 *
 * The macros BOARD_P, BOARD_N, BOARD_K1 and BOARD_K2 are the "true" values of P, N, K1 and K2
*/
#define BOARD_P					1U
#define BOARD_N					36U
#define BOARD_K2				4U
#define BOARD_K2_INITIAL		5U /* start with 90 MHz */
#define BOARD_K1				1U
#define BOARD_K3				8U /* fPLL2 @90 MHz */

#elif (BOARD_XTAL_FREQ==20000000U) && (BOARD_SYS_FREQ==150000000U)
/*
 * P = 1;  N = 30;  K2 = 4;
 *
 * Input to VCO is 20MHz/1 = 20 MHz.
 * PLL runs at 20MHz*30 = 600 MHz, which is within the 400 - 800MHz operating range.
 * Output is 600MHz/4 = 150 MHz.
 *
 * The macros BOARD_P, BOARD_N, BOARD_K1 and BOARD_K2 are the "true" values of P, N, K1 and K2
*/
#define BOARD_P					1U
#define BOARD_N					30U
#define BOARD_K2				4U
#define BOARD_K2_INITIAL		6U /* start with 100 MHz */
#define BOARD_K1				1U
#define BOARD_K3				6U /* fPLL2 @100 MHz */

#elif (BOARD_XTAL_FREQ==20000000U) && (BOARD_SYS_FREQ==200000000U)
/*
 * P = 1;  N = 40;  K2 = 3;
 *
 * Input to VCO is 20MHz/1 = 20 MHz.
 * PLL runs at 20MHz*40 = 800 MHz, which is within the 400 - 800MHz operating range.
 * Output is 800MHz/4 = 200 MHz.
 *
 * The macros BOARD_P, BOARD_N, BOARD_K1 and BOARD_K2 are the "true" values of P, N, K1 and K2
*/
#define BOARD_P					1U
#define BOARD_N					40U
#define BOARD_K2				4U
#define BOARD_K2_INITIAL		8U /* start with 100 MHz */
#define BOARD_K1				1U
#define BOARD_K3				8U /* fPLL2 @100 MHz */

#elif (BOARD_XTAL_FREQ==20000000U) && (BOARD_SYS_FREQ==250000000U)
/*
 * P = 1;  N = 25;  K2 = 2;
 *
 * Input to VCO is 20MHz/1 = 20 MHz.
 * PLL runs at 20MHz*25 = 500 MHz, which is within the 400 - 800MHz operating range.
 * Output is 500MHz/2 = 250 MHz.
 *
 * The macros BOARD_P, BOARD_N, BOARD_K1 and BOARD_K2 are the "true" values of P, N, K1 and K2
*/
#define BOARD_P					1U
#define BOARD_N					25U
#define BOARD_K2				2U
#define BOARD_K2_INITIAL		5U /* start with 100 MHz */
#define BOARD_K1				1U
#define BOARD_K3				5U /* fPLL2 @100 MHz */

#elif (BOARD_XTAL_FREQ==20000000U) && (BOARD_SYS_FREQ==300000000U)
/*
 * P = 1;  N = 30;  K2 = 2;
 *
 * Input to VCO is 20MHz/1 = 20 MHz.
 * PLL runs at 20MHz*30 = 600 MHz, which is within the 400 - 800MHz operating range.
 * Output is 600MHz/2 = 300 MHz.
 *
 * The macros BOARD_P, BOARD_N, BOARD_K1 and BOARD_K2 are the "true" values of P, N, K1 and K2
*/
#define BOARD_P					1U
#define BOARD_N					30U
#define BOARD_K2				2U
#define BOARD_K2_INITIAL		6U /* start with 100 MHz */
#define BOARD_K1				1U
#define BOARD_K3				6U /* fPLL2 @100 MHz */

#define BOARD_CPU2_DIV			21u /* core 2 runs at 201.5625 MHz (300 MHz * (64-21)/64) */

#else
#error "You must define appropriate P, N, K1 and K2 values for this combination of crystal and CPU speed."
#endif
#endif

#define BOARD_VCO_FREQ			(BOARD_XTAL_FREQ * BOARD_N / BOARD_P)

#if defined(BOARD_P) && defined(BOARD_N) && defined(BOARD_K1) && defined(BOARD_K2) && defined(BOARD_K3)
/*
 * These definitions should work for all valid combinations of P, N, K1 and K2.
 * The macros represent the base values of PLLCON0 and PLLCON1; extra bits that need
 * to be set and then cleared in order to kick-start the PLL are added by software in board.c
 *
 * The bit OSCDISCDIS is set.
 *
 * Besides PLL settings, the clock dividers inside the clock control unit (CCU) are set up.
*/
#define BOARD_INITIAL_PLLCON0		(OS_PLL_SET_P(BOARD_P)|OS_PLL_SET_N(BOARD_N)|OS_PLL_PLLPWD|OS_PLLCON0_INSEL_FOSC_AS_CLK_SOURCE)
#define BOARD_INITIAL_PLLCON1		(OS_PLL_SET_K2(BOARD_K2_INITIAL))

#elif BOARD_USE_BACKUP_CLOCK==1

#else
#error "The crystal versus CPU speed selection above does not set the divider macros correctly!"
#endif

#define BOARD_INITIAL_CCUCON_DIV_MASK	0x0FFFFFFFU

#define BOARD_FSI2_DIV 1u /* 0 (stopped), 1, 2, 3; input fSRI */
#define BOARD_BBB_DIV  2u /* 0 (stopped), 1, 2, 3, 4, 5, 6, 8, 10, 12, 15; input fPLL */
#define BOARD_SRI_DIV  1u /* 1, 2, 3, 4, 5, 6, 8, 10, 12, 15; input fPLL*/
#define BOARD_LP_DIV   0u /* 0 (do not use LP_DIV), 1, 2, 3, 4 (see manual for meaning) */

#if BOARD_SYS_FREQ <= 200000000U
#define BOARD_FSI_DIV  2u /* 0 (stopped), 1, 2, 3; input fSRI*/
#define BOARD_SPB_DIV  3u /* 2, 3, 4, 5, 6, 8, 10, 12, 15; input fPLL */
#define BOARD_STM_DIV  2u /* 0 (stopped), 1, 2, 3, 4, 5, 6, 8, 10, 12, 15; input fPLL */
#define BOARD_GTM_DIV  2u /* 0 (stopped), 1, 2, 3, 4, 5, 6, 8, 10, 12, 15; input fPLL */

#else /* BOARD_SYS_FREQ <= 300 MHz */
#error "Please define clock divider macros for your chosen BOARD_SYS_FREQ"

#endif

#if (BOARD_SYS_FREQ <= 200000000U)
#define BOARD_INITIAL_CCUCON0_DIV ( \
    (BOARD_FSI2_DIV << 26u) | \
	(BOARD_FSI_DIV  << 24u) | \
	(BOARD_BBB_DIV  << 20u) | \
	(BOARD_SPB_DIV  << 16u) | \
    (BOARD_LP_DIV   << 12u) | \
	(BOARD_SRI_DIV  <<  8u) | \
	(BOARD_GTM_DIV  <<  4u) | \
	BOARD_STM_DIV \
	)
#else
#error "Please define clock divider macros for your chosen BOARD_SYS_FREQ"
#endif /*(BOARD_SYS_FREQ <= 200000000U)*/

/* By default the SCU clocks the STM modules with f_source/2, whereat f_sys is the PLL's output in
 * this configuration (see register CCUCON1 field STMDIV).
 * If the user changes this during startup, the following macro needs to be adapted.
 */
#define BOARD_Fstm_FREQ			((BOARD_SYS_FREQ)/BOARD_STM_DIV)

/*!
 * OS_BoardNsToTicks() and OS_BoardTicksToNs()
 *
 * OS_BoardNsToTicks() converts nanoseconds (nS) to ticks. This macro must
 * compute entirely in the preprocessor, because it is used to initialise time
 * tables.
 * The calculation for this board is ns * Fmod / 1000000000.
 *
*/
#if (BOARD_Fstm_FREQ == 90000000U)
#define OS_BoardNsToTicks(nS)	OS_NsToTicks_90000000(nS)
#define OS_BoardTicksToNs(tik)	OS_TicksToNs_90000000(tik)

#elif (BOARD_Fstm_FREQ == 75000000U)
#define OS_BoardNsToTicks(nS)	OS_NsToTicks_75000000(nS)
#define OS_BoardTicksToNs(tik)	OS_TicksToNs_75000000(tik)

#elif (BOARD_Fstm_FREQ == 50000000U)
#define OS_BoardNsToTicks(nS)	OS_NsToTicks_50000000(nS)
#define OS_BoardTicksToNs(tik)	OS_TicksToNs_50000000(tik)

#elif (BOARD_Fstm_FREQ == 100000000U)
#define OS_BoardNsToTicks(nS)	OS_NsToTicks_100000000(nS)
#define OS_BoardTicksToNs(tik)	OS_TicksToNs_100000000(tik)

#else
#error "You must configure the above macros for the BOARD_Fstm_FREQ frequency"
#endif


/* Note to OS_STM_PRESCALE: This value is used for initialization of STMs and calculation of times.
 * The TC29XT derivative does not offer RMC fields in the STM's clock control registers (CLC), hence
 * all STMs use the same input frequency.
 * Therefore, this macro is set to one, to make it behave neutrally in calculations.
 */
#define OS_STM_PRESCALE		1U

/*
 * define CPUx clock dividers in (64-BOARD_CPUx_DIV)/64, i.e. divider value 0 means fCPUx = fSRI
 * We set defaults here to 64u, override above as needed
 */
#ifndef BOARD_CPU0_DIV
#define BOARD_CPU0_DIV 0u
#endif
#ifndef BOARD_CPU1_DIV
#define BOARD_CPU1_DIV 0u
#endif
#ifndef BOARD_CPU2_DIV
#define BOARD_CPU2_DIV 0u
#endif

#include <TRICORE/Os_TRICORE_stmconfig.h>

#if (BOARD_SYS_FREQ) > 300000000u
#error "Maximum fPLL is 300 MHz"
#endif

#if BOARD_BBB_DIV > BOARD_SPB_DIV
#error "fBBB has to be faster or equal to fSPB"
#endif

#if (BOARD_SYS_FREQ / BOARD_SPB_DIV) > 100000000u
#error "Maximum fSPB is 100 MHz"
#endif

#if (BOARD_SYS_FREQ / BOARD_FSI_DIV) > 100000000u
#error "Maximum fFSI is 100 MHz"
#endif

#if BOARD_Fstm_FREQ > 100000000u
#error "Maximum fSTM is 100 MHz"
#endif

#if (BOARD_SYS_FREQ / BOARD_GTM_DIV) > 100000000u
#error "Maximum fGTM is 100 MHz"
#endif

#if (BOARD_SYS_FREQ / BOARD_BBB_DIV) > 150000000u
#error "Maximum fBBB is 150 MHz"
#endif


/* This is the initial PSW value:
 *   - call depth count disabled
 *   - supervisor mode
 *   - protection register set 0
 *   - interrupt stack (so we don't have to initialise the IS register yet)
*/
#define OS_INITIAL_PSW		(OS_PSW_CDC_DIS+OS_PSW_IO_SU+OS_PSW_PRS_0+OS_PSW_IS)

#define BOARD_TRICORE_BMI 0x0070 /* internal start from flash */
#define BOARD_TRICORE_BOOTWORD    0xa0000020

#ifndef OS_ASM
void BoardStart(void);
void boardInitStm(os_tricorestm_t *stm);
#endif
#endif
/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/