#ifndef TERMINAL_H
#define TERMINAL_H
#include "../card/card.h"
#include <stdint.h>
typedef struct ST_terminalData_t
{
    float transAmount;
    float maxTransAmount;
    float maxDepositAmount;
    uint8_t transactionDate[11];
}ST_terminalData_t;

typedef enum EN_terminalError_t
{
    TERMINAL_OK, WRONG_DATE, EXPIRED_CARD, INVALID_CARD, INVALID_AMOUNT,
    EXCEED_MAX_AMOUNT, INVALID_MAX_AMOUNT
}EN_terminalError_t ;

void getTerminalData(ST_terminalData_t *termData);
EN_terminalError_t getTransactionDate(ST_terminalData_t *termData);
EN_terminalError_t isCardExpired(ST_cardData_t *cardData, ST_terminalData_t* termData);
EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData);
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData);




#endif // TERMINAL_H
