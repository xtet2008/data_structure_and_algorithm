#include<stdlib.h>
#include<stdio.h>
#include "LkStack.h"
#define vnum 20

typedef int VertexType;
typedef struct arcnode //边结构体
{
    int adjvex; //下一条孤的孤头编号
    struct arcnode *nextarc; //指向下一条孤的指针
}ArcNode;
typedef struct vexnode //顶点数组结构体
{
    VertexType vertex; //顶点编号
    int in; //入度，即：有多少条箭头指向该顶点的边
    ArcNode *firstarc; //第一条边
}AdjList[vnum];
typedef struct gp //图结构体
{
    AdjList adjlist;
    int vexnum, arcnum; //顶点数，孤数
}Graph;
/* 邻接表描述有向图效果如下
AdjList[num] = vertex|in|firstarc = adjvex|nextarc  
0               [C0|0|->]          [1|->]          [2|^] 
1               [C1|1|->]          [4|^]
2               [C2|2|->]          [4|^]
3               [C3|0|->]          [2|^]
4               [C4|2|^]
*/


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
        g->adjlist[i].in = 0; //入度初始化为0
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
            g->adjlist[V2].in++; //入度加1
            g->arcnum +=1;
        }else{
            break;
        }
    }
}

int Tp_Sort(Graph g)
{
    LkStk S; //栈指针
    InitStack(&S); //初始化栈
    ArcNode *p; //边指针
    int m, i, v;

    for(i=0; i<g.vexnum; i++){
        if(g.adjlist[i].in == 0){
            Push(&S, i); // 将入度为0的结点入栈
        }
    }

    m=0;
    while (m<g.vexnum && !EmptyStack(&S)){ //TODO: optimize 如果不加这句代码 m<g.vexnum，那么后面栈S会益出，因为第一个空值不是NULL,是0x5
        v = GetTop(&S);
        Pop(&S);
        printf("，%d", v);
        m++; //输出结点数加1
        p = g.adjlist[v].firstarc; //找到v的邻结点所在链表
        while(p!=NULL){
            g.adjlist[p->adjvex].in--; //v的邻接点入度减1
            if(g.adjlist[p->adjvex].in==0){
                Push(&S, p->adjvex); //如果邻接点入度为0的话，需要将其压入栈
            }
            p = p->nextarc; //指向v的下一条边
        }
    }

    if(m<g.vexnum) {
        return 0; //图中含有环
    }else{
        return 1; //图中无环
    }
}