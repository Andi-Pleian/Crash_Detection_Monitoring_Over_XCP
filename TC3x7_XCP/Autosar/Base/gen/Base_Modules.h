/**
 * \file
 *
 * \brief AUTOSAR Base
 *
 * This file contains the implementation of the AUTOSAR
 * module Base.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2017 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/* !LINKSTO Base.ModuleInfo.HeaderFile,1 */
#if (!defined BASE_MODULES_H)
#define BASE_MODULES_H

/*==================[macros]=================================================*/

#ifndef BASE_ADC_ENABLED
/** \brief Enable status of the module Adc (/Adc/Adc) (VariantPostBuild) */
#define BASE_ADC_ENABLED STD_ON
#endif

#ifndef BASE_ADC_HEADER
/** \brief Name of the Adc (/Adc/Adc) module's main header file */
#define BASE_ADC_HEADER <Adc.h>
#endif

#ifndef BASE_BASE_ENABLED
/** \brief Enable status of the module Base (/Base/Base) (VariantPreCompile) */
#define BASE_BASE_ENABLED STD_ON
#endif

#ifndef BASE_BASE_HEADER
/** \brief Name of the Base (/Base/Base) module's main header file */
#define BASE_BASE_HEADER <Base.h>
#endif

#ifndef BASE_BSWM_ENABLED
/** \brief Enable status of the module BswM (/BswM/BswM) (VariantPreCompile) */
#define BASE_BSWM_ENABLED STD_ON
#endif

#ifndef BASE_BSWM_HEADER
/** \brief Name of the BswM (/BswM/BswM) module's main header file */
#define BASE_BSWM_HEADER <BswM.h>
#endif

#ifndef BASE_CAN_ENABLED
/** \brief Enable status of the module Can (/Can/Can) (VariantPostBuild) */
#define BASE_CAN_ENABLED STD_ON
#endif

#ifndef BASE_CAN_17_MCMCAN_ENABLED
/** \brief Enable status of the module Can (/Can/Can) (VariantPostBuild) */
#define BASE_CAN_17_MCMCAN_ENABLED STD_ON
#endif

#ifndef BASE_CAN_HEADER
/** \brief Name of the Can (/Can/Can) module's main header file */
#define BASE_CAN_HEADER <Can_17_McmCan.h>
#endif

#ifndef BASE_CAN_17_MCMCAN_HEADER
/** \brief Name of the Can (/Can/Can) module's main header file */
#define BASE_CAN_17_MCMCAN_HEADER <Can_17_McmCan.h>
#endif

#ifndef BASE_CANIF_ENABLED
/** \brief Enable status of the module CanIf (/CanIf/CanIf) (VariantPostBuild) */
#define BASE_CANIF_ENABLED STD_ON
#endif


#ifndef BASE_CANIF_CONFIG_PTR
/** \brief Address of the first multiple configuration container for CanIf (/CanIf/CanIf) */
#define BASE_CANIF_CONFIG_PTR (&CanIf_InitCfg)
#endif


#ifndef BASE_CANIF_HEADER
/** \brief Name of the CanIf (/CanIf/CanIf) module's main header file */
#define BASE_CANIF_HEADER <CanIf.h>
#endif

#ifndef BASE_CANSM_ENABLED
/** \brief Enable status of the module CanSM (/CanSM/CanSM) (VariantPreCompile) */
#define BASE_CANSM_ENABLED STD_ON
#endif


#ifndef BASE_CANSM_CONFIG_PTR
/** \brief Address of the first multiple configuration container for CanSM (/CanSM/CanSM) */
#define BASE_CANSM_CONFIG_PTR (&CanSM_Config_0)
#endif


#ifndef BASE_CANSM_HEADER
/** \brief Name of the CanSM (/CanSM/CanSM) module's main header file */
#define BASE_CANSM_HEADER <CanSM.h>
#endif

#ifndef BASE_COM_ENABLED
/** \brief Enable status of the module Com (/Com/Com) (VariantPreCompile) */
#define BASE_COM_ENABLED STD_OFF
#endif

#ifndef BASE_COM_HEADER
/** \brief Name of the Com (/Com/Com) module's main header file */
#define BASE_COM_HEADER <Com.h>
#endif

#ifndef BASE_COMM_ENABLED
/** \brief Enable status of the module ComM (/ComM/ComM) (VariantPostBuild) */
#define BASE_COMM_ENABLED STD_ON
#endif


#ifndef BASE_COMM_CONFIG_PTR
/** \brief Address of the first multiple configuration container for ComM (/ComM/ComM) */
#define BASE_COMM_CONFIG_PTR (&ComMConfigSet_0)
#endif


