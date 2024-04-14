/************* TIMER SW Module / Driver ***********/
/************* Layer : MCAL **********************/
/************* File : Timer_prog.c ***********/
/************ Author : Abdelhady ****************/
/************ Date : 20/ 11 / 2023 *************/
/*********** version 1.1 **********************/
/*********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Timer_interface.h"
#include "Timer_privite.h"
#include "Timer_config.h"

/* Interrupt State */
static u8 Timer0_INT_FUNC_State = NORMAL_STATE ;

static void (*Timers_pfTImer0OVFGlobalSETCalllBack[2]) (void) = {NULL};

static u32 Timer0_OVF_Counts = 0 ;

void Timers_voidTimer0Init(void )
{

	/* Select the mode */

	#if TIMER0_OPREATION_MODE == TIMER_NORMAL_MODE
		CLR_BIT(TIMER_u8_T0_TCCR0_REG,TIMER_u8_T0_TTCR0_REG_WGM00_BIT);
		CLR_BIT(TIMER_u8_T0_TCCR0_REG,TIMER_u8_T0_TTCR0_REG_WGM01_BIT);

		/*SET Preload value */
		TIMER_u8_T0_TCNT0_REG = TIMER_u8_PRELOAD_VALUE ;

			/* OVF interrupt mode */
			#if TIMER0_OVF_INTERRUPT_MODE == INTERRUPT_DISABLE

					CLR_BIT(TIMER_u8_TIMSK_REG,TIMER_u8_T0_TOIE0);

			#elif TIMER0_OVF_INTERRUPT_MODE == INTERRUPT_ENABLED

					SET_BIT(TIMER_u8_TIMSK_REG,TIMER_u8_T0_TOIE0);
			#endif

	#elif TIMER0_OPREATION_MODE == TIMER_CTC_MODE
		CLR_BIT(TIMER_u8_T0_TCCR0_REG,TIMER_u8_T0_TTCR0_REG_WGM00_BIT);
		SET_BIT(TIMER_u8_T0_TCCR0_REG,TIMER_u8_T0_TTCR0_REG_WGM01_BIT);

		/* SET the COMPARE MATCH value */
		TIMER_u8_T0_OCR0_REG = TIMER_OCR0_VALUE ;
		/* OVF interrupt mode */
			#if TIMER0_CTC_INTERRUPT_MODE == INTERRUPT_DISABLE

					CLR_BIT(TIMER_u8_TIMSK_REG,TIMER_u8_T0_TOIE0);

			#elif TIMER0_CTC_INTERRUPT_MODE == INTERRUPT_ENABLED

					SET_BIT(TIMER_u8_TIMSK_REG,TIMER_u8_T0_OCIE0);
			#endif


	#elif TIMER0_OPREATION_MODE == TIMER_FAST_PWM_MODE
		SET_BIT(TIMER_u8_T0_TCCR0_REG,TIMER_u8_T0_TTCR0_REG_WGM00_BIT);
		SET_BIT(TIMER_u8_T0_TCCR0_REG,TIMER_u8_T0_TTCR0_REG_WGM01_BIT);

		/* choose PWM WAVE SHAPE*/

			#if OC0_PIN_MODE == OC0_PIN_DISCONECTED
				CLR_BIT(TIMER_u8_T0_TCCR0_REG,TIMER_u8_T0_TTCR0_REG_COM01_BIT);
				CLR_BIT(TIMER_u8_T0_TCCR0_REG,TIMER_u8_T0_TTCR0_REG_COM00_BIT);

			#elif OC0_PIN_MODE == CLR_ON_COPMARE_SET_AT_TOP
				SET_BIT(TIMER_u8_T0_TCCR0_REG,TIMER_u8_T0_TTCR0_REG_COM01_BIT);
				CLR_BIT(TIMER_u8_T0_TCCR0_REG,TIMER_u8_T0_TTCR0_REG_COM00_BIT);

			#elif OC0_PIN_MODE == SET_ON_COPMARE_CLR_AT_TOP
				SET_BIT(TIMER_u8_T0_TCCR0_REG,TIMER_u8_T0_TTCR0_REG_COM01_BIT);
				SET_BIT(TIMER_u8_T0_TCCR0_REG,TIMER_u8_T0_TTCR0_REG_COM00_BIT);
			#endif
	
	#elif ITMER0_OPREATION_MODE == TIMER_PHASE_CORRECT_PWM_MODE
		SET_BIT(TIMER_u8_T0_TCCR0_REG,TIMER_u8_T0_TTCR0_REG_WGM00_BIT);
		CLR_BIT(TIMER_u8_T0_TCCR0_REG,TIMER_u8_T0_TTCR0_REG_WGM01_BIT);

			/* choose PWM WAVE SHAPE*/
			#if OC0_PIN_MODE == OC0_PIN_DISCONECTED
				CLR_BIT(TIMER_u8_T0_TCCR0_REG,TIMER_u8_T0_TTCR0_REG_COM01_BIT);
				CLR_BIT(TIMER_u8_T0_TCCR0_REG,TIMER_u8_T0_TTCR0_REG_COM00_BIT);

			#elif OC0_PIN_MODE == CLR_ON_COPMARE_SET_AT_TOP
				SET_BIT(TIMER_u8_T0_TCCR0_REG,TIMER_u8_T0_TTCR0_REG_COM01_BIT);
				CLR_BIT(TIMER_u8_T0_TCCR0_REG,TIMER_u8_T0_TTCR0_REG_COM00_BIT);

			#elif OC0_PIN_MODE == SET_ON_COPMARE_CLR_AT_TOP
				SET_BIT(TIMER_u8_T0_TCCR0_REG,TIMER_u8_T0_TTCR0_REG_COM01_BIT);
				SET_BIT(TIMER_u8_T0_TCCR0_REG,TIMER_u8_T0_TTCR0_REG_COM00_BIT);
			#endif


	#endif
	
	
	/*PRE scaling clock  */
	/* 1- clearing the previous scaling value
	 * 2- Assign the PRE scaling value
	 * */
	TIMER_u8_T0_TCCR0_REG &= PRE_SCALING_MASK ;
	TIMER_u8_T0_TCCR0_REG |= PRE_SCALING_VLUE ;
	
	
}	


