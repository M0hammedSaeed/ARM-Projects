/**************************************************************************************
 *  [File Name]	 : main.c
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "OS_interface.h"

#include "LED_interface.h"


void first(void);
void second(void);
void third(void);

HLED_t led1 = {MGPIO_PORTA,MGPIO_PIN9};
HLED_t led2 = {MGPIO_PORTA,MGPIO_PIN10};
HLED_t led3 = {MGPIO_PORTA,MGPIO_PIN11};


int main(void)
{
	MRCC_voidInitSysClock();

	HLED_voidInit(&led1);
	HLED_voidInit(&led2);
	HLED_voidInit(&led3);

	OS_voidCreateTask(0, 0, 100000, first);
	OS_voidCreateTask(1, 0, 200000, second);
	OS_voidCreateTask(2, 0, 300000, third);

	OS_voidStart();

	while(1)
	{
		OS_voidDispatcher();
	}
}

void first(void)
{
	HLED_voidToggle(&led1);
}

void second(void)
{
	HLED_voidToggle(&led2);
}

void third(void)
{
	HLED_voidToggle(&led3);
}
