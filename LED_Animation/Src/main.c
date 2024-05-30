/**************************************************************************************
 *  [File Name]	 : main.c
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/
 
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LED_interface.h"

/* Functions prototypes */
void Led_animation(void);

/* enum to hold the states for the finite state machine */
typedef enum {
	LED_LEFT  ,
	LED_RIGHT ,
	LED_IN    ,
	LED_OUT   ,
	LED_BLINK
}led_state_t;

/* Global variables */
led_state_t Global_state = LED_LEFT ;
u8 Global_u8Offset = 0x01 ;
u8 Global_u8Timer = 0 ;
u8 Global_u8Counter = 0 ;
u8 up = 4 ;
u8 down = 3 ;

HLED_t led1 = {MGPIO_PORTA,MGPIO_PIN0};
HLED_t led2 = {MGPIO_PORTA,MGPIO_PIN1};
HLED_t led3 = {MGPIO_PORTA,MGPIO_PIN2};
HLED_t led4 = {MGPIO_PORTA,MGPIO_PIN3};
HLED_t led5 = {MGPIO_PORTA,MGPIO_PIN4};
HLED_t led6 = {MGPIO_PORTA,MGPIO_PIN5};
HLED_t led7 = {MGPIO_PORTA,MGPIO_PIN6};
HLED_t led8 = {MGPIO_PORTA,MGPIO_PIN7};


int main(void)
{
	/* Initialize the RCC to HSE */
	MRCC_voidInitSysClock();

	/* Initialize the LEDs */
	HLED_voidInit(&led1);
	HLED_voidInit(&led2);
	HLED_voidInit(&led3);
	HLED_voidInit(&led4);
	HLED_voidInit(&led5);
	HLED_voidInit(&led6);
	HLED_voidInit(&led7);
	HLED_voidInit(&led8);

	/* Enable SysTick */
	MSTK_voidInit();

	MSTK_voidSetPeriodicInterval(100000, Led_animation);

	while(1)
	{

	}
}

void Led_animation(void)
{
	Global_u8Timer++;

	switch(Global_state)
	{
	case LED_LEFT:
		/* will execute every 200 mSec */
		if(Global_u8Timer == 2)
		{
			Global_u8Timer = 0;
			MGPIO_voidSetNumOfPinsValue(MGPIO_PORTA, MGPIO_PIN0, PINS_8, Global_u8Offset);
			Global_u8Offset <<= 1;
			if(Global_u8Offset == 0x00)
			{
				Global_state = LED_RIGHT;
				Global_u8Offset = 0x80;
			}
		}
	break;
	case LED_RIGHT:
		/* will execute every 200 mSec */
		if(Global_u8Timer == 2)
		{
			Global_u8Timer = 0;
			MGPIO_voidSetNumOfPinsValue(MGPIO_PORTA, MGPIO_PIN0, PINS_8, Global_u8Offset);
			Global_u8Offset >>= 1;
			if(Global_u8Offset == 0x00)
			{
				Global_state = LED_LEFT;
				Global_u8Offset = 0x01;
				Global_u8Counter++;
			}
			if(Global_u8Counter == 4)
			{
				Global_state = LED_IN;
				Global_u8Counter = 0;
			}
		}
	break;
	case LED_IN:
		/* will execute every 200 mSec */
		if(Global_u8Timer == 2)
		{
			Global_u8Timer = 0;
			MGPIO_voidSetPinValue(MGPIO_PORTA, up, MGPIO_HIGH);
			MGPIO_voidSetPinValue(MGPIO_PORTA, down, MGPIO_HIGH);
			up++;
			down--;
			if(up > 7)
			{
				Global_state = LED_OUT;
				up = 7;
				down = 0;
			}
		}
	break;
	case LED_OUT:
		/* will execute every 200 mSec */
		if(Global_u8Timer == 2)
		{
			Global_u8Timer = 0;
			MGPIO_voidSetPinValue(MGPIO_PORTA, up, MGPIO_LOW);
			MGPIO_voidSetPinValue(MGPIO_PORTA, down, MGPIO_LOW);
			up--;
			down++;
			if(up < 4)
			{
				Global_state = LED_IN;
				Global_u8Counter++;
				up = 4;
				down = 3;
			}
			if(Global_u8Counter == 4)
			{
				Global_state = LED_BLINK;
				Global_u8Counter = 0;
			}
		}
	break;
	case LED_BLINK:
		/* will execute every 500 mSec */
		if(Global_u8Timer == 5)
		{
			Global_u8Timer = 0;
			/* Toggle the 8 pins */
			HLED_voidToggle(&led1);
			HLED_voidToggle(&led2);
			HLED_voidToggle(&led3);
			HLED_voidToggle(&led4);
			HLED_voidToggle(&led5);
			HLED_voidToggle(&led6);
			HLED_voidToggle(&led7);
			HLED_voidToggle(&led8);
			Global_u8Counter++;
			if(Global_u8Counter > 8)
			{
				Global_state = LED_LEFT;
				Global_u8Counter = 0;
				MGPIO_voidSetNumOfPinsValue(MGPIO_PORTA, MGPIO_PIN0, PINS_8, 0x00);
			}
		}
	break;
	}
}
