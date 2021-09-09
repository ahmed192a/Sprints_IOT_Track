/*
 * main.c
 *
 *  Created on: Sep 4, 2021
 *      Author: Ahmed Mohamed
 */
#include "timer.h"
#include "common_macros.h"

// In CASE WE WANT USE INTERRUPT SET THE INTERRUPT MACRO TO 1
#define INTERRUPT 		0

#define LED				0x04

void Timer1_INT();

Timer_ConfigType timer1_Strut;


int main(){
#if INTERRUPT
	/* Enable Global Interrupt */
	SREG |= (1<<7);
#endif


	PORTA_DIR = LED;
	PORTA_OUT = 0x00;
	/* Timer Structure for timer 1 configurations */
	/* Configure Timer1 to count for 1 Second*/


#if INTERRUPT
	timer1_Strut.mode				= CTC_MODE;
	timer1_Strut.clock				= F_CPU_1024;
	timer1_Strut.PWM				= PWM_0;
	timer1_Strut.initial			= 0;
	timer1_Strut.top_count			= 500;
	timer1_Strut.interrupt			= TRUE;

#else
	timer1_Strut.mode				= CTC_MODE;
	timer1_Strut.clock				= F_CPU_1024;
	timer1_Strut.PWM				= PWM_0;
	timer1_Strut.initial			= 0;
	timer1_Strut.top_count			= 500;
	timer1_Strut.interrupt			= FALSE;
#endif

	/* Timer 1 Initialization */
	TIMER1_init(&timer1_Strut);

#if INTERRUPT
	/* CallBack Function for timer 1 CTC Channel A Interrupt Function */
	Timer1_setCallBack(Timer1_INT);
#endif


	while(1){
#if !INTERRUPT
		while(!TIFR& (1<<OCF1A));
		TIFR |= 1<<OCF1A;
		TOGGLE_BIT(PORTA_OUT,LED);
		timer1_Strut.initial			= 0;
		if(PORTA_OUT&LED){
		timer1_Strut.top_count			= 300;
		}
		else{
			timer1_Strut.top_count			= 500;
		}
		/* Timer 1 Initialization */
		TIMER1_init(&timer1_Strut);
#endif
	}
}


void Timer1_INT(){
	TOGGLE_BIT(PORTA_OUT,LED);
	timer1_Strut.initial			= 0;
	if(PORTA_OUT&LED){
		timer1_Strut.top_count			= 300;
	}
	else{
		timer1_Strut.top_count			= 500;
	}
	/* Timer 1 Initialization */
	TIMER1_init(&timer1_Strut);
}
