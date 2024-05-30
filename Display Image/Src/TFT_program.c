/**************************************************************************************
 *  [File Name]	 : TFT_program.c
 *	[Version]	 : V01
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "SPI_interface.h"

#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"

#include "ImageArray.h"

void HTFT_voidInit(void)
{
	MRCC_voidEnableClock(MRCC_APB2, HTFT_A0_PORT);
	MRCC_voidEnableClock(MRCC_APB2, SPI1_PERIPHERAL);

	MGPIO_voidSetPinMode(HTFT_A0_PORT, HTFT_A0_PIN, MGPIO_OUTPUT_PP_2MHZ);
	MGPIO_voidSetPinMode(HTFT_RESET_PORT, HTFT_RESET_PIN, MGPIO_OUTPUT_PP_2MHZ);

	MSTK_voidInit();

	MSPI_voidInit(MSPI_1);

	/* Reset Pulse To Initializing All registers */
	MGPIO_voidSetPinValue(HTFT_RESET_PORT, HTFT_RESET_PIN, MGPIO_HIGH);
	MSTK_voidSetMicroBusyWait(100);
	MGPIO_voidSetPinValue(HTFT_RESET_PORT, HTFT_RESET_PIN, MGPIO_LOW);
	MSTK_voidSetMicroBusyWait(1);
	MGPIO_voidSetPinValue(HTFT_RESET_PORT, HTFT_RESET_PIN, MGPIO_HIGH);
	MSTK_voidSetMicroBusyWait(100);
	MGPIO_voidSetPinValue(HTFT_RESET_PORT, HTFT_RESET_PIN, MGPIO_LOW);
	MSTK_voidSetMicroBusyWait(100);
	MGPIO_voidSetPinValue(HTFT_RESET_PORT, HTFT_RESET_PIN, MGPIO_HIGH);
	MSTK_voidSetMilliBusyWait(120);

	/* Sleep it out and Active 4-Line MCU serial interface mode then display on */
	HTFT_voidSendCommand(SLPOUT);
	MSTK_voidSetMilliBusyWait(150);
	HTFT_voidSendCommand(COLMOD);
	HTFT_voidSendData(COLMOD_RGB565_16BIT);
	HTFT_voidSendCommand(DISPON);
	MSTK_voidSetMilliBusyWait(1);
	HTFT_voidSendCommand(MADCTL);
	HTFT_voidSendData(PWCTR1);
}

static void HTFT_voidSendData(u8 Copy_u8Data)
{
	/* Set A0 HIGH */
	MGPIO_voidSetPinValue(HTFT_A0_PORT, HTFT_A0_PIN, MGPIO_HIGH);
	/* Send Data */
	MSPI_voidSendData(MSPI_1, Copy_u8Data);
}

static void HTFT_voidSendCommand(u8 Copy_u8Command)
{
	/* Set A0 LOW */
	MGPIO_voidSetPinValue(HTFT_A0_PORT, HTFT_A0_PIN, MGPIO_LOW);
	/* Send command */
	MSPI_voidSendData(MSPI_1, Copy_u8Command);
}

void HTFT_voidFillColor(u16 Copy_u16Color)
{
	u8 Local_u8XCounter;
	u8 Local_u8YCounter;

	for( Local_u8YCounter = 0 ; Local_u8YCounter < 160 ; Local_u8YCounter++ )
	{
		HTFT_voidSendCommand(CASET);
		HTFT_voidSendData(ZERO_DATA);
		HTFT_voidSendData(ZERO_DATA);
		HTFT_voidSendCommand(RASET);
		HTFT_voidSendData(ZERO_DATA);
		HTFT_voidSendData(Local_u8YCounter);
		HTFT_voidSendCommand(RAMWR);

		for (Local_u8XCounter = 0; Local_u8XCounter < 128; Local_u8XCounter++)
		{
			HTFT_voidSendData(Copy_u16Color >> 8);
			HTFT_voidSendData(Copy_u16Color & 0xFF);
		}
	}
}

void HTFT_voidSetWindow(u8 Copy_u8X0, u8 Copy_u8X1, u8 Copy_u8Y0, u8 Copy_u8Y1)
{
	/* Set X Address */
    HTFT_voidSendCommand(CASET);
    HTFT_voidSendData(ZERO_DATA);
    HTFT_voidSendData(Copy_u8X0);
    HTFT_voidSendData(ZERO_DATA);
    HTFT_voidSendData(Copy_u8X1);

    /* Set Y Address */
    HTFT_voidSendCommand(RASET);
    HTFT_voidSendData(ZERO_DATA);
    HTFT_voidSendData(Copy_u8Y0);
    HTFT_voidSendData(ZERO_DATA);
    HTFT_voidSendData(Copy_u8Y1);
}

void HTFT_voidDrawPixel(u8 Copy_u8XCoordinate, u8 Copy_u8YCoordinate, u16 Copy_u16Color)
{
	HTFT_voidSetWindow(Copy_u8XCoordinate,Copy_u8XCoordinate , Copy_u8YCoordinate,Copy_u8YCoordinate);
	HTFT_voidSendData(Copy_u16Color>>8);
	HTFT_voidSendData((u8)Copy_u16Color);
}

