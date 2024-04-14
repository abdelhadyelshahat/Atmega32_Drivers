/***************  Author : Abdelhady Elshahat */
/**************  Layer   : MCAL       ********/
/**************  SWC     : EXTI        ********/
/**************  Date    : 03/08/2023 ********/
/**************  Version : 1.0        ********/
/**************                       ********/
/********************************************/


/* LIB includes*/
#include "STD_TYPES.h"
#include  "BIT_MATH.h"

/*MCAL includes */
#include "EXTI_interface.h"
#include "EXTI_privite.h"
#include "EXTI_config.h"

static void (* EXTI_APF[3]) (void) = {NULL,NULL,NULL};

u8 EXTI_u8SetCallback ( u8 Copy_u8EXTIIndex, void (* Copy_PF) (void) )
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;
	
	if ((Copy_u8EXTIIndex < EXTI_u8_INT2) && (Copy_PF != NULL)  )
	{
		
		EXTI_APF[Copy_u8EXTIIndex] = Copy_PF ;
		
	}
	
	else 
	{
		u8 Local_u8ErrorState = STD_TYPES_NOK ;
	}
	
	return Local_u8ErrorState;

}


u8 EXTI_u8EXTIEnable(u8 Copy_u8EXTIIndex, u8 Copy_EXTISOCTrigger)
{
	
	u8 Local_ErrorState = STD_TYPES_OK ;
	
	switch (Copy_u8EXTIIndex)
	{
		case EXTI_u8_INT0 :
			switch (Copy_EXTISOCTrigger)
			{
				case EXTI_u8_FALLING_EDGE :

					/* Tigger SOC*/
					SET_BIT(EXTI_u8_MCUCR,ISC01);
					CLR_BIT(EXTI_u8_MCUCR,ISC00);
					
					/* Enable EXTI0*/
					SET_BIT(EXTI_u8_GICR,EXTI_u8_GICR_PIE_INT0);
				break;
				
				
				
				case EXTI_u8_LOW_EDGE :
					/* Tigger SOC*/
					CLR_BIT(EXTI_u8_MCUCR,ISC01);
					CLR_BIT(EXTI_u8_MCUCR,ISC00);
					
					/* Enable EXTI0*/
					SET_BIT(EXTI_u8_GICR,EXTI_u8_GICR_PIE_INT0);
				break;
				
				case EXTI_u8_RISING_EDGE :
					/* Tigger SOC*/
					SET_BIT(EXTI_u8_MCUCR,ISC01);
					SET_BIT(EXTI_u8_MCUCR,ISC00);
					
					/* Enable EXTI0*/
					SET_BIT(EXTI_u8_GICR,EXTI_u8_GICR_PIE_INT0);			
				break;
				
				case EXTI_u8_ANY_CHANGE_EDGE :
				
					/* Tigger SOC*/
					CLR_BIT(EXTI_u8_MCUCR,ISC01);
					SET_BIT(EXTI_u8_MCUCR,ISC00);
					
					/* Enable EXTI0*/
					SET_BIT(EXTI_u8_GICR,EXTI_u8_GICR_PIE_INT0);
				break;
				
				default :
					Local_ErrorState = STD_TYPES_NOK;
				break;
				
			}
		break;
		
		
		case EXTI_u8_INT1 :
			switch (Copy_EXTISOCTrigger)
			{
				case EXTI_u8_FALLING_EDGE :
					/* Tigger SOC*/
					SET_BIT(EXTI_u8_MCUCR,ISC11);
					CLR_BIT(EXTI_u8_MCUCR,ISC10);
					
					/* Enable EXTI0*/
					SET_BIT(EXTI_u8_GICR,EXTI_u8_GICR_PIE_INT1);
				break;
				
				
				
				case EXTI_u8_LOW_EDGE :
					/* Tigger SOC*/
					CLR_BIT(EXTI_u8_MCUCR,ISC11);
					CLR_BIT(EXTI_u8_MCUCR,ISC10);
					
					/* Enable EXTI0*/
					SET_BIT(EXTI_u8_GICR,EXTI_u8_GICR_PIE_INT1);
				break;
				
				case EXTI_u8_RISING_EDGE :
					/* Tigger SOC*/
					SET_BIT(EXTI_u8_MCUCR,ISC11);
					SET_BIT(EXTI_u8_MCUCR,ISC10);
					
					/* Enable EXTI0*/
					SET_BIT(EXTI_u8_GICR,EXTI_u8_GICR_PIE_INT1);			
				break;
				
				case EXTI_u8_ANY_CHANGE_EDGE :
				
					/* Tigger SOC*/
					CLR_BIT(EXTI_u8_MCUCR,ISC11);
					SET_BIT(EXTI_u8_MCUCR,ISC10);
					
					/* Enable EXTI0*/
					SET_BIT(EXTI_u8_GICR,EXTI_u8_GICR_PIE_INT1);
				break;
				
				default :
					Local_ErrorState = STD_TYPES_NOK;
				break;
				
			}
			
		break;

		case EXTI_u8_INT2 :
			switch(Copy_EXTISOCTrigger)
			{
					
				case EXTI_u8_FALLING_EDGE :
					CLR_BIT(EXTI_u8_MCUCSR,ISC2);
					/* EN EXTI2 */
					SET_BIT(EXTI_u8_GICR,EXTI_u8_GICR_PIE_INT2);
				break ;
						
				case EXTI_u8_RISING_EDGE :
					SET_BIT(EXTI_u8_MCUCSR,ISC2);
					SET_BIT(EXTI_u8_GICR,EXTI_u8_GICR_PIE_INT2);
				break ;	
						
				default : 
					Local_ErrorState = STD_TYPES_NOK;
				break;		
			}
			
		break;
		
		default :
			Local_ErrorState = STD_TYPES_NOK;
		break;	
	
		
	}
		
	return Local_ErrorState; 
	
}


u8 EXTI_u8EXTIDisable (u8 Copy_u8EXTIIndex) 
{
	
	u8 Local_u8ErrorState = STD_TYPES_OK ; 
	
	switch (Copy_u8EXTIIndex)
	{
		case EXTI_u8_INT0 :
			CLR_BIT(EXTI_u8_GICR, EXTI_u8_GICR_PIE_INT0);
		break ;
		
		case EXTI_u8_INT1 :
			CLR_BIT(EXTI_u8_GICR, EXTI_u8_GICR_PIE_INT1);
		break ;
		
		case EXTI_u8_INT2 :
			CLR_BIT(EXTI_u8_GICR, EXTI_u8_GICR_PIE_INT2);
		break ;
		
		default	 : Local_u8ErrorState = STD_TYPES_NOK ;	break;
	}

	return Local_u8ErrorState ;
	
}


void __vector_1 (void) __attribute__((signal));

void __vector_1 (void)
{
	
	EXTI_APF[EXTI_u8_INT0] () ;
	
	
}


void __vector_2 (void) __attribute__((signal));

void __vector_2 (void)
{
	
	
	EXTI_APF[EXTI_u8_INT1] () ;
	
}



void __vector_3 (void) __attribute__((signal));

void __vector_3 (void)
{
	
	EXTI_APF[EXTI_u8_INT2] () ;
	
	
}








