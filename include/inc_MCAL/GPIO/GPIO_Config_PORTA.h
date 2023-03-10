/****************************************************/
/*		Auther	 :  Ramy Haddad						*/
/* 		Date	 :  15-JAN-23				    	*/
/*		Version  :  V.1.0							*/
/****************************************************/

#ifndef INC_MCAL_GPIO_GPIO_CONFIG_PORTA_H_
#define INC_MCAL_GPIO_GPIO_CONFIG_PORTA_H_


/*------------------ PORT A MODE --------------------*/

#define CONC_PORTA_MODE(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)       CONC_HELP_PORTA_MODE(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_HELP_PORTA_MODE(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)  0b##b15##b14##b13##b12##b11##b10##b9##b8##b7##b6##b5##b4##b3##b2##b1##b0

#define GPIO_PORTA_MODE_PINS  CONC_PORTA_MODE(EN_GPIOA_PIN_15,EN_GPIOA_PIN_14,EN_GPIOA_PIN_13,EN_GPIOA_PIN_12,EN_GPIOA_PIN_11,EN_GPIOA_PIN_10,EN_GPIOA_PIN_9,EN_GPIOA_PIN_8,EN_GPIOA_PIN_7,EN_GPIOA_PIN_6,EN_GPIOA_PIN_5,EN_GPIOA_PIN_4,EN_GPIOA_PIN_3,EN_GPIOA_PIN_2,EN_GPIOA_PIN_1,EN_GPIOA_PIN_0)
/*
 * CONFIG_PIN_INPUT
 * CONFIG_PIN_OUTPUT
 * CONFIG_PIN_ALTERNATE_FUNCTION
 * CONFIG_PIN_ANALOG_MODE
 * */
#define EN_GPIOA_PIN_0 		CONFIG_PIN_OUTPUT
#define EN_GPIOA_PIN_1      CONFIG_PIN_OUTPUT
#define EN_GPIOA_PIN_2      CONFIG_PIN_INPUT
#define EN_GPIOA_PIN_3      CONFIG_PIN_INPUT
#define EN_GPIOA_PIN_4      CONFIG_PIN_INPUT
#define EN_GPIOA_PIN_5      CONFIG_PIN_INPUT
#define EN_GPIOA_PIN_6      CONFIG_PIN_INPUT
#define EN_GPIOA_PIN_7      CONFIG_PIN_INPUT
#define EN_GPIOA_PIN_8      CONFIG_PIN_INPUT
#define EN_GPIOA_PIN_9      CONFIG_PIN_INPUT
#define EN_GPIOA_PIN_10     CONFIG_PIN_INPUT
#define EN_GPIOA_PIN_11     CONFIG_PIN_INPUT
#define EN_GPIOA_PIN_12     CONFIG_PIN_INPUT
#define EN_GPIOA_PIN_13     CONFIG_PIN_ALTERNATE_FUNCTION	//DEFAULT VALUE
#define EN_GPIOA_PIN_14     CONFIG_PIN_ALTERNATE_FUNCTION	//DEFAULT VALUE
#define EN_GPIOA_PIN_15     CONFIG_PIN_ALTERNATE_FUNCTION	//DEFAULT VALUE

/*------------------ PORT A OUTPUT PUSH / OPEN DRAIN --------------------*/

#define CONC_PORTA_PP_OD(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)       CONC_HELP_PORTA_PP_OD(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_HELP_PORTA_PP_OD(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)  0b##b15##b14##b13##b12##b11##b10##b9##b8##b7##b6##b5##b4##b3##b2##b1##b0

#define GPIO_PORTA_PP_OD CONC_PORTA_PP_OD(EN_GPIOA_PP_OD_15,EN_GPIOA_PP_OD_14,EN_GPIOA_PP_OD_13,EN_GPIOA_PP_OD_12,EN_GPIOA_PP_OD_11,EN_GPIOA_PP_OD_10,EN_GPIOA_PP_OD_9,EN_GPIOA_PP_OD_8,EN_GPIOA_PP_OD_7,EN_GPIOA_PP_OD_6,EN_GPIOA_PP_OD_5,EN_GPIOA_PP_OD_4,EN_GPIOA_PP_OD_3,EN_GPIOA_PP_OD_2,EN_GPIOA_PP_OD_1,EN_GPIOA_PP_OD_0)
/*
 * CONFIG_OUTPUT_PUSH_PULL
 * CONFIG_OUTPUT_OPEN_DRAIN
 * */

