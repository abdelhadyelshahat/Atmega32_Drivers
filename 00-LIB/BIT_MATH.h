/*
 * BIT_MATH.h
 *
 *  Created on: Mar 6, 2024
 *      Author: hady
 */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_


/*Bit math macros */

#define SET_BIT(REG,BIT)  	REG |=  (1 << BIT)
#define CLR_BIT(REG,BIT)  	REG &= ~(1 << BIT)
#define GET_BIT(REG,BIT)  	((REG >> BIT) & 0x01)
#define TOG_BIT(REG,BIT)	REG ^=  (1 << BIT)


#endif /* LIB_BIT_MATH_H_ */
