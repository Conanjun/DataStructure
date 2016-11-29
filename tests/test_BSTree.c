#include "../BiTree/bstree.c"

void testBSTree(){
    BSTree T;
    T=NULL;
    InsertBST(&T,8);
    InsertBST(&T,9);
    InsertBST(&T,5);
    InsertBST(&T,4);
    InsertBST(&T,6);
    InsertBST(&T,11);
    InsertBST(&T,10);
    InsertBST(&T,12);
    InsertBST(&T,7);
    PrintBSTree(T,1);
    InOrderBST(T);
    DeleteBST(&T,5);
    PrintBSTree(T,1);
    InOrderBST(T);
}