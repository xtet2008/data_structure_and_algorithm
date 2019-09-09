#include<stdlib.h>
#include<stdio.h>

typedef int DataType;

/* ����������
    root
    /   \
lchild  rchild
*/
typedef struct btnode
{
    DataType data;
    struct btnode *lchild, *rchild; //ָ�����Һ��ӵ�ָ��
}*BinTree;



/* ���������� (��һ��ָ��)
   parent
     |
    root
    /   \
lchild  rchild
*/
typedef struct ttnode
{
    DataType data;
    struct ttnode *lchild, *parent, *rchild;
}*TBinTree;



/*
�����У�ר��Ϊ DataTypeΪ Bintree��д��
LkQue -> LkQueNode_A -> LkQueNode_B -> ... -> LkQueNode_X
LkQue(ͷ���) -> �׽�� ->              ... -> β���(LkQueNode_X.next=NULL)
Empty��LQ.rear==LQ.front
EnQueue��new_QueNode.next=NULL; (LQ.rear)->next = new_QueNode; LQ.rear=new_QueNode
OutQueue��pop_Queue=(LQ.front)->next;   (LQ.front)->next=pop_Queue->next;    if (pop_Queue.next==NULL){LQ.rear=LQ.front;}
GetHead��return LQ.front->next->data;
*/
typedef BinTree BtData; //ר��ΪBintree��д��
typedef struct LinkQueueNode
{
    BtData data;
    struct LinkQueueNode *next;
}LkQueNode;
typedef struct LkQueue
{
    LkQueNode *front, *rear;
}LkQue;

void InitQueue(LkQue *LQ)
//���г�ʼ��
{
    LkQueNode *temp;
    temp = (LkQueNode *)malloc(sizeof(LkQueNode)); //���ɶ��е�headͷ���
    LQ->front=temp; //����ͷָ��ָ�����ͷ���
    LQ->rear=temp; //����βָ��ָ�����β���
    (LQ->front)->next=NULL;  //�൱�� temp->next=NULL
}

int EmptyQueue(LkQue LQ)
//�ж϶����Ƿ�Ϊ��
{
    if(LQ.rear==LQ.front){
        return 1; //����Ϊ��
    }else{
        return 0;
    }
}

void EnQueue(LkQue *LQ, BtData x)
//�����
{
    LkQueNode *temp;
    temp = (LkQueNode *)malloc(sizeof(LkQueNode));
    temp->data = x;
    temp->next = NULL;
    (LQ->rear)->next = temp; //�½������� 
    LQ->rear = temp; //���ö���β���
}

int OutQueue(LkQue *LQ)
//������
{
    LkQueNode *temp;
    if(EmptyQueue(*LQ)){
        printf("����Ϊ�գ��޷�����.\n");
        return 0;
    }else{
        temp = (LQ->front)->next; //ָ����е��׽��
        (LQ->front)->next = temp->next; //�޸�ͷ���ָ����ָ���µ��׽��
        if(temp->next==NULL){
            LQ->rear=LQ->front; //���׽��ʱ��front��rear��ָ��ͷ���
        }
        free(temp);
        return 1;
    }
}

BtData GetHead(LkQue LQ)
//ȡ������Ԫ��
{
    LkQueNode *temp;
    if(EmptyQueue(LQ)){
        return NULL;
    }else{
        temp = LQ.front->next;
        return temp->data; //�����׽��Ԫ��
    }
}

BinTree CreateTree()
//ѭ������ʽ����
{
    LkQue Q;
    InitQueue(&Q);

    // int l, r;

    int val;
    BinTree root, parent_node, new_node;
    root = (BinTree)malloc(sizeof(BinTree));
    root->data = NULL;
    root->lchild = NULL;
    root->rchild = NULL;
    EnQueue(&Q, root); //�յ��׽�������
    while(1){
        printf("\n�������²���Ľ��ֵ(����0��������)��");
        scanf("%d", &val);
        if (!val){break;}

        parent_node = GetHead(Q); //��ȡ�����
        if(parent_node->data == NULL){
            parent_node->data = val; //����������ͷ���Ļ���ֻҪ����ֵ�Ϳ����ˣ����ó�����
        }else{
            new_node = (BinTree)malloc(sizeof(BinTree));
            new_node->data = val;
            new_node->lchild = NULL;
            new_node->rchild = NULL;
            EnQueue(&Q, new_node); //���µ��ӽڵ���Ϊ������һ�������еĸ���㣨�Ա��ֲ���ṹ���룩

            if (parent_node->lchild == NULL){
                parent_node->lchild = new_node;
            }else if(parent_node->rchild == NULL){
                parent_node->rchild = new_node;
                OutQueue(&Q); 
                // ���������Ҳ�������µĽ�㣬˵����ǰ������Ѿ����ˣ�����ǰparent���ӣ��Ա�֤������һ�����ӵ���δ���루��δ�������ӵĽ����Ϊ�����
            }else{
                printf("\n��ǰ����㣺%d �Ѿ����Ҷ��к����ˣ��޷��ٲ����º��ӡ�", parent_node->data);
            }
        }
    }

    return root;
}

BinTree GetLast(BinTree bt)
//�ҵ����һ������
{return bt;}

void insert(BinTree bt, DataType val)
//�����½ڵ㣨�Ȳ�����߽ڵ㣬������Ϊ�������ұ߲��룬������Ҷ���Ϊ�գ��������ڵ���Ϊ����
{
    if (bt->data == NULL){
        bt->data = val; // ����ǿ����Ļ����򵱳� root �ڵ㸳ֵ
    }else{
        BinTree new_node = (BinTree)malloc(sizeof(BinTree));
        new_node->data = val;
        new_node->lchild = NULL;
        new_node->rchild = NULL;
        if(bt->lchild == NULL){
            bt->lchild = new_node;
        }else if(bt->rchild == NULL){
            bt->rchild = new_node;
        }else{
            printf("\n Tree has full child, can not insert now. ");
        }
    }

}

void visit(BinTree bt)
//���������洢������
{
    printf("��%d", bt->data);
}

void preorder(BinTree bt)
//���������root��left��right
{
    if(bt!=NULL){
        visit(bt);
        preorder(bt->lchild);
        preorder(bt->rchild);
    }
}

void inorder(BinTree bt)
//���������left��root��right
{
    if(bt!=NULL){
        inorder(bt->lchild);
        visit(bt);
        inorder(bt->rchild);
    }
}

void postorder(BinTree bt)
//���������left��right��root
{
    if(bt!=NULL){
        postorder(bt->lchild);
        postorder(bt->rchild);
        visit(bt);
    }
}

void levelorder(BinTree bt)
//��α��������ö��У���root.data��left.data��right.data��left��right
{
    if(bt!=NULL){
        LkQue Q;
        InitQueue(&Q);
        EnQueue(&Q, bt); //����������
        while (!EmptyQueue(Q)){
            BinTree p = GetHead(Q);
            OutQueue(&Q);
            visit(p); //���ʳ����еĽ��

            if(p->lchild!=NULL){EnQueue(&Q, p->lchild);} //���ӽ�������
            if(p->rchild!=NULL){EnQueue(&Q, p->rchild);} //�Һ��ӽ�������
        }
    }
}

int Height(BinTree bt)
//��������ĸ߶�
{
    int lh, rt; //��ʼ���������ĸ߶�Ϊ0
    if(bt==NULL){
        return 0;
    }else{
        lh=Height(bt->lchild);
        rt=Height(bt->rchild);
        return 1+(lh>rt ? lh: rt);
    }
}

