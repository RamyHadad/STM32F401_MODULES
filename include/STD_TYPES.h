/*
 * STD_TYPES.h
 *
 *  Created on: Jan 1, 2023
 *      Author: Ramy
 */

#ifndef INCLUDE_STD_TYPES_H_
#define INCLUDE_STD_TYPES_H_


typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef signed char sint8_t;
typedef signed short sint16_t;
typedef signed int sint32_t;

#define BIT_MASK  1
#define SET_BIT(REG, BIT_POSN)     (REG |= (BIT_MASK << BIT_POSN))
#define CLEAR_BIT(REG, BIT_POSN)   (REG &= ~(BIT_MASK << BIT_POSN))
#define TOGGLE_BIT(REG, BIT_POSN)  (REG ^= (BIT_MASK << BIT_POSN))
#define READ_BIT(REG, BIT_POSN)    ((REG >> BIT_POSN) & BIT_MASK)

typedef enum {
	E_OUT_RANGE,
	E_OK,
	E_NOT_OK
}Std_ReturnType;

/* Section: Macro Declarations */


#define STD_HIGH       0x01
#define STD_LOW        0x00

#define STD_ON         0x01
#define STD_OFF        0x00

#define STD_ACTIVE     0x01
#define STD_IDLE       0x00




#endif /* INCLUDE_STD_TYPES_H_ */
