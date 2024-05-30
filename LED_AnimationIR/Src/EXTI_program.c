/**************************************************************************************
 *  [File Name]	 : EXTI_program.c
 *	[Version]	 : V01
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"


static void (*pvCallBack[16])(void) = {NULL_PTR};


void MEXTI_voidInit(void)
{
	/* Simple Function for single specific line, Don't use with mixed lines */

#if MEXTI_SENSE_SIGNAL == MEXTI_RISING_EDGE
	CLR_BIT(MEXTI->FTSR, MEXTI_LINE); /* clear the bit of the line in the FTSR Register */
	SET_BIT(MEXTI->RTSR, MEXTI_LINE); /* Set the bit of the line in the RTSR Register */
#elif MEXTI_SENSE_SIGNAL == MEXTI_FALLING_EDGE
	SET_BIT(MEXTI->FTSR, MEXTI_LINE); /* Set the bit of the line in the FTSR Register */
	CLR_BIT(MEXTI->RTSR, MEXTI_LINE); /* clear the bit of the line in the RTSR Register */
#elif MEXTI_SENSE_SIGNAL == MEXTI_ON_CHANGE
	SET_BIT(MEXTI->RTSR, MEXTI_LINE); /* Set the bit of the line in the RTSR Register */
	SET_BIT(MEXTI->FTSR, MEXTI_LINE); /* Set the bit of the line in the FTSR Register */
#else
	#error "EXTI MEXTI_SENSE_SIGNAL, Configuration Error"
#endif

	SET_BIT(MEXTI->IMR, MEXTI_LINE);
}

void MEXTI_voidEnableInterrupt(u8 Copy_u8EXTILine)
{
	if (Copy_u8EXTILine > 15)
	{
		return;
	}
	/* Enable interrupt on line */
	SET_BIT(MEXTI->IMR, Copy_u8EXTILine);
}

void MEXTI_voidDisableInterrupt(u8 Copy_u8EXTILine)
{
	if (Copy_u8EXTILine > 15)
	{
		return;
	}
	/* Disable interrupt on line */
	CLR_BIT(MEXTI->IMR, Copy_u8EXTILine);
}

void MEXTI_voidEnableEvent(u8 Copy_u8EXTILine)
{
	if (Copy_u8EXTILine > 15)
	{
		return;
	}
	SET_BIT(MEXTI->EMR, Copy_u8EXTILine);
}

void MEXTI_voidDisableEvent(u8 Copy_u8EXTILine)
{
	if (Copy_u8EXTILine > 15)
	{
		return;
	}
	CLR_BIT(MEXTI->EMR, Copy_u8EXTILine);
}

/* Function to set the software interrupt trigger */
void MEXTI_voidSoftwareTrigger(u8 Copy_u8EXTILine)
{
	if (Copy_u8EXTILine > 15)
	{
		return;
	}
	/* Setting the line in the SWIER Register to enable the
	 * event and it clears itself after occurrence of the event */
	SET_BIT(MEXTI->SWIER, Copy_u8EXTILine);
}

void MEXTI_voidSetSignalLatch(u8 Copy_u8EXTILine, u8 Copy_u8SenseSignal)
{
	switch(Copy_u8SenseSignal)
	{
	case MEXTI_RISING_EDGE:	/* If it Rising Edge */
		CLR_BIT(MEXTI->FTSR, Copy_u8EXTILine); /* clear the bit of the line in the FTSR Register */
		SET_BIT(MEXTI->RTSR, Copy_u8EXTILine); /* Set the bit of the line in the RTSR Register */
	break;
	case MEXTI_FALLING_EDGE:	/* If it Falling Edge */
		CLR_BIT(MEXTI->RTSR, Copy_u8EXTILine); /* clear the bit of the line in the RTSR Register */
		SET_BIT(MEXTI->FTSR, Copy_u8EXTILine); /* Set the bit of the line in the FTSR Register */
	break;
	case MEXTI_ON_CHANGE:	/* If it On Change */
		SET_BIT(MEXTI->RTSR, Copy_u8EXTILine); /* Set the bit of the line in the RTSR Register */
		SET_BIT(MEXTI->FTSR, Copy_u8EXTILine); /* Set the bit of the line in the FTSR Register */
	break;
	}
}

void MEXTI_voidSetCallBack(u8 Copy_u8EXTILine, void (*pvNotificationFunction)(void))
{
	pvCallBack[Copy_u8EXTILine] = pvNotificationFunction;
}


/************* EXTI0 ISR ******************/
void EXTI0_IRQHandler(void)
{
	if (pvCallBack[MEXTI_LINE0] != NULL_PTR)
	{
		pvCallBack[MEXTI_LINE0]();
	}

	/* Clear pending Bit */
	SET_BIT(MEXTI->PR, MEXTI_LINE0);
}

/************* EXTI1 ISR ******************/
void EXTI1_IRQHandler(void)
{
	if (pvCallBack[MEXTI_LINE1] != NULL_PTR)
	{
		pvCallBack[MEXTI_LINE1]();
	}

	/* Clear pending Bit */
	SET_BIT(MEXTI->PR, MEXTI_LINE1);
}

/************* EXTI2 ISR ******************/
void EXTI2_IRQHandeler(void)
{
	if (pvCallBack[MEXTI_LINE2] != NULL_PTR)
	{
		pvCallBack[MEXTI_LINE2]();
	}

	/* Clear pending Bit */
	SET_BIT(MEXTI->PR, MEXTI_LINE2);
}

