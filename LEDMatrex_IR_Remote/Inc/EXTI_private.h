/**************************************************************************************
 *  [File Name]	 : EXTI_private.h
 *	[Version]	 : V01
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define HIGH              1
#define LOW               0

/********************************************************************************
 *                              Register Description
 ********************************************************************************/

/* Struct for the EXTI register mapping */
typedef struct
{
	volatile u32 IMR   ;	/* INTERRUPT MASK REGISTER 			  */
	volatile u32 EMR   ;	/* EVENT MASK REGISTER 				  */
	volatile u32 RTSR  ;	/* RISING TRIGGER SELECTION REGISTER  */
	volatile u32 FTSR  ;	/* FALLING TRIGGER SELECTION REGISTER */
	volatile u32 SWIER ;	/* SOFTWARE INTERRUPT EVENT REGISTER  */
	volatile u32 PR    ;	/* PENDING REGISTER 				  */
}MEXTI_t;

#define MEXTI_BASE_ADDRESS   0x40010400
#define MEXTI	((volatile MEXTI_t *) MEXTI_BASE_ADDRESS)

#endif	/* EXTI_PRIVATE_H_ */
