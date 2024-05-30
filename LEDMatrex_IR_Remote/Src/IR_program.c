/**************************************************************************************
 *  [File Name]	 : IR_program.c
 *	[Version]	 : V01
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "STK_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "AFIO_interface.h"

#include "IR_Interface.h"
#include "IR_Config.h"
#include "IR_Private.h"


static void (*pvCallBack[21])(void) = {NULL_PTR};

static volatile u8  Global_u8StartEdgeFlag 		= 0;
static volatile u32 Global_u32ReceivedFrame[50] = {0};
static volatile u8  Global_u8EdgeCounter 		= 0;
static volatile u8  Global_u8ButtonData 		= 0;
static volatile u8  Global_u8Iterator 			= 0;


void HIR_voidInit(void)
{
	MRCC_voidEnableClock(MRCC_APB2, HIR_PORT);

	/* SET IR PIN AS INPUT to DETECT FALLING EDGE */
	MGPIO_voidSetPinMode(HIR_PORT, HIR_PIN, MGPIO_INPUT_PU);
	MGPIO_voidSetPinValue(HIR_PORT, HIR_PIN, MGPIO_HIGH);

	/* TURN ON NVIC TO SET PRIORITY AND ENABLE PERIPHERAL */
	/* Enable EXTI from NVIC */
	MNVIC_voidInit();
#if (HIR_PIN >= 0) && (HIR_PIN <= 4)
		MNVIC_voidEnablePeripheralInterrupt(HIR_PIN+6);
		MNVIC_voidSetPeripheralPriority((HIR_PIN+6), 1);
#elif (HIR_PIN >= 5) && (HIR_PIN <= 9)
		MNVIC_voidEnablePeripheralInterrupt(MNVIC_EXTI9_5_IRQ);
		MNVIC_voidSetPeripheralPriority(MNVIC_EXTI9_5_IRQ, 1);
#elif (HIR_PIN >= 10) && (HIR_PIN <= 15)
		MNVIC_voidEnablePeripheralInterrupt(MNVIC_EXTI15_10_IRQ);
		MNVIC_voidSetPeripheralPriority(MNVIC_EXTI15_10_IRQ, 1);
#else
		#error "IR HIR_PIN, Configuration Error"
#endif

	MAFIO_voidSetEXTIPinConfiguration(HIR_PIN, (HIR_PORT-2));

	/* EXTI Initialization */
	MEXTI_voidSetCallBack(HIR_PIN, HIR_voidGetFrame);
	/*INIT LINE FROM (0 :15) , MODE (FALLING OR RISING, ..)*/
	MEXTI_voidEnableInterrupt(HIR_PIN);	/* EXTI0 Enable */
	MEXTI_voidSetSignalLatch(HIR_PIN, MEXTI_FALLING_EDGE); /* Falling Edge */

	/* SysTick Initialize */
	MSTK_voidInit();
}


static void HIR_voidGetFrame(void)
{
	/* First we check the StartFlag was the first or not --> Start bit
	 * If it was the first, START THE TIMER TO CALCULATE IT */
	if(Global_u8StartEdgeFlag == 0)
	{
		/* Stay here while start bit */
		MSTK_voidSetSingleInterval(FRAME_TIME, HIR_voidTakeAction);
		/* Change flag to get in else condition after start bit */
		Global_u8StartEdgeFlag = 1;
	}
	else
	{
		/* Now checking how much time did it count */
		/* for the start bit = 13,500usec */
		Global_u32ReceivedFrame[Global_u8EdgeCounter] = MSTK_u32GetElapsedTime();

		/* Then Reset the timer and go again */
		MSTK_voidResetSystick();
		MSTK_voidSetSingleInterval(FRAME_TIME, HIR_voidTakeAction);

		/* To save in the array's new location by incrementing it */
		Global_u8EdgeCounter++;
	}
}

static void HIR_voidTakeAction(void)
{
	for (Global_u8Iterator = 0; Global_u8Iterator < 8; Global_u8Iterator++)
		{
	        /* Check timing */
			if ((Global_u32ReceivedFrame[(START_EDGE_OF_DATA + Global_u8Iterator)] >= MIN_INTERVAL_TIME) && (Global_u32ReceivedFrame[(START_EDGE_OF_DATA + Global_u8Iterator)] <= MAX_INTERVAL_TIME))
			{
	            /* Timing of logical zero */
				CLR_BIT(Global_u8ButtonData, Global_u8Iterator);
			}
			else
			{
	            /* Timing of logical one */
				SET_BIT(Global_u8ButtonData, Global_u8Iterator);
			}
		}
		Global_u8StartEdgeFlag = 0;
		Global_u8EdgeCounter = 0;
}

