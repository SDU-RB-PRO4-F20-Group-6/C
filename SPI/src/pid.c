/*
 * pid.c
 *
 *  Created on: 20. apr. 2020
 *      Author: claus
 */

/*
 * pid.h
 *
 *  Created on: 20. apr. 2020
 *      Author: claus
 */

#ifndef INC_PID_H_
#define INC_PID_H_
/***************************** Include files *******************************/
#include <stdint.h>
#include <stdbool.h>
#include "pid.h"
/*****************************    Defines    *******************************/
#define kpH 1
#define kiH 1
#define kdH 1
#define UPPER_THRESHOLD_H 0
#define LOWER_THRESHOLD_H 0

#define kpV 1
#define kiV 1
#define kdV 1
#define UPPER_THRESHOLD_V 0
#define LOWER_THRESHOLD_V 0

/********************** External declaration of Variables ******************/

/*****************************   Constants   *******************************/

/*****************************   variable    *******************************/
int16_t errorSumH, errorDiffH, errorPreH, errorSumV, errorDiffV, errorPreV = 0;

//for optimisation (to stop function form initializing at every call)
int16_t pwmOut = 0;
int16_t error = 0;
bool antiwindup = false;

/*************************  Function interfaces ****************************/

void pidH()
{

    error = serialcom_get_hor() - requestframe(1, 0);
    if (error < UPPER_THRESHOLD_H && error > LOWER_THRESHOLD_H)
        errorSumH += error;
    errorDiffH = errorPreH - error;

    pwmOut = error*kpH + errorSumH*kiH + errorDiffH*kdH;

    if (pwmOut < 0)
        senddataframe(1, 1, pwmOut);
    else
        senddataframe(1, 0, pwmOut);
}

void pidV()
{

    error = serialcom_get_ver() - requestframe(0, 0);
    if (error < UPPER_THRESHOLD_V && error > LOWER_THRESHOLD_V)
        errorSumV += error;
    errorDiffV = errorPreV - error;

    pwmOut = error*kpV + errorSumV*kiV + errorDiffV*kdV;

    if (pwmOut < 0)
        senddataframe(0, 1, pwmOut);
    else
        senddataframe(0, 0, pwmOut);
}


#endif /* INC_PID_H_ */
/****************************** End Of Module *******************************/


/* Change Log:
*****************************************************************************
* Date    Id    Change
* DDMMYY
* --------------------
* 200420  TH/MW/CH    Module created.
* 280420  TH/MW/CH    Added conditional integration
*/



