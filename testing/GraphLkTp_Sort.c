#include "../structure/GraphLkTp_Sort.h"

void main(){
    Graph G;
    CreateAdjlist(&G);
    Tp_Sort(G);
    getch();
}