#include "graph.c"
#include "../Stack/stack.c"
#include <string.h>

//设置顶点的入席
void SetIndegree(MGraph G,int* indegree){
    for(int i=0;i<G.vexnum;i++)
        indegree[i]=0;
    for(int i=0;i<G.vexnum;i++){
        for(int j=0;j<G.vexnum;j++){
            if(G.arcs[i][j].adj!=INT_MAX && i!=j)
                indegree[j]++;
        }
    }
    /*
    for(int i=0;i<G.vexnum;i++)
        printf(i?" %d":"%d",indegree[i]);
    printf("\n");
    */
}

//有向图
void TopoSort(MGraph G){
    //复制该图
    MGraph Gtemp;
    memcpy(&Gtemp,&G,sizeof(MGraph));
    int* indegree=(int*)malloc(sizeof(int)*Gtemp.vexnum);
    SetIndegree(Gtemp,indegree);
    SqStack ss;
    InitStack(&ss);
    //将入度为0的结点入栈
    for(int i=0;i<G.vexnum;i++)
        if(indegree[i]==0){
            Push(&ss,i);
            indegree[i]=-1;//删除结点的入度
            Gtemp.arcnum--;
            break;//任意选一个结点入栈即可
        }
    int temp;
    while(!StackEmpty(ss)){
        Pop(&ss,&temp);
        Gtemp.vexnum--;
        printf("%3c",Gtemp.vexs[temp]);
        //以该结点为起点的边的indree减一,并删除该边
        for(int i=0;i<G.vexnum;i++){
            if(Gtemp.arcs[temp][i].adj!=INT_MAX && i!=temp){
                indegree[i]--;
                Gtemp.arcs[temp][i].adj=INT_MAX;
            }
        }
        for(int i=0;i<G.vexnum;i++){
            if(indegree[i]==0){
                Push(&ss,i);
                indegree[i]=-1;//置为-1该结点己纳入拓扑
                Gtemp.arcnum--;
                break;
            }
        }
    }
    printf("\n");
    //判断是否存在环路
    if(Gtemp.vexnum!=0){
        printf("该图存在环路\n");
    }
    return;
}