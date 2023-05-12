/**
 * \file IfxMinimcds_bf.h
 * \brief
 * \copyright Copyright (c) 2015 Infineon Technologies AG. All rights reserved.
 *
 *
 * Date: 2015-12-17 16:15:04 GMT
 * Version: TBD
 * Specification: TBD
 * MAY BE CHANGED BY USER [yes/no]: No
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 * \defgroup IfxLld_Minimcds_Registers_BitfieldsMask Bitfields mask and offset
 * \ingroup IfxLld_Minimcds_Registers
 * 
 */
#ifndef IFXMINIMCDS_BF_H
#define IFXMINIMCDS_BF_H 1
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxLld_Minimcds_BitfieldsMask
 * \{  */
/** \brief Length for Ifx_MINIMCDS_CLC_Bits.DISR */
#define IFX_MINIMCDS_CLC_DISR_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_CLC_Bits.DISR */
#define IFX_MINIMCDS_CLC_DISR_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_CLC_Bits.DISR */
#define IFX_MINIMCDS_CLC_DISR_OFF (0u)

/** \brief Length for Ifx_MINIMCDS_CLC_Bits.DISS */
#define IFX_MINIMCDS_CLC_DISS_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_CLC_Bits.DISS */
#define IFX_MINIMCDS_CLC_DISS_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_CLC_Bits.DISS */
#define IFX_MINIMCDS_CLC_DISS_OFF (1u)

/** \brief Length for Ifx_MINIMCDS_OCS_Bits.SUS */
#define IFX_MINIMCDS_OCS_SUS_LEN (4u)

/** \brief Mask for Ifx_MINIMCDS_OCS_Bits.SUS */
#define IFX_MINIMCDS_OCS_SUS_MSK (0xfu)

/** \brief Offset for Ifx_MINIMCDS_OCS_Bits.SUS */
#define IFX_MINIMCDS_OCS_SUS_OFF (24u)

/** \brief Length for Ifx_MINIMCDS_OCS_Bits.SUS_P */
#define IFX_MINIMCDS_OCS_SUS_P_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_OCS_Bits.SUS_P */
#define IFX_MINIMCDS_OCS_SUS_P_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_OCS_Bits.SUS_P */
#define IFX_MINIMCDS_OCS_SUS_P_OFF (28u)

/** \brief Length for Ifx_MINIMCDS_OCS_Bits.SUSSTA */
#define IFX_MINIMCDS_OCS_SUSSTA_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_OCS_Bits.SUSSTA */
#define IFX_MINIMCDS_OCS_SUSSTA_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_OCS_Bits.SUSSTA */
#define IFX_MINIMCDS_OCS_SUSSTA_OFF (29u)

/** \brief Length for Ifx_MINIMCDS_ID_Bits.MOD_REV */
#define IFX_MINIMCDS_ID_MOD_REV_LEN (8u)

/** \brief Mask for Ifx_MINIMCDS_ID_Bits.MOD_REV */
#define IFX_MINIMCDS_ID_MOD_REV_MSK (0xffu)

/** \brief Offset for Ifx_MINIMCDS_ID_Bits.MOD_REV */
#define IFX_MINIMCDS_ID_MOD_REV_OFF (0u)

/** \brief Length for Ifx_MINIMCDS_ID_Bits.MOD_TYPE */
#define IFX_MINIMCDS_ID_MOD_TYPE_LEN (8u)

/** \brief Mask for Ifx_MINIMCDS_ID_Bits.MOD_TYPE */
#define IFX_MINIMCDS_ID_MOD_TYPE_MSK (0xffu)

/** \brief Offset for Ifx_MINIMCDS_ID_Bits.MOD_TYPE */
#define IFX_MINIMCDS_ID_MOD_TYPE_OFF (8u)

/** \brief Length for Ifx_MINIMCDS_ID_Bits.MOD_NUMBER */
#define IFX_MINIMCDS_ID_MOD_NUMBER_LEN (16u)

/** \brief Mask for Ifx_MINIMCDS_ID_Bits.MOD_NUMBER */
#define IFX_MINIMCDS_ID_MOD_NUMBER_MSK (0xffffu)

/** \brief Offset for Ifx_MINIMCDS_ID_Bits.MOD_NUMBER */
#define IFX_MINIMCDS_ID_MOD_NUMBER_OFF (16u)

/** \brief Length for Ifx_MINIMCDS_CT_Bits.KOK */
#define IFX_MINIMCDS_CT_KOK_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_CT_Bits.KOK */
#define IFX_MINIMCDS_CT_KOK_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_CT_Bits.KOK */
#define IFX_MINIMCDS_CT_KOK_OFF (5u)

/** \brief Length for Ifx_MINIMCDS_CT_Bits.KAV */
#define IFX_MINIMCDS_CT_KAV_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_CT_Bits.KAV */
#define IFX_MINIMCDS_CT_KAV_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_CT_Bits.KAV */
#define IFX_MINIMCDS_CT_KAV_OFF (7u)

/** \brief Length for Ifx_MINIMCDS_CT_Bits.EN */
#define IFX_MINIMCDS_CT_EN_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_CT_Bits.EN */
#define IFX_MINIMCDS_CT_EN_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_CT_Bits.EN */
#define IFX_MINIMCDS_CT_EN_OFF (13u)

/** \brief Length for Ifx_MINIMCDS_CT_Bits.CLRE */
#define IFX_MINIMCDS_CT_CLRE_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_CT_Bits.CLRE */
#define IFX_MINIMCDS_CT_CLRE_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_CT_Bits.CLRE */
#define IFX_MINIMCDS_CT_CLRE_OFF (14u)

/** \brief Length for Ifx_MINIMCDS_CT_Bits.SETE */
#define IFX_MINIMCDS_CT_SETE_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_CT_Bits.SETE */
#define IFX_MINIMCDS_CT_SETE_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_CT_Bits.SETE */
#define IFX_MINIMCDS_CT_SETE_OFF (15u)

/** \brief Length for Ifx_MINIMCDS_CT_Bits.BED */
#define IFX_MINIMCDS_CT_BED_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_CT_Bits.BED */
#define IFX_MINIMCDS_CT_BED_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_CT_Bits.BED */
#define IFX_MINIMCDS_CT_BED_OFF (16u)

/** \brief Length for Ifx_MINIMCDS_CT_Bits.BED_P */
#define IFX_MINIMCDS_CT_BED_P_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_CT_Bits.BED_P */
#define IFX_MINIMCDS_CT_BED_P_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_CT_Bits.BED_P */
#define IFX_MINIMCDS_CT_BED_P_OFF (19u)

/** \brief Length for Ifx_MINIMCDS_CT_Bits.IRA */
#define IFX_MINIMCDS_CT_IRA_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_CT_Bits.IRA */
#define IFX_MINIMCDS_CT_IRA_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_CT_Bits.IRA */
#define IFX_MINIMCDS_CT_IRA_OFF (21u)

/** \brief Length for Ifx_MINIMCDS_CT_Bits.CLRI */
#define IFX_MINIMCDS_CT_CLRI_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_CT_Bits.CLRI */
#define IFX_MINIMCDS_CT_CLRI_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_CT_Bits.CLRI */
#define IFX_MINIMCDS_CT_CLRI_OFF (22u)

/** \brief Length for Ifx_MINIMCDS_CT_Bits.IWA */
#define IFX_MINIMCDS_CT_IWA_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_CT_Bits.IWA */
#define IFX_MINIMCDS_CT_IWA_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_CT_Bits.IWA */
#define IFX_MINIMCDS_CT_IWA_OFF (23u)

/** \brief Length for Ifx_MINIMCDS_CT_Bits.RES */
#define IFX_MINIMCDS_CT_RES_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_CT_Bits.RES */
#define IFX_MINIMCDS_CT_RES_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_CT_Bits.RES */
#define IFX_MINIMCDS_CT_RES_OFF (29u)

/** \brief Length for Ifx_MINIMCDS_CT_Bits.SETR */
#define IFX_MINIMCDS_CT_SETR_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_CT_Bits.SETR */
#define IFX_MINIMCDS_CT_SETR_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_CT_Bits.SETR */
#define IFX_MINIMCDS_CT_SETR_OFF (31u)

/** \brief Length for Ifx_MINIMCDS_MUX_Bits.TMUX0 */
#define IFX_MINIMCDS_MUX_TMUX0_LEN (4u)

/** \brief Mask for Ifx_MINIMCDS_MUX_Bits.TMUX0 */
#define IFX_MINIMCDS_MUX_TMUX0_MSK (0xfu)

/** \brief Offset for Ifx_MINIMCDS_MUX_Bits.TMUX0 */
#define IFX_MINIMCDS_MUX_TMUX0_OFF (0u)

/** \brief Length for Ifx_MINIMCDS_MUX_Bits.TM_P0 */
#define IFX_MINIMCDS_MUX_TM_P0_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_MUX_Bits.TM_P0 */
#define IFX_MINIMCDS_MUX_TM_P0_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_MUX_Bits.TM_P0 */
#define IFX_MINIMCDS_MUX_TM_P0_OFF (7u)

/** \brief Length for Ifx_MINIMCDS_MUX_Bits.TMUX1 */
#define IFX_MINIMCDS_MUX_TMUX1_LEN (4u)

/** \brief Mask for Ifx_MINIMCDS_MUX_Bits.TMUX1 */
#define IFX_MINIMCDS_MUX_TMUX1_MSK (0xfu)

/** \brief Offset for Ifx_MINIMCDS_MUX_Bits.TMUX1 */
#define IFX_MINIMCDS_MUX_TMUX1_OFF (8u)

/** \brief Length for Ifx_MINIMCDS_MUX_Bits.TM_P1 */
#define IFX_MINIMCDS_MUX_TM_P1_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_MUX_Bits.TM_P1 */
#define IFX_MINIMCDS_MUX_TM_P1_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_MUX_Bits.TM_P1 */
#define IFX_MINIMCDS_MUX_TM_P1_OFF (15u)

/** \brief Length for Ifx_MINIMCDS_MUX_Bits.TMUX2 */
#define IFX_MINIMCDS_MUX_TMUX2_LEN (4u)

/** \brief Mask for Ifx_MINIMCDS_MUX_Bits.TMUX2 */
#define IFX_MINIMCDS_MUX_TMUX2_MSK (0xfu)

/** \brief Offset for Ifx_MINIMCDS_MUX_Bits.TMUX2 */
#define IFX_MINIMCDS_MUX_TMUX2_OFF (16u)

/** \brief Length for Ifx_MINIMCDS_MUX_Bits.TM_P2 */
#define IFX_MINIMCDS_MUX_TM_P2_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_MUX_Bits.TM_P2 */
#define IFX_MINIMCDS_MUX_TM_P2_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_MUX_Bits.TM_P2 */
#define IFX_MINIMCDS_MUX_TM_P2_OFF (23u)

/** \brief Length for Ifx_MINIMCDS_MUX_Bits.TMUX3 */
#define IFX_MINIMCDS_MUX_TMUX3_LEN (4u)

/** \brief Mask for Ifx_MINIMCDS_MUX_Bits.TMUX3 */
#define IFX_MINIMCDS_MUX_TMUX3_MSK (0xfu)

/** \brief Offset for Ifx_MINIMCDS_MUX_Bits.TMUX3 */
#define IFX_MINIMCDS_MUX_TMUX3_OFF (24u)

/** \brief Length for Ifx_MINIMCDS_MUX_Bits.TM_P3 */
#define IFX_MINIMCDS_MUX_TM_P3_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_MUX_Bits.TM_P3 */
#define IFX_MINIMCDS_MUX_TM_P3_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_MUX_Bits.TM_P3 */
#define IFX_MINIMCDS_MUX_TM_P3_OFF (31u)

/** \brief Length for Ifx_MINIMCDS_MUX_TC_RC_Bits.TC_MUX0 */
#define IFX_MINIMCDS_MUX_TC_RC_TC_MUX0_LEN (2u)

/** \brief Mask for Ifx_MINIMCDS_MUX_TC_RC_Bits.TC_MUX0 */
#define IFX_MINIMCDS_MUX_TC_RC_TC_MUX0_MSK (0x3u)

/** \brief Offset for Ifx_MINIMCDS_MUX_TC_RC_Bits.TC_MUX0 */
#define IFX_MINIMCDS_MUX_TC_RC_TC_MUX0_OFF (0u)

/** \brief Length for Ifx_MINIMCDS_MUX_TC_RC_Bits.TC_MUX1 */
#define IFX_MINIMCDS_MUX_TC_RC_TC_MUX1_LEN (2u)

/** \brief Mask for Ifx_MINIMCDS_MUX_TC_RC_Bits.TC_MUX1 */
#define IFX_MINIMCDS_MUX_TC_RC_TC_MUX1_MSK (0x3u)

/** \brief Offset for Ifx_MINIMCDS_MUX_TC_RC_Bits.TC_MUX1 */
#define IFX_MINIMCDS_MUX_TC_RC_TC_MUX1_OFF (2u)

/** \brief Length for Ifx_MINIMCDS_MUX_TC_RC_Bits.TC_MUX2 */
#define IFX_MINIMCDS_MUX_TC_RC_TC_MUX2_LEN (2u)

/** \brief Mask for Ifx_MINIMCDS_MUX_TC_RC_Bits.TC_MUX2 */
#define IFX_MINIMCDS_MUX_TC_RC_TC_MUX2_MSK (0x3u)

/** \brief Offset for Ifx_MINIMCDS_MUX_TC_RC_Bits.TC_MUX2 */
#define IFX_MINIMCDS_MUX_TC_RC_TC_MUX2_OFF (4u)

/** \brief Length for Ifx_MINIMCDS_MUX_TC_RC_Bits.TC_MUX3 */
#define IFX_MINIMCDS_MUX_TC_RC_TC_MUX3_LEN (2u)

/** \brief Mask for Ifx_MINIMCDS_MUX_TC_RC_Bits.TC_MUX3 */
#define IFX_MINIMCDS_MUX_TC_RC_TC_MUX3_MSK (0x3u)

/** \brief Offset for Ifx_MINIMCDS_MUX_TC_RC_Bits.TC_MUX3 */
#define IFX_MINIMCDS_MUX_TC_RC_TC_MUX3_OFF (6u)

/** \brief Length for Ifx_MINIMCDS_MUX_TC_RC_Bits.TC_MUX4 */
#define IFX_MINIMCDS_MUX_TC_RC_TC_MUX4_LEN (2u)

/** \brief Mask for Ifx_MINIMCDS_MUX_TC_RC_Bits.TC_MUX4 */
#define IFX_MINIMCDS_MUX_TC_RC_TC_MUX4_MSK (0x3u)

/** \brief Offset for Ifx_MINIMCDS_MUX_TC_RC_Bits.TC_MUX4 */
#define IFX_MINIMCDS_MUX_TC_RC_TC_MUX4_OFF (8u)

/** \brief Length for Ifx_MINIMCDS_MUX_TC_RC_Bits.TC_MUX5 */
#define IFX_MINIMCDS_MUX_TC_RC_TC_MUX5_LEN (2u)

/** \brief Mask for Ifx_MINIMCDS_MUX_TC_RC_Bits.TC_MUX5 */
#define IFX_MINIMCDS_MUX_TC_RC_TC_MUX5_MSK (0x3u)

/** \brief Offset for Ifx_MINIMCDS_MUX_TC_RC_Bits.TC_MUX5 */
#define IFX_MINIMCDS_MUX_TC_RC_TC_MUX5_OFF (10u)

/** \brief Length for Ifx_MINIMCDS_MUX_TC_RC_Bits.TC_TM_P */
#define IFX_MINIMCDS_MUX_TC_RC_TC_TM_P_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_MUX_TC_RC_Bits.TC_TM_P */
#define IFX_MINIMCDS_MUX_TC_RC_TC_TM_P_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_MUX_TC_RC_Bits.TC_TM_P */
#define IFX_MINIMCDS_MUX_TC_RC_TC_TM_P_OFF (15u)

/** \brief Length for Ifx_MINIMCDS_MUX_TC_RC_Bits.RC */
#define IFX_MINIMCDS_MUX_TC_RC_RC_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_MUX_TC_RC_Bits.RC */
#define IFX_MINIMCDS_MUX_TC_RC_RC_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_MUX_TC_RC_Bits.RC */
#define IFX_MINIMCDS_MUX_TC_RC_RC_OFF (24u)

/** \brief Length for Ifx_MINIMCDS_MUX_TC_RC_Bits.RC_P */
#define IFX_MINIMCDS_MUX_TC_RC_RC_P_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_MUX_TC_RC_Bits.RC_P */
#define IFX_MINIMCDS_MUX_TC_RC_RC_P_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_MUX_TC_RC_Bits.RC_P */
#define IFX_MINIMCDS_MUX_TC_RC_RC_P_OFF (27u)

/** \brief Length for Ifx_MINIMCDS_FIFONOW_Bits.NOW */
#define IFX_MINIMCDS_FIFONOW_NOW_LEN (8u)

/** \brief Mask for Ifx_MINIMCDS_FIFONOW_Bits.NOW */
#define IFX_MINIMCDS_FIFONOW_NOW_MSK (0xffu)

/** \brief Offset for Ifx_MINIMCDS_FIFONOW_Bits.NOW */
#define IFX_MINIMCDS_FIFONOW_NOW_OFF (5u)

/** \brief Length for Ifx_MINIMCDS_FIFOBOT_Bits.BOTTOM */
#define IFX_MINIMCDS_FIFOBOT_BOTTOM_LEN (3u)

/** \brief Mask for Ifx_MINIMCDS_FIFOBOT_Bits.BOTTOM */
#define IFX_MINIMCDS_FIFOBOT_BOTTOM_MSK (0x7u)

/** \brief Offset for Ifx_MINIMCDS_FIFOBOT_Bits.BOTTOM */
#define IFX_MINIMCDS_FIFOBOT_BOTTOM_OFF (10u)

/** \brief Length for Ifx_MINIMCDS_FIFOPRE_Bits.PRE */
#define IFX_MINIMCDS_FIFOPRE_PRE_LEN (8u)

/** \brief Mask for Ifx_MINIMCDS_FIFOPRE_Bits.PRE */
#define IFX_MINIMCDS_FIFOPRE_PRE_MSK (0xffu)

/** \brief Offset for Ifx_MINIMCDS_FIFOPRE_Bits.PRE */
#define IFX_MINIMCDS_FIFOPRE_PRE_OFF (5u)

/** \brief Length for Ifx_MINIMCDS_FIFOTOP_Bits.TOP */
#define IFX_MINIMCDS_FIFOTOP_TOP_LEN (8u)

/** \brief Mask for Ifx_MINIMCDS_FIFOTOP_Bits.TOP */
#define IFX_MINIMCDS_FIFOTOP_TOP_MSK (0xffu)

/** \brief Offset for Ifx_MINIMCDS_FIFOTOP_Bits.TOP */
#define IFX_MINIMCDS_FIFOTOP_TOP_OFF (5u)

/** \brief Length for Ifx_MINIMCDS_FIFOCTL_Bits.TRG */
#define IFX_MINIMCDS_FIFOCTL_TRG_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_FIFOCTL_Bits.TRG */
#define IFX_MINIMCDS_FIFOCTL_TRG_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_FIFOCTL_Bits.TRG */
#define IFX_MINIMCDS_FIFOCTL_TRG_OFF (0u)

/** \brief Length for Ifx_MINIMCDS_FIFOCTL_Bits.FFE */
#define IFX_MINIMCDS_FIFOCTL_FFE_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_FIFOCTL_Bits.FFE */
#define IFX_MINIMCDS_FIFOCTL_FFE_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_FIFOCTL_Bits.FFE */
#define IFX_MINIMCDS_FIFOCTL_FFE_OFF (1u)

/** \brief Length for Ifx_MINIMCDS_FIFOCTL_Bits.TRDIS */
#define IFX_MINIMCDS_FIFOCTL_TRDIS_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_FIFOCTL_Bits.TRDIS */
#define IFX_MINIMCDS_FIFOCTL_TRDIS_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_FIFOCTL_Bits.TRDIS */
#define IFX_MINIMCDS_FIFOCTL_TRDIS_OFF (9u)

/** \brief Length for Ifx_MINIMCDS_FIFOCTL_Bits.TRON */
#define IFX_MINIMCDS_FIFOCTL_TRON_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_FIFOCTL_Bits.TRON */
#define IFX_MINIMCDS_FIFOCTL_TRON_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_FIFOCTL_Bits.TRON */
#define IFX_MINIMCDS_FIFOCTL_TRON_OFF (10u)

/** \brief Length for Ifx_MINIMCDS_FIFOCTL_Bits.TROFF */
#define IFX_MINIMCDS_FIFOCTL_TROFF_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_FIFOCTL_Bits.TROFF */
#define IFX_MINIMCDS_FIFOCTL_TROFF_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_FIFOCTL_Bits.TROFF */
#define IFX_MINIMCDS_FIFOCTL_TROFF_OFF (11u)

/** \brief Length for Ifx_MINIMCDS_FIFOCTL_Bits.FLSH */
#define IFX_MINIMCDS_FIFOCTL_FLSH_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_FIFOCTL_Bits.FLSH */
#define IFX_MINIMCDS_FIFOCTL_FLSH_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_FIFOCTL_Bits.FLSH */
#define IFX_MINIMCDS_FIFOCTL_FLSH_OFF (13u)

/** \brief Length for Ifx_MINIMCDS_FIFOCTL_Bits.CLR */
#define IFX_MINIMCDS_FIFOCTL_CLR_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_FIFOCTL_Bits.CLR */
#define IFX_MINIMCDS_FIFOCTL_CLR_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_FIFOCTL_Bits.CLR */
#define IFX_MINIMCDS_FIFOCTL_CLR_OFF (14u)

/** \brief Length for Ifx_MINIMCDS_FIFOCTL_Bits.SET */
#define IFX_MINIMCDS_FIFOCTL_SET_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_FIFOCTL_Bits.SET */
#define IFX_MINIMCDS_FIFOCTL_SET_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_FIFOCTL_Bits.SET */
#define IFX_MINIMCDS_FIFOCTL_SET_OFF (15u)

/** \brief Length for Ifx_MINIMCDS_FIFOWARN_Bits.WARN */
#define IFX_MINIMCDS_FIFOWARN_WARN_LEN (8u)

/** \brief Mask for Ifx_MINIMCDS_FIFOWARN_Bits.WARN */
#define IFX_MINIMCDS_FIFOWARN_WARN_MSK (0xffu)

/** \brief Offset for Ifx_MINIMCDS_FIFOWARN_Bits.WARN */
#define IFX_MINIMCDS_FIFOWARN_WARN_OFF (5u)

/** \brief Length for Ifx_MINIMCDS_FIFOWARN_Bits.EN */
#define IFX_MINIMCDS_FIFOWARN_EN_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_FIFOWARN_Bits.EN */
#define IFX_MINIMCDS_FIFOWARN_EN_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_FIFOWARN_Bits.EN */
#define IFX_MINIMCDS_FIFOWARN_EN_OFF (31u)

/** \brief Length for Ifx_MINIMCDS_FIFOOVRCNT_Bits.COUNT */
#define IFX_MINIMCDS_FIFOOVRCNT_COUNT_LEN (8u)

/** \brief Mask for Ifx_MINIMCDS_FIFOOVRCNT_Bits.COUNT */
#define IFX_MINIMCDS_FIFOOVRCNT_COUNT_MSK (0xffu)

/** \brief Offset for Ifx_MINIMCDS_FIFOOVRCNT_Bits.COUNT */
#define IFX_MINIMCDS_FIFOOVRCNT_COUNT_OFF (0u)

/** \brief Length for Ifx_MINIMCDS_FIFOOVRCNT_Bits.CLR */
#define IFX_MINIMCDS_FIFOOVRCNT_CLR_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_FIFOOVRCNT_Bits.CLR */
#define IFX_MINIMCDS_FIFOOVRCNT_CLR_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_FIFOOVRCNT_Bits.CLR */
#define IFX_MINIMCDS_FIFOOVRCNT_CLR_OFF (15u)

/** \brief Length for Ifx_MINIMCDS_TSUREFCNT_Bits.COUNT */
#define IFX_MINIMCDS_TSUREFCNT_COUNT_LEN (32u)

/** \brief Mask for Ifx_MINIMCDS_TSUREFCNT_Bits.COUNT */
#define IFX_MINIMCDS_TSUREFCNT_COUNT_MSK (0xffffffffu)

/** \brief Offset for Ifx_MINIMCDS_TSUREFCNT_Bits.COUNT */
#define IFX_MINIMCDS_TSUREFCNT_COUNT_OFF (0u)

/** \brief Length for Ifx_MINIMCDS_TSUPRSCL_Bits.RELOAD */
#define IFX_MINIMCDS_TSUPRSCL_RELOAD_LEN (32u)

/** \brief Mask for Ifx_MINIMCDS_TSUPRSCL_Bits.RELOAD */
#define IFX_MINIMCDS_TSUPRSCL_RELOAD_MSK (0xffffffffu)

/** \brief Offset for Ifx_MINIMCDS_TSUPRSCL_Bits.RELOAD */
#define IFX_MINIMCDS_TSUPRSCL_RELOAD_OFF (0u)

/** \brief Length for Ifx_MINIMCDS_TSUEMUCNT_Bits.COUNT */
#define IFX_MINIMCDS_TSUEMUCNT_COUNT_LEN (32u)

/** \brief Mask for Ifx_MINIMCDS_TSUEMUCNT_Bits.COUNT */
#define IFX_MINIMCDS_TSUEMUCNT_COUNT_MSK (0xffffffffu)

/** \brief Offset for Ifx_MINIMCDS_TSUEMUCNT_Bits.COUNT */
#define IFX_MINIMCDS_TSUEMUCNT_COUNT_OFF (0u)

/** \brief Length for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ0 */
#define IFX_MINIMCDS_MCX_EVT_EIQ0_LEN (2u)

/** \brief Mask for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ0 */
#define IFX_MINIMCDS_MCX_EVT_EIQ0_MSK (0x3u)

/** \brief Offset for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ0 */
#define IFX_MINIMCDS_MCX_EVT_EIQ0_OFF (0u)

/** \brief Length for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ1 */
#define IFX_MINIMCDS_MCX_EVT_EIQ1_LEN (2u)

/** \brief Mask for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ1 */
#define IFX_MINIMCDS_MCX_EVT_EIQ1_MSK (0x3u)

/** \brief Offset for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ1 */
#define IFX_MINIMCDS_MCX_EVT_EIQ1_OFF (2u)

/** \brief Length for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ2 */
#define IFX_MINIMCDS_MCX_EVT_EIQ2_LEN (2u)

/** \brief Mask for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ2 */
#define IFX_MINIMCDS_MCX_EVT_EIQ2_MSK (0x3u)

/** \brief Offset for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ2 */
#define IFX_MINIMCDS_MCX_EVT_EIQ2_OFF (4u)

/** \brief Length for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ3 */
#define IFX_MINIMCDS_MCX_EVT_EIQ3_LEN (2u)

/** \brief Mask for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ3 */
#define IFX_MINIMCDS_MCX_EVT_EIQ3_MSK (0x3u)

/** \brief Offset for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ3 */
#define IFX_MINIMCDS_MCX_EVT_EIQ3_OFF (6u)

/** \brief Length for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ4 */
#define IFX_MINIMCDS_MCX_EVT_EIQ4_LEN (2u)

/** \brief Mask for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ4 */
#define IFX_MINIMCDS_MCX_EVT_EIQ4_MSK (0x3u)

/** \brief Offset for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ4 */
#define IFX_MINIMCDS_MCX_EVT_EIQ4_OFF (8u)

/** \brief Length for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ5 */
#define IFX_MINIMCDS_MCX_EVT_EIQ5_LEN (2u)

/** \brief Mask for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ5 */
#define IFX_MINIMCDS_MCX_EVT_EIQ5_MSK (0x3u)

/** \brief Offset for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ5 */
#define IFX_MINIMCDS_MCX_EVT_EIQ5_OFF (10u)

/** \brief Length for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ6 */
#define IFX_MINIMCDS_MCX_EVT_EIQ6_LEN (2u)

/** \brief Mask for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ6 */
#define IFX_MINIMCDS_MCX_EVT_EIQ6_MSK (0x3u)

/** \brief Offset for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ6 */
#define IFX_MINIMCDS_MCX_EVT_EIQ6_OFF (12u)

/** \brief Length for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ7 */
#define IFX_MINIMCDS_MCX_EVT_EIQ7_LEN (2u)

/** \brief Mask for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ7 */
#define IFX_MINIMCDS_MCX_EVT_EIQ7_MSK (0x3u)

/** \brief Offset for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ7 */
#define IFX_MINIMCDS_MCX_EVT_EIQ7_OFF (14u)

/** \brief Length for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ8 */
#define IFX_MINIMCDS_MCX_EVT_EIQ8_LEN (2u)

/** \brief Mask for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ8 */
#define IFX_MINIMCDS_MCX_EVT_EIQ8_MSK (0x3u)

/** \brief Offset for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ8 */
#define IFX_MINIMCDS_MCX_EVT_EIQ8_OFF (16u)

/** \brief Length for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ9 */
#define IFX_MINIMCDS_MCX_EVT_EIQ9_LEN (2u)

/** \brief Mask for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ9 */
#define IFX_MINIMCDS_MCX_EVT_EIQ9_MSK (0x3u)

/** \brief Offset for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ9 */
#define IFX_MINIMCDS_MCX_EVT_EIQ9_OFF (18u)

/** \brief Length for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ10 */
#define IFX_MINIMCDS_MCX_EVT_EIQ10_LEN (2u)

/** \brief Mask for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ10 */
#define IFX_MINIMCDS_MCX_EVT_EIQ10_MSK (0x3u)

/** \brief Offset for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ10 */
#define IFX_MINIMCDS_MCX_EVT_EIQ10_OFF (20u)

/** \brief Length for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ11 */
#define IFX_MINIMCDS_MCX_EVT_EIQ11_LEN (2u)

/** \brief Mask for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ11 */
#define IFX_MINIMCDS_MCX_EVT_EIQ11_MSK (0x3u)

/** \brief Offset for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ11 */
#define IFX_MINIMCDS_MCX_EVT_EIQ11_OFF (22u)

/** \brief Length for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ12 */
#define IFX_MINIMCDS_MCX_EVT_EIQ12_LEN (2u)

/** \brief Mask for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ12 */
#define IFX_MINIMCDS_MCX_EVT_EIQ12_MSK (0x3u)

/** \brief Offset for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ12 */
#define IFX_MINIMCDS_MCX_EVT_EIQ12_OFF (24u)

/** \brief Length for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ13 */
#define IFX_MINIMCDS_MCX_EVT_EIQ13_LEN (2u)

/** \brief Mask for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ13 */
#define IFX_MINIMCDS_MCX_EVT_EIQ13_MSK (0x3u)

/** \brief Offset for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ13 */
#define IFX_MINIMCDS_MCX_EVT_EIQ13_OFF (26u)

/** \brief Length for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ14 */
#define IFX_MINIMCDS_MCX_EVT_EIQ14_LEN (2u)

/** \brief Mask for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ14 */
#define IFX_MINIMCDS_MCX_EVT_EIQ14_MSK (0x3u)

/** \brief Offset for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ14 */
#define IFX_MINIMCDS_MCX_EVT_EIQ14_OFF (28u)

/** \brief Length for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ15 */
#define IFX_MINIMCDS_MCX_EVT_EIQ15_LEN (2u)

/** \brief Mask for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ15 */
#define IFX_MINIMCDS_MCX_EVT_EIQ15_MSK (0x3u)

/** \brief Offset for Ifx_MINIMCDS_MCX_EVT_Bits.EIQ15 */
#define IFX_MINIMCDS_MCX_EVT_EIQ15_OFF (30u)

/** \brief Length for Ifx_MINIMCDS_MCX_ACT_Bits.AIS0 */
#define IFX_MINIMCDS_MCX_ACT_AIS0_LEN (5u)

/** \brief Mask for Ifx_MINIMCDS_MCX_ACT_Bits.AIS0 */
#define IFX_MINIMCDS_MCX_ACT_AIS0_MSK (0x1fu)

/** \brief Offset for Ifx_MINIMCDS_MCX_ACT_Bits.AIS0 */
#define IFX_MINIMCDS_MCX_ACT_AIS0_OFF (0u)

/** \brief Length for Ifx_MINIMCDS_MCX_ACT_Bits.AIQ0 */
#define IFX_MINIMCDS_MCX_ACT_AIQ0_LEN (2u)

/** \brief Mask for Ifx_MINIMCDS_MCX_ACT_Bits.AIQ0 */
#define IFX_MINIMCDS_MCX_ACT_AIQ0_MSK (0x3u)

/** \brief Offset for Ifx_MINIMCDS_MCX_ACT_Bits.AIQ0 */
#define IFX_MINIMCDS_MCX_ACT_AIQ0_OFF (5u)

/** \brief Length for Ifx_MINIMCDS_MCX_ACT_Bits.LV0 */
#define IFX_MINIMCDS_MCX_ACT_LV0_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_MCX_ACT_Bits.LV0 */
#define IFX_MINIMCDS_MCX_ACT_LV0_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_MCX_ACT_Bits.LV0 */
#define IFX_MINIMCDS_MCX_ACT_LV0_OFF (7u)

/** \brief Length for Ifx_MINIMCDS_MCX_ACT_Bits.AIS1 */
#define IFX_MINIMCDS_MCX_ACT_AIS1_LEN (5u)

/** \brief Mask for Ifx_MINIMCDS_MCX_ACT_Bits.AIS1 */
#define IFX_MINIMCDS_MCX_ACT_AIS1_MSK (0x1fu)

/** \brief Offset for Ifx_MINIMCDS_MCX_ACT_Bits.AIS1 */
#define IFX_MINIMCDS_MCX_ACT_AIS1_OFF (8u)

/** \brief Length for Ifx_MINIMCDS_MCX_ACT_Bits.AIQ1 */
#define IFX_MINIMCDS_MCX_ACT_AIQ1_LEN (2u)

/** \brief Mask for Ifx_MINIMCDS_MCX_ACT_Bits.AIQ1 */
#define IFX_MINIMCDS_MCX_ACT_AIQ1_MSK (0x3u)

/** \brief Offset for Ifx_MINIMCDS_MCX_ACT_Bits.AIQ1 */
#define IFX_MINIMCDS_MCX_ACT_AIQ1_OFF (13u)

/** \brief Length for Ifx_MINIMCDS_MCX_ACT_Bits.LV1 */
#define IFX_MINIMCDS_MCX_ACT_LV1_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_MCX_ACT_Bits.LV1 */
#define IFX_MINIMCDS_MCX_ACT_LV1_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_MCX_ACT_Bits.LV1 */
#define IFX_MINIMCDS_MCX_ACT_LV1_OFF (15u)

/** \brief Length for Ifx_MINIMCDS_MCX_ACT_Bits.AIS2 */
#define IFX_MINIMCDS_MCX_ACT_AIS2_LEN (5u)

/** \brief Mask for Ifx_MINIMCDS_MCX_ACT_Bits.AIS2 */
#define IFX_MINIMCDS_MCX_ACT_AIS2_MSK (0x1fu)

/** \brief Offset for Ifx_MINIMCDS_MCX_ACT_Bits.AIS2 */
#define IFX_MINIMCDS_MCX_ACT_AIS2_OFF (16u)

/** \brief Length for Ifx_MINIMCDS_MCX_ACT_Bits.AIQ2 */
#define IFX_MINIMCDS_MCX_ACT_AIQ2_LEN (2u)

/** \brief Mask for Ifx_MINIMCDS_MCX_ACT_Bits.AIQ2 */
#define IFX_MINIMCDS_MCX_ACT_AIQ2_MSK (0x3u)

/** \brief Offset for Ifx_MINIMCDS_MCX_ACT_Bits.AIQ2 */
#define IFX_MINIMCDS_MCX_ACT_AIQ2_OFF (21u)

/** \brief Length for Ifx_MINIMCDS_MCX_ACT_Bits.LV2 */
#define IFX_MINIMCDS_MCX_ACT_LV2_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_MCX_ACT_Bits.LV2 */
#define IFX_MINIMCDS_MCX_ACT_LV2_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_MCX_ACT_Bits.LV2 */
#define IFX_MINIMCDS_MCX_ACT_LV2_OFF (23u)

/** \brief Length for Ifx_MINIMCDS_MCX_ACT_Bits.AIS3 */
#define IFX_MINIMCDS_MCX_ACT_AIS3_LEN (5u)

/** \brief Mask for Ifx_MINIMCDS_MCX_ACT_Bits.AIS3 */
#define IFX_MINIMCDS_MCX_ACT_AIS3_MSK (0x1fu)

/** \brief Offset for Ifx_MINIMCDS_MCX_ACT_Bits.AIS3 */
#define IFX_MINIMCDS_MCX_ACT_AIS3_OFF (24u)

/** \brief Length for Ifx_MINIMCDS_MCX_ACT_Bits.AIQ3 */
#define IFX_MINIMCDS_MCX_ACT_AIQ3_LEN (2u)

/** \brief Mask for Ifx_MINIMCDS_MCX_ACT_Bits.AIQ3 */
#define IFX_MINIMCDS_MCX_ACT_AIQ3_MSK (0x3u)

/** \brief Offset for Ifx_MINIMCDS_MCX_ACT_Bits.AIQ3 */
#define IFX_MINIMCDS_MCX_ACT_AIQ3_OFF (29u)

/** \brief Length for Ifx_MINIMCDS_MCX_ACT_Bits.LV3 */
#define IFX_MINIMCDS_MCX_ACT_LV3_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_MCX_ACT_Bits.LV3 */
#define IFX_MINIMCDS_MCX_ACT_LV3_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_MCX_ACT_Bits.LV3 */
#define IFX_MINIMCDS_MCX_ACT_LV3_OFF (31u)

/** \brief Length for Ifx_MINIMCDS_MCX_CNT_CCL_Bits.INC0 */
#define IFX_MINIMCDS_MCX_CNT_CCL_INC0_LEN (7u)

/** \brief Mask for Ifx_MINIMCDS_MCX_CNT_CCL_Bits.INC0 */
#define IFX_MINIMCDS_MCX_CNT_CCL_INC0_MSK (0x7fu)

/** \brief Offset for Ifx_MINIMCDS_MCX_CNT_CCL_Bits.INC0 */
#define IFX_MINIMCDS_MCX_CNT_CCL_INC0_OFF (0u)

/** \brief Length for Ifx_MINIMCDS_MCX_CNT_CCL_Bits.ILV0 */
#define IFX_MINIMCDS_MCX_CNT_CCL_ILV0_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_MCX_CNT_CCL_Bits.ILV0 */
#define IFX_MINIMCDS_MCX_CNT_CCL_ILV0_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_MCX_CNT_CCL_Bits.ILV0 */
#define IFX_MINIMCDS_MCX_CNT_CCL_ILV0_OFF (7u)

/** \brief Length for Ifx_MINIMCDS_MCX_CNT_CCL_Bits.CLR0 */
#define IFX_MINIMCDS_MCX_CNT_CCL_CLR0_LEN (6u)

/** \brief Mask for Ifx_MINIMCDS_MCX_CNT_CCL_Bits.CLR0 */
#define IFX_MINIMCDS_MCX_CNT_CCL_CLR0_MSK (0x3fu)

/** \brief Offset for Ifx_MINIMCDS_MCX_CNT_CCL_Bits.CLR0 */
#define IFX_MINIMCDS_MCX_CNT_CCL_CLR0_OFF (8u)

/** \brief Length for Ifx_MINIMCDS_MCX_CNT_CCL_Bits.CLV0 */
#define IFX_MINIMCDS_MCX_CNT_CCL_CLV0_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_MCX_CNT_CCL_Bits.CLV0 */
#define IFX_MINIMCDS_MCX_CNT_CCL_CLV0_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_MCX_CNT_CCL_Bits.CLV0 */
#define IFX_MINIMCDS_MCX_CNT_CCL_CLV0_OFF (15u)

/** \brief Length for Ifx_MINIMCDS_MCX_CNT_CCL_Bits.INC1 */
#define IFX_MINIMCDS_MCX_CNT_CCL_INC1_LEN (7u)

/** \brief Mask for Ifx_MINIMCDS_MCX_CNT_CCL_Bits.INC1 */
#define IFX_MINIMCDS_MCX_CNT_CCL_INC1_MSK (0x7fu)

/** \brief Offset for Ifx_MINIMCDS_MCX_CNT_CCL_Bits.INC1 */
#define IFX_MINIMCDS_MCX_CNT_CCL_INC1_OFF (16u)

/** \brief Length for Ifx_MINIMCDS_MCX_CNT_CCL_Bits.ILV1 */
#define IFX_MINIMCDS_MCX_CNT_CCL_ILV1_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_MCX_CNT_CCL_Bits.ILV1 */
#define IFX_MINIMCDS_MCX_CNT_CCL_ILV1_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_MCX_CNT_CCL_Bits.ILV1 */
#define IFX_MINIMCDS_MCX_CNT_CCL_ILV1_OFF (23u)

/** \brief Length for Ifx_MINIMCDS_MCX_CNT_CCL_Bits.CLR1 */
#define IFX_MINIMCDS_MCX_CNT_CCL_CLR1_LEN (6u)

/** \brief Mask for Ifx_MINIMCDS_MCX_CNT_CCL_Bits.CLR1 */
#define IFX_MINIMCDS_MCX_CNT_CCL_CLR1_MSK (0x3fu)

/** \brief Offset for Ifx_MINIMCDS_MCX_CNT_CCL_Bits.CLR1 */
#define IFX_MINIMCDS_MCX_CNT_CCL_CLR1_OFF (24u)

/** \brief Length for Ifx_MINIMCDS_MCX_CNT_CCL_Bits.CLV1 */
#define IFX_MINIMCDS_MCX_CNT_CCL_CLV1_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_MCX_CNT_CCL_Bits.CLV1 */
#define IFX_MINIMCDS_MCX_CNT_CCL_CLV1_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_MCX_CNT_CCL_Bits.CLV1 */
#define IFX_MINIMCDS_MCX_CNT_CCL_CLV1_OFF (31u)

/** \brief Length for Ifx_MINIMCDS_MCX_CNT_LMT_Bits.LIMIT */
#define IFX_MINIMCDS_MCX_CNT_LMT_LIMIT_LEN (16u)

/** \brief Mask for Ifx_MINIMCDS_MCX_CNT_LMT_Bits.LIMIT */
#define IFX_MINIMCDS_MCX_CNT_LMT_LIMIT_MSK (0xffffu)

/** \brief Offset for Ifx_MINIMCDS_MCX_CNT_LMT_Bits.LIMIT */
#define IFX_MINIMCDS_MCX_CNT_LMT_LIMIT_OFF (0u)

/** \brief Length for Ifx_MINIMCDS_MCX_CNT_LMT_Bits.MOD0 */
#define IFX_MINIMCDS_MCX_CNT_LMT_MOD0_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_MCX_CNT_LMT_Bits.MOD0 */
#define IFX_MINIMCDS_MCX_CNT_LMT_MOD0_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_MCX_CNT_LMT_Bits.MOD0 */
#define IFX_MINIMCDS_MCX_CNT_LMT_MOD0_OFF (30u)

/** \brief Length for Ifx_MINIMCDS_MCX_CNT_LMT_Bits.MOD1 */
#define IFX_MINIMCDS_MCX_CNT_LMT_MOD1_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_MCX_CNT_LMT_Bits.MOD1 */
#define IFX_MINIMCDS_MCX_CNT_LMT_MOD1_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_MCX_CNT_LMT_Bits.MOD1 */
#define IFX_MINIMCDS_MCX_CNT_LMT_MOD1_OFF (31u)

/** \brief Length for Ifx_MINIMCDS_MCX_CNT_CNT_Bits.COUNT */
#define IFX_MINIMCDS_MCX_CNT_CNT_COUNT_LEN (16u)

/** \brief Mask for Ifx_MINIMCDS_MCX_CNT_CNT_Bits.COUNT */
#define IFX_MINIMCDS_MCX_CNT_CNT_COUNT_MSK (0xffffu)

/** \brief Offset for Ifx_MINIMCDS_MCX_CNT_CNT_Bits.COUNT */
#define IFX_MINIMCDS_MCX_CNT_CNT_COUNT_OFF (0u)

/** \brief Length for Ifx_MINIMCDS_TCX_DCSTS_Bits.SUS */
#define IFX_MINIMCDS_TCX_DCSTS_SUS_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_TCX_DCSTS_Bits.SUS */
#define IFX_MINIMCDS_TCX_DCSTS_SUS_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_TCX_DCSTS_Bits.SUS */
#define IFX_MINIMCDS_TCX_DCSTS_SUS_OFF (0u)

/** \brief Length for Ifx_MINIMCDS_TCX_DCSTS_Bits.IDLE */
#define IFX_MINIMCDS_TCX_DCSTS_IDLE_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_TCX_DCSTS_Bits.IDLE */
#define IFX_MINIMCDS_TCX_DCSTS_IDLE_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_TCX_DCSTS_Bits.IDLE */
#define IFX_MINIMCDS_TCX_DCSTS_IDLE_OFF (1u)

/** \brief Length for Ifx_MINIMCDS_TCX_DCSTS_Bits.HALT */
#define IFX_MINIMCDS_TCX_DCSTS_HALT_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_TCX_DCSTS_Bits.HALT */
#define IFX_MINIMCDS_TCX_DCSTS_HALT_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_TCX_DCSTS_Bits.HALT */
#define IFX_MINIMCDS_TCX_DCSTS_HALT_OFF (2u)

/** \brief Length for Ifx_MINIMCDS_TCX_DCSTS_Bits.ISR */
#define IFX_MINIMCDS_TCX_DCSTS_ISR_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_TCX_DCSTS_Bits.ISR */
#define IFX_MINIMCDS_TCX_DCSTS_ISR_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_TCX_DCSTS_Bits.ISR */
#define IFX_MINIMCDS_TCX_DCSTS_ISR_OFF (3u)

/** \brief Length for Ifx_MINIMCDS_TCX_DCSTS_Bits.HBRK */
#define IFX_MINIMCDS_TCX_DCSTS_HBRK_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_TCX_DCSTS_Bits.HBRK */
#define IFX_MINIMCDS_TCX_DCSTS_HBRK_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_TCX_DCSTS_Bits.HBRK */
#define IFX_MINIMCDS_TCX_DCSTS_HBRK_OFF (4u)

/** \brief Length for Ifx_MINIMCDS_TCX_DCSTS_Bits.SBRK */
#define IFX_MINIMCDS_TCX_DCSTS_SBRK_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_TCX_DCSTS_Bits.SBRK */
#define IFX_MINIMCDS_TCX_DCSTS_SBRK_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_TCX_DCSTS_Bits.SBRK */
#define IFX_MINIMCDS_TCX_DCSTS_SBRK_OFF (5u)

/** \brief Length for Ifx_MINIMCDS_TCX_DCSTS_Bits.IEN */
#define IFX_MINIMCDS_TCX_DCSTS_IEN_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_TCX_DCSTS_Bits.IEN */
#define IFX_MINIMCDS_TCX_DCSTS_IEN_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_TCX_DCSTS_Bits.IEN */
#define IFX_MINIMCDS_TCX_DCSTS_IEN_OFF (7u)

/** \brief Length for Ifx_MINIMCDS_TCX_DCSTS_Bits.DBGEN */
#define IFX_MINIMCDS_TCX_DCSTS_DBGEN_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_TCX_DCSTS_Bits.DBGEN */
#define IFX_MINIMCDS_TCX_DCSTS_DBGEN_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_TCX_DCSTS_Bits.DBGEN */
#define IFX_MINIMCDS_TCX_DCSTS_DBGEN_OFF (8u)

/** \brief Length for Ifx_MINIMCDS_TCX_DCSTS_Bits.CLKDIV */
#define IFX_MINIMCDS_TCX_DCSTS_CLKDIV_LEN (2u)

/** \brief Mask for Ifx_MINIMCDS_TCX_DCSTS_Bits.CLKDIV */
#define IFX_MINIMCDS_TCX_DCSTS_CLKDIV_MSK (0x3u)

/** \brief Offset for Ifx_MINIMCDS_TCX_DCSTS_Bits.CLKDIV */
#define IFX_MINIMCDS_TCX_DCSTS_CLKDIV_OFF (9u)

/** \brief Length for Ifx_MINIMCDS_TCX_CIP_Bits.CURRENT */
#define IFX_MINIMCDS_TCX_CIP_CURRENT_LEN (31u)

/** \brief Mask for Ifx_MINIMCDS_TCX_CIP_Bits.CURRENT */
#define IFX_MINIMCDS_TCX_CIP_CURRENT_MSK (0x7fffffffu)

/** \brief Offset for Ifx_MINIMCDS_TCX_CIP_Bits.CURRENT */
#define IFX_MINIMCDS_TCX_CIP_CURRENT_OFF (1u)

/** \brief Length for Ifx_MINIMCDS_TCX_CFT_Bits.VSHRT_FCT */
#define IFX_MINIMCDS_TCX_CFT_VSHRT_FCT_LEN (10u)

/** \brief Mask for Ifx_MINIMCDS_TCX_CFT_Bits.VSHRT_FCT */
#define IFX_MINIMCDS_TCX_CFT_VSHRT_FCT_MSK (0x3ffu)

/** \brief Offset for Ifx_MINIMCDS_TCX_CFT_Bits.VSHRT_FCT */
#define IFX_MINIMCDS_TCX_CFT_VSHRT_FCT_OFF (0u)

/** \brief Length for Ifx_MINIMCDS_TCX_CFT_Bits.SHRT_FCT */
#define IFX_MINIMCDS_TCX_CFT_SHRT_FCT_LEN (10u)

/** \brief Mask for Ifx_MINIMCDS_TCX_CFT_Bits.SHRT_FCT */
#define IFX_MINIMCDS_TCX_CFT_SHRT_FCT_MSK (0x3ffu)

/** \brief Offset for Ifx_MINIMCDS_TCX_CFT_Bits.SHRT_FCT */
#define IFX_MINIMCDS_TCX_CFT_SHRT_FCT_OFF (16u)

/** \brief Length for Ifx_MINIMCDS_TCX_EA_BND_Bits.BOUND */
#define IFX_MINIMCDS_TCX_EA_BND_BOUND_LEN (32u)

/** \brief Mask for Ifx_MINIMCDS_TCX_EA_BND_Bits.BOUND */
#define IFX_MINIMCDS_TCX_EA_BND_BOUND_MSK (0xffffffffu)

/** \brief Offset for Ifx_MINIMCDS_TCX_EA_BND_Bits.BOUND */
#define IFX_MINIMCDS_TCX_EA_BND_BOUND_OFF (0u)

/** \brief Length for Ifx_MINIMCDS_TCX_EA_RNG_Bits.RANGE */
#define IFX_MINIMCDS_TCX_EA_RNG_RANGE_LEN (32u)

/** \brief Mask for Ifx_MINIMCDS_TCX_EA_RNG_Bits.RANGE */
#define IFX_MINIMCDS_TCX_EA_RNG_RANGE_MSK (0xffffffffu)

/** \brief Offset for Ifx_MINIMCDS_TCX_EA_RNG_Bits.RANGE */
#define IFX_MINIMCDS_TCX_EA_RNG_RANGE_OFF (0u)

/** \brief Length for Ifx_MINIMCDS_TCX_WD_BND_Bits.BOUND */
#define IFX_MINIMCDS_TCX_WD_BND_BOUND_LEN (32u)

/** \brief Mask for Ifx_MINIMCDS_TCX_WD_BND_Bits.BOUND */
#define IFX_MINIMCDS_TCX_WD_BND_BOUND_MSK (0xffffffffu)

/** \brief Offset for Ifx_MINIMCDS_TCX_WD_BND_Bits.BOUND */
#define IFX_MINIMCDS_TCX_WD_BND_BOUND_OFF (0u)

/** \brief Length for Ifx_MINIMCDS_TCX_WD_RNG_Bits.RANGE */
#define IFX_MINIMCDS_TCX_WD_RNG_RANGE_LEN (32u)

/** \brief Mask for Ifx_MINIMCDS_TCX_WD_RNG_Bits.RANGE */
#define IFX_MINIMCDS_TCX_WD_RNG_RANGE_MSK (0xffffffffu)

/** \brief Offset for Ifx_MINIMCDS_TCX_WD_RNG_Bits.RANGE */
#define IFX_MINIMCDS_TCX_WD_RNG_RANGE_OFF (0u)

/** \brief Length for Ifx_MINIMCDS_TCX_WD_MSK_Bits.MASK */
#define IFX_MINIMCDS_TCX_WD_MSK_MASK_LEN (32u)

/** \brief Mask for Ifx_MINIMCDS_TCX_WD_MSK_Bits.MASK */
#define IFX_MINIMCDS_TCX_WD_MSK_MASK_MSK (0xffffffffu)

/** \brief Offset for Ifx_MINIMCDS_TCX_WD_MSK_Bits.MASK */
#define IFX_MINIMCDS_TCX_WD_MSK_MASK_OFF (0u)

/** \brief Length for Ifx_MINIMCDS_TCX_WD_SGN_Bits.SIGN */
#define IFX_MINIMCDS_TCX_WD_SGN_SIGN_LEN (5u)

/** \brief Mask for Ifx_MINIMCDS_TCX_WD_SGN_Bits.SIGN */
#define IFX_MINIMCDS_TCX_WD_SGN_SIGN_MSK (0x1fu)

/** \brief Offset for Ifx_MINIMCDS_TCX_WD_SGN_Bits.SIGN */
#define IFX_MINIMCDS_TCX_WD_SGN_SIGN_OFF (0u)

/** \brief Length for Ifx_MINIMCDS_TCX_AC_BND_Bits.BOUND */
#define IFX_MINIMCDS_TCX_AC_BND_BOUND_LEN (12u)

/** \brief Mask for Ifx_MINIMCDS_TCX_AC_BND_Bits.BOUND */
#define IFX_MINIMCDS_TCX_AC_BND_BOUND_MSK (0xfffu)

/** \brief Offset for Ifx_MINIMCDS_TCX_AC_BND_Bits.BOUND */
#define IFX_MINIMCDS_TCX_AC_BND_BOUND_OFF (0u)

/** \brief Length for Ifx_MINIMCDS_TCX_AC_RNG_Bits.RANGE */
#define IFX_MINIMCDS_TCX_AC_RNG_RANGE_LEN (12u)

/** \brief Mask for Ifx_MINIMCDS_TCX_AC_RNG_Bits.RANGE */
#define IFX_MINIMCDS_TCX_AC_RNG_RANGE_MSK (0xfffu)

/** \brief Offset for Ifx_MINIMCDS_TCX_AC_RNG_Bits.RANGE */
#define IFX_MINIMCDS_TCX_AC_RNG_RANGE_OFF (0u)

/** \brief Length for Ifx_MINIMCDS_TCX_AC_MSK_Bits.SVM */
#define IFX_MINIMCDS_TCX_AC_MSK_SVM_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_TCX_AC_MSK_Bits.SVM */
#define IFX_MINIMCDS_TCX_AC_MSK_SVM_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_TCX_AC_MSK_Bits.SVM */
#define IFX_MINIMCDS_TCX_AC_MSK_SVM_OFF (0u)

/** \brief Length for Ifx_MINIMCDS_TCX_AC_MSK_Bits.MASTER */
#define IFX_MINIMCDS_TCX_AC_MSK_MASTER_LEN (4u)

/** \brief Mask for Ifx_MINIMCDS_TCX_AC_MSK_Bits.MASTER */
#define IFX_MINIMCDS_TCX_AC_MSK_MASTER_MSK (0xfu)

/** \brief Offset for Ifx_MINIMCDS_TCX_AC_MSK_Bits.MASTER */
#define IFX_MINIMCDS_TCX_AC_MSK_MASTER_OFF (1u)

/** \brief Length for Ifx_MINIMCDS_TCX_AC_MSK_Bits.SUBCHANNEL */
#define IFX_MINIMCDS_TCX_AC_MSK_SUBCHANNEL_LEN (7u)

/** \brief Mask for Ifx_MINIMCDS_TCX_AC_MSK_Bits.SUBCHANNEL */
#define IFX_MINIMCDS_TCX_AC_MSK_SUBCHANNEL_MSK (0x7fu)

/** \brief Offset for Ifx_MINIMCDS_TCX_AC_MSK_Bits.SUBCHANNEL */
#define IFX_MINIMCDS_TCX_AC_MSK_SUBCHANNEL_OFF (5u)

/** \brief Length for Ifx_MINIMCDS_TCX_AC_MSK_Bits.WR */
#define IFX_MINIMCDS_TCX_AC_MSK_WR_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_TCX_AC_MSK_Bits.WR */
#define IFX_MINIMCDS_TCX_AC_MSK_WR_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_TCX_AC_MSK_Bits.WR */
#define IFX_MINIMCDS_TCX_AC_MSK_WR_OFF (12u)

/** \brief Length for Ifx_MINIMCDS_TCX_AC_MSK_Bits.RD */
#define IFX_MINIMCDS_TCX_AC_MSK_RD_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_TCX_AC_MSK_Bits.RD */
#define IFX_MINIMCDS_TCX_AC_MSK_RD_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_TCX_AC_MSK_Bits.RD */
#define IFX_MINIMCDS_TCX_AC_MSK_RD_OFF (13u)

/** \brief Length for Ifx_MINIMCDS_TCX_AC_MSK_Bits.MSK */
#define IFX_MINIMCDS_TCX_AC_MSK_MSK_LEN (1u)

/** \brief Mask for Ifx_MINIMCDS_TCX_AC_MSK_Bits.MSK */
#define IFX_MINIMCDS_TCX_AC_MSK_MSK_MSK (0x1u)

/** \brief Offset for Ifx_MINIMCDS_TCX_AC_MSK_Bits.MSK */
#define IFX_MINIMCDS_TCX_AC_MSK_MSK_OFF (14u)

/** \brief Length for Ifx_MINIMCDS_TCX_IP_BND_Bits.BOUND */
#define IFX_MINIMCDS_TCX_IP_BND_BOUND_LEN (31u)

/** \brief Mask for Ifx_MINIMCDS_TCX_IP_BND_Bits.BOUND */
#define IFX_MINIMCDS_TCX_IP_BND_BOUND_MSK (0x7fffffffu)

/** \brief Offset for Ifx_MINIMCDS_TCX_IP_BND_Bits.BOUND */
#define IFX_MINIMCDS_TCX_IP_BND_BOUND_OFF (1u)

/** \brief Length for Ifx_MINIMCDS_TCX_IP_RNG_Bits.RANGE */
#define IFX_MINIMCDS_TCX_IP_RNG_RANGE_LEN (31u)

/** \brief Mask for Ifx_MINIMCDS_TCX_IP_RNG_Bits.RANGE */
#define IFX_MINIMCDS_TCX_IP_RNG_RANGE_MSK (0x7fffffffu)

/** \brief Offset for Ifx_MINIMCDS_TCX_IP_RNG_Bits.RANGE */
#define IFX_MINIMCDS_TCX_IP_RNG_RANGE_OFF (1u)

/** \}  */
/******************************************************************************/
/******************************************************************************/
#endif /* IFXMINIMCDS_BF_H */
