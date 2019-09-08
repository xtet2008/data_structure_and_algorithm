#include<stdio.h>
// #include<stdlib.h>

typedef int DataType; //用int代替 DataType 结构型，不然结构变量不能使用 != 或 == 操作符判断

/* 顺序栈 
data：[0]，[1]，[2]，[...]，[maxsize-1]
empty: top=0
push：top++
pop：top--
full:  top=maxsize-1
*/
const int maxsize = 5;  //顺序栈的容量
typedef struct seqstack
{
    DataType data[5]; // 存储栈中数据元素的数组
    int top; // 标志栈顶位置的变量
}SeqStk;

int InitStack(SeqStk *stk)
// 初始化
{
    stk->top=0; //
    return 1;
}

int EmptyStack(SeqStk *stk)
//判断栈是否为空，为空返回1，否则返回0
{
    if (stk->top==0){
        return 1;
    }else{
        return 0;
    }
}

int Push(SeqStk *stk, DataType x)
//进栈，若栈未满，元素x进栈中，否则提示出错信息
{
    if (stk->top==maxsize-1){
        printf("栈已满\n"); //上溢
        return 0;
    }else{
        stk->top++; // 栈未满，top值加1
        stk->data[stk->top]=x; // 元素x进栈
        return 1;
    }
}

int Pop(SeqStk *stk)
//出栈
{
    if(EmptyStack(stk)){
        printf("下溢\n");
        return 0;
    }else{
        stk->top--; // top值减1
        return 1;
    }
}

DataType GetTop(SeqStk *stk)
//取栈顶元素
{
    if (EmptyStack(stk)){
        return NULL;
    }else{
        return stk->data[stk->top];
    }
}



/* 双栈 
data：[0]，[1]，[2]，[...]，[maxsize-1]
empty: top1=0，top2=maxsize-1
push: top1++，top2--
pop：top1--，top2++
full:  top1+1 == top2
*/
// const int maxsize = 50;  //顺序栈的容量
typedef struct dseqstack
{
    DataType data[50]; // 存储栈中数据元素的数组
    int top1; // 栈1顶位置
    int top2; // 栈2顶位置
}DSeqStk;

int InitDStack(DSeqStk *dstk)
// 初始化
{
    dstk->top1=0; //栈1顶初始位置
    dstk->top2=maxsize-1; //栈2顶初始位置
    return 1;
}