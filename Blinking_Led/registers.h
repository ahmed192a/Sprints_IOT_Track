/*
 * registers.h
 *
 *      Author: Ahmed Mohamed
 */

#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "std_types.h"
#define PORTA_DIR	*((volatile uint8_t*)(0x3A))
#define PORTB_DIR	*((volatile uint8_t*)(0x37))
#define PORTC_DIR	*((volatile uint8_t*)(0x34))
#define PORTD_DIR	*((volatile uint8_t*)(0x31))

#define PORTA_OUT	*((volatile uint8_t*)(0x3B))
#define PORTB_OUT	*((volatile uint8_t*)(0x38))
#define PORTC_OUT	*((volatile uint8_t*)(0x35))
#define PORTD_OUT	*((volatile uint8_t*)(0x32))

#define PORTA_IN	*((volatile uint8_t*)(0x39))
#define PORTB_IN	*((volatile uint8_t*)(0x36))
#define PORTC_IN	*((volatile uint8_t*)(0x33))
#define PORTD_IN	*((volatile uint8_t*)(0x30))


#define P0			0
#define P1			1
#define P2			2
#define P3			3
#define P4			4
#define P5			5
#define P6			6
#define P7			7

#define SREG 		(*(volatile uint8_t *)(0x3F))

// Timer
#define TCCR0 		(*(volatile uint8_t *)(0x53))
#define FOC0		7
#define TCNT0 		(*(volatile uint8_t *)(0x52))
#define OCR0 		(*(volatile uint8_t *)(0x5C))
#define TIMSK		(*(volatile uint8_t *)(0x59))
#define TOIE0		0
#define OCIE0		1
#define TOIE1		2
#define OCIE1B		3
#define OCIE1A		4
#define TOIE2		6
#define OCIE2		7
#define WGM00		6
#define COM00		4
#define TCNT1		(*(volatile uint16_t *)(0x2C))
#define TCCR1A		(*(volatile uint8_t *)(0x4F))
#define COM1A0		6
#define FOC1A		3
#define FOC1B		2
#define OCR1A		(*(volatile uint16_t *)(0x4A))
#define OCR1B		(*(volatile uint16_t *)(0x48))
#define COM1B0		4
#define TCCR1B		(*(volatile uint8_t *)(0x4E))
#define WGM12		3
#define TCNT2		(*(volatile uint8_t *)(0x44))
#define OCR2		(*(volatile uint8_t *)(0x43))
#define TCCR2		(*(volatile uint8_t *)(0x45))
#define WGM20		6
#define FOC2		7
#define COM20		4
//#define TIFR		(*(volatile uint8_t *)(0x38))




void __vector_11(void) __attribute__ ((signal,used));
void __vector_10(void) __attribute__ ((signal,used));
void __vector_9(void) __attribute__ ((signal,used));
void __vector_8(void) __attribute__ ((signal,used));
void __vector_7(void) __attribute__ ((signal,used));
void __vector_5(void) __attribute__ ((signal,used));
void __vector_4(void) __attribute__ ((signal,used));


#endif /* REGISTERS_H_ */