/************* EXTI3 ISR ******************/
void EXTI3_IRQHandler(void)
{
	if (pvCallBack[MEXTI_LINE3] != NULL_PTR)
	{
		pvCallBack[MEXTI_LINE3]();
	}

	/* Clear pending Bit */
	SET_BIT(MEXTI->PR, MEXTI_LINE3);
}

/************* EXTI4 ISR ******************/
void EXTI4_IRQHandler(void)
{
	if (pvCallBack[MEXTI_LINE4] != NULL_PTR)
	{
		pvCallBack[MEXTI_LINE4]();
	}

	/* Clear pending Bit */
	SET_BIT(MEXTI->PR, MEXTI_LINE4);
}

/************* EXTI9_5 ISR ******************/
void EXTI9_5_IRQHandler(void)
{
    u8 Local_u8PendingResult5;
    Local_u8PendingResult5 = GET_BIT(MEXTI->PR, MEXTI_LINE5);

    if (Local_u8PendingResult5 == HIGH)
    {
        if (pvCallBack[MEXTI_LINE5] != NULL_PTR)
        {
            pvCallBack[MEXTI_LINE5]();
        }
        SET_BIT(MEXTI->PR, MEXTI_LINE5);
    }

    u8 Local_u8PendingResult6;
    Local_u8PendingResult6 = GET_BIT(MEXTI->PR, MEXTI_LINE6);

    if (Local_u8PendingResult6 == HIGH)
    {
        if (pvCallBack[MEXTI_LINE6] != NULL_PTR)
        {
            pvCallBack[MEXTI_LINE6]();
        }
        SET_BIT(MEXTI->PR, MEXTI_LINE6);
    }

    u8 Local_u8PendingResult7;
    Local_u8PendingResult7 = GET_BIT(MEXTI->PR, MEXTI_LINE7);

    if (Local_u8PendingResult7 == HIGH)
    {
        if (pvCallBack[MEXTI_LINE7] != NULL_PTR)
        {
            pvCallBack[MEXTI_LINE7]();
        }
        SET_BIT(MEXTI->PR, MEXTI_LINE7);
    }

    u8 Local_u8PendingResult8;
    Local_u8PendingResult8 = GET_BIT(MEXTI->PR, MEXTI_LINE8);

    if (Local_u8PendingResult8 == HIGH)
    {
        if (pvCallBack[MEXTI_LINE8] != NULL_PTR)
        {
            pvCallBack[MEXTI_LINE8]();
        }
        SET_BIT(MEXTI->PR, MEXTI_LINE8);
    }

    u8 Local_u8PendingResult9;
    Local_u8PendingResult9 = GET_BIT(MEXTI->PR, MEXTI_LINE9);

    if (Local_u8PendingResult9 == HIGH)
    {
        if (pvCallBack[MEXTI_LINE9] != NULL_PTR)
        {
            pvCallBack[MEXTI_LINE9]();
        }
        SET_BIT(MEXTI->PR, MEXTI_LINE9);
    }
}

/************* EXTI15_10 ISR ******************/
void EXTI15_10_IRQHandler(void)
{
    u8 Local_u8PendingResult10;
    Local_u8PendingResult10 = GET_BIT(MEXTI->PR, MEXTI_LINE10);

    if (Local_u8PendingResult10 == HIGH)
    {
        if (pvCallBack[MEXTI_LINE10] != NULL_PTR)
        {
            pvCallBack[MEXTI_LINE10]();
        }
        SET_BIT(MEXTI->PR, MEXTI_LINE10);
    }

    u8 Local_u8PendingResult11;
    Local_u8PendingResult11 = GET_BIT(MEXTI->PR, MEXTI_LINE11);

    if (Local_u8PendingResult11 == HIGH)
    {
        if (pvCallBack[MEXTI_LINE11] != NULL_PTR)
        {
            pvCallBack[MEXTI_LINE11]();
        }
        SET_BIT(MEXTI->PR, MEXTI_LINE11);
    }

    u8 Local_u8PendingResult12;
    Local_u8PendingResult12 = GET_BIT(MEXTI->PR, MEXTI_LINE12);

    if (Local_u8PendingResult12 == HIGH)
    {
        if (pvCallBack[MEXTI_LINE12] != NULL_PTR)
        {
            pvCallBack[MEXTI_LINE12]();
        }
        SET_BIT(MEXTI->PR, MEXTI_LINE12);
    }

    u8 Local_u8PendingResult13;
    Local_u8PendingResult13 = GET_BIT(MEXTI->PR, MEXTI_LINE13);

    if (Local_u8PendingResult13 == HIGH)
    {
        if (pvCallBack[MEXTI_LINE13] != NULL_PTR)
        {
            pvCallBack[MEXTI_LINE13]();
        }
        SET_BIT(MEXTI->PR, MEXTI_LINE13);
    }

    u8 Local_u8PendingResult14;
    Local_u8PendingResult14 = GET_BIT(MEXTI->PR, MEXTI_LINE14);

    if (Local_u8PendingResult14 == HIGH)
    {
        if (pvCallBack[MEXTI_LINE14] != NULL_PTR)
        {
            pvCallBack[MEXTI_LINE14]();
        }
        SET_BIT(MEXTI->PR, MEXTI_LINE14);
    }

    u8 Local_u8PendingResult15;
    Local_u8PendingResult15 = GET_BIT(MEXTI->PR, MEXTI_LINE15);

    if (Local_u8PendingResult15 == HIGH)
    {
        if (pvCallBack[MEXTI_LINE14] != NULL_PTR)
        {
            pvCallBack[MEXTI_LINE14]();
        }
        SET_BIT(MEXTI->PR, MEXTI_LINE14);
    }
}
