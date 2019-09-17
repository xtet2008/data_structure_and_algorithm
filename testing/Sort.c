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
    heap_sort(LS5, n); //堆排序
    printf("\nHeap insert sorting end ---------");

    printf("\n\n\nMerge sorting start ---------");
    List LS6;
    memcpy(LS6, LS, sizeof(LS));
    LS6[n+1].key = 14; //特意添加一个元素，使长度为其数，造成归并的时候有尾巴元素没有被归并到的情况，方便测试和调试
    merge_sort(LS6, n+1); //合并(二路归并)排序
    printf("\nMerge insert sorting end ---------");

    getch();
}