#include<stdlib.h>
#include<stdio.h>

/* �ڽӱ���ʾͼ
     V0
    / |
   /  |
  V1  |  V3
   \  | /
    \ |/
     V2

/* �ڽӱ���ʾЧ������
AdjList[num] = vertex|firstarc = adjvex|nextarc  
0               [V0|->]          [1|->]          [2|^] 
1               [V1|->]          [0|->]          [2|^]
2               [V2|->]          [0|->]          [1|->]          [3|^]
3               [V3|->]          [2|^]
*/

#define vnum 20
typedef int WeightType; //�߳�����
typedef struct arcnode //�����
{
    int adjvex; //��һ���ߵĶ�����
    WeightType weight; //��Ȩͼ��Ȩֵ�����ǷǴ�Ȩͼ���ɲ��ø���
    struct arcnode *nextarc; //ָ����һ���ߵ�ָ��
}ArcNode;
typedef struct vexnode //ͷ���
{
    int vertex; //������
    ArcNode *firstarc; //ָ���һ���ߵ�ָ��
}AdjList[20];
typedef struct gp
{
    AdjList adjlist;
    int vexnum, arcnum; //����ͱߵĸ���
}Graph;



void CreateAdjlist(Graph *g)
//��������ͼ���ڽӱ��㷨
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
        printf("\n�����붥�������ֵ���ɵıߣ��Կո���������磺0 1�����Ӷ���0������1�ıߣ�����0��������룺");
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