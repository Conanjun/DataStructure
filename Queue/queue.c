#ifndef _QUEUE_C
#define _QUEUE_C
#include "queue.h"

void InitQueue(SqQueue *q){
    q->rear=q->front=0;
}

bool QueueEmpty(SqQueue q){
    if(q.rear==q.front)
        return true;
    else
        return false;
}

bool EnQueue(SqQueue *q,ElemType x){
    if((q->rear+1)%Maxsize==q->front)
        return false;
    q->data[q->rear]=x;
    q->rear=(q->rear+1)%Maxsize;
    return true;
}

bool DeQueue(SqQueue *q,ElemType *x){
    if(q->rear==q->front)
        return false;
    *x=q->data[q->front];
    q->front=(q->front+1)%Maxsize;
    return true;
}

void PrintQueue(SqQueue q){
    int start=q.front;
    int i=q.front;
    int j=q.rear;
    if(i<j){
        while(i<j)
        {
            printf(i==start?"%d":" %d",q.data[i]);
            i++;
        }
        printf("\n");
    }
    else if(i>j){
        while(i<Maxsize)
        {
            printf(i==start?"%d":" %d",q.data[i]);
            i++;
        }
        i=i%Maxsize;//i=0
        while(i<j){
            printf(i==0?"%d":" %d",q.data[i]);
        }
        printf("\n");
    }
}

#endif