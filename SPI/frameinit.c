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
#include <emp_type.h>
#include <glob_def.h>
#include <serialcommunication.h>
#include <frameinit.h>





/*****************************    Defines    *******************************/

#define FRAMESIZE 16

// used for frame composition
#define FRAMETYPEOFFSET 15
#define MCSELECTOFFSET 14
#define MDIROFFSET 13
#define PWMOFFSET 4
#define PARITYOFFSET 0
#define PWMRESOLUTION 9

#define DATATYPEOFFSET 14

#define EMPTYFRAME 0
/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/


/*****************************   Functions   *******************************/

void function1(void)
/*****************************************************************************
*   Input    :
*   Output   :
*   Function :
******************************************************************************/
{

}



void senddataframe(BOOLEAN mcselect, BOOLEAN mdir, INT16U PWM)
/*****************************************************************************
*   Input    : the values needed for frame construction
*   Output   : -
*   Function : creates a full frame and transmits
******************************************************************************/
{
    INT16U spiframe = 0x0;

    spiframe |= (0x1 << FRAMETYPEOFFSET);

    if( mcselect != 0 ) { spiframe |= (0x1 << MCSELECTOFFSET); }

    if( mdir != 0 ) { spiframe |= (0x1 << MDIROFFSET); }

    PWM = (PWM >> (FRAMESIZE - PWMRESOLUTION) );

    spiframe |= (PWM << PWMOFFSET);


    if( !evenparity(spiframe) ) { spiframe |= (0x1 << PARITYOFFSET); }

    spi_transmit(spiframe);
}


INT16U requestframe(BOOLEAN motorchoice, BOOLEAN datatype)
/*****************************************************************************
*   Input    : specification of chosen motor [0/1] and the type of data [hallindex/motorposition] = [1/0]
*   Output   : the recieved dataframe after requesting
*   Function : requests different types of frames from the FPGA
******************************************************************************/
{
    INT16U spiframe = 0x0;

    if( motorchoice != 0 ) { spiframe |= (0x1 << MCSELECTOFFSET); }

    if( datatype != 0 ) { spiframe |= (0x1 << DATATYPEOFFSET); }

    if( !evenparity(spiframe) ) { spiframe |= (0x1 << PARITYOFFSET); }

    spi_transmit(spiframe);


    spi_transmit(EMPTYFRAME);

    INT16U receivedframe = spi_receive();


    if ( evenparity(receivedframe) ) { return receivedframe; } else {return 0x0;}
}



BOOLEAN evenparity(INT16U frame)
/*****************************************************************************
*   Input    : the frame without parity
*   Output   : if parity is true or false
*   Function : parity calculator for both checking and creating
******************************************************************************/
{
    // parity calculation and put on bit 3

    INT8U paritycounter = 0x0;

    // parity bit calculation for even parity
    for(int i = 15; i >= 0; i--)
    {
        paritycounter += frame && 0x1;
        frame = (frame >> 0x1);
    }


    if( paritycounter % 2 ) {return 0x0;} else {return 0x1;}
}

/****************************** End Of Module *******************************/


/* Change Log:
*****************************************************************************
* Date    Id    Change
* DDMMYY
* --------------------
* 100420  TH/MW/CH    Module created.
*/










