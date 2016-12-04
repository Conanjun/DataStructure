#include "graph.c"
#include "../Stack/stack.c"

void PrintPathAndDistanceDijkstra(MGraph G,int v0,int path[],int dist[]){
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
    PrintPathAndDistanceDijkstra(G,v0,path,dist);
}


void PrintPathAndDistanceFloyd(MGraph G,int** path,int** dist){
    SqStack ss;
    InitStack(&ss);
    for(int i=0;i<G.vexnum;i++){
        for(int j=0;j<G.vexnum;j++){
            printf("%c 到 %c 的最短路径为: ",G.vexs[i],G.vexs[j]);
            //路径回溯
            int temp=j;
            while(temp!=i){
                Push(&ss,temp);
                temp=path[i][temp];
            }
            printf("%c",G.vexs[i]);
            while(!StackEmpty(ss)){
                int temp;
                Pop(&ss,&temp);
                printf("->%c",G.vexs[temp]);
            }
            printf("    最短距离为%d\n",dist[i][j]);
        }
    }
}

void Floyd(MGraph G){
    //注意，二维数组的指针的定义
    int** path=(int**)malloc(sizeof(int*)*G.vexnum);
    for(int i=0;i<G.vexnum;i++){
        path[i]=(int*)malloc(sizeof(int)*G.vexnum);
    }
    int** dist=(int**)malloc(sizeof(int*)*G.vexnum);
    for(int i=0;i<G.vexnum;i++){
        dist[i]=(int*)malloc(sizeof(int)*G.vexnum);
    }

    //初始化path dist
    for(int i=0;i<G.vexnum;i++){
        for(int j=0;j<G.vexnum;j++){
            dist[i][j]=G.arcs[i][j].adj;// vi 到 vj的距离为 dist[i][j]
            if(i==j)
                path[i][j]=-1;// 当前最短距离路径为 i 到 j,前缀为i
            else
                if(G.arcs[i][j].adj!=INT_MAX)
                    path[i][j]=i;
                else
                    path[i][j]=-1;
        }
    }
    //n次试探 修改
    for(int k=0;k<G.vexnum;k++){
        for(int i=0;i<G.vexnum;i++){
            for(int j=0;j<G.vexnum;j++){
                if(dist[i][j]>dist[i][k]+dist[k][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                    path[i][j]=k;
                }
            }
        }
    }
    //打印path dist
    for(int i=0;i<G.vexnum;i++){
        for(int j=0;j<G.vexnum;j++){
            printf(j?" %d":"%d",path[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<G.vexnum;i++){
        for(int j=0;j<G.vexnum;j++){
            printf(j?" %d":"%d",dist[i][j]);
        }
        printf("\n");
    }
    PrintPathAndDistanceFloyd(G,path,dist);
    //释放内存
    for(int i=0;i<G.vexnum;i++){
        free(path[i]);
        free(dist[i]);
    }
    free(path);
    free(dist);
}

