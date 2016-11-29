#ifndef _AVLTREE_C
#define _AVLTREE_C

#include "../custom_define.h"

typedef struct AVLTNode{
    char data;
    struct AVLTNode *lchild,*rchild;
    int balance;
}*AVLTree;

int GetBalance(AVLTNode *p);
void SingleRotateWithRR(AVLTNode **k2);
void SingleRotateWithLL(AVLTNode **k2);
void DoubleRotateWithLR(AVLTNode **k3);
void DoubleRotateWithRL(AVLTNode **k3);
void AVLInsert(AVLTree *T,char x);
AVLTree CreateAVLTree();
void AVLPrintTree(AVLTree T,int nlayer);
#endif