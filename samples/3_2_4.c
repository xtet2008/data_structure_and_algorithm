// #include<stdlib.h>
// #include<stdio.h>
#include "../structure/Lkqueue.h"

//����Ӧ�ã�ģ�������Ŷ�ȡ��
void main(){
    LkQue LQ;
    int n;
    char ch;
    InitQueue(&LQ);
    
    while(1){
        //TODO: check ��֪Ϊɶ��ִ�г����ʱ�������ʾ��������ӡ������ʾ
        printf("\n���������A:�ͻ�ȡ���Ŷӣ�N:���ŵ��˽��ܷ���Q:�鿴�����л�ʣ��Щ����û�н��ܷ��񲢽�������");
        scanf("%c", &ch);

        switch(ch){
            case 'A':
                printf("\n������ͻ�ȡ���ĺ��루��������");
                scanf("%d", &n);
                EnQueue(&LQ, n);
                break;
            case 'N':
                if(!EmptyQueue(LQ)){                    
                    printf("\n�����Ϊ %d �Ŀͻ���ǰ̨���ڽ��ܷ���", GetHead(LQ)); //ȡ�������׽��Ԫ��
                    OutQueue(&LQ); //������
                }else{
                    printf("\n��ʱû�пͻ��Ŷӵȴ�����");
                }
                break;
            case 'Q':
                printf("\n�ŶӵȺ���ܷ�����������ǣ�");
                break;
        }

        if(ch=='Q'){
            while(!EmptyQueue(LQ)){
                printf("��%d", GetHead(LQ)); //ȡ���׽��Ԫ��
                OutQueue(&LQ); //������
            }
            break;
        }
    }

    getch();
}