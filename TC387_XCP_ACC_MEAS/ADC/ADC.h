/*
 * ADC.h
 *
 *  Created on: Jun 1, 2023
 *      Author: uif47623
 */
#ifndef ADC_H_
#define ADC_H_

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "IfxEvadc_Adc.h"
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

#define ADC_THRESHOLD       0.1
#define MINUS_THRESHOLD     -100
#define PLUS_THRESHOLD      100

#define CONVERT_TO_G(x)     (float)x / (-100.00)
#define GET_FRACT(x)        x - (int) x

#define CHANGE_SIGN(x)      -x
/*********************************************************************************************************************/
/*--------------------------------------------------Data Structures--------------------------------------------------*/
/*********************************************************************************************************************/
typedef struct {
        float xAxisValue;
        float yAxisValue;
        float zAxisValue;
} ADC_Results_t;
/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/
void initEVADC(void);
void readEVADC(void);

extern void getADCRes(ADC_Results_t);

#endif /* ADC_H_ */

//END OF FILE
