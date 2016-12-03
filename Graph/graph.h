#ifndef _GRAPH_H
#define _GRAPH_H
#include "../custom_define.h"

//邻接矩阵表示图
//邻接矩阵结构体
typedef struct ArcCell{
    int adj; //边的权重
    //char* info;//边的信息
}ArcCell,AdjMatrix[Maxsize][Maxsize];

typedef struct{
    char vexs[Maxsize];//顶点标识
    AdjMatrix arcs;//图的邻接矩阵
    int vexnum,arcnum;//图的顶点数目，边数
}MGraph;

//创建无向图
void CreateUDG(MGraph *G);
void CreateDG(MGraph *G);
void PrintGraph(MGraph G);
void DFS(MGraph G,int v);
void DFSGraph(MGraph G);
void BFSGraph(MGraph G);

#endif
