/****************************************************/
/*		Auther	 :  Ramy Haddad						*/
/* 		Date	 :  15-JAN-23				    	*/
/*		Version  :  V.1.0							*/
/****************************************************/

#ifndef INCLUDE_INC_MCAL_GPIO_GPIO_INTERFACING_H_
#define INCLUDE_INC_MCAL_GPIO_GPIO_INTERFACING_H_

/*--------------------includes--------------------*/
#include "../../STD_TYPES.h"
#include "GPIO_Private.h"
#include "GPIO_Config.h"

/*---------------MACRO Declerations---------------*/
#define GPIO_OUTPUT_PUSH_PULLL 0
#define GPIO_OUTPUT_OPEN_DRAIN 1
/*---------------MACRO Functions---------------*/

/*---------------Types Declerations---------------*/

typedef enum{
	GPIO_PIN_0,
	GPIO_PIN_1,
	GPIO_PIN_2,
	GPIO_PIN_3,
	GPIO_PIN_4,
	GPIO_PIN_5,
	GPIO_PIN_6,
	GPIO_PIN_7,
	GPIO_PIN_8,
	GPIO_PIN_9,
	GPIO_PIN_10,
	GPIO_PIN_11,
	GPIO_PIN_12,
	GPIO_PIN_13,
	GPIO_PIN_14,
	GPIO_PIN_15
}GPIO_PINS;

typedef enum {
	GPIO_PORTA,
	GPIO_PORTB,
	GPIO_PORTC
}GPIO_PORT;

typedef enum{
	GPIO_PIN_INPUT,
	GPIO_PIN_OUTPUT,
	GPIO_PIN_ALTERNATE_FUNCTION,
	GPIO_PIN_ANALOG_MODE
}PIN_MODE;

typedef enum {
	SPEED_LOW,
	SPEED_MEDIUM,
	SPEED_FAST,
	SPEED_HIGH
}PIN_OP_AF_SPEED;

typedef enum {
	PULL_NO,
	PULL_UP,
	PULL_DOWN
}PULL_UP_PULL_DOWN;

typedef enum {
	GPIO_LOW,
	GPIO_HIGH
}GPIO_logic;

/*
typedef struct
{
	uint8_t pin   : 4 ;
	uint8_t port  : 2 ;
	uint8_t mode  : 2 ;
	uint8_t speed : 2 ;
	uint8_t push_pull_mode : 2 ;
	uint8_t logic : 2 ;


}GPIO_PIN_t;
*/

/*--------------Function Declaration--------------*/

//Std_ReturnType GPIO_PRECONFIG_INIT();
//Std_ReturnType GPIO_MODE_SELECT(const GPIO_PIN_t * pin_obj );
//Std_ReturnType GPIO_OUTPUT_SPEED_SELECT(const GPIO_PIN_t * pin_obj );
//Std_ReturnType GPIO_PULL_UP_PULL_DOWN_SELECT(const GPIO_PIN_t * pin_obj );

Std_ReturnType GPIO_PRECONFIG_INIT();
Std_ReturnType GPIO_WRITE_LOGIC(uint8_t Port,uint8_t Pin,uint8_t LOGIC);
Std_ReturnType GPIO_WRITE_LOGIC_ATOMIC(uint8_t Port,uint8_t Pin,uint8_t LOGIC);
Std_ReturnType GPIO_READ_LOGIC(uint8_t Port,uint8_t Pin,uint8_t * VALUE);





#endif /* INCLUDE_INC_MCAL_GPIO_GPIO_INTERFACING_H_ */
