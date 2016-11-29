#ifndef _BSTREE_C
#define _BSTREE_C

#include "bstree.h"
//查找成功，q指向该节点，查找失败，q指向最后一个访问的节点(p指向当前访问节点的父节点)
int SearchBST(BSTNode *bt,ElemType key,BSTNode **p,BSTNode **q){
    //if(T==NULL || key==T->data) return T;
    if(bt==NULL){*q=*p;return 0;}//查找失败
    else if(key==bt->data){*q=bt;return 1;}//查找成功
    if(key<bt->data) return SearchBST(bt->lchild,key,&bt,q);
    else return SearchBST(bt->rchild,key,&bt,q);
}

//查找失败则插入并返回1，查找成功则返回0
int InsertBST(BSTree *T,int key){
    BSTNode *pp=(BSTNode*)malloc(sizeof(struct BSTNode)),*qq=(BSTNode*)malloc(sizeof(struct BSTNode));
    BSTNode **p=&pp,**q=&qq;
    *p=NULL;
    *q=NULL;
    if(SearchBST(*T,key,p,q)==0){//查找失败插入节点
        BSTNode *temp=(BSTNode*)malloc(sizeof(struct BSTNode));
        temp->data=key;
        temp->lchild=temp->rchild=NULL;
        //作为根插入
        if(!(*q)) *T=temp;
            //作为左儿子插入
        else if(key<(*q)->data) (*q)->lchild=temp;
            //作为右儿子插入
        else (*q)->rchild=temp;
        return 1;
    }
    else return 0;
}

//delete_bst_node.png
//返回0表示查找并删除成功
int DeleteHelp(BSTree *p){
    BSTNode *temp;
    if((*p)->rchild==NULL){ //右子树为空，重接左子树 (此分支包括叶子节点的情况)
        temp=*p;
        (*p)=(*p)->lchild;
        free(temp);
    }
    else if((*p)->lchild==NULL){//左子树为空
        temp=*p;
        (*p)=(*p)->rchild;
        free(temp);
    }
    else{ //左右子树均非空
        //查找前驱节点 temp
        BSTNode *pre;
        pre=*p;
        temp=(*p)->lchild;
        while(temp->rchild){ //找最右下的节点
            pre=temp;
            temp=temp->rchild;
        }
        (*p)->data=temp->data;
        if(pre!=*p) pre->rchild=temp->lchild;
        else pre->lchild=temp->lchild;//前驱节点为只有左分支的左儿子
        free(temp);
    }
    return 0;
}
int DeleteBST(BSTree *T,int key){
    if(!*T)
        return -1;
    else{
        if(key==(*T)->data)
            return DeleteHelp(T);
        else if(key<(*T)->data)
            return DeleteBST(&((*T)->lchild),key);
        else
            return DeleteBST(&((*T)->rchild),key);
    }
}

void visitBST(BSTree T){
    printf("%d",T->data);
}
//二叉树中序遍历为有序序列
void InOrderBST(BSTree T){
    if(T!=NULL){
        InOrderBST(T->lchild);
        visitBST(T);
        InOrderBST(T->rchild);
    }
}

void PrintBSTree(BSTree T,int nlayer){
    if(T == NULL) return;
    PrintBSTree(T->rchild,nlayer+1);
    for(int i=0;i<nlayer;i++)
        printf("  ");
    printf("%d\n",T->data);
    PrintBSTree(T->lchild,nlayer+1);
}
#endif