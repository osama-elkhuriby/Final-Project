/*
 * dio.c
 *
 *  Created on: Aug 15, 2022
 *      Author: Osama
 */

#include "dio.h"
#include <avr/io.h>
#include <stdint.h>



/**
 * @brief
 * Set DIO pins direction
 * @param DIOx: Specifies the PORT num where x equals A,B,C,D
 * @param pin:
 * @param direction :
 * 						this value must be type of dio_direction_t
 * @example:
 * dio_set_direction(PORTA, 4, OUTPUT);
 */

void dio_set_direction(dio_t DIOx, uint8_t pin, dio_direction_t direction)
{
	switch (DIOx)
	{
	case DIOA:
		/* code */
		DDRA &= ~(0x01<<pin);   // clear bit
		DDRA |= direction << pin; // set value
		break;
	case DIOB:
		DDRB &= ~(0x01<<pin);   // clear bit
		DDRB |= direction << pin; // set value
		/* code */
		break;
	case DIOC:
		/* code */
		DDRC &= ~(0x01<<pin);   // clear bit
		DDRC |= direction << pin; // set value
		break;
	case DIOD:
		/* code */
		DDRD &= ~(0x01<<pin);   // clear bit
		DDRD |= direction << pin; // set value
		break;

	default:
		//report error
		break;
	}
}

void dio_set_level(dio_t DIOx, dio_pin_t pin, dio_level_t value)
{
	switch (DIOx)
	{
	case DIOA:
		/* code */
		PORTA &= ~(0x01<<pin);  // clear bit
		PORTA |= value << pin; // set value
		break;
	case DIOB:
		PORTB &= ~(0x01<<pin);  // clear bit
		PORTB |= value << pin; // set value
		/* code */
		break;
	case DIOC:
		/* code */
		PORTC &= ~(0x01<<pin);  // clear bit
		PORTC |= value << pin; // set value
		break;
	case DIOD:
		/* code */
		PORTD &= ~(0x01<<pin);   // clear bit
		PORTD |= value << pin; // set value
		break;

	default:
		//report error
		break;
	}

}

void dio_set_all_level(dio_t DIOx, uint8_t value)
{
	switch (DIOx)
	{
	case DIOA:
		/* code */
		PORTA = value;
		break;
	case DIOB:
		PORTB = value;
		/* code */
		break;
	case DIOC:
		/* code */
		PORTC = value;
		break;
	case DIOD:
		/* code */
		PORTD = value;
		break;

	default:
		//report error
		break;
	}

}


dio_level_t dio_get_level(dio_t DIOx, dio_pin_t pin)
{
	switch (DIOx)
		{
		case DIOA:
			/* code */
			return 0b01&(PINA>>pin);
			break;
		case DIOB:
			return 0b01&(PINB>>pin);
			/* code */
			break;
		case DIOC:
			/* code */
			return 0b01&(PINC>>pin);
			break;
		case DIOD:
			/* code */
			return 0b01&(PIND>>pin);
			break;

		default:
			//report error
			break;
		}

}

void dio_set_all_direction(dio_t DIOx, uint8_t direction)
{
	switch (DIOx)
	{
	case DIOA:
		/* code */
		DDRA =  direction;
		break;
	case DIOB:
		DDRB =  direction;
		/* code */
		break;
	case DIOC:
		/* code */
		DDRC =  direction;
		break;
	case DIOD:
		/* code */
		DDRC =  direction;
		break;

	default:
		//report error
		break;
	}
}




void dio_pin_toggel(dio_t DIOx, dio_pin_t pin)
{
	switch (DIOx)
	{
	case DIOA:
		/* code */
		PORTA ^= (0x01<<pin);
		break;
	case DIOB:
		PORTB ^= (0x01<<pin);
		/* code */
		break;
	case DIOC:
		/* code */
		PORTC ^= (0x01<<pin);
		break;
	case DIOD:
		/* code */
		PORTD ^= (0x01<<pin);
		break;

	default:
		//report error
		break;
	}

}




