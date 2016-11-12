#include <stdio.h>
#include "../Stack/stack.c"

void testStack() {
    SqStack s;
    InitStack(&s);
    for (int i = 0; i < 10; i++)
        Push(&s, i);
    PrintStack(s);
    ElemType x;
    Pop(&s, &x);
    printf("%d\n", x);
    PrintStack(s);
    GetTop(s, &x);
    printf("%d\n", x);
    PrintStack(s);
    for (int i = 0; i < 9; i++)
        Pop(&s, &x);
    if (StackEmpty(s))
        printf("stack s is empty now\n");
    printf("%d\n", Pop(&s, &x));//验证栈空无法pop
    for (int i = 0; i < Maxsize; i++)
        Push(&s, i);
    printf("%d\n", Push(&s, x));//验证栈满无法push
}