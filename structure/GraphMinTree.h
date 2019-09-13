#include<stdio.h>
#include<stdlib.h>

/*
利用Prim算法求图的最小生成树
*/
#define vnum 5
// const int vnum=5;
const int MAX_INT = 32767;
typedef struct gp
{
    int vexs[vnum];
    int arcs[vnum][vnum];
    int vexnum, arcnum;
}Graph;

struct
{
    int adjvex; 
    int lowcost; // 每个顶点所对应的最小距离值
}closedge[vnum];

Graph Build_Testing_Tree()
{
    Graph G;
    G.vexnum = 5;
    G.arcnum = 6; //无向图，顶点对数=2*实际边数，因为(a,b)和(b,a)两个顶点对，但是1条实际边
    for(int i=0; i<G.vexnum; i++){G.vexs[i] = i;} // 初始化顶点

    //初始化边，全部无穷大(相当于无边)
    for(int i=0; i<G.vexnum; i++){
        for(int j=0; j<G.vexnum; j++){
            G.arcs[i][j] = MAX_INT;
        }
    }

    //Set arc and distance for V0
    G.arcs[0][1] = 50;
    G.arcs[0][3] = 40;
    G.arcs[0][4] = 20;

    //Set arc and distance for V1
    G.arcs[1][0] = 50;
    G.arcs[1][2] = 10;
    
    //Set arc and distance for V2
    G.arcs[2][1] = 10;
    G.arcs[2][3] = 20;
    G.arcs[2][4] = 30;
    
    //Set arc and distance for V3
    G.arcs[3][0] = 40;
    G.arcs[3][2] = 20;

    //Set arc and distance for V4
    G.arcs[4][0] = 20;
    G.arcs[4][2] = 30;

    return G;
}

// prim最小生成树算法
void prim(Graph g, int u)
{
    int v,k,j,min;

    for(v=0; v<g.vexnum; v++){
        if(v!=u){ //初始化其他各顶点到 顶点u的距离，u参数为0，相当于初始化从其他各顶点到顶点0的距离
            closedge[v].adjvex=u; //初始化(u, v)起始点
            closedge[v].lowcost=g.arcs[u][v]; // 初始化最小距离（如果无边，则用最大值代表)
        }
    }
    closedge[u].lowcost=MAX_INT; //相当设定 (0, 0)的距离设为无穷大（代表无边)

    int visited[g.vexnum];
    for(int i=0; i<g.vexnum; i++){visited[i]=0;}
    visited[u] = 1;

    for(k=0; k<g.vexnum-1; k++){
        min=closedge[k].lowcost; //假如(u, k)具有最小代价
        v=k; 
        for(j=0; j<g.vexnum; j++){
            if(!visited[j] && closedge[j].lowcost<min){
                min=closedge[j].lowcost;
                v=j; //v代表最短距离的顶点序号
            }
        }

        printf("%d %d\n", closedge[v].lowcost, v); //输出生成树的边
        visited[v] = 1; //代表着这个顶点已经访问过了
        closedge[v].lowcost = MAX_INT; //顶点v并入u集，代表着下一个顶点v已访问

        //更新新顶点到其他各点的距离值（为下一轮在若干个新顶点到其他各点距离的值中寻找最小值做数据初始化准备）
        for(j=0; j<g.vexnum; j++){
            if(g.arcs[v][j] < closedge[j].lowcost){ //如果U与 V-U间有更小代价的边
                closedge[j].lowcost = g.arcs[v][j]; //调整closedge中的代价
                closedge[j].adjvex=v; //调整closedge中的顶点
            }
        }
    }
}