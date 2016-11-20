#include "../Sort/sort.c"

void printArray(ElemType A[],int n){
    for(int i=0;i<n;i++)
        printf(i?" %d":"%d",A[i]);
    printf("\n");
}

typedef void (*FunType)(int A[],int n);

//利用函数指针传参，传人函数指针，方便用一个testSort测试不同的排序算法而不用考虑数组被修改后不能继续排序验证的问题
void testSortByFunType(FunType pfun){
    ElemType a[10]={3,1,5,7,2,4,8,9,10,6};
    pfun(a,10);
    printArray(a,10);
}

void testSort(){
    printf("InsertSort: ");
    testSortByFunType(InsertSort);
    printf("ShellSort: ");
    testSortByFunType(ShellSort);
    printf("SimpleSelectSort： ");
    testSortByFunType(SimpleSelectSort);
    printf("BubbleSort: ");
    testSortByFunType(BubbleSort);
    printf("QuickSortWrapper: ");
    testSortByFunType(QuickSortWrapper);
    printf("HeapSort: ");
    testSortByFunType(HeapSort);
    printf("MergeSort: ");
    testSortByFunType(MergeSortWrapper);
    printf("BucketSort: ");
    testSortByFunType(BucketSort);
}