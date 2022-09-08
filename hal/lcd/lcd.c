/*
 * lcd.c
 *
 *  Created on: Aug 16, 2022
 *      Author: osama
 */

#include "lcd.h"
#include "lcd_config.h"
#include "avr/delay.h"
#include <stdlib.h>

void lcd_init()
{
	_delay_ms(30);

    dio_set_direction(LCD_EN_PORT, LCD_EN_PIN , OUTPUT);
    dio_set_direction(LCD_RS_PORT, LCD_RS_PIN , OUTPUT);
    dio_set_all_direction(LCD_DATA_PORT,ALL_OUTPUT);

    /*
    lcd_send_cmd(0x38);
    _delay_ms(2);
    lcd_send_cmd(0x0C);
    _delay_ms(2);
    lcd_send_cmd(0x01);

	*/

    lcd_send_cmd(0b00111000);
    lcd_send_cmd(0b00000001);
    _delay_ms(2);
    lcd_send_cmd(0b00000110);
    lcd_send_cmd(0b00001101);

}

void lcd_send_cmd( int8_t command)
{

    dio_set_level(LCD_RS_PORT,LCD_RS_PIN,LOW);

    dio_set_all_level(LCD_DATA_PORT, command);



    dio_set_level(LCD_EN_PORT,LCD_EN_PIN,HIGH);

    _delay_ms(2);

    dio_set_level(LCD_EN_PORT,LCD_EN_PIN,LOW);

	
}

void lcd_send_data(uint8_t data)
{

	dio_set_level(LCD_RS_PORT,LCD_RS_PIN,HIGH);

	dio_set_all_level(LCD_DATA_PORT, data);

	dio_set_level(LCD_EN_PORT,LCD_EN_PIN,HIGH);

	_delay_ms(2);

	dio_set_level(LCD_EN_PORT,LCD_EN_PIN,LOW);
}

void lcd_send_str(uint8_t str[])
{
    dio_set_level(LCD_RS_PORT,LCD_RS_PIN,HIGH);
    uint8_t i = 0;
    while (str[i] != '\0')
    {
        dio_set_all_level(LCD_DATA_PORT,str[i]);
        i++;
        dio_set_level(LCD_EN_PORT,LCD_EN_PIN,HIGH);
        _delay_ms(2);
        dio_set_level(LCD_EN_PORT,LCD_EN_PIN,LOW);
        _delay_ms(2);
    }
    

}

void lcd_set_curser(uint8_t x, uint8_t y)
{
    uint8_t address = x;

    if (1 == y)
    {
        address += 0x40;
    }

    uint8_t cmd = 0b10000000;

    cmd |= address;

    lcd_send_cmd(cmd);
}

void lcd_set_specialchar(uint8_t arr[], uint8_t block_num)
{
	uint8_t address = block_num * 8;
	lcd_send_cmd(0b01000000 | address);
	_delay_ms(30);
	for(uint8_t i = 0; i < 8; i++)
	{
		lcd_send_data(arr[i]);
		_delay_ms(30);
	}
}

void lcd_send_specialchar(uint8_t block_num, uint8_t x, uint8_t y)
{
	lcd_set_curser(x, y);
	lcd_send_data(block_num);
}


void lcd_send_integer(uint16_t number)
{
	uint8_t ch[6] = {' '};

	for (int8_t i = 0; i < 6; ++i)
	{
		ch[i] = ' ';
	}

	itoa(number,ch,10);

	for (int8_t j = 0; j < 6; ++j)
	{
		if(ch[j] < '0' || ch[j] > '9')
		{
			lcd_send_data(' ');
		}
		else
		{
			lcd_send_data(ch[j]);
		}
	}
}