void HTFT_voidFillRect(u8 Copy_u8X0, u8 Copy_u8X1, u8 Copy_u8Y0, u8 Copy_u8Y1, u16 Copy_u16Color)
{
	u16 Local_u16LoopCounter = 0;
	/*
	 * decrement one from End of location for X & Y
	 * to prevent add one location in both of them
	 * EX: x0 = 0 & x1 = 10
	 * this for user is mean 10 pixel but for controller this 11 pixel
	 * for that I decrement one from End of location to become like this
	 * from 0 to 9 --> 10 location
	 */
	u8 Local_u8Width  = (Copy_u8X1--) - Copy_u8X0;
	u8 Local_u8Height = (Copy_u8Y1--) - Copy_u8Y0;
	u16 Local_u16Area = Local_u8Width  * Local_u8Height;

	HTFT_voidSetWindow(Copy_u8X0, Copy_u8X1, Copy_u8Y0, Copy_u8Y1);
    HTFT_voidSendCommand(RAMWR);

    for(Local_u16LoopCounter = 0; Local_u16LoopCounter < Local_u16Area; Local_u16LoopCounter++)
    {
    	HTFT_voidSendData(Copy_u16Color >> 8);
    	HTFT_voidSendData((u8)Copy_u16Color);
    }
}

void HTFT_voidDrawHorizontalLine(u8 Copy_u8X0, u8 Copy_u8X1, u8 Copy_u8Y, u16 Copy_u16Color)
{
	u8 Local_u8LoopCounter = 0;
	u8 Local_u8Length  = Copy_u8X1 - Copy_u8X0 + 1;

	HTFT_voidSetWindow(Copy_u8X0, Copy_u8X1, Copy_u8Y, Copy_u8Y);
    HTFT_voidSendCommand(RAMWR);

    for(Local_u8LoopCounter = 0; Local_u8LoopCounter < Local_u8Length; Local_u8LoopCounter++)
    {
    	HTFT_voidSendData(Copy_u16Color >> 8);
    	HTFT_voidSendData((u8)Copy_u16Color);
    }
}

void HTFT_voidDrawVerticalLine(u8 Copy_u8X, u8 Copy_u8Y0, u8 Copy_u8Y1, u16 Copy_u16Color)
{
	u32 Local_u32LoopCounter = 0;
	u8 Local_u8Length  = Copy_u8Y1 - Copy_u8Y0 + 1;

	HTFT_voidSetWindow(Copy_u8X, Copy_u8X, Copy_u8Y0, Copy_u8Y1);
    HTFT_voidSendCommand(RAMWR);

    for(Local_u32LoopCounter = 0; Local_u32LoopCounter < Local_u8Length; Local_u32LoopCounter++)
    {
    	HTFT_voidSendData(Copy_u16Color >> 8);
    	HTFT_voidSendData((u8)Copy_u16Color);
    }
}

void HTFT_voidDisplayImage(void)
{
	u16 Local_u16LoopCounter;
	u8 Local_u8Data = 0;

	HTFT_voidSetWindow(HTFT_X0, HTFT_X1, HTFT_Y0, HTFT_Y1);
    HTFT_voidSendCommand(RAMWR);	/* RAM write */

    for(Local_u16LoopCounter=0; Local_u16LoopCounter <= IMAGE_SIZE; Local_u16LoopCounter++)
    {
    	Local_u8Data = Image_Array[Local_u16LoopCounter] >> 8;
    	HTFT_voidSendData(Local_u8Data);	/* Write the High Byte */
    	Local_u8Data = (u8) Image_Array[Local_u16LoopCounter];
    	HTFT_voidSendData(Local_u8Data);	/* Write the Low Byte */
    }
}

void HTFT_voidWriteChar(u8 *Copy_pu8Char, u8 Copy_u8Xaxis, u8 Copy_u8Yaxis, u16 Copy_u16Color)
{
	u8 Local_u8Mask = 0x80;
	u8 Local_u8Iterator1;
	u8 Local_u8Iterator2;
	u8 Local_u8DataMasked;
	u16 Local_u16Pixel;

	for(Local_u8Iterator1 = 0; Local_u8Iterator1 < 5; Local_u8Iterator1++)
	{
		for(Local_u8Iterator2 = 0; Local_u8Iterator2 < 7; Local_u8Iterator2++)
		{
			HTFT_voidSendCommand(CASET);
			HTFT_voidSendData(Copy_u8Xaxis + Local_u8Iterator1);
			HTFT_voidSendData(Copy_u8Xaxis + Local_u8Iterator1);
			HTFT_voidSendCommand(RASET);
			HTFT_voidSendData(Copy_u8Yaxis + Local_u8Iterator2);
			HTFT_voidSendData(Copy_u8Yaxis + Local_u8Iterator2);
			HTFT_voidSendCommand(RAMWR);
			Local_u8DataMasked = Copy_pu8Char[Local_u8Iterator1] & Local_u8Mask;

			if(Local_u8DataMasked == 0)
			{
				Local_u16Pixel = 0x0000;
			}
			else
			{
				Local_u16Pixel = Copy_u16Color;
			}

			HTFT_voidSendData(Local_u16Pixel >> 8);
			HTFT_voidSendData(Local_u16Pixel & 0xFF);
			Local_u8Mask >>= 1;
		}
		Local_u8Mask = 0x80;
	}
}

void HTFT_voidSetColorMode(u8 Copy_u8Mode)
{
	HTFT_voidSendCommand(COLMOD);
	HTFT_voidSendData(Copy_u8Mode);
}

void HTFT_voidSetFeature(u8 Copy_u8Feature)
{
	HTFT_voidSendCommand(MADCTL);
	HTFT_voidSendData(Copy_u8Feature);
}

void HTFT_voidContentHide(void)
{
	HTFT_voidSendCommand(DISPOFF);
}
