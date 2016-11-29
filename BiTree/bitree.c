#include <stdio.h>
#include <stdlib.h>
#include "bitree.h"
#include "bitnode_stack.c"
#include "bitnode_queue.h"

void visit(BiTree T){
    printf("%c",T->data);
}

BiTree CreateBiTree(){
    char ch;
    BiTree T;
    //scanf为%c时会读取回车，应去除
    scanf("%c%*c",&ch);
    //printf("%c",ch);
    //ch=getchar();
    if(ch=='#')
        T=NULL;
    else{
        T=(BiTNode*)malloc(sizeof(BiTNode));//*root 即表示了该BiTNode块
        T->data=ch;
        printf("请输入%c结点的左子结点:",T->data);
        T->lchild=CreateBiTree();
        printf("请输入%c结点的右子结点:",T->data);
        T->rchild=CreateBiTree();
    }
    return T;
}

void PreOrder(BiTree T){
    if(T!=NULL){
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(BiTree T){
    if(T!=NULL){
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

void PostOrder(BiTree T){
    if(T!=NULL){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}


void InOrderByStack(BiTree T){
    BiTNodeStack s;
    InitBiTNodeStack(&s);
    BiTNode *p=T;
    while(p || !BiTNodeStackEmpty(s)){
        if(p){
            //根指针进栈，遍历左子树
            BiTNodeStackPush(&s,*p);
            p=p->lchild;
        }else{
            //根指针退栈，访问根结点，遍历右子树
            BiTNodeStackPop(&s,&p);
            visit(p);
            p=p->rchild;
        }
    }
}

void LevelOrder(BiTree T){
    SqBiTNodeQueue sq;
    InitBiTNodeQueue(&sq);
    //BiTNode *p=T;//这里写法错误，这样后面的出队列会直接修改树
    BiTNode p;
    EnBiTNodeQueue(&sq,*T);
    while(!BiTNodeQueueEmpty(sq)){
        DeBiTNodeQueue(&sq,&p);
        visit(&p);
        if(p.lchild!=NULL)
            EnBiTNodeQueue(&sq,*(p.lchild));
        if(p.rchild!=NULL)
            EnBiTNodeQueue(&sq,*(p.rchild));
    }
}

//竖向打印树
void PrintTree(BiTree T,int nlayer){
    if(T == NULL) return;
    PrintTree(T->rchild,nlayer+1);
    for(int i=0;i<nlayer;i++)
        printf("  ");
    printf("%c\n",T->data);
    PrintTree(T->lchild,nlayer+1);
}