void Timers_voidTimer0SetOCR0Value (u8 Copy_u8OCR0Value)
{


	TIMER_u8_T0_OCR0_REG = Copy_u8OCR0Value ;
}

void Timers_voidTimer0SetPreLoadValue (u8 Copy_u8PreloadValue)
{

	TIMER_u8_T0_TCNT0_REG = Copy_u8PreloadValue ;

}


u8 Timers_voidTimer0SetCallBackFun ( void (*Copy_pfCallBack) (void) ,u8 Copy_u8ID )
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	
	if (*Copy_pfCallBack != NULL)
	{
		Timers_pfTImer0OVFGlobalSETCalllBack[Copy_u8ID] = Copy_pfCallBack ;
	}
	else 
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState ; 
	
	
	
	
	
}

u8 Timer0_u8DelayMs (u32 Copy_u8DelayMs , void (*NotificationFunc)(void) )
{
	u8 Local_u8LocalErrorState = STD_TYPES_NOK;
	if (NotificationFunc != NULL )
	{
		/* tick time must be 1 microseconds for correct calculations
		 * select OCR0 value that make calculations easy I choice 100
		 *
		 * */
		Timers_voidTimer0SetOCR0Value (150);

		/* convert milliseconds to microseconds*/
		u32 Local_u8DElayMicroSec = Copy_u8DelayMs * 1000 ;

		/* calculate the Numbers of OVF */
		Timer0_OVF_Counts = Local_u8DElayMicroSec / 100 ;

		/* set callback the notification function*/
		Timers_pfTImer0OVFGlobalSETCalllBack[1] = NotificationFunc ;

		/* The interrupt function using delay state  */
		Timer0_INT_FUNC_State = DELAY_STATE  ;

		/* set Pre scalling value to En the timer  */
		Timer0_voidSetPrescaller (PRE_SCALING_VLUE);

		Local_u8LocalErrorState = STD_TYPES_OK;

	}




	return Local_u8LocalErrorState ;
}

