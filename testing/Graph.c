#include "../structure/GraphM.h"
void main(){
    Graph *G = (Graph *)malloc(sizeof(Graph));
    G->vexnum = 0;
    G->arcnum = 0;
    CreateGraph(G);

    int visited[G->vexnum]; //根据图创建相应的顶点数组（主要用来深度搜索的时候，用来临时保存已访问过的顶点信息)
    for (int i=0; i<G->vexnum; i++){
        visited[i] = 0; //初始化全为0，代表没有访问过
    }
    printf("深度优先遍历图（邻接矩阵）结果：");
    DFS(G, 0, &visited);

    getch();
} 


// #include "../structure/GraphLk.h"
// void main(){
//     Graph *G = (Graph *)malloc(sizeof(Graph));
//     G->vexnum = 0;
//     G->arcnum = 0;
//     CreateAdjlist(G);
    
//     int visited[G->vexnum]; //根据图创建相应的顶点数组（主要用来深度搜索的时候，用来临时保存已访问过的顶点信息)
//     for (int i=0; i<G->vexnum; i++){
//         visited[i] = 0; //初始化全为0，代表没有访问过
//     }
//     printf("深度优先遍历图（邻接表）结果：");
//     DFS(*G, 0, &visited);

//     getch();
// } 