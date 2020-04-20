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
/*****************************    Defines    *******************************/

/********************** External declaration of Variables ******************/

/*****************************   Constants   *******************************/

/*************************  Function interfaces ****************************/

void pidH(int16_t reference);

void pidV(int16_t reference);



#endif /* INC_PID_H_ */
