#include<stdlib.h>
#include "LinearL.h"
// #include "../structure/LinearL.h"

/* ˳���Ļ������� */
void InsertSeqList(SeqList L, DataType x, int i)
// ���룺��Ԫ�� x ���뵽˳���L�ĵ�i������Ԫ��֮ǰ
{
    if(L.length==Maxsize) exit("������");   
    if(i<1 || i>L.length+1) exit("λ�ô�");

    int j;
    L.length++;
    for(j=L.length; j>=i; j--)
        L.data[j] = L.data[j-1];
    L.data[i] = x;
}

void DeleteSeqList(SeqList L, int i)
// ɾ��������i������Ԫ��ɾ���������Ԫ����ǰ��
{
    if(i<1 || i>L.length) exit("λ�ô�");

    int j;
    for(j=i; j<=L.length; j++)
        L.data[j+1] = L.data[j];

}

void LocateSeqList(SeqList L, DataType x)
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



/* ������Ļ������� */
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
    else{q=GetLinkList(head, i-1);}

    if (q!=NULL && q->next!=NULL){
        p=q->next;  //pָ���ɾ�����
        q->next=p->next; //�Ƴ���ɾ�����
        free(p); //�ͷ����Ƴ����p�Ŀռ�
    }else{
        exit("�Ҳ���Ҫɾ���Ľ��");  //��㲻����
    }
}