/**************************************************************************************
 *  [File Name]	 : main.c
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

#include "DAC_interface.h"
#include "LEDMRX_interface.h"

#include "OS_interface.h"

#include "song.h"

/* Prototypes */
void voidDance(void);
void voidSetDataDisplay(void);

/* user defined */
typedef enum
{
	RIGHT,
	LEFT
}state_t;

/* Global variables */
const u8 Global_u8Frames[4][8] = {{24, 214, 62, 214, 48, 0, 0, 0},
				   	     	      {0, 176, 86, 62, 86, 152, 0, 0},
								  {0, 0, 24, 214, 62, 214, 48, 0},
								  {0, 0, 0, 176, 86, 62, 86, 152}};

volatile u8 Global_u8Index = 0 ;
volatile state_t Global_state ;

int main(void)
{
	/* Initialize the RCC to HSE 8MHz */
	MRCC_voidInitSysClock();

	/* H.W initialize */
	HLEDMRX_voidInit();
	HDAC_voidInit();
	HDAC_voidSetSong(tabib_raw, 39288);

	/* Initialize the OS */
	OS_voidStart();

	/* Create Tasks */
	OS_voidCreateTask(0, 0  , 125   , HDAC_voidPlay);
	OS_voidCreateTask(1, 250, 2500  , voidSetDataDisplay);
	OS_voidCreateTask(2, 0  , 500000, voidDance);


	while(1)
	{
		OS_voidDispatcher();
	}
}

/* Periodic task to make the dance on led matrix*/
void voidDance(void)
{
	switch (Global_state)
	{
	case RIGHT :
		Global_u8Index++;
		if (Global_u8Index == 3)
		{
			Global_state = LEFT ;
		}
	break;
	case LEFT:
		Global_u8Index--;
		if (Global_u8Index == 0)
		{
			Global_state = RIGHT ;
		}
	break;
	}
}

void voidSetDataDisplay(void)
{
	HLEDMRX_voidDisplay(&Global_u8Frames[Global_u8Index][0]);


}
