#include <stdio.h>
#include "../BiTree/bitnode_queue.c"

void testBiTNodeQueue() {
    //测试结构体是否能直接赋值
    BiTNode data[3];
    BiTNode p,q,r;
    p.data='a';
    q.data='b';
    r.data='c';
    p.lchild=&q;
    p.rchild=&r;
    q.lchild=q.rchild=NULL;
    r.lchild=r.rchild=NULL;
    data[0]=p;
    printf("%c\n",data[0].data);
    printf("%c\n",data[0].lchild->data);
    printf("%c\n",data[0].rchild->data);
    //测试BiTNodeQueue en de
    SqBiTNodeQueue sq;
    InitBiTNodeQueue(&sq);
    EnBiTNodeQueue(&sq,p);
    EnBiTNodeQueue(&sq,q);
    EnBiTNodeQueue(&sq,r);
    PrintBiTNodeQueue(sq);
    BiTNode temp;
    DeBiTNodeQueue(&sq,&temp);
    printf("%c\n",temp.data);
    PrintBiTNodeQueue(sq);
    DeBiTNodeQueue(&sq,&temp);
    DeBiTNodeQueue(&sq,&temp);
}
