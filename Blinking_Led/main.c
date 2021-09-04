/*
 * main.c
 *
 *  Created on: Sep 4, 2021
 *      Author: ah132
 */
#include "timer.h"

void Timer1_INT();

volatile uint8_t g_timer1_SecFlag = 0xff;
Timer_ConfigType timer1_Strut;

int main(){
	/* Enable Global Interrupt */
	SREG |= (1<<7);

	PORTA_DIR = 0xFF;
	PORTA_OUT = 0x00;
	/* Timer Structure for timer 1 configurations */
	/* Configure Timer1 to count for 1 Second*/

	timer1_Strut.mode				= CTC_MODE_CHANNEL_A;
	timer1_Strut.compare_output		= NORMAL;
	timer1_Strut.OutputPin			= NONE;
	timer1_Strut.clock				= F_CPU_1024;
	timer1_Strut.initial			= 0;
	timer1_Strut.compare_value		= 800;

	/* Timer 1 Initialization */
	TIMER1_init(&timer1_Strut);

	/* CallBack Function for timer 1 CTC Channel A Interrupt Function */
	Timer1_setCallBack(Timer1_INT);
//	PORTA_OUT = 0xFF;


	while(1){

	}
}


void Timer1_INT(){

	//TOGGLE_BIT(PORTA_OUT,4);
	PORTA_OUT = 0xFF;
	timer1_Strut.initial				= 0;
	if(PORTA_OUT&0x04)
		timer1_Strut.compare_value 		= 200;
	else
		timer1_Strut.compare_value		= 800;
	TIMER1_init(&timer1_Strut);
}
