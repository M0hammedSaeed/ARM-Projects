/**************************************************************************************
 *  [File Name]	 : RCC_config.h
 *	[Version]	 : V01
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/*
 *	Options:
 *		MRCC_HSE_CRYSTAL
 *		MRCC_HSE_RC
 * 		MRCC_HSI
 *		MRCC_PLL
 */
#define MRCC_SYS_CLOCK		MRCC_HSE_CRYSTAL

/* Clock Security System: (ENABLE - DISABLE) */
#define MRCC_CLOCK_SECURITY_SYSTEM_ON            DISABLE


/* Note: Select Value only if you have PLL as input System Clock */
#if MRCC_SYS_CLOCK == MRCC_PLL

/*
 *	Options:
 *		MRCC_PLL_HSI_BY2
 *		MRCC_PLL_HSE_BY2
 *		MRCC_PLL_HSE
 */
#define MRCC_PLL_SOURCE		MRCC_PLL_HSE_BY2

/*
 * RCC_PLL_MULTIBLE can be :
 *                1-MRCC_PLL_MULTIPLE_2
 *                2-MRCC_PLL_MULTIPLE_3
 *                3-MRCC_PLL_MULTIPLE_4
 *                4-MRCC_PLL_MULTIPLE_5
 *                5-MRCC_PLL_MULTIPLE_6
 *                6-MRCC_PLL_MULTIPLE_7
 *                7-MRCC_PLL_MULTIPLE_8
 *                8-MRCC_PLL_MULTIPLE_9
 *                9-MRCC_PLL_MULTIPLE_10
 *               10-MRCC_PLL_MULTIPLE_11
 *               11-MRCC_PLL_MULTIPLE_12
 *               12-MRCC_PLL_MULTIPLE_13
 *               13-MRCC_PLL_MULTIPLE_14
 *               14-MRCC_PLL_MULTIPLE_15
 *               15-MRCC_PLL_MULTIPLE_16
 */
#define MRCC_PLL_MULTIBLE     MRCC_PLL_MULTIPLE_16

#endif

/*
 * Options :
 *  		NO_CLOCK
 *			HSI_CLOCK
 *			HSE_CLOCK
 *			PLL_CLOCK
 *			SYSTEM_CLOCK
 */
#define MRCC_MCO_PIN       NO_CLOCK

/*
 * Options :
 *			MRCC_PRESCALER_2
 *			MRCC_PRESCALER_4
 *			MRCC_PRESCALER_6
 *			MRCC_PRESCALER_8
 */
#define MRCC_ADC_PRESCALER    MRCC_PRESCALER_2

/*
 * Options :
 *			MRCC_PRESCALER_0
 *			MRCC_PRESCALER_2
 *			MRCC_PRESCALER_4
 *			MRCC_PRESCALER_8
 *			MRCC_PRESCALER_16
 */
#define MRCC_APB2_PRESCALER   MRCC_PRESCALER_0

/*
 * Options :
 *			MRCC_PRESCALER_0
 *			MRCC_PRESCALER_2
 *			MRCC_PRESCALER_4
 *			MRCC_PRESCALER_8
 *			MRCC_PRESCALER_16
 */
/* Note : this bus clock must not exceed 36 MHZ */
#define MRCC_APB1_PRESCALER   MRCC_PRESCALER_0

/*
 * Options :
 *			MRCC_PRESCALER_0
 *			MRCC_PRESCALER_2
 *			MRCC_PRESCALER_4
 *			MRCC_PRESCALER_8
 *			MRCC_PRESCALER_16
 *			MRCC_PRESCALER_64
 *			MRCC_PRESCALER_128
 *			MRCC_PRESCALER_256
 *			MRCC_PRESCALER_512
 */
#define MRCC_AHB_PRESCALER    MRCC_PRESCALER_0

#endif	/* RCC_CONFIG_H_ */
