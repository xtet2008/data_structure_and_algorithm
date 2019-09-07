#include<stdlib.h>
#include "../structure/Seqstack.h"

main(){
    SeqStk stk;
    int i;
    char ch;

    InitStack(&stk);
    printf("Push£º");
    for(ch='A'; ch<='A'+10; ch++){
        Push(&stk, ch);
        printf("%c", ch);
    }
    printf("\n");

    printf("Pop£º");
    while(!EmptyStack(&stk)){
        ch=GetTop(&stk);
        Pop(&stk);
        printf("%c", ch);
    }
    printf("\n");

    getch();
}