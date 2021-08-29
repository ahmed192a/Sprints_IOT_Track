/*
 * main.c
 *
 *  Created on: Aug 29, 2021
 *      Author: ah132
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "system_types.h"

// macros
#define DPRINTF(...) { fflush(stdout);\
		fflush(stdin);\
		printf(__VA_ARGS__);\
		fflush(stdout);\
		fflush(stdin);}

// Global variables
ST_accountBalance_t g_serverData [10] ={{100.0,"123456789"}, {6000,"234567891"},{3250.25,"567891234"},{1500.12,"456789123"},{500,"258649173"},{2100,"654823719"},{0,"971362485"},{1.0,"793148625"},{10.12,"123123456"},{0.55,"456789321"}};

uint8_t check_date(uint8_t cardExpirationDate[], uint8_t transactionDate[]);
uint8_t Check_Account_in_Server(uint8_t primaryAccountNumer[]);


int main(){
	uint8_t choice[5], temp[20];
	int32_t index;
	ST_transaction_t transaction;
	do{
		DPRINTF("\n\tEnter Card Data ..\n");

		DPRINTF("Please Enter The Card Holder Name : ");
		gets(transaction.cardHolderData.cardHolderName);
		DPRINTF("Please Enter The Primary Account Number : ");
		gets(transaction.cardHolderData.primaryAccountNumer);
		DPRINTF("Please Enter The Card Expire Date : ");
		gets(transaction.cardHolderData.cardExpirationDate);

		DPRINTF("\n\tEnter Terminal Data ..\n");

		DPRINTF("Please Enter The Transaction Amount : ");
		gets(temp);
		transaction.transData.transAmount = atof(temp);

		// is Amount Accepted by terminal
		if(transaction.transData.transAmount < MAX_TRANSACTION_AMOUNT){
			DPRINTF("Please Enter The Transaction Date : ");
			gets(transaction.transData.transactionDate);
			// check if card is expired
			if(check_date(transaction.cardHolderData.cardExpirationDate,transaction.transData.transactionDate)){
				DPRINTF("Verifying Data From The Server...\n");
				// check if account exist in server
				index = Check_Account_in_Server(transaction.cardHolderData.primaryAccountNumer);
				if(index!=-1){
					if(g_serverData[index].balance>=transaction.transData.transAmount){
						transaction.transStat= APPROVED;
					}
					else{
						transaction.transStat= DECLINED;
					}
				}
				else{
					transaction.transStat= DECLINED;
				}
			}
			else{
				transaction.transStat= DECLINED;
			}
		}
		else{
			transaction.transStat= DECLINED;
		}
		switch(transaction.transStat){
		case APPROVED:
			DPRINTF("The Transaction is APPROVED\n");
			break;
		case DECLINED:
			DPRINTF("The Transaction is DECLINED\n");
			break;
		}
		DPRINTF("\nDo You Want To Continue?(y/n)\n");
		gets(choice);
	}while(choice[0] == 'y' || choice[0] == 'Y');


	return 0;
}



uint8_t check_date(uint8_t cardExpirationDate[], uint8_t transactionDate[]){
	if(transactionDate[3] < cardExpirationDate[0]){
		return 1;
	}
	else if(transactionDate[3] == cardExpirationDate[0]){
		if(transactionDate[4] < cardExpirationDate[1]){
			return 1;
		}
		else if(transactionDate[4] == cardExpirationDate[1]){
			if(transactionDate[0] == cardExpirationDate[3]){
				return 1;
			}
			else  if(transactionDate[0] == cardExpirationDate[3]){
				if(transactionDate[1] <= cardExpirationDate[4]){
					return 1;
				}
			}

		}

	}
	return 0;
}

int8_t Check_Account_in_Server(uint8_t primaryAccountNumer[]){
	int i;
	for(i = 0; i< 10; i++){
		if(!strcmp(g_serverData[i].primaryAccountNumber, primaryAccountNumer)){
			return i;
		}
	}
	return -1;
}
