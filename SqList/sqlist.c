#include "sqlist.h"

SqList ListInitial(ElemType l[],int len){
    SqList L;
    L.length=len;
    for(int i=0;i<L.length;i++)
        L.data[i]=l[i];
    return L;
}

void ListPrint(SqList L){
    for(int i=0;i<L.length;i++)
        printf(i?" %d":"%d",L.data[i]);
    printf("\n");
}

bool ListInsert(SqList *L,int i,ElemType e){
    if(i<0 || i>L->length-1)
        return false;
    if(L->length>=Maxsize)
        return false;
    for(int j=L->length;j>=i;j--)
        L->data[j]=L->data[j-1];
    L->data[i-1]=e;
    L->length++;
    return true;
}

bool ListDelete(SqList *L,int i,ElemType *e){
    if(i<0 || i>L->length-1)
        return false;
    if(L->length<1)
        return false;
    *e=L->data[i];
    for(int j=i;j<L->length;j++)
        L->data[j]=L->data[j+1];
    L->length--;
    return true;
}

int LocateElem(SqList L,ElemType e){
    for(int i=0;i<L.length;i++)
        if(L.data[i]==e)
            return i;
    return -1;
}
