#include<stdlib.h>
#include<stdio.h>
#include "LkStack.h"
#define vnum 20

typedef int VertexType;
typedef struct arcnode //�߽ṹ��
{
    int adjvex; //��һ���µĹ�ͷ���
    struct arcnode *nextarc; //ָ����һ���µ�ָ��
}ArcNode;
typedef struct vexnode //��������ṹ��
{
    VertexType vertex; //������
    int in; //��ȣ������ж�������ͷָ��ö���ı�
    ArcNode *firstarc; //��һ����
}AdjList[vnum];
typedef struct gp //ͼ�ṹ��
{
    AdjList adjlist;
    int vexnum, arcnum; //������������
}Graph;
/* �ڽӱ���������ͼЧ������
AdjList[num] = vertex|in|firstarc = adjvex|nextarc  
0               [C0|0|->]          [1|->]          [2|^] 
1               [C1|1|->]          [4|^]
2               [C2|2|->]          [4|^]
3               [C3|0|->]          [2|^]
4               [C4|2|^]
*/


/*��������ͼ���ڽӱ��㷨
�ȴ����������飬����ʼ�����ж�����ϢȨֵΪ����󣨴����ޱߣ���Ȼ�����������������ԣ��ߣ�
*/
void CreateAdjlist(Graph *g)
{
    int V1, V2;
    ArcNode *p;

    //��ʼ��������Ϣ
    int n;
    printf("�����붥���ܸ�����");
    fflush(stdin); //�����scanf֮ǰ����ջ��棬��Ȼ������쳣������ֱ������scanf����ִ�к���Ĵ���
    scanf("%d", &n);
    g->vexnum = n;
    for(int i=0; i<n; i++){
        g->adjlist[i].vertex = i; //��ʼ������Vi����Ϣ
        g->adjlist[i].in = 0; //��ȳ�ʼ��Ϊ0
        g->adjlist[i].firstarc = NULL; //��ʼ������Vi�ĵ�1���ڽ��ΪNULL
    }

    while(1){
        printf("\n�����붥�������ֵ���ɵıߣ��Կո���������磺0 1����Ӷ���0������1�ıߣ�����0��������룺");
        fflush(stdin); //�����scanf֮ǰ����ջ��棬��Ȼ������쳣������ֱ������scanf����ִ�к���Ĵ���
        scanf("%d %d", &V1, &V2);
        if(V1 || V2){
            p = (ArcNode *)malloc(sizeof(ArcNode));//����V2�ı߽��
            p->adjvex = V2;
            p->nextarc = g->adjlist[V1].firstarc; // ���½��V2 ���� V1�ĵ�������
            
            g->adjlist[V1].firstarc = p; //�൱��ǰ�壬�Ȱ��½���p.nextarcָ��g�ĵ�һ���ߣ�Ȼ������g�ĵ�һ����ָ���µĽ��p
            g->adjlist[V2].in++; //��ȼ�1
            g->arcnum +=1;
        }else{
            break;
        }
    }
}

int Tp_Sort(Graph g)
{
    LkStk S; //ջָ��
    InitStack(&S); //��ʼ��ջ
    ArcNode *p; //��ָ��
    int m, i, v;

    for(i=0; i<g.vexnum; i++){
        if(g.adjlist[i].in == 0){
            Push(&S, i); // �����Ϊ0�Ľ����ջ
        }
    }

    m=0;
    while (m<g.vexnum && !EmptyStack(&S)){ //TODO: optimize ������������� m<g.vexnum����ô����ջS���������Ϊ��һ����ֵ����NULL,��0x5
        v = GetTop(&S);
        Pop(&S);
        printf("��%d", v);
        m++; //����������1
        p = g.adjlist[v].firstarc; //�ҵ�v���ڽ����������
        while(p!=NULL){
            g.adjlist[p->adjvex].in--; //v���ڽӵ���ȼ�1
            if(g.adjlist[p->adjvex].in==0){
                Push(&S, p->adjvex); //����ڽӵ����Ϊ0�Ļ�����Ҫ����ѹ��ջ
            }
            p = p->nextarc; //ָ��v����һ����
        }
    }

    if(m<g.vexnum) {
        return 0; //ͼ�к��л�
    }else{
        return 1; //ͼ���޻�
    }
}