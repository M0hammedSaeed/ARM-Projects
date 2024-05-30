/**************************************************************************************
 *  [File Name]	 : GPIO_interface.h
 *	[Version]	 : V01
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

/*------------------------------------------------------------------------------
 *                                 DEFINITIONS
 *------------------------------------------------------------------------------*/

/* number of pins to write into */
typedef enum
{
	PINS_2 = 0x03,
	PINS_3 = 0x07,
	PINS_4 = 0x0f,
	PINS_5 = 0x1f,
	PINS_6 = 0x3f,
	PINS_7 = 0x7f,
	PINS_8 = 0xff,
}MGPIO_numberOfPins_t;


#define MGPIO_HIGH					1
#define MGPIO_LOW					0


/* GPIO port id */
#define MGPIO_PORTA					2
#define MGPIO_PORTB					3
#define MGPIO_PORTC					4


/* GPIO pins number */
#define MGPIO_PIN0					0
#define MGPIO_PIN1					1
#define MGPIO_PIN2					2
#define MGPIO_PIN3					3
#define MGPIO_PIN4					4
#define MGPIO_PIN5					5
#define MGPIO_PIN6					6
#define MGPIO_PIN7					7
#define MGPIO_PIN8					8
#define MGPIO_PIN9					9
#define MGPIO_PIN10					10
#define MGPIO_PIN11					11
#define MGPIO_PIN12					12
#define MGPIO_PIN13					13
#define MGPIO_PIN14					14
#define MGPIO_PIN15					15


/* PORT Pin CONFIGURATION OPTIONS */
/* Input modes */
#define MGPIO_INPUT_ANALOG			0b0000	/* INPUT ANALOG */
#define MGPIO_INPUT_FLOATING		0b0100  /* INPUT FLOATING */
#define MGPIO_INPUT_PD				0b1000  /* INPUT PULL-DOWN */
#define MGPIO_INPUT_PU				0b1000  /* INPUT PULL-UP */

/* Output modes */
#define MGPIO_OUTPUT_PP_10MHZ 		0b0001  /* OUTPUT PUSH-PULL, MAXIMUM OUTPUT SPEED 10 MHZ */
#define MGPIO_OUTPUT_OD_10MHZ       0b0101  /* OUTPUT OPEN-DRAIN, MAXIMUM OUTPUT SPEED 10 MHZ */
#define MGPIO_OUTPUT_AFPP_10MHZ     0b1001  /* OUTPUT ALTERNATE FUNCTION PUSH PULL, MAXIMUM OUTPUT SPEED 10 MHZ */
#define MGPIO_OUTPUT_AFOD_10MHZ     0b1101  /* OUTPUT ALTERNATE FUNCTION OPEN DRAIN, MAXIMUM OUTPUT SPEED 10 MHZ */
		                                    
#define MGPIO_OUTPUT_PP_2MHZ 		0b0010  /* OUTPUT PUSH-PULL, MAXIMUM OUTPUT SPEED 2 MHZ */
#define MGPIO_OUTPUT_OD_2MHZ	    0b0110  /* OUTPUT OPEN-DRAIN, MAXIMUM OUTPUT SPEED 2 MHZ */
#define MGPIO_OUTPUT_AFPP_2MHZ      0b1010  /* OUTPUT ALTERNATE FUNCTION PUSH PULL, MAXIMUM OUTPUT SPEED 2 MHZ */
#define MGPIO_OUTPUT_AFOD_2MHZ      0b1110  /* OUTPUT ALTERNATE FUNCTION OPEN DRAIN, MAXIMUM OUTPUT SPEED 2 MHZ */
                                            
#define MGPIO_OUTPUT_PP_50MHZ 		0b0011  /* OUTPUT PUSH PULL, MAXIMUM OUTPUT SPEED 50 MHZ */
#define MGPIO_OUTPUT_OD_50MHZ       0b0111  /* OUTPUT OPEN DRAIN, MAXIMUM OUTPUT SPEED 50 MHZ*/
#define MGPIO_OUTPUT_AFPP_50MHZ     0b1011  /* OUTPUT ALTERNATE FUNCTION PUSH PULL, MAXIMUM OUTPUT SPEED 50 MHZ*/
#define MGPIO_OUTPUT_AFOD_50MHZ     0b1111  /* OUTPUT ALTERNATE FUNCTION OPEN DRAIN, MAXIMUM OUTPUT SPEED 50 MHZ */


