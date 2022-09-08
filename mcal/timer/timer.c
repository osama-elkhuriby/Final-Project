/*
 * timer.c
 *
 *  Created on: Aug 23, 2022
 *      Author: osama
 */
#include "timer.h"
#include <avr/io.h>
#include <avr/delay.h>
#include  "../dio/dio.h"
#include <avr/interrupt.h>


static void (*call_back) (void);

ISR(TIMER0_COMP_vect)
{
	if(call_back)
	{
		call_back();
	}
}



void timer0_init()
{
	// CTC MODE
	CLR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);

	TCNT0 = 0;

	//compare value

	OCR0 = 125;

	CLR_BIT(TCCR0, COM00);
	CLR_BIT(TCCR0, COM01);

	// CLOCK SELECT       64 PRESCALER
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);

	// ENABLE INT

	//SET_BIT(TIMSK,TOIE0);
	SET_BIT(TIMSK, OCIE0);

}

void timer0_deinit()
{
	CLR_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);

	CLR_BIT(TIMSK,TOIE0);

}



uint8_t timer0_get_count()
{
	return TCNT0;
}


void pwm_init()
{
	// FAST PWM MODE
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);




	// CLOCK SELECT       64 PRESCALER
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);


	//NON-INVERTING MODE
	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);


	dio_set_direction(DIOB, PIN_3, OUTPUT);
}

void pwm_deinit()
{
	CLR_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);

	CLR_BIT(TIMSK,TOIE0);

}



void timer1_fast_pwm()
{

	TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11);
	TCCR1B|=(1<<WGM13)|(1<<WGM12)|(1<<CS11)|(1<<CS10);

	ICR1 = 4999;

	DDRD|=(1<<PD4)|(1<<PD5);

}

void timer1_deinit()
{
	CLR_BIT(TCCR1B,ICES1);
	CLR_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);



	CLR_BIT(TCCR1B,CS10);
	CLR_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);


}



void servo_motor_0(void)
{
	timer1_fast_pwm();
	 OCR1A=97;

	_delay_ms(1000);
}


void servo_motor_90(void)
{
	timer1_fast_pwm();
	OCR1A=316;
	_delay_ms(1000);
}






void timer0_set_callback(void (*fun_ptr)(void))
{
	call_back = fun_ptr;
}




