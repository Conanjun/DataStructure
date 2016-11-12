#include "../custom_define.h"

typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}*LinkStack;

void initStack(LinkStack s);

bool StackEmpty(const LinkStack s);

bool Push(LinkStack s,ElemType x);

bool Pop(LinkStack s,ElemType *x);

bool GetTop(const LinkStack s,ElemType *x);

void PrintStack(const LinkStack s);
