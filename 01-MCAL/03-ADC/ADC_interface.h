/*********************************************/
/********* ADC_INTERFACE_H_ *****************/
/********* SWC : ADC ***********************/
/********* Layer : MCAL *******************/
/********* Author : Abdelhady Elshahat ***/
/********* Date : 30 / 10 / 2023 ********/
/********* version : 1.0 ***************/
/**************************************/


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


/*********** macros for channels  *************/
/***********  SN ---> Single Mode  DF ----> Diffrential Mode *********/
#define ADC_u8_CHANNEL_0   0       /* SN - CH 1  */
#define ADC_u8_CHANNEL_1   1       /* SN - CH 2  */
#define ADC_u8_CHANNEL_2   2       /* SN - CH 3  */
#define ADC_u8_CHANNEL_3   3       /* SN - CH 4  */
#define ADC_u8_CHANNEL_4   4       /* SN - CH 5  */
#define ADC_u8_CHANNEL_5   5       /* SN - CH 6  */
#define ADC_u8_CHANNEL_6   6       /* SN - CH 7  */
#define ADC_u8_CHANNEL_7   7       /* SN - CH 8  */
#define ADC_u8_CHANNEL_8   8 	   /* DF - CH0 & CH0 with G = 10x */
#define ADC_u8_CHANNEL_9   9       /* DF - CH1 & CH0 with G = 10x */
#define ADC_u8_CHANNEL_10  10      /* DF - CH0 & CH0 with G = 200x */
#define ADC_u8_CHANNEL_11  11      /* DF - CH1 & CH0 with G = 200x */
#define ADC_u8_CHANNEL_12  12      /* DF - CH2 & CH2 with G = 10x */
#define ADC_u8_CHANNEL_13  13      /* DF - CH3 & CH2 with G = 10x */
#define ADC_u8_CHANNEL_14  14      /* DF - CH2 & CH2 with G = 200x */
#define ADC_u8_CHANNEL_15  15      /* DF - CH3 & CH2 with G = 200x */
#define ADC_u8_CHANNEL_16  16      /* DF - CH0 & CH1 with G = 1x */
#define ADC_u8_CHANNEL_17  17      /* DF - CH1 & CH1 with G = 1x */
#define ADC_u8_CHANNEL_18  18      /* DF - CH2 & CH1 with G = 1x */
#define ADC_u8_CHANNEL_19  19      /* DF - CH3 & CH1 with G = 1x */
#define ADC_u8_CHANNEL_20  20      /* DF - CH4 & CH1 with G = 1x */
#define ADC_u8_CHANNEL_21  21      /* DF - CH5 & CH1 with G = 1x */
#define ADC_u8_CHANNEL_22  22      /* DF - CH6 & CH1 with G = 1x */
#define ADC_u8_CHANNEL_23  23      /* DF - CH7 & CH1 with G = 1x */
#define ADC_u8_CHANNEL_24  24      /* DF - CH0 & CH2 with G = 1x */
#define ADC_u8_CHANNEL_25  25      /* DF - CH1 & CH2 with G = 1x */
#define ADC_u8_CHANNEL_26  26      /* DF - CH2 & CH2 with G = 1x */
#define ADC_u8_CHANNEL_27  27      /* DF - CH3 & CH2 with G = 1x */
#define ADC_u8_CHANNEL_28  28      /* DF - CH4 & CH2 with G = 1x */
#define ADC_u8_CHANNEL_29  29      /* DF - CH5 & CH2 with G = 1x */          
#define ADC_u8_CHANNEL_30  30	   /* SN - 1.22 V for testing   */
#define ADC_u8_CHANNEL_31  31      /* SN - GND for testing   */
/********************************************************/






void ADC_voidInit (void) ;

u8 ADC_u8GetDigitalValueSyncNoBlocking (u8 Copy_u8ChannelNumber, u16 * Copy_Pu16DigitalValue );
 

u8 ADC_u8GetDigitalValueAsynch (u8 Copy_u8ChannelNumber, u8 (*Copy_PFNotification_function) (void) );



#endif 
