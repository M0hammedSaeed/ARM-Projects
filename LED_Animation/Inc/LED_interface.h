/**************************************************************************************
 *  [File Name]	 : LED_interface.h
 *	[Version]	 : V01
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

typedef struct {
	u8 LED_PORT;
	u8 LED_PIN;
}HLED_t;


/*
 * HLED_voidInit --> initialize the led
 * i/p : struct have the port and the pin
 */
void HLED_voidInit(HLED_t* LedObj);

/*
 * HLED_voidTurnOn --> Set led state on
 * i/p : struct have the port and the pin
 */
void HLED_voidTurnOn(HLED_t* LedObj);

/*
 * HLED_voidTurnOff --> Set led state off
 * i/p : struct have the port and the pin
 */
void HLED_voidTurnOff(HLED_t* LedObj);

/*
 * HLED_voidToggle --> toggle led state
 * i/p : struct have the port and the pin
 */
void HLED_voidToggle(HLED_t* LedObj);

#endif /* LED_INTERFACE_H_ */
