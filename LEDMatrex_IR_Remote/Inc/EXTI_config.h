/**************************************************************************************
 *  [File Name]	 : EXTI_config.h
 *	[Version]	 : V01
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

/*
 * The external interrupt line number.
 * Note:
 *		Your options: FROM MEXTI_LINE0 TO MEXTI_LINE15
 */
#define MEXTI_LINE   			MEXTI_LINE0	 /* The line number for external interrupts */

/*
 * The mode for external interrupts.
 * Note:
 *		Your options: MEXTI_RISING_EDGE, MEXTI_FALLING_EDGE, MEXTI_ON_CHANGE
 */
#define MEXTI_SENSE_SIGNAL		MEXTI_RISING_EDGE	/* The mode for external interrupts. Can be RISING, FALLING, or ON_CHANGE */

#endif	/* EXTI_CONFIG_H_ */
