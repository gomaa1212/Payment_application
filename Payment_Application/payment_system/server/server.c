#include "server.h"
#include <stdio.h>
#include <stdbool.h>
#include "../../system/data_structure/ist/list.h"
#include "../../system/data_bases/file_handling.h"
#include "../../system/data_structure/queue/queu.h"

// Validate account details
EN_serverError_t isValidAccount(ST_cardData_t *cardData, ST_accountsDB_t** accountRefrence)
{
    if(cardData==NULL||accountRefrence==NULL)
    {
        return ACCOUNT_NOT_FOUND;
    }
    readAccountDataDB();
    listnode *p;
    p=accounstList.head;
    while(p)
    {
        if(strcmp(cardData->primaryAccountNumber,p->entry.primaryAccountNumber)==0)
        {
            if(strcmp(cardData->cardHolderName,p->entry.AccountName)==0)
            {
                if(strcmp(cardData->cardExpirationDate,p->entry.AccountDate)==0)
                {
                    *accountRefrence=&(p->entry);
                    return SERVER_OK;

                }
            }
        }
        p=p->next;
    }
    *accountRefrence=NULL;
    return ACCOUNT_NOT_FOUND ;
}

// Validate receiver's account
EN_serverError_t isValidAccountReceiver(ST_cardData_t *cardData, ST_accountsDB_t** accountRefrence)
{
      if(cardData==NULL||accountRefrence==NULL)
      {
        return ACCOUNT_NOT_FOUND;
      }
      listnode *p;
      p=accounstList.head;
      while(p)
      {
          if(strcmp(cardData->primaryAccountNumber,p->entry.primaryAccountNumber)==0)
          {
              *accountRefrence=&(p->entry);
                return SERVER_OK;
          }
          p=p->next;
      }
    *accountRefrence=NULL;
    return ACCOUNT_NOT_FOUND ;
}

// Check if account is blocked
EN_serverError_t isBlockedAccount(ST_accountsDB_t *accountRefrence)
{
    if(accountRefrence==NULL)
    {
        return ACCOUNT_NOT_FOUND;
    }
    if(accountRefrence->state==0)
    {
        return BLOCKED_ACCOUNT;
    }
    if(accountRefrence->state==1)
    {
        return SERVER_OK;
    }
    return ACCOUNT_NOT_FOUND;
}

// Check if sufficient funds are available
EN_serverError_t isAmountAvailable(ST_terminalData_t *termData,ST_accountsDB_t* accountRefrence)
{
    if(termData==NULL||accountRefrence==NULL)
    {
        return ACCOUNT_NOT_FOUND;
    }
    if(termData->transAmount>accountRefrence->balance)
    {
        return LOW_BALANCE;
    }
    return SERVER_OK;
}

// Convert transaction state string to enum
EN_transState_t getTransactionStateToenum(char *strstate)
{
    if(strcmp(strstate,"APPROVED")==0)
        return APPROVED;
    if(strcmp(strstate,"DECLINED_INSUFFECIENT_FUND")==0)
        return DECLINED_INSUFFECIENT_FUND;
    if(strcmp(strstate,"DECLINED_STOLEN_CARD")==0)
        return DECLINED_STOLEN_CARD;
    if(strcmp(strstate,"FRAUD_CARD")==0)
        return FRAUD_CARD;
    if(strcmp(strstate,"INTERNAL_SERVER_ERROR")==0)
        return INTERNAL_SERVER_ERROR;
    if(strcmp(strstate,"DECLINED_EXCEED_LIMIT")==0)
        return DECLINED_EXCEED_LIMIT;
    return INTERNAL_SERVER_ERROR;

}

// Convert transaction state enum to string
char *getTransactionStateTostring(EN_transState_t enumstate)
{
    if(enumstate==APPROVED)
        return "APPROVED";
    if(enumstate==DECLINED_INSUFFECIENT_FUND)
        return "DECLINED_INSUFFECIENT_FUND";
    if(enumstate==DECLINED_STOLEN_CARD)
        return "DECLINED_STOLEN_CARD";
    if(enumstate==FRAUD_CARD)
        return "FRAUD_CARD";
    if(enumstate==INTERNAL_SERVER_ERROR)
        return "INTERNAL_SERVER_ERROR";
    if(enumstate==DECLINED_EXCEED_LIMIT)
        return "DECLINED_EXCEED_LIMIT";
    return "INTERNAL_SERVER_ERROR";
}

