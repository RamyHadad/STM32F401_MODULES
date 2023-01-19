/*
 * RCC_API.c
 *
 *  Created on: Dec 25, 2022
 *      Author: Ramy
 */

#include "../../../include/inc_MCAL/RCC/RCC_interfacing.h"

static void RCC_Periphral_Group_enable();

Std_ReturnType RCC_INIT(){

	Std_ReturnType ret = E_NOT_OK ;

#if sys_clock_source == HSI

	/* Enable clock source */
	ret = RCC_CLK_source_enable(HSI);
	/* SET clock source as sys clock & check is it ready or not */
	ret = RCC_Sys_CLK_SET(HSI);
	/* Busses Prescaler Select*/
	ret = RCC_CLK_Busses_Prescaler(APB1,APB1_Prescaler_init);
	ret = RCC_CLK_Busses_Prescaler(APB2,APB2_Prescaler_init);
	ret = RCC_CLK_Busses_Prescaler(AHB1,AHB_Prescaler_init);
	/* Turn OFF UNSED clock sources */
	ret = RCC_CLK_source_disable(HSE);
	ret = RCC_CLK_source_disable(PLL);
	/* Enable Periphral */
	RCC_Periphral_Group_enable();

#elif sys_clock_source == HSE

		/* Enable clock source */
		ret = RCC_CLK_source_enable(HSE);
		/* SET clock source as sys clock & check is it ready or not */
		ret = RCC_Sys_CLK_SET(HSE);
		/* Busses Prescaler Select*/
		ret = RCC_CLK_Busses_Prescaler(APB1,APB1_Prescaler_init);
		ret = RCC_CLK_Busses_Prescaler(APB2,APB2_Prescaler_init);
		ret = RCC_CLK_Busses_Prescaler(AHB1,AHB_Prescaler_init);
		/* Turn OFF UNSED clock sources */
		ret = RCC_CLK_source_disable(HSI);
		ret = RCC_CLK_source_disable(PLL);
		/* Enable Periphral */
		RCC_Periphral_Group_enable();

#elif sys_clock_source == PLL

			/* Turn ON Pre configered source for PLL
			 * @RCC_config */

			/* Enable DEFUALT clock source */
			ret = RCC_CLK_source_enable(HSI);
			/* SET clock source as sys clock & check is it ready or not */
			ret = RCC_Sys_CLK_SET(HSI);
			/* TURN OFF PLL */
			 PLL_Source_Disable();
			 /*Check clock source for the PLL */
			ret = RCC_CLK_source_enable(PLL_clock_source);
			    //ret = RCC_PLL_CLK_source_SET(PLL_clock_source); NOT SURE YET :)
			/*PLL Factors Selecting (P_fact , N_fact , M_fact ,  Q_fact ) */
			ret = RCC_PLL_SET_FACTORS(PLL_P_FACT,PLL_N_FACT,PLL_M_FACT,PLL_Q_FACT);
			/* Busses Prescaler Select*/
			ret = RCC_CLK_Busses_Prescaler(APB1,APB1_Prescaler_init);
			ret = RCC_CLK_Busses_Prescaler(APB2,APB2_Prescaler_init);
			ret = RCC_CLK_Busses_Prescaler(AHB1,AHB_Prescaler_init);
			/* Enable PLL clock */
			ret = RCC_CLK_source_enable(PLL);
			/* SET PLL as SYS clock */
			ret = RCC_Sys_CLK_SET(PLL);


		#endif

			return ret;

}


Std_ReturnType RCC_Sys_CLK_SET(uint8_t Copy_clk_source){

	Std_ReturnType ret = E_NOT_OK ;
	uint8_t ready_check = RCC_CLK_RDY_Status_check(Copy_clk_source);
	if(Copy_clk_source < HSI || Copy_clk_source > PLL || !(ready_check) )
		{
			ret = E_OUT_RANGE;
			return ret;
		}
		else
		{
			switch(Copy_clk_source)
			{
			case HSI :
				CLEAR_BIT(RCC->CFGR,CFGR_SW0_bit) ;
				CLEAR_BIT(RCC->CFGR,CFGR_SW1_bit) ; break;
			case HSE :
				SET_BIT(RCC->CFGR,CFGR_SW0_bit) ;
				CLEAR_BIT(RCC->CFGR,CFGR_SW1_bit) ; break;
			case PLL :
				CLEAR_BIT(RCC->CFGR,CFGR_SW0_bit) ;
				SET_BIT(RCC->CFGR,CFGR_SW1_bit) ; break;
			}
		}


	return ret;
}


