/**************************************************************************************
 *  [File Name]	 : RCC_interface.h
 *	[Version]	 : V01
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

#define MRCC_AHB		0
#define MRCC_APB1		1
#define MRCC_APB2		2

/* Peripherals id bits for AHP */
#define DMA1_PERIPHERAL      0
#define DMA2_PERIPHERAL      1
#define SRAM_PERIPHERAL      2
#define FLITF_PERIPHERAL     4
#define CRCE_PERIPHERAL      6
#define FSMC_PERIPHERAL      8
#define SDIO_PERIPHERAL      10

/* Peripherals id bits for APB2 */
#define AFIO_PERIPHERAL      0
#define GPIOA_PERIPHERAL     2
#define GPIOB_PERIPHERAL     3
#define GPIOC_PERIPHERAL     4
#define GPIOD_PERIPHERAL     5
#define GPIOE_PERIPHERAL     6
#define GPIOF_PERIPHERAL     7
#define GPIOG_PERIPHERAL     8
#define ADC1_PERIPHERAL      9
#define ADC2_PERIPHERAL      10
#define TIM1_PERIPHERAL      11
#define SPI1_PERIPHERAL      12
#define TIM8_PERIPHERAL      13
#define USART1_PERIPHERAL    14
#define ADC3_PERIPHERAL      15
#define TIM9_PERIPHERAL      19
#define TIM10_PERIPHERAL     20
#define TIM11_PERIPHERAL     21

/* Peripherals id bits for APB1 */
#define TIM2_PERIPHERAL      0
#define TIM3_PERIPHERAL      1
#define TIM4_PERIPHERAL      2
#define TIM5_PERIPHERAL      3
#define TIM6_PERIPHERAL      4
#define TIM7_PERIPHERAL      5
#define TIM12_PERIPHERAL     6
#define TIM13_PERIPHERAL     7
#define TIM14_PERIPHERAL     8
#define WWD_PERIPHERAL       11
#define SPI2_PERIPHERAL      14
#define SPI3_PERIPHERAL      15
#define USART2_PERIPHERAL    17
#define USART3_PERIPHERAL    18
#define USART4_PERIPHERAL    19
#define USART5_PERIPHERAL    20
#define I2C1_PERIPHERAL      21
#define I2C2_PERIPHERAL      22
#define USB_PERIPHERAL       23
#define CAN_PERIPHERAL       25
#define BKP_PERIPHERAL       27
#define PWR_PERIPHERAL       28
#define DAC_PERIPHERAL       29

/* MRCC_voidInitSysClock --> Initialize the clock for the system */
void MRCC_voidInitSysClock(void);

/*
 * MRCC_voidEnableClock --> Enable a peripheral clock
 * i/p : Bus id (AHP - APB1 - APB2) / Peripheral id 0:31
 */
void MRCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PeripheralId);
/*
 * MRCC_voidDisableClock - > Disable a peripheral clock
 * i/p : Bus id (AHP - APB1 - APB2) / Peripheral id 0:31
 */
void MRCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PeripheralId);

#endif	/* RCC_INTERFACE_H_ */
