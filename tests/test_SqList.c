#include <stdio.h>
#include "../SqList/sqlist.c"

void testSqList(){
    ElemType testdata[10]={1,2,3,4,5,6,7,8,9,10};
    ElemType temp;
    SqList L=ListInitial(testdata,10);
    ListPrint(L);
    printf("%d\n",L.length);
    ListInsert(&L,4,11);
    ListPrint(L);
    printf("%d\n",L.length);
    ListInsert(&L,4,12);
    printf("%d\n",L.length);
    ListPrint(L);
    ListDelete(&L,4,&temp);
    printf("%d\n",temp);
    ListPrint(L);
    printf("%d",LocateElem(L,12));
}
