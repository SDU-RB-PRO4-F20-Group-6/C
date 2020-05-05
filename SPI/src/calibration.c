/*****************************************************************************
* University of Southern Denmark
* Embedded Programming (EMP)
*
* MODULENAME.: 
*
* PROJECT....: 
*
* DESCRIPTION:
*
* Change Log (SEE end of document)
*****************************************************************************

****************************** Include files *******************************/
#include <tm4c123gh6pm.h>
#include <emp_type.h>
#include <glob_def.h>
#include <stdint.h>
#include <stdbool.h>

#include <frameinit.h>
#include <calibration.h>
/*****************************    Defines    *******************************/

#define MOTOR0 0
#define MOTOR1 1

// names should change to correspond with chosen directions
#define MOTORFORWARD 0
#define MOTORBACKWARD 1

#define LOWPWM 0x0A00
#define NOPWM 0x0

#define HALLINDEXDATA 1
#define MOTORPOSITIONDATA 0


#define HALLINDEXMASK 0x1

/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/


/*****************************   Functions   *******************************/

extern void calibratesetup(void)
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : calibration for the frames to make sure they start at a predefined start position
******************************************************************************/
{
    bool hallindexmotor0found = 0;
    bool hallindexmotor1found = 0;

    // start motor 0 rotation to find limit
    senddataframe(MOTOR0, MOTORFORWARD, LOWPWM);
    int16_t recievedhallframe;


    // check hall index frame every iteration and check if hallindex = true
    while(hallindexmotor0found)
    {
       recievedhallframe = requestframe(MOTOR0, HALLINDEXDATA);

       if( recievedhallframe &= HALLINDEXMASK )
           { hallindexmotor0found = true; }
    }
    //***************************
    // insert anti overshoot here
    //***************************
    senddataframe(MOTOR0, MOTORFORWARD, NOPWM);


    // find index for motor 1
    int16_t currentposition;
    int16_t lastposition;

    // stop motor 0 from rotating


    // start motor rotation to find limit
    senddataframe(MOTOR1, MOTORFORWARD, LOWPWM);

    lastposition = requestframe(MOTOR1, MOTORPOSITIONDATA);

    // check hall index frame every iteration and check if hallindex = true
    while(hallindexmotor1found)
    {
        // check if frame position doesent change and change direction if thats true
        currentposition = requestframe(MOTOR1, MOTORPOSITIONDATA);
        if(currentposition == lastposition)
        {
            senddataframe(MOTOR1, MOTORBACKWARD, LOWPWM);
        }

        // check hall index every iteration
        recievedhallframe = requestframe(MOTOR1, HALLINDEXDATA);

        if( recievedhallframe &= HALLINDEXMASK )
            { hallindexmotor1found = true; }
    }



    //***************************
    // insert anti overshoot here
    //***************************
     senddataframe(MOTOR1, MOTORFORWARD, NOPWM);


// not failsafe method, motordirection can only go forward -> backward not backward -> forward again
// meaning if a unforseen complication happens then we cant stop again if we miss the hall index
}



/****************************** End Of Module *******************************/


/* Change Log:
*****************************************************************************
* Date    Id    Change
* DDMMYY
* --------------------
* 290420  TH    Module created.
*/
