#ifndef SERVER_H
#define SERVER_H
#include "../card/card.h"
#include "../terminal/terminal.h"



typedef enum EN_transState_t
{
    APPROVED, DECLINED_INSUFFECIENT_FUND, DECLINED_STOLEN_CARD,
    FRAUD_CARD, INTERNAL_SERVER_ERROR,DECLINED_EXCEED_LIMIT
}EN_transState_t;

typedef struct ST_transaction_t
{
    ST_cardData_t cardHolderData;
    ST_terminalData_t terminalData;
    EN_transState_t transState;
    uint32_t transactionSequenceNumber;
}ST_transaction_t;

typedef enum EN_serverError_t
{
    SERVER_OK, SAVING_FAILED, TRANSACTION_NOT_FOUND, ACCOUNT_NOT_FOUND,
    LOW_BALANCE, BLOCKED_ACCOUNT
}EN_serverError_t ;
typedef enum EN_accountState_t
{
    BLOCKED,
    RUNNING
}EN_accountState_t;

typedef struct ST_accountsDB_t
{
    float balance;
    EN_accountState_t state;
    uint8_t primaryAccountNumber[20];
    uint8_t AccountName[25];
    uint8_t AccountDate[6];

}ST_accountsDB_t;

EN_transState_t recieveTransactionData(ST_transaction_t *transData);
EN_serverError_t isValidAccount(ST_cardData_t *cardData, ST_accountsDB_t** accountRefrence);
EN_serverError_t isValidAccountReceiver(ST_cardData_t *cardData, ST_accountsDB_t** accountRefrence);
EN_serverError_t isBlockedAccount(ST_accountsDB_t *accountRefrence);
EN_serverError_t isAmountAvailable(ST_terminalData_t *termData,ST_accountsDB_t* accountRefrence);
void listSavedTransactions(ST_transaction_t *transData);
EN_transState_t getTransactionStateToenum(char *strstate);
char *getTransactionStateTostring(EN_transState_t enumstate);
void handleMoneyTransfer(ST_transaction_t *transData, ST_accountsDB_t *accountReference);
void handleMoneyDeposit(ST_transaction_t *transData, ST_accountsDB_t *accountReference);

#endif // SERVER_H
