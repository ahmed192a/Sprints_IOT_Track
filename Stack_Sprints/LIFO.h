/*
 * LIFO.h
 *
 *  Created on: Aug 20, 2021
 *      Author: ah132
 */

#ifndef LIFO_H_
#define LIFO_H_

#include "stdio.h"
#include "stdlib.h"
#define int8_t char
#define uint8_t unsigned char
#define uint32_t unsigned long

//User Configuration
// select the element type (uint8_t, uint26_t, uint32_t ...)
#define element_type int8_t

// macros
#define DPRINTF(...) { fflush(stdout);\
		fflush(stdin);\
		printf(__VA_ARGS__);\
		fflush(stdout);\
		fflush(stdin);}
// type definitions
struct LIFO_data{
	element_type data;
	struct LIFO_data * Prev;
	struct LIFO_data * Next;
};

typedef struct LIFO_data LIFO_data_t;

typedef struct {
	uint32_t  count;
	struct LIFO_data * base;
	struct LIFO_data * head;
}LIFO_Buf_t;



typedef enum{
	LIFO_no_error,
	LIFO_empty,
	LIFO_Null
}LIFO_status;

// APIs
LIFO_status LIFO_Init(LIFO_Buf_t *lifo_buf);
LIFO_status LIFO_Add_Item(LIFO_Buf_t *lifo_buf, element_type item);
LIFO_status LIFO_Get_Item(LIFO_Buf_t *lifo_buf, element_type * item);
LIFO_status LIFO_Peek(LIFO_Buf_t *lifo_buf, element_type * item);
LIFO_status LIFO_Is_empty(LIFO_Buf_t *lifo_buf);


#endif /* LIFO_H_ */
