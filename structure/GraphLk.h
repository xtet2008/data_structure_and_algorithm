#include<stdlib.h>
#include<stdio.h>
#include "Lkqueue.h"

/* 邻接表表示图
     V0
    / |
   /  |
  V1  |  V3
   \  | /
    \ |/
     V2

/* 邻接表表示效果如下
AdjList[num] = vertex|firstarc = adjvex|nextarc  
0               [V0|->]          [1|->]          [2|^] 
1               [V1|->]          [0|->]          [2|^]
2               [V2|->]          [0|->]          [1|->]          [3|^]
3               [V3|->]          [2|^]
*/

#define vnum 20
typedef int WeightType; //边长类型
typedef struct arcnode //表结点
{
    int adjvex; //下一条边的顶点编号
    WeightType weight; //带权图的权值域，若是非带权图，可不用该域
    struct arcnode *nextarc; //指向下一条边的指针
}ArcNode;
typedef struct vexnode //头结点
{
    int vertex; //顶点编号
    ArcNode *firstarc; //指向第一条边的指针
}AdjList[vnum];
typedef struct gp
{
    AdjList adjlist;
    int vexnum, arcnum; //顶点和边的个数
}Graph;


/*建立有向图的邻接表算法
先创建顶点数组，并初始化所有顶点信息权值为无穷大（代表无边），然后再依次输入各顶点对（边）
*/
void CreateAdjlist(Graph *g)
{
    int V1, V2;
    ArcNode *p;

    //初始化顶点信息
    int n;
    printf("请输入顶点总个数：");
    fflush(stdin); //最好在scanf之前，清空缓存，不然会出现异常，导致直接跳过scanf函数执行后面的代码
    scanf("%d", &n);
    g->vexnum = n;
    for(int i=0; i<n; i++){
        g->adjlist[i].vertex = i; //初始化顶点Vi的信息
        g->adjlist[i].firstarc = NULL; //初始化顶点Vi的第1个邻结点为NULL
    }

    while(1){
        printf("\n请输入顶点对两个值构成的边，以空格隔开，例如：0 1代表从顶点0到顶点1的边，两个0则结束输入：");
        fflush(stdin); //最好在scanf之前，清空缓存，不然会出现异常，导致直接跳过scanf函数执行后面的代码
        scanf("%d %d", &V1, &V2);
        if(V1 || V2){
            p = (ArcNode *)malloc(sizeof(ArcNode));//生成V2的边结点
            p->adjvex = V2;
            p->nextarc = g->adjlist[V1].firstarc; // 将新结点V2 链到 V1的单链表中
            
            g->adjlist[V1].firstarc = p; //相当于前插，先把新结点的p.nextarc指向g的第一条边，然后再用g的第一条边指向新的结点p
            g->arcnum +=1;
        }else{
            break;
        }
    }
}

/*邻接表图的深度优先搜索(类似于树的先序遍历)
沿着某个顶点搜索，并且每次访问过后将顶点存起来代表着已经访问过了，然后再继续访问下一个顶点
*/
void DFS(Graph g, int v, int *visited[])
{
    ArcNode *p;
    printf("，%d", v); //访问顶点
    visited[v] = 1; //代码着已经访问过了
    p = g.adjlist[v].firstarc;
    while (p!=NULL){
        if(!visited[p->adjvex]){
            DFS(g, p->adjvex, visited);
        }
        p=p->nextarc;
    }
}   

/*邻接表图的广度优先搜索(类似于树的层序遍历)
通过队列，依次把各节点入队，并出队后访问各子节点
*/
void BFS(Graph g, int v, int *visited[])
{   
    ArcNode *p; //表结点
    LkQue Q; //Q为链对列
    InitQueue(&Q);
    printf("，%d", v);
    visited[v]=1; //置已访问标志
    EnQueue(&Q, v); //访问过的顶点入队列
    while (!EmptyQueue(Q)){
        v = GetHead(Q);
        OutQueue(&Q); //顶点出队列
        p = g.adjlist[v].firstarc; //找到v的第一个邻结点
        while(p!=NULL){
            if(!visited[p->adjvex]){
                //访问各节点
                printf("，%d", p->adjvex);
                visited[p->adjvex]=1;
                EnQueue(&Q, p->adjvex);
            }
            p = p->nextarc; //沿着v的邻接点链表顺序搜索
        }
    }
}

//计算一个图中有多少个连通分量（最大多少个互不连通的子图数)
int Count_Component(Graph g)
{
    int count=0, v;
    int visited[g.vexnum];
    for(int v=0; v<g.vexnum; v++){visited[v]=0;} // 初始化都为0，代表没有被访问过

    for(int v=0; v<g.vexnum; v++){
        if(!visited[v]){
            count++; //计数加1
            printf("\n第 %d 个连通分量包含以下顶点：");
            BFS(g, 0, &visited);
        }
    }

    printf("一共有 %d 个连通分量\n", count);  //count即是连通分量的个数

    return count;
}