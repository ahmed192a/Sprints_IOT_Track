/*
 * LIFO.c
 *
 *  Created on: Aug 20, 2021
 *      Author: ah132
 */


#include "LIFO.h"
LIFO_status LIFO_Init(LIFO_Buf_t *lifo_buf){
	lifo_buf->base = NULL;
	lifo_buf->head = NULL;
	lifo_buf->count = 0;
	return LIFO_no_error;
}
LIFO_status LIFO_Add_Item(LIFO_Buf_t *lifo_buf, element_type item){
	// check if LIFO is empty
	if(lifo_buf->count == 0){
		lifo_buf->head = (LIFO_data_t *)malloc(sizeof(LIFO_data_t));
		lifo_buf->base = lifo_buf->head;
		lifo_buf->head->data = item;
		lifo_buf->head->Next = NULL;
		lifo_buf->head->Prev = NULL;
		lifo_buf->count++;
		return LIFO_no_error;
	}
	// add value
	lifo_buf->head->Next = (struct LIFO_data *)malloc(sizeof(struct LIFO_data));
	lifo_buf->head->Next->Prev = lifo_buf->head;
	lifo_buf->head = lifo_buf->head->Next;
	lifo_buf->head->data = item;
	lifo_buf->head->Next = NULL;
	lifo_buf->count++;
	return LIFO_no_error;
}
LIFO_status LIFO_Get_Item(LIFO_Buf_t *lifo_buf, element_type * item){
	// check if LIFO is valid
	if(lifo_buf->count == 0 ){
			return LIFO_empty;
	}
	// get value
	*item = lifo_buf->head->data;
	if(lifo_buf->head->Prev){
		lifo_buf->head = lifo_buf->head->Prev;
		free (lifo_buf->head->Next);
		lifo_buf->head->Next = NULL;
	}
	else{
		free (lifo_buf->head);
		lifo_buf->head = NULL;
		lifo_buf->base = NULL;
	}
	lifo_buf->count--;
	return LIFO_no_error;
}

LIFO_status LIFO_Peek(LIFO_Buf_t *lifo_buf, element_type * item){
	// check if LIFO is valid
	if(lifo_buf->count == 0 ){
			return LIFO_empty;
	}
	// get value
	*item = lifo_buf->head->data;
	return LIFO_no_error;
}

LIFO_status LIFO_Is_empty(LIFO_Buf_t *lifo_buf){
	// check if LIFO is valid
	if(lifo_buf->count == 0 ){
			return LIFO_empty;
	}
	return LIFO_no_error;
}