#ifndef BASE_COMM_HEADER
/** \brief Name of the ComM (/ComM/ComM) module's main header file */
#define BASE_COMM_HEADER <ComM.h>
#endif

#ifndef BASE_CRC_ENABLED
/** \brief Enable status of the module Crc (/Crc/Crc) (VariantPreCompile) */
#define BASE_CRC_ENABLED STD_OFF
#endif

#ifndef BASE_CRC_HEADER
/** \brief Name of the Crc (/Crc/Crc) module's main header file */
#define BASE_CRC_HEADER <Crc.h>
#endif

#ifndef BASE_DCM_ENABLED
/** \brief Enable status of the module Dcm (/Dcm/Dcm) (VariantPreCompile) */
#define BASE_DCM_ENABLED STD_OFF
#endif

#ifndef BASE_DCM_HEADER
/** \brief Name of the Dcm (/Dcm/Dcm) module's main header file */
#define BASE_DCM_HEADER <Dcm.h>
#endif

#ifndef BASE_DEM_ENABLED
/** \brief Enable status of the module Dem (/Dem/Dem) (VariantPreCompile) */
#define BASE_DEM_ENABLED STD_OFF
#endif

#ifndef BASE_DEM_HEADER
/** \brief Name of the Dem (/Dem/Dem) module's main header file */
#define BASE_DEM_HEADER <Dem.h>
#endif

#ifndef BASE_DET_ENABLED
/** \brief Enable status of the module Det (/Det/Det) (VariantPreCompile) */
#define BASE_DET_ENABLED STD_ON
#endif

#ifndef BASE_DET_HEADER
/** \brief Name of the Det (/Det/Det) module's main header file */
#define BASE_DET_HEADER <Det.h>
#endif

#ifndef BASE_DIO_ENABLED
/** \brief Enable status of the module Dio (/Dio/Dio) (VariantLinkTime) */
#define BASE_DIO_ENABLED STD_ON
#endif

#ifndef BASE_DIO_HEADER
/** \brief Name of the Dio (/Dio/Dio) module's main header file */
#define BASE_DIO_HEADER <Dio.h>
#endif

#ifndef BASE_DMA_ENABLED
/** \brief Enable status of the module Dma (/Dma/Dma) (VariantPreCompile) */
#define BASE_DMA_ENABLED STD_OFF
#endif

#ifndef BASE_DMA_HEADER
/** \brief Name of the Dma (/Dma/Dma) module's main header file */
#define BASE_DMA_HEADER <Dma.h>
#endif

#ifndef BASE_EA_ENABLED
/** \brief Enable status of the module Ea (/Ea/Ea) (VariantPreCompile) */
#define BASE_EA_ENABLED STD_OFF
#endif

#ifndef BASE_EA_HEADER
/** \brief Name of the Ea (/Ea/Ea) module's main header file */
#define BASE_EA_HEADER <Ea.h>
#endif

#ifndef BASE_ECUC_ENABLED
/** \brief Enable status of the module EcuC (/EcuC/EcuC) (VariantPostBuild) */
#define BASE_ECUC_ENABLED STD_ON
#endif

#ifndef BASE_ECUC_HEADER
/** \brief Name of the EcuC (/EcuC/EcuC) module's main header file */
#define BASE_ECUC_HEADER <EcuC.h>
#endif

#ifndef BASE_ECUM_ENABLED
/** \brief Enable status of the module EcuM (/EcuM/EcuM) (VariantPostBuild) */
#define BASE_ECUM_ENABLED STD_ON
#endif


#ifndef BASE_ECUM_CONFIG_PTR
/** \brief Address of the first multiple configuration container for EcuM (/EcuM/EcuM) */
#define BASE_ECUM_CONFIG_PTR (&EcuMConfiguration)
#endif


#ifndef BASE_ECUM_HEADER
/** \brief Name of the EcuM (/EcuM/EcuM) module's main header file */
#define BASE_ECUM_HEADER <EcuM.h>
#endif

#ifndef BASE_EEP_ENABLED
/** \brief Enable status of the module Eep (/Eep/Eep) (VariantPreCompile) */
#define BASE_EEP_ENABLED STD_OFF
#endif

#ifndef BASE_EEP_HEADER
/** \brief Name of the Eep (/Eep/Eep) module's main header file */
#define BASE_EEP_HEADER <Eep.h>
#endif

#ifndef BASE_FEE_ENABLED
/** \brief Enable status of the module Fee (/Fee/Fee) (VariantPreCompile) */
#define BASE_FEE_ENABLED STD_OFF
#endif

