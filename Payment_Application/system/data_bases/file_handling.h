#ifndef FILE_H
#define FILE_H
#include "../../payment_system/server/server.h"
#include "../data_structure/list/list.h"
#include "../data_structure/queue/queu.h"

#define FILEACOUNTNAME "accounts.txt"
#define FILETRANSACTIONNAME "transaction.txt"


extern queu transActionQueue;
extern List accounstList;
extern int lastSeqNum;
void readAccountDataDB();
void  readTransactionData();
void appendtransactioncardData(ST_transaction_t *transData);
int updateAccountBalane();

#endif // FILE_H
