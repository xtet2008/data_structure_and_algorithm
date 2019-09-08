#include<stdio.h>
#include<stdlib.h>
#include "../structure/Seqstack.h"
#include "../structure/Lkqueue.h"

/*
����ջ�Ͷ������ݽṹ�ۺ�Ӧ����ģ��ͣ��������ϵͳ����������ͣ�������뿪ͣ������ͣ��������Ⱥ��Ŷ�ͣ����
�ο�������ṹ�飺84ҳ
*/
void main(){
    SeqStk ps, ts; //ͣ��������ʱͣ��ջ���޶�ͣ��λ���ȣ������� ˳��ջ�ṹ
    LkQue LQ; // ����������У����޳��ȣ������� ���ӽṹ
    int out, number, temp;
    char ch;

    InitStack(&ps); // ��ʼ�� psջ���洢ͣ������ͣ�ŵĳ���
    InitStack(&ts); // ��ʼ�� tsջ�������洢��ʱ�˳�ͣ�����ĳ���
    // ����ͣ�����ǵ���ͣ���ģ���ô�ʼͣ��ȥ�ĳ���Ҫ�˳���ʱ��������ͣ�������ĳ����˳�
    InitQueue(&LQ); // ��ʼ�� LQ���У������洢ͣ�ڱ�����ŶӴ�����ͣ��������ͣ���ĳ���
    out = 0; //0����ͣ������δ�ҵ�����Ϊnumber�ĳ�����1�����ҵ���

    // printf("������Ҫִ�еĶ������A:��������ͣ������C:�鿴ͣ���ڳ�����D:��������ͣ������L:�鿴���������Q:�˳�����");
    printf("\n������Ҫִ�еĶ������A:��������ͣ������D:��������ͣ������Q:�鿴ͣ�����������˳���");
    scanf("%c", &ch); //�������������ΪQʱ�˳�����
    while(1){
        if(ch=='Q'){
            printf("\nͣ������ͣ�ų������£�");
            while(!EmptyStack(&ps)){
                printf("��%d", GetTop(&ps));
                Pop(&ps);
            }

            printf("\n������Ŷӵĳ������£�");
            while(!EmptyQueue(LQ)){
                printf("��%d", GetHead(LQ));
                OutQueue(&LQ);
            }

            break;
        }

        printf("\n�����복�����룺"); 
        scanf("%d", &number); //���복��
        switch(ch){                
            case 'A': // ����Ϊ'A'ʱ����������ͣ����
                {
                    if(ps.top==maxsize-1){
                        EnQueue(&LQ, number);
                        printf("ͣ������������ %d �ų�ʻ�����ȴ�ͣ����\n", number);
                    }else{
                        Push(&ps, number);
                        printf("���ƺ�Ϊ %d �ĳ����ѳɹ�ͣ��ͣ������\n", number);
                    }
                    break;
                }
            case 'D': // ����Ϊ 'D' ʱ����������ͣ����
                {
                    while (!EmptyStack(&ps)){
                        temp = GetTop(&ps);  //temp��ʱ��������ų�ջ�ı�ţ�����ͣ����������һ����
                        Pop(&ps);
                        if(temp!=number){
                            Push(&ts, temp); //�������ȡ���ĳ�������Ҫ����ʻ��������������ŵ���һ�������ʱ�˳�������ջ����
                        }else{
                            printf("���ƺ�Ϊ %d �ĳ�����ʻ��ͣ������\n", number);
                            out = 1;
                            break; //���ֻ���˳���ǰwhile��Ӷ����룬�����whileִ�д��룬�����˳� case 'D':��
                        }   
                    }
                    
                    while(!EmptyStack(&ts)){ 
                        //��Ų������ʱͣ�����ĳ�����ͣ����
                        temp = GetTop(&ts);
                        Pop(&ts);
                        Push(&ps, temp);
                    }

                    if(!out){
                        printf("ͣ������û��ͣ�ų��ƺ�Ϊ %d �ĳ�����\n", number);
                    }
                    else if(!EmptyQueue(LQ)){
                        // ����г���ʻ��ͣ��������ô��ͣ�ڱ�����������еĵ�һ����ʻ��ͣ������
                        temp = GetHead(LQ);
                        OutQueue(&LQ);
                        printf("����ϵĳ��ƺ�Ϊ %d �ĳ�����ʻ��ͣ������\n", temp);
                        Push(&ps, temp);
                    }
                    
                    out = 0; // �ָ�����״̬
                    break;
                }
        }

        printf("\n������Ҫִ�еĶ������A:��������ͣ������D:��������ͣ������Q:�鿴ͣ�����������˳���");
        scanf("%c", &ch); //�������������ΪQʱ�˳�����
    }

    getch();
}