#ifndef BASE_FEE_HEADER
/** \brief Name of the Fee (/Fee/Fee) module's main header file */
#define BASE_FEE_HEADER <Fee.h>
#endif

#ifndef BASE_FLS_ENABLED
/** \brief Enable status of the module Fls (/Fls/Fls) (VariantPreCompile) */
#define BASE_FLS_ENABLED STD_OFF
#endif

#ifndef BASE_FLS_HEADER
/** \brief Name of the Fls (/Fls/Fls) module's main header file */
#define BASE_FLS_HEADER <Fls.h>
#endif

#ifndef BASE_FR_ENABLED
/** \brief Enable status of the module Fr (/Fr/Fr) (VariantPreCompile) */
#define BASE_FR_ENABLED STD_OFF
#endif

#ifndef BASE_FR_HEADER
/** \brief Name of the Fr (/Fr/Fr) module's main header file */
#define BASE_FR_HEADER <Fr.h>
#endif

#ifndef BASE_FRIF_ENABLED
/** \brief Enable status of the module FrIf (/FrIf/FrIf) (VariantPreCompile) */
#define BASE_FRIF_ENABLED STD_OFF
#endif

#ifndef BASE_FRIF_HEADER
/** \brief Name of the FrIf (/FrIf/FrIf) module's main header file */
#define BASE_FRIF_HEADER <FrIf.h>
#endif

#ifndef BASE_FRNM_ENABLED
/** \brief Enable status of the module FrNm (/FrNm/FrNm) (VariantPreCompile) */
#define BASE_FRNM_ENABLED STD_OFF
#endif

#ifndef BASE_FRNM_HEADER
/** \brief Name of the FrNm (/FrNm/FrNm) module's main header file */
#define BASE_FRNM_HEADER <FrNm.h>
#endif

#ifndef BASE_FRSM_ENABLED
/** \brief Enable status of the module FrSM (/FrSM/FrSM) (VariantPreCompile) */
#define BASE_FRSM_ENABLED STD_OFF
#endif

#ifndef BASE_FRSM_HEADER
/** \brief Name of the FrSM (/FrSM/FrSM) module's main header file */
#define BASE_FRSM_HEADER <FrSM.h>
#endif

#ifndef BASE_FRTP_ENABLED
/** \brief Enable status of the module FrTp (/FrTp/FrTp) (VariantPreCompile) */
#define BASE_FRTP_ENABLED STD_OFF
#endif

#ifndef BASE_FRTP_HEADER
/** \brief Name of the FrTp (/FrTp/FrTp) module's main header file */
#define BASE_FRTP_HEADER <FrTp.h>
#endif

#ifndef BASE_FRTRCV_ENABLED
/** \brief Enable status of the module FrTrcv (/FrTrcv/FrTrcv) (VariantPreCompile) */
#define BASE_FRTRCV_ENABLED STD_OFF
#endif

#ifndef BASE_FRTRCV_HEADER
/** \brief Name of the FrTrcv (/FrTrcv/FrTrcv) module's main header file */
#define BASE_FRTRCV_HEADER <FrTrcv.h>
#endif

#ifndef BASE_GPT_ENABLED
/** \brief Enable status of the module Gpt (/Gpt/Gpt) (VariantPreCompile) */
#define BASE_GPT_ENABLED STD_OFF
#endif

#ifndef BASE_GPT_HEADER
/** \brief Name of the Gpt (/Gpt/Gpt) module's main header file */
#define BASE_GPT_HEADER <Gpt.h>
#endif

#ifndef BASE_IPDUM_ENABLED
/** \brief Enable status of the module IpduM (/IpduM/IpduM) (VariantPreCompile) */
#define BASE_IPDUM_ENABLED STD_OFF
#endif

#ifndef BASE_IPDUM_HEADER
/** \brief Name of the IpduM (/IpduM/IpduM) module's main header file */
#define BASE_IPDUM_HEADER <IpduM.h>
#endif

#ifndef BASE_MCU_ENABLED
/** \brief Enable status of the module Mcu (/Mcu/Mcu) (VariantPostBuild) */
#define BASE_MCU_ENABLED STD_ON
#endif

#ifndef BASE_MCU_HEADER
/** \brief Name of the Mcu (/Mcu/Mcu) module's main header file */
#define BASE_MCU_HEADER <Mcu.h>
#endif

#ifndef BASE_MEMIF_ENABLED
/** \brief Enable status of the module MemIf (/MemIf/MemIf) (VariantPreCompile) */
#define BASE_MEMIF_ENABLED STD_OFF
#endif

