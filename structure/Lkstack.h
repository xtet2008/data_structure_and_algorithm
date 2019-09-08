#include<stdlib.h>
// #define NULL 0xFFFFFFFF

/* ջ����
Empty_stack: head->NULL   (head->next=NULL)
Push: A��B��C��D��E
Push_stack: head->E->D->C->B->A->NULL   (A->next=NULL)
Pop��E��D��C��B��A
*/
typedef int DataType; 
typedef struct node
{
    DataType data;
    struct node *next;
}LkStk;

void InitStack(LkStk *LS)
//��ʼ��
{
    LS = (LkStk *)malloc(sizeof(LkStk));
    LS->next = NULL; //����һ����ջ
}

int EmptyStack(LkStk *LS)
//�ж��Ƿ��ջ����1����0
{
    if(LS->next==NULL){
        return 1;
    }else{
        return 0;
    }
}

void Push(LkStk *LS, DataType x)
//��ջ
{
    LkStk *temp;
    temp = (LkStk *)malloc(sizeof(LkStk)); // tempָ��������½��
    temp->data = x; //�½���data��ֵΪx
    temp->next = LS->next; // temp��next��ָ��ԭ��ջ�Ķ����
    LS->next = temp; //ָ���µ�ջ�����
}

int Pop(LkStk *LS)
//��ջ
{
    LkStk *temp;
    if(!EmptyStack(LS)){
        temp = LS->next; // tempָ��ջ�����
        LS->next = temp->next; //ԭջ������һ�����Ϊ�µ�ջ��
        free(temp);
        return 1;
    }else{
        return 0;
    }
}

DataType GetTop(LkStk *LS)
//ȡջ��Ԫ��
{
    if(!EmptyStack(LS)){
        return LS->next->data; //��ջ�ǿգ�����ջ������Ԫ��
    }else{
        return NULL; //���򷵻ؿ�Ԫ��
    }
}