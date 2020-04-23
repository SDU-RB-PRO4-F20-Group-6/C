#  Serial communication 

# Description

Module used in collaboration with UART, to establish connection between serial communication tool PUTTY, and the MCU. 

# Functions

serialcommunication_standardinitialize - Function initializes UART communication. Baud rate set to 9600.

serialcom_printchar - Function prints a char to PUTTY. 

serialcom_getchar - Function receives a char from PUTTY.

serialcom_printnl - Function prints a new line to PUTTY - used for better readability. 

serialcom_setparameters - This function receives position parameters from PUTTY, and stores them.
