/************* TIMER SW Module / Driver ***********/
/************* Layer : MCAL **********************/
/************* File : Timer_config.h***********/
/************ Author : Abdelhady ****************/
/************ Date : 20/ 11 / 2023 *************/
/*********** version 1.1 **********************/
/*********************************************/

#ifndef TIMER_CONFIG_H_ 
#define TIMER_CONFIG_H_


/*options :
 * 1- TIMER_NORMAL_MODE
 * 2- TIMER_CTC_MODE
 * 3- TIMER_FAST_PWM_MODE
 * 4- TIMER_PHASE_CORRECT_PWM_MODE
 * */


#define TIMER0_OPREATION_MODE  TIMER_CTC_MODE


/*options in Fast PWM or phase correct PWM mode
 * 1- OC0_PIN_DISCONECTED
 * 2- CLR_ON_COPMARE_SET_AT_TOP
 * 3- SET_ON_COPMARE_CLR_AT_TOP
 * */

#define OC0_PIN_MODE OC0_PIN_DISCONECTED

/* PRELOAD value options : [0 : 255]*/
#define TIMER_u8_PRELOAD_VALUE      0

/* OCR0 REG Value options :[0: 255] */
#define TIMER_OCR0_VALUE            0

/*Interrupt OVF Configuration*/
/*options :
 * 1- INTERRUPT_DISABLE
 * 2- INTERRUPT_ENABLED
 * */

#define IMER0_OVF_INTERRUPT_MODE   INTERRUPT_ENABLED


/*Interrupt CTC Configuration*/
/*options :
 * 1- INTERRUPT_DISABLE
 * 2- INTERRUPT_ENABLED
 * */

#define TIMER0_CTC_INTERRUPT_MODE   INTERRUPT_ENABLED

/* PRE scaling mask value */

#define PRE_SCALING_MASK 0b11111000

/*PRE SCALING Values
 * options :
 * 1- PRE_SCALING_DISABLED
 * 2- PRE_SCALING_OVER_1
 * 3- PRE_SCALING_OVER_8
 * 3- PRE_SCALING_OVER_64
 * 4- PRE_SCALING_OVER_256
 * 5- PRE_SCALING_OVER_1024
 * 6- EXT_CLK_DOC_TRIGGER_ON_FALLING
 * 7- EXT_CLK_DOC_TRIGGER_ON_RISING
 * */
#define PRE_SCALING_VLUE   PRE_SCALING_OVER_1024





#endif
