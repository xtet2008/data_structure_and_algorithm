// #include<stdio.h> // It's already exist in the file ../structure/Search.h
// #include<stdlib.h>
#include "../structure/Search.h"

void main(){
    int search_arr[9] = {10, 13, 17, 20, 30, 55, 68, 89, 95};
    int length = 9;

    SqTable T;
    T.n=length;
    printf("Array list：");
    for (int i=0; i<length; i++){
        printf(", %d", search_arr[i]);
        T.elem[i+1].key = search_arr[i]; //SqTable数组的起始下标为1，所以要 i+1
    }

    printf("\nSequence Search：%d", SearchSqTable(T, 17));
    fflush(stdin);
    printf("\nBinary Search：%d", SearchBin(T, 17));

    if (0){
        BinTree T1=CreateBinTree();
        BinTree S1=SearchBST(T1, 76);

        BinTree T2=CreateBinTree();
        BinTree S2=SearchBST(T2, 22);
    }

    int tree_arr[7] = {50, 48, 24, 55, 53, 50, 90};
    int length2=7;
    BinTree T3=malloc(sizeof(BinTree));
    T3->key = NULL; //初始化
    for (int i=0; i<length2; i++){
        InsertBST(T3, tree_arr[i]);
    }

    getch();
}