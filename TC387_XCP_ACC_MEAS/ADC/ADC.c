/*
 * ADC.c
 *
 *  Created on: Jun 1, 2023
 *      Author: uif47623
 */
/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "ADC.h"
/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
IfxEvadc_Adc         g_evadc;
IfxEvadc_Adc_Group   g_adcGroup;
IfxEvadc_Adc_Channel g_adcChannel[CHANNELS_NUM];                         /* channels array                           */

uint8 g_grp2channels[CHANNELS_NUM] = {AN17_CHID, AN20_CHID, AN21_CHID};  /* AN17, AN20, AN21 channel IDs array       */

Ifx_EVADC_G_RES g_results[CHANNELS_NUM];                                 /* Array of results                        */

sint32 x_AxisValue = AXIS_DEFAULT_VALUE;
sint32 y_AxisValue = AXIS_DEFAULT_VALUE;
sint32 z_AxisValue = AXIS_DEFAULT_VALUE;

float x_AxisG = AXIS_DEFAULT_VALUE;
float y_AxisG = AXIS_DEFAULT_VALUE;
float z_AxisG = AXIS_DEFAULT_VALUE;

ADC_Results_t ADC_Results;

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/
void initEVADCModule(void);
void initEVADCGroup(void);
void initEVADCChannels(void);
void fillAndStartQueue(void);
/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
void getADCRes(ADC_Results_t paramRes) {
    paramRes.xAxisValue = ADC_Results.xAxisValue;
    paramRes.yAxisValue = ADC_Results.yAxisValue;
    paramRes.zAxisValue = ADC_Results.zAxisValue;
}

void initEVADC()
{
    initEVADCModule();
    initEVADCGroup();
    initEVADCChannels();
    fillAndStartQueue();
}

void initEVADCModule()
{
    // create config
    IfxEvadc_Adc_Config adcConfig;
    IfxEvadc_Adc_initModuleConfig(&adcConfig, &MODULE_EVADC);

    // init module
    IfxEvadc_Adc_initModule(&g_evadc, &adcConfig);
}

void initEVADCGroup()
{
    // create and init group configuration with default values
    IfxEvadc_Adc_GroupConfig adcGroupConfig;
    IfxEvadc_Adc_initGroupConfig(&adcGroupConfig, &g_evadc);

    adcGroupConfig.groupId = GROUPID_2;
    adcGroupConfig.master = GROUPID_2;

    adcGroupConfig.arbiter.requestSlotQueue0Enabled = TRUE;

    adcGroupConfig.queueRequest[0].triggerConfig.gatingMode = IfxEvadc_GatingMode_always;

    // init group
    IfxEvadc_Adc_initGroup(&g_adcGroup, &adcGroupConfig);
}

void initEVADCChannels()
{
    // create channel config
    IfxEvadc_Adc_ChannelConfig adcChannelConfig[CHANNELS_NUM];

    for(uint16 idx = 0; idx < CHANNELS_NUM; idx++)
    {
        // init config with default values
        IfxEvadc_Adc_initChannelConfig(&adcChannelConfig[idx], &g_adcGroup);

        adcChannelConfig[idx].channelId = (IfxEvadc_ChannelId)(g_grp2channels[idx]);
        adcChannelConfig[idx].resultRegister = (IfxEvadc_ChannelResult)(g_grp2channels[idx]);

        // init channel
        IfxEvadc_Adc_initChannel(&g_adcChannel[idx], &adcChannelConfig[idx]);
    }
}

void fillAndStartQueue()
{
    for(uint16 idx = 0; idx < CHANNELS_NUM; idx++)
    {
        // add channel to queue with refill option enabled
        IfxEvadc_Adc_addToQueue(&g_adcChannel[idx], IfxEvadc_RequestSource_queue0, IFXEVADC_QUEUE_REFILL);
    }

    // start the queue
    IfxEvadc_Adc_startQueue(&g_adcGroup, IfxEvadc_RequestSource_queue0);
}

sint32 map(sint32 x, sint32 inMin, sint32 inMax, sint32 outMin, sint32 outMax){
    return (x - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
}

float normalizeStaticVal(float value) {
    float x = value;

    if (x > 0) {
        //check if x is in threshold interval
        if (x < 0.1) {
            x = 0;
        }
    } else if (x < 0) {
        //check if x is in threshold interval
        if (x > -0.1) {
            x = 0;
        }
    }

    return x;
}

void readEVADC()
{
    for(uint8 i = 0; i < CHANNELS_NUM; i++)
    {
        // Wait for a valid result
        Ifx_EVADC_G_RES conversionResult;
        do
        {
            conversionResult = IfxEvadc_Adc_getResult(&g_adcChannel[i]); // read the result of the selected channel
        } while(!conversionResult.B.VF);

        g_results[i] = conversionResult;
    }

    x_AxisValue = map(g_results[X_CHANNEL_ID].B.RESULT, X_MINUS_1G_VALUE, X_PLUS_1G_VALUE, MINUS_THRESHOLD, PLUS_THRESHOLD);
    y_AxisValue = map(g_results[Y_CHANNEL_ID].B.RESULT, Y_MINUS_1G_VALUE, Y_PLUS_1G_VALUE, MINUS_THRESHOLD, PLUS_THRESHOLD);
    z_AxisValue = map(g_results[Z_CHANNEL_ID].B.RESULT, Z_MINUS_1G_VALUE, Z_PLUS_1G_VALUE, MINUS_THRESHOLD, PLUS_THRESHOLD);

    x_AxisG = CONVERT_TO_G(x_AxisValue);
    y_AxisG = CONVERT_TO_G(y_AxisValue);
    // sensor is inverted, so Z value should be inverted as well
    // if not, Z value will be -1g when car is normal and it is not correct
    z_AxisG = CHANGE_SIGN(CONVERT_TO_G(z_AxisValue));

    ADC_Results.xAxisValue = x_AxisG;//normalizeStaticVal(x_AxisG);
    ADC_Results.yAxisValue = y_AxisG;//normalizeStaticVal(y_AxisG);
    ADC_Results.zAxisValue = z_AxisG;//normalizeStaticVal(z_AxisG);

//    if (GET_FRACT(x_AxisG) < ADC_THRESHOLD && GET_FRACT(x_AxisG) > CHANGE_SIGN(ADC_THRESHOLD)) {
//        x_AxisG -= GET_FRACT(x_AxisG);
//    }
//    if (GET_FRACT(y_AxisG) < ADC_THRESHOLD && GET_FRACT(y_AxisG) > CHANGE_SIGN(ADC_THRESHOLD)) {
//        y_AxisG -= GET_FRACT(y_AxisG);
//    }
//    if (GET_FRACT(z_AxisG) < ADC_THRESHOLD && GET_FRACT(z_AxisG) > CHANGE_SIGN(ADC_THRESHOLD)) {
//        z_AxisG -= GET_FRACT(z_AxisG);
//    }
}

//END OF FILE