#define EN_GPIOA_PP_OD_0 	  CONFIG_OUTPUT_PUSH_PULL
#define EN_GPIOA_PP_OD_1      CONFIG_OUTPUT_PUSH_PULL
#define EN_GPIOA_PP_OD_2      CONFIG_OUTPUT_PUSH_PULL
#define EN_GPIOA_PP_OD_3      CONFIG_OUTPUT_PUSH_PULL
#define EN_GPIOA_PP_OD_4      CONFIG_OUTPUT_PUSH_PULL
#define EN_GPIOA_PP_OD_5      CONFIG_OUTPUT_PUSH_PULL
#define EN_GPIOA_PP_OD_6      CONFIG_OUTPUT_PUSH_PULL
#define EN_GPIOA_PP_OD_7      CONFIG_OUTPUT_PUSH_PULL
#define EN_GPIOA_PP_OD_8      CONFIG_OUTPUT_PUSH_PULL
#define EN_GPIOA_PP_OD_9      CONFIG_OUTPUT_PUSH_PULL
#define EN_GPIOA_PP_OD_10     CONFIG_OUTPUT_PUSH_PULL
#define EN_GPIOA_PP_OD_11     CONFIG_OUTPUT_PUSH_PULL
#define EN_GPIOA_PP_OD_12     CONFIG_OUTPUT_PUSH_PULL
#define EN_GPIOA_PP_OD_13     CONFIG_OUTPUT_PUSH_PULL
#define EN_GPIOA_PP_OD_14     CONFIG_OUTPUT_PUSH_PULL
#define EN_GPIOA_PP_OD_15     CONFIG_OUTPUT_PUSH_PULL

/*------------------ PORT A OUTPUT SPEED --------------------*/

#define CONC_PORTA_OUTPUT_SPEED(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)       CONC_HELP_PORTA_OUTPUT_SPEED(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_HELP_PORTA_OUTPUT_SPEED(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)  0b##b15##b14##b13##b12##b11##b10##b9##b8##b7##b6##b5##b4##b3##b2##b1##b0

#define GPIO_PORTA_OUTPUT_SPEED CONC_PORTA_OUTPUT_SPEED(EN_GPIOA_OUTPUT_SPEED_15,EN_GPIOA_OUTPUT_SPEED_14,EN_GPIOA_OUTPUT_SPEED_13,EN_GPIOA_OUTPUT_SPEED_12,EN_GPIOA_OUTPUT_SPEED_11,EN_GPIOA_OUTPUT_SPEED_10,EN_GPIOA_OUTPUT_SPEED_9,EN_GPIOA_OUTPUT_SPEED_8,EN_GPIOA_OUTPUT_SPEED_7,EN_GPIOA_OUTPUT_SPEED_6,EN_GPIOA_OUTPUT_SPEED_5,EN_GPIOA_OUTPUT_SPEED_4,EN_GPIOA_OUTPUT_SPEED_3,EN_GPIOA_OUTPUT_SPEED_2,EN_GPIOA_OUTPUT_SPEED_1,EN_GPIOA_OUTPUT_SPEED_0)
/*
 * CONFIG_OUTPUT_SPEED_LOW
 * CONFIG_OUTPUT_SPEED_MEDIUM
 * CONFIG_OUTPUT_SPEED_FAST
 * CONFIG_OUTPUT_SPEED_HIGH
 * */

