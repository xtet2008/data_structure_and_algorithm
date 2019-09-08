// #include<stdlib.h>
// #include<stdio.h>
#include "../structure/Lkqueue.h"

//队列应用，模拟银行排队取号
void main(){
    LkQue LQ;
    int n;
    char ch;
    InitQueue(&LQ);
    
    while(1){
        //TODO: check 不知为啥在执行程序的时候，这个提示会连续打印两行提示
        printf("\n请输入命令，A:客户取号排队；N:报号的人接受服务；Q:查看队伍中还剩哪些号码没有接受服务并结束程序。");
        scanf("%c", &ch);

        switch(ch){
            case 'A':
                printf("\n请输入客户取到的号码（整数）：");
                scanf("%d", &n);
                EnQueue(&LQ, n);
                break;
            case 'N':
                if(!EmptyQueue(LQ)){                    
                    printf("\n请号码为 %d 的客户上前台窗口接受服务", GetHead(LQ)); //取出队列首结点元素
                    OutQueue(&LQ); //出队列
                }else{
                    printf("\n暂时没有客户排队等待服务");
                }
                break;
            case 'Q':
                printf("\n排队等候接受服务的人依次是：");
                break;
        }

        if(ch=='Q'){
            while(!EmptyQueue(LQ)){
                printf("，%d", GetHead(LQ)); //取出首结点元素
                OutQueue(&LQ); //出队列
            }
            break;
        }
    }

    getch();
}