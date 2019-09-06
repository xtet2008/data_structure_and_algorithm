#include<stdlib.h>
#include "LinearL.h"
// #include "../structure/LinearL.h"

/* 顺序表的基本运算 */
void InsertSeqList(SeqList L, DataType x, int i)
// 插入：将元素 x 插入到顺序表L的第i个数据元素之前
{
    if(L.length==Maxsize) exit("表已满");   
    if(i<1 || i>L.length+1) exit("位置错");

    int j;
    L.length++;
    for(j=L.length; j>=i; j--)
        L.data[j] = L.data[j-1];
    L.data[i] = x;
}

void DeleteSeqList(SeqList L, int i)
// 删除：将第i个数据元素删除，后面的元素往前移
{
    if(i<1 || i>L.length) exit("位置错");

    int j;
    for(j=i; j<=L.length; j++)
        L.data[j+1] = L.data[j];

}

void LocateSeqList(SeqList L, DataType x)
// 定位：查找
{
    int i=0;
    while(i<L.length && (L.data[i]!=x))
        i++;

    if (i<L.length) 
        return i+1;
    else 
        return 0;
}



/* 单链表的基本运算 */
LinkList InitiateLinkList()
// 初始化：建立一个空的单链表
{
    LinkList head; // 头指针
    head = malloc(sizeof(Node)); // 动态构建一结构，它是头结点
    head->next = NULL; 
    return head;
}

int LengthLinkList(LinkList head)
// 求表长：求单链表head的长度
{

    Node *p = head; // p是工作指针，初始时p指向头结点
    int cnt = 0;
    while(p->next != NULL){ // 判断是否尾结点
        p = p->next;    // 指针移到下一个结点
        cnt++;
    }
    return cnt; // 返回表长
}

Node *GetLinkList(LinkList head, int i)
// 读表元素：在单链表head中查找第i个元素结点。若找到，则返回指向该结点的指针；否则返回 NULL
{
    Node *p;    // p是工作指针
    p=head->next; //初始时，p指向首结点
    int c=1;
    while((c<i) && (p!=NULL)){ // 当未到第i结点且未到尾结点时继续后移
        p=p->next;
        c++;
    }

    if (i==c) return p; // 找到第i个结点
    else return NULL; // i<1 或 i>n，i值不合法，查找失败
}

int LocateLinkList(LinkList head, DataType x)
// 定位：求表head中第一个值等于x的结点的序号，若不存在这种结点，返回结果为0
{
    Node *p=head;   //p工作指针
    p=p->next; // 初始时指向首结点
    int i=0; // i代表结点序号，这里置初值为0
    while (p!=NULL && p->data!=x) // 访问链表
    {
        i++;
        p=p->next;
    }

    if(p!=NULL) return i+1;
    else return 0;
}

void InsertLinkList(LinkList head, DataType x, int i)
//插入：在表head的第i个数据结点之前插入一个以x为值的新结点
{
    Node *p, *q;
    if (i==1) {q=head;}
    else{q=GetLinkList(head, i-1);} // 找到第i-1个元素

    if (q==NULL) {exit("找不到插入的位置");}
    else{
        p=malloc(sizeof(Node));
        p->data=x; //生成新结点
        p->next=q->next; // 新结点链域指向 *q的后继结点
        q->next=p; // 修改*q的链域
    }
}

void DeleteLinkList(LinkList head, int i)
//删除：删除表中第i个结点
{
    Node *q, *p;   // 
    if(i==1){q=head;}
    else{q=GetLinkList(head, i-1);}

    if (q!=NULL && q->next!=NULL){
        p=q->next;  //p指向待删除结点
        q->next=p->next; //移出待删除结点
        free(p); //释放已移出结点p的空间
    }else{
        exit("找不到要删除的结点");  //结点不存在
    }
}