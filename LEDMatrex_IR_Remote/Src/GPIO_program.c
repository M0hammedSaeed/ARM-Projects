/**************************************************************************************
 *  [File Name]	 : GPIO_program.c
 *	[Version]	 : V01
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void MGPIO_voidSetPinMode(u8 Copy_u8PortId, u8 Copy_u8PinNumber, u8 Copy_u8Mode)
{
	/* Setup the pin Mode as required */
	switch(Copy_u8PortId)
	{
		/* check if the the pin between 0:7 --> CRL or 8:15 --> CRH */
	case MGPIO_PORTA :
		if(Copy_u8PinNumber <=7)
		{
			MGPIOA_CRL_R &= ~(CLEAR_VALUE << (Copy_u8PinNumber * 4)); /* clear the four bits first */
			MGPIOA_CRL_R |=  (Copy_u8Mode << (Copy_u8PinNumber * 4)); /* update with mode value */
		}
		else if(Copy_u8PinNumber <=15)
		{
			Copy_u8PinNumber -= 8;
			MGPIOA_CRH_R &= ~(CLEAR_VALUE << (Copy_u8PinNumber * 4)); /* clear the four bits first */
			MGPIOA_CRH_R |=  (Copy_u8Mode << (Copy_u8PinNumber * 4)); /* update with mode value */
		}
		else{ /* Return Error */ }
	break;
	case MGPIO_PORTB :
		if(Copy_u8PinNumber <=7)
		{
			MGPIOB_CRL_R &= ~(CLEAR_VALUE << (Copy_u8PinNumber * 4)); /* clear the four bits first */
			MGPIOB_CRL_R |=  (Copy_u8Mode << (Copy_u8PinNumber * 4)); /* update with mode value */
		}
		else if(Copy_u8PinNumber <=15)
		{
			Copy_u8PinNumber -= 8;
			MGPIOB_CRH_R &= ~(CLEAR_VALUE << (Copy_u8PinNumber * 4)); /* clear the four bits first */
			MGPIOB_CRH_R |=  (Copy_u8Mode << (Copy_u8PinNumber * 4)); /* update with mode value */
		}
		else{ /* Return Error */ }
	break;
	case MGPIO_PORTC :
		if(Copy_u8PinNumber <=7)
		{
			MGPIOC_CRL_R &= ~(CLEAR_VALUE << (Copy_u8PinNumber * 4)); /* clear the four bits first */
			MGPIOC_CRL_R |=  (Copy_u8Mode << (Copy_u8PinNumber * 4)); /* update with mode value */
		}
		else if(Copy_u8PinNumber <=15)
		{
			Copy_u8PinNumber -= 8;
			MGPIOC_CRH_R &= ~(CLEAR_VALUE << (Copy_u8PinNumber * 4)); /* clear the four bits first */
			MGPIOC_CRH_R |=  (Copy_u8Mode << (Copy_u8PinNumber * 4)); /* update with mode value */
		}
		else{ /* Return Error */ }
	break;
	}
}	

void MGPIO_voidSetPortMode (u8 Copy_u8PortId, u8 Copy_u8Mode)
{
	for (u8 pin = MGPIO_PIN0 ; pin <= MGPIO_PIN15 ; pin++)
	{
		MGPIO_voidSetPinMode(Copy_u8PortId, pin, Copy_u8Mode);
	}
}

void MGPIO_voidSetHalfPortMode(u8 Copy_u8PortId, u8 Copy_u8HalfPortPosition, u8 Copy_u8Mode)
{
    u8 Local_u8Iterator;
    u8 Local_u8StartCounter;
    u8 Local_u8EndCounter;

    if (Copy_u8HalfPortPosition == MGPIO_LOW_HALF_PORT)
    {
        Local_u8StartCounter = 0;
        Local_u8EndCounter   = 7;
    }
    else if (Copy_u8HalfPortPosition == MGPIO_HIGH_HALF_PORT)
    {
        Local_u8StartCounter = 8;
        Local_u8EndCounter   = 15;
    }

    switch (Copy_u8PortId)
    {
	case MGPIO_PORTA:
		for (Local_u8Iterator = Local_u8StartCounter; Local_u8Iterator <= Local_u8EndCounter; Local_u8Iterator++)
		{
			MGPIO_voidSetPinMode(MGPIO_PORTA, Local_u8Iterator, Copy_u8Mode);
		}
	break;
	case MGPIO_PORTB:
		for (Local_u8Iterator = Local_u8StartCounter; Local_u8Iterator <= Local_u8EndCounter; Local_u8Iterator++)
		{
			MGPIO_voidSetPinMode(MGPIO_PORTB, Local_u8Iterator, Copy_u8Mode);
		}
	break;
	case MGPIO_PORTC:
		for (Local_u8Iterator = Local_u8StartCounter; Local_u8Iterator <= Local_u8EndCounter; Local_u8Iterator++)
		{
			MGPIO_voidSetPinMode(MGPIO_PORTC, Local_u8Iterator, Copy_u8Mode);
		}
	break;
    }
}