Std_ReturnType RCC_CLK_RDY_Status_check(uint8_t Copy_clk_source){

	Std_ReturnType ret = E_NOT_OK ;
	uint8_t rdy_bit_number = 0;
	uint8_t rdy_status = NO_RDY;
	uint8_t busy_wait_counter = 0 ;

	if(Copy_clk_source < HSI || Copy_clk_source > PLL )
	{
		ret = E_OUT_RANGE;
		return ret;
	}
	else
	{
		switch(Copy_clk_source)
		{
		case HSI : rdy_bit_number = CR_HSI_RDY_Bit ; break;
		case HSE : rdy_bit_number = CR_HSE_RDY_Bit ; break;
		case PLL : rdy_bit_number = CR_PLL_RDY_Bit ; break;
		}
		do{
			rdy_status = READ_BIT(RCC->CR,rdy_bit_number);
			busy_wait_counter++;
		}while((rdy_status == NO_RDY) && (busy_wait_counter< rdy_busy_wait_time));

		ret = E_OK;
	}

		return ret;

}

Std_ReturnType RCC_CLK_SET_re_check(uint8_t Copy_clk_source){

	Std_ReturnType ret = E_NOT_OK ;

		if( ( (RCC->CFGR >> 2) & Copy_clk_source ) != Copy_clk_source )
		{
			ret = E_NOT_OK;
			return ret;
		}
		else
		{

			ret = E_OK;
		}

			return ret;

}

Std_ReturnType RCC_CLK_source_enable(uint8_t Copy_clk_source){

	Std_ReturnType ret = E_NOT_OK ;

			if(Copy_clk_source < HSI || Copy_clk_source > PLL )
			{
				ret = E_NOT_OK;
				return ret;
			}
			else
			{
				switch(Copy_clk_source)
				{
				case HSI :
					SET_BIT(RCC->CR,CR_HSI_ON_Bit) ; break;
				case HSE :
					SET_BIT(RCC->CR,CR_HSE_ON_Bit) ; break;
				case PLL :
					SET_BIT(RCC->CR,CR_PLL_ON_Bit) ; break;
				}
				ret = E_OK;
			}

				return ret;
}

Std_ReturnType RCC_CLK_source_disable(uint8_t Copy_clk_source){

	Std_ReturnType ret = E_NOT_OK ;

	if(Copy_clk_source < HSI || Copy_clk_source > PLL )
				{
					ret = E_NOT_OK;
					return ret;
				}
				else
				{
					switch(Copy_clk_source)
					{
					case HSI :
						CLEAR_BIT(RCC->CR,CR_HSI_ON_Bit) ; break;
					case HSE :
						CLEAR_BIT(RCC->CR,CR_HSE_ON_Bit) ; break;
					case PLL :
						CLEAR_BIT(RCC->CR,CR_PLL_ON_Bit) ; break;
					}
					ret = E_OK;
				}

					return ret;
}

Std_ReturnType RCC_CLK_Busses_Prescaler(Busses_t Copy_bus_name , uint8_t Prescaler_value){

	Std_ReturnType ret = E_NOT_OK ;
	uint8_t Local_precaler = Prescaler_value;

		if(Copy_bus_name < APB1 || Copy_bus_name > AHB1 )
					{
						ret = E_NOT_OK;
						return ret;
					}
					else
					{
						switch(Copy_bus_name)
						{
						case APB1 : if(Prescaler_value>APB_1_Prescaler_16_division) Local_precaler = APB_1_Prescaler_16_division ;
							RCC->CFGR &= ~(Clear_mask_3_Bits << 10 ); RCC->CFGR |= (Local_precaler << 10 ) ; break;
						case APB2 : if(Prescaler_value>APB_2_Prescaler_16_division) Local_precaler = APB_2_Prescaler_16_division ;
							RCC->CFGR &= ~(Clear_mask_3_Bits << 13 ); RCC->CFGR |= (Local_precaler << 13 ) ; break;
						case AHB1 : if(Prescaler_value>AHB_Prescaler_512_division) Local_precaler = AHB_Prescaler_512_division ;
							RCC->CFGR &= ~(Clear_mask_4_Bits << 4 ); RCC->CFGR |= (Local_precaler << 4 ) ; break;
						default : return ret;
						}

						ret = E_OK;
					}

						return ret;

}

