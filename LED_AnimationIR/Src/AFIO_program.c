/**************************************************************************************
 *  [File Name]	 : AFIO_program.c
 *	[Version]	 : V01
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"

void MAFIO_voidSetEXTIPinConfiguration(u8 Copy_u8Line, u8 Copy_u8PortMap)
{
	u8 Local_u8RegIndex = Copy_u8Line/4;	/* Calculate register index using integer division */
	Copy_u8Line %= 4;						/* Calculate line number using remainder division */
	
	/* Clear the four bits first */
	MAFIO->EXTICR[Local_u8RegIndex] &= ~((0b1111) << (Copy_u8Line*4));
	/* Write into the four bits */
	MAFIO->EXTICR[Local_u8RegIndex] |= ((Copy_u8PortMap) << (Copy_u8Line*4));
}
