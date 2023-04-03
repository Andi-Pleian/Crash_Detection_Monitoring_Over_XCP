/**
 * \file IfxHspdm_PinMap.h
 * \brief HSPDM I/O map
 * \ingroup IfxLld_Hspdm
 *
 * \version iLLD_1_0_1_15_0_1
 * \copyright Copyright (c) 2017 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_Hspdm_pinmap HSPDM Pin Mapping
 * \ingroup IfxLld_Hspdm
 */

#ifndef IFXHSPDM_PINMAP_H
#define IFXHSPDM_PINMAP_H

#include <IfxHspdm_reg.h>
#include <_Impl/IfxHspdm_cfg.h>
#include <Port/Std/IfxPort.h>

/** \addtogroup IfxLld_Hspdm_pinmap
 * \{ */

/** \brief HSPDM BS pin mapping structure */
typedef const struct
{
    Ifx_HSPDM*         module;    /**< \brief Base address */
    IfxPort_Pin       pin;       /**< \brief Port pin */
    IfxPort_OutputIdx select;    /**< \brief Port control code */
} IfxHspdm_Bs_Out;

/** \brief HSPDM MUTE pin mapping structure */
typedef const struct
{
    Ifx_HSPDM*         module;    /**< \brief Base address */
    IfxPort_Pin       pin;       /**< \brief Port pin */
    IfxPort_OutputIdx select;    /**< \brief Port control code */
} IfxHspdm_Mute_Out;

IFX_EXTERN IfxHspdm_Bs_Out IfxHspdm0_BS0_OUT_P22_4_OUT;  /**< \brief Bit stream 0 output to the pad */
IFX_EXTERN IfxHspdm_Bs_Out IfxHspdm0_BS1_OUT_P22_5_OUT;  /**< \brief Bit stream 1 output to the pad */
IFX_EXTERN IfxHspdm_Mute_Out IfxHspdm0_MUTE_P22_3_OUT;  /**< \brief Mute output from the micro controller which could be used to control an external Transmitter */

/** \brief Table dimensions */
#define IFXHSPDM_PINMAP_NUM_MODULES 1
#define IFXHSPDM_PINMAP_NUM_0S 1
#define IFXHSPDM_PINMAP_BS_OUT_NUM_ITEMS 2
#define IFXHSPDM_PINMAP_MUTE_OUT_NUM_ITEMS 1


/** \brief IfxHspdm_Bs_Out table */
IFX_EXTERN const IfxHspdm_Bs_Out *IfxHspdm_Bs_Out_pinTable[IFXHSPDM_PINMAP_NUM_MODULES][IFXHSPDM_PINMAP_NUM_0S][IFXHSPDM_PINMAP_BS_OUT_NUM_ITEMS];

/** \brief IfxHspdm_Mute_Out table */
IFX_EXTERN const IfxHspdm_Mute_Out *IfxHspdm_Mute_Out_pinTable[IFXHSPDM_PINMAP_NUM_MODULES][IFXHSPDM_PINMAP_NUM_0S][IFXHSPDM_PINMAP_MUTE_OUT_NUM_ITEMS];

/** \} */

#endif /* IFXHSPDM_PINMAP_H */
