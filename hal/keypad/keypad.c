/*
 * keypad.c
 *
 *  Created on: Aug 17, 2022
 *      Author: osama
 */
#include <stdint.h>
#include "../../mcal/dio/dio.h"
#include "keypad_config.h"
#include "keypad_private.h"
#include "avr/delay.h"

void keypad_init()
{
	// set the Rows to INPUT

	/*
	dio_set_direction(KEYPAD_ROW1_PORT, KEYPAD_ROW1_PIN, INPUT);
	dio_set_direction(KEYPAD_ROW2_PORT, KEYPAD_ROW2_PIN, INPUT);
	dio_set_direction(KEYPAD_ROW3_PORT, KEYPAD_ROW3_PIN, INPUT);
	dio_set_direction(KEYPAD_ROW4_PORT, KEYPAD_ROW4_PIN, INPUT);
	*/

	porting_t row_arr[KEYPAD_ROW_NUM] = KEYPAD_ROW_ARR_VAL;

	porting_t column_arr[KEYPAD_COLUMN_NUM] = KEYPAD_COLUMN_ARR_VAL;

	for(int8_t i = 0; i < KEYPAD_ROW_NUM; i++)
	{
		dio_set_direction(row_arr[i].port,row_arr[i].pin, INPUT);
	}


	for(int8_t i = 0; i < KEYPAD_COLUMN_NUM; i++)
	{
		dio_set_direction(column_arr[i].port,column_arr[i].pin, OUTPUT);

	}

	// set the COLUMNS to OUTPUT

	/*
	dio_set_direction(KEYPAD_COLUMN1_PORT, KEYPAD_COLUMN1_PIN, OUTPUT);
	dio_set_direction(KEYPAD_COLUMN2_PORT, KEYPAD_COLUMN2_PIN, OUTPUT);
	dio_set_direction(KEYPAD_COLUMN3_PORT, KEYPAD_COLUMN3_PIN, OUTPUT);
	dio_set_direction(KEYPAD_COLUMN4_PORT, KEYPAD_COLUMN4_PIN, OUTPUT);
	*/


}

uint8_t keypad_get_pressed_key()
{
	uint8_t keys[KEYPAD_ROW_NUM][KEYPAD_COLUMN_NUM] = KEYPAD_KEY_VAL;

	porting_t row_arr[KEYPAD_ROW_NUM] = KEYPAD_ROW_ARR_VAL;
	porting_t col_arr[KEYPAD_COLUMN_NUM] = KEYPAD_COLUMN_ARR_VAL;



		for(int8_t i = 0; i < KEYPAD_COLUMN_NUM; i++)
		{
			dio_set_level(col_arr[i].port,col_arr[i].pin,HIGH);
		}


		for(uint8_t c = 0; c < KEYPAD_COLUMN_NUM; c++)
		{
			dio_set_level(col_arr[c].port,col_arr[c].pin, LOW);

			for(uint8_t i = 0; i < KEYPAD_ROW_NUM; i++)
			{
				_delay_ms(3);

				if(dio_get_level(row_arr[i].port,row_arr[i].pin) == LOW)
				{
					_delay_ms(5);

					while(dio_get_level(row_arr[i].port,row_arr[i].pin) == LOW);

					return keys[i][c];
				}

			}
			dio_set_level(col_arr[c].port,col_arr[c].pin, HIGH);
		}

	return 0;

}
