/*
 * main.c
 *
 *  Created on: Sup 7, 2022
 *      Author: Osama Elkhuriby
 */

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include "mcal/dio/dio.h"
#include "hal/lcd/lcd.h"
#include "hal/keypad/keypad.h"
#include "mcal/timer/timer.h"
#include "hal/smart_lock/smart_lock.h"


int main()
{
	lcd_init();
	keypad_init();

	smart_lock_init();

}

