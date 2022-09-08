/*
 * smart_lock.c
 *
 *  Created on: Sep 8, 2022
 *      Author: osama
 */

#include "smart_lock.h"
#include "smart_lock_config.h"
#include "../../mcal/dio/dio.h"
#include "../../mcal/timer/timer.h"
#include "../keypad/keypad.h"
#include "../lcd/lcd.h"
#include <avr/delay.h>
#include <stdint.h>


uint8_t current_password[4];

void smart_lock_init()
{

	uint8_t counter, key, wrong_times = 0;
	uint8_t password[4];
	uint8_t ent_pass[]="ENTER PASSWORD : ";
	uint8_t door_open[]="OPENING DOOR";
	uint8_t wrong_pass[]="WRONG PASSWORD";

	dio_set_direction(RED_LED_PORT, RED_LED_PIN, OUTPUT); //RED LED DIR
	dio_set_direction(GREEN_LED_PORT, GREEN_LED_PIN, OUTPUT); //GREEN LED DIR



	// CREATE PASSWORD FOR FIRST TIME
	set_password();

	while(1)
	{

		lcd_send_cmd(0x01); // clear LCD
		_delay_ms(1000);
		lcd_send_str(ent_pass);
		lcd_send_cmd(0xc0); // writing in the next row
		counter = 0;
		dio_set_level(RED_LED_PORT, RED_LED_PIN, LOW);  //RED LED LOW
		dio_set_level(GREEN_LED_PORT, GREEN_LED_PIN, LOW);  //GREEN LED LOW
		//dio_set_level(DIOB, PIN_2, LOW);  //BUZZER LOW
		servo_motor_0(); // Door CLOSED

		// Get Password
		while(counter < 4)
		{

			key = keypad_get_pressed_key();
			if(key != '\0')
			{
				password[counter] = key;
				lcd_send_data('*');
				counter++;
				_delay_ms(1000);
			}
		}

		// Check Password
		if(password[0] == current_password[0] && password[1] == current_password[1] && password[2] == current_password[2] && password[3] == current_password[3] )
		{
			//CORRECT PASS
			lcd_send_cmd(0x01);
			_delay_ms(1000);
			lcd_send_str(door_open);

			_delay_ms(1000);
			dio_set_level(GREEN_LED_PORT, GREEN_LED_PIN, HIGH);  //GREEN LED HIGH

			servo_motor_90(); // Door open

			_delay_ms(5000);
		}
		else
		{
			//WRONG PASS
			lcd_send_cmd(0x01);
			_delay_ms(1000);
			lcd_send_str(wrong_pass);
			_delay_ms(1000);

			// if it wrong for 3 times
			if(wrong_times < 2)
			{
				wrong_times++;
			}
			else
			{
				for(uint8_t i = 0; i < 3;i++)
				{
					//FLASH RED LED
					dio_set_level(RED_LED_PORT, RED_LED_PIN, HIGH);   //RED LED HIGH
					//dio_set_level(DIOB, PIN_2, HIGH);   //BUZZER HIGH
					dio_set_direction(BUZZER_LED_PORT, BUZZER_LED_PIN, OUTPUT); //BUZZER DIR
					_delay_ms(2000);
					dio_set_level(RED_LED_PORT, RED_LED_PIN, LOW);	//RED LED LOW
					//dio_set_level(DIOB, PIN_2, LOW);	//BUZZER LOW
					dio_set_direction(BUZZER_LED_PORT, BUZZER_LED_PIN, INPUT); //BUZZER DIR
					_delay_ms(2000);
				}

				wrong_times = 0;
			}

		}

	}


}

void set_password()
{
	uint8_t i = 0, key;
	uint8_t set_pass[]="SET PASS **** :";


	lcd_send_cmd(0x01);
	lcd_send_str(set_pass);
	lcd_send_cmd(0xc0);

	while(i < 4)
	{
			// Get Password
		key = keypad_get_pressed_key();

		if(key != '\0')
		{
			current_password[i] = key;
			lcd_send_data(key);
			i++;
			_delay_ms(1000);
		}
	}


}
