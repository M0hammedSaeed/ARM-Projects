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

const u8 Global_DataArray[57] = {0, 0, 0, 0, 0, 0, 0, 0, 254, 4,
				  	  	  	  	 8, 4, 254, 0, 56, 68, 130, 130, 130, 68,
								 56, 0, 254, 16, 16, 16, 254, 0, 248, 36,
								 34, 36, 248, 0, 254, 4, 8, 4, 254, 0,
								 254, 146, 146, 146, 0, 254, 130, 68, 56, 0,
								 0, 0, 0, 0, 0, 0, 0};


const u8 Global_ZeroArray[8] = {0};

u8  Global_PowerFlag = 0 ;

void voidTurnOnLEDMatrix(void)
{
	Global_PowerFlag = 1 ;
}

void voidTurnOffLEDMatrix(void)
{
	Global_PowerFlag = 0 ;
}

void voidTakeAction(void)
{
	if (Global_PowerFlag)
	{
		while(Global_PowerFlag != 0)
		{
			HLEDMRX_voidDisplayShiftText(Global_DataArray, 57);
		}
	}
	else if (!(Global_PowerFlag))
	{
		HLEDMRX_voidDisplay(Global_ZeroArray);
	}
	else{ }
}


int main(void)
{
	MRCC_voidInitSysClock();

	HLEDMRX_voidInit();

	HIR_voidPowerButton(voidTurnOffLEDMatrix);
	HIR_voidPlayButton(voidTurnOnLEDMatrix);
	HIR_voidInit();

	while(1)
	{
		HIR_voidPlay();
		voidTakeAction();
	}
}
