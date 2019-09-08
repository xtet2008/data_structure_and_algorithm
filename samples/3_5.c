#include<stdlib.h>
#include "../structure/Lkstack.h"

//将链表逆转 (两个栈实现一个队列效果)
void ReverseList(LkStk *head ){
    LkStk *S;
    InitStack(S); //初始化链栈
    if(!EmptyStack(S)){S->next=NULL;} // 赋完NULL值后，本应该是0x00，但执行完 InitStack（）函数回到这里后 ->next 随机变化
    
    LkStk *p=head->next; 
    while(p!=NULL){
        Push(S, p->data); //元素进栈
        p=p->next; //扫描链表
    }

    p=head->next; 
    while (!EmptyStack(S)){
        p->data=GetTop(S); //取出S栈中的元素并填入单链表中
        Pop(S);
        p=p->next;
    }
}

void main(){
    LkStk *Stk;
    InitStack(Stk); 
    if(!EmptyStack(Stk)){Stk->next=NULL;}  //TODO: 赋完NULL值后，本应该是0x00，但执行完 InitStack（）函数回到这里后 ->next 随机变化

    printf("Stack Push");
    for(int i=0; i<10; i++){
        printf("，%d", i);
        Push(Stk, i);
    }

    ReverseList(Stk); //TODO:执行函数数不知为啥不会往下执行了

    printf("\nStack Pop");
    while(!EmptyStack(Stk)){
        printf("，%d", GetTop(Stk));
        Pop(Stk);
    }
    printf("\n");

    getch();
}