/*******************************************************************************
 *  [File Name]	 : STD_TYPES.h
 *  [version]	 : V01
 *  [Author]	 : Mohamed Saeed
 *******************************************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/*------------------------------------------------------------------------------
 *                                 DEFINITIONS
 *------------------------------------------------------------------------------*/

#define NULL_PTR		((void *)0)

#ifndef TRUE
#define	TRUE			(1u)
#endif
#ifndef FALSE
#define FALSE			(0u)
#endif

#define DISABLE			(0u)
#define ENABLE			(1u)

/*------------------------------------------------------------------------------
 *                                    TYPES
 *------------------------------------------------------------------------------*/

/*Boolean Data Type */
typedef unsigned char		boolean;

/* unsigned Data types */
typedef unsigned char 		u8;       /*                   0..255                     */
typedef unsigned short 		u16;      /*                  0..65535                    */
typedef unsigned long 		u32;      /*                0..4294967295                 */
typedef unsigned long long 	u64;  	 /*           0..1844674407370955                */

/* Signed Data types */
typedef signed char 		s8;       /*                 -128 .. +127                 */
typedef signed short 		s16;      /*               -32768 .. +3276                */
typedef signed long 		s32;      /*          -2147483648 .. +2147483647          */
typedef signed long long 	s64;      /* -9223372036854775808 .. +9223372036854775807 */

/* float types*/
typedef float 				f32;
typedef double 				f64;

#endif /* STD_TYPES_H_ */
