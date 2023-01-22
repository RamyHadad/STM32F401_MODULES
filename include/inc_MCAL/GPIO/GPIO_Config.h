/****************************************************/
/*		Auther	 :  Ramy Haddad						*/
/* 		Date	 :  15-JAN-23				    	*/
/*		Version  :  V.1.0							*/
/****************************************************/

#ifndef MCAL_GPIO_GPIO_CONFIG_H_
#define MCAL_GPIO_GPIO_CONFIG_H_

/*-----------------------------------------DONT EDIT ANY VALUE IN GPIO_CONFIG.h-----------------------------------------*/

/*------------------MODES--------------------*/

#define CONFIG_PIN_INPUT 			 			00
#define CONFIG_PIN_OUTPUT			 			01
#define CONFIG_PIN_ALTERNATE_FUNCTION			10
#define CONFIG_PIN_ANALOG_MODE 11

/*------------------OUTPUT PP/OD --------------------*/

#define CONFIG_OUTPUT_PUSH_PULL   				 0
#define CONFIG_OUTPUT_OPEN_DRAIN  				 1

/*------------------ OUTPUT SPEED--------------------*/

#define CONFIG_OUTPUT_SPEED_LOW      			00
#define CONFIG_OUTPUT_SPEED_MEDIUM   			01
#define CONFIG_OUTPUT_SPEED_FAST    			10
#define CONFIG_OUTPUT_SPEED_HIGH    			11

/*------------------ PULL UP / PULL DOWN --------------------*/

#define CONFIG_PULL_NO							00
#define CONFIG_PULL_UP							01
#define CONFIG_PULL_DOWN						10

/*-------------------------------------- EDITABLE CONFIGURATIONS FILES -----------------------------------------*/

#include "GPIO_Config_PORTA.h"
#include "GPIO_Config_PORTB.h"
#include "GPIO_Config_PORTC.h"

#endif /*MCAL_GPIO_GPIO_CONFIG_H_*/
