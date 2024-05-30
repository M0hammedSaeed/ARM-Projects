/**************************************************************************************
 *  [File Name]	 : AFIO_private.h
 *	[Version]	 : V01
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#ifndef AFIO_PRIVATE_H_
#define AFIO_PRIVATE_H_

/********************************************************************************
 *                              Register Description
 ********************************************************************************/

/* AFIO Register Map */
typedef struct
{
	volatile u32 EVCR;		/* EVENT CONTROL REGISTER   				   */
	volatile u32 MAPR;		/* REMAP AND DEBUG I/O CONFIGURATION REGISTER  */
	volatile u32 EXTICR[4];	/* EXTERNAL INTERRUPT CONFIGURATION REGISTERS  */
	volatile u32 MAPR2;		/* REMAP AND DEBUG I/O CONFIGURATION REGISTER2 */
}MAFIO_t;

/* AFIO Register Access */
#define MAFIO 	((volatile MAFIO_t*) 0x40010000)

#endif	/* AFIO_PRIVATE_H_ */
