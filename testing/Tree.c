#include "../structure/Tree.h"

void main(){
    BinTree bt = CreateTree();

    printf("\n���ĸ߶ȣ�%d", Height(bt));
    
    printf("\n�������");
    levelorder(bt);

    printf("\n�������");
    preorder(bt);
    
    printf("\n�������");
    inorder(bt);

    printf("\n�������");
    postorder(bt);

    getch();
    // getchar();
}