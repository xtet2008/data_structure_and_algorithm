#include "../structure/Tree.h"

void main(){
    BinTree bt;

    if (0){
        char a[10] = {'A', 'B', 'D', 'E', 'G', 'C', 'F'}; //������
        char b[10] = {'D', 'B', 'G', 'E', 'A', 'C', 'F'}; //������
        bt = CreateTree2(a, b, 0, 6, 0, 6); //TODO: check ��̫�ȶ�����bug���пտ�һ��Ϊʲô���ɵ����༸�����
        printf("\n�������");
        levelorder(bt);
    }

    bt = CreateTree();

    printf("\n���ĸ߶ȣ�%d", Height(bt));
    
    printf("\n�������");
    levelorder(bt);

    printf("\n�������");
    preorder(bt);

    printf("\n�ǵݹ��������(����ջ)");
    preorder(bt);
    
    printf("\n�������");
    inorder(bt);

    printf("\n�������");
    postorder(bt);

    getch();
    // getchar();
}

