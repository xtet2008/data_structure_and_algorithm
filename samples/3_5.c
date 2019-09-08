#include<stdlib.h>
#include "../structure/Lkstack.h"

//��������ת (����ջʵ��һ������Ч��)
void ReverseList(LkStk *head ){
    LkStk *S;
    InitStack(S); //��ʼ����ջ
    if(!EmptyStack(S)){S->next=NULL;} // ����NULLֵ�󣬱�Ӧ����0x00����ִ���� InitStack���������ص������ ->next ����仯
    
    LkStk *p=head->next; 
    while(p!=NULL){
        Push(S, p->data); //Ԫ�ؽ�ջ
        p=p->next; //ɨ������
    }

    p=head->next; 
    while (!EmptyStack(S)){
        p->data=GetTop(S); //ȡ��Sջ�е�Ԫ�ز����뵥������
        Pop(S);
        p=p->next;
    }
}

void main(){
    LkStk *Stk;
    InitStack(Stk); 
    if(!EmptyStack(Stk)){Stk->next=NULL;}  //TODO: ����NULLֵ�󣬱�Ӧ����0x00����ִ���� InitStack���������ص������ ->next ����仯

    printf("Stack Push");
    for(int i=0; i<10; i++){
        printf("��%d", i);
        Push(Stk, i);
    }

    ReverseList(Stk); //TODO:ִ�к�������֪Ϊɶ��������ִ����

    printf("\nStack Pop");
    while(!EmptyStack(Stk)){
        printf("��%d", GetTop(Stk));
        Pop(Stk);
    }
    printf("\n");

    getch();
}