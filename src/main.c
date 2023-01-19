

#include "../include/inc_MCAL/RCC/RCC_interfacing.h"
#include "../include/inc_MCAL/GPIO/GPIO_interfacing.h"

Std_ReturnType ret ;

void main()
{
		ret = RCC_INIT();
		ret = GPIO_PRECONFIG_INIT();

  while (1)
    {
	  	 GPIO_WRITE_LOGIC(GPIO_PORTB,GPIO_PIN_0,GPIO_HIGH);
	  	  //GPIO_WRITE_LOGIC(GPIO_PORTB,GPIO_PIN_1,GPIO_HIGH);
	 	 GPIO_WRITE_LOGIC(GPIO_PORTA,GPIO_PIN_0,GPIO_HIGH);
	 	 GPIO_WRITE_LOGIC(GPIO_PORTA,GPIO_PIN_1,GPIO_HIGH);

    }
}



