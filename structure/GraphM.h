#include<stdlib.h>
#include<stdio.h>

/* 邻接矩阵表示图
通过两顶点之间的二维数据值=0或1来判断是否有边，例如：(V0, V1)=1,代表从顶点V0至顶点V1之间有边
    V0  V1  V2 V3
V0  0   1   0   0   => (V0, V0)或<V0, V0>=0，(V0, V1)=1，(V0, V2)=0，(V0, V3)=0
V1  1   0   1   0   => (V1, V0)或<V1, V0>=1，(V1, V1)=0，(V1, V2)=1，(V1, V3)=0
V2  1   0   0   1   ......
V3  0   0   0   0   => (V3, V0)或<V1, V0>=0，(V3, V1)=0，(V3, V2)=0，(V3, V3)=0
*/
const int vnum=20; //Vertex num顶点个数
typedef char VertexType ;
typedef struct gp
{
    VertexType vexs[20]; //顶点信息
    int arcs[20][20]; // 邻接矩阵，两点之间是否有边，1代表有，0则代表没边
    int vexnum, arcnum; //顶点数，边数
}Graph;


/* 带权图：邻接矩阵(二维数组)的值表示边和边之间的距离，权值
在以上的结构基础之上，将 int arcs[20][20]改为 WeightType arcs[20][20] 数据域，代表两点之间的距离，权值
权值或是无穷小或无穷大代表没有权值，即没有边
*/
typedef int WeightType;
const int MAX_INT=32767; //权值：无穷大
typedef struct gp2
{
    VertexType vexs[20]; //顶点信息
    WeightType arcs[20][20]; //两顶点之间权值，无穷大或无穷小代表无边
    int vexnum, arcnum;
}WGraph;



/*建图（无向带权图）
先将矩阵A的每个元素都初始化为最大值（当作无边），然后再读入边值（i, j, Wij），并将A的相应元素置成Wij
*/
void CreateGraph(Graph *g)
{
    // int i, j, n, e, w;
    int i, v1, v2, weight;
    char ch;

    // printf("请输入顶点数和边数（空格隔开）：");
    // scanf("%d, %d", &n, &e);
    // g->vexnum=n; //顶点数
    // g->arcnum=e; //边数    

    // // 读入顶点信息
    // for(i=0; i<g->vexnum; i++)
    // {   
    //     printf("\n请输入顶点名（一个字符）：");
    //     scanf("%c", &ch);
    //     g->vexs[i] = ch;
    // }

    // 先构建图的顶点信息
    i=0; 
    while(1){
        printf("请输入顶点名（一个字符），Q代表结束输入：");
        fflush(stdin); //最好在scanf之前，清空缓存，不然会出现异常，导致直接跳过scanf函数执行后面的代码
        scanf("%c", &ch);
        if(ch=='Q' || ch=='\n' || ch=='\r'){
            if(i){
                break;
            } else{
                printf("请确保图中至少有一个以上顶点\n");
            }
        }else{
            g->vexs[i] = ch; // 数组下标从0开始
            i++;
            g->vexnum ++;
        }
    }

    // 初始化所有点到点的边距离权值为：无穷大
    for(v1=0; v1<g->vexnum; v1++){
        for(v2=0; v2<g->vexnum; v2++){
            g->arcs[v1][v2] = MAX_INT;
        }
    }

    i=0; 
    while(1){
        printf("\n请输入顶点对索引编号及距离的权值，三个值分别以空格隔开，例如：0 1 10 代表(0,1)=10，全0代表结束输入：");
        scanf("%d %d %d", &v1, &v2, &weight); // 读入边（顶点对）和权值
        if(v1 || v2 || weight){
            i++;
            g->arcnum = i;
            g->arcs[v1][v2] = weight;
            g->arcs[v2][v1] = weight; //因为是无向图，所以两点之间要生成两个顶点对（边）
        }else{
            break;
        }
    }
}
