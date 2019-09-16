#include "../structure/Hash.h"

void main(){
    int arr[11] = {26, 41, 25, 05, 07, 15, 12, 49, 51, 31, 62};
    LinkHash HP; //创建散列表 (链地址)
    CreateLinkHash(HP, arr, 11);
    PrintLinkHash(HP);

    DeleteLinkHash(12, HP);
    printf("\n\nafter the value 12 deleted.");
    PrintLinkHash(HP);

    printf("\n\n");
    OpenHash HL; //创建散列表 (线性探测法)
    CreateOpenHash(HL, arr, 11);
    PrintOpenHash(HL);

    getch();
}