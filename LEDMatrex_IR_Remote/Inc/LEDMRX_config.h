/**************************************************************************************
 *  [File Name]	 : LEDMRX_config.h
 *	[Version]	 : V01
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#ifndef LEDMRX_CONFIG_H_
#define LEDMRX_CONFIG_H_


/* The number of rows and columns in the LED matrix. */
#define HLEDMRX_ROWs_NUM			8
#define HLEDMRX_COLS_NUM			8

#define HLEDMRX_ROW_PORT		MGPIO_PORTA
#define HLEDMRX_COL_PORT		MGPIO_PORTB
/*
 * Defines the pin used for LED matrix row output.
 * These pin definitions are used for writing the output pins for an LED matrix row.
 */
#define HLEDMRX_ROW0_PIN	 HLEDMRX_ROW_PORT, MGPIO_PIN0
#define HLEDMRX_ROW1_PIN     HLEDMRX_ROW_PORT, MGPIO_PIN1
#define HLEDMRX_ROW2_PIN     HLEDMRX_ROW_PORT, MGPIO_PIN2
#define HLEDMRX_ROW3_PIN     HLEDMRX_ROW_PORT, MGPIO_PIN3
#define HLEDMRX_ROW4_PIN     HLEDMRX_ROW_PORT, MGPIO_PIN4
#define HLEDMRX_ROW5_PIN     HLEDMRX_ROW_PORT, MGPIO_PIN5
#define HLEDMRX_ROW6_PIN     HLEDMRX_ROW_PORT, MGPIO_PIN6
#define HLEDMRX_ROW7_PIN     HLEDMRX_ROW_PORT, MGPIO_PIN7

/*
 * Defines the pin used for LED matrix column output.
 * These pin definitions are used for writing the output pins for an LED matrix column.
 */
#define HLEDMRX_COL0_PIN	 HLEDMRX_COL_PORT, MGPIO_PIN0
#define HLEDMRX_COL1_PIN     HLEDMRX_COL_PORT, MGPIO_PIN1
#define HLEDMRX_COL2_PIN     HLEDMRX_COL_PORT, MGPIO_PIN5
#define HLEDMRX_COL3_PIN     HLEDMRX_COL_PORT, MGPIO_PIN6
#define HLEDMRX_COL4_PIN     HLEDMRX_COL_PORT, MGPIO_PIN7
#define HLEDMRX_COL5_PIN     HLEDMRX_COL_PORT, MGPIO_PIN8
#define HLEDMRX_COL6_PIN     HLEDMRX_COL_PORT, MGPIO_PIN9
#define HLEDMRX_COL7_PIN     HLEDMRX_COL_PORT, MGPIO_PIN10

#endif	/* LEDMRX_CONFIG_H_ */
