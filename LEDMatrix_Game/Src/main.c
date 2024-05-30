/**************************************************************************************
 *  [File Name]	 : main.c
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

#include "LEDMRX_interface.h"
#include "IR_interface.h"

/****** Prototypes ******/
void voidChangeStateOfLEDMatrix(void);
void voidRepeatStateOfLEDMatrix(void);
void voidTakeAction(void);

/***** global variables  ****/
/* the LED matrix frames */
const u8 Global_DataArray[10][8] = { {28, 8, 42, 20, 8, 84, 20, 20 },
									 {28, 8, 42, 20, 8, 20, 100, 68},
									 {28, 8, 42, 20, 8, 84, 36, 68 },
									 {28, 8, 42, 20, 72, 20, 36, 68},
									 {28, 8, 42, 84, 8, 20, 36, 68 },
									 {28, 8, 106, 20, 8, 20, 36, 68},
									 {28, 8, 42, 84, 8, 20, 36, 68 },
									 {28, 8, 42, 20, 72, 20, 36, 68},
									 {28, 8, 42, 20, 8, 84, 36, 68 },
									 {28, 8, 42, 20, 8, 20, 100, 68} };

const u8 Global_ZeroArray[8] = {0};
u8 Global_u8PowerState = 0;
u8 Global_u8PlayState = 0;



int main(void)
{
	MRCC_voidInitSysClock();

	HLEDMRX_voidInit();

	HIR_voidPowerButton(voidChangeStateOfLEDMatrix);
	HIR_voidRptButton(voidRepeatStateOfLEDMatrix);
	HIR_voidInit();

	while(1)
	{
		HIR_voidPlay();
		voidTakeAction();
	}
}

void voidChangeStateOfLEDMatrix(void)
{
	Global_u8PowerState = !(Global_u8PowerState) ;
}

void voidRepeatStateOfLEDMatrix(void)
{
	Global_u8PlayState = 1 ;
}

/* Take action based on the date came from receiver */
void voidTakeAction(void)
{
	if (Global_u8PowerState)
	{
		if (Global_u8PlayState)
		{
			for(u8 i= 0; i < 10; i++)
			{
				u8 delay = 10;
				while(delay--)
				{
					HLEDMRX_voidDisplay(&Global_DataArray[i][0]);
				}
			}
		}
		else
		{
			HLEDMRX_voidDisplay(&Global_DataArray[0][0]);
		}

	}
	else
	{
		HLEDMRX_voidDisplay(Global_ZeroArray);
	}
}
