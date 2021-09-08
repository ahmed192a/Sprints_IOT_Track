/*
 * LED_driver.c
 *
 *      Author: Ahmed Mohamed
 */

/************************************************************************
  	  	  	  	  	  	  	  Includes
 ***********************************************************************/
#include "LED_driver.h"
#include "../../MCAL/DIO.h"

/************************************************************************
  	  	  	  	  	  	  	  Local Macros
 ***********************************************************************/
#define LED 	0x10

/************************************************************************
  	  	  	  	  	  	  	  Global Static Variables
 ***********************************************************************/
static PORT_Config_t Porta;


/************************************************************************
  	  	  	  	  	  	  	  Function Definitions
 ***********************************************************************/
void LED_Init(){
	Porta.port = A;
	Porta.direction = LED;
	Porta.Data &= ~LED;
	Port_Init(&Porta);
	Write_Port(&Porta);
}

void LED_ON(){
	Porta.Data |= LED;
	Write_Port(&Porta);
}


void LED_OFF(){
	Porta.Data &= ~LED;
	Write_Port(&Porta);
}

void LED_Toggle(){
	Porta.Data ^= LED;
	Write_Port(&Porta);
}

