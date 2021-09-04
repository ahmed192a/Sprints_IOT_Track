/*
 * registers.h
 *
 *      Author: Ahmed Mohamed
 *
 *      Description: Registers definitions for ATMEGA32
 */

#ifndef REGISTERS_H_
#define REGISTERS_H_
/************************************************************************
  	  	  	  	  	  	  	  Includes
 ***********************************************************************/
#include "std_types.h"

/************************************************************************
  	  	  	  	  	  	  	  Registers Definitions
 ***********************************************************************/
#define PORTA_DIR	*((volatile uint8_t*)(0x3A))
#define PORTA_IN	*((volatile uint8_t*)(0x39))
#define PORTA_OUT	*((volatile uint8_t*)(0x3B))

#define PORTC_DIR	*((volatile uint8_t*)(0x34))
#define PORTC_OUT	*((volatile uint8_t*)(0x35))
#define PORTC_IN	*((volatile uint8_t*)(0x33))

#define PORTB_DIR	*((volatile uint8_t*)(0x37))
#define PORTB_OUT	*((volatile uint8_t*)(0x38))
#define PORTB_IN	*((volatile uint8_t*)(0x36))

#define PORTD_DIR	*((volatile uint8_t*)(0x31))
#define PORTD_OUT	*((volatile uint8_t*)(0x32))
#define PORTD_IN	*((volatile uint8_t*)(0x30))


#endif /* REGISTERS_H_ */
