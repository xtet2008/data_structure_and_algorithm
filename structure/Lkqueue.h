#include<stdlib.h>
#include<stdio.h>

/*
������
LkQue -> LkQueNode_A -> LkQueNode_B -> ... -> LkQueNode_X
LkQue(ͷ���) -> �׽�� ->              ... -> β���(LkQueNode_X.next=NULL)
Empty��LQ.rear==LQ.front
EnQueue��new_QueNode.next=NULL; (LQ.rear)->next = new_QueNode; LQ.rear=new_QueNode
OutQueue��pop_Queue=(LQ.front)->next;   (LQ.front)->next=pop_Queue->next;    if (pop_Queue.next==NULL){LQ.rear=LQ.front;}
GetHead��return LQ.front->next->data;
*/

typedef int DataType; //��int���� DataType �ṹ�ͣ���Ȼ�ṹ��������ʹ�� != �� == �������ж�
typedef struct LinkQueueNode
{
    DataType data;
    struct LinkQueueNode *next;
} LkQueNode;
typedef struct LkQueue
{
    LkQueNode *front, *rear;
}LkQue;

void InitQueue(LkQue *LQ)
//���г�ʼ��
{
    LkQueNode *temp;
    temp = malloc(sizeof(LkQueNode)); //���ɶ��е�headͷ���
    LQ->front=temp; //����ͷָ��ָ�����ͷ���
    LQ->rear=temp; //����βָ��ָ�����β���
    (LQ->front)->next=NULL;  //�൱�� temp->next=NULL
}

int EmptyQueue(LkQue LQ)
//�ж϶����Ƿ�Ϊ��
{
    if(LQ.rear==LQ.front){
        return 1; //����Ϊ��
    }else{
        return 0;
    }
}

void EnQueue(LkQue *LQ, DataType x)
//�����
{
    LkQueNode *temp;
    temp = (LkQueNode *)malloc(sizeof(LkQueNode));
    temp->data = x;
    temp->next = NULL;
    (LQ->rear)->next = temp; //�½������� 
    LQ->rear = temp; //���ö���β���
}

int OutQueue(LkQue *LQ)
//������
{
    LkQueNode *temp;
    if(EmptyQueue(*LQ)){
        printf("����Ϊ�գ��޷�����.\n");
        return 0;
    }else{
        temp = (LQ->front)->next; //ָ����е��׽��
        (LQ->front)->next = temp->next; //�޸�ͷ���ָ����ָ���µ��׽��
        if(temp->next==NULL){
            LQ->rear=LQ->front; //���׽��ʱ��front��rear��ָ��ͷ���
        }
        free(temp);
        return 1;
    }
}

DataType GetHead(LkQue LQ)
{
    LkQueNode *temp;
    if(EmptyQueue(LQ)){
        return NULL;
    }else{
        temp = LQ.front->next;
        return temp->data; //�����׽��Ԫ��
    }
}