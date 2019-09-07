#include<stdlib.h>
#include<stdio.h>

typedef int DataType; //用int代替 DataType 结构型，不然结构变量不能使用 != 或 == 操作符判断
const int maxsize=4;

//顺序队列
typedef struct seqqueu
{
    DataType data[20]; //TODO: data[maxsize]会提示出错，只能填数字
    int front; //队列首指针，取值范围 0 ~ (mazsize-1)
    int rear; //队列尾指针，取值范围 0 ~ (mazsize-1)
}SeqQue;

//循环队列
typedef struct cycqueue
{
    DataType data[4]; //TODO: data[maxsize]
    int front; //队列首指针，取值范围 0 ~ (mazsize-1)
    int rear; //队列尾指针，取值范围 0 ~ (mazsize-1)
}CycQue;


void InitQueue(CycQue CQ)
//队列初始化
{
    CQ.front=0; 
    CQ.rear=0;
}

int EmptyQueue(CycQue CQ)
//判断队列是否为空
{
    if (CQ.rear==CQ.front){
        return 1; //队列为空
    }else{
        return 0; //不为空
    }
}

int EnQueue(CycQue CQ, DataType x)
//入队列
{
    if ((CQ.rear+1)%maxsize == CQ.front){
        printf("队列已满，无法再入队");
        return 0; //入队失败
    }else{
        CQ.rear = (CQ.rear+1) % maxsize;
        CQ.data[CQ.rear] = x;
        return 1; //入队成功
    }
}

int OutQueue(CycQue CQ)
//出队列
{
    if(EmptyQueue(CQ)){
        printf("队列为空，无法出队");
        return 0;
    }else{
        CQ.front = (CQ.front+1) % maxsize; // 不为空出队列（移动队列首指针）
        return 1;
    }
}

DataType GetHead(CycQue CQ)
//队队列首元素
{
    if (EmptyQueue(CQ)){
        return (DataType)NULL;
    }else{
        return CQ.data[(CQ.front+1) % maxsize];
    }
}

void PrintQueue(CycQue CQ)
//打印所有队列
{
    printf("queue：");
    while(!EmptyQueue(CQ)){
        printf("，%c", GetHead(CQ)); //"%c"意思是以字符的方式打印出来，将asci码翻译成字符
        OutQueue(CQ);
    }
    printf("\n");
}