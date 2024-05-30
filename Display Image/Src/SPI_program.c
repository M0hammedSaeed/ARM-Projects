/**************************************************************************************
 *  [File Name]	 : SPI_program.c
 *	[Version]	 : V01
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

/* Global variables */
static void (*MSPI1_CallBack)(void) = NULL_PTR;
static void (*MSPI2_CallBack)(void) = NULL_PTR;


void MSPI_voidInit(u8 Copy_u8SPINumber)
{
	switch(Copy_u8SPINumber)
	{
	case MSPI_1:
		#if MSPI_ENABLE_PERIPHERAL == MSPI_ENABLE

			#if MSPI_MASTER_SELECTION == SLAVE_CONFIGURATION
				CLR_BIT(MSPI1->CR1, CR1_MSTR);
			#elif MSPI_MASTER_SELECTION == MASTER_CONFIGURATION
				SET_BIT(MSPI1->CR1, CR1_MSTR);
			#else
                #error "SPI MSPI_MASTER_SELECTION, Configuration Error"
            #endif

			#if MSPI_CLOCK_PHASE == FIRST_CLOCK_TRANSITION
				CLR_BIT(MSPI1->CR1, CR1_CPHA);
			#elif MSPI_CLOCK_PHASE == SECOND_CLOCK_TRANSITION
				SET_BIT(MSPI1->CR1, CR1_CPHA);
			#else
                #error "SPI MSPI_CLOCK_PHASE, Configuration Error"
            #endif

			#if MSPI_CLOCK_POLARITY == CLK_TO_0_AT_IDLE
				CLR_BIT(MSPI1->CR1, CR1_CPOL);
			#elif MSPI_CLOCK_POLARITY == CLK_TO_1_AT_IDLE
				SET_BIT(MSPI1->CR1, CR1_CPOL);
			#else
                #error "SPI MSPI_CLOCK_POLARITY, Configuration Error"
            #endif

			#if MSPI_FRAME_FORMAT == MSB_FIRST
				CLR_BIT(MSPI1->CR1, CR1_LSBFIRST);
			#elif MSPI_FRAME_FORMAT == LSB_FIRST
				SET_BIT(MSPI1->CR1, CR1_LSBFIRST);
			#else
                #error "SPI MSPI_FRAME_FORMAT, Configuration Error"
            #endif

			#if MSPI_SOFTWARE_SLAVE == SW_SLAVE_DISABLE
				CLR_BIT(MSPI1->CR1, CR1_SSM);
			#elif MSPI_SOFTWARE_SLAVE == SW_SLAVE_ENABLE
				#if MSPI_MASTER_SELECTION == MASTER_CONFIGURATION
					SET_BIT(MSPI1->CR1, CR1_SSM);
					SET_BIT(MSPI1->CR1, CR1_SSI);
				#elif MSPI_MASTER_SELECTION == SLAVE_CONFIGURATION
					SET_BIT(MSPI1->CR1, CR1_SSM);
					CLR_BIT(MSPI1->CR1, CR1_SSI);
				#endif
			#else
                #error "SPI MSPI_SOFTWARE_SLAVE, Configuration Error"
            #endif

			#if MSPI_TRANSMITTER_INTERRUPT == TXE_DISABLE
				CLR_BIT(MSPI1->CR2, CR2_TXEIE);
			#elif MSPI_TRANSMITTER_INTERRUPT == TXE_ENABLE
				SET_BIT(MSPI1->CR2, CR2_TXEIE);
			#else
                #error "SPI MSPI_TRANSMITTER_INTERRUPT, Configuration Error"
            #endif

			#if MSPI_RECEIVER_INTERRUPT == RXE_DISABLE
				CLR_BIT(MSPI1->CR2, CR2_RXNEIE);
			#elif MSPI_RECEIVER_INTERRUPT == RXE_ENABLE
				SET_BIT(MSPI1->CR2, CR2_RXNEIE);
			#else
                #error "SPI MSPI_RECEIVER_INTERRUPT, Configuration Error"
            #endif

			#if MSPI_ERROR_INTERRUPT == ERROR_DISABLE
				CLR_BIT(MSPI1->CR2, CR2_ERRIE);
			#elif MSPI_ERROR_INTERRUPT == ERROR_ENABLE
				SET_BIT(MSPI1->CR2, CR2_ERRIE);
			#else
                #error "SPI MSPI_ERROR_INTERRUPT, Configuration Error"
            #endif

			#if MSPI_DATA_FRAME_FORMAT== FRAME_8_BIT
				CLR_BIT(MSPI1->CR1, CR1_DFF);
			#elif MSPI_DATA_FRAME_FORMAT == FRAME_16_BIT
				SET_BIT(MSPI1->CR1, CR1_DFF);
			#else
                #error "SPI MSPI_DATA_FRAME_FORMAT, Configuration Error"
            #endif

			MSPI1->CR1 &= MSPI_FPCLK_MASK;
			MSPI1->CR1 |= (MSPI_BAUD_RATE << CR1_BR);

			SET_BIT(MSPI1->CR1, CR1_SPE);

		#elif MSPI_ENABLE_PERIPHERAL == MSPI_DISABLE
			CLR_BIT(MSPI1->CR1, CR1_SPE);
		#else
			#error "SPI MSPI_ENABLE_PERIPHERAL, Configuration Error"
		#endif
	break;
	case MSPI_2:
		#if MSPI_ENABLE_PERIPHERAL == MSPI_ENABLE

			#if MSPI_MASTER_SELECTION == SLAVE_CONFIGURATION
				CLR_BIT(MSPI2->CR1, CR1_MSTR);
			#elif MSPI_MASTER_SELECTION == MASTER_CONFIGURATION
				SET_BIT(MSPI2->CR1, CR1_MSTR);
			#else
                #error "SPI MSPI_MASTER_SELECTION, Configuration Error"
            #endif

			#if MSPI_CLOCK_PHASE == FIRST_CLOCK_TRANSITION
				CLR_BIT(MSPI2->CR1, CR1_CPHA);
			#elif MSPI_CLOCK_PHASE == SECOND_CLOCK_TRANSITION
				SET_BIT(MSPI2->CR1, CR1_CPHA);
			#else
                #error "SPI MSPI_ENABLE_PERIPHERAL, Configuration Error"
            #endif

			#if MSPI_CLOCK_POLARITY == CLK_TO_0_AT_IDLE
				CLR_BIT(MSPI2->CR1, CR1_CPOL);
			#elif MSPI_CLOCK_POLARITY == CLK_TO_1_AT_IDLE
				SET_BIT(MSPI2->CR1, CR1_CPOL);
			#else
                #error "SPI MSPI_CLOCK_POLARITY, Configuration Error"
            #endif

			#if MSPI_FRAME_FORMAT == MSB_FIRST
				CLR_BIT(MSPI2->CR1, CR1_LSBFIRST);
			#elif MSPI_FRAME_FORMAT == LSB_FIRST
				SET_BIT(MSPI2->CR1, CR1_LSBFIRST);
			#else
                #error "SPI MSPI_FRAME_FORMAT, Configuration Error"
            #endif

			#if MSPI_SOFTWARE_SLAVE == SW_SLAVE_DISABLE
				CLR_BIT(MSPI2->CR1, CR1_SSM);
			#elif MSPI_SOFTWARE_SLAVE == SW_SLAVE_ENABLE
				SET_BIT(MSPI2->CR1, CR1_SSM);
			#else
                #error "SPI MSPI_SOFTWARE_SLAVE, Configuration Error"
            #endif

			#if MSPI_TRANSMITTER_INTERRUPT == TXE_DISABLE
				CLR_BIT(MSPI2->CR2, CR2_TXEIE);
			#elif MSPI_TRANSMITTER_INTERRUPT == TXE_ENABLE
				SET_BIT(MSPI2->CR2, CR2_TXEIE);
			#else
                #error "SPI MSPI_TRANSMITTER_INTERRUPT, Configuration Error"
            #endif

			#if MSPI_RECEIVER_INTERRUPT == RXE_DISABLE
				CLR_BIT(MSPI2->CR2, CR2_RXNEIE);
			#elif MSPI_RECEIVER_INTERRUPT == RXE_ENABLE
				SET_BIT(MSPI2->CR2, CR2_RXNEIE);
			#else
                #error "SPI MSPI_RECEIVER_INTERRUPT, Configuration Error"
            #endif

			#if MSPI_ERROR_INTERRUPT == ERROR_DISABLE
				CLR_BIT(MSPI2->CR2, CR2_ERRIE);
			#elif MSPI_ERROR_INTERRUPT == ERROR_ENABLE
				SET_BIT(MSPI2->CR2, CR2_ERRIE);
			#else
                #error "SPI MSPI_ERROR_INTERRUPT, Configuration Error"
            #endif

			#if MSPI_DATA_FRAME_FORMAT== FRAME_8_BIT
				CLR_BIT(MSPI2->CR1, CR1_DFF);
			#elif MSPI_DATA_FRAME_FORMAT == FRAME_16_BIT
				SET_BIT(MSPI2->CR1, CR1_DFF);
			#else
                #error "SPI MSPI_DATA_FRAME_FORMAT, Configuration Error"
            #endif

			MSPI2->CR1 &= MSPI_FPCLK_MASK;
			MSPI2->CR1 |= (MSPI_BAUD_RATE << CR1_BR);

			SET_BIT(MSPI2->CR1, CR1_SPE);

		#elif MSPI_ENABLE_PERIPHERAL == MSPI_DISABLE
			CLR_BIT(MSPI2->CR1, CR1_SPE);
		#else
			#error "SPI MSPI_ENABLE_PERIPHERAL, Configuration Error"
		#endif
	break;

	}
}

void MSPI_voidSetFullDuplexMode(u8 Copy_u8SPINumber)
{
	switch(Copy_u8SPINumber)
	{
	case MSPI_1:
		CLR_BIT(MSPI1->CR1, CR1_BIDIMODE);
		CLR_BIT(MSPI1->CR1, CR1_RXONLY);
	break;
	case MSPI_2:
		CLR_BIT(MSPI2->CR1, CR1_BIDIMODE);
		CLR_BIT(MSPI2->CR1, CR1_RXONLY);
	break;
	}
}

void MSPI_voidSetUnidirectionalReceiveOnlyMode(u8 Copy_u8SPINumber)
{
	switch(Copy_u8SPINumber)
	{
	case MSPI_1:
		CLR_BIT(MSPI1->CR1, CR1_BIDIMODE);
		SET_BIT(MSPI1->CR1, CR1_RXONLY);
	break;
	case MSPI_2:
		CLR_BIT(MSPI2->CR1, CR1_BIDIMODE);
		SET_BIT(MSPI2->CR1, CR1_RXONLY);
	break;
	}
}

void MSPI_voidSetBidirectionalTransmittingMode(u8 Copy_u8SPINumber)
{
	switch(Copy_u8SPINumber)
	{
	case MSPI_1:
		SET_BIT(MSPI1->CR1, CR1_BIDIMODE);
		SET_BIT(MSPI1->CR1, CR1_BIDIOE);
	break;
	case MSPI_2:
		SET_BIT(MSPI2->CR1, CR1_BIDIMODE);
		SET_BIT(MSPI2->CR1, CR1_BIDIOE);
	break;
	}
}

void MSPI_voidSetBidirectionalReceivingMode(u8 Copy_u8SPINumber)
{
	switch(Copy_u8SPINumber)
	{
	case MSPI_1:
		SET_BIT(MSPI1->CR1, CR1_BIDIMODE);
		CLR_BIT(MSPI1->CR1, CR1_BIDIOE);
	break;
	case MSPI_2:
		SET_BIT(MSPI2->CR1, CR1_BIDIMODE);
		CLR_BIT(MSPI2->CR1, CR1_BIDIOE);
	break;
	}
}

u8 MSPI_u8SendReceiveData(u8 Copy_u8SPINumber, u8 Copy_u8Data)
{
	u8 Local_u8ReceivedData;

	switch(Copy_u8SPINumber)
	{
	case MSPI_1:
		MSPI1->DR = Copy_u8Data;	/* Send data */
		while(GET_BIT(MSPI1->SR, SR_BSY) == 1);	/* Wait till finish transmission */
		Local_u8ReceivedData = MSPI1->DR;
	break;
	case MSPI_2:
		MSPI2->DR = Copy_u8Data;	/* Send data */
		while(GET_BIT(MSPI2->SR, SR_BSY) == 1);	/* Wait till finish transmission */
		Local_u8ReceivedData = MSPI2->DR;
	break;
	}

	return Local_u8ReceivedData;
}

u16 MSPI_u16SendReceiveWord(u8 Copy_u8SPINumber, u16 Copy_u16Data)
{
	u16 Local_u16ReceivedData;

	switch(Copy_u8SPINumber)
	{
	case MSPI_1:
		MSPI1->DR = Copy_u16Data;	/* Send data */
		while(GET_BIT(MSPI1->SR, SR_BSY) == 1);	/* Wait till finish transmission */
		Local_u16ReceivedData = MSPI1->DR;
	break;
	case MSPI_2:
		MSPI2->DR = Copy_u16Data;	/* Send data */
		while(GET_BIT(MSPI2->SR, SR_BSY) == 1);	/* Wait till finish transmission */
		Local_u16ReceivedData = MSPI2->DR;
	break;
	}

	return Local_u16ReceivedData;
}

void MSPI_voidSendData(u8 Copy_u8SPINumber, u8 Copy_u8Data)
{
	switch(Copy_u8SPINumber)
	{
	case MSPI_1:
		MSPI1->DR = Copy_u8Data;	/* Send data */
		while(GET_BIT(MSPI1->SR, SR_BSY) == 1);	/* Wait till finish transmission */
	break;
	case MSPI_2:
		MSPI2->DR = Copy_u8Data;	/* Send data */
		while(GET_BIT(MSPI2->SR, SR_BSY) == 1);	/* Wait till finish transmission */
	break;
	}
}

void MSPI_voidSendWord(u8 Copy_u8SPINumber, u16 Copy_u16Data)
{
	switch(Copy_u8SPINumber)
	{
	case MSPI_1:
		MSPI1->DR = Copy_u16Data;	/* Send data */
		while(GET_BIT(MSPI1->SR, SR_BSY) == 1);	/* Wait till finish transmission */
	break;
	case MSPI_2:
		MSPI2->DR = Copy_u16Data;	/* Send data */
		while(GET_BIT(MSPI2->SR, SR_BSY) == 1);	/* Wait till finish transmission */
	break;
	}

}

u8 MSPI_u8ReceiveData(u8 Copy_u8SPINumber)
{
	u8 Local_u8ReceivedData;

	switch(Copy_u8SPINumber)
	{
	case MSPI_1:
		while(GET_BIT(MSPI1->SR, SR_BSY) == 1);	/* Wait till finish transmission */
		Local_u8ReceivedData = MSPI1->DR;
	break;
	case MSPI_2:
		while(GET_BIT(MSPI2->SR, SR_BSY) == 1);	/* Wait till finish transmission */
		Local_u8ReceivedData = MSPI2->DR;
	break;
	}

	return Local_u8ReceivedData;
}

u16 MSPI_u16ReceiveWord(u8 Copy_u8SPINumber)
{
	u16 Local_u16ReceivedData;

	switch(Copy_u8SPINumber)
	{
	case MSPI_1:
		while(GET_BIT(MSPI1->SR, SR_BSY) == 1);	/* Wait till finish transmission */
		Local_u16ReceivedData = MSPI1->DR;
	break;
	case MSPI_2:
		while(GET_BIT(MSPI2->SR, SR_BSY) == 1);	/* Wait till finish transmission */
		Local_u16ReceivedData = MSPI2->DR;
	break;
	}

	return Local_u16ReceivedData;
}

u8 MSPI_u8GetFlagStatus(u8 Copy_u8SPINumber, u8 Copy_u8FlagName)
{
	u8 Local_u8Temp;

	switch(Copy_u8SPINumber)
	{
	case MSPI_1:
		Local_u8Temp = (GET_BIT(MSPI1->SR, Copy_u8FlagName));
	break;
	case MSPI_2:
		Local_u8Temp = (GET_BIT(MSPI2->SR, Copy_u8FlagName));
	break;
	}

	return Local_u8Temp;
}

void MSPI1_voidSetCallBack(void(*pvNotificationFunction)(void))
{
	MSPI1_CallBack = pvNotificationFunction;
}

void MSPI2_voidSetCallBack(void(*pvNotificationFunction)(void))
{
	MSPI2_CallBack = pvNotificationFunction;
}


/************* SPI ISR ******************/

void SPI1_IRQHandler (void)
{
    if (MSPI1_CallBack != NULL_PTR)
    {
        MSPI1_CallBack();
    }
}

void SPI2_IRQHandler(void)
{
    if (MSPI2_CallBack != NULL_PTR)
    {
        MSPI2_CallBack();
    }
}

















