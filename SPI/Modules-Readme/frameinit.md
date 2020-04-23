#  Frameinit - Frame initialization

# Description

Module used in collaboration with SPI. This module contains the frames that are a part of the SPI protocol. 

# Functions

Senddataframe - Function creates a dataframe and transmits it to the FPGA using the SPI protocol.

Requestframe - Requests frames from the FPGA. Either hall index or motorposition will be requested.

Evenparity - Function that calculates parity, used for both creating a frame, and checking a received frame for errors.
