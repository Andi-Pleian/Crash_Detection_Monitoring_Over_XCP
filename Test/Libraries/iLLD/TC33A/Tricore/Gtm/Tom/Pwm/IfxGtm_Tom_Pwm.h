/**
 * \file IfxGtm_Tom_Pwm.h
 * \brief GTM PWM details
 * \ingroup IfxLld_Gtm
 *
 * \version iLLD_1_0_1_15_0_1
 * \copyright Copyright (c) 2019 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 * Use of this file is subject to the terms of use agreed between (i) you or
 * the company in which ordinary course of business you are acting and (ii)
 * Infineon Technologies AG or its licensees. If and as long as no such terms
 * of use are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * \defgroup IfxLld_Gtm_Tom_Pwm_Usage How to use the GTM TOM PWM Driver
 * \ingroup IfxLld_Gtm_Tom_Pwm
 *
 * This interface allows to generate simple PWM signal on a TOM out put and can generate interrupts if enabled.
 * this output can also be routed to port pin if required.
 *
 * \section Preparation Preparation
 * \subsection Include Include Files
 *
 * Include following header file into your C code:
 * \code
 *     #include <Gtm/Tom/Pwm/IfxGtm_Tom_Pwm.h>
 * \endcode
 *
 * \subsection Variables Variables
 * define global variables if necessary
 *
 * \code
 * Ifx_GTM *gtm = &MODULE_GTM;
 * #define TOM0_CH0_PRIO 10
 * \endcode
 *
 * \subsection Interrupts Interrupts
 * define Interrupts if needed
 *
 * \code
 * IFX_INTERRUPT(TOM0Ch0_ISR, 0, TOM0_CH0_PRIO)
 * {}
 * \endcode
 *
 * \subsection Initialization Initialization
 *
 * \code
 * // install interrupt handlers
 * IfxCpu_Irq_installInterruptHandler (TOM0Ch0_ISR, TOM0_CH0_PRIO);
 *
 * // enable GTM clock
 * {
 *     float32 frequency = IfxGtm_Cmu_getModuleFrequency(gtm);
 *     // Enables the GTM
 *     IfxGtm_enable(gtm);
 *     // Set the global clock frequency to the max
 *     IfxGtm_Cmu_setGclkFrequency(gtm, frequency);
 *     // Set the CMU CLK0
 *     IfxGtm_Cmu_setClkFrequency(gtm, IfxGtm_Cmu_Clk_0, frequency);
 *     // FXCLK: used by TOM and CLK0: used by ATOM
 *     IfxGtm_Cmu_enableClocks(gtm, IFXGTM_CMU_CLKEN_FXCLK | IFXGTM_CMU_CLKEN_CLK0);
 * }
 *
 * // initialise TOM
 * IfxGtm_Tom_Pwm_Config tomConfig;	\\configuration structure
 * IfxGtm_Tom_Pwm_Driver tomHandle;	\\ handle
 *
 * IfxGtm_Tom_Pwm_initConfig(&tomConfig, gtm);
 *
 * tomConfig.tomChannel  = IfxGtm_Tom_Ch_0;
 * tomConfig.period                   = 20;
 * tomConfig.dutyCycle              = 10;
 * tomConfig.interrupt.ccu0Enabled = TRUE;
 * tomConfig.interrupt.isrPriority = TOM0_CH0_PRIO;
 * tomConfig.pin.outputPin = &IfxGtm_TOM0_0_TOUT106_P10_4_OUT;
 *
 * IfxGtm_Tom_Pwm_init(&tomHandle, &tomConfig);
 * \endcode
 *
 * TOM will be now generating a PWM signal on the selected port pin while generating selected interrupt according to above configured period and duty cycle.
 *
 * \defgroup IfxLld_Gtm_Tom_Pwm TOM PWM Interface Driver
 * \ingroup IfxLld_Gtm_Tom
 * \defgroup IfxLld_Gtm_Tom_Pwm_DataStructures TOM PWM DataStructures
 * \ingroup IfxLld_Gtm_Tom_Pwm
 * \defgroup IfxLld_Gtm_Tom_Pwm_Pwm_Functions Pwm Functions
 * \ingroup IfxLld_Gtm_Tom_Pwm
 */

