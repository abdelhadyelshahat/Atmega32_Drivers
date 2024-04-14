/*
 * KPD_intrtface.h
 *
 *  Created on: Mar 12, 2024
 *      Author: hady
 */

#ifndef HAL_KPD_KPD_INTERFACE_H_
#define HAL_KPD_KPD_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

#define KPD_u8_NOT_PRESSED 0xff
#define KPD_u8_PRESSED  0x00

void H_KPD_void_KPDInit(void);


u8 H_KPD_u8_GetKey(void);

#endif /* HAL_KPD_KPD_INTERFACE_H_ */
