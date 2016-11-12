#include <stdio.h>
#include "../BiTree/bitnode_stack.c"

void testBiTNodeStack() {
    //测试结构体是否能直接赋值
    BiTNode data[3];
    BiTNode p,q,r;
    p.data='a';
    q.data='b';
    r.data='c';
    p.lchild=&q;
    p.rchild=&r;
    q.lchild=q.rchild=NULL;
    r.lchild=r.rchild=NULL;
    data[0]=p;
    printf("%c\n",data[0].data);
    printf("%c\n",data[0].lchild->data);
    printf("%c\n",data[0].rchild->data);
    //测试BiTNodeStackPush BiTNodeStack GetTop
    BiTNodeStack s;
    InitBiTNodeStack(&s);
    BiTNodeStackPush(&s,p);
    BiTNodeStackPush(&s,q);
    BiTNodeStackPush(&s,r);
    PrintBiTNodeStack(s);
    BiTNode *temp;
    BiTNodeStackPop(&s,&temp);
    printf("%c\n",temp->data);
    PrintBiTNodeStack(s);
    BiTNodeStackPop(&s,&temp);
    BiTNodeStackPop(&s,&temp);
    printf("temp--->%c %c %c\n",temp->data,temp->lchild->data,temp->rchild->data);
}