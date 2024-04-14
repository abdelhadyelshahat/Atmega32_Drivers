/*
 * KPD_config.h
 *
 *  Created on: Mar 12, 2024
 *      Author: hady
 */

#ifndef HAL_KPD_KPD_CONFIG_H_
#define HAL_KPD_KPD_CONFIG_H_

#include "../../LIB/STD_TYPES.h"

/* Macros configuration for Columns */
#define KPD_u8_COLs_PORT 				DIO_u8_PORTD

#define KPD_u8_COL1_PIN					DIO_u8_PIN0
#define KPD_u8_COL2_PIN					DIO_u8_PIN1
#define KPD_u8_COL3_PIN					DIO_u8_PIN2
#define KPD_u8_COL4_PIN					DIO_u8_PIN3

/* Macros configuration for Rows */
#define KPD_u8_ROWs_PORT 				DIO_u8_PORTC

#define KPD_u8_ROW1_PIN					DIO_u8_PIN0
#define KPD_u8_ROW2_PIN					DIO_u8_PIN1
#define KPD_u8_ROW3_PIN					DIO_u8_PIN2
#define KPD_u8_ROW4_PIN					DIO_u8_PIN3

#define KPD_u8_NO_SWICH_PRESSED			0xff

/* Pull-up Resistors Activation*/
/* options : KPD_u8_PULLUP_RES_INTERNAL_ACTIVATION
 * 			 KPD_u8_PULLUP_RES_EXTERNAL_ACTIVATION
 * */
#define KPD_u8_PULLUP_RES_AVTIVATION  KPD_u8_PULLUP_RES_INTERNAL_ACTIVATION

u8 KPD_Au8Matrix[4][4] = {   {'7','8','9','/'},
						     {'4','5','6','*'},
						     {'1','2','3','-'},
							 {'O','0','=','+'}   };


#endif /* HAL_KPD_KPD_CONFIG_H_ */
