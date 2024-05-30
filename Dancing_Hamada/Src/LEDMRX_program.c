/**************************************************************************************
 *  [File Name]	 : LEDMRX_program.c
 *	[Version]	 : V01
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LEDMRX_interface.h"
#include "LEDMRX_config.h"
#include "LEDMRX_private.h"

static u8 rows[HLEDMRX_ROWs_NUM*2] = {HLEDMRX_ROW0_PIN, HLEDMRX_ROW1_PIN, HLEDMRX_ROW2_PIN, HLEDMRX_ROW3_PIN,
									  HLEDMRX_ROW4_PIN, HLEDMRX_ROW5_PIN, HLEDMRX_ROW6_PIN, HLEDMRX_ROW7_PIN};

static u8 cols[HLEDMRX_ROWs_NUM*2] = {HLEDMRX_COL0_PIN, HLEDMRX_COL1_PIN, HLEDMRX_COL2_PIN, HLEDMRX_COL3_PIN,
								      HLEDMRX_COL4_PIN, HLEDMRX_COL5_PIN, HLEDMRX_COL6_PIN, HLEDMRX_COL7_PIN};

void HLEDMRX_voidInit(void)
{
	MRCC_voidEnableClock(MRCC_APB2, HLEDMRX_ROW_PORT);
	MRCC_voidEnableClock(MRCC_APB2, HLEDMRX_COL_PORT);

	MSTK_voidInit();	/* Initialize the SysTick */

	/* Making the pins for rows and columns output */
	for(u8 i = 0; i < HLEDMRX_COLS_NUM; i++)
	{
		MGPIO_voidSetPinMode(rows[i*2],rows[i*2+1], MGPIO_OUTPUT_PP_2MHZ);
		MGPIO_voidSetPinMode(cols[i*2],cols[i*2+1], MGPIO_OUTPUT_PP_2MHZ);
	}
}

void HLEDMRX_voidDisplay(const u8 *Copy_u8Data)
{
	static u8 Local_u8ColIndex = 0;

	HLEDMRX_voidDisableAllCols();
	HLEDMRX_voidSetRowValus(Copy_u8Data[Local_u8ColIndex]);
	/* Enable Column x */
	MGPIO_voidSetPinValue(cols[Local_u8ColIndex*2],cols[Local_u8ColIndex*2+1], MGPIO_LOW);

	Local_u8ColIndex++;
	if(Local_u8ColIndex == 8)
	{
		Local_u8ColIndex = 0;
	}
}

void HLEDMRX_voidDisplayShiftText(const u8 *Copy_u8Data, u8 Copy_u8TextSize)
{
	u16 Local_u16Ticks = (1000000 / (Copy_u8TextSize * 50));
	u8 Local_u8FPS = 0;
	/* // 40 Column needed --> 40x50 = 2000, then FPS for 1 led = 1000/2000 = delay time = 0.5 msec */
	for(u8 i = 0; i < (Copy_u8TextSize - HLEDMRX_COLS_NUM); i++)
	{
		u8 Local_temp_data [8] = {Copy_u8Data[i], Copy_u8Data[i+1], Copy_u8Data[i+2], Copy_u8Data[i+3],
								  Copy_u8Data[i+4], Copy_u8Data[i+5], Copy_u8Data[i+6], Copy_u8Data[i+7]};
		while(Local_u8FPS <= 50)	/* FPS = 50Hz */
		{
			Local_u8FPS++;
			HLEDMRX_voidDisplayAnimation(Local_temp_data, Local_u16Ticks);
		}

		if(Local_u8FPS >= 50)
		{
			Local_u8FPS = 0;
		}
	}
}

/************************* Private functions *************************/

static void HLEDMRX_voidDisableAllCols(void)
{
	u8 Local_u8ColIndex;
	for(Local_u8ColIndex = 0; Local_u8ColIndex < HLEDMRX_COLS_NUM; Local_u8ColIndex++)
	{
		MGPIO_voidSetPinValue(cols[Local_u8ColIndex*2],cols[Local_u8ColIndex*2+1], MGPIO_HIGH);
	}
}

static void HLEDMRX_voidSetRowValus(const u8 Copy_u8Value)
{
	u8 Local_u8BIT;
	u8 Local_u8RowIndex;

	for(Local_u8RowIndex = 0; Local_u8RowIndex < HLEDMRX_ROWs_NUM; Local_u8RowIndex++)
	{
		Local_u8BIT = GET_BIT(Copy_u8Value, Local_u8RowIndex);
		MGPIO_voidSetPinValue(rows[Local_u8RowIndex*2],rows[Local_u8RowIndex*2+1], Local_u8BIT);
	}
}

static void HLEDMRX_voidDisplayAnimation(const u8 *Copy_u8Data, u16 Copy_u32Ticks)
{
	for(u8 i = 0; i < HLEDMRX_COLS_NUM; i++)
	{
		HLEDMRX_voidDisableAllCols();
		HLEDMRX_voidSetRowValus(Copy_u8Data[i]);
		/* Enable Column x */
		MGPIO_voidSetPinValue(cols[i*2],cols[i*2+1], MGPIO_LOW);
		MSTK_voidSetMicroBusyWait(Copy_u32Ticks);
	}
}
