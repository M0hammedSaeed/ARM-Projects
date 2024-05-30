/**************************************************************************************
 *  [File Name]	 : SPI_config.h
 *	[Version]	 : V01
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

/*
 *  OPTIONS:
 *  	MSPI_ENABLE
 *  	MSPI_DISABLE
 */
#define MSPI_ENABLE_PERIPHERAL			MSPI_ENABLE

/*
 *  OPTIONS:
 *   	MSPI_FPCLK_DIVIDED_BY_2
 *   	MSPI_FPCLK_DIVIDED_BY_4
 *   	MSPI_FPCLK_DIVIDED_BY_8
 *   	MSPI_FPCLK_DIVIDED_BY_16
 *   	MSPI_FPCLK_DIVIDED_BY_32
 *   	MSPI_FPCLK_DIVIDED_BY_64
 *   	MSPI_FPCLK_DIVIDED_BY_128
 *   	MSPI_FPCLK_DIVIDED_BY_256
 */
#define MSPI_BAUD_RATE                 	MSPI_FPCLK_DIVIDED_BY_2

/*
 *  OPTIONS:
 *  	FIRST_CLOCK_TRANSITION 	--> Read then Write
 *  	SECOND_CLOCK_TRANSITION	--> Write then Read
 */
#define MSPI_CLOCK_PHASE            	SECOND_CLOCK_TRANSITION

/*
 *   OPTIONS:
 *  	CLK_TO_0_AT_IDLE
 *  	CLK_TO_1_AT_IDLE
 */
#define	MSPI_CLOCK_POLARITY           	CLK_TO_1_AT_IDLE

/*
 *   OPTIONS:
 *  	SLAVE_CONFIGURATION
 *  	MASTER_CONFIGURATION
 */
#define MSPI_MASTER_SELECTION          	MASTER_CONFIGURATION

/*
 *   OPTIONS:
 *   	MSB_FIRST
 *   	LSB_FIRST
 */
#define MSPI_FRAME_FORMAT              	MSB_FIRST

/*
 *   OPTIONS:
 *  	SW_SLAVE_DISABLE
 *  	SW_SLAVE_ENABLE
 */
#define MSPI_SOFTWARE_SLAVE            	SW_SLAVE_ENABLE

/*
 *   OPTIONS:
 *  	FRAME_8_BIT
 *  	FRAME_16_BIT
 */
#define MSPI_DATA_FRAME_FORMAT         	FRAME_8_BIT

/*
 *   OPTIONS:
 *  	TXE_DISABLE
 *  	TXE_ENABLE
 */
#define MSPI_TRANSMITTER_INTERRUPT     	TXE_ENABLE

/*
 *   OPTIONS:
 *  	RXE_DISABLE
 *  	RXE_ENABLE
 */
#define MSPI_RECEIVER_INTERRUPT        	RXE_DISABLE

/*
 *   OPTIONS:
 *  	ERROR_DISABLE
 *  	ERROR_ENABLE
 */
#define MSPI_ERROR_INTERRUPT           ERROR_DISABLE

#endif /* SPI_CONFIG_H_ */
