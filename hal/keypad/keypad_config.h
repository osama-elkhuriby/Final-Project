/*
 * keypad_config.h
 *
 *  Created on: Aug 17, 2022
 *      Author: osama
 */

#ifndef KEYPAD_KEYPAD_CONFIG_H_
#define KEYPAD_KEYPAD_CONFIG_H_


#define KEYPAD_ROW_NUM 4
#define KEYPAD_COLUMN_NUM 4

// ROWS
/*
#define KEYPAD_ROW1_PORT DIOA
#define KEYPAD_ROW1_PIN PIN_0
#define KEYPAD_ROW2_PORT DIOA
#define KEYPAD_ROW2_PIN PIN_1
#define KEYPAD_ROW3_PORT DIOA
#define KEYPAD_ROW3_PIN PIN_2
#define KEYPAD_ROW4_PORT DIOA
#define KEYPAD_ROW4_PIN PIN_3
*/

#define KEYPAD_ROW_ARR_VAL { \
	{DIOA, PIN_0},    \
	{DIOA, PIN_1},   \
	{DIOA, PIN_2},  \
	{DIOA, PIN_3}, \
}

// COLUNMS

/*
#define KEYPAD_COLUMN1_PORT DIOA
#define KEYPAD_COLUMN1_PIN PIN_4
#define KEYPAD_COLUMN2_PORT DIOA
#define KEYPAD_COLUMN2_PIN PIN_5
#define KEYPAD_COLUMN3_PORT DIOA
#define KEYPAD_COLUMN3_PIN PIN_6
#define KEYPAD_COLUMN4_PORT DIOA
#define KEYPAD_COLUMN4_PIN PIN_7
*/

#define KEYPAD_COLUMN_ARR_VAL { \
	{DIOA, PIN_4},    \
	{DIOA, PIN_5},   \
	{DIOA, PIN_6},  \
	{DIOA, PIN_7}, \
}

#define KEYPAD_KEY_VAL { \
	{'1','2','3','4'},	 \
	{'5','6','7','8'},	 \
	{'9','A','B','C'},	 \
	{'D','E','F','0'},	 \
}



#define RELEASED_LEVEL LOW


#endif /* KEYPAD_KEYPAD_CONFIG_H_ */
