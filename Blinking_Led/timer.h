 /******************************************************************************
 *
 * Module: Timer
 *
 * File Name: timer.h
 *
 * Description: Header file for the timer driver
 *
 * Author: ah132
 *
 *******************************************************************************/
#ifndef TIMER_H_
#define TIMER_H_

#include "registers.h"

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum
{
	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024,EXTERNAL_FALLING,EXTERNAL_RISING
}Timer_Clock;

typedef enum
{
	NORMAL_MODE,
	CTC_MODE,
	PWM_PHASE,
	PWM_FAST,
}Timer_Mode;

typedef enum{
	CHANNEL_A,
	CHANNEL_B
}Channel;
typedef enum{

	NONE,
	OC0  = 3,
	OC1B = 4,
	OC1A = 5,
	OC2  = 7

}Timer_OutputComparePinsType;

typedef enum
{
	NORMAL,TOGGLE_ON_COMPARE,CLEAR_ON_COMPARE,SET_ON_COMPARE
}C_Output_Mode;


typedef enum{
	PWM_0,
	PWM_1,
	PWM_2,
	PWM_3
}PWM_Type;

typedef struct
{
	Timer_Clock clock;
	Timer_Mode mode;
	C_Output_Mode compare_output;
	PWM_Type PWM;
	Timer_OutputComparePinsType OutputPin;
	uint16_t initial;
	uint16_t compare_value ;
	uint16_t top_count;
	bool interrupt;
	Channel channel;
}Timer_ConfigType;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void TIMER0_init(const Timer_ConfigType * Config_Ptr);
void TIMER1_init(const Timer_ConfigType * Config_Ptr);
void TIMER2_init(const Timer_ConfigType * Config_Ptr);
void Timer0_setCallBack(void(*a_ptr)(void));
void Timer1_setCallBack(void(*a_ptr)(void));
void Timer2_setCallBack(void(*a_ptr)(void));

void Timer0_Stop();

void Timer1_Stop();

void Timer2_Stop();

#endif /* TIMER_H_ */
