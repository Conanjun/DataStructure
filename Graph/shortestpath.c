#include "graph.c"
#include "../Stack/stack.c"

void PrintPathAndDistance(MGraph G,int v0,int path[],int dist[]){
    SqStack sq;
    InitStack(&sq);
    for(int i=0;i<G.vexnum;i++){
        printf("%c 到 %c 的最短路径为: ",G.vexs[v0],G.vexs[i]);
        //路径回溯
        int temp=i;
        while(temp!=v0){
            Push(&sq,temp);
            temp=path[temp];
        }
        printf("%c",G.vexs[v0]);
        while(!StackEmpty(sq)){
            int temp;
            Pop(&sq,&temp);
            printf("->%c",G.vexs[temp]);
        }
        printf("    最短距离为%d\n",dist[i]);
    }
}

void Dijkstra(MGraph G,int v0){
    int* dist=(int*)malloc(sizeof(int)*G.vexnum);//dist记录源点到其他顶点当前的最短距离
    int* path=(int*)malloc(sizeof(int)*G.vexnum);//某顶点当前最短路径的前一个结点
    int* s=(int*)malloc(sizeof(int)*G.vexnum);//判断该结点是否已加入集合

    //初始化s dist path
    for(int i=0;i<G.vexnum;i++){
        s[i]=0;
        dist[i]=G.arcs[v0][i].adj;
        path[i]=dist[i]<INT_MAX?v0:-1;
    }
    //加入v0
    dist[v0]=0;
    s[v0]=1;
    //加入其他的结点
    for(int i=1;i<G.vexnum;i++){
        int v=-1;//当前选中的满足条件的结点
        int min=INT_MAX;//当前的最小距离
        for(int j=0;j<G.vexnum;j++){
            //顶点j不属于S且离v0更近
            if(!s[j] && dist[j]<min){
                v=j;
                min=dist[j];
            }
        }
        if(v==-1) break;//无顶点可加入s,退出
        s[v]=1;
        //调整集合T(V-S)中的各个顶点的距离值
        //以k为中间结点
        for(int k=0;k<G.vexnum;k++){
            if(!s[k] && min+G.arcs[v][k].adj<dist[k]){ //经过k的路径较短，则更新
                dist[k]=min+G.arcs[v][k].adj;
                path[k]=v;
            }
        }
    }
    printf("path:\n");
    for(int i=0;i<G.vexnum;i++){
        printf(i?" %d":"%d ",path[i]);
    }
    printf("\n");
    printf("dist:\n");
    for(int i=0;i<G.vexnum;i++){
        printf(i?" %d":"%d",dist[i]);
    }
    printf("\n");
    //打印最短路径和最短距离
    PrintPathAndDistance(G,v0,path,dist);
}

