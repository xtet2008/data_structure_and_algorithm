#include "../structure/Tree.h"

void main(){
    BinTree bt = CreateTree();

    printf("\n树的高度：%d", Height(bt));
    
    printf("\n层序遍历");
    levelorder(bt);

    printf("\n先序遍历");
    preorder(bt);
    
    printf("\n中序遍历");
    inorder(bt);

    printf("\n后序遍历");
    postorder(bt);

    getch();
    // getchar();
}