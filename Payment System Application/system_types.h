/*
 * system_types.h
 *
 *  Created on: Aug 29, 2021
 *      Author: ah132
 */

#ifndef SYSTEM_TYPES_H_
#define SYSTEM_TYPES_H_

#define MAX_TRANSACTION_AMOUNT 5000

typedef  char uint8_t;
typedef char int8_t;
typedef int int32_t;
typedef unsigned int uint32_t;


typedef struct ST_cardData_t{
	uint8_t cardHolderName[25];
	uint8_t primaryAccountNumer[20];
	uint8_t cardExpirationDate[6];
}ST_cardData_t;

typedef struct ST_terminalData_t{
	float transAmount;
	//float maxTransAmount;
	uint8_t transactionDate[11];
} ST_terminalData_t;

typedef enum EN_transStat_t{
	DECLINED,
	APPROVED
}EN_transStat_t;

typedef struct ST_transaction_t{
	ST_cardData_t cardHolderData;
	ST_terminalData_t transData;
	EN_transStat_t transStat;
}ST_transaction_t;

typedef struct ST_accountBalance_t{
	float balance;
	uint8_t primaryAccountNumber[20];
} ST_accountBalance_t;

typedef struct ST_transactionData_t{

}ST_transactionData_t;


#endif /* SYSTEM_TYPES_H_ */
