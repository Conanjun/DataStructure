#ifndef _BITNODE_QUEUE_H
#define _BITNODE_QUEUE_H

#include "bitnode_queue.h"

void InitBiTNodeQueue(SqBiTNodeQueue *q){
    q->rear=q->front=0;
}

bool BiTNodeQueueEmpty(SqBiTNodeQueue q){
    if(q.rear==q.front)
        return true;
    else
        return false;
}

bool EnBiTNodeQueue(SqBiTNodeQueue *q,BiTNode x){
    if((q->rear+1)%Maxsize==q->front)
        return false;
    q->data[q->rear]=x;
    q->rear=(q->rear+1)%Maxsize;
    return true;
}

bool DeBiTNodeQueue(SqBiTNodeQueue *q,BiTNode *x){
    if(q->rear==q->front)
        return false;
    *x=q->data[q->front];
    q->front=(q->front+1)%Maxsize;
    return true;
}

void PrintBiTNodeQueue(SqBiTNodeQueue q){
    int start=q.front;
    int i=q.front;
    int j=q.rear;
    if(i<j){
        while(i<j)
        {
            printf(i==start?"%d":" %d",q.data[i].data);
            i++;
        }
        printf("\n");
    }
    else if(i>j){
        while(i<Maxsize)
        {
            printf(i==start?"%d":" %d",q.data[i].data);
            i++;
        }
        i=i%Maxsize;//i=0
        while(i<j){
            printf(i==0?"%d":" %d",q.data[i].data);
        }
        printf("\n");
    }
}

#endif