Std_ReturnType RCC_Periphral_enable(Busses_t Copy_bus_name , uint8_t Periphral_name){

	Std_ReturnType ret = E_NOT_OK ;

			if(Copy_bus_name < APB1 || Copy_bus_name > AHB2 )
						{
							ret = E_NOT_OK;
							return ret;
						}
						else
						{
							switch(Copy_bus_name)
							{
							case APB1 : SET_BIT(RCC->APB1ENR,Periphral_name);  break;
							case APB2 : SET_BIT(RCC->APB2ENR,Periphral_name);  break;
							case AHB1 : SET_BIT(RCC->AHB1ENR,Periphral_name);  break;
							case AHB2 : SET_BIT(RCC->AHB2ENR,Periphral_name);  break;
							default : return ret;
							}

							ret = E_OK;
						}

							return ret;
}

Std_ReturnType RCC_Periphral_disable(Busses_t Copy_bus_name , uint8_t Periphral_name){

	Std_ReturnType ret = E_NOT_OK ;

			if(Copy_bus_name < APB1 || Copy_bus_name > AHB2 )
						{
							ret = E_NOT_OK;
							return ret;
						}
						else
						{
							switch(Copy_bus_name)
							{
							case APB1 : CLEAR_BIT(RCC->APB1ENR,Periphral_name);  break;
							case APB2 : CLEAR_BIT(RCC->APB2ENR,Periphral_name);  break;
							case AHB1 : CLEAR_BIT(RCC->AHB1ENR,Periphral_name);  break;
							case AHB2 : CLEAR_BIT(RCC->AHB2ENR,Periphral_name);  break;
							default : return ret;
							}

							ret = E_OK;
						}

							return ret;
}

Std_ReturnType RCC_PLL_CLK_source_SET(uint8_t Copy_clk_source){

	Std_ReturnType ret = E_NOT_OK ;

				if(Copy_clk_source < HSI || Copy_clk_source > HSE )
							{
								ret = E_NOT_OK;
								return ret;
							}
							else
							{	uint8_t PLL_enabled = PLL_Source_Check();
								if(PLL_enabled == 1){PLL_Source_Disable();} // Disables PLL before setting the configrations

								switch(Copy_clk_source)
								{
								case HSI : CLEAR_BIT(RCC->PLLCFGR,PLLSRC);  break;
								case HSE : SET_BIT(RCC->PLLCFGR,PLLSRC); 	break;

								default : return ret;
								}
								ret = E_OK;
							}

								return ret;

}

Std_ReturnType RCC_PLL_SET_FACTORS(uint8_t P_fact , uint8_t N_fact , uint8_t M_fact , uint8_t Q_fact ){

	Std_ReturnType ret = E_NOT_OK ;
	uint8_t PLL_enabled = PLL_Source_Check();

					if( (N_fact < 192 || N_fact > 432) || (M_fact < 2 || M_fact > 63) || (Q_fact < 2 || Q_fact > 15) || (P_fact < 2 || P_fact > 8 || P_fact %2 != 0 )  )
								{
									ret = E_OUT_RANGE;
									return ret;
								}
								else
								{	if(PLL_enabled == 1){PLL_Source_Disable();} // Disables PLL before setting the configrations

									RCC->PLLCFGR &= ~(Clear_mask_6_Bits << 0 )  ;
									RCC->PLLCFGR |= (M_fact << 0 )  ;

									RCC->PLLCFGR &= ~(Clear_mask_9_Bits << 6 )  ;
									RCC->PLLCFGR |= (N_fact << 6 )  ;

									RCC->PLLCFGR &= ~(Clear_mask_2_Bits << 16 )  ;
									RCC->PLLCFGR |= (P_fact << 16 ) ;

									RCC->PLLCFGR &= ~(Clear_mask_4_Bits << 24 )  ;
									RCC->PLLCFGR |= (Q_fact << 24 ) ;
									ret = E_OK;
								}

									return ret;
}

static void RCC_Periphral_Group_enable(){

	RCC->APB1ENR = APB1_Periphrals_Group_Value ;
	RCC->APB2ENR = APB2_Periphrals_Group_Value ;
	RCC->AHB1ENR = AHB1_Periphrals_Group_Value ;
	RCC->AHB2ENR = AHB2_Periphrals_Group_Value ;
}

