/**
 * \file
 *
 * \brief AUTOSAR ApplTemplates
 *
 * This file contains the implementation of the AUTOSAR
 * module ApplTemplates.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2015 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef PLATFORMS_MODULES_H
#define PLATFORMS_MODULES_H


/*==================[includes]==============================================*/
#include "Base_Modules.h"
#include "Can.h"
#include "Fr_17_Eray.h"
#include "Dma.h"
#include "Spi.h"
#include "Mcu.h"
#include "Gpt.h"
#include "Port.h"
#include "Pwm.h"

/*==================[macros]================================================*/

/*
 * Here you can define platform-specific names for init functions 
 * and configuration pointer names when modules require other init function
 * names or configuration pointer names than defined in BswM_Modules.h
 * or Base_Modules.h.
 */

#define BASE_GPT_CONFIG_PTR       &Gpt_Config
#define BASE_MCU_CONFIG_PTR       &Mcu_Config 
#define BASE_PORT_CONFIG_PTR      &Port_Config
#define BASE_FR_CONFIG_PTR        &Fr_17_Eray_Config
#define BASE_FLS_CONFIG_PTR       &Fls_17_Pmu_Config
#define BASE_DMA_CONFIG_PTR       &Dma_Config
#define BASE_SPI_CONFIG_PTR       &Spi_Config
#define BASE_CAN_CONFIG_PTR       &Can_17_McmCan_Config
#define BASE_PWM_CONFIG_PTR       &Pwm_17_Gtm_Config
#define BASE_ADC_CONFIG_PTR       &Adc_Config

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*Mcal configuration that was not explicitly exported */
extern const Mcu_ConfigType           Mcu_Config; 
extern const Gpt_ConfigType           Gpt_Config;
extern const Port_ConfigType          Port_Config;
extern const Fr_17_Eray_ConfigType    Fr_17_Eray_Config;
extern const Can_17_McmCan_ConfigType Can_17_McmCan_Config;
extern const Dma_ConfigType           Dma_Config;
extern const Spi_ConfigType           Spi_Config;

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* ifndef PLATFORMS_MODULES_H */

/*==================[end of file]===========================================*/
