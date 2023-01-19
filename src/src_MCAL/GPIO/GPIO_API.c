/****************************************************/
/*		Auther	 :  Ramy Haddad						*/
/* 		Date	 :  15-JAN-23				    	*/
/*		Version  :  V.1.0							*/
/****************************************************/

#include "../../../include/inc_MCAL/GPIO/GPIO_interfacing.h"

static volatile GPIO_t * GPIOX_ARR[3] = {GPIOA_REG,GPIOB_REG,GPIOC_REG};

Std_ReturnType GPIO_PRECONFIG_INIT(){

	Std_ReturnType ret = E_NOT_OK ;

	/*mode direction select for all PORTS*/

	GPIOA_REG->MODER = GPIO_PORTA_MODE_PINS ;
	GPIOB_REG->MODER = GPIO_PORTB_MODE_PINS ;
	GPIOC_REG->MODER = GPIO_PORTC_MODE_PINS ;

	/*PP OR OD select for all PORTS*/

	GPIOA_REG->OTYPER = GPIO_PORTA_PP_OD ;
	GPIOB_REG->OTYPER = GPIO_PORTB_PP_OD ;
	GPIOC_REG->OTYPER = GPIO_PORTC_PP_OD ;

	/*output speed select for all ports*/

	GPIOA_REG->OSPEEDER = GPIO_PORTA_OUTPUT_SPEED ;
	GPIOB_REG->OSPEEDER = GPIO_PORTB_OUTPUT_SPEED ;
	GPIOC_REG->OSPEEDER = GPIO_PORTC_OUTPUT_SPEED ;


	/*pull up or pull down select for all ports*/

	GPIOA_REG->PUPDR = GPIO_PORTA_PULL_MODE ;
	GPIOB_REG->PUPDR = GPIO_PORTB_PULL_MODE ;
	GPIOC_REG->PUPDR = GPIO_PORTC_PULL_MODE ;


	return ret;
}


Std_ReturnType GPIO_WRITE_LOGIC(uint8_t Port,uint8_t Pin,uint8_t LOGIC){

	Std_ReturnType ret = E_NOT_OK ;

	if(Port > GPIO_PORTC || Pin > GPIO_PIN_15)
	{
		return ret ;
	}
	else
	{
		//volatile GPIO_t * Local_Reg_PTR = (volatile GPIO_t *)( (uint32_t) GPIOx_REG + Port );

		switch(LOGIC)
		{
		case GPIO_HIGH : GPIOX_ARR[Port]->ODR |= (1<<Pin)  ; break;

		case GPIO_LOW  : GPIOX_ARR[Port]->ODR &= ~(1<<Pin)  ; break;
		}

	}


	return ret;
}
