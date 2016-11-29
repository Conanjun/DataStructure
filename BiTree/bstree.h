#ifndef _BSTREE_H
#define _BSTREE_H

#include "../custom_define.h"

typedef struct BSTNode{
    int data;
    struct BSTNode *lchild,*rchild;
}*BSTree;

int SearchBST(BSTNode *bt,ElemType key,BSTNode **p,BSTNode **q);
int InsertBST(BSTree *T,int key);
int DeleteHelp(BSTree *p);
int DeleteBST(BSTree *T,int key);
void visitBST(BSTree T);
void InOrderBST(BSTree T);
void PrintBSTree(BSTree T,int nlayer);
#endif