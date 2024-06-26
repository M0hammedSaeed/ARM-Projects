/**************************************************************************************
 *  [File Name]	 : GPIO_private.h
 *	[Version]	 : V01
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

/* I will used it to check validation the number of port passed to function */
#define NUM_OF_PORTS			3
/* I will used it to check validation of number of pin passed to function */
#define NUM_OF_PINS_PER_PORT	16

#define CLEAR_VALUE 			15

/* Base Address */
#define MGPIOA_BASE_ADDRESS		0x40010800
#define MGPIOB_BASE_ADDRESS		0x40010C00
#define MGPIOC_BASE_ADDRESS		0x40011000

/*------------------------------------------------------------------------------
 *                                 Registers Definitions
 *------------------------------------------------------------------------------*/

/* Definition for PORTA Registers */
#define MGPIOA_CRL_R				*((volatile u32 *) (MGPIOA_BASE_ADDRESS+0x00))	/* PORT A CONFIGURATION REGISTER LOW */
#define MGPIOA_CRH_R				*((volatile u32 *) (MGPIOA_BASE_ADDRESS+0x04))	/* PORT A CONFIGURATION REGISTER HIGH */
#define MGPIOA_IDR_R				*((volatile u32 *) (MGPIOA_BASE_ADDRESS+0x08))	/* PORT A INPUT DATA REGISTER */
#define MGPIOA_ODR_R				*((volatile u32 *) (MGPIOA_BASE_ADDRESS+0x0C))	/* PORT A OUTPUT DATA REGISTER */
#define MGPIOA_BSRR_R				*((volatile u32 *) (MGPIOA_BASE_ADDRESS+0x10))	/* PORT A BIT SET/RESET REGISTER */
#define MGPIOA_BRR_R				*((volatile u32 *) (MGPIOA_BASE_ADDRESS+0x14))	/* PORT A BIT RESET REGISTER */
#define MGPIOA_LCKR_R				*((volatile u32 *) (MGPIOA_BASE_ADDRESS+0x18))	/* PORT A CONFIGURATION LOCK REGISTER */

/* Definition for PORTB Registers */
#define MGPIOB_CRL_R				*((volatile u32 *) (MGPIOB_BASE_ADDRESS+0x00))	/* PORT B CONFIGURATION REGISTER LOW */
#define MGPIOB_CRH_R				*((volatile u32 *) (MGPIOB_BASE_ADDRESS+0x04))	/* PORT B CONFIGURATION REGISTER HIGH */
#define MGPIOB_IDR_R				*((volatile u32 *) (MGPIOB_BASE_ADDRESS+0x08))	/* PORT B INPUT DATA REGISTER */
#define MGPIOB_ODR_R				*((volatile u32 *) (MGPIOB_BASE_ADDRESS+0x0C))	/* PORT B OUTPUT DATA REGISTER */
#define MGPIOB_BSRR_R				*((volatile u32 *) (MGPIOB_BASE_ADDRESS+0x10))	/* PORT B BIT SET/RESET REGISTER */
#define MGPIOB_BRR_R				*((volatile u32 *) (MGPIOB_BASE_ADDRESS+0x14))	/* PORT B BIT RESET REGISTER */
#define MGPIOB_LCKR_R				*((volatile u32 *) (MGPIOB_BASE_ADDRESS+0x18))	/* PORT B CONFIGURATION LOCK REGISTER */

/* Definition for PORTC Registers */
#define MGPIOC_CRL_R				*((volatile u32 *) (MGPIOC_BASE_ADDRESS+0x00))	/* PORT C CONFIGURATION REGISTER LOW */
#define MGPIOC_CRH_R				*((volatile u32 *) (MGPIOC_BASE_ADDRESS+0x04))	/* PORT C CONFIGURATION REGISTER HIGH */
#define MGPIOC_IDR_R				*((volatile u32 *) (MGPIOC_BASE_ADDRESS+0x08))	/* PORT C INPUT DATA REGISTER */
#define MGPIOC_ODR_R				*((volatile u32 *) (MGPIOC_BASE_ADDRESS+0x0C))	/* PORT C OUTPUT DATA REGISTER */
#define MGPIOC_BSRR_R				*((volatile u32 *) (MGPIOC_BASE_ADDRESS+0x10))	/* PORT C BIT SET/RESET REGISTER */
#define MGPIOC_BRR_R				*((volatile u32 *) (MGPIOC_BASE_ADDRESS+0x14))	/* PORT C BIT RESET REGISTER */
#define MGPIOC_LCKR_R				*((volatile u32 *) (MGPIOC_BASE_ADDRESS+0x18))	/* PORT C CONFIGURATION LOCK REGISTER */

#endif	/* GPIO_PRIVATE_H_ */
