#ifndef _BITNODE_STACK_H

#define _BITNODE_STACK_H

// 注意此处不能引用bitree.c,包含了同名方法
#include "bitree.h"

//栈存放指向结构体BiTNode的指针
typedef struct {
    BiTNode data[Maxsize];
    int top;
}BiTNodeStack;

void InitBiTNodeStack(BiTNodeStack* s);

bool BiTNodeStackEmpty(BiTNodeStack s);

bool BiTNodeStackPush(BiTNodeStack *s,BiTNode x);

bool BiTNodeStackPop(BiTNodeStack *s,BiTNode *x);

bool BiTNodeStackGetTop(BiTNodeStack s,BiTNode *x);

void PrintBiTNodeStack(BiTNodeStack s);

#endif
