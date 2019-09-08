#include<stdio.h>
// #include<stdlib.h>

typedef int DataType; //��int���� DataType �ṹ�ͣ���Ȼ�ṹ��������ʹ�� != �� == �������ж�

/* ˳��ջ 
data��[0]��[1]��[2]��[...]��[maxsize-1]
empty: top=0
push��top++
pop��top--
full:  top=maxsize-1
*/
const int maxsize = 5;  //˳��ջ������
typedef struct seqstack
{
    DataType data[5]; // �洢ջ������Ԫ�ص�����
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



/* ˫ջ 
data��[0]��[1]��[2]��[...]��[maxsize-1]
empty: top1=0��top2=maxsize-1
push: top1++��top2--
pop��top1--��top2++
full:  top1+1 == top2
*/
// const int maxsize = 50;  //˳��ջ������
typedef struct dseqstack
{
    DataType data[50]; // �洢ջ������Ԫ�ص�����
    int top1; // ջ1��λ��
    int top2; // ջ2��λ��
}DSeqStk;

int InitDStack(DSeqStk *dstk)
// ��ʼ��
{
    dstk->top1=0; //ջ1����ʼλ��
    dstk->top2=maxsize-1; //ջ2����ʼλ��
    return 1;
}