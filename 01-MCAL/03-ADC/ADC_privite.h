/*********************************************/
/********* ADC_PRIVITE_H_ *****************/
/********* SWC : ADC ***********************/
/********* Layer : MCAL *******************/
/********* Author : Abdelhady Elshahat ***/
/********* Date : 30 / 10 / 2023 ********/
/********* version : 1.0 ***************/
/**************************************/

#ifndef  ADC_PRIVITE_H_
#define ADC_PRIVITE_H_


/*********** REG defintion *****************************/

/**************** ADC_u8_ADMUX_REG *********/
/* macros for ADC_u8_ADMUX_REG bits  */

#define REFS1_BIT 7
#define REFS0_BIT 6
#define ADLAR_BIT 5


#define ADC_u8_ADMUX_REG_CH_CLEAR 0b11100000

#define ADC_u8_ADMUX_REG        *((volatile u8 *)0x27)
/*******************************************/

/***************** ADC_u8_ADCSRA_REG********/
/* macros for ADC_u8_ADCSRA_REG bits  */
#define ADEN_BIT  7
#define ADSC_BIT  6
#define ADATE_BIT 5
#define ADIF_BIT  4
#define ADIE_BIT  3
#define ADPS2_BIT 2
#define ADPS1_BIT 1
#define ADPS0_BIT 0

#define ADC_u8_ADCSRA_REG        *((volatile u8 *)0x26)

/********************************************/

#define ADC_u8_ADCL_REG        *((volatile u8 *)0x24)

#define ADC_u8_ADCH_REG        *((volatile u8 *)0x25)

#define ADC_u16_ADC_WORD_REG        *((volatile u16 *)0x24)



#define ADC_u8_SFIOR_REG        *((volatile u8 *)0x50)

/******** Macros for Voltage Referance *********/

#define ADC_u8_AREF      0
#define ADC_u8_AVCC      1
#define ADC_u8_INTERNAL  2
 
/****************** macros for Adjust *******/
#define ADC_u8_RIGHT_ADJUST   0
#define ADC_u8_LEFT_ADJUST    1

/************ macros for conversion mode (Auto trigger) **********/
#define ADC_u8_AUTO_TIGGER_DISABLE 0
#define ADC_u8_AUTO_TIGGER_ENABLE 1

/********** macros for prescalling **********/
#define ADC_u8_PRESCALLER_32   0
#define ADC_u8_PRESCALLER_64   1
#define ADC_u8_PRESCALLER_128  2


/** macros for ADC statue */

#define ADC_u8_BUSY 1
#define ADC_u8_NOT_BUSY 0



#endif 
