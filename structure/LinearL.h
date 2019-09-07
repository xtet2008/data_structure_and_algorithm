#include<stdlib.h>
// #include "LinearL.h"
// #include "../structure/LinearL.h"

/* ���������Ԫ�ؽṹ 
typedef struct
{
    int num;    // ѧ��
    char name[8];   // ����
    char sex[2];    // �Ա�
    int age;    // ����
    int score;    // ��ѧ�ɼ�
} DataType; // �����������
*/
typedef int DataType; //��int���� DataType �ṹ�ͣ���Ȼ�ṹ��������ʹ�� != �� == �������ж�

/* ˳��� */
const int Maxsize = 7;
typedef struct 
{
    /* data */
    DataType data[7];  // ������ݵ�����
    int length;  // ˳����ʵ�ʳ���
} SeqList;  // ˳�������Ϊ SeqList
// SeqList student;  // studentΪ˳��������

/* =======================˳���Ļ�������=================================*/
void InsertSeqList(SeqList L, DataType x, int i)
// ���룺��Ԫ�� x ���뵽˳���L�ĵ�i������Ԫ��֮ǰ
{
    if(L.length==Maxsize) exit("������");   
    if(i<1 || i>L.length+1) exit("λ�ô�");
   
    for(int j=L.length; j>=i; j--) // ����i����i�����Ԫ�������������һλ
        L.data[j] = L.data[j-1];

    L.data[i-1] = x;
    L.length++;
}

void DeleteSeqList(SeqList L, int i)
// ɾ��������i������Ԫ��ɾ���������Ԫ����ǰ��
{
    if(i<1 || i>L.length) exit("λ�ô�");

    int j;
    for(j=i; j<=L.length; j++)
        L.data[j+1] = L.data[j];

}

int LocateSeqList(SeqList L, DataType x)
// ��λ������
{
    int i=0;
    while(i<L.length && (L.data[i]!=x))
        i++;

    if (i<L.length) 
        return i+1;
    else 
        return 0;
}



/* ������ */
typedef struct node
{
    DataType data;    // ������
    struct node * next; // ָ����
}Node, *LinkList;
// LinkList head;    // headΪͷָ��

/* =======================������Ļ�������=================================*/
LinkList InitiateLinkList()
// ��ʼ��������һ���յĵ�����
{
    LinkList head; // ͷָ��
    head = malloc(sizeof(Node)); // ��̬����һ�ṹ������ͷ���
    head->next = NULL; 
    return head;
}

int LengthLinkList(LinkList head)
// �����������head�ĳ���
{

    Node *p = head; // p�ǹ���ָ�룬��ʼʱpָ��ͷ���
    int cnt = 0;
    while(p->next != NULL){ // �ж��Ƿ�β���
        p = p->next;    // ָ���Ƶ���һ�����
        cnt++;
    }
    return cnt; // ���ر�
}

void PrintLinkList(LinkList head)
// ��ӡ����������ӡ���Ԫ�أ��ԣ�����
{
    Node *p=head; // p�ǹ���ָ�룬��ʼʱpָ��ͷ���
    printf("head");
    while(p->next != NULL){
        p = p->next;
        printf("��%d", p->data);
    }
    printf("\n");
}

Node *GetLinkList(LinkList head, int i)
// ����Ԫ�أ��ڵ�����head�в��ҵ�i��Ԫ�ؽ�㡣���ҵ����򷵻�ָ��ý���ָ�룻���򷵻� NULL
{
    Node *p;    // p�ǹ���ָ��
    p=head->next; //��ʼʱ��pָ���׽��
    int c=1;
    while((c<i) && (p!=NULL)){ // ��δ����i�����δ��β���ʱ��������
        p=p->next;
        c++;
    }

    if (i==c) return p; // �ҵ���i�����
    else return NULL; // i<1 �� i>n��iֵ���Ϸ�������ʧ��
}

int LocateLinkList(LinkList head, DataType x)
// ��λ�����head�е�һ��ֵ����x�Ľ�����ţ������������ֽ�㣬���ؽ��Ϊ0
{
    Node *p=head;   //p����ָ��
    p=p->next; // ��ʼʱָ���׽��
    int i=0; // i��������ţ������ó�ֵΪ0
    while (p!=NULL && p->data!=x) // ��������
    {
        i++;
        p=p->next;
    }

    if(p!=NULL) return i+1;
    else return 0;
}

void InsertLinkList(LinkList head, DataType x, int i)
//���룺�ڱ�head�ĵ�i�����ݽ��֮ǰ����һ����xΪֵ���½��
{
    Node *p, *q;
    if (i==1) {q=head;}
    else{q=GetLinkList(head, i-1);} // �ҵ���i-1��Ԫ��

    if (q==NULL) {exit("�Ҳ��������λ��");}
    else{
        p=malloc(sizeof(Node));
        p->data=x; //�����½��
        p->next=q->next; // �½������ָ�� *q�ĺ�̽��
        q->next=p; // �޸�*q������
    }
}

void DeleteLinkList(LinkList head, int i)
//ɾ����ɾ�����е�i�����
{
    Node *q, *p;   // 
    if(i==1){q=head;}
    else{q=GetLinkList(head, i-1);}  // ���Ҵ�ɾ������ֱ��ǰ��

    if (q!=NULL && q->next!=NULL){  // ��ֱ��ǰ�������Ҵ�ɾ��������
        p=q->next;  //pָ���ɾ�����
        q->next=p->next; //�Ƴ���ɾ�����
        free(p); //�ͷ����Ƴ����p�Ŀռ�
    }else{
        exit("�Ҳ���Ҫɾ���Ľ��");  //��㲻����
    }
}

/* =======================������Ľ���=================================*/
LinkList CreateLinkList() // O(n^2)
//ͨ������ InitiateLinkList �� InsertLinkListʵ�ֽ������㷨�� �ٶ�0�����������־
{
    LinkList head;
    int x, i;
    head=InitiateLinkList(); // �����ձ�
    i=1; // �ò���λ�ó�ֵ

    printf("������1������Ϊ�������½��ֵ������0Ϊ������");
    scanf("%d", &x); //�����һ������Ԫ�أ�xΪ����
    while(x!=0){
        InsertLinkList(head, x, i);
        i++;
        printf("������1������Ϊ�������½��ֵ������0Ϊ������");
        scanf("%d", &x);
    }

    return head;
}

LinkList CreateLinkList2() //O(n)
//��һ��ָ�����qָ�����һ���²���Ľڵ㣬����ÿ�β���һ���½ڵ��� q->next=new_node���ɣ�ʡȥ������� InsertLinkList�еĲ�������
{
    LinkList head;
    Node *q, *t;
    int x;
    head=malloc(sizeof(Node)); //����ͷ���
    q=head;

    printf("������1������Ϊ�������½��ֵ������0Ϊ������");
    scanf("%d", &x);
    while(x!=0){
        t=malloc(sizeof(Node));t->data=x;
        q->next=t;
        q=t;
        printf("������1������Ϊ�������½��ֵ������0Ϊ������");
        scanf("%d", &x);
    }
    q->next=NULL;

    return head;
}

LinkList CreateLinkList3()  // O(n)
// ǰ�崴����ÿ�δ����½����뵽 head->next����˳����ǰ�����������෴��
{
    LinkList head;
    Node *p;
    int x;
    head=malloc(sizeof(Node)); // ����ͷ���
    head->next=NULL;

    printf("������1������Ϊ�������½��ֵ������0Ϊ������");
    scanf("%d", &x);
    while(x){
        p=malloc(sizeof(Node));
        p->data=x;
        p->next=head->next; //ǰ�壺���뵽����ĵ�һ����㴦
        head->next=p;
        printf("������1������Ϊ�������½��ֵ������0Ϊ������");
        scanf("%d", &x);
    }

    return head;
}

void PurgeLinkList(LinkList head)
//ɾ����head�ж�����ظ����
{
    Node *p, *q, *r;
    q=head->next; // ��ֵָ���׽��
    while(q!=NULL){
        p=q; // ����ָ��pָ��*q

        while(p->next!=NULL){
            // ��*p�ĺ�̽�����ʱ��������������*q������Ƚ�
            if(p->next->data==q->data){
                // ��*(p->next)��*q���ظ����
                r=p->next; // rָ���ɾ�����
                p->next=r->next; //�Ƴ����*(p->next)��p->nextָ��ԭ��*(p->next)�ĺ�̽��
                free(r);
            }else{
                p=p->next; //������pָ����һ�����
            }
        }

        q=q->next; //���¼����
    }
}



/* ˫����(˫��ѭ������) */
typedef struct dbnode
{
    DataType data; // ������
    struct dbnode *prior; // ָ����һ��˫��������ָ����
    struct dbnode *next; // ָ����һ��˫��������ָ����
}DbNode, *DLinkList;

