/**************************************************************************************
 *  [File Name]	 : LED_program.c
 *	[Version]	 : V01
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"


#if   HLED_OPERATION == ACTIVE_HIGH
	#define HLED_SET_ON  1
	#define HLED_SET_OFF 0
#elif HLED_OPERATION == ACTIVE_LOW
	#define HLED_SET_ON  0
	#define HLED_SET_OFF 1
#endif


void HLED_voidInit(HLED_t* LedObj)
{
	/*  RCC enable clock for port  */
	MRCC_voidEnableClock(MRCC_APB2, LedObj->LED_PORT);
	/* Setting pin as output */
	MGPIO_voidSetPinMode(LedObj->LED_PORT, LedObj->LED_PIN, MGPIO_OUTPUT_PP_2MHZ);
	/* Initialize the LED off */
	MGPIO_voidSetPinValue(LedObj->LED_PORT, LedObj->LED_PIN, HLED_SET_OFF);
}

void HLED_voidTurnOn(HLED_t* LedObj)
{
	MGPIO_voidSetPinValue(LedObj->LED_PORT, LedObj->LED_PIN, HLED_SET_ON);
}

void HLED_voidTurnOff(HLED_t* LedObj)
{
	MGPIO_voidSetPinValue(LedObj->LED_PORT, LedObj->LED_PIN, HLED_SET_OFF);
}

void HLED_voidToggle(HLED_t* LedObj)
{
	MGPIO_voidTogPinValue(LedObj->LED_PORT, LedObj->LED_PIN);

}
