#ifndef _AVLTREE_C
#define _AVLtREE_C

#include "avltree.h"

//这里注意下命名
// 左单旋转适用于RR型
// 右单旋转适用于LL型
// 先左后右适用于LR型
// 先右后左适用于RL型

int GetBalance(AVLTNode *p) {
    if(p == NULL)
        return -1;
    else
        return p->balance;
}

//见single_rotate_with_rr.png
void SingleRotateWithRR(AVLTNode **k2){
    AVLTNode *k1;
    k1=(*k2)->rchild;
    //看图分析知仅仅需要修改两条线
    (*k2)->rchild=k1->lchild;
    k1->lchild=(*k2);
    //更新k1 k2的高度
    k1->balance=GetBalance(k1->lchild)>GetBalance(k1->rchild)?GetBalance(k1->lchild)+1:GetBalance(k1->rchild)+1;
    (*k2)->balance=GetBalance((*k2)->lchild)>GetBalance((*k2)->rchild)?GetBalance((*k2)->lchild)+1:GetBalance((*k2)->rchild)+1;
    //修改分支根
    (*k2)=k1;
    return;
}

//见single_rotate_with_ll.png
void SingleRotateWithLL(AVLTNode **k2){
    AVLTNode *k1;
    k1=(*k2)->lchild;
    //看图分析知仅仅需要修改两条线
    (*k2)->lchild=k1->rchild;
    k1->rchild=(*k2);
    //更新k1 k2的高度
    k1->balance=GetBalance(k1->lchild)>GetBalance(k1->rchild)?GetBalance(k1->lchild)+1:GetBalance(k1->rchild)+1;
    (*k2)->balance=GetBalance((*k2)->lchild)>GetBalance((*k2)->rchild)?GetBalance((*k2)->lchild)+1:GetBalance((*k2)->rchild)+1;
    //修改分支根
    (*k2)=k1;
    return;
}

//见double_rotate_with_lr.png
void DoubleRotateWithLR(AVLTNode **k3){
    SingleRotateWithRR(&((*k3)->lchild));
    SingleRotateWithLL(k3);
}

//见double_rotate_with_rl.png
void DoubleRotateWithRL(AVLTNode **k3){
    SingleRotateWithLL(&((*k3)->rchild));
    SingleRotateWithRR(k3);
}

void AVLInsert(AVLTree *T,char x){
    if((*T)==NULL){
        (*T)=(struct AVLTNode*)malloc(sizeof(struct AVLTNode));
        if((*T)==NULL)
            perror("malloc error");
        (*T)->data=x;
        (*T)->balance=0;
        (*T)->lchild=(*T)->rchild=NULL;
    }
    else if(x<(*T)->data){
        AVLInsert(&((*T)->lchild),x);
        if(GetBalance((*T)->lchild)-GetBalance((*T)->rchild)==2){
            if( x<(*T)->lchild->data) //LL
                SingleRotateWithLL(T);
            else //LR
                DoubleRotateWithLR(T);
        }
    }
    else if(x>(*T)->data){
        AVLInsert(&((*T)->rchild),x);
        if(GetBalance((*T)->rchild)-GetBalance((*T)->lchild)==2){
            if(x>((*T)->rchild)->data) //RR
                SingleRotateWithRR(T);
            else //Rl
                DoubleRotateWithRL(T);
        }

    }
    else
        perror("key repetition");
    (*T)->balance=GetBalance((*T)->lchild)>GetBalance((*T)->rchild)?GetBalance((*T)->lchild)+1:GetBalance((*T)->rchild)+1;
    return;
}

AVLTree CreateAVLTree(){
    char ch;
    AVLTree T=NULL;
    scanf("%c%*c",&ch);
    while(ch!='#'){
        AVLInsert(&T,ch);
        AVLPrintTree(T,1);
        printf("请输入下一个要插入平衡树的字母\n");
        scanf("%c%*c",&ch);
    }
    return T;
}

void AVLPrintTree(AVLTree T,int nlayer){
    if(T == NULL) return;
    AVLPrintTree(T->rchild,nlayer+1);
    for(int i=0;i<nlayer;i++)
        printf("  ");
    printf("%c\n",T->data);
    AVLPrintTree(T->lchild,nlayer+1);
}
#endif