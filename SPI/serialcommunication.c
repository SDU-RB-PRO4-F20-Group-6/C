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
#include <uart0.h>
/*****************************    Defines    *******************************/

/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/

INT8U    commandline[9]; // Saved characters from cli.
INT8U    commandlinepointer = 0; // Pointer to commandline[9]. Indicates next char in array to be input.

/*****************************   Functions   *******************************/

extern void function1(void);
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Test function
******************************************************************************/

void serialcommunication_standardinitialize(void)
/*****************************************************************************
*   Input    :
*   Output   :
*   Function :
******************************************************************************/
{
    uart0_init(9600,8,1,'n');
}


extern void serialcom_printchar(INT8U inpchar)
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Test function
******************************************************************************/
{
    while(!uart0_tx_rdy());

    uart0_putc(inpchar);
}

extern INT8U serialcom_getchar(void)
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Test function
******************************************************************************/
{
    if(uart0_rx_rdy())
    {
        return uart0_getc();
    }
    else
    {
        return 0;
    }
}

extern void serialcom_printnl(void)
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Test function
******************************************************************************/
{
    serialcom_printchar(0x0a);
    serialcom_printchar(0x0d);
}


extern void serialcom_setparameters(void)
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Function that gets parameters from a serial terminal program
******************************************************************************/
{
    // gets the first control parameter 'H' meaning horizontal values will now be input
    // error 'X' will be output should the control parameter be faulty

    if(serialcom_getchar() == 'H')
    {
        commandline[commandlinepointer] = 'H';
        commandlinepointer++;
    }
    else
    {
        serialcom_printnl();
        serialcom_printchar('X');
    }

    // takes the next 4 chars
    for(int i = 0; i < 4; i++)
    {
        commandline[commandlinepointer] = serialcom_getchar();
        commandlinepointer++;
    }

    // next control parameter & error value output
    if(serialcom_getchar() == 'V')
    {
        commandline[commandlinepointer] = 'V';
        commandlinepointer++;
    }
    else
    {
        serialcom_printnl();
        serialcom_printchar('X');
    }

    // takes next 4 chars
    for(int i = 0; i < 4; i++)
    {
        commandline[commandlinepointer] = serialcom_getchar();
        commandlinepointer++;
    }

    // resets pointer
    commandlinepointer = 0;

    /*
     * INSERT FUNCTION TO RECIEVE THE INPUT DATA AND DOES SOMETHING WITH IT
     */
}


/****************************** End Of Module *******************************/


/* Change Log:
*****************************************************************************
* Date    Id    Change
* DDMMYY
* --------------------
* XXYYZZ  TH    Module created.
*/










