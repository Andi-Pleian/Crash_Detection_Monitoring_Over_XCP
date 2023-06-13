/*
 * Crash_Detection.c
 *
 *  Created on: Jun 9, 2023
 *      Author: uif47623
 */
/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "Crash_Detection.h"
/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
CrashDetection_T CarData;
extern ADC_Results_t ADC_Results;
/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/

float get_xVal() {
    return ADC_Results.xAxisValue;
}

float get_yVal() {
    return ADC_Results.yAxisValue;
}

float get_zVal() {
    return ADC_Results.zAxisValue;
}


enum RET_VAL isXValOK() {
    enum RET_VAL retVal = VAL_NOK;

    if (get_xVal() > 0.5 || get_xVal() < -0.5) {
        retVal = VAL_NOK;
    } else {
        retVal = VAL_OK;
    }

    return retVal;
}

enum RET_VAL isZValOK() {
    enum RET_VAL retVal = VAL_NOK;

    if (get_zVal() > -0.9 || get_zVal() < -1.5) {
        retVal = VAL_NOK;
    } else {
        retVal = VAL_OK;
    }

    return retVal;
}

enum RET_VAL checkUpsideDown() {
    enum RET_VAL retVal = VAL_NOK;

    if (get_zVal() < -0.5) {
        retVal = VAL_OK;
    }

    return retVal;
}

enum RET_VAL checkFlippedLeft() {
    return 0;
}

enum RET_VAL checkFlippedRight() {
    return 0;
}


enum CAR_STATE_T    computeCarState() {
   // init return val with error state
   enum CAR_STATE_T retVal = CAR_STATE_ERROR;

  /* if (isXValOK() && isZValOK()) {
       //retVal = CAR_STATE_NORMAL;
   } else */ if (checkUpsideDown() == VAL_OK){
       retVal = CAR_STATE_UPSIDE_DOWN;
   } else if (checkFlippedRight()){
       retVal = CAR_STATE_FLIPPED_RIGHT;
   } else if (checkFlippedLeft()){
       retVal = CAR_STATE_FLIPPED_LEFT;
   }

   return retVal;
}

enum CRASH_STATE_T  computeCrashState() {
    enum CRASH_STATE_T retVal = CRASH_STATE_ERROR;

    return retVal;
}

void initCrashDetection() {
    CarData.xVal = DEFAULT_AXIS_VALUE;
    CarData.yVal = DEFAULT_AXIS_VALUE;
    CarData.zVal = DEFAULT_AXIS_VALUE;

    CarData.carState     = CAR_STATE_NORMAL;
    CarData.crashState   = NO_CRASH;

    //TODO: init CD_ADC_Results
}

void MainFunction_CrashDetection() {
    //getADCRes(CD_ADC_Results);

    CarData.xVal = get_xVal();
    CarData.yVal = get_yVal();
    CarData.zVal = get_zVal();

    CarData.carState     = computeCarState();
    CarData.crashState   = computeCrashState();
}

//END OF FILE

