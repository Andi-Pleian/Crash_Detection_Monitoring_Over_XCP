
/**
 * \file
 *
 * \brief AUTOSAR FrIf
 *
 * This file contains the implementation of the AUTOSAR
 * module FrIf.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2017 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef FRIF_PBCFG_H
#define FRIF_PBCFG_H



/*==================[inclusions]=============================================*/

#include <FrIf_SymbolicNames_PBcfg.h>
#include <TSAutosar.h>
#include <FrIf_CfgTypes.h>
#include <Compiler.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_PTR_CLASS FRIF_APPL_CONST
#include <TSPBConfig_Types.h>


/*==================[macros]=================================================*/

#if (defined FrIfConfig) /* To prevent double definition */
#error FrIfConfig already defined
#endif /* (defined FrIfConfig) */

#define FrIfConfig (FrIf_ConfigLayout.RootCfg)



/*==================[type definitions]=======================================*/

typedef struct /* FrIf_ConfigLayoutType */ {
    VAR( FrIf_ConfigType, TYPEDEF ) RootCfg;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_STAT_FUNKSCHLUESSEL_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_PCSH_RERA_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_STAT_ZV_KLAPPEN_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_PCSH_WBK_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_CON_VEH_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_MILE_VEH_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_ST_RCP_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_pTL_MST_GW_TRNSM_FR_254_150A0001R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_pTL_BRC_FR_32_209A0001R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_pTL_BRC_FR_32_210A0001R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_pTL_BRC_FR_32_211A0001R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_pTL_BRC_FR_32_212A0001R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_pTL_BRC_FR_32_213A0001R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_SVC_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_pdummy32bmaster_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_DT_PT_2_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_ST_PMA_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_DIST_DT_APD_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_STAT_GANG_RUECKWAERTS_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_ST_FN_PDC_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_ST_TIR_RC_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_BLINKEN_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_CTR_DIAG_OBD_DRDY_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_DIAG_OBD_ENG_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_CALC_DT_NAVI_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_ST_IDT_CHGNG_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_A_TEMP_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_LCD_BRIG_CLCTR_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_STAT_FAHRLICHT_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_PIA_DT_INQY_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_PIA_DT_SET_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_PIA_SU_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_PIA_TRANA_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_WISCHERGESCHWINDIGKEIT_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_DT_DVMOD_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_SPEC_ACTVN_BLTW_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_OP_PUBU_PKG_DUR_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_DISP_PMA_2_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_RQ_ACTVN_FN_PKG_2_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_STATE_SBIL_DR_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_STATE_SBIL_PS_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_FZZSTD_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_FAHRGESTELLNUMMER_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_RELATIVZEIT_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_KILOMETERSTAND_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_UHRZEIT_DATUM_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_RQ_AB_REC_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_AVL_RPM_WHL_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_ST_STAB_DSC_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_MASS_VEH_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_SU_CLE_DRDY_DXP_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_VEH_DYNMC_DT_ESTI_VRFD_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_V_VEH_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_AVL_STEA_DV_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_PKG_LNG_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_DT_STMD_DRDY_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_EVT_DRASY_3_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_ST_FN_APDC_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_TAR_DVE_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_NM3_AFR_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_pCCLK_COU_SYNCN_FR_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_EVT_DRASY_1_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_EVT_DRASY_2_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_ST_DISP_KI_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_DISP_CTA_R;
    VAR( FrIf_PduIdxType, TYPEDEF ) simpleRxPduId_OP_PUBU_PKG_R;
    VAR( FrIf_TxPduType, TYPEDEF ) aTxPdu[33];
    VAR( FrIf_PduPositionType, TYPEDEF ) aFrameStruct_fST_QU_RV_ST_QU_TVIEW_R[2];
    VAR( FrIf_PduPositionType, TYPEDEF ) aFrameStruct_fIDENT_NO_SEN_CLU_SEN_CLU_DT_RAW_OFFS_COMPT_T[2];
    VAR( FrIf_PduPositionType, TYPEDEF ) aFrameStruct_fTORQ_CRSH_1_ANG_ACPD_R[2];
    VAR( FrIf_PduPositionType, TYPEDEF ) aFrameStruct_fSEN_CLU_DT_RAW_SEN_CLU_DT_EXT_RAW_T[2];
    VAR( FrIf_PduPositionType, TYPEDEF ) aFrameStruct_fAVL_BRTORQ_SUM_ST_PRMSN_IBRK_R[2];
    VAR( FrIf_PduPositionType, TYPEDEF ) aFrameStruct_fACLNX_MASSCNTR_ACLNY_MASSCNTR_R[2];
    VAR( FrIf_PduPositionType, TYPEDEF ) aFrameStruct_fDT_DRDYSEN_EXT_VYAW_VEH_R[1];
    VAR( FrIf_PduPositionType, TYPEDEF ) aFrameStruct_fTLT_RW_STEA_FTAX_EFFV_R[1];
    VAR( FrIf_ComOpType, TYPEDEF ) aComOp_A_FlexRay_Job_0_909_0[59];
    VAR( FrIf_ComOpType, TYPEDEF ) aComOp_A_FlexRay_Job_0_2727_1[18];
    VAR( FrIf_ComOpType, TYPEDEF ) aComOp_A_FlexRay_Job_1_909_0[54];
    VAR( FrIf_ComOpType, TYPEDEF ) aComOp_A_FlexRay_Job_1_2727_1[18];
    VAR( FrIf_ComOpType, TYPEDEF ) aComOp_A_FlexRay_Job_2_909_0[57];
    VAR( FrIf_ComOpType, TYPEDEF ) aComOp_A_FlexRay_Job_2_2727_1[18];
    VAR( FrIf_ComOpType, TYPEDEF ) aComOp_A_FlexRay_Job_3_909_0[60];
    VAR( FrIf_ComOpType, TYPEDEF ) aComOp_A_FlexRay_Job_3_2727_1[19];
    VAR( FrIf_ComOpType, TYPEDEF ) aComOp_A_FlexRay_Job_4_909_0[58];
    VAR( FrIf_ComOpType, TYPEDEF ) aComOp_A_FlexRay_Job_5_909_0[55];
    VAR( FrIf_ComOpType, TYPEDEF ) aComOp_A_FlexRay_Job_5_2727_1[19];
    VAR( FrIf_ComOpType, TYPEDEF ) aComOp_A_FlexRay_Job_6_909_0[58];
    VAR( FrIf_ComOpType, TYPEDEF ) aComOp_A_FlexRay_Job_7_909_0[57];
    VAR( FrIf_ComOpType, TYPEDEF ) aComOp_A_FlexRay_Job_7_2727_1[18];
    VAR( FrIf_ComOpType, TYPEDEF ) aComOp_A_FlexRay_Job_8_909_0[59];
    VAR( FrIf_ComOpType, TYPEDEF ) aComOp_A_FlexRay_Job_9_909_0[55];
    VAR( FrIf_ComOpType, TYPEDEF ) aComOp_A_FlexRay_Job_10_909_0[58];
    VAR( FrIf_ComOpType, TYPEDEF ) aComOp_A_FlexRay_Job_11_909_0[60];
    VAR( FrIf_ComOpType, TYPEDEF ) aComOp_A_FlexRay_Job_12_909_0[60];
    VAR( FrIf_ComOpType, TYPEDEF ) aComOp_A_FlexRay_Job_13_909_0[57];
    VAR( FrIf_ComOpType, TYPEDEF ) aComOp_A_FlexRay_Job_14_909_0[57];
    VAR( FrIf_ComOpType, TYPEDEF ) aComOp_A_FlexRay_Job_15_909_0[57];
    VAR( FrIf_ComOpType, TYPEDEF ) aComOp_A_FlexRay_Job_18_909_0[56];
    VAR( FrIf_ComOpType, TYPEDEF ) aComOp_A_FlexRay_Job_19_909_0[59];
    VAR( FrIf_JobType, TYPEDEF ) aJobList_A_FlexRay[64];
    VAR( FrIf_CtrlType, TYPEDEF ) aCtrl[1];
    VAR( FrIf_ClstType, TYPEDEF ) aClst[1];
} FrIf_ConfigLayoutType;

typedef CONST( FrIf_ConfigLayoutType, FRIF_APPL_CONST ) FrIf_ConstConfigLayoutType;


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/

#define FRIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <MemMap.h>

extern FrIf_ConstConfigLayoutType FrIf_ConfigLayout;

#define FRIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <MemMap.h>


/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/



#undef TS_RELOCATABLE_CFG_ENABLE

#undef TS_PB_CFG_PTR_CLASS

#endif /* FRIF_PBCFG_H */

/*==================[end of file]============================================*/

