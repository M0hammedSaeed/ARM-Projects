/**************************************************************************************
 *  [File Name]	 : AFIO_interface.h
 *	[Version]	 : V01
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#ifndef AFIO_INTERFACE_H_
#define AFIO_INTERFACE_H_

/*
 * Defines the line numbers for external interrupts.
 * Note: 
 *      Your options: FROM LINE0 TO LINE15
 */
#define MAFIO_EXTI0				0     /* The line number for interrupt line 0  */
#define MAFIO_EXTI1				1     /* The line number for interrupt line 1  */
#define MAFIO_EXTI2				2     /* The line number for interrupt line 2  */
#define MAFIO_EXTI3				3     /* The line number for interrupt line 3  */
#define MAFIO_EXTI4				4     /* The line number for interrupt line 4  */
#define MAFIO_EXTI5				5     /* The line number for interrupt line 5  */
#define MAFIO_EXTI6				6     /* The line number for interrupt line 6  */
#define MAFIO_EXTI7				7     /* The line number for interrupt line 7  */
#define MAFIO_EXTI8				8     /* The line number for interrupt line 8  */
#define MAFIO_EXTI9				9     /* The line number for interrupt line 9  */
#define MAFIO_EXTI10 			10    /* The line number for interrupt line 10 */
#define MAFIO_EXTI11 			11    /* The line number for interrupt line 11 */
#define MAFIO_EXTI12 			12    /* The line number for interrupt line 12 */
#define MAFIO_EXTI13 			13    /* The line number for interrupt line 13 */
#define MAFIO_EXTI14 			14    /* The line number for interrupt line 14 */
#define MAFIO_EXTI15			15    /* The line number for interrupt line 15 */

/*
 * Defines the binary values for each port to be used with external interrupts.
 *
 * Note:
 *		For EXTI0, the binary value 0000 should be used with Port A pin0,
 *		For EXTI1, the binary value 0001 should be used with Port B pin1, and so on.
 */ 
#define MAFIO_PORTA				0b0000 /* The binary value for Port A pins */
#define MAFIO_PORTB				0b0001 /* The binary value for Port B pins */
#define MAFIO_PORTC				0b0010 /* The binary value for Port C pins */


/*
 * MAFIO_voidSetEXTIPinConfiguration --> Assign the line for specific port
 * i/p : (u8) line number 0:15  / (u8) Port id 0:2
 */
void MAFIO_voidSetEXTIPinConfiguration(u8 Copy_u8Line, u8 Copy_u8PortMap);

#endif	/* AFIO_INTERFACE_H_ */
