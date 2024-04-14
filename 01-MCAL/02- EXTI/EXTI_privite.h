/**************** EXTI_privite.h ****************/
/***************  Author : Abdelhady Elshahat */
/**************  Layer   : MCAL       ********/
/**************  SWC     : EXTI        ********/
/**************  Date    : 03/08/2023 ********/
/**************  Version : 1.0        ********/
/**************                       ********/
/********************************************/

#ifndef EXTI_PRIVITE_H_
#define EXTI_PRIVITE_H_


/* REGs definirion */



/* PIE */
#define EXTI_u8_GICR           *((volatile u8 *)0x5b)
/* BITS for PIE*/
#define EXTI_u8_GICR_PIE_INT0      6
#define EXTI_u8_GICR_PIE_INT1      7
#define EXTI_u8_GICR_PIE_INT2      5



/* PIF */
#define EXTI_u8_GIFR           *((volatile u8 *)0x5a)

/* MCUCR*/
#define EXTI_u8_MCUCR           *((volatile u8 *)0x55)
/* BITS for MCUCR*/
#define ISC2	6

/* MCUCSR*/
#define EXTI_u8_MCUCSR          *((volatile u8 *)0x54)
/* BITS in MCUCR */
#define ISC00     0
#define ISC01     1
#define ISC10     2
#define ISC11     3


#endif 