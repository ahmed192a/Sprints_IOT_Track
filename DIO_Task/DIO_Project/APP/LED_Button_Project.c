/*
 *  LED_Button_Project.c
 *
 *      Author: Ahmed Mohamed
 *
 *      Description: Turn on the led if the button is pressed and turn it off if the button is unpressed
 */

/************************************************************************
  	  	  	  	  	  	  	  Includes
 ***********************************************************************/
#include "LED_Button_Project.h"

/************************************************************************
  	  	  	  	  	  	  	  Function Definitions
 ***********************************************************************/
void APP(){
	uint32_t i;							/* Variable used for counting in for loop to create delay */
	LED_Init();							/* Initialize LED */
	Button_Init();						/* Initialize Button */
	while(1){
		if(Check_Button()){				/* check if the button is pressed */
			LED_Toggle();				/* toggles the led */
			for(i=0; i<10000; i++);		/* Toggle the Led */
		}
	}
}