#define EN_GPIOA_OUTPUT_SPEED_0 	 CONFIG_OUTPUT_SPEED_LOW
#define EN_GPIOA_OUTPUT_SPEED_1      CONFIG_OUTPUT_SPEED_LOW
#define EN_GPIOA_OUTPUT_SPEED_2      CONFIG_OUTPUT_SPEED_LOW
#define EN_GPIOA_OUTPUT_SPEED_3      CONFIG_OUTPUT_SPEED_LOW
#define EN_GPIOA_OUTPUT_SPEED_4      CONFIG_OUTPUT_SPEED_LOW
#define EN_GPIOA_OUTPUT_SPEED_5      CONFIG_OUTPUT_SPEED_LOW
#define EN_GPIOA_OUTPUT_SPEED_6      CONFIG_OUTPUT_SPEED_LOW
#define EN_GPIOA_OUTPUT_SPEED_7      CONFIG_OUTPUT_SPEED_LOW
#define EN_GPIOA_OUTPUT_SPEED_8      CONFIG_OUTPUT_SPEED_LOW
#define EN_GPIOA_OUTPUT_SPEED_9      CONFIG_OUTPUT_SPEED_LOW
#define EN_GPIOA_OUTPUT_SPEED_10     CONFIG_OUTPUT_SPEED_LOW
#define EN_GPIOA_OUTPUT_SPEED_11     CONFIG_OUTPUT_SPEED_LOW
#define EN_GPIOA_OUTPUT_SPEED_12     CONFIG_OUTPUT_SPEED_LOW
#define EN_GPIOA_OUTPUT_SPEED_13     CONFIG_OUTPUT_SPEED_LOW
#define EN_GPIOA_OUTPUT_SPEED_14     CONFIG_OUTPUT_SPEED_LOW
#define EN_GPIOA_OUTPUT_SPEED_15     CONFIG_OUTPUT_SPEED_LOW

/*------------------ PORT A PULL UP/DOWN  --------------------*/

#define CONC_PORTA_PULL_MODE(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)       CONC_HELP_PORTA_PULL_MODE(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_HELP_PORTA_PULL_MODE(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)  0b##b15##b14##b13##b12##b11##b10##b9##b8##b7##b6##b5##b4##b3##b2##b1##b0

#define GPIO_PORTA_PULL_MODE  CONC_PORTA_PULL_MODE(EN_GPIOA_PULL_MODE_15,EN_GPIOA_PULL_MODE_14,EN_GPIOA_PULL_MODE_13,EN_GPIOA_PULL_MODE_12,EN_GPIOA_PULL_MODE_11,EN_GPIOA_PULL_MODE_10,EN_GPIOA_PULL_MODE_9,EN_GPIOA_PULL_MODE_8,EN_GPIOA_PULL_MODE_7,EN_GPIOA_PULL_MODE_6,EN_GPIOA_PULL_MODE_5,EN_GPIOA_PULL_MODE_4,EN_GPIOA_PULL_MODE_3,EN_GPIOA_PULL_MODE_2,EN_GPIOA_PULL_MODE_1,EN_GPIOA_PULL_MODE_0)

/*
 * CONFIG_PULL_NO
 * CONFIG_PULL_UP
 * CONFIG_PULL_DOWN
 * */
#define EN_GPIOA_PULL_MODE_0 	  CONFIG_PULL_NO
#define EN_GPIOA_PULL_MODE_1      CONFIG_PULL_NO
#define EN_GPIOA_PULL_MODE_2      CONFIG_PULL_NO
#define EN_GPIOA_PULL_MODE_3      CONFIG_PULL_NO
#define EN_GPIOA_PULL_MODE_4      CONFIG_PULL_NO
#define EN_GPIOA_PULL_MODE_5      CONFIG_PULL_UP
#define EN_GPIOA_PULL_MODE_6      CONFIG_PULL_NO
#define EN_GPIOA_PULL_MODE_7      CONFIG_PULL_NO
#define EN_GPIOA_PULL_MODE_8      CONFIG_PULL_NO
#define EN_GPIOA_PULL_MODE_9      CONFIG_PULL_NO
#define EN_GPIOA_PULL_MODE_10     CONFIG_PULL_NO
#define EN_GPIOA_PULL_MODE_11     CONFIG_PULL_NO
#define EN_GPIOA_PULL_MODE_12     CONFIG_PULL_NO
#define EN_GPIOA_PULL_MODE_13     CONFIG_PULL_UP	//DEFAULT VALUE
#define EN_GPIOA_PULL_MODE_14     CONFIG_PULL_DOWN	//DEFAULT VALUE
#define EN_GPIOA_PULL_MODE_15     CONFIG_PULL_UP	//DEFAULT VALUE



#endif /* INC_MCAL_GPIO_GPIO_CONFIG_PORTA_H_ */
