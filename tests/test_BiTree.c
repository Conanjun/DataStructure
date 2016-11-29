#include "../BiTree/bitree.c"

void testBiTree(){
    BiTree T=CreateBiTree();
    PreOrder(T);
    printf("\n");
    InOrder(T);
    printf("\n");
    PostOrder(T);
    printf("\n");
    InOrderByStack(T);
    printf("\n");
    LevelOrder(T);
    printf("\n");
    PrintTree(T,1);
}