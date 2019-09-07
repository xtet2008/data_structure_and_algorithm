#include "Seqstack.h"

void main(void){
    SeqStk *S;
    S = malloc(sizeof(SeqStk));
    InitStack(S);
    printf("EmptyStack(S)=%d\n", EmptyStack(S));
    Push(S, 1);
    Push(S, 2);
    Push(S, 3);
    printf("Push, 1, 2, 3\n");
    printf("EmptyStack(S)=%d\n", EmptyStack(S));

    printf("Pop");
    while(!EmptyStack(S)){
        printf("£¬%d", GetTop(S));
        Pop(S);
    }
    printf("\n");
    printf("EmptyStack(S)=%d\n", EmptyStack(S));

    getch();
}
