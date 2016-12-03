#include "../Graph/graph.c"

void testGraph(){
    MGraph G;
    CreateUDG(&G);
    printf("图的邻接矩阵:\n");
    PrintGraph(G);
    printf("图的深度优先遍历:\n");
    DFSGraph(G);
    printf("\n");
    printf("图的广度优先遍历:\n");
    BFSGraph(G);
    printf("\n");
}