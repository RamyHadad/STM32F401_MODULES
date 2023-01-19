/*
 * RCC_Private.h
 *
 *  Created on: Dec 25, 2022
 *      Author: Ramy
 */

#ifndef MCAL_GPIO_GPIO_PRIVATE_H_
#define MCAL_GPIO_GPIO_PRIVATE_H_

#include "../../STD_TYPES.h"

/*--------------Memory Mapping-----------------*/

#define GPIOx_REG 	((volatile GPIO_t*)0x40020000) // Base Address which is equal to GPIOA

#define GPIOA_REG	((volatile GPIO_t*)0x40020000)
#define GPIOB_REG	((volatile GPIO_t*)0x40020400)
#define GPIOC_REG	((volatile GPIO_t*)0x40020800)


typedef struct {

	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDER;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFRL;
	volatile uint32_t AFRH;

}GPIO_t;


#endif /* MCAL_GPIO_GPIO_PRIVATE_H_ */
