#include "../structure/GraphM.h"
void main(){
    Graph *G = (Graph *)malloc(sizeof(Graph));
    G->vexnum = 0;
    G->arcnum = 0;
    CreateGraph(G);

    int visited[G->vexnum]; //����ͼ������Ӧ�Ķ������飨��Ҫ�������������ʱ��������ʱ�����ѷ��ʹ��Ķ�����Ϣ)
    for (int i=0; i<G->vexnum; i++){
        visited[i] = 0; //��ʼ��ȫΪ0������û�з��ʹ�
    }
    printf("������ȱ���ͼ���ڽӾ��󣩽����");
    DFS(G, 0, &visited);

    getch();
} 


// #include "../structure/GraphLk.h"
// void main(){
//     Graph *G = (Graph *)malloc(sizeof(Graph));
//     G->vexnum = 0;
//     G->arcnum = 0;
//     CreateAdjlist(G);
    
//     int visited[G->vexnum]; //����ͼ������Ӧ�Ķ������飨��Ҫ�������������ʱ��������ʱ�����ѷ��ʹ��Ķ�����Ϣ)
//     for (int i=0; i<G->vexnum; i++){
//         visited[i] = 0; //��ʼ��ȫΪ0������û�з��ʹ�
//     }
//     printf("������ȱ���ͼ���ڽӱ������");
//     DFS(*G, 0, &visited);

//     getch();
// } 