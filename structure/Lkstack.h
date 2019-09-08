#include<stdlib.h>
// #define NULL 0xFFFFFFFF

/* 栈链表
Empty_stack: head->NULL   (head->next=NULL)
Push: A，B，C，D，E
Push_stack: head->E->D->C->B->A->NULL   (A->next=NULL)
Pop：E，D，C，B，A
*/
typedef int DataType; 
typedef struct node
{
    DataType data;
    struct node *next;
}LkStk;

void InitStack(LkStk *LS)
//初始化
{
    LS = (LkStk *)malloc(sizeof(LkStk));
    LS->next = NULL; //创建一个空栈
}

int EmptyStack(LkStk *LS)
//判断是否空栈，是1，否0
{
    if(LS->next==NULL){
        return 1;
    }else{
        return 0;
    }
}

void Push(LkStk *LS, DataType x)
//进栈
{
    LkStk *temp;
    temp = (LkStk *)malloc(sizeof(LkStk)); // temp指向申请的新结点
    temp->data = x; //新结点的data域赋值为x
    temp->next = LS->next; // temp的next域指向原来栈的顶结点
    LS->next = temp; //指向新的栈顶结点
}

int Pop(LkStk *LS)
//出栈
{
    LkStk *temp;
    if(!EmptyStack(LS)){
        temp = LS->next; // temp指向栈顶结点
        LS->next = temp->next; //原栈顶的下一个结点为新的栈顶
        free(temp);
        return 1;
    }else{
        return 0;
    }
}

DataType GetTop(LkStk *LS)
//取栈顶元素
{
    if(!EmptyStack(LS)){
        return LS->next->data; //若栈非空，返回栈顶数据元素
    }else{
        return NULL; //否则返回空元素
    }
}