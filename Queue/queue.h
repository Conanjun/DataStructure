#ifndef _QUEUE_H
#define _QUEUE_H

#include "../custom_define.h"
typedef struct {
    ElemType data[Maxsize];
    int front,rear;
}SqQueue;

void InitQueue(SqQueue *q);
bool QueueEmpty(SqQueue q);
bool EnQueue(SqQueue *q,ElemType x);
bool DeQueue(SqQueue *q,ElemType *x);
void PrintQueue(SqQueue q);
#endif