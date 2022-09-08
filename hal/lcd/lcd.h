/*
 * lcd.h
 *
 *  Created on: Aug 16, 2022
 *      Author: osama
 */

#ifndef LCD_LCD_H_
#define LCD_LCD_H_

#include <stdint.h>

void lcd_init();
void lcd_send_cmd( int8_t command);
void lcd_send_data(uint8_t data);
void lcd_send_str(uint8_t str[]);
void lcd_set_curser(uint8_t x, uint8_t y);
void lcd_set_specialchar(uint8_t arr[], uint8_t block_num);
void lcd_send_specialchar(uint8_t block_num, uint8_t x, uint8_t y);

void lcd_send_integer(uint16_t number);



#endif /* LCD_LCD_H_ */
