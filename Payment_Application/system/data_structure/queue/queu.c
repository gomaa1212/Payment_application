#include "queu.h"
#include <stdio.h>
#include <stdlib.h>

void initial_queu(queu *pq)
{
    pq->Front=NULL;
    pq->rear=NULL;
    pq->Size=0;
}
void append(queu_entry value,queu *pq)
{
    queunode *q=(queunode*)malloc(sizeof(queunode));
    q->entry=value;
    q->next=NULL;
    if(pq->rear==NULL)
    {
        pq->Front=q;
    }
    else
    {
        pq->rear->next=q;
    }
    pq->rear=q;
    pq->Size++;
}
void serve(queu_entry *value,queu *pq)
{
    if(queu_empty(pq))
    {
        printf("queu is empty \n");
        return ;
    }
    queunode *q;
    q=pq->Front;
    *value=q->entry;
    pq->Front=q->next;
    pq->Size--;
    free(q);
    if(pq->Front==NULL)
    {
        pq->rear=NULL;
    }
}
int queu_empty(queu *pq)
{
    return pq->Size==0;
}
int queu_full(queu *pq)
{
    return 0;
}
int queu_size(queu *pq)
{
    return pq->Size;
}
void clear_queu(queu *pq)
{
    queunode *q;
    while(pq->Front==NULL)
    {
        q=pq->Front;
        pq->Front=q->next;
        free(q);
    }
    pq->rear=NULL;
    pq->Size=0;
}
void traversequeu(queu* pq,void(*pf)(queu_entry))
{
    queunode *q;
    while(pq->Front!=NULL)
    {
        q=pq->Front;
        (*pf)(q->entry);
        pq->Front=q->next;
    }
}

