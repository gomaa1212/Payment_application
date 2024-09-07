#include <stdio.h>
#include "file_handling.h"

List accounstList;
queu transActionQueue;
int lastSeqNum=0;

void readAccountDataDB()
{
    initial_list(&accounstList);
    FILE *myfile=fopen(FILEACOUNTNAME,"r");
    if(myfile==NULL)
    {
        printf("Failed to open accounts data file!! \n");
        return;
    }
    ST_accountsDB_t account;
    int i=0;
    char accountState[10];
    while(fscanf(myfile,"%f %s %s %s %s",&(account.balance),accountState,&(account.primaryAccountNumber),&(account.AccountName),&(account.AccountDate))==5)
    {
        account.state=getAccountStateToenum(accountState);
        insert_list(i++,account,&accounstList);
    }
    fclose(myfile);
}

int updateAccountBalane()
{
    FILE *myfile=fopen(FILEACOUNTNAME,"w");
    if(myfile==NULL)
    {
        printf("Failed to open accounts data file!! \n");
        return 0;
    }
    listnode *p=accounstList.head;
    while(p)
    {
        char *accountState=getAccountStateTostring(p->entry.state);
        fprintf(myfile,"%.2f %s %s %s %s\n",p->entry.balance,accountState,p->entry.primaryAccountNumber,p->entry.AccountName,p->entry.AccountDate);
        p=p->next;
    }
    fclose(myfile);
    return 1;
}

void readTransactionData()
{
    initial_queu(&transActionQueue);
    FILE *myfile=fopen(FILETRANSACTIONNAME,"r");
    if(myfile==NULL)
    {
        printf("Failed to open transaction data file!! \n");
        return ;
    }
    char strstate[30];
    ST_transaction_t transAction;
    while(fscanf(myfile,"%s %s %s %f %f %s %s %d",(transAction.cardHolderData.cardHolderName)
                                                  ,(transAction.cardHolderData.primaryAccountNumber)
                                                  ,(transAction.cardHolderData.cardExpirationDate)
                                                  ,&(transAction.terminalData.maxTransAmount)
                                                  ,&(transAction.terminalData.transAmount)
                                                  ,(transAction.terminalData.transactionDate)
                                                  ,strstate
                                                  ,&(transAction.transactionSequenceNumber))==8)
    {
        transAction.transState=getTransactionStateToenum(strstate);
        append(transAction,&transActionQueue);
        lastSeqNum=transAction.transactionSequenceNumber;
    }
    fclose(myfile);

}


void appendtransactioncardData(ST_transaction_t *transData)
{
    FILE *myfile=fopen(FILETRANSACTIONNAME,"a");
    if(myfile==NULL)
    {
        printf("Failed to open file for appending \n");
        return ;
    }
    char *strstate=getTransactionStateTostring(transData->transState);
     fprintf(myfile, "%s %s %s %.2f %.2f %s %s %d\n",
            transData->cardHolderData.cardHolderName,
            transData->cardHolderData.primaryAccountNumber,
            transData->cardHolderData.cardExpirationDate,
            transData->terminalData.maxTransAmount,
            transData->terminalData.transAmount,
            transData->terminalData.transactionDate,
            strstate,
            transData->transactionSequenceNumber);
        fclose(myfile);
}
