/**************************************************************************************
 *  [File Name]	 : DAC_program.c
 *	[Version]	 : V01
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

#include "DAC_interface.h"
#include "DAC_private.h"
#include "DAC_config.h"

volatile const u8  *Global_u8SongPtr = 0;
volatile u32 Global_u32SongCounter = 0;
volatile u32 Global_u32SongLen = 0;

void HDAC_voidInit(void)
{
	MRCC_voidEnableClock(MRCC_APB2, HDAC_PORT_NAME);

	MGPIO_voidSetHalfPortMode(HDAC_PORT_NAME, HDAC_HALF_PORT_NAME, MGPIO_OUTPUT_PP_2MHZ);
}

void HDAC_voidPlay(void)
{
#if HDAC_HALF_PORT_NAME == MGPIO_HIGH_HALF_PORT
	MGPIO_voidSetNumOfPinsValue(HDAC_PORT_NAME, MGPIO_PIN8, PINS_8, Global_u8SongPtr[Global_u32SongCounter]);
#elif HDAC_HALF_PORT_NAME == MGPIO_LOW_HALF_PORT
	MGPIO_voidSetNumOfPinsValue(HDAC_PORT_NAME, MGPIO_PIN0, PINS_8, Global_u8SongPtr[Global_u32SongCounter]);
#endif

	Global_u32SongCounter++;
	if(Global_u32SongCounter == Global_u32SongLen)
	{
		Global_u32SongCounter = 0;
	}
}

void HDAC_voidSetSong(const u8 *Copy_u8Arr, u32 Copy_u32SongLen)
{
	Global_u8SongPtr = Copy_u8Arr;
	Global_u32SongLen = Copy_u32SongLen;
}
