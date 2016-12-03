#ifndef _STACK_H
#define _STACK_H

#include "../custom_define.h"

typedef struct {
    ElemType data[Maxsize];
    int top;
}SqStack;

void InitStack(SqStack* s);

bool StackEmpty(SqStack s);

bool Push(SqStack *s,ElemType x);

bool Pop(SqStack *s,ElemType *x);

bool GetTop(SqStack s,ElemType *x);

void PrintStack(SqStack s);

#endif