void MGPIO_voidSetNipplePortMode(u8 Copy_u8PortId, u8 Copy_u8NipplePortPosition, u8 Copy_u8Mode)
{
    u8 Local_u8Iterator;
    u8 Local_u8StartCounter;
    u8 Local_u8EndCounter;

    if (Copy_u8NipplePortPosition == MGPIO_FIRST_NIPPLE_PORT)
    {
        Local_u8StartCounter = 0;
        Local_u8EndCounter   = 3;
    }
    else if (Copy_u8NipplePortPosition == MGPIO_SECOND_NIPPLE_PORT)
    {
        Local_u8StartCounter = 4;
        Local_u8EndCounter   = 7;
    }
    else if (Copy_u8NipplePortPosition == MGPIO_THIRD_NIPPLE_PORT)
    {
        Local_u8StartCounter = 8;
        Local_u8EndCounter   = 11;
    }
    else if (Copy_u8NipplePortPosition == MGPIO_FOURTH_NIPPLE_PORT)
    {
        Local_u8StartCounter = 12;
        Local_u8EndCounter   = 15;
    }

    switch (Copy_u8PortId)
    {
	case MGPIO_PORTA:
		for (Local_u8Iterator = Local_u8StartCounter; Local_u8Iterator <= Local_u8EndCounter; Local_u8Iterator++)
		{
			MGPIO_voidSetPinMode(MGPIO_PORTA, Local_u8Iterator, Copy_u8Mode);
		}
	break;
	case MGPIO_PORTB:
		for (Local_u8Iterator = Local_u8StartCounter; Local_u8Iterator <= Local_u8EndCounter; Local_u8Iterator++)
		{
			MGPIO_voidSetPinMode(MGPIO_PORTB, Local_u8Iterator, Copy_u8Mode);
		}
	break;
	case MGPIO_PORTC:
		for (Local_u8Iterator = Local_u8StartCounter; Local_u8Iterator <= Local_u8EndCounter; Local_u8Iterator++)
		{
			MGPIO_voidSetPinMode(MGPIO_PORTC, Local_u8Iterator, Copy_u8Mode);
		}
	break;
    }
}

void MGPIO_voidSetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinNumber, u8 Copy_u8PinValue)
{
	/* Write the pin value as required */
	switch(Copy_u8PortId)
	{
	case MGPIO_PORTA :
		if(Copy_u8PinValue == MGPIO_HIGH)
		{
			MGPIOA_BSRR_R = (1 << Copy_u8PinNumber);
		}
		else if(Copy_u8PinValue == MGPIO_LOW)
		{
			MGPIOA_BRR_R = (1 << Copy_u8PinNumber);
		}
		else{ /* Return Error */ }
	break;
	case MGPIO_PORTB :
		if(Copy_u8PinValue == MGPIO_HIGH)
		{
			MGPIOB_BSRR_R = (1 << Copy_u8PinNumber);
		}
		else if(Copy_u8PinValue == MGPIO_LOW)
		{
			MGPIOB_BRR_R = (1 << Copy_u8PinNumber);
		}
		else{ /* Return Error */ }
	break;
	case MGPIO_PORTC :
		if(Copy_u8PinValue == MGPIO_HIGH)
		{
			MGPIOC_BSRR_R = (1 << Copy_u8PinNumber);
		}
		else if(Copy_u8PinValue == MGPIO_LOW)
		{
			MGPIOC_BRR_R = (1 << Copy_u8PinNumber);
		}
		else{ /* Return Error */ }
	break;
	}
}

void MGPIO_voidTogPinValue(u8 Copy_u8PortId, u8 Copy_u8PinNumaber)
{
	/* Toggle the pin value */
	switch(Copy_u8PortId)
	{
	case MGPIO_PORTA :
		TOG_BIT(MGPIOA_ODR_R, Copy_u8PinNumaber);
	break;
	case MGPIO_PORTB :
		TOG_BIT(MGPIOB_ODR_R, Copy_u8PinNumaber);
	break;
	case MGPIO_PORTC :
		TOG_BIT(MGPIOC_ODR_R, Copy_u8PinNumaber);
	break;
	}
}

