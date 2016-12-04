#include "../Graph/graph.c"
#include "../Graph/shortestpath.c"
#include "../Graph/toposort.c"

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
    printf("无向图的邻接矩阵:\n");
    PrintGraph(UDG);
    printf("无向图的深度优先遍历:\n");
    DFSGraph(UDG);
    printf("\n");
    printf("无向图的广度优先遍历:\n");
    BFSGraph(UDG);
    printf("\n");
    printf("无向图的单源最短路径:\n");
    Dijkstra(UDG,0);
    printf("无向图的所有顶点的最短路径:\n");
    Floyd(UDG);

/*
有向图
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

    MGraph DG;
    CreateDG(&DG);
    printf("有向图的邻接矩阵:\n");
    PrintGraph(DG);
    printf("有向图的深度优先遍历:\n");
    DFSGraph(DG);
    printf("\n");
    printf("有向图的广度优先遍历:\n");
    BFSGraph(DG);
    printf("\n");
    printf("有向图的单源最短路径:\n");
    Dijkstra(DG,0);
    printf("有向图的所有顶点的最短路径:\n");
    Floyd(DG);
    printf("有向图的拓扑排序:\n");
    TopoSort(DG);
}