#include<stdlib.h>
#include<stdio.h>

typedef int DataType; //��int���� DataType �ṹ�ͣ���Ȼ�ṹ��������ʹ�� != �� == �������ж�
const int maxsize=4;

/*˳�����
data��[0]��[1]��[2]��[...]��[maxsize-1]
empty: front=0; rear=0;
full:  rear=maxsize-1
push��rear++
pop��front++
*/
typedef struct seqqueu
{
    DataType data[20]; //TODO: data[maxsize]����ʾ����ֻ��������
    int front; //������ָ�룬ȡֵ��Χ 0 ~ (mazsize-1)
    int rear; //����βָ�룬ȡֵ��Χ 0 ~ (mazsize-1)
}SeqQue;



/*ѭ������
data��[0]��[1]��[2]��[...]��[maxsize-1]
init: front=0; rear=0;
push: rear = (rear+1)%maxsize
pop:  front = (front+1)%maxsize
getHead: Get data��(front+1)%maxsize��
empty: front == rear;
full:  (rear+1)%maxsize == front
���洢����: maxsize-1����ΪҪ����һ��Ԫ�ؿռ䣬��ֻʣ��һ���ռ�ʱ��Ϊβָ�룬׷������ָ�룬�ж�Ϊ��������������Ͷӿղ�������)
*/
typedef struct cycqueue
{
    DataType data[4]; //TODO: data[maxsize]
    int front; //������ָ�룬ȡֵ��Χ 0 ~ (mazsize-1)
    int rear; //����βָ�룬ȡֵ��Χ 0 ~ (mazsize-1)
}CycQue;


void InitQueue(CycQue CQ)
//���г�ʼ��
{
    CQ.front=0; 
    CQ.rear=0;
}

int EmptyQueue(CycQue CQ)
//�ж϶����Ƿ�Ϊ��
{
    if (CQ.rear==CQ.front){
        return 1; //����Ϊ��
    }else{
        return 0; //��Ϊ��
    }
}

int EnQueue(CycQue CQ, DataType x)
//�����
{
    if ((CQ.rear+1)%maxsize == CQ.front){
        printf("�����������޷������");
        return 0; //���ʧ��
    }else{
        CQ.rear = (CQ.rear+1) % maxsize;
        CQ.data[CQ.rear] = x;
        return 1; //��ӳɹ�
    }
}

int OutQueue(CycQue CQ)
//������
{
    if(EmptyQueue(CQ)){
        printf("����Ϊ�գ��޷�����");
        return 0;
    }else{
        CQ.front = (CQ.front+1) % maxsize; // ��Ϊ�ճ����У��ƶ�������ָ�룩
        return 1;
    }
}

DataType GetHead(CycQue CQ)
//�Ӷ�����Ԫ��
{
    if (EmptyQueue(CQ)){
        return (DataType)NULL;
    }else{
        return CQ.data[(CQ.front+1) % maxsize];
    }
}

void PrintQueue(CycQue CQ)
//��ӡ���ж���
{
    printf("queue��");
    while(!EmptyQueue(CQ)){
        printf("��%c", GetHead(CQ)); //"%c"��˼�����ַ��ķ�ʽ��ӡ��������asci�뷭����ַ�
        OutQueue(CQ);
    }
    printf("\n");
}