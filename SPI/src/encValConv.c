/*
 * encValConv.c
 *
 *  Created on: 20. apr. 2020
 *      Author: claus
 */
/***************************** Include files *******************************/
#include <stdint.h>
#include "encValConv.h"
#include <math.h>

/*****************************    Defines    *******************************/
#define dis2Wall 2000
#define PI 3.14159265
/********************** External declaration of Variables ******************/

/*****************************   Constants   *******************************/

/*************************  Function interfaces ****************************/

double enc2Len (double enc)
{
    return tan(enc * (2*PI)/32400)* dis2Wall;
}


double len2Enc(double len)
{
    return atan2(len, dis2Wall);
}

/****************************** End Of Module *******************************/


/* Change Log:
*****************************************************************************
* Date    Id    Change
* DDMMYY
* --------------------
* 200420  TH/MW/CH    Module created.
*/



