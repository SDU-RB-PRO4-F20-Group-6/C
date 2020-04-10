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
* Change Log:
******************************************************************************
See [$filename$].c
*****************************************************************************/

//#ifndef "HEADERNAME"
//#define "HEADERNAME"

/***************************** Include files *******************************/
#include <emp_type.h>
#include <glob_def.h>
/*****************************    Defines    *******************************/

/********************** External declaration of Variables ******************/

/*****************************   Constants   *******************************/

/*************************  Function interfaces ****************************/

extern void function1(void);
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Test function
******************************************************************************/

void senddataframe(BOOLEAN mcselect, BOOLEAN mdir, INT16U PWM);
/*****************************************************************************
*   Input    : the values needed for frame construction
*   Output   : -
*   Function : creates a full frame and transmits
******************************************************************************/


extern void requestframe(BOOLEAN motorchoice, BOOLEAN datatype);
/*****************************************************************************
*   Input    : specification of chosen motor [0/1] and the type of data [hallindex/motorposition] = [1/0]
*   Output   : -
*   Function : requests different types of frames from the FPGA
******************************************************************************/


 BOOLEAN evenparity(INT16U frame);
/*****************************************************************************
*   Input    : the frame without parity
*   Output   : if parity is true or false
*   Function : parity calculator for both checking and creating
******************************************************************************/

/****************************** End Of Module *******************************/
//#endif
