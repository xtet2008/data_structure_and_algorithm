#include<stdlib.h>
#include<stdio.h>

/*
链队列
LkQue -> LkQueNode_A -> LkQueNode_B -> ... -> LkQueNode_X
LkQue(头结点) -> 首结点 ->              ... -> 尾结点(LkQueNode_X.next=NULL)
Empty：LQ.rear==LQ.front
EnQueue：new_QueNode.next=NULL; (LQ.rear)->next = new_QueNode; LQ.rear=new_QueNode
OutQueue：pop_Queue=(LQ.front)->next;   (LQ.front)->next=pop_Queue->next;    if (pop_Queue.next==NULL){LQ.rear=LQ.front;}
GetHead：return LQ.front->next->data;
*/

typedef int DataType; //用int代替 DataType 结构型，不然结构变量不能使用 != 或 == 操作符判断
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
//队列初始化
{
    LkQueNode *temp;
    temp = malloc(sizeof(LkQueNode)); //生成队列的head头结点
    LQ->front=temp; //队列头指针指向队列头结点
    LQ->rear=temp; //队列尾指针指向队列尾结点
    (LQ->front)->next=NULL;  //相当于 temp->next=NULL
}

int EmptyQueue(LkQue LQ)
//判断队列是否为空
{
    if(LQ.rear==LQ.front){
        return 1; //队列为空
    }else{
        return 0;
    }
}

void EnQueue(LkQue *LQ, DataType x)
//入队列
{
    LkQueNode *temp;
    temp = (LkQueNode *)malloc(sizeof(LkQueNode));
    temp->data = x;
    temp->next = NULL;
    (LQ->rear)->next = temp; //新结点入队列 
    LQ->rear = temp; //重置队列尾结点
}

int OutQueue(LkQue *LQ)
//出队列
{
    LkQueNode *temp;
    if(EmptyQueue(*LQ)){
        printf("队列为空，无法出队.\n");
        return 0;
    }else{
        temp = (LQ->front)->next; //指向队列的首结点
        (LQ->front)->next = temp->next; //修改头结点指针域指向新的首结点
        if(temp->next==NULL){
            LQ->rear=LQ->front; //无首结点时，front和rear都指向头结点
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
        return temp->data; //队列首结点元素
    }
}