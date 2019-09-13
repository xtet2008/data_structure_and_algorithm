#include<stdlib.h>
#include<stdio.h>
#include "Lkqueue.h"

/* �ڽӱ��ʾͼ
     V0
    / |
   /  |
  V1  |  V3
   \  | /
    \ |/
     V2

/* �ڽӱ��ʾЧ������
AdjList[num] = vertex|firstarc = adjvex|nextarc  
0               [V0|->]          [1|->]          [2|^] 
1               [V1|->]          [0|->]          [2|^]
2               [V2|->]          [0|->]          [1|->]          [3|^]
3               [V3|->]          [2|^]
*/

#define vnum 20
typedef int WeightType; //�߳�����
typedef struct arcnode //����
{
    int adjvex; //��һ���ߵĶ�����
    WeightType weight; //��Ȩͼ��Ȩֵ�����ǷǴ�Ȩͼ���ɲ��ø���
    struct arcnode *nextarc; //ָ����һ���ߵ�ָ��
}ArcNode;
typedef struct vexnode //ͷ���
{
    int vertex; //������
    ArcNode *firstarc; //ָ���һ���ߵ�ָ��
}AdjList[vnum];
typedef struct gp
{
    AdjList adjlist;
    int vexnum, arcnum; //����ͱߵĸ���
}Graph;


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
            g->arcnum +=1;
        }else{
            break;
        }
    }
}

/*�ڽӱ�ͼ�������������(�����������������)
����ĳ����������������ÿ�η��ʹ��󽫶���������������Ѿ����ʹ��ˣ�Ȼ���ټ���������һ������
*/
void DFS(Graph g, int v, int *visited[])
{
    ArcNode *p;
    printf("��%d", v); //���ʶ���
    visited[v] = 1; //�������Ѿ����ʹ���
    p = g.adjlist[v].firstarc;
    while (p!=NULL){
        if(!visited[p->adjvex]){
            DFS(g, p->adjvex, visited);
        }
        p=p->nextarc;
    }
}   

/*�ڽӱ�ͼ�Ĺ����������(���������Ĳ������)
ͨ�����У����ΰѸ��ڵ���ӣ������Ӻ���ʸ��ӽڵ�
*/
void BFS(Graph g, int v, int *visited[])
{   
    ArcNode *p; //����
    LkQue Q; //QΪ������
    InitQueue(&Q);
    printf("��%d", v);
    visited[v]=1; //���ѷ��ʱ�־
    EnQueue(&Q, v); //���ʹ��Ķ��������
    while (!EmptyQueue(Q)){
        v = GetHead(Q);
        OutQueue(&Q); //���������
        p = g.adjlist[v].firstarc; //�ҵ�v�ĵ�һ���ڽ��
        while(p!=NULL){
            if(!visited[p->adjvex]){
                //���ʸ��ڵ�
                printf("��%d", p->adjvex);
                visited[p->adjvex]=1;
                EnQueue(&Q, p->adjvex);
            }
            p = p->nextarc; //����v���ڽӵ�����˳������
        }
    }
}

//����һ��ͼ���ж��ٸ���ͨ�����������ٸ�������ͨ����ͼ��)
int Count_Component(Graph g)
{
    int count=0, v;
    int visited[g.vexnum];
    for(int v=0; v<g.vexnum; v++){visited[v]=0;} // ��ʼ����Ϊ0������û�б����ʹ�

    for(int v=0; v<g.vexnum; v++){
        if(!visited[v]){
            count++; //������1
            printf("\n�� %d ����ͨ�����������¶��㣺");
            BFS(g, 0, &visited);
        }
    }

    printf("һ���� %d ����ͨ����\n", count);  //count������ͨ�����ĸ���

    return count;
}