/***************************************************/
/************* TIMER SW Module / Driver ***********/
/************* Layer : MCAL **********************/
/************* File : Timer_interface.h***********/
/************ Author : Abdelhady ****************/
/************ Date : 20/ 11 / 2023 *************/
/*********** version 1.1 **********************/
/*********************************************/

#ifndef TIMER_INTERFACE_H_ 
#define TIMER_INTERFACE_H_




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


void Timers_voidTimer0Init(void );


u8 Timers_voidTimer0SetCallBackFun ( void (*Copy_pfCallBack) (void) ,u8 Copy_u8ID );


void Timers_voidTimer0SetOCR0Value (u8 Copy_u8OCR0Value);

void Timers_voidTimer0SetPreLoadValue (u8 Copy_u8PreloadValue);


u8 Timer0_u8DelayMs (u32 Copy_u8DelayMs , void (*NotificationFunc)(void) );

void Timer0_voidSetPrescaller (u8 copy_u8PrescallingValue);

void Timers_voidTimer1Init(void );

#endif
