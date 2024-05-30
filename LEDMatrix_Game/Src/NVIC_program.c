/**************************************************************************************
 *  [File Name]	 : NVIC_program.c
 *	[Version]	 : V01
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void MNVIC_voidInit(void)
{
	/* Set Group and Sub Priorities Distribution */
	SCB_AIRCR = (AIRCR_PRIVKEY | (MNVIC_GROUP_SUB_DISTRIBUTION << GROUPING_BIT));
}

void MNVIC_voidEnablePeripheralInterrupt(MNVIC_IRQn_t Copy_PeripheralID)
{
	/* Divided by 32 to write to the right register index */
	/* Use Modulus with 32 or Anding (Copy_PeripheralID) with 31 so value will always be under 32 */
	u8 Local_u8ISERIndex = Copy_PeripheralID / 32;
	MNVIC->ISER[Local_u8ISERIndex] = (1 << (Copy_PeripheralID % 32));
	/*MNVIC->ISER[Local_u8ISERIndex] = (1 << (Copy_PeripheralID & 31)); */
}

void MNVIC_voidDisablePeripheralInterrupt(MNVIC_IRQn_t Copy_PeripheralID)
{
	u8 Local_u8ICERIndex = Copy_PeripheralID / 32;
	MNVIC->ICER[Local_u8ICERIndex] = (1 << (Copy_PeripheralID % 32));
}

void MNVIC_voidSetPendingFlag(MNVIC_IRQn_t Copy_PeripheralID)
{
	u8 Local_u8ISPRIndex = Copy_PeripheralID / 32;
	MNVIC->ISPR[Local_u8ISPRIndex] = (1 << (Copy_PeripheralID % 32));
}

void MNVIC_voidClearPendingFlag(MNVIC_IRQn_t Copy_PeripheralID)
{
	u8 Local_u8ICPRIndex = Copy_PeripheralID / 32;
	MNVIC->ICPR[Local_u8ICPRIndex] = (1 << (Copy_PeripheralID % 32));
}

u8 MNVIC_u8GetActiveFlag(MNVIC_IRQn_t Copy_PeripheralID)
{
	u8 Local_u8ActiveFlag;
	Local_u8ActiveFlag = GET_BIT(MNVIC->IABR[Copy_PeripheralID / 32], (Copy_PeripheralID % 32));
	return Local_u8ActiveFlag;
}

void MNVIC_voidSetPeripheralPriority(MNVIC_IRQn_t Copy_PeripheralID, u8 Copy_u8Priority)
{
	/* Writing into the four bit the priority */
	MNVIC->IPR[Copy_PeripheralID] = (Copy_u8Priority << 4);
}