/* pull types */
#define MGPIO_PULL_UP   			1
#define MGPIO_PULL_DOWN 			0


/* GPIO Half Port Selection */
#define MGPIO_HIGH_HALF_PORT        1
#define MGPIO_LOW_HALF_PORT         0

/* GPIO Nipple Port Selection */
#define MGPIO_FIRST_NIPPLE_PORT		0
#define MGPIO_SECOND_NIPPLE_PORT    1
#define MGPIO_THIRD_NIPPLE_PORT     2
#define MGPIO_FOURTH_NIPPLE_PORT    3


/*
 * MGPIO_voidSetPinMode --> set the mode of the pin
 * i/p : port id (PORTA - PORTB - PORTC) / pin number ( PIN0 --> PIN15) / mode
 */
void MGPIO_voidSetPinMode(u8 Copy_u8PortId, u8 Copy_u8PinNumber, u8 Copy_u8Mode);

/*
 * MGPIO_voidSetPortMode --> set the mode of the port
 * i/p : port id (PORTA - PORTB - PORTC) / mode
 */
void MGPIO_voidSetPortMode (u8 Copy_u8PortId, u8 Copy_u8Mode);

/*
 * MGPIO_voidSetHalfPortMode --> set the mode for half of the port
 * i/p : port id (PORTA - PORTB - PORTC) / half port position ( High - Low)/ mode
 */
void MGPIO_voidSetHalfPortMode(u8 Copy_u8PortId, u8 Copy_u8HalfPortPosition, u8 Copy_u8Mode);

/*
 * MGPIO_voidSetNipplePortMode --> set the mode for Specific Nipple of the port
 * i/p : port id (PORTA - PORTB - PORTC) / nipple port position ( first - second - third - fourth)/ mode
 */
void MGPIO_voidSetNipplePortMode(u8 Copy_u8PortId, u8 Copy_u8NipplePortPosition, u8 Copy_u8Mode);

/*
 * MGPIO_voidSetPinValue --> used to set a specific pin HIGH or LOW or enable PULL UP or DOWN
 * i/p : port id (PORTA - PORTB - PORTC) / pin number ( PIN0 -> PIN15) / value ( HIGH - LOW) (MGPIO_PULL_UP - MGPIO_PULL_DOWN)
 */
void MGPIO_voidSetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinNumber, u8 Copy_u8PinValue);

/*
 * MGPIO_voidTogPinValue --> Toggle the pin value
 * i/p : port id (PORTA - PORTB - PORTC) / pin number ( PIN0 -> PIN15)
 */
void MGPIO_voidTogPinValue(u8 Copy_u8PortId, u8 Copy_u8PinNumaber);

/*
 * MGPIO_u8GetPinValue --> set the pin value 1 or 0
 * i/p : port id (PORTA - PORTB - PORTC) / pin number ( PIN0 -> PIN15)
 * o/p : the pin value (u8)
 */
u8 MGPIO_u8GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinNumaber);

/*
 * MGPIO_voidSetPortValue --> write a value to the whole port
 * i/p : port id (PORTA - PORTB - PORTC) / value (0x0000 - 0xffff)
 */
void MGPIO_voidSetPortValue (u8 Copy_u8PortId, u16 Copy_u16PortValue);

/*
 * MGPIO_voidSetNumOfPinsValue --> write a value to the Specific Number of pins
 * i/p : port id (PORTA - PORTB - PORTC) / start pin number ( PIN0 -> PIN15)/ number of pins to be written /value (0x00 - 0xff)
 */
void MGPIO_voidSetNumOfPinsValue(u8 Copy_u8PortId, u8 Copy_u8StartPinNumber, MGPIO_numberOfPins_t Copy_NumberOfPins, u8 Copy_u8Value);

/*
  * MGPIO_voidLockPinConfiguration --> Lock the pin configuration
  * i/p : port id (PORTA - PORTB - PORTC) / pin number (PIN0 - PIN15)
*/
void MGPIO_voidLockPinConfiguration(u8 Copy_u8PortId, u8 Copy_u8PinNumber);

#endif	/* GPIO_INTERFACE_H_ */
