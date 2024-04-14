/************* TIMER SW Module / Driver ***********/
/************* Layer : MCAL **********************/
/************* File : Timer_iprivite.h***********/
/************ Author : Abdelhady ****************/
/************ Date : 20/ 11 / 2023 *************/
/*********** version 1.1 **********************/
/*********************************************/

#ifndef TIMER_PRIVITE_H_ 
#define TIMER_PRIVITE_H_

/******************** REG definitions *************/
/********************** TCFR REG &its bits **************************/
#define TIMER_u8_T0_TCCR0_REG  *((volatile u8*)0x53)

#define TIMER_u8_T0_TTCR0_REG_WGM00_BIT 6
#define TIMER_u8_T0_TTCR0_REG_WGM01_BIT 3
#define TIMER_u8_T0_TTCR0_REG_COM01_BIT 5
#define TIMER_u8_T0_TTCR0_REG_COM00_BIT 4
#define TIMER_u8_T0_TTCR0_REG_CS00_BIT  0
#define TIMER_u8_T0_TTCR0_REG_CS01_BIT  1
#define TIMER_u8_T0_TTCR0_REG_CS02_BIT  2
/*******************************************************************/			
#define TIMER_u8_T0_TCNT0_REG  *((volatile u8*)0x52)
			
#define TIMER_u8_T0_OCR0_REG  *((volatile u8*)0x5C)

/*******************************************************/			 
#define TIMER_u8_TIMSK_REG    *((volatile u8*)0x59)

#define TIMER_u8_T0_TOIE0         0
#define TIMER_u8_T0_OCIE0         1
/****************************************************/
#define TIMER_u8_TIFR_REG     *((volatile u8*)0x58)


 /********************** Timer1 Reg*********************************/
#define TIMER_u8_T1_TCCR1A_REG *((volatile u8*)0x4F)
#define TIMER_u8_T1_TCCR1B_REG *((volatile u8*)0x4E)
#define TIMER_u8_T1_TCCR1B_REG_WGM13_BIT 4
#define TIMER_u8_T1_TCCR1B_REG_WGM12_BIT 3
#define TIMER_u8_T1_TCCR1A_REG_WGM11_BIT 1
#define TIMER_u8_T1_TCCR1A_REG_WGM10_BIT 0
#define TIMER_u8_T1_TCCR1A_REG_COM1A1_BIT 7
#define TIMER_u8_T1_TCCR1A_REG_COM1A0_BIT 6
#define TIMER_u8_T1_TCCR1B_REG_CS12_BIT 2
#define TIMER_u8_T1_TCCR1B_REG_CS11_BIT 1
#define TIMER_u8_T1_TCCR1B_REG_CS10_BIT 0

#define TIMER_u8_T1_TCNT1H_REG *((volatile u8*)0x4D)
#define TIMER_u8_T1_TCNT1L_REG *((volatile u8*)0x4C)
#define TIMER_u16_T1_TCNT1_REG *((volatile u16*)0x4C)

#define TIMER_u8_T1_OCR1AH_REG *((volatile u8*)0x4B)
#define TIMER_u8_T1_OCR1AL_REG *((volatile u8*)0x4A)
#define TIMER_u16_T1_OCR1A_REG *((volatile u16*)0x4A)

#define TIMER_u8_T1_ICR1H_REG *((volatile u8*)0x47)
#define TIMER_u8_T1_ICR1L_REG *((volatile u8*)0x46)
#define TIMER_u16_T1_ICR1_REG *((volatile u16*)0x46)

/*********************** Private macros *******************************/
#define TIMER_NORMAL_MODE            1
#define TIMER_CTC_MODE               2
#define TIMER_FAST_PWM_MODE          3
#define TIMER_PHASE_CORRECT_PWM_MODE 4



/* macros for OC0 PIN MODE */
#define OC0_PIN_DISCONECTED         1
#define CLR_ON_COPMARE_SET_AT_TOP   2
#define SET_ON_COPMARE_CLR_AT_TOP   3

/* macros for interrupt */
#define INTERRUPT_DISABLE  1
#define INTERRUPT_ENABLED  2

/* macros for PRE SCALLING values */
#define PRE_SCALING_DISABLED                 0
#define PRE_SCALING_OVER_1            		 1
#define PRE_SCALING_OVER_8                   2
#define PRE_SCALING_OVER_64                  3
#define PRE_SCALING_OVER_256                 4
#define PRE_SCALING_OVER_1024                5
#define EXT_CLK_DOC_TRIGGER_ON_FALLING       6
#define EXT_CLK_DOC_TRIGGER_ON_RISING        7

/* macros for interrupt state  */
#define DELAY_STATE                          1
#define NORMAL_STATE                         2



#endif 
