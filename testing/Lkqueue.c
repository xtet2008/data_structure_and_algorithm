#include<stdlib.h>
#include<stdio.h>
#include "../structure/Lkqueue.h"

void main(){
    if(0){
        LkQue *LQ; InitQueue(LQ); //TODO: implement
        // *LQ��Ϊʲô�ȶ�����ָ������ٴ���ַ�����������ַ�ʽ�������ִ��InitQueue��Ĵ��룬LQ->front=temp; ʱ�����
    }

    LkQue LQ;
    InitQueue(&LQ);

    int x;
    printf("������1������Ϊ�������½��ֵ������0Ϊ������");
    scanf("%d", &x);
    while(x!=0){
        EnQueue(&LQ, x);
        printf("������1������Ϊ�������½��ֵ������0Ϊ������");
        scanf("%d", &x);
    }

    printf("\npop");
    while(!EmptyQueue(LQ)){
        printf("��%d", GetHead(LQ));
        OutQueue(&LQ);
    }
    getch();
}