void HIR_voidPlay(void)
{
	switch(Global_u8ButtonData)
	{
	case POWER_BUTTON:
        if (pvCallBack[0] != NULL_PTR)
        {
            pvCallBack[0]();
        }
    break;
	case MODE_BUTTON:
        if (pvCallBack[1] != NULL_PTR)
        {
            pvCallBack[1]();
        }
    break;
	case MUTE_BUTTON:
        if (pvCallBack[2] != NULL_PTR)
        {
            pvCallBack[2]();
        }
    break;
	case PLAY_BUTTON:
        if (pvCallBack[3] != NULL_PTR)
        {
            pvCallBack[3]();
        }
    break;
	case LEFT_BUTTON:
        if (pvCallBack[4] != NULL_PTR)
        {
            pvCallBack[4]();
        }
    break;
	case RIGHT_BUTTON:
        if (pvCallBack[5] != NULL_PTR)
        {
            pvCallBack[5]();
        }
    break;
	case EQ_BUTTON:
        if (pvCallBack[6] != NULL_PTR)
        {
            pvCallBack[6]();
        }
    break;
	case VOL_DOWN_BUTTON:
        if (pvCallBack[7] != NULL_PTR)
        {
            pvCallBack[7]();
        }
    break;
	case VOL_UP_BUTTON:
        if (pvCallBack[8] != NULL_PTR)
        {
            pvCallBack[8]();
        }
    break;
	case ZERO_BUTTON:
        if (pvCallBack[9] != NULL_PTR)
        {
            pvCallBack[9]();
        }
    break;
	case RPT_BUTTON:
        if (pvCallBack[10] != NULL_PTR)
        {
            pvCallBack[10]();
        }
    break;
	case USD_BUTTON:
        if (pvCallBack[11] != NULL_PTR)
        {
            pvCallBack[11]();
        }
    break;
	case ONE_BUTTON:
        if (pvCallBack[12] != NULL_PTR)
        {
            pvCallBack[12]();
        }
    break;
	case TWO_BUTTON:
        if (pvCallBack[13] != NULL_PTR)
        {
            pvCallBack[13]();
        }
    break;
	case THREE_BUTTON:
        if (pvCallBack[14] != NULL_PTR)
        {
            pvCallBack[14]();
        }
    break;
	case FOUR_BUTTON:
        if (pvCallBack[15] != NULL_PTR)
        {
            pvCallBack[15]();
        }
    break;
	case FIVE_BUTTON:
        if (pvCallBack[16] != NULL_PTR)
        {
            pvCallBack[16]();
        }
    break;
	case SIX_BUTTON:
        if (pvCallBack[17] != NULL_PTR)
        {
            pvCallBack[17]();
        }
    break;
	case SEVEN_BUTTON:
        if (pvCallBack[18] != NULL_PTR)
        {
            pvCallBack[18]();
        }
    break;
	case EIGHT_BUTTON:
        if (pvCallBack[19] != NULL_PTR)
        {
            pvCallBack[19]();
        }
    break;
	case NINE_BUTTON:
        if (pvCallBack[20] != NULL_PTR)
        {
            pvCallBack[20]();
        }
    break;
	}
}

void HIR_voidPowerButton(void (*pvNotificationFunction)(void))
{
    pvCallBack[0] = pvNotificationFunction;
}

void HIR_voidModeButton(void (*pvNotificationFunction)(void))
{
    pvCallBack[1] = pvNotificationFunction;
}

void HIR_voidMuteButton(void (*pvNotificationFunction)(void))
{
    pvCallBack[2] = pvNotificationFunction;
}

void HIR_voidPlayButton(void (*pvNotificationFunction)(void))
{
    pvCallBack[3] = pvNotificationFunction;
}

void HIR_voidLeftButton(void (*pvNotificationFunction)(void))
{
    pvCallBack[4] = pvNotificationFunction;
}

void HIR_voidRightButton(void (*pvNotificationFunction)(void))
{
    pvCallBack[5] = pvNotificationFunction;
}

void HIR_voidEQButton(void (*pvNotificationFunction)(void))
{
    pvCallBack[6] = pvNotificationFunction;
}

void HIR_voidVolDownButton(void (*pvNotificationFunction)(void))
{
    pvCallBack[7] = pvNotificationFunction;
}

void HIR_voidVolUPButton(void (*pvNotificationFunction)(void))
{
    pvCallBack[8] = pvNotificationFunction;
}

void HIR_voidZeroButton(void (*pvNotificationFunction)(void))
{
    pvCallBack[9] = pvNotificationFunction;
}

void HIR_voidRptButton(void (*pvNotificationFunction)(void))
{
    pvCallBack[10] = pvNotificationFunction;
}

void HIR_voidUsdButton(void (*pvNotificationFunction)(void))
{
    pvCallBack[11] = pvNotificationFunction;
}

void HIR_voidOneButton(void (*pvNotificationFunction)(void))
{
    pvCallBack[12] = pvNotificationFunction;
}

void HIR_voidTwoButton(void (*pvNotificationFunction)(void))
{
    pvCallBack[13] = pvNotificationFunction;
}

void HIR_voidThreeButton(void (*pvNotificationFunction)(void))
{
    pvCallBack[14] = pvNotificationFunction;
}

void HIR_voidFourButton(void (*pvNotificationFunction)(void))
{
    pvCallBack[15] = pvNotificationFunction;
}

void HIR_voidFiveButton(void (*pvNotificationFunction)(void))
{
    pvCallBack[16] = pvNotificationFunction;
}

void HIR_voidSixButton(void (*pvNotificationFunction)(void))
{
    pvCallBack[17] = pvNotificationFunction;
}

void HIR_voidSevenButton(void (*pvNotificationFunction)(void))
{
    pvCallBack[18] = pvNotificationFunction;
}

void HIR_voidEightButton(void (*pvNotificationFunction)(void))
{
    pvCallBack[19] = pvNotificationFunction;
}

void HIR_voidNineButton(void (*pvNotificationFunction)(void))
{
    pvCallBack[20] = pvNotificationFunction;
}
