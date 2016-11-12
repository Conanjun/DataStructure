#ifndef _BITNODE_STACK_C
#define _BITNODE_STACK_C
#include "bitnode_stack.h"

void InitBiTNodeStack(BiTNodeStack *s){
    s->top=-1;
}

bool BiTNodeStackEmpty(BiTNodeStack s){
    if(s.top==-1)
        return true;
    else
        return false;
}

bool BiTNodeStackPush(BiTNodeStack *s,BiTNode x){
    if(s->top==Maxsize-1)
        return false;
    // 结构体赋值 纯C的话不能直接用=，需要用memcpy
    s->data[++s->top]=x;
    return true;
}

bool BiTNodeStackPop(BiTNodeStack *s,BiTNode **x){
    if(s->top==-1)
        return false;
    *x=&(s->data[s->top--]);//修改x的指向，故应该用二重指针
    return true;
}

bool BiTNodeStackGetTop(BiTNodeStack s,BiTNode *x){
    if(s.top==-1)
        return false;
    *x=s.data[s.top];
    return true;
}

void PrintBiTNodeStack(BiTNodeStack s){
    for(int i=0;i<=s.top;i++)
        printf(i?" %c":"%c",s.data[i].data);
    printf("\n");
}

#endif