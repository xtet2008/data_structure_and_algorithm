#include "../structure/GraphMinTree.h"

void main(){
    Graph G=Build_Testing_Tree();
    prim(G, 0);
    getch();
}