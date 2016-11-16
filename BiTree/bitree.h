#include "../custom_define.h"

#ifndef _BITREE_H

#define _BITREE_H

typedef struct BiTNode{
    char data;
    struct BiTNode *lchild,*rchild;
}*BiTree;

void visit(BiTree);
void PreOrder(BiTree T);
void InOrder(BiTree T);
void PostOrder(BiTree T);
void InOrderByStack(BiTree T);
void LevelOrder(BiTree T);

#endif
