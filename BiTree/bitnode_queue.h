#ifndef BITNODE_QUEUE_H
#define BITNODE_QUEUE_H

#include "bitree.h"
typedef struct {
    BiTNode data[Maxsize];
    int front,rear;
}SqBiTNodeQueue;

void InitBiTNodeQueue(SqBiTNodeQueue *q);
bool BiTNodeQueueEmpty(SqBiTNodeQueue q);
bool EnBiTNodeQueue(SqBiTNodeQueue *q,BiTNode x);
bool DeBiTNodeQueue(SqBiTNodeQueue *q,BiTNode *x);
void PrintBiTNodeQueue(SqBiTNodeQueue q);
#endif
