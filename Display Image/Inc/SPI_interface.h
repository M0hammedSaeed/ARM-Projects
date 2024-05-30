/**************************************************************************************
 *  [File Name]	 : SPI_interface.h
 *	[Version]	 : V01
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

/* SPI Number */
#define MSPI_1        			    0
#define MSPI_2           			1

/* Flag Name */
#define RECEIVE_BUFFER_NOT_EMPTY    0
#define TRANSMIT_BUFFER_EMPTY       1
#define MODE_FAULT                  5
#define OVERRUN_FLAG                6
#define BUSY_FLAG                   7


void MSPI_voidInit(u8 Copy_u8SPINumber);

void MSPI_voidSetFullDuplexMode(u8 Copy_u8SPINumber);

void MSPI_voidSetUnidirectionalReceiveOnlyMode(u8 Copy_u8SPINumber);

void MSPI_voidSetBidirectionalTransmittingMode(u8 Copy_u8SPINumber);

void MSPI_voidSetBidirectionalReceivingMode(u8 Copy_u8SPINumber);

u8 MSPI_u8SendReceiveData(u8 Copy_u8SPINumber, u8 Copy_u8Data);

u16 MSPI_u16SendReceiveWord(u8 Copy_u8SPINumber, u16 Copy_u16Data);

void MSPI_voidSendData(u8 Copy_u8SPINumber, u8 Copy_u8Data);

void MSPI_voidSendWord(u8 Copy_u8SPINumber, u16 Copy_u16Data);

u8 MSPI_u8ReceiveData(u8 Copy_u8SPINumber);

u16 MSPI_u16ReceiveWord(u8 Copy_u8SPINumber);

u8 MSPI_u8GetFlagStatus(u8 Copy_u8SPINumber, u8 Copy_u8FlagName);

void MSPI1_voidSetCallBack(void(*pvNotificationFunction)(void));

void MSPI2_voidSetCallBack(void(*pvNotificationFunction)(void));

#endif /* SPI_INTERFACE_H_ */
