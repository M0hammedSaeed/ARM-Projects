/**************************************************************************************
 *  [File Name]	 : EXTI_interface.h
 *	[Version]	 : V01
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/*
 * Defines the line numbers for External Interrupts.
 * Note:
 *		Your options: FROM LINE0 TO LINE15
 */

#define MEXTI_LINE0 				    0 	/* The line number for interrupt line 0  */
#define MEXTI_LINE1 				    1 	/* The line number for interrupt line 1  */
#define MEXTI_LINE2 				    2 	/* The line number for interrupt line 2  */
#define MEXTI_LINE3 				    3 	/* The line number for interrupt line 3  */
#define MEXTI_LINE4 				    4 	/* The line number for interrupt line 4  */
#define MEXTI_LINE5 				    5 	/* The line number for interrupt line 5  */
#define MEXTI_LINE6 				    6 	/* The line number for interrupt line 6  */
#define MEXTI_LINE7 				    7 	/* The line number for interrupt line 7  */
#define MEXTI_LINE8 				    8 	/* The line number for interrupt line 8  */
#define MEXTI_LINE9 				    9 	/* The line number for interrupt line 9  */
#define MEXTI_LINE10 					10	/* The line number for interrupt line 10 */
#define MEXTI_LINE11 					11	/* The line number for interrupt line 11 */
#define MEXTI_LINE12 					12	/* The line number for interrupt line 12 */
#define MEXTI_LINE13 					13	/* The line number for interrupt line 13 */
#define MEXTI_LINE14 					14	/* The line number for interrupt line 14 */
#define MEXTI_LINE15 					15	/* The line number for interrupt line 15 */

/*
 * The mode for external interrupts.
 * Note:
 *	    Your options: RISING, FALLING, ON_CHANGE
 */
#define MEXTI_RISING_EDGE       		0	/* The rising edge mode for external interrupts  */
#define MEXTI_FALLING_EDGE      		1	/* The falling edge mode for external interrupts */
#define MEXTI_ON_CHANGE         		2	/* The on-change mode for external interrupts    */


/* MEXTI_voidInit --> Simple Function for single specific line */
void MEXTI_voidInit(void);

/*
 * MEXTI_voidEnableInterrupt --> Enable a specific external interrupt line
 * i/p : (u8) line number
 */
void MEXTI_voidEnableInterrupt(u8 Copy_u8EXTILine);

/*
 * MEXTI_voidDisableInterrupt --> Disable a specific external interrupt line
 * i/p : (u8) line number
 */
void MEXTI_voidDisableInterrupt(u8 Copy_u8EXTILine);

void MEXTI_voidEnableEvent(u8 Copy_u8EXTILine);

void MEXTI_voidDisableEvent(u8 Copy_u8EXTILine);

/*
  * MEXTI_voidSoftwareTrigger --> Trigger SWI for a given external interrupt line
  * i/p : (u8) line number
*/
void MEXTI_voidSoftwareTrigger(u8 Copy_u8EXTILine);

/*
 * MEXTI_voidSetSignalLatch --> set the Signal
 * i/p : (u8) line number / (u8) the Sense Signal
 */
void MEXTI_voidSetSignalLatch(u8 Copy_u8EXTILine, u8 Copy_u8SenseSignal);

void MEXTI_voidSetCallBack(u8 Copy_u8EXTILine, void (*pvNotificationFunction)(void));

#endif	/* EXTI_INTERFACE_H_ */
