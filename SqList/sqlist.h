#include "../custom_define.h"

typedef struct {
    ElemType data[Maxsize];
    int length;
}SqList;

// index start from 0 ->->length-1
SqList ListInitial(ElemType l[],int len);

void ListPrint(SqList L);

bool ListInsert(SqList *L,int i,ElemType e);

bool ListDelete(SqList *L,int i,ElemType * e);

int LocateElem(SqList L,ElemType e);
