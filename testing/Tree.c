#include "../structure/Tree.h"

void main(){
    BinTree bt;

    if (0){
        char a[10] = {'A', 'B', 'D', 'E', 'G', 'C', 'F'}; //先序列
        char b[10] = {'D', 'B', 'G', 'E', 'A', 'C', 'F'}; //中序列
        bt = CreateTree2(a, b, 0, 6, 0, 6); //TODO: check 不太稳定，有bug，有空看一下为什么建成的树多几个结点
        printf("\n层序遍历");
        levelorder(bt);
    }

    bt = CreateTree();

    printf("\n树的高度：%d", Height(bt));
    
    printf("\n层序遍历");
    levelorder(bt);

    printf("\n先序遍历");
    preorder(bt);

    printf("\n非递归先序遍历(利用栈)");
    preorder(bt);
    
    printf("\n中序遍历");
    inorder(bt);

    printf("\n后序遍历");
    postorder(bt);

    getch();
    // getchar();
}

