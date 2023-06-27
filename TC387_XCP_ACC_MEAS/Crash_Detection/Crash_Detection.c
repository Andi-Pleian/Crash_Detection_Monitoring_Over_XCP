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

enum CRASH_DETECTION_CALIB CD_Calibration;
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

enum RET_VAL checkUpsideDown() {
    enum RET_VAL retVal = VAL_NOK;

    // if value on Z axis is under specific threshold return OK
    if (get_zVal() < UPSIDE_DOWN_VAL) {
        retVal = VAL_OK;
    }

    return retVal;
}

enum RET_VAL checkFlippedLeft() {
    enum RET_VAL retVal = VAL_NOK;

    // if value on X axis is over specific threshold return OK
    if (get_xVal() > FLIPPED_LEFT_VAL) {
        retVal = VAL_OK;
    }

    return retVal;
}

enum RET_VAL checkFlippedRight() {
    enum RET_VAL retVal = VAL_NOK;

    // if value on X axis is over specific threshold return OK
    if (get_xVal() < FLIPPED_RIGHT_VAL) {
        retVal = VAL_OK;
    }

    return retVal;
}

/**
 *   Return the state of the car on the road.
 */
enum CAR_STATE_T computeCarState() {
   // init return val with error state
   enum CAR_STATE_T retVal = CAR_STATE_ERROR;

   // check if car is upside down or on a side
  if (checkUpsideDown()){
      CarData.carFlipInfo = CAR_STATE_UPSIDE_DOWN;
      retVal = CAR_STATE_UPSIDE_DOWN;
   } else if (checkFlippedRight()){
       CarData.carFlipInfo = CAR_STATE_FLIPPED_RIGHT;
      retVal = CAR_STATE_FLIPPED_RIGHT;
   } else if (checkFlippedLeft()){
       CarData.carFlipInfo = CAR_STATE_FLIPPED_LEFT;
      retVal = CAR_STATE_FLIPPED_LEFT;
   } else {
      // if all values are in normal ranges, car state is set to normal
       CarData.carFlipInfo = CAR_STATE_NORMAL;
      retVal = CAR_STATE_NORMAL;
   }

   return retVal;
}

enum RET_VAL checkFrontCrash(){
    enum RET_VAL retVal = VAL_NOK;

    if (get_yVal() < FRONT_CRASH_VAL) {
        retVal = VAL_OK;
    }

    return retVal;
}

enum RET_VAL checkLeftCrash(){
    enum RET_VAL retVal = VAL_NOK;

    if (get_xVal() > LEFT_CRASH_VAL) {
        retVal = VAL_OK;
    }

    return retVal;
}

enum RET_VAL checkRightCrash(){
    enum RET_VAL retVal = VAL_NOK;

    if (get_xVal() < RIGHT_CRASH_VAL) {
        retVal = VAL_OK;
    }

    return retVal;
}

enum RET_VAL checkBackCrash(){
    enum RET_VAL retVal = VAL_NOK;

    if (get_yVal() > BACK_CRASH_VAL) {
        retVal = VAL_OK;
    }

    return retVal;
}

/**
 *   Return the crash state of the car.
 */
enum CRASH_STATE_T computeCrashState() {
    // init return val with error state
    enum CRASH_STATE_T retVal = CRASH_STATE_ERROR;

    // check type of crash
    if (checkFrontCrash()) {
        CarData.carState = CAR_STATE_CRASHED;
        retVal = CRASH_STATE_FRONTSIDE_CRASH;
    } else if (checkLeftCrash()) {
        CarData.carState = CAR_STATE_CRASHED;
        retVal = CRASH_STATE_LEFTSIDE_CRASH;
    } else if (checkRightCrash()) {
        CarData.carState = CAR_STATE_CRASHED;
        retVal = CRASH_STATE_RIGHTSIDE_CRASH;
    } else if (checkBackCrash()) {
        CarData.carState = CAR_STATE_CRASHED;
        retVal = CRASH_STATE_BACKSIDE_CRASH;
    } else {
        // if all values are in normal ranges, crash state is set to normal
        retVal = CRASH_STATE_NO_CRASH;
    }

    return retVal;
}

void Init_CrashDetection() {
    CarData.xVal = DEFAULT_AXIS_VALUE;
    CarData.yVal = DEFAULT_AXIS_VALUE;
    CarData.zVal = DEFAULT_AXIS_VALUE;

    CarData.carState     = CAR_STATE_NORMAL;
    CarData.carFlipInfo  = CAR_STATE_NORMAL;
    CarData.crashState   = CRASH_STATE_NO_CRASH;

    CD_Calibration = CRASH_DETECTION_NO_ACTION;

    //TODO: init CD_ADC_Results
}

void MainFunction_CrashDetection() {
    //getADCRes(CD_ADC_Results);

    CarData.xVal = get_xVal();
    CarData.yVal = get_yVal();
    CarData.zVal = get_zVal();

    // only compute car data if car not crashed
    if (CarData.carState != CAR_STATE_CRASHED) {
        CarData.carState     = computeCarState();
        CarData.crashState   = computeCrashState();
    } else {
        // if crashed, compute car state only to keep flip state accurate
        computeCarState();

        // car crashed, stop computing to keep the values car state and crash state
        // TODO: blackbox

        // if CD_Calibration was set to reset the algorithm, init CD again in order to
        // start computing car/crash data
        if (CD_Calibration == CRASH_DETECTION_RESET) {
            Init_CrashDetection();
        }
    }
}

//END OF FILE
