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



/***************************** Include files *******************************/

/*****************************    Defines    *******************************/

/********************** External declaration of Variables ******************/

/*****************************   Constants   *******************************/

/*************************  Function interfaces ****************************/


void spi_transmit(INT16U dataframe);
/*****************************************************************************
*   Input    : the specified dataframe that has to be sent using the spi communication.
*   Output   : -
*   Function : the spi function that takes care of sending to slave
******************************************************************************/


INT16U spi_receive(void);
/*****************************************************************************
*   Input    : -
*   Output   : the received dataframe from slave
*   Function : the spi function that takes care of receiving from slave
******************************************************************************/


void spi_init(INT8U clkprescale);
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : initialization of spi communication
******************************************************************************/



/****************************** End Of Module *******************************/