#ifndef IFXGTM_TOM_PWM_H
#define IFXGTM_TOM_PWM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_PinMap/IfxGtm_PinMap.h"
#include "Gtm/Std/IfxGtm_Tom.h"
#include "Gtm/Std/IfxGtm_Cmu.h"
#include "Gtm/Std/IfxGtm_Dtm.h"
#include "Cpu/Std/IfxCpu.h"

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Gtm_Tom_Pwm_DataStructures
 * \{ */
/** \brief configuration structure for interrupts
 */
typedef struct
{
    boolean        ccu0Enabled;       /**< \brief Enable/Disable choice for CCU0 trigger interrupt */
    boolean        ccu1Enabled;       /**< \brief Enable/Disable choice for CCU1 trigger interrupt */
    IfxGtm_IrqMode mode;              /**< \brief IRQ mode of interrupt */
    IfxSrc_Tos     isrProvider;       /**< \brief Type of Service for Ccu0/1 interrupt */
    Ifx_Priority   isrPriority;       /**< \brief Priority for Ccu0/1 interrupt */
} IfxGtm_Tom_Pwm_Interrupt;

/** \} */

/** \brief configuration structure for output pin
 */
typedef struct
{
    IfxGtm_Tom_ToutMap *outputPin;        /**< \brief output pin */
    IfxPort_OutputMode  outputMode;       /**< \brief Output mode */
    IfxPort_PadDriver   padDriver;        /**< \brief Pad driver */
} IfxGtm_Tom_Pwm_pin;

/** \addtogroup IfxLld_Gtm_Tom_Pwm_DataStructures
 * \{ */
/** \brief Configuration structure
 */
typedef struct
{
    Ifx_GTM                 *gtm;                            /**< \brief Pointer to GTM module */
    IfxGtm_Tom               tom;                            /**< \brief Index of the TOM object used */
    IfxGtm_Tom_Ch            tomChannel;                     /**< \brief TOM channel used for the timer */
    IfxGtm_Tom_Ch_ClkSrc     clock;                          /**< \brief Timer input clock */
    uint32                   period;                         /**< \brief Period */
    uint32                   dutyCycle;                      /**< \brief Duty Cycle */
    Ifx_ActiveState          signalLevel;                    /**< \brief Signal Level */
    boolean                  oneShotModeEnabled;             /**< \brief Enable/Disable the one shot mode */
    IfxGtm_Dtm_ClockSource   dtmClockSource;                 /**< \brief DTM clock source */
    boolean                  synchronousUpdateEnabled;       /**< \brief Synchronous or Asynchronous update */
    IfxGtm_Tom_Pwm_Interrupt interrupt;                      /**< \brief configuration structure for interrupt */
    IfxGtm_Tom_Pwm_pin       pin;                            /**< \brief configuration structure for output pin */
    boolean                  immediateStartEnabled;          /**< \brief enable/disable immediate start of PWM */
} IfxGtm_Tom_Pwm_Config;

/** \brief Driver Handle
 */
typedef struct
{
    Ifx_GTM         *gtm;              /**< \brief Pointer to GTM module */
    IfxGtm_Tom       tomIndex;         /**< \brief Index of the TOM object used */
    IfxGtm_Tom_Ch    tomChannel;       /**< \brief TOM channel used for the timer */
    Ifx_GTM_TOM     *tom;              /**< \brief Pointer to the TOM object */
    Ifx_GTM_TOM_TGC *tgc[2];           /**< \brief Pointer to the TGC object */
} IfxGtm_Tom_Pwm_Driver;

/** \} */

/** \addtogroup IfxLld_Gtm_Tom_Pwm_Pwm_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Initialises the Timer object
 * \param driver TOM Handle
 * \param config Configuration structure for TOM Timer
 * \return TRUE on success else FALSE
 */
IFX_EXTERN boolean IfxGtm_Tom_Pwm_init(IfxGtm_Tom_Pwm_Driver *driver, const IfxGtm_Tom_Pwm_Config *config);

/** \brief Initializes the configuration structure to default
 * \param config This parameter is Initialised by the function
 * \param gtm Pointer to GTM module
 * \return None
 */
IFX_EXTERN void IfxGtm_Tom_Pwm_initConfig(IfxGtm_Tom_Pwm_Config *config, Ifx_GTM *gtm);

/** \} */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief starts the PWM generation from the configured channel
 * \param driver handle for the PWM device
 * \param immediate immediate start or not
 * \return None
 */
IFX_EXTERN void IfxGtm_Tom_Pwm_start(IfxGtm_Tom_Pwm_Driver *driver, boolean immediate);

/** \brief Stops the PWM generation from the configured channel
 * \param driver handle for the PWM device
 * \param immediate immediate start or not.
 * \return None
 */
IFX_EXTERN void IfxGtm_Tom_Pwm_stop(IfxGtm_Tom_Pwm_Driver *driver, boolean immediate);

#endif /* IFXGTM_TOM_PWM_H */
