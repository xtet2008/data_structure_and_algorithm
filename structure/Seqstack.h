#include<stdio.h>
// #include<stdlib.h>

typedef int DataType; //��int���� DataType �ṹ�ͣ���Ȼ�ṹ��������ʹ�� != �� == �������ж�

/* ˳��ջ */
const int maxsize = 50;  //˳��ջ������
typedef struct seqstack
{
    DataType data[50]; // �洢ջ������Ԫ�ص�����
    int top; // ��־ջ��λ�õı���
}SeqStk;

int InitStack(SeqStk *stk)
// ��ʼ��
{
    stk->top=0; //
    return 1;
}

int EmptyStack(SeqStk *stk)
//�ж�ջ�Ƿ�Ϊ�գ�Ϊ�շ���1�����򷵻�0
{
    if (stk->top==0){
        return 1;
    }else{
        return 0;
    }
}

int Push(SeqStk *stk, DataType x)
//��ջ����ջδ����Ԫ��x��ջ�У�������ʾ������Ϣ
{
    if (stk->top==maxsize-1){
        printf("ջ����\n"); //����
        return 0;
    }else{
        stk->top++; // ջδ����topֵ��1
        stk->data[stk->top]=x; // Ԫ��x��ջ
        return 1;
    }
}

int Pop(SeqStk *stk)
//��ջ
{
    if(EmptyStack(stk)){
        printf("����\n");
        return 0;
    }else{
        stk->top--; // topֵ��1
        return 1;
    }
}

DataType GetTop(SeqStk *stk)
//ȡջ��Ԫ��
{
    if (EmptyStack(stk)){
        return NULL;
    }else{
        return stk->data[stk->top];
    }
}