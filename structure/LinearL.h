#include<stdlib.h>
// #include "LinearL.h"
// #include "../structure/LinearL.h"

/* 定义表数据元素结构 
typedef struct
{
    int num;    // 学号
    char name[8];   // 姓名
    char sex[2];    // 性别
    int age;    // 年龄
    int score;    // 入学成绩
} DataType; // 定义结点的类型
*/
typedef int DataType; //用int代替 DataType 结构型，不然结构变量不能使用 != 或 == 操作符判断

/* 顺序表 */
const int Maxsize = 7;
typedef struct 
{
    /* data */
    DataType data[7];  // 存放数据的数组
    int length;  // 顺序表的实际长度
} SeqList;  // 顺序表名字为 SeqList
// SeqList student;  // student为顺序表的名称

/* =======================顺序表的基本运算=================================*/
void InsertSeqList(SeqList L, DataType x, int i)
// 插入：将元素 x 插入到顺序表L的第i个数据元素之前
{
    if(L.length==Maxsize) exit("表已满");   
    if(i<1 || i>L.length+1) exit("位置错");
   
    for(int j=L.length; j>=i; j--) // 将第i个及i后面的元素依次往后槽移一位
        L.data[j] = L.data[j-1];

    L.data[i-1] = x;
    L.length++;
}

void DeleteSeqList(SeqList L, int i)
// 删除：将第i个数据元素删除，后面的元素往前移
{
    if(i<1 || i>L.length) exit("位置错");

    int j;
    for(j=i; j<=L.length; j++)
        L.data[j+1] = L.data[j];

}

int LocateSeqList(SeqList L, DataType x)
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



/* 单链表 */
typedef struct node
{
    DataType data;    // 数据域
    struct node * next; // 指针域
}Node, *LinkList;
// LinkList head;    // head为头指针

/* =======================单链表的基本运算=================================*/
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

void PrintLinkList(LinkList head)
// 打印：遍历并打印逐个元素，以，隔开
{
    Node *p=head; // p是工作指针，初始时p指向头结点
    printf("head");
    while(p->next != NULL){
        p = p->next;
        printf("，%d", p->data);
    }
    printf("\n");
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
    else{q=GetLinkList(head, i-1);}  // 先找待删除结点的直接前驱

    if (q!=NULL && q->next!=NULL){  // 若直接前驱存在且待删除结点存在
        p=q->next;  //p指向待删除结点
        q->next=p->next; //移出待删除结点
        free(p); //释放已移出结点p的空间
    }else{
        exit("找不到要删除的结点");  //结点不存在
    }
}

/* =======================单链表的建表=================================*/
LinkList CreateLinkList() // O(n^2)
//通过调用 InitiateLinkList 和 InsertLinkList实现建链表算法。 假定0是输入结束标志
{
    LinkList head;
    int x, i;
    head=InitiateLinkList(); // 建立空表
    i=1; // 置插入位置初值

    printf("请输入1个数作为单链表新结点值，输入0为结束：");
    scanf("%d", &x); //读入第一个插入元素，x为整形
    while(x!=0){
        InsertLinkList(head, x, i);
        i++;
        printf("请输入1个数作为单链表新结点值，输入0为结束：");
        scanf("%d", &x);
    }

    return head;
}

LinkList CreateLinkList2() //O(n)
//用一个指针变量q指向最后一个新插入的节点，这样每次插入一个新节点用 q->next=new_node即可，省去了上面的 InsertLinkList中的查找运算
{
    LinkList head;
    Node *q, *t;
    int x;
    head=malloc(sizeof(Node)); //生成头结点
    q=head;

    printf("请输入1个数作为单链表新结点值，输入0为结束：");
    scanf("%d", &x);
    while(x!=0){
        t=malloc(sizeof(Node));t->data=x;
        q->next=t;
        q=t;
        printf("请输入1个数作为单链表新结点值，输入0为结束：");
        scanf("%d", &x);
    }
    q->next=NULL;

    return head;
}

LinkList CreateLinkList3()  // O(n)
// 前插创建：每次创建新结点插入到 head->next处（顺序与前面两个插入相反）
{
    LinkList head;
    Node *p;
    int x;
    head=malloc(sizeof(Node)); // 生成头结点
    head->next=NULL;

    printf("请输入1个数作为单链表新结点值，输入0为结束：");
    scanf("%d", &x);
    while(x){
        p=malloc(sizeof(Node));
        p->data=x;
        p->next=head->next; //前插：插入到链表的第一个结点处
        head->next=p;
        printf("请输入1个数作为单链表新结点值，输入0为结束：");
        scanf("%d", &x);
    }

    return head;
}

void PurgeLinkList(LinkList head)
//删除表head中多余的重复结点
{
    Node *p, *q, *r;
    q=head->next; // 初值指向首结点
    while(q!=NULL){
        p=q; // 工作指针p指向*q

        while(p->next!=NULL){
            // 当*p的后继结点存在时，将其数据域与*q数据域比较
            if(p->next->data==q->data){
                // 或*(p->next)是*q的重复结点
                r=p->next; // r指向待删除结点
                p->next=r->next; //移出结点*(p->next)，p->next指向原来*(p->next)的后继结点
                free(r);
            }else{
                p=p->next; //否则让p指向下一个结点
            }
        }

        q=q->next; //更新检查结点
    }
}



/* 双链表(双向循环链表) */
typedef struct dbnode
{
    DataType data; // 数据域
    struct dbnode *prior; // 指向上一个双链表对象的指针域
    struct dbnode *next; // 指向下一个双链表对象的指针域
}DbNode, *DLinkList;

