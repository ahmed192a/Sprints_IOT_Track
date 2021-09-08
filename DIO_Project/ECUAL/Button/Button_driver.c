/*
 * Button_driver.c
 *
 *      Author: Ahmed Mohamed
 */

/************************************************************************
  	  	  	  	  	  	  	  Includes
 ***********************************************************************/
#include "Button_driver.h"
#include "../../MCAL/DIO.h"

/************************************************************************
  	  	  	  	  	  	  	  Local Macros
 ***********************************************************************/
#define BUTTON1		0x01

/************************************************************************
  	  	  	  	  	  	  	  Global Static Variables
 ***********************************************************************/
static PORT_Config_t Portc;


/************************************************************************
  	  	  	  	  	  	  	  Function Definitions
 ***********************************************************************/

void Button_Init(){
	Portc.port = C;					// set port to PORT C
	Portc.direction &= ~BUTTON1;	// set direction of PC0 to input
	Port_Init(&Portc);				// initialize Port C
}



uint8_t Check_Button(){
	Read_Port(&Portc);				// Read Value of PORT C
	return (Portc.Data&BUTTON1);	// return only the value of button after the mask
}
