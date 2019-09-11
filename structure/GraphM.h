#include<stdlib.h>
#include<stdio.h>

/* �ڽӾ����ʾͼ
ͨ��������֮��Ķ�ά����ֵ=0��1���ж��Ƿ��бߣ����磺(V0, V1)=1,����Ӷ���V0������V1֮���б�
    V0  V1  V2 V3
V0  0   1   0   0   => (V0, V0)��<V0, V0>=0��(V0, V1)=1��(V0, V2)=0��(V0, V3)=0
V1  1   0   1   0   => (V1, V0)��<V1, V0>=1��(V1, V1)=0��(V1, V2)=1��(V1, V3)=0
V2  1   0   0   1   ......
V3  0   0   0   0   => (V3, V0)��<V1, V0>=0��(V3, V1)=0��(V3, V2)=0��(V3, V3)=0
*/
const int vnum=20; //Vertex num�������
typedef char VertexType ;
typedef struct gp
{
    VertexType vexs[20]; //������Ϣ
    int arcs[20][20]; // �ڽӾ�������֮���Ƿ��бߣ�1�����У�0�����û��
    int vexnum, arcnum; //������������
}Graph;


/* ��Ȩͼ���ڽӾ���(��ά����)��ֵ��ʾ�ߺͱ�֮��ľ��룬Ȩֵ
�����ϵĽṹ����֮�ϣ��� int arcs[20][20]��Ϊ WeightType arcs[20][20] �����򣬴�������֮��ľ��룬Ȩֵ
Ȩֵ��������С����������û��Ȩֵ����û�б�
*/
typedef int WeightType;
const int MAX_INT=32767; //Ȩֵ�������
typedef struct gp2
{
    VertexType vexs[20]; //������Ϣ
    WeightType arcs[20][20]; //������֮��Ȩֵ������������С�����ޱ�
    int vexnum, arcnum;
}WGraph;



/*��ͼ�������Ȩͼ��
�Ƚ�����A��ÿ��Ԫ�ض���ʼ��Ϊ���ֵ�������ޱߣ���Ȼ���ٶ����ֵ��i, j, Wij��������A����ӦԪ���ó�Wij
*/
void CreateGraph(Graph *g)
{
    // int i, j, n, e, w;
    int i, v1, v2, weight;
    char ch;

    // printf("�����붥�����ͱ������ո��������");
    // scanf("%d, %d", &n, &e);
    // g->vexnum=n; //������
    // g->arcnum=e; //����    

    // // ���붥����Ϣ
    // for(i=0; i<g->vexnum; i++)
    // {   
    //     printf("\n�����붥������һ���ַ�����");
    //     scanf("%c", &ch);
    //     g->vexs[i] = ch;
    // }

    // �ȹ���ͼ�Ķ�����Ϣ
    i=0; 
    while(1){
        printf("�����붥������һ���ַ�����Q����������룺");
        fflush(stdin); //�����scanf֮ǰ����ջ��棬��Ȼ������쳣������ֱ������scanf����ִ�к���Ĵ���
        scanf("%c", &ch);
        if(ch=='Q' || ch=='\n' || ch=='\r'){
            if(i){
                break;
            } else{
                printf("��ȷ��ͼ��������һ�����϶���\n");
            }
        }else{
            g->vexs[i] = ch; // �����±��0��ʼ
            i++;
            g->vexnum ++;
        }
    }

    // ��ʼ�����е㵽��ı߾���ȨֵΪ�������
    for(v1=0; v1<g->vexnum; v1++){
        for(v2=0; v2<g->vexnum; v2++){
            g->arcs[v1][v2] = MAX_INT;
        }
    }

    i=0; 
    while(1){
        printf("\n�����붥���������ż������Ȩֵ������ֵ�ֱ��Կո���������磺0 1 10 ����(0,1)=10��ȫ0����������룺");
        scanf("%d %d %d", &v1, &v2, &weight); // ����ߣ�����ԣ���Ȩֵ
        if(v1 || v2 || weight){
            i++;
            g->arcnum = i;
            g->arcs[v1][v2] = weight;
            g->arcs[v2][v1] = weight; //��Ϊ������ͼ����������֮��Ҫ������������ԣ��ߣ�
        }else{
            break;
        }
    }
}
