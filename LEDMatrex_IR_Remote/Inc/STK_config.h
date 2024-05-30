/**************************************************************************************
 *  [File Name]	 : STK_config.h
 *	[Version]	 : V01
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#ifndef STK_CONFIG_H_
#define STK_CONFIG_H_

/*
 * OPTIONS:
 *  	AHB_DEVIDED_BY_8
 *  	AHB_DEVIDED_BY_1
 */
#define MSTK_CLOCK_SOURCE        AHB_DEVIDED_BY_8

/*
 * OPTIONS:
 *   	ENABLE_INTERRUPT
 *   	DISABLE_INTERRUPT
 */
#define MSTK_INTERRUPT           ENABLE_INTERRUPT

/*
 * OPTIONS:
 *   	STK_ENABLE
 *   	STK_DISABLE
 */
#define MSTK_ENABLE              STK_ENABLE

#endif	/* STK_CONFIG_H_ */
