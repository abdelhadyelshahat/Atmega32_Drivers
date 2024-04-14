/*********************************************/
/********* ADC_PROG_C ***********************/
/********* SWC : ADC ***********************/
/********* Layer : MCAL *******************/
/********* Author : Abdelhady Elshahat ***/
/********* Date : 30 / 10 / 2023 ********/
/********* version : 1.0 ***************/
/**************************************/


/*LIB includes*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL includes */
#include "ADC_config.h"
#include "ADC_privite.h"
#include "ADC_interface.h"

static  void (*ADC_pfNotification) (u16);

static u8 ADC_u8ADCStatue = ADC_u8_NOT_BUSY ;


 void ADC_voidInit (void)
{
	/* steps for intialzation 
	
	1- select Vref
	2- R or L Adjust
	3- single or free running (Dis OR EN Auto trigger)
	4- select Prescaller ( /64 if 10 bit resolution)
	5- Enable ADC
	*/
	
    /* 1- select Vref  */ 	
	
#if ADC_u8_Voltage_REF == ADC_u8_AREF

		CLR_BIT(ADC_u8_ADMUX_REG,REFS1_BIT);
		CLR_BIT(ADC_u8_ADMUX_REG,REFS0_BIT);
		
	#elif ADC_u8_Voltage_REF == ADC_u8_AVCC
		
		CLR_BIT(ADC_u8_ADMUX_REG,REFS1_BIT);
		SET_BIT(ADC_u8_ADMUX_REG,REFS0_BIT);
		
	#elif ADC_u8_Voltage_REF == ADC_u8_INTERNAL

		SET_BIT(ADC_u8_ADMUX_REG,REFS1_BIT);
		SET_BIT(ADC_u8_ADMUX_REG,REFS0_BIT);
		
	#endif 	
	
	/* 2- select R or L Adjust */
	
	#if ADC_u8_ADJUST == ADC_u8_RIGHT_ADJUST
		CLR_BIT(ADC_u8_ADMUX_REG,ADLAR_BIT);
		
	#elif ADC_u8_ADJUST == ADC_u8_LEFT_ADJUST 
		SET_BIT(ADC_u8_ADMUX_REG,ADLAR_BIT);
	#endif
	
	
	/* 3- select conversin mode (Auto trigger)*/
	#if ADC_u8_AUTO_TIGGER == ADC_u8_AUTO_TIGGER_DISABLE 
		CLR_BIT(ADC_u8_ADCSRA_REG , ADATE_BIT);
	#elif ADC_u8_AUTO_TIGGER == ADC_u8_AUTO_TIGGER_ENABLE 
		SET_BIT(ADC_u8_ADCSRA_REG , ADATE_BIT);
	#endif
	
	
	/*4- select prescaller */
	#if ADC_u8_PRESCALLER == ADC_u8_PRESCALLER_32
		SET_BIT(ADC_u8_ADCSRA_REG,ADPS2_BIT);
		CLR_BIT(ADC_u8_ADCSRA_REG,ADPS1_BIT);
		SET_BIT(ADC_u8_ADCSRA_REG,ADPS0_BIT);
	#elif ADC_u8_PRESCALLER == ADC_u8_PRESCALLER_64
		SET_BIT(ADC_u8_ADCSRA_REG,ADPS2_BIT);
		SET_BIT(ADC_u8_ADCSRA_REG,ADPS1_BIT);
		CLR_BIT(ADC_u8_ADCSRA_REG,ADPS0_BIT);
	#elif ADC_u8_PRESCALLER == ADC_u8_PRESCALLER_128
		SET_BIT(ADC_u8_ADCSRA_REG,ADPS2_BIT);
		SET_BIT(ADC_u8_ADCSRA_REG,ADPS1_BIT);
		SET_BIT(ADC_u8_ADCSRA_REG,ADPS  0_BIT);
	#endif
	
	/* 5- Enable ADC */
	SET_BIT(ADC_u8_ADCSRA_REG,ADEN_BIT);
}

u8 ADC_u8GetDigitalValueSyncNoBlocking (u8 Copy_u8ChannelNumber, u16 * Copy_Pu16DigitalValue )
{
	
	u8 Local_u8ErrorState = STD_TYPES_OK ;
	u32 Local_u32TimingOutCounter = STD_TYPES_NOK;
	
	if ( (Copy_u8ChannelNumber <= ADC_u8_CHANNEL_31) && (Copy_Pu16DigitalValue != NULL ))
	{
		/* Cear  ADC_u8_ADMUX_REG from any previous values*/
		ADC_u8_ADMUX_REG &= ADC_u8_ADMUX_REG_CH_CLEAR;
		/* select for channel */
		ADC_u8_ADMUX_REG |= Copy_u8ChannelNumber ;
		
		/* ADC start conversion */
		SET_BIT(ADC_u8_ADCSRA_REG,ADSC_BIT);
		
		/* pooling on EOC flaf  with timing out counter */
		while ((!GET_BIT(ADC_u8_ADCSRA_REG,ADIF_BIT)) && (Local_u32TimingOutCounter < ADC_u32_TIMING_OUT_MAX_VALUE) ) ;
		{
			Local_u32TimingOutCounter++;
		}
		
		if (GET_BIT(ADC_u8_ADCSRA_REG,ADIF_BIT) != 0) /* another condition (Local_u32TimingOutCounter < ADC_u32_TIMING_OUT_MAX_VALUE)*/
		{
			/* CLR EOC flag*/
			CLR_BIT(ADC_u8_ADCSRA_REG,ADIF_BIT);

			/* getting the digital value*/
			*Copy_Pu16DigitalValue = ADC_u16_ADC_WORD_REG ;

		}
		else
		{
			Local_u8ErrorState = STD_TYPES_NOK;
		}
		
			
		
	}
	 else 
	 {Local_u8ErrorState = STD_TYPES_NOK;  }
	
	
	
	return Local_u8ErrorState ;
	
}
 

u8 ADC_u8GetDigitalValueAsynch (u8 Copy_u8ChannelNumber, u8 (*Copy_PFNotification_function) (u16) )
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;

	if ((Copy_u8ChannelNumber < ADC_u8_CHANNEL_31) && (Copy_PFNotification_function != NULL) && (ADC_u8ADCStatue == ADC_u8_NOT_BUSY) )
	{
		ADC_u8ADCStatue = ADC_u8_BUSY;
		/* update pf (set the callback pf)*/
		ADC_pfNotification = Copy_PFNotification_function ;

		/*Enable the interrupt*/
		SET_BIT(ADC_u8_ADCSRA_REG,ADIE_BIT);

		/* Cear  ADC_u8_ADMUX_REG from any previous values*/
		ADC_u8_ADMUX_REG &= ADC_u8_ADMUX_REG_CH_CLEAR;

		/* select for channel */
		ADC_u8_ADMUX_REG |= Copy_u8ChannelNumber ;

		/* ADC start conversion */
		SET_BIT(ADC_u8_ADCSRA_REG,ADSC_BIT);
	}

	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState ;
}






void __vector_16 (void)  __attribute__((signal));

void __vector_16 (void)  __attribute__((signal))
{

	if (ADC_pfNotification != NULL)

	{
		/* making the ADC not busy */
		ADC_u8ADCStatue = ADC_u8_NOT_BUSY ;
		/*Disable the interrupt*/
		CLR_BIT(ADC_u8_ADCSRA_REG,ADIE_BIT);

		/*calling pf*/
		ADC_pfNotification (ADC_u16_ADC_WORD_REG);
	}
}
