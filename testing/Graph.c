#include "../structure/GraphM.h"
void main(){
    Graph *G = (Graph *)malloc(sizeof(Graph));
    G->vexnum = 0;
    G->arcnum = 0;
    CreateGraph(G);
    getch();
} 


// #include "../structure/GraphLk.h"
// void main(){
//     Graph *G = (Graph *)malloc(sizeof(Graph));
//     G->vexnum = 0;
//     G->arcnum = 0;
//     CreateAdjlist(G);
//     getch();
// } 