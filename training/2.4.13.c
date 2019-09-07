#include<stdlib.h>
#include "../structure/LinearL.h"

/* =======================循环双链表的基本运算=================================*/
DLinkList InitiateLinkList()  // untest
// 初始化：建立一个空的双链表
{
    DLinkList head; // 头指针
    head = malloc(sizeof(DbNode)); // 动态构建一结点，它是头结点
    head->prior=NULL;
    head->next= NULL; 
    return head;
}

int LengthLinkList(DLinkList head)  // untest
// 求表长：求双链表head的长度
{

    DbNode *q, *p = head; // p是工作指针，初始时p指向头结点
    q=p;
    int cnt = 0;
    while(p->next!=q){ // 判断是否尾结点
        p = p->next;    // 指针移到下一个结点
        cnt++;
    }
    return cnt; // 返回表长
}

DbNode *GetDLinkList(DLinkList head, int i) // untest
// 读表元素：在双链表head中查找第i个元素结点。若找到，则返回指向该结点的指针；否则返回 NULL
{
    DbNode *q, *p;    // p是工作指针
    q=head;
    p=head->next; //初始时，p指向首结点
    int c=1;
    while((c<i) && (p!=q)){ // 当未到第i结点且未到尾结点时继续后移
        p=p->next;
        c++;
    }

    if (i==c) return p; // 找到第i个结点
    else return NULL; // i<1 或 i>n，i值不合法，查找失败
}

int LocateLinkList(DLinkList head, DataType x) // untest
// 定位：求双链表head中第一个值等于x的结点的序号，若不存在这种结点，返回结果为0
{
    DbNode *q, *p=head;   //p工作指针
    q=head;
    p=p->next; // 初始时指向首结点
    int i=0; // i代表结点序号，这里置初值为0
    while (p!=q && p->data!=x) // 访问链表
    {
        i++;
        p=p->next;
    }

    if(p!=NULL) return i+1;
    else return 0;
}

void InsertLinkList(DLinkList head, DataType x, int i)
//插入：在表head的第i个数据结点之前插入一个以x为值的新结点
{
    DbNode *p, *q;
    if (i==1) {q=head;}
    else{q=GetDLinkList(head, i-1);} // 找到第i-1个元素 (前驱结点)

    if (q==NULL) {exit("找不到插入的位置");}
    else{
        p=malloc(sizeof(DbNode));
        p->data=x; //生成新结点

        q->next->prior = p; // 前驱结点.next.prior=新结点
        p->next = q->next; // 新结点.next = 前驱结点.next
        p->prior = q; // 新结点.prior=前驱结点
        q->next = p; // 前驱结点.next=新结点

        

        p->next=q->next; // 新结点链域指向 *q的后继结点
        q->next=p; // 修改*q的链域
    }
}

void DeleteDLinkList(DLinkList head, int i)  // untest
//删除：删除表中第i个结点
{
    DbNode *q, *p;   // 
    if(i==1){q=head;}
    else{q=GetDLinkList(head, i-1);} // 先找待删除结点的直接前驱

    if (q!=NULL && q->next!=NULL){  // 若直接前驱和待删除的节点都存在
        p=q->next;  //p指向待删除结点
        q->next = p->next; // 前驱.next = 待删除.next
        p->next->prior = p->prior; // 待删除后驱.prior = 待删除.prior
        free(p); //释放已移出结点p的空间
    }else{
        exit("找不到要删除的结点");  //结点不存在
    }
}