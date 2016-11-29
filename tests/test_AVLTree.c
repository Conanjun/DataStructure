#include <stdio.h>
#include "../BiTree/avltree.c"

//测试数据
//测试LL h e c b a
//测试RR a b c d e
//测试LR k g e a c
//测试RL a b c g h e
void testAVLTree(){
    AVLTree T;
    T=CreateAVLTree();
    AVLPrintTree(T,1);
}