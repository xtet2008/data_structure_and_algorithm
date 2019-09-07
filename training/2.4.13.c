#include<stdlib.h>
#include "../structure/LinearL.h"

/* =======================ѭ��˫����Ļ�������=================================*/
DLinkList InitiateLinkList()  // untest
// ��ʼ��������һ���յ�˫����
{
    DLinkList head; // ͷָ��
    head = malloc(sizeof(DbNode)); // ��̬����һ��㣬����ͷ���
    head->prior=NULL;
    head->next= NULL; 
    return head;
}

int LengthLinkList(DLinkList head)  // untest
// �������˫����head�ĳ���
{

    DbNode *q, *p = head; // p�ǹ���ָ�룬��ʼʱpָ��ͷ���
    q=p;
    int cnt = 0;
    while(p->next!=q){ // �ж��Ƿ�β���
        p = p->next;    // ָ���Ƶ���һ�����
        cnt++;
    }
    return cnt; // ���ر�
}

DbNode *GetDLinkList(DLinkList head, int i) // untest
// ����Ԫ�أ���˫����head�в��ҵ�i��Ԫ�ؽ�㡣���ҵ����򷵻�ָ��ý���ָ�룻���򷵻� NULL
{
    DbNode *q, *p;    // p�ǹ���ָ��
    q=head;
    p=head->next; //��ʼʱ��pָ���׽��
    int c=1;
    while((c<i) && (p!=q)){ // ��δ����i�����δ��β���ʱ��������
        p=p->next;
        c++;
    }

    if (i==c) return p; // �ҵ���i�����
    else return NULL; // i<1 �� i>n��iֵ���Ϸ�������ʧ��
}

int LocateLinkList(DLinkList head, DataType x) // untest
// ��λ����˫����head�е�һ��ֵ����x�Ľ�����ţ������������ֽ�㣬���ؽ��Ϊ0
{
    DbNode *q, *p=head;   //p����ָ��
    q=head;
    p=p->next; // ��ʼʱָ���׽��
    int i=0; // i��������ţ������ó�ֵΪ0
    while (p!=q && p->data!=x) // ��������
    {
        i++;
        p=p->next;
    }

    if(p!=NULL) return i+1;
    else return 0;
}

void InsertLinkList(DLinkList head, DataType x, int i)
//���룺�ڱ�head�ĵ�i�����ݽ��֮ǰ����һ����xΪֵ���½��
{
    DbNode *p, *q;
    if (i==1) {q=head;}
    else{q=GetDLinkList(head, i-1);} // �ҵ���i-1��Ԫ�� (ǰ�����)

    if (q==NULL) {exit("�Ҳ��������λ��");}
    else{
        p=malloc(sizeof(DbNode));
        p->data=x; //�����½��

        q->next->prior = p; // ǰ�����.next.prior=�½��
        p->next = q->next; // �½��.next = ǰ�����.next
        p->prior = q; // �½��.prior=ǰ�����
        q->next = p; // ǰ�����.next=�½��

        

        p->next=q->next; // �½������ָ�� *q�ĺ�̽��
        q->next=p; // �޸�*q������
    }
}

void DeleteDLinkList(DLinkList head, int i)  // untest
//ɾ����ɾ�����е�i�����
{
    DbNode *q, *p;   // 
    if(i==1){q=head;}
    else{q=GetDLinkList(head, i-1);} // ���Ҵ�ɾ������ֱ��ǰ��

    if (q!=NULL && q->next!=NULL){  // ��ֱ��ǰ���ʹ�ɾ���Ľڵ㶼����
        p=q->next;  //pָ���ɾ�����
        q->next = p->next; // ǰ��.next = ��ɾ��.next
        p->next->prior = p->prior; // ��ɾ������.prior = ��ɾ��.prior
        free(p); //�ͷ����Ƴ����p�Ŀռ�
    }else{
        exit("�Ҳ���Ҫɾ���Ľ��");  //��㲻����
    }
}