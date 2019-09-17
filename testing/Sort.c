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
    memcpy(LS1, LS, sizeof(LS)); //将 LS内容拷贝到 LS1上，拷贝的字节长度为 sizeof(LS)
    straight_insert_sort(LS1, n); //直接插入排序
    printf("\nStraight insert sorting end ---------");

    printf("\n\n\nBubble sorting start ---------");
    List LS2;
    memcpy(LS2, LS, sizeof(LS));
    bubble_sort(LS2, n); //冒泡排序
    printf("\nBubble insert sorting end ---------");

    printf("\n\n\nQuick sorting start ---------");
    List LS3;
    memcpy(LS3, LS, sizeof(LS));
    printf("\nraw data: ");
    PrintList(LS3);
    quick_sort(LS3, 1, n); //快速排序
    printf("\nQuick insert sorting end ---------");

    printf("\n\n\nSelect sorting start ---------");
    List LS4;
    memcpy(LS4, LS, sizeof(LS));
    select_sort(LS4, n); //选择排序
    printf("\nSelect insert sorting end ---------");

    printf("\n\n\nHeap sorting start ---------");
    List LS5;
    memcpy(LS5, LS, sizeof(LS));
    heap_sort(LS5, n); //选择排序
    printf("\nHeap insert sorting end ---------");

    getch();
}