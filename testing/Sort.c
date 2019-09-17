#include<string.h>
#include "../structure/Sort.h"

void main(){
    int arr[8] = {45, 38, 66 , 90, 88, 10, 25, 45};
    int i, n=8;
    List LS;

    LS[0].key = NULL;
    for(int i=0; i<=length; i++){
        if (i<n){
            LS[i+1].key = arr[i];
        }else{
            LS[i+1].key = NULL;
        }
    }


    printf("\nStraight insert sorting start ---------");
    List LS1;
    memcpy(LS1, LS, sizeof(LS)); //�� LS���ݿ����� LS1�ϣ��������ֽڳ���Ϊ sizeof(LS)
    straight_insert_sort(LS1, n); //ֱ�Ӳ�������
    printf("\nStraight insert sorting end ---------");

    printf("\n\n\nBubble sorting start ---------");
    List LS2;
    memcpy(LS2, LS, sizeof(LS));
    bubble_sort(LS2, n); //ð������
    printf("\nBubble insert sorting end ---------");

    printf("\n\n\nQuick sorting start ---------");
    List LS3;
    memcpy(LS3, LS, sizeof(LS));
    printf("\nraw data: ");
    PrintList(LS3);
    quick_sort(LS3, 1, n); //��������
    printf("\nQuick insert sorting end ---------");

    printf("\n\n\nSelect sorting start ---------");
    List LS4;
    memcpy(LS4, LS, sizeof(LS));
    select_sort(LS4, n); //ѡ������
    printf("\nSelect insert sorting end ---------");

    printf("\n\n\nHeap sorting start ---------");
    List LS5;
    memcpy(LS5, LS, sizeof(LS));
    heap_sort(LS5, n); //������
    printf("\nHeap insert sorting end ---------");

    printf("\n\n\nMerge sorting start ---------");
    List LS6;
    memcpy(LS6, LS, sizeof(LS));
    LS6[n+1].key = 14; //�������һ��Ԫ�أ�ʹ����Ϊ��������ɹ鲢��ʱ����β��Ԫ��û�б��鲢���������������Ժ͵���
    merge_sort(LS6, n+1); //�ϲ�(��·�鲢)����
    printf("\nMerge insert sorting end ---------");

    getch();
}