#include<stdio.h>
#include<stdlib.h>

/*
����Prim�㷨��ͼ����С������
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
    int lowcost; // ÿ����������Ӧ����С����ֵ
}closedge[vnum];

Graph Build_Testing_Tree()
{
    Graph G;
    G.vexnum = 5;
    G.arcnum = 6; //����ͼ���������=2*ʵ�ʱ�������Ϊ(a,b)��(b,a)��������ԣ�����1��ʵ�ʱ�
    for(int i=0; i<G.vexnum; i++){G.vexs[i] = i;} // ��ʼ������

    //��ʼ���ߣ�ȫ�������(�൱���ޱ�)
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

// prim��С�������㷨
void prim(Graph g, int u)
{
    int v,k,j,min;

    for(v=0; v<g.vexnum; v++){
        if(v!=u){ //��ʼ�����������㵽 ����u�ľ��룬u����Ϊ0���൱�ڳ�ʼ�������������㵽����0�ľ���
            closedge[v].adjvex=u; //��ʼ��(u, v)��ʼ��
            closedge[v].lowcost=g.arcs[u][v]; // ��ʼ����С���루����ޱߣ��������ֵ����)
        }
    }
    closedge[u].lowcost=MAX_INT; //�൱�趨 (0, 0)�ľ�����Ϊ����󣨴����ޱ�)

    int visited[g.vexnum];
    for(int i=0; i<g.vexnum; i++){visited[i]=0;}
    visited[u] = 1;

    for(k=0; k<g.vexnum-1; k++){
        min=closedge[k].lowcost; //����(u, k)������С����
        v=k; 
        for(j=0; j<g.vexnum; j++){
            if(!visited[j] && closedge[j].lowcost<min){
                min=closedge[j].lowcost;
                v=j; //v������̾���Ķ������
            }
        }

        printf("%d %d\n", closedge[v].lowcost, v); //����������ı�
        visited[v] = 1; //��������������Ѿ����ʹ���
        closedge[v].lowcost = MAX_INT; //����v����u������������һ������v�ѷ���

        //�����¶��㵽��������ľ���ֵ��Ϊ��һ�������ɸ��¶��㵽������������ֵ��Ѱ����Сֵ�����ݳ�ʼ��׼����
        for(j=0; j<g.vexnum; j++){
            if(g.arcs[v][j] < closedge[j].lowcost){ //���U�� V-U���и�С���۵ı�
                closedge[j].lowcost = g.arcs[v][j]; //����closedge�еĴ���
                closedge[j].adjvex=v; //����closedge�еĶ���
            }
        }
    }
}