#include "../structure/LinearL.h"

void main(void){
    //Ë³Ðò±í
    SeqList S;
    S.length = 0;
    InsertSeqList(S, 0, 1);  //todo: 
    InsertSeqList(S, 1, 1);
    InsertSeqList(S, 2, 1);
    InsertSeqList(S, 3, 1);
    InsertSeqList(S, 4, 1);
    

    //µ¥Á´±í
    LinkList L=CreateLinkList3();
    PrintLinkList(L);
    printf("%d", LengthLinkList(L));
    getch();
}
