/**********************************************************************************************************************
 * \file ADC_Queued_Scan.c
 * \copyright Copyright (C) Infineon Technologies AG 2019
 *
 * Use of this file is subject to the terms of use agreed between (i) you or the company in which ordinary course of
 * business you are acting and (ii) Infineon Technologies AG or its licensees. If and as long as no such terms of use
 * are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization obtaining a copy of the software and
 * accompanying documentation covered by this license (the "Software") to use, reproduce, display, distribute, execute,
 * and transmit the Software, and to prepare derivative works of the Software, and to permit third-parties to whom the
 * Software is furnished to do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including the above license grant, this restriction
 * and the following disclaimer, must be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are solely in the form of
 * machine-executable object code generated by a source language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *********************************************************************************************************************/

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "IfxEvadc_Adc.h"
#include "ADC_Queued_Scan.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define GROUPID_2           IfxEvadc_GroupId_2                  /* EVADC group                                      */

#define CHANNELS_NUM        3                                   /* Number of used channels                          */

#define AN17_CHID           1                                   /* Channel ID for pin AN17                          */
#define AN20_CHID           4                                   /* Channel ID for pin AN20                          */
#define AN21_CHID           5                                   /* Channel ID for pin AN21                          */

#define AXIS_DEFAULT_VALUE  -100

#define X_CHANNEL_ID        0
#define Y_CHANNEL_ID        1
#define Z_CHANNEL_ID        2

#define X_MINUS_1G_VALUE    1065
#define X_PLUS_1G_VALUE     1600

#define Y_MINUS_1G_VALUE    1050
#define Y_PLUS_1G_VALUE     1572

#define Z_MINUS_1G_VALUE    1058
#define Z_PLUS_1G_VALUE     1570

#define MINUS_THRESHOLD     -100
#define PLUS_THRESHOLD      100

#define CONVERT_TO_G(x)     (float)x / (-100.00)

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
 /* EVADC handle */
IfxEvadc_Adc         g_evadc;                                   /* EVADC module handle variable                     */
IfxEvadc_Adc_Group   g_adcGroup;                                /* EVADC group handle variable                      */
IfxEvadc_Adc_Channel g_adcChannel[CHANNELS_NUM];                /* EVADC channels handle array                      */

uint8 g_grp2channels[CHANNELS_NUM] = {AN17_CHID, AN20_CHID, AN21_CHID}; /* AN17, AN20, AN21 channel IDs array       */

Ifx_EVADC_G_RES g_results[CHANNELS_NUM];                        /* Array of results                                 */

sint32 x_AxisValue = AXIS_DEFAULT_VALUE;
sint32 y_AxisValue = AXIS_DEFAULT_VALUE;
sint32 z_AxisValue = AXIS_DEFAULT_VALUE;

float x_AxisG = AXIS_DEFAULT_VALUE;
float y_AxisG = AXIS_DEFAULT_VALUE;
float z_AxisG = AXIS_DEFAULT_VALUE;

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/
void initEVADCModule(void);                                     /* Function to initialize the EVADC module          */
void initEVADCGroup(void);                                      /* Function to initialize the EVADC group           */
void initEVADCChannels(void);                                   /* Function to initialize the EVADC channels        */
void fillAndStartQueue(void);                             /* Function to add each channel to the queue and start it */

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
/* Function to initialize the EVADC with default parameters */
void initEVADC()
{
    initEVADCModule();      /* Initialize the EVADC module  */
    initEVADCGroup();       /* Initialize the EVADC group   */
    initEVADCChannels();    /* Initialize the channels      */
    fillAndStartQueue();    /* Fill the queue and start it  */
}

/* Function to initialize the EVADC module with default parameters */
void initEVADCModule()
{
    /* Create configuration */
    IfxEvadc_Adc_Config adcConfig;
    IfxEvadc_Adc_initModuleConfig(&adcConfig, &MODULE_EVADC);

    /* Initialize module */
    IfxEvadc_Adc_initModule(&g_evadc, &adcConfig);
}

