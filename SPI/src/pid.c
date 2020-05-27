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
#define kpH 300
#define kiH 30
#define kdH 900

#define kpV 100
#define kiV 10
#define kdV 300

/********************** External declaration of Variables ******************/

/*****************************   Constants   *******************************/

/*****************************   variable    *******************************/
extern volatile INT16S tickH;
extern volatile INT16S tickV;

int16_t errorSumH, errorDiffH, errorPreH, errorSumV, errorDiffV, errorPreV = 0;

//for optimisation (to stop function form initializing at every call)
int16_t pwmOut = 0;
int16_t error = 0;
bool antiwindup = false;

/*************************  Function interfaces ****************************/

void pidH()
{

    error = serialcom_get_hor() - requestframe(1, 0);
    errorSumH += (tickH/2)*(error+errorPreH);
    errorDiffH -= (2/tickH)*(error-errorPreH);

    pwmOut = error*kpH + errorSumH*kiH + errorDiffH*kdH;

    if (pwmOut < 0)
        senddataframe(1, 1, pwmOut);
    else
        senddataframe(1, 0, pwmOut);
    tickH = 0;
}

void pidV()
{

    error = serialcom_get_ver() - requestframe(0, 0);
    errorSumV += (tickV/2)*(error+errorPreV);
    errorDiffV -= (2/tickV)*(error-errorPreV);

    pwmOut = error*kpV + errorSumV*kiV + errorDiffV*kdV;

    if (pwmOut < 0)
        senddataframe(0, 1, pwmOut);
    else
        senddataframe(0, 0, pwmOut);

    tickV = 0;
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



