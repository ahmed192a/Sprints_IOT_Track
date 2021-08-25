/*
 * main.c
 *
 *  Created on: Aug 20, 2021
 *      Author: ah132
 */



#include "LIFO.h"
element_type buffer1[5];

int main(){
	element_type temp;
	int8_t s[40];
	int8_t *ptr;
	LIFO_Buf_t Stack;
	//static allocation
	LIFO_Init(&Stack);

	DPRINTF("Enter string to check: ");
	gets(s);
	ptr= s;
	while(*ptr!= '\0'){
		//DPRINTF("-----------%c\n", *ptr);
		if(*ptr =='(' || *ptr == '{'){
			if(LIFO_Add_Item(&Stack, *ptr)== LIFO_no_error){
				DPRINTF("Stack add : %c \n", *ptr);
			}
		}
		else if(*ptr == ')'){

			if(LIFO_Peek(&Stack, &temp)==LIFO_no_error){
				if(temp == '('){
					LIFO_Get_Item(&Stack, &temp);
					DPRINTF("Stack get : %c \n", temp);
				}
				else{
					LIFO_Add_Item(&Stack, *ptr);
				}
			}
		}
		else if(*ptr == '}'){
			if(LIFO_Peek(&Stack, &temp)==LIFO_no_error){
				if(temp == '{'){
					LIFO_Get_Item(&Stack, &temp);
					DPRINTF("Stack get : %c \n", temp);
				}
				else{
					LIFO_Add_Item(&Stack, *ptr);
				}
			}
		}
		ptr++;
	}
	if(LIFO_Is_empty(&Stack)==LIFO_empty){
		DPRINTF("Balanced");
	}
	else{
		DPRINTF("Not Balanced");
	}


	return 0;
}