/* Function to initialize the EVADC group with default parameters */
void initEVADCGroup()
{
    /* Create and initialize group configuration with default values */
    IfxEvadc_Adc_GroupConfig adcGroupConfig;
    IfxEvadc_Adc_initGroupConfig(&adcGroupConfig, &g_evadc);

    /* Setting user configuration using group 2 */
    adcGroupConfig.groupId = GROUPID_2;
    adcGroupConfig.master = GROUPID_2;

    /* Enable queued source */
    adcGroupConfig.arbiter.requestSlotQueue0Enabled = TRUE;

    /* Enable all gates in "always" mode (no edge detection) */
    adcGroupConfig.queueRequest[0].triggerConfig.gatingMode = IfxEvadc_GatingMode_always;

    /* Initialize the group */
    IfxEvadc_Adc_initGroup(&g_adcGroup, &adcGroupConfig);
}

void initEVADCChannels()
{
    /* Create channel configuration */
    IfxEvadc_Adc_ChannelConfig adcChannelConfig[CHANNELS_NUM];

    for(uint16 idx = 0; idx < CHANNELS_NUM; idx++)
    {
        /* Initialize the configuration with default values */
        IfxEvadc_Adc_initChannelConfig(&adcChannelConfig[idx], &g_adcGroup);

        /* Select the channel ID and the respective result register */
        adcChannelConfig[idx].channelId = (IfxEvadc_ChannelId)(g_grp2channels[idx]);
        adcChannelConfig[idx].resultRegister = (IfxEvadc_ChannelResult)(g_grp2channels[idx]);

        /* Initialize the channel */
        IfxEvadc_Adc_initChannel(&g_adcChannel[idx], &adcChannelConfig[idx]);
    }
}

void fillAndStartQueue()
{
    for(uint16 idx = 0; idx < CHANNELS_NUM; idx++)
    {
        /* Add channel to queue with refill option enabled */
        IfxEvadc_Adc_addToQueue(&g_adcChannel[idx], IfxEvadc_RequestSource_queue0, IFXEVADC_QUEUE_REFILL);
    }

    /* Start the queue */
    IfxEvadc_Adc_startQueue(&g_adcGroup, IfxEvadc_RequestSource_queue0);
}

sint32 map(sint32 x, sint32 inMin, sint32 inMax, sint32 outMin, sint32 outMax){
    return (x - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
}

/* Function to read the EVADC used channel */
void readEVADC()
{
    for(uint8 i = 0; i < CHANNELS_NUM; i++)
    {
        /* Wait for a valid result */
        Ifx_EVADC_G_RES conversionResult;
        do
        {
            conversionResult = IfxEvadc_Adc_getResult(&g_adcChannel[i]); /* Read the result of the selected channel */
        } while(!conversionResult.B.VF);

        g_results[i] = conversionResult;
    }

    //                    X                                      1065           1600            -100            +100
    x_AxisValue = map(g_results[X_CHANNEL_ID].B.RESULT, X_MINUS_1G_VALUE, X_PLUS_1G_VALUE, MINUS_THRESHOLD, PLUS_THRESHOLD);
    y_AxisValue = map(g_results[Y_CHANNEL_ID].B.RESULT, Y_MINUS_1G_VALUE, Y_PLUS_1G_VALUE, MINUS_THRESHOLD, PLUS_THRESHOLD);
    z_AxisValue = map(g_results[Z_CHANNEL_ID].B.RESULT, Z_MINUS_1G_VALUE, Z_PLUS_1G_VALUE, MINUS_THRESHOLD, PLUS_THRESHOLD);

    x_AxisG = CONVERT_TO_G(x_AxisValue);
    y_AxisG = CONVERT_TO_G(y_AxisValue);
    z_AxisG = CONVERT_TO_G(z_AxisValue);
}
