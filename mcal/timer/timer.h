/*
 * himer.h
 *
 *  Created on: Aug 23, 2022
 *      Author: osama
 */

#ifndef MCAL_TIMER_TIMER_H_
#define MCAL_TIMER_TIMER_H_

#include <stdint.h>


typedef enum{
	TIMER0,
	TIMER1,
	TIMER2,
}timer_t;

typedef enum{
	TIMER,
	COUNTER
}timer_mode_t;

typedef enum{
	NORMAL,
	CTC,
	PWM,
	FAST_PWM,
}timer_output_t;


typedef enum{
	TIMER_NO_CLKSRC,
	TIME_PRESCALER_1,
	TIME_PRESCALER_8,
	TIME_PRESCALER_64,
	TIME_PRESCALER_256,
	TIME_PRESCALER_1024,
	TIMER_EXTCLK_RISING,
	TIMER_EXTCLK_FALLING,
}timer_clksrc_t;

typedef enum{
	CTC_PIN_DISCON,
	CTC_PIN_TOGGLE,
	CTC_PIN_CLR,
	CTC_PIN_SET,
}ctc_outmode_t;


typedef struct
{
	timer_mode_t mode;
	timer_output_t output_mode;
	timer_clksrc_t clksrc;
	uint8_t int_state;
}timer_cofig_t;


#define SET_BIT( reg,bit){ \
	reg |=  1 << bit ;		\
}
#define CLR_BIT( reg,bit){ \
	reg &=  ~(1 << bit) ;		\
}

void timer_init(timer_t timer , timer_cofig_t config);
void timer_set_state(uint8_t state);
void timer_set_preload(timer_t timer,uint16_t preload);
void timer_set_ctcmode(timer_t timer,ctc_outmode_t ctcmode);
void timer_set_interuppt(timer_t timer , uint8_t state);
uint16_t timer_get_counter();

uint8_t timer_is_overflow(timer_t timer);

void timer0_init();
void timer0_deinit();
uint8_t timer0_get_count();
void timer0_set_callback(void (*fun_ptr)(void));



void pwm_init();
void pwm_deinit();

void timer1_fast_pwm();
void servo_motor_90(void);
void servo_motor_0(void);

void timer1_deinit();


#endif /* MCAL_TIMER_TIMER_H_ */
