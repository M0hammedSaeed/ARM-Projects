/**************************************************************************************
 *  [File Name]	 : TFT_config.h
 *	[Version]	 : V01
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#ifndef TFT_CONFIG_H_
#define TFT_CONFIG_H_

/*
 * OPTIONS:
 *   	MGPIO_PORTA
 *   	MGPIO_PORTB
 *   	MGPIO_PORTC
 */
#define HTFT_RESET_PORT         MGPIO_PORTA
#define HTFT_A0_PORT            MGPIO_PORTA

/*
 * OPTIONS:
 *   	MGPIO_PIN0
 *	    MGPIO_PIN1
 *   	MGPIO_PIN2
 * 	    MGPIO_PIN3
 *   	MGPIO_PIN4
 *   	MGPIO_PIN5
 *   	MGPIO_PIN6
 *  	MGPIO_PIN7
 *	    MGPIO_PIN8
 *	    MGPIO_PIN9
 *   	MGPIO_PIN10
 *   	MGPIO_PIN11
 *   	MGPIO_PIN12
 *   	MGPIO_PIN13
 *   	MGPIO_PIN14
 *   	MGPIO_PIN15
 */
#define HTFT_RESET_PIN          MGPIO_PIN1
#define HTFT_A0_PIN             MGPIO_PIN2

#endif /* TFT_CONFIG_H_ */
