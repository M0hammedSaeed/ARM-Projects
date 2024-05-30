/**************************************************************************************
 *  [File Name]	 : STK_interface.h
 *	[Version]	 : V01
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#ifndef STK_INTERFACE_H_
#define STK_INTERFACE_H_

#define MSTK_AHB_DEVIDED_BY_8    0
#define MSTK_AHB_DEVIDED_BY_1    1

/* MSTK_voidInit --> initialize the SysTick */
void MSTK_voidInit(void);

/* MSTK_voidInterruptEnable --> Enable the Interrupt */
void MSTK_voidInterruptEnable(void);

/* MSTK_voidInterruptEnable --> Disable the Interrupt */
void MSTK_voidInterruptDisable(void);

/* MSTK_voidEnable --> Enable the SysTick */
void MSTK_voidEnable(void);

/* MSTK_voidDisable --> Disable the SysTick */
void MSTK_voidDisable(void);

/*
 * MSTK_voidClockSource --> Select the CLK Source
 * i/p : (u8) (MSTK_AHB_DEVIDED_BY_8 - MSTK_AHB_DEVIDED_BY_1)
 */
void MSTK_voidClockSource(u8 Copy_u8SelectedClock);

/* MSTK_u32GetElapsedTime --> return elapsed time */
u32 MSTK_u32GetElapsedTime(void);

/* STK_u32GetRemainingTime - > return remaining time */
u32 MSTK_u32GetRemainingTime(void);

/*
 * MSTK_voidSetMicroBusyWait --> hold the processor for amount of time in uSec
 * i/p : (u32) Time
 */
void MSTK_voidSetMicroBusyWait(u32 Copy_u32uTicksWaiting);

/*
 * MSTK_voidSetMilliBusyWait --> hold the processor for amount of time in mSec
 * i/p : (u16) Time
 */
void MSTK_voidSetMilliBusyWait(u16 Copy_u16mTicksWaiting);

/*
 * MSTK_voidSetSecondsBusyWait --> hold the processor for amount of time in Sec
 * i/p : (u8) Time
 */
void MSTK_voidSetSecondsBusyWait(u8 Copy_u8sTicksWaiting);

/* MSTK_voidResetSystick --> Reset The Counter */
void MSTK_voidResetSystick(void);

/*
 * MSTK_voidSetSingleInterval --> pass a one shot function to the SysTick ISR
 * i/p : (u32) Time / void function
 */
void MSTK_voidSetSingleInterval(u32 Copy_u32Ticks, void (*NotificationFunction)(void));

/*
 * MSTK_voidSetPeriodicInterval --> pass a periodic function to the SysTick ISR
 * i/p : (u32) Time / void function
 */
void MSTK_voidSetPeriodicInterval(u32 Copy_u32Ticks, void (*NotificationFunction)(void));

/* MSTK_voidStopInterval --> stop the timer and clear the counter */
void MSTK_voidStopInterval(void);


#endif	/* STK_INTERFACE_H_ */