#ifndef BASE_MEMIF_HEADER
/** \brief Name of the MemIf (/MemIf/MemIf) module's main header file */
#define BASE_MEMIF_HEADER <MemIf.h>
#endif

#ifndef BASE_NM_ENABLED
/** \brief Enable status of the module Nm (/Nm/Nm) (VariantPreCompile) */
#define BASE_NM_ENABLED STD_OFF
#endif

#ifndef BASE_NM_HEADER
/** \brief Name of the Nm (/Nm/Nm) module's main header file */
#define BASE_NM_HEADER <Nm.h>
#endif

#ifndef BASE_NVM_ENABLED
/** \brief Enable status of the module NvM (/NvM/NvM) (VariantPreCompile) */
#define BASE_NVM_ENABLED STD_OFF
#endif

#ifndef BASE_NVM_HEADER
/** \brief Name of the NvM (/NvM/NvM) module's main header file */
#define BASE_NVM_HEADER <NvM.h>
#endif

#ifndef BASE_OS_ENABLED
/** \brief Enable status of the module Os (/Os/Os) (VariantPreCompile) */
#define BASE_OS_ENABLED STD_ON
#endif

#ifndef BASE_OS_HEADER
/** \brief Name of the Os (/Os/Os) module's main header file */
#define BASE_OS_HEADER <Os.h>
#endif

#ifndef BASE_PDUR_ENABLED
/** \brief Enable status of the module PduR (/PduR/PduR) (VariantPreCompile) */
#define BASE_PDUR_ENABLED STD_OFF
#endif

#ifndef BASE_PDUR_HEADER
/** \brief Name of the PduR (/PduR/PduR) module's main header file */
#define BASE_PDUR_HEADER <PduR.h>
#endif

#ifndef BASE_PORT_ENABLED
/** \brief Enable status of the module Port (/Port/Port) (VariantPostBuild) */
#define BASE_PORT_ENABLED STD_ON
#endif

#ifndef BASE_PORT_HEADER
/** \brief Name of the Port (/Port/Port) module's main header file */
#define BASE_PORT_HEADER <Port.h>
#endif

#ifndef BASE_PWM_ENABLED
/** \brief Enable status of the module Pwm (/Pwm/Pwm) (VariantPreCompile) */
#define BASE_PWM_ENABLED STD_OFF
#endif

#ifndef BASE_PWM_HEADER
/** \brief Name of the Pwm (/Pwm/Pwm) module's main header file */
#define BASE_PWM_HEADER <Pwm.h>
#endif

#ifndef BASE_RESOURCE_ENABLED
/** \brief Enable status of the module Resource (/Resource/Resource) (VariantPreCompile) */
#define BASE_RESOURCE_ENABLED STD_ON
#endif

#ifndef BASE_RESOURCE_HEADER
/** \brief Name of the Resource (/Resource/Resource) module's main header file */
#define BASE_RESOURCE_HEADER <Resource.h>
#endif

#ifndef BASE_SPI_ENABLED
/** \brief Enable status of the module Spi (/Spi/Spi) (VariantPreCompile) */
#define BASE_SPI_ENABLED STD_OFF
#endif

#ifndef BASE_SPI_HEADER
/** \brief Name of the Spi (/Spi/Spi) module's main header file */
#define BASE_SPI_HEADER <Spi.h>
#endif

#ifndef BASE_WDG_ENABLED
/** \brief Enable status of the module Wdg (/Wdg/Wdg) (VariantPreCompile) */
#define BASE_WDG_ENABLED STD_OFF
#endif

#ifndef BASE_WDG_HEADER
/** \brief Name of the Wdg (/Wdg/Wdg) module's main header file */
#define BASE_WDG_HEADER <Wdg.h>
#endif

#ifndef BASE_XCP_ENABLED
/** \brief Enable status of the module Xcp (/Xcp/Xcp) (VariantPreCompile) */
#define BASE_XCP_ENABLED STD_ON
#endif


#ifndef BASE_XCP_CONFIG_PTR
/** \brief Address of the first multiple configuration container for Xcp (/Xcp/Xcp) */
#define BASE_XCP_CONFIG_PTR (&XcpConfig)
#endif


#ifndef BASE_XCP_HEADER
/** \brief Name of the Xcp (/Xcp/Xcp) module's main header file */
#define BASE_XCP_HEADER <Xcp.h>
#endif

#endif /* if !defined( BASE_MODULES_H ) */
/*==================[end of file]============================================*/
