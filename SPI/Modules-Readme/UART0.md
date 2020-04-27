#  UART

# Description

Module that contains the UART functions and initialization, used by the serial communication module. 

# Functions 

uart0_rx_rdy - True if character is ready at the UART0 RX (Receive).

uart0_getc - Gets a character from UART0 RX (receive).

uart0_tx_rdy - True if the UART0 TX (transmit) buffer is ready.

uart0_putc - Puts character into the TX (transmit) buffer of UART0.

uart0_init - Initializes the UART setup.
