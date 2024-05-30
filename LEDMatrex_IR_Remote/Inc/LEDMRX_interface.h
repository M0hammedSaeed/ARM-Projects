/**************************************************************************************
 *  [File Name]	 : LEDMRX_interface.h
 *	[Version]	 : V01
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#ifndef LEDMRX_INTERFACE_H_
#define LEDMRX_INTERFACE_H_

void HLEDMRX_voidInit(void);

void HLEDMRX_voidDisplay(const u8 *Copy_u8Data);

void HLEDMRX_voidDisplayShiftText(const u8 *Copy_u8Data, u8 Copy_u8TextSize);

#endif	/* LEDMRX_INTERFACE_H_ */
