/*********************************************/
/********* ADC_CONFIG_H_ *****************/
/********* SWC : ADC ***********************/
/********* Layer : MCAL *******************/
/********* Author : Abdelhady Elshahat ***/
/********* Date : 30 / 10 / 2023 ********/
/********* version : 1.0 ***************/
/**************************************/

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_


/* configur volatage REF : options : ADC_VREF_AREF
                                     ADC_VREF_AVCC
                                     ADC_INTERNAL_VREF */
#define ADC_u8_Voltage_REF  ADC_u8_AVCC

#define ADC_u8_ADJUST  ADC_u8_RIGHT_ADJUST

#define ADC_u8_AUTO_TIGGER  ADC_u8_AUTO_TIGGER_DISABLE

#define ADC_u8_PRESCALLER  ADC_u8_PRESCALLER_64

#define ADC_u32_TIMING_OUT_MAX_VALUE     50000

#endif 
