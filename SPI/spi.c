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
#include <stdint.h>
#include <emp_type.h>
#include<glob_def.h>
#include <spi.h>
#include <tm4c123gh6pm.h>
/*****************************    Defines    *******************************/

/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/

/*****************************   Functions   *******************************/

void spi_init(INT8U clkprescale)
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : initialization of spi communication
******************************************************************************/
{
    //enable ssi on portd (R3)
    SYSCTL_RCGCSSI_R |= SYSCTL_RCGCSSI_R3;

    //enable clock on portd (R3)
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R3;


    //setup for ssi on gpio-portd
    GPIO_PORTD_AFSEL_R  |= (0x1 << 2) | (0x1 << 3) | (0x1 << 4) | (0x1 << 5);

    GPIO_PORTD_PCTL_R   |= (0x2 << 8) | (0x2 << 12) | (0x2 << 16) | (0x2 << 20);

    GPIO_PORTD_DEN_R    |= (0x1 << 2) | (0x1 << 3) | (0x1 << 4) | (0x1 << 5);

    // Ensuring the SSE bit in the SSICR1 register is clear
    SSI3_CR1_R &= ~(0x1 << 1);

    //Select ssi to master
    SSI3_CR1_R = 0x00000000;

    // configure ssi clock source to system clock
    SSI3_CC_R |= 0x0;

    // configure ssi clock prescaler
    SSI3_CPSR_R = clkprescale;

    // SSICR0 register configuration
    SSI3_CR0_R |= (0 << 8) | (0 << 7) | (0 << 6) | (0 << 5) | (0xF << 0);

    // Ensuring the SSE bit in the SSICR1 register is set
    SSI3_CR1_R |= (0x1 << 1);
}



void spi_transmit(INT16U dataframe)
/*****************************************************************************
*   Input    : the specified dataframe that has to be sent using the spi communication.
*   Output   : -
*   Function : the spi function that takes care of sending to slave
******************************************************************************/
{
    SSI3_DR_R  = dataframe;
}


INT16U spi_receive(void)
/*****************************************************************************
*   Input    : -
*   Output   : the received dataframe from slave
*   Function : the spi function that takes care of receiving from slave
******************************************************************************/
{
    INT16U regdata = SSI3_DR_R;
    return regdata;
}


/****************************** End Of Module *******************************/


/* Change Log:
*****************************************************************************
* Date    Id    Change
* DDMMYY
* --------------------
* 280320  TH/MW     Module created - spi_initialization created
* 020420  TH/MW/CH  spi_recieve/transmit added
*
*/










