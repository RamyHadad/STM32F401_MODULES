/*
 * RCC_Private.h
 *
 *  Created on: Dec 25, 2022
 *      Author: Ramy
 */

#ifndef MCAL_RCC_RCC_PRIVATE_H_
#define MCAL_RCC_RCC_PRIVATE_H_

#include "../../STD_TYPES.h"

/*--------------Memory Mapping-----------------*/

#define RCC ((volatile RCC_reg*)0x40023800)

typedef struct{

    volatile uint32_t CR;
    volatile uint32_t PLLCFGR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    volatile uint32_t AHB1RSTR;
    volatile uint32_t AHB2RSTR;
    volatile uint32_t reserved_1[2];
    volatile uint32_t APB1RSTR;
    volatile uint32_t APB2RSTR;
    volatile uint32_t reserved_2[2];
    volatile uint32_t AHB1ENR;
    volatile uint32_t AHB2ENR;
    volatile uint32_t reserved_3[2];
    volatile uint32_t APB1ENR;
    volatile uint32_t APB2ENR;
    volatile uint32_t reserved_4[2];
    volatile uint32_t AHB1LPENR;
    volatile uint32_t AHB2LPENR;
    volatile uint32_t reserved_5[2];
    volatile uint32_t APB1LPENR;
    volatile uint32_t APB2LPENR;
    volatile uint32_t reserved_6[2];
    volatile uint32_t BDCR;
    volatile uint32_t CSR;
    volatile uint32_t reserved_7[2];
    volatile uint32_t SSCGR;
    volatile uint32_t PLLI2SCFGR;

}RCC_reg;




#endif /* MCAL_RCC_RCC_PRIVATE_H_ */
