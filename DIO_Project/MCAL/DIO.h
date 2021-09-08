/*
 * DIO.h
 *
 *      Author: Ahmed Mohamed
 */

#ifndef DIO_H_
#define DIO_H_

/************************************************************************
  	  	  	  	  	  	  	  Includes
 ***********************************************************************/
#include "../registers.h"

/************************************************************************
  	  	  	  	  	  	  	  ENUMS
 ***********************************************************************/
typedef enum{
	INPUT,
	OUTPUT
}Direction_t;

typedef enum{
	A,
	B,
	C,
	D
}PORT_t;


/************************************************************************
  	  	  	  	  	  	  	  STRUCTS & UNIONS
 ***********************************************************************/
typedef struct{
	uint8_t Data;
	uint8_t direction;
	PORT_t port;
}PORT_Config_t;

//typedef struct
//{
//	Direction_t P0 : 1;
//	Direction_t P1 : 1;
//	Direction_t P2 : 1;
//	Direction_t P3 : 1;
//	Direction_t P4 : 1;
//	Direction_t P5 : 1;
//	Direction_t P6 : 1;
//	Direction_t P7 : 1;
//}BITS8_t;
//
//
//typedef	union
//{
//      BITS8_t bits;
//      uint8_t byte;
//}DIR_t;

/************************************************************************
  	  	  	  	  	  	  	  Function Decelerations
 ***********************************************************************/
void Port_Init(PORT_Config_t * Port);
void Write_Port(PORT_Config_t *Port);
void Read_Port(PORT_Config_t *Port);
void Write_Pin(PORT_t port, uint8_t pin, uint8_t Data);



#endif /* DIO_H_ */
