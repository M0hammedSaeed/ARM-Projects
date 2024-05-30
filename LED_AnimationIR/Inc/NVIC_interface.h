/**************************************************************************************
 *  [File Name]	 : NVIC_interface.h
 *	[Version]	 : V01
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

/* enum for all external interrupt 0:59 */
typedef enum {
	MNVIC_WWDG_IRQ    = 0     ,
	MNVIC_PVD_IRQ             ,
	MNVIC_TAMPER_IRQ          ,
	MNVIC_RTC_IRQ             ,
	MNVIC_FLASH_IRQ           ,
	MNVIC_RCC_IRQ             ,
	MNVIC_EXTI0_IRQ           ,
	MNVIC_EXTI1_IRQ           ,
	MNVIC_EXTI2_IRQ           ,
	MNVIC_EXTI3_IRQ           ,
	MNVIC_EXTI4_IRQ           ,
	MNVIC_DMA1_Channel1_IRQ   ,
	MNVIC_DMA1_Channel2_IRQ   ,
	MNVIC_DMA1_Channel3_IRQ   ,
	MNVIC_DMA1_Channel4_IRQ   ,
	MNVIC_DMA1_Channel5_IRQ   ,
	MNVIC_DMA1_Channel6_IRQ   ,
	MNVIC_DMA1_Channel7_IRQ   ,
	MNVIC_ADC1_2_IRQ          ,
	MNVIC_USB_HP_CAN_IRQ      ,
	MNVIC_USB_LP_CAN_IRQ      ,
	MNVIC_CAN_RX1_IRQ         ,
	MNVIC_CAN_SCE_IRQ         ,
	MNVIC_EXTI9_5_IRQ         ,
	MNVIC_TIM1_BRK_IRQ        ,
	MNVIC_TIM1_UP_IRQ         ,
	MNVIC_TIM1_TRG_COM_IRQ    ,
	MNVIC_TIM1_CC_IRQ         ,
	MNVIC_TIM2_IRQ            ,
	MNVIC_TIM3_IRQ            ,
	MNVIC_TIM4_IRQ            ,
	MNVIC_I2C1_EV_IRQ         ,
	MNVIC_I2C1_ER_IRQ         ,
	MNVIC_I2C2_EV_IRQ         ,
	MNVIC_I2C2_ER_IRQ         ,
	MNVIC_SPI1_IRQ            ,
	MNVIC_SPI2_IRQ            ,
	MNVIC_USART1_IRQ          ,
	MNVIC_USART2_IRQ          ,
	MNVIC_USART3_IRQ          ,
	MNVIC_EXTI15_10_IRQ       ,
	MNVIC_RTCAlarm_IRQ        ,
	MNVIC_USBWakeup_IRQ       ,
	MNVIC_TIM8_BRK_IRQ        ,
	MNVIC_TIM8_UP_IRQ         ,
	MNVIC_TIM8_TRG_COM_IRQ    ,
	MNVIC_TIM8_CC_IRQ         ,
	MNVIC_ADC3_IRQ            ,
	MNVIC_FSMC_IRQ            ,
	MNVIC_SDIO_IRQ            ,
	MNVIC_TIM5_IRQ            ,
	MNVIC_SPI3_IRQ            ,
	MNVIC_UART4_IRQ           ,
	MNVIC_UART5_IRQ           ,
	MNVIC_TIM6_IRQ            ,
	MNVIC_TIM7_IRQ            ,
	MNVIC_DMA2_Channel1_IRQ   ,
	MNVIC_DMA2_Channel2_IRQ   ,
	MNVIC_DMA2_Channel3_IRQ   ,
	MNVIC_DMA2_Channel4_5_IRQ
}MNVIC_IRQn_t;


/* MNVIC_voidInit --> initialize the priority system (determine number of group priorities and sub priorities) */
void MNVIC_voidInit(void);

/*
 * MNVIC_voidEnablePeripheralInterrupt --> Enable a specific external interrupt
 * i/p : Interrupt number (MNVIC_IRQn_t) 0:59
 */
void MNVIC_voidEnablePeripheralInterrupt(MNVIC_IRQn_t Copy_PeripheralID);

/*
 * MNVIC_voidDisablePeripheralInterrupt --> Disable a specific external interrupt
 * i/p : Interrupt number (MNVIC_IRQn_t) 0:59
 */
void MNVIC_voidDisablePeripheralInterrupt(MNVIC_IRQn_t Copy_PeripheralID);

/*
 * MNVIC_voidSetPendingFlag --> set pending flag for a specific external interrupt
 * i/p : Interrupt number (MNVIC_IRQn_t) 0:59
 */
void MNVIC_voidSetPendingFlag(MNVIC_IRQn_t Copy_u8PeripheralID);

/*
 * MNVIC_voidClearPendingFlag --> clear pending flag for a specific external interrupt
 * i/p : Interrupt number (MNVIC_IRQn_t) 0:59
 */
void MNVIC_voidClearPendingFlag(MNVIC_IRQn_t Copy_u8PeripheralID);

/*
 * MNVIC_u8GetActiveFlag --> Get the active flag state
 * i/p : Interrupt number (MNVIC_IRQn_t) 0:59
 * o/p : (u8) 0 or 1
 */
u8 MNVIC_u8GetActiveFlag(MNVIC_IRQn_t Copy_PeripheralID);

/*
 * MNVIC_voidSetPeripheralPriority --> Set priority for a specific external interrupt
 * i/p : Interrupt number (MNVIC_IRQn_t) 0:59  /  Interrupt priority (u8) 0:15
 */
void MNVIC_voidSetPeripheralPriority(MNVIC_IRQn_t Copy_PeripheralID, u8 Copy_u8Priority);

#endif	/* NVIC_INTERFACE_H_ */