void Timer0_voidSetPrescaller (u8 copy_u8PrescallingValue)
{
	/*PRE scaling clock  */
		/* 1- clearing the previous scaling value
		 * 2- Assign the PRE scaling value
		 * */
		TIMER_u8_T0_TCCR0_REG &= PRE_SCALING_MASK ;
		TIMER_u8_T0_TCCR0_REG |= copy_u8PrescallingValue ;


}



void __vector_10 (void) __attribute__((signal)) ;
void __vector_10 (void)
{

	switch(Timer0_INT_FUNC_State)
	{

		case DELAY_STATE :
			if (Timers_pfTImer0OVFGlobalSETCalllBack[1]!= NULL )
			{
				static u32 Local_u32Counter = 0;
				if (Local_u32Counter == Timer0_OVF_Counts)
				{
					Local_u32Counter = 0 ;
					Timers_pfTImer0OVFGlobalSETCalllBack[1]();
					Timer0_INT_FUNC_State = NORMAL_STATE ;

				}
				else
				{
					Local_u32Counter++ ;

				}

			}

			break;

		case NORMAL_STATE :

			Timers_pfTImer0OVFGlobalSETCalllBack[1]();
			break;

	}

}











/*prototype for ISR for T0 OVF */
void __vector_11 (void) __attribute__((signal)) ;

void __vector_11 (void)
{
	static u16 Local_Timer0OVFCounter = 0 ; 
	Local_Timer0OVFCounter ++;
	
	if (Local_Timer0OVFCounter == 3907)
	{
		/* Preload value*/
		TIMER_u8_T0_TCNT0_REG = 192 ;
		/* intite the counter */
		Local_Timer0OVFCounter = 0 ; 	 
	
	/* calling the applicaion function*/
		if (*Timers_pfTImer0OVFGlobalSETCalllBack[0] != NULL)
			{
				Timers_pfTImer0OVFGlobalSETCalllBack[0] ();
			}
		
	}
	
	
	
}
void Timers_voidTimer1Init(void )
{
	/** chosse the mode Numer 14 Fast PWM with top of ICR1 **/
	SET_BIT(TIMER_u8_T1_TCCR1A_REG,TIMER_u8_T1_TCCR1A_REG_WGM11_BIT);
	CLR_BIT(TIMER_u8_T1_TCCR1A_REG,TIMER_u8_T1_TCCR1A_REG_WGM10_BIT);
	SET_BIT(TIMER_u8_T1_TCCR1B_REG,TIMER_u8_T1_TCCR1B_REG_WGM13_BIT);
	SET_BIT(TIMER_u8_T1_TCCR1B_REG,TIMER_u8_T1_TCCR1B_REG_WGM12_BIT);


	/*** choose the oc1A pin output = NON inverting *************/

	SET_BIT(TIMER_u8_T1_TCCR1A_REG,TIMER_u8_T1_TCCR1A_REG_COM1A1_BIT);
	CLR_BIT(TIMER_u8_T1_TCCR1A_REG,TIMER_u8_T1_TCCR1A_REG_COM1A0_BIT);

	/*  set ICR1 with value **/


	TIMER_u16_T1_ICR1_REG = 19999 ; /* this vale represent T period of 20msec*/

	/* set the OCR1A value **********/
	TIMER_u16_T1_OCR1A_REG = 1600 ; /* value REP 1m SEC Ton*/

	/* choosing the PRESCALLER = 8 */
	CLR_BIT(TIMER_u8_T1_TCCR1B_REG,TIMER_u8_T1_TCCR1B_REG_CS12_BIT);
	SET_BIT(TIMER_u8_T1_TCCR1B_REG,TIMER_u8_T1_TCCR1B_REG_CS11_BIT);
	CLR_BIT(TIMER_u8_T1_TCCR1B_REG,TIMER_u8_T1_TCCR1B_REG_CS10_BIT);

}
