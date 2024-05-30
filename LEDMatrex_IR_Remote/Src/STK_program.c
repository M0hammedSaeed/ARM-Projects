/**************************************************************************************
 *  [File Name]	 : STK_program.c
 *	[Version]	 : V01
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"


static void (*pvCallBack)(void) = NULL_PTR;
static u8 Global_u8IntervalFlag = SINGLE_INTERVAL;


void MSTK_voidInit(void)
{
	/* Select SysTick clock source */
#if MSTK_CLOCK_SOURCE == AHB_DEVIDED_BY_1
	SET_BIT(MSTK->CTRL, MSTK_CTRL_CLKSOURCE);
#elif MSTK_CLOCK_SOURCE == AHB_DEVIDED_BY_8
	CLR_BIT(MSTK->CTRL, MSTK_CTRL_CLKSOURCE);
#else
	#error "STK MSTK_CLOCK_SOURCE, Configuration Error"
#endif

	/* Enable/Disable SysTick Interrupt */
#if MSTK_INTERRUPT == ENABLE_INTERRUPT
	SET_BIT(MSTK->CTRL, MSTK_CTRL_TICKINT);
#elif MSTK_INTERRUPT == DISABLE_INTERRUPT
	CLR_BIT(MSTK->CTRL, MSTK_CTRL_TICKINT);
#else
	#error "STK MSTK_INTERRUPT, Configuration Error"
#endif

	/* Enable/Disable SysTick */
#if MSTK_ENABLE == STK_ENABLE
	SET_BIT(MSTK->CTRL, MSTK_CTRL_ENABLE);
#elif MSTK_ENABLE == STK_DISABLE
	CLR_BIT(MSTK->CTRL, MSTK_CTRL_ENABLE);
#else
	#error "STK MSTK_ENABLE, Configuration Error"
#endif
}

void MSTK_voidInterruptEnable(void)
{
	SET_BIT(MSTK->CTRL, MSTK_CTRL_TICKINT);
}

void MSTK_voidInterruptDisable(void)
{
	CLR_BIT(MSTK->CTRL, MSTK_CTRL_TICKINT);
}

void MSTK_voidEnable(void)
{
    SET_BIT(MSTK->CTRL, MSTK_CTRL_ENABLE);
}

void MSTK_voidDisable(void)
{
    CLR_BIT(MSTK->CTRL, MSTK_CTRL_ENABLE);
}

void MSTK_voidClockSource(u8 Copy_u8SelectedClock)
{
    switch (Copy_u8SelectedClock)
    {
	case MSTK_AHB_DEVIDED_BY_8:
		CLR_BIT(MSTK->CTRL, MSTK_CTRL_CLKSOURCE);
	break;
	case MSTK_AHB_DEVIDED_BY_1:
		SET_BIT(MSTK->CTRL, MSTK_CTRL_CLKSOURCE);
	break;
    }

    SET_BIT(MSTK->CTRL, MSTK_CTRL_ENABLE);
}

u32 MSTK_u32GetElapsedTime(void)
{
	u32 Local_u32ElapsedTime = 0;
	Local_u32ElapsedTime = (MSTK->LOAD) - (MSTK->VAL);
	return Local_u32ElapsedTime;
}

u32 MSTK_u32GetRemainingTime(void)
{
	u32 Local_u32RemainTime = 0;
	Local_u32RemainTime = (MSTK->VAL);
	return Local_u32RemainTime;
}

void MSTK_voidSetMicroBusyWait(u32 Copy_u32uTicksWaiting)
{
    /* Max = 16,777,215 uSec */
    MSTK->LOAD =  Copy_u32uTicksWaiting;	/* Load ticks to load register */

    MSTK_voidEnable();	/* Start Timer */

    while(GET_BIT(MSTK->CTRL, MSTK_CTRL_COUNTFLAG) == 0);	/* Wait till flag is raised */

    MSTK_voidDisable();	/* Stop Timer */
    MSTK_voidResetSystick();
}

void MSTK_voidSetMilliBusyWait(u16 Copy_u16mTicksWaiting)
{
    /* Max = 16,777 mSec */
	MSTK->LOAD =  (Copy_u16mTicksWaiting * 1000);	/* Load ticks to load register */

	MSTK_voidEnable();	/* Start Timer */

    while(GET_BIT(MSTK->CTRL, MSTK_CTRL_COUNTFLAG) == 0);	/* Wait till flag is raised */

    MSTK_voidDisable();	/* Stop Timer */
    MSTK_voidResetSystick();
}

void MSTK_voidSetSecondsBusyWait(u8 Copy_u8sTicksWaiting)
{
    /* Max = 16 s */
	MSTK->LOAD =  (Copy_u8sTicksWaiting * 1000000);	/* Load ticks to load register */

	MSTK_voidEnable();	/* Start Timer */

	while(GET_BIT(MSTK->CTRL, MSTK_CTRL_COUNTFLAG) == 0);	/* Wait till flag is raised */

	MSTK_voidDisable();	/* Stop Timer */
	MSTK_voidResetSystick();
}

void MSTK_voidResetSystick(void)
{
    MSTK->VAL = 0;
}

void MSTK_voidSetSingleInterval(u32 Copy_u32Ticks, void (*NotificationFunction)(void))
{
	/* Disable the Timer, Make it =0 to make sure if the timer was already counting
	 * It returns to count from the start */
	MSTK_voidDisable();
	MSTK_voidResetSystick();

	MSTK->LOAD = Copy_u32Ticks;	/* Load ticks to load register */

	Global_u8IntervalFlag = SINGLE_INTERVAL; /* Set Mode to Single */

	pvCallBack = NotificationFunction; /* Save CallBack */

    MSTK_voidInterruptEnable();	/* Enable STK Interrupt */

    MSTK_voidEnable();	/* Start Timer */
}


void MSTK_voidSetPeriodicInterval(u32 Copy_u32Ticks, void (*NotificationFunction)(void))
{
	MSTK->LOAD = Copy_u32Ticks;	/* Load ticks to load register */

	Global_u8IntervalFlag = PERIODIC_INTERVAL;	/* Set Mode to PERIODIC */

	pvCallBack = NotificationFunction;	/* Save CallBack */

	MSTK_voidInterruptEnable();	/* Enable STK Interrupt */

	MSTK_voidEnable();	/* Start Timer */
}

void MSTK_voidStopInterval(void)
{
	MSTK_voidInterruptDisable();	/* Disable STK Interrupt */

	MSTK_voidDisable();	/* Stop Timer */

	MSTK_voidResetSystick();
}

/************* SysTick ISR ******************/
void SysTick_Handler(void)
{
	u32 Local_u32TempVar;
	/* In case of using single interval */
	if(Global_u8IntervalFlag == SINGLE_INTERVAL)
	{
		CLR_BIT(MSTK->CTRL, MSTK_CTRL_ENABLE);	/* Stop timer */
		MSTK->LOAD = 0;
		MSTK->VAL  = 0;

		CLR_BIT(MSTK->CTRL, MSTK_CTRL_TICKINT);	/* Disable STK Interrupt */
	}

	if(pvCallBack != NULL_PTR)
	{
		pvCallBack();
	}
	/* Clear interrupt flag*/
	Local_u32TempVar = GET_BIT(MSTK->CTRL, MSTK_CTRL_COUNTFLAG);
}
