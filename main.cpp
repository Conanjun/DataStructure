#include<stdio.h>
#include "tests/test_SqList.c"
#include "tests/test_Stack.c"
#include "tests/test_BiTNodeStack.c"
#include "tests/test_BiTNodeQueue.c"
#include "tests/test_BiTree.c"
#include "tests/test_Queue.c"
#include "tests/test_Sort.c"
#include "tests/test_AVLTree.c"
#include "tests/test_BSTree.c"
#include "tests/test_Graph.c"

//说明:要测试哪个模块则直接将该模块的注释取消
int main(){
    //testSqList();
    //testStack();
    //testBiTNodeStack();
    //testBiTree();
    //testQueue();
    //testBiTNodeQueue();
    //testSort();
    //testAVLTree();
    //testBSTree();
    testGraph();
    return 0;
}