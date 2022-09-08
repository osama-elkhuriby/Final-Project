/*
 * bit_math.h
 *
 *  Created on: Aug 29, 2022
 *      Author: osama
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT( reg,bit){ \
	reg |=  1 << bit ;		\
}

#define CLR_BIT( reg,bit){ \
	reg &=  ~(1 << bit) ;		\
}

#define GET_BIT(reg,bit) ((reg>>bit)&1)

#endif /* BIT_MATH_H_ */
