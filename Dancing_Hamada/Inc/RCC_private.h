/**************************************************************************************
 *  [File Name]	 : RCC_private.h
 *	[Version]	 : V01
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

/********************************************************************************
 *                              Register Definitions                                                                   
 ********************************************************************************/

/* base address : 0x4002 1000 */
#define MRCC_CR_REG				*((volatile u32 *)0x40021000)	/* (for clock) choose and enable the clock on the processor */
#define MRCC_CFGR_REG			*((volatile u32 *)0x40021004)	/* (for clock) choose and enable the clock on the processor */
#define MRCC_CIR_REG			*((volatile u32 *)0x40021008)
#define MRCC_APB2RSTR_REG		*((volatile u32 *)0x4002100C)
#define MRCC_APB1RSTR_REG		*((volatile u32 *)0x40021010)
#define MRCC_AHBENR_REG			*((volatile u32 *)0x40021014)	/* (for clock) enable and disable the clock on the different peripherals */
#define MRCC_APB2ENR_REG		*((volatile u32 *)0x40021018)	/* (for clock) enable and disable the clock on the different peripherals */
#define MRCC_APB1ENR_REG		*((volatile u32 *)0x4002101C)	/* (for clock) enable and disable the clock on the different peripherals */
#define MRCC_BDCR_REG			*((volatile u32 *)0x40021020)
#define MRCC_CSR_REG			*((volatile u32 *)0x40021024)


/* MRCC_CR_REG BITS  */
#define MRCC_HSI_ON       0
#define MRCC_HSI_RDY      1
#define MRCC_HSI_TRIM0    3
#define MRCC_HSE_ON       16
#define MRCC_HSE_RDY      17
#define MRCC_HSE_BYP      18
#define MRCC_CSS_ON       19
#define MRCC_PLL_ON       24
#define MRCC_PLL_RDY      25

/* MRCC_CFGR_REG BITS */
#define MRCC_SW0          0
#define MRCC_SW1          1
#define MRCC_HPRE0        4
#define MRCC_HPRE1        5
#define MRCC_HPRE2        6
#define MRCC_HPRE3        7
#define MRCC_PPRE1_0      8
#define MRCC_PPRE1_1      9
#define MRCC_PPRE1_2      10
#define MRCC_PPRE2_0      11
#define MRCC_PPRE2_1      12
#define MRCC_PPRE2_2      13
#define MRCC_ADCPRE0      14
#define MRCC_ADCPRE1      15
#define MRCC_PLL_SRC      16
#define MRCC_PLL_XTPRE    17
#define MRMCC_PLL_MUL0    18
#define MRCC_MCO_0        24
#define MRCC_MCO_1        25
#define MRCC_MCO_2        26


/* Clock system options  */
#define MRCC_HSE_CRYSTAL		0
#define MRCC_HSE_RC				1
#define MRCC_HSI				2
#define MRCC_PLL				3

/* PLL options */
#define MRCC_PLL_HSI_BY2		0
#define MRCC_PLL_HSE_BY2		1
#define MRCC_PLL_HSE			2

/*  MCO pin options   */
#define NO_CLOCK     			0
#define HSI_CLOCK     			1
#define HSE_CLOCK     			2
#define PLL_CLOCK     			3
#define SYSTEM_CLOCK  			4

/* Prescaler options for buses*/
#define MRCC_PRESCALER_0 	 	0
#define MRCC_PRESCALER_2     	2
#define MRCC_PRESCALER_4     	3
#define MRCC_PRESCALER_8     	4
#define MRCC_PRESCALER_16    	5
#define MRCC_PRESCALER_64    	6
#define MRCC_PRESCALER_128   	7
#define MRCC_PRESCALER_256   	8
#define MRCC_PRESCALER_512   	9

/* PLL Multiplication factor */
#define MRCC_PLL_MULTIPLE_2   1
#define MRCC_PLL_MULTIPLE_3   2
#define MRCC_PLL_MULTIPLE_4   3
#define MRCC_PLL_MULTIPLE_5   4
#define MRCC_PLL_MULTIPLE_6   5
#define MRCC_PLL_MULTIPLE_7   6
#define MRCC_PLL_MULTIPLE_8   7
#define MRCC_PLL_MULTIPLE_9   8
#define MRCC_PLL_MULTIPLE_10  9
#define MRCC_PLL_MULTIPLE_11  10
#define MRCC_PLL_MULTIPLE_12  11
#define MRCC_PLL_MULTIPLE_13  12
#define MRCC_PLL_MULTIPLE_14  13
#define MRCC_PLL_MULTIPLE_15  14
#define MRCC_PLL_MULTIPLE_16  15

#endif	/* RCC_PRIVATE_H_ */
