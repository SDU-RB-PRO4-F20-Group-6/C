# README


**#GENERAL**

The MCU controls the Pan-Tilt-system, and is the master in the MCU to FPGA SPI communication protocol. 	The MCU is accessed by the  	user through a serial communication tool, fx. PUTTY, which was used 	during development. The project consists of modules implemented in 	a class-like system. In main.c, 	a super-loop is used, which implements the modules. 

**#FILE MANIFEST**

The following are the modules created by the project team. Modules provided by the EMP course teacher 	Oskar Palinko, are not explained in detail here. 

	frameinit.h - Module for building the frames described by the SPI protocol.
	
	serialcommunication.h - Module that works together with the UART module to provide the CLI.

	spi.h - SPI communication protocol. This module is deeply correlated with frameinit.h.

	uart0.h - UART serial communication for the CLI.

**#DEVELOPER INFORMATION**

For further developing the software, or changing the software to meet personal requirements, use the 	following data sheet for configuration 	of SPI and UART communication: tm4c123gh6pm.pdf. The data sheet 	is available online.
