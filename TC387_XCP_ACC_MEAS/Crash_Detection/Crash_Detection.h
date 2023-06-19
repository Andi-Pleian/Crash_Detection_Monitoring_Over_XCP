/*
 * Crash_Detection.h
 *
 *  Created on: Jun 9, 2023
 *      Author: uif47623
 */

#ifndef CRASH_DETECTION_CRASH_DETECTION_H_
#define CRASH_DETECTION_CRASH_DETECTION_H_

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "ADC_Queued_Scan.h"
/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
enum CAR_STATE_T {CAR_STATE_ERROR,
                  CAR_STATE_NORMAL,
                  CAR_STATE_UPSIDE_DOWN,
                  CAR_STATE_FLIPPED_RIGHT,
                  CAR_STATE_FLIPPED_LEFT,
                  CAR_STATE_CRASHED};

enum CRASH_STATE_T {CRASH_STATE_ERROR,
                    CRASH_STATE_NO_CRASH,
                    CRASH_STATE_BACKSIDE_CRASH,
                    CRASH_STATE_FRONTSIDE_CRASH,
                    CRASH_STATE_LEFTSIDE_CRASH,
                    CRASH_STATE_RIGHTSIDE_CRASH};
enum RET_VAL {
        VAL_NOK,
        VAL_OK
};

#define DEFAULT_AXIS_VALUE 0

/*********************************************************************************************************************/
/*--------------------------------------------------Data Structures--------------------------------------------------*/
/*********************************************************************************************************************/
typedef struct {
        float xVal;
        float yVal;
        float zVal;

        enum CAR_STATE_T     carState;
        enum CRASH_STATE_T   crashState;
}CrashDetection_T;
/*********************************************************************************************************************/
/*-----------------------------------------------Function Prototypes-------------------------------------------------*/
/*********************************************************************************************************************/

float get_xVal();
float get_yVal();
float get_zVal();

enum RET_VAL isXValOK();
enum RET_VAL isYValOK();
enum RET_VAL isZValOK();

enum RET_VAL checkUpsideDown();
enum RET_VAL checkFlippedLeft();
enum RET_VAL checkFlippedRight();

enum CAR_STATE_T   getCarState();
enum CRASH_STATE_T getCrashState();

enum CAR_STATE_T    computeCarState();
enum CRASH_STATE_T  computeCrashState();

void initCrashDetection();
void MainFunction_CrashDetection();

#endif /* CRASH_DETECTION_CRASH_DETECTION_H_ */

//END OF FILE
