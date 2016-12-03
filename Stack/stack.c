#ifndef _STACK_C
#define _STACK_C

#include "stack.h"

void InitStack(SqStack* s){
    s->top=-1;
}

bool StackEmpty(SqStack s){
    if(s.top==-1)
        return true;
    else
        return false;
}

bool Push(SqStack *s,ElemType x){
    if(s->top==Maxsize-1)
        return false;
    s->data[++s->top]=x;
    return true;
}

bool Pop(SqStack *s,ElemType *x){
    if(s->top==-1)
        return false;
    *x=s->data[s->top--];
    return true;
}

bool GetTop(SqStack s,ElemType *x){
    if(s.top==-1)
        return false;
    *x=s.data[s.top];
    return true;
}

void PrintStack(SqStack s){
    for(int i=0;i<=s.top;i++)
        printf(i?"% d":"%d",s.data[i]);
    printf("\n");
}

#endif
