/****************************************************/
/*		Auther	 :  Ramy Haddad						*/
/* 		Date	 :  15-JAN-23				    	*/
/*		Version  :  V.1.0							*/
/****************************************************/

#ifndef MCAL_RCC_RCC_CONFIG_H_
#define MCAL_RCC_RCC_CONFIG_H_


#define rdy_busy_wait_time 5000

/*system clock source options*/

#define HSI 0x01
#define HSE 0x02
#define PLL 0x03

#define sys_clock_source HSE // EDIT

/*system clock source selecting */

#if sys_clock_source == PLL

/* HSI
 * HSE
 */

#define PLL_clock_source HSE // EDIT

#endif

/* PLL Factors */

#define PLL_P_FACT		2				// Acceptable range	2 / 4 / 6 / 8
#define PLL_N_FACT		20				// Acceptable range	192<=PLL_N_FACT=>432
#define PLL_M_FACT 		0				// Acceptable range	2<=PLL_M_FACT=>63
#define PLL_Q_FACT 		2				// Acceptable range	2<=PLL_Q_FACT=>15


/*-----Busses Prescaler-----*/

/*
 * Chose from
 * Enum APB_1_prescaler_t
 * @ RCC_interfacing.h
 */
#define APB1_Prescaler_init APB_1_Prescaler_NO_division
/*
 * Chose from
 * Enum APB_2_prescaler_t
 * @ RCC_interfacing.h
 */
#define APB2_Prescaler_init APB_2_Prescaler_4_division
/*
 * Chose from
 * Enum AHB_prescaler_t
 * @ RCC_interfacing.h
 */
#define AHB_Prescaler_init AHB_Prescaler_NO_division


/*APB1_Periphrals_Group*/
#define CONC_APB1(b28,b23,b22,b21,b17,b15,b14,b11,b3,b2,b1,b0)       CONC_HELP_APB1(b28,b23,b22,b21,b17,b15,b14,b11,b3,b2,b1,b0)
#define CONC_HELP_APB1(b28,b23,b22,b21,b17,b15,b14,b11,b3,b2,b1,b0)  0b##000##b28##0000##b23##b22##b21##000##b17##0##b15##b14##00##b11##0000000##b3##b2##b1##b0

#define APB1_Periphrals_Group_Value CONC_APB1(EN_PWR,EN_I2C3,EN_I2C2,EN_I2C1,EN_USART2,EN_SPI3,EN_SPI2,EN_WWDG,EN_TIM5,EN_TIM4,EN_TIM3,EN_TIM2)
/*
 * Enable  1
 * Disable 0
 * */
#define EN_PWR	   0
#define EN_I2C3	   0
#define EN_I2C2	   0
#define EN_I2C1	   0
#define EN_USART2  0
#define EN_SPI3	   0
#define EN_SPI2	   0
#define EN_WWDG	   0
#define EN_TIM5	   0
#define EN_TIM4	   0
#define EN_TIM3	   0
#define EN_TIM2	   0

/*APB2_Periphrals_Group*/
#define CONC_APB2(b18,b17,b16,b14,b13,b12,b11,b8,b5,b4,b0)      	CONC_HELP_APB2(b18,b17,b16,b14,b13,b12,b11,b8,b5,b4,b0)
#define CONC_HELP_APB2(b18,b17,b16,b14,b13,b12,b11,b8,b5,b4,b0)   	0b##0000000000000##b18##b17##b16##0##b14##b13##b12##b11##00##b8##00##b5##b4##000##b0

#define APB2_Periphrals_Group_Value CONC_APB2(EN_TIM11,EN_TIM10,EN_TIM9,EN_SYSCFG,EN_SPI4,EN_SPI1,EN_SDIO,EN_ADC1,EN_USART6,EN_USART1,EN_TIM1)
/*
 * Enable  1
 * Disable 0
 * */
#define EN_TIM11	0
#define EN_TIM10	0
#define EN_TIM9		0
#define EN_SYSCFG	0
#define EN_SPI4		0
#define EN_SPI1		0
#define EN_SDIO		0
#define EN_ADC1		0
#define EN_USART6	0
#define EN_USART1	0
#define EN_TIM1		0

/*AHB1_Periphrals_Group*/
#define CONC_AHB1(b22,b21,b12,b7,b4,b3,b2,b1,b0)      		CONC_HELP_AHB1(b22,b21,b12,b7,b4,b3,b2,b1,b0)
#define CONC_HELP_AHB1(b22,b21,b12,b7,b4,b3,b2,b1,b0)   	0b##000000000##b22##b21##00000000##b12##0000##b7##00##b4##b3##b2##b1##b0

#define AHB1_Periphrals_Group_Value CONC_AHB1(EN_DMA2,EN_DMA1,EN_CRC,EN_GPIOH,EN_GPIOE,EN_GPIOD,EN_GPIOC,EN_GPIOB,EN_GPIOA)
/*
 * Enable  1
 * Disable 0
 * */
#define EN_DMA2		0
#define EN_DMA1		0
#define EN_CRC		0
#define EN_GPIOH	0
#define EN_GPIOE	0
#define EN_GPIOD	0
#define EN_GPIOC	1
#define EN_GPIOB	1
#define EN_GPIOA	1

/*AHB2_Periphrals_Group*/

#define CONC_AHB2(b7)      				CONC_HELP_AHB2(b7)
#define CONC_HELP_AHB2(b7)    			0b##000000000000000000000000##b7##0000000

#define AHB2_Periphrals_Group_Value     CONC_AHB2(EN_OTGFS)

/*
 * Enable  1
 * Disable 0
 * */
#define EN_OTGFS		0


#endif /* MCAL_RCC_RCC_CONFIG_H_ */
