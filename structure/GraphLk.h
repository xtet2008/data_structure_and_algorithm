#include<stdlib.h>
#include<stdio.h>

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
}AdjList[20];
typedef struct gp
{
    AdjList adjlist;
    int vexnum, arcnum; //顶点和边的个数
}Graph;



void CreateAdjlist(Graph *g)
//建立有向图的邻接表算法
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