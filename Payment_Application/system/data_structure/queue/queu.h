#ifndef QUEU_H
#define QUEU_H
#include "../../../payment_system/server/server.h"
typedef ST_transaction_t queu_entry;

typedef struct queunode
{
    queu_entry entry;
    struct queunode *next;
}queunode;

typedef struct queu
{
    queunode *rear;
    queunode *Front;
    int Size;
}queu;

void initial_queu(queu *pq);
void append(queu_entry value,queu *pq);
void serve(queu_entry *value,queu *pq);
int queu_empty(queu *pq);
int queu_full(queu *pq);
int queu_size(queu *pq);
void traversequeu(queu* pq,void(*pf)(queu_entry));

#endif // QUEU_H