u8 MGPIO_u8GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinNumaber)
{
	u8 Local_u8PinValue = MGPIO_LOW;
	
	/* Git the pin value as required */
	switch(Copy_u8PortId)
	{
	case MGPIO_PORTA :
		Local_u8PinValue = GET_BIT(MGPIOA_IDR_R, Copy_u8PinNumaber);
	break;
	case MGPIO_PORTB :
		Local_u8PinValue = GET_BIT(MGPIOB_IDR_R, Copy_u8PinNumaber);
	break;
	case MGPIO_PORTC :
		Local_u8PinValue = GET_BIT(MGPIOC_IDR_R, Copy_u8PinNumaber);
	break;
	}
	
	return Local_u8PinValue;
}

void MGPIO_voidSetPortValue (u8 Copy_u8PortId, u16 Copy_u16PortValue)
{
	switch (Copy_u8PortId)
	{
	case MGPIO_PORTA :
		MGPIOA_ODR_R = Copy_u16PortValue ;
	break ;
	case MGPIO_PORTB :
		MGPIOB_ODR_R = Copy_u16PortValue ;
	break ;
	case MGPIO_PORTC :
		MGPIOC_ODR_R = Copy_u16PortValue ;
	break ;
	}
}

void MGPIO_voidSetNumOfPinsValue(u8 Copy_u8PortId, u8 Copy_u8StartPinNumber, MGPIO_numberOfPins_t Copy_NumberOfPins, u8 Copy_u8Value)
{
	switch (Copy_u8PortId)
	{
	case MGPIO_PORTA :
		MGPIOA_ODR_R &= ~(Copy_NumberOfPins << Copy_u8StartPinNumber);
		MGPIOA_ODR_R |=  (Copy_u8Value      << Copy_u8StartPinNumber);
	break ;
	case MGPIO_PORTB :
		MGPIOB_ODR_R &= ~(Copy_NumberOfPins << Copy_u8StartPinNumber);
		MGPIOB_ODR_R |=  (Copy_u8Value      << Copy_u8StartPinNumber);
	break ;
	case MGPIO_PORTC :
		MGPIOC_ODR_R &= ~(Copy_NumberOfPins << Copy_u8StartPinNumber);
		MGPIOC_ODR_R |=   (Copy_u8Value << Copy_u8StartPinNumber);
	break ;
	}
}

void MGPIO_voidLockPinConfiguration(u8 Copy_u8PortId, u8 Copy_u8PinNumber)
{
	u32 Local_u32Temp = 0x00010000;
    switch (Copy_u8PortId)
    {
	case MGPIO_PORTA:
		Local_u32Temp |= (1 << Copy_u8PinNumber);
		MGPIOA_LCKR_R = Local_u32Temp;	/* Set LCKK bit */
		MGPIOA_LCKR_R = (1 << Copy_u8PinNumber);	/* Reset LCKK bit */
		MGPIOA_LCKR_R = Local_u32Temp;	/* Set LCKK bit */
		Local_u32Temp = MGPIOA_LCKR_R;	/* Read LCKK bit*/
		Local_u32Temp = MGPIOA_LCKR_R;	/* Read LCKK bit*/
	break;
	case MGPIO_PORTB:
		Local_u32Temp |= (1 << Copy_u8PinNumber);
		MGPIOB_LCKR_R = Local_u32Temp;	/* Set LCKK bit */
		MGPIOB_LCKR_R = (1 << Copy_u8PinNumber);	/* Reset LCKK bit */
		MGPIOB_LCKR_R = Local_u32Temp;	/* Set LCKK bit */
		Local_u32Temp = MGPIOB_LCKR_R;	/* Read LCKK bit*/
		Local_u32Temp = MGPIOB_LCKR_R;	/* Read LCKK bit*/
	break;
	case MGPIO_PORTC:
		Local_u32Temp |= (1 << Copy_u8PinNumber);
		MGPIOC_LCKR_R = Local_u32Temp;	/* Set LCKK bit */
		MGPIOC_LCKR_R = (1 << Copy_u8PinNumber);	/* Reset LCKK bit */
		MGPIOC_LCKR_R = Local_u32Temp;	/* Set LCKK bit */
		Local_u32Temp = MGPIOC_LCKR_R;	/* Read LCKK bit*/
		Local_u32Temp = MGPIOC_LCKR_R;	/* Read LCKK bit*/
	break;
    }
}
