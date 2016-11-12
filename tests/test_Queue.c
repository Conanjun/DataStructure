#include "../Queue/queue.c"

void testQueue(){
    SqQueue q;
    InitQueue(&q);
    for(int i=0;i<10;i++)
        EnQueue(&q,i);
    PrintQueue(q);
    EnQueue(&q,10);
    PrintQueue(q);
    int temp;
    DeQueue(&q,&temp);
    PrintQueue(q);
    printf("%d\n",temp);
    for(int i=0;i<10;i++){
        DeQueue(&q,&temp);
        PrintQueue(q);
    }
    if(QueueEmpty(q))
        printf("queue is empty now");
}