/*
 * DIO.c
 *
 *      Author: Ahmed Mohamed
 */

/************************************************************************
  	  	  	  	  	  	  	  Includes
 ***********************************************************************/
#include "DIO.h"


/************************************************************************
  	  	  	  	  	  	  	  Function Definitions
 ***********************************************************************/
void Port_Init(PORT_Config_t * Port){
	switch(Port->port){
	case A:
		PORTA_DIR = Port->direction;
		break;
	case B:
		PORTB_DIR = Port->direction;
		break;
	case C:
		PORTC_DIR = Port->direction;
		break;
	case D:
		PORTD_DIR = Port->direction;
		break;
	}
}

void Write_Port(PORT_Config_t *Port){
	switch(Port->port){
	case A:
		PORTA_OUT = Port->Data;
		break;
	case B:
		PORTB_OUT = Port->Data;
		break;
	case C:
		PORTC_OUT = Port->Data;
		break;
	case D:
		PORTD_OUT = Port->Data;
		break;
	}
}

void Read_Port(PORT_Config_t *Port){
	switch(Port->port){
	case A:
		Port->Data= PORTA_IN;
		break;
	case B:
		Port->Data= PORTB_IN;
		break;
	case C:
		Port->Data= PORTC_IN;
		break;
	case D:
		Port->Data= PORTD_IN;
		break;
	}
}