// List saved transactions for a specific card
void listSavedTransactions(ST_transaction_t *transData)
{
    bool flag=false;
    readTransactionData();
    queunode *q=transActionQueue.Front;
    while(q)
    {
        if(strcmp(q->entry.cardHolderData.primaryAccountNumber,transData->cardHolderData.primaryAccountNumber)==0)
        {
            printf("_______________________________________________________________________\n");
            printf("|                                                                     |\n");
            printf("| Transaction Sequence Number : %-37d |\n", q->entry.transactionSequenceNumber);
            printf("| Transaction Date            : %-37s |\n", q->entry.terminalData.transactionDate);
            printf("| Transaction Amount          : %-37.2f |\n",q->entry.terminalData.transAmount);
            switch(q->entry.transState)
            {
            case APPROVED:
                printf("| Transaction State           : APPROVED                              |\n");
                break;
            case DECLINED_INSUFFECIENT_FUND:
                printf("| Transaction State           : DECLINED_INSUFFECIENT_FUND            | \n");
                break;
            case DECLINED_STOLEN_CARD:
                printf("| Transaction State           : DECLINED_STOLEN_CARD                  |\n");
                break;
            case FRAUD_CARD:
                printf("| Transaction State           : FRAUD_CARD                            |\n");
                break;
            case INTERNAL_SERVER_ERROR:
                printf("| Transaction State           : INTERNAL_SERVER_ERROR                 |\n");
                break;
            case DECLINED_EXCEED_LIMIT:
                printf("| Transaction state           : DECLINED_EXCEED_LIMIT                 |\n");
                break;
            default:
                printf("| Transaction State           : UNKNOWN                               |\n");
                break;
            }
              printf("| Terminal Max Amount         : %-37.2f |\n", q->entry.terminalData.maxTransAmount);
              printf("| Cardholder Name             : %-37s |\n", q->entry.cardHolderData.cardHolderName);
              printf("| PAN                         : %-37s |\n", q->entry.cardHolderData.primaryAccountNumber);
              printf("| Card Expiration Date        : %-37s |\n", q->entry.cardHolderData.cardExpirationDate);
              printf("|_____________________________________________________________________|\n");

            flag=true;
        }
        q=q->next;
    }
    if(!flag)
    {
        printf("There are no money transfers.\n");
    }

}

// Save transaction details
EN_serverError_t saveTransaction(ST_transaction_t *transData)
{
    if(transData==NULL)
    {
        return INTERNAL_SERVER_ERROR;
    }
    readTransactionData();
    transData->transactionSequenceNumber=lastSeqNum+1;
    appendtransactioncardData(transData);
    append(*transData,&transActionQueue);
    return SERVER_OK;
}

// Handle money transfer process
void handleMoneyTransfer(ST_transaction_t *transData, ST_accountsDB_t *accountReference) {
    int choice = TransferMoneyMenu();
    ST_accountsDB_t *receivingAccountReference = NULL;
    bool invalidReceivingAccount = false;

    if (choice == 1) {
        // Transfer money to another account
        ST_cardData_t receiveAccount;
        printf("Enter the receiving account number: ");
        scanf("%s", receiveAccount.primaryAccountNumber);

        // Validate receiving account
        EN_serverError_t isValidReceivingAccount = isValidAccountReceiver(&receiveAccount, &receivingAccountReference);
        if (isValidReceivingAccount == ACCOUNT_NOT_FOUND) {
            printf("The account does not exist.\n");
            transData->transState = FRAUD_CARD;
            invalidReceivingAccount = true;
        }
    }

    // Process transaction amount
    bool invalidAmount = false;
    if (!invalidReceivingAccount) {
        EN_terminalError_t amountError;
        do {
            amountError = getTransactionAmount(&transData->terminalData);
            if (amountError == INVALID_AMOUNT) {
                printf("Invalid amount! Please enter a valid amount.\n");
            }
        } while (amountError == INVALID_AMOUNT);

        //delay 5 sec for transaction processing
        printf("Please wait for transaction processing...\n");
        sleep(5);

        // Check if the amount exceeds maximum allowed
        EN_terminalError_t belowMax = isBelowMaxAmount(&transData->terminalData);
        if (belowMax == EXCEED_MAX_AMOUNT) {
            printf("Declined! Amount exceeds the limit.\n");
            transData->transState=DECLINED_EXCEED_LIMIT;
            invalidAmount = true;
        }
    }

    // Check for sufficient balance
    bool insufficientFunds = false;
    if (!invalidAmount && !invalidReceivingAccount) {
        EN_serverError_t availableAmount = isAmountAvailable(&transData->terminalData, accountReference);
        if (availableAmount == LOW_BALANCE) {
            printf("Declined! Insufficient funds.\n");
            transData->transState = DECLINED_INSUFFECIENT_FUND;
            insufficientFunds = true;
        }
    }
    // Complete the transaction
    if (!insufficientFunds && !invalidReceivingAccount && !invalidAmount) {
        if (choice == 1) {
            // Update receiving account balance
            receivingAccountReference->balance += transData->terminalData.transAmount;
        }

        // Update sender account balance
        accountReference->balance -= transData->terminalData.transAmount;
        updateAccountBalane();
        transData->transState = APPROVED;
        printf("Your transaction has been successfuly completed.\n");
    }

    // Save transaction details
    saveTransaction(transData);
}

void handleMoneyDeposit(ST_transaction_t *transData, ST_accountsDB_t *accountReference)
{
    float deposit;
    printf("Please enter the deposit amount : ");
    scanf("%f",&deposit);
    printf("Please wait for processing...\n");
    sleep(5);   // Wait for 5 seconds to simulate processing
    // Check if the deposit amount exceeds the maximum allowed deposit
    if(deposit>transData->terminalData.maxDepositAmount)
    {
        printf("You have exceeded the maximum deposit limit.\n");
        return ;
    }
    // Add the deposit amount to the account balance
    accountReference->balance+=deposit;
     // Update the account balance in the database
    updateAccountBalane();
    printf("Your deposit has been successfuly completed.\n");
}
