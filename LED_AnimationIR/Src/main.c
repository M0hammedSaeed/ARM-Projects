/**************************************************************************************
 *  [File Name]	 : main.c
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"

#include "IR_interface.h"
#include "LED_interface.h"

/* Functions prototypes */
void voidInitializeLeds(void);
void voidStopState(void);
void voidPingPongState(void);
void voidInOutState(void);
void voidFlashingState(void);
void voidTakeAction(void);
void ping_pong(void);
void in_out(void);
void flashing (void);



typedef enum {
	PING_PONG ,
	IN_OUT ,
	FLASHING ,
	STOP
}state_t;

/* Global variables */
state_t state = STOP;

HLED_t led[8] = {{MGPIO_PORTA,MGPIO_PIN1},
				 {MGPIO_PORTA,MGPIO_PIN2},
				 {MGPIO_PORTA,MGPIO_PIN3},
				 {MGPIO_PORTA,MGPIO_PIN4},
				 {MGPIO_PORTA,MGPIO_PIN5},
				 {MGPIO_PORTA,MGPIO_PIN6},
				 {MGPIO_PORTA,MGPIO_PIN7},
				 {MGPIO_PORTA,MGPIO_PIN8}};

int main(void)
{
	/* Initialize the RCC to HSE */
	MRCC_voidInitSysClock();

	voidInitializeLeds();

	HIR_voidPowerButton(voidStopState);
	HIR_voidOneButton(voidPingPongState);
	HIR_voidTwoButton(voidInOutState);
	HIR_voidThreeButton(voidFlashingState);
	HIR_voidInit();
	while(1)
	{
		HIR_voidPlay();
		voidTakeAction();
	}
}

/* initialize the LEDs */
void voidInitializeLeds(void)
{
	for(u8 i = 0 ; i < 8 ; i++)
	{
		HLED_voidInit(&led[i]);
	}
}

void voidStopState(void)
{
	state = STOP;
}

void voidPingPongState(void)
{
	state = PING_PONG;
}

void voidInOutState(void)
{
	state = IN_OUT;
}

void voidFlashingState(void)
{
	state = FLASHING;
}

/* Take action based on the data came from receiver */
void voidTakeAction(void)
{
	switch (state)
	{
	case STOP :
		for(u8 i = 0 ; i < 8 ; i++)
		{
			HLED_voidTurnOff(&led[i]);
		}
	break;
	case PING_PONG :
		ping_pong();
	break ;
	case IN_OUT    :
		in_out();
	break ;
	case FLASHING  :
		flashing();
	break;
	}
}

void ping_pong(void)
{
	for(u8 i = 0 ; i < 8 ; i++)
	{
		HLED_voidTurnOn(&led[i]);
		MSTK_voidSetMilliBusyWait(200);
		HLED_voidTurnOff(&led[i]);
	}

	for(s8 i = 7 ; i >= 0 ; i--)
	{
		HLED_voidTurnOn(&led[i]);
		MSTK_voidSetMilliBusyWait(200);
		HLED_voidTurnOff(&led[i]);
	}
}

void in_out(void)
{
	u8 Local_u8MidleUp = 4;
	u8 Local_u8MidleDown = 3;
	u8 Local_u8Iterator= 0;

	while(Local_u8Iterator < 4)
	{
		HLED_voidTurnOn(&led[Local_u8MidleUp]);
		HLED_voidTurnOn(&led[Local_u8MidleDown]);
		Local_u8MidleUp++;
		Local_u8MidleDown--;
		Local_u8Iterator++;
		MSTK_voidSetMilliBusyWait(200);
	}

	Local_u8MidleUp = 7;
	Local_u8MidleDown = 0;
	Local_u8Iterator = 0;

	while(Local_u8Iterator < 4)
	{
		HLED_voidTurnOff(&led[Local_u8MidleUp]);
		HLED_voidTurnOff(&led[Local_u8MidleDown]);
		Local_u8MidleUp--;
		Local_u8MidleDown++;
		Local_u8Iterator++;
		MSTK_voidSetMilliBusyWait(200);
	}
}

void flashing (void)
{
	u8 Local_u8Iterator= 0;

	while(Local_u8Iterator < 8)
	{
		HLED_voidTurnOn(&led[Local_u8Iterator]);
		Local_u8Iterator++;
	}

	MSTK_voidSetMilliBusyWait(500);
	Local_u8Iterator = 0;

	while(Local_u8Iterator < 8)
	{
		HLED_voidTurnOff(&led[Local_u8Iterator]);
		Local_u8Iterator++;
	}

	MSTK_voidSetMilliBusyWait(500);
}
