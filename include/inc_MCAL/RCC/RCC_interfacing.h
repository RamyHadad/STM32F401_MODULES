/*
 * RCC_interfacing.h
 *
 *  Created on: Dec 25, 2022
 *      Author: Ramy
 */

#ifndef MCAL_RCC_RCC_INTERFACING_H_
#define MCAL_RCC_RCC_INTERFACING_H_

#include "../../STD_TYPES.h"
#include "RCC_Private.h"
#include "RCC_Config.h"


#define NO_RDY 0
#define RDY  1

#define Clear_mask_2_Bits 0x03
#define Clear_mask_3_Bits 0x07
#define Clear_mask_4_Bits 0x0F
#define Clear_mask_6_Bits 0x3F
#define Clear_mask_9_Bits 0x11F

#define CR_HSI_RDY_Bit 1
#define CR_HSI_ON_Bit 0

#define CR_HSE_RDY_Bit 17
#define CR_HSE_ON_Bit 16

#define CR_PLL_RDY_Bit 25
#define CR_PLL_ON_Bit 24

#define CFGR_SW0_bit 0
#define CFGR_SW1_bit 1

#define PLLSRC 22 // PLL Clk source selecting bit

/*--------------MACRO Declaration ----------------*/

#define PLL_Source_Disable() CLEAR_BIT(RCC->CR,CR_PLL_ON_Bit)
#define PLL_Source_Enable()  SET_BIT(RCC->CR,CR_PLL_ON_Bit)
#define PLL_Source_Check()   READ_BIT(RCC->CR,CR_PLL_ON_Bit)

/*--------------AHB1 Periphrals List----------------*/

#define AHB1_DMA2 22
#define AHB1_DMA1 21
#define AHB1_CRC  12
#define AHB1_GPIOH 7
#define AHB1_GPIOE 4
#define AHB1_GPIOD 3
#define AHB1_GPIOC 2
#define AHB1_GPIOB 1
#define AHB1_GPIOA 0

/*--------------AHB1 Periphrals List----------------*/

#define AHB2_OTGFS 7

/*--------------APB1 Periphrals List----------------*/

#define APB1_PWR	28
#define APB1_I2C3	23
#define APB1_I2C2	22
#define APB1_I2C1	21
#define APB1_USART2	17
#define APB1_SPI3	15
#define APB1_SPI2	14
#define APB1_WWDG	11
#define APB1_TIM5	3
#define APB1_TIM4	2
#define APB1_TIM3	1
#define APB1_TIM2	0

/*--------------APB2 Periphrals List----------------*/

#define APB2_TIM11	18
#define APB2_TIM10	17
#define APB2_TIM9	16
#define APB2_SYSCFG	14
#define APB2_SPI4	13
#define APB2_SPI1	12
#define APB2_SDIO	11
#define APB2_ADC1	8
#define APB2_USART6	5
#define APB2_USART1	4
#define APB2_TIM1	0


typedef enum {
	APB1,
	APB2,
	AHB1,
	AHB2
}Busses_t;

typedef enum {
	APB_1_Prescaler_NO_division,
	APB_1_Prescaler_2_division=4,
	APB_1_Prescaler_4_division,
	APB_1_Prescaler_8_division,
	APB_1_Prescaler_16_division
}APB_1_prescaler_t;

typedef enum {
	APB_2_Prescaler_NO_division,
	APB_2_Prescaler_2_division=4,
	APB_2_Prescaler_4_division,
	APB_2_Prescaler_8_division,
	APB_2_Prescaler_16_division
}APB_2_prescaler_t;

typedef enum {
	AHB_Prescaler_NO_division,
	AHB_Prescaler_2_division=8,
	AHB_Prescaler_4_division,
	AHB_Prescaler_8_division,
	AHB_Prescaler_16_division,
	AHB_Prescaler_64_division,
	AHB_Prescaler_128_division,
	AHB_Prescaler_256_division,
	AHB_Prescaler_512_division
}AHB_prescaler_t;

/*
typedef struct{
#if sys_clock_source == PLL
	uint16_t PLL_M_factor:6;
	uint16_t PLL_N_factor:9; // only 9 bits last bit not used
	uint16_t reserved : 1;
	uint8_t PLL_P_factor :2; // only 2 bits used later factor Q could be added using bit field
	uint8_t PLL_Q_factor :6;
#endif
}RCC_PLL_MODE_t;
*/

/*--------------Function Declaration--------------*/

Std_ReturnType RCC_INIT();

Std_ReturnType RCC_Sys_CLK_SET(uint8_t Copy_clk_source);

Std_ReturnType RCC_CLK_RDY_Status_check(uint8_t Copy_clk_source);

Std_ReturnType RCC_CLK_SET_re_check(uint8_t Copy_clk_source);

Std_ReturnType RCC_CLK_source_enable(uint8_t Copy_clk_source);

Std_ReturnType RCC_CLK_source_disable(uint8_t Copy_clk_source);

Std_ReturnType RCC_CLK_Busses_Prescaler(Busses_t Copy_bus_name , uint8_t Prescaler_value);

Std_ReturnType RCC_Periphral_enable(Busses_t Copy_bus_name , uint8_t Periphral_name);

Std_ReturnType RCC_Periphral_disable(Busses_t Copy_bus_name , uint8_t Periphral_name);

Std_ReturnType RCC_PLL_CLK_source_SET(uint8_t Copy_clk_source);

Std_ReturnType RCC_PLL_SET_FACTORS(uint8_t P_fact , uint8_t N_fact , uint8_t M_fact , uint8_t Q_fact );



#endif /* MCAL_RCC_RCC_INTERFACING_H_ */
