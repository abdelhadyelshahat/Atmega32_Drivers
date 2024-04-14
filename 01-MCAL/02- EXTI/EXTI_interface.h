/***************  Author : Abdelhady Elshahat */
/**************  Layer   : MCAL       ********/
/**************  SWC     : EXTI        ********/
/**************  Date    : 03/08/2023 ********/
/**************  Version : 1.0        ********/
/**************                       ********/
/********************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/* Macros for index*/
#define EXTI_u8_INT0   0
#define EXTI_u8_INT1   1
#define EXTI_u8_INT2   2

/* macros for SOC Trigger */

#define EXTI_u8_FALLING_EDGE              0
#define EXTI_u8_LOW_EDGE                  1
#define EXTI_u8_RISING_EDGE               2
#define EXTI_u8_ANY_CHANGE_EDGE           3


u8 EXTI_u8EXTIEnable(u8 Copy_u8EXTIIndex, u8 Copy_EXTISOCTrigger);

u8 EXTI_u8EXTIDisable (u8 Copy_u8EXTIIndex) ;

u8 EXTI_u8SetCallback ( u8 Copy_u8EXTIIndex, void (* Copy_PF) (void) );


#endif