/**************************************************************************************
 *  [File Name]	 : main.c
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"

#include "TFT_interface.h"

int main(void)
{
	/* Choose Clock System to HSE 8MHz */
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(MRCC_APB2, GPIOA_PERIPHERAL);

	MGPIO_voidSetPinMode(MGPIO_PORTA, MGPIO_PIN5, MGPIO_OUTPUT_AFPP_10MHZ);	/* CLK */
	MGPIO_voidSetPinMode(MGPIO_PORTA, MGPIO_PIN7, MGPIO_OUTPUT_AFPP_10MHZ);	/* MOSI */

	HTFT_voidInit();	/* TFT Initialize */

	HTFT_voidDisplayImage();

	while(1);

	return 0;
}
