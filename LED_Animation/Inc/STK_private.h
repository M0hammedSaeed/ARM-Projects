/**************************************************************************************
 *  [File Name]	 : STK_private.h
 *	[Version]	 : V01
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#ifndef STK_PRIVATE_H_
#define STK_PRIVATE_H_

/********************************************************************************
 *                              Register Description
 ********************************************************************************/

typedef struct
{
	volatile u32 CTRL  ;
	volatile u32 LOAD  ;
	volatile u32 VAL   ;
	volatile u32 CALIB ;
}MSTK_t;

#define MSTK_BASE_ADDRESS		0xE000E010
#define MSTK					((volatile MSTK_t *)MSTK_BASE_ADDRESS)
	
/********** Bits **********/
#define MSTK_CTRL_ENABLE          	0
#define MSTK_CTRL_TICKINT         	1
#define MSTK_CTRL_CLKSOURCE       	2
#define MSTK_CTRL_COUNTFLAG       	16

/******** Clk options ********/
#define AHB_DEVIDED_BY_8    0
#define AHB_DEVIDED_BY_1    1

/****** interrupt options *******/
#define ENABLE_INTERRUPT	1
#define DISABLE_INTERRUPT	0

#define STK_ENABLE			1
#define STK_DISABLE			0

#define	SINGLE_INTERVAL     0
#define PERIODIC_INTERVAL   1

#endif	/* STK_PRIVATE_H_ */
