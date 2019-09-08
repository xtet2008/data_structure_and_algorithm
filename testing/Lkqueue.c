#include<stdlib.h>
#include<stdio.h>
#include "../structure/Lkqueue.h"

void main(){
    if(0){
        LkQue *LQ; InitQueue(LQ); //TODO: implement
        // *LQ，为什么先定义结点指针变量再传地址到函数，这种方式会出错，在执行InitQueue里的代码，LQ->front=temp; 时会出错
    }

    LkQue LQ;
    InitQueue(&LQ);

    int x;
    printf("请输入1个数作为单链表新结点值，输入0为结束：");
    scanf("%d", &x);
    while(x!=0){
        EnQueue(&LQ, x);
        printf("请输入1个数作为单链表新结点值，输入0为结束：");
        scanf("%d", &x);
    }

    printf("\npop");
    while(!EmptyQueue(LQ)){
        printf("，%d", GetHead(LQ));
        OutQueue(&LQ);
    }
    getch();
}