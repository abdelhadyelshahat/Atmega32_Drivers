/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    STD_TYPES.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Abdelhady Elshahat Abdelhady
 *  Layer  : LIB
 *
 */

#ifndef LIB_STD_TYPES_H_
#define LIB_STD_TYPES_H_

/*
 * STD TYPES
 * */
/* unsigned types */
 typedef unsigned char u8;
 typedef unsigned short int u16 ;
 typedef unsigned long int u32 ;
 typedef unsigned long long int u64;

/* signed types */
 typedef signed char s8 ;
 typedef signed short int s16 ;
 typedef signed long int s32;
 typedef signed long long s64;

 /* float types */
 typedef float f32;
 typedef double f64;

 /* Error State Macros*/
#define NO_ERROR    0
#define ERROR       1

/* NULL pointer Macro*/
#define NULL (volatile void *)0x00

#endif /* LIB_STD_TYPES_H_ */
