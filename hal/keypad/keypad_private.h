/*
 * keypad_private.h
 *
 *  Created on: Aug 17, 2022
 *      Author: osama
 */

#ifndef KEYPAD_KEYPAD_PRIVATE_H_
#define KEYPAD_KEYPAD_PRIVATE_H_

#include "../../mcal/dio/dio.h"

typedef struct{
	dio_t  port;
	dio_pin_t pin;

}porting_t;



#endif /* KEYPAD_KEYPAD_PRIVATE_H_ */
