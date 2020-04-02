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
#include <stdint.h>
#include <emp_type.h>
#include <glob_def.h>
#include <serialcommunication.h>
#include <spi.h>
/*****************************    Defines    *******************************/

/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/


/*****************************   Functions   *******************************/


void DummyRead(void)
/*****************************************************************************
*   Input    :
*   Output   :
*   Function : inserts a few cycles before use of GPIO PORTF
******************************************************************************/
{
    // Enable the GPIO PORTF that is used for the on-board LEDs and switches
    SYSCTL_RCGC2_R = SYSCTL_RCGC2_GPIOF;

    // do a dummy read to insert a few cycles after enabling the peripheral
    int dummy = 0;
    dummy += 1;
    dummy = SYSCTL_RCGC2_R;
};

void StartSetup(void)
/*****************************************************************************
*   Input    :
*   Output   :
*   Function : the start setup of registers etc
******************************************************************************/
{
    DummyRead();

    // PORTF FORMAT: 000 SW1 LED1 LED2 LED3 SW2

    // enable pins - Disable-Enable Register (PortF)
    GPIO_PORTF_DEN_R = 0x1F; // 0001 1111

    // Enable Internal Pullups - Pull Up Resistor (PORTF)
    // pullups for buttons etc
    GPIO_PORTF_PUR_R = 0x11; // 0001 0001

    // Set DIRection pins Register (PORTF)
    // 1 meaning output 0 meaning input
    GPIO_PORTF_DIR_R = 0x0E; // 0000 1110
}


int main(void)
/*****************************************************************************
*   Input    :
*   Output   :
*   Function :
******************************************************************************/
{
    StartSetup();

    serialcommunication_standardinitialize();
    serialcom_printchar('r');
    serialcom_printnl();

    INT8U a = 0x2;
    spi_init(a);

    serialcom_printchar('s');
    serialcom_printnl();


    return 0;
}

/****************************** End Of Module *******************************/


/* Change Log:
*****************************************************************************
* Date    Id    Change
* DDMMYY
* --------------------
* XXYYZZ  TH    Module created.
*/










