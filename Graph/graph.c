#ifndef _GRAPH_C
#define _GRAPH_C

#include "graph.h"
#include "../Queue/queue.c"
#define INT_MAX 32767

int visited[Maxsize];
//返回结点字符的下标
int LocateVex(MGraph G,char p){
    for(int i=0;i<G.vexnum;i++){
        if(G.vexs[i]==p){
            return i;
        }
    }
    return -1;
}
//创建无向图
void CreateUDG(MGraph *G){
    printf("输入顶点数和边数:\n");
    scanf("%d%d",&(G->vexnum),&(G->arcnum));
    for(int i=0;i<G->vexnum;i++) visited[i]=0;
    printf("按次序输入%d个顶点的字母标号\n",G->vexnum);
    getchar();//吸收回车
    for(int i=0;i<G->vexnum;i++){
        scanf("%c",&(G->vexs[i]));
    }
    getchar();//吸收回车
    //初始化邻接矩阵
    for(int i=0;i<G->vexnum;i++){
        for(int j=0;j<G->vexnum;j++){
            if(i==j)
                G->arcs[i][j].adj=0;
            else
                G->arcs[i][j].adj=INT_MAX;
        }
    }
    for(int i=0;i<G->arcnum;i++){
        printf("输入边的顶点和权值(A B 10)\n");
        char v1,v2;
        int value;
        scanf("%c %c %d",&v1,&v2,&value);
        getchar();
        G->arcs[LocateVex(*G,v1)][LocateVex(*G,v2)].adj= G->arcs[LocateVex(*G,v2)][LocateVex(*G,v1)].adj=value;
    }
}

//创建有向图
void CreateDG(MGraph *G){
    printf("输入顶点数和边数:\n");
    scanf("%d%d",&(G->vexnum),&(G->arcnum));
    for(int i=0;i<G->vexnum;i++) visited[i]=0;
    printf("按次序输入%d个顶点的字母标号\n",G->vexnum);
    getchar();//吸收回车
    for(int i=0;i<G->vexnum;i++){
        scanf("%c",&(G->vexs[i]));
    }
    getchar();//吸收回车
    //初始化邻接矩阵
    for(int i=0;i<G->vexnum;i++){
        for(int j=0;j<G->vexnum;j++){
            if(i==j)
                G->arcs[i][j].adj=0;
            else
                G->arcs[i][j].adj=INT_MAX;
        }
    }
    for(int i=0;i<G->arcnum;i++){
        printf("输入边的顶点和权值(A B 10)\n");
        char v1,v2;
        int value;
        scanf("%c %c %d",&v1,&v2,&value);
        getchar();
        G->arcs[LocateVex(*G,v1)][LocateVex(*G,v2)].adj=value;
    }
}

void PrintGraph(MGraph G){
    for(int i=0;i<G.vexnum;i++){
        for(int j=0;j<G.vexnum;j++){
            if(INT_MAX==G.arcs[i][j].adj)
                printf("%6s","INF");
            else
                printf("%6d",G.arcs[i][j].adj);
        }
        printf("\n");
    }
}

void DFS(MGraph G,int v){
    printf("%3c",G.vexs[v]);
    visited[v]=1;
    //找出下一个结点进行遍历
    for(int i=0;i<G.vexnum;i++){
        if(G.arcs[v][i].adj!=INT_MAX && !visited[i])
            DFS(G,i);
    }
}

void DFSGraph(MGraph G){
    for(int i=0;i<G.vexnum;i++)
        visited[i]=0;
    for(int i=0;i<G.vexnum;i++)
        if(!visited[i])
            DFS(G,i);
}

void BFSGraph(MGraph G){
    SqQueue vexqueue;
    InitQueue(&vexqueue);
    for(int i=0;i<G.vexnum;i++) visited[i]=0;
    //默认从0开始广度遍历
    if(G.vexnum<=0) return;//防止空图
    for(int i=0;i<G.vexnum;i++){
        if(!visited[i]){
            printf("%3c",G.vexs[i]);
            visited[i]=1;
            EnQueue(&vexqueue,i);
        }
        while(!QueueEmpty(vexqueue)){
            DeQueue(&vexqueue,&i);
            for(int j=0;j<G.vexnum;j++){
                if(G.arcs[i][j].adj!=INT_MAX && !visited[j]){
                    printf("%3c",G.vexs[j]);
                    visited[j]=1;
                    EnQueue(&vexqueue,j);
                }
            }
        }
    }
}

#endif