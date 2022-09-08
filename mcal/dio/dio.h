/*
 * dio.h
 *
 *  Created on: Aug 15, 2022
 *      Author: osama
 */

#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_
#include <stdint.h>

typedef enum
{
    DIOA,
    DIOB,
    DIOC,
    DIOD,
} dio_t;


typedef enum
{
    zero = 0b00111111 ,
    one = 0b00000110,
    two = 0b01011011,
    three = 0b01001111,
	four = 0b01100110,
	five = 0b01101101,
	six = 0b01111101,
	seven = 0b00000111,
	eight = 0b01111111,
	nine = 0b01101111,


} numbers;


typedef enum{
    PIN_0,
    PIN_1,
    PIN_2,
    PIN_3,
    PIN_4,
    PIN_5,
    PIN_6,
    PIN_7,
} dio_pin_t;

typedef enum
{
    INPUT = 0,
    OUTPUT = 1,
	ALL_OUTPUT = 0xff,
	ALL_INPUT = 0x00,
} dio_direction_t;

typedef enum
{
    LOW = 0,
    HIGH = 1
} dio_level_t;

void dio_set_direction(dio_t PORTx, dio_pin_t pin, dio_direction_t direction);

void dio_set_all_direction(dio_t PORTx, uint8_t direction);

void dio_set_level(dio_t PORTx, dio_pin_t pin, dio_level_t value);

void dio_set_all_level(dio_t PORTx, uint8_t value);

dio_level_t dio_get_level(dio_t PORTx, dio_pin_t pin);

void dio_pin_toggel(dio_t PORTx, dio_pin_t pin);

#endif /* MCAL_DIO_DIO_H_ */
