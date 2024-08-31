#include "terminal.h"
#include "string.h"
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <stdio.h>


void getTerminalData(ST_terminalData_t *termData)
{
    termData->maxTransAmount=70000;
    termData->maxDepositAmount=20000;
    termData->transAmount=0;
    strcpy(termData->transactionDate,"");
}

EN_terminalError_t getTransactionDate(ST_terminalData_t *termData)
{
    if(termData==NULL)
    {
        return WRONG_DATE;
    }
    // Get the current date and format it as "DD/MM/YYYY".
    time_t currentTime;
    struct tm *localTime;
    time(&currentTime);
    localTime = localtime(&currentTime);
    strftime(termData->transactionDate, sizeof(termData->transactionDate), "%d/%m/%Y", localTime);
    return TERMINAL_OK;
}

EN_terminalError_t isCardExpired(ST_cardData_t *cardData, ST_terminalData_t* termData)
{
    int cardyear;
    // Extract the card expiration year and month from the card data
    cardyear=(cardData->cardExpirationDate[4])-'0'+((cardData->cardExpirationDate[3])-'0')*10;
    int cardmonth;
    cardmonth=(cardData->cardExpirationDate[1])-'0'+((cardData->cardExpirationDate[0])-'0')*10;

    int transyear;
    // Extract the transaction year and month from the terminal data.
    transyear=((termData->transactionDate[9])-'0')+((termData->transactionDate[8])-'0')*10;
    int transmonth;
    transmonth=((termData->transactionDate[4])-'0')+((termData->transactionDate[3])-'0')*10;

    if(transyear>cardyear)
    {
        return EXPIRED_CARD;
    }
    if(transyear==cardyear&&transmonth>cardmonth)
    {
        return EXPIRED_CARD;
    }
    return TERMINAL_OK;
}

EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData)
{
    if(termData==NULL)
    {
        return INVALID_AMOUNT;
    }
    printf("enter transaction amount : ");
    float trans_amount;
    scanf("%f",&trans_amount);
    if(trans_amount<=0)
    {
        return INVALID_AMOUNT;
    }
    termData->transAmount=trans_amount;
    return TERMINAL_OK;
}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData)
{
    if(termData==NULL)
    {
        return EXCEED_MAX_AMOUNT;
    }
    if((termData->transAmount)>termData->maxTransAmount)
    {
        return EXCEED_MAX_AMOUNT;
    }
    return TERMINAL_OK;
}




