#include "../Graph/graph.c"
#include "../Graph/shortestpath.c"



void testGraph(){
/*
无向图测试数据:
6 9
ABCDEF
A B 6
A C 3
B C 2
B D 5
C D 3
C E 4
D E 2
D F 3
E F 5
*/
    MGraph UDG;
    CreateUDG(&UDG);
    printf("图的邻接矩阵:\n");
    PrintGraph(UDG);
    printf("图的深度优先遍历:\n");
    DFSGraph(UDG);
    printf("\n");
    printf("图的广度优先遍历:\n");
    BFSGraph(UDG);
    printf("\n");
    printf("图的单源最短路径:\n");
    Dijkstra(UDG,0);
    printf("图的所有顶点的最短路径:\n");
    Floyd(UDG);
}