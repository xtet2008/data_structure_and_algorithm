#include<stdlib.h>
#include<stdio.h>

typedef int DataType;

/* 二叉链表树
    root
    /   \
lchild  rchild
*/
typedef struct btnode
{
    DataType data;
    struct btnode *lchild, *rchild; //指向左右孩子的指针
}*BinTree;



/* 三叉链表树 (多一个指针)
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
链队列，专门为 DataType为 Bintree而写的
LkQue -> LkQueNode_A -> LkQueNode_B -> ... -> LkQueNode_X
LkQue(头结点) -> 首结点 ->              ... -> 尾结点(LkQueNode_X.next=NULL)
Empty：LQ.rear==LQ.front
EnQueue：new_QueNode.next=NULL; (LQ.rear)->next = new_QueNode; LQ.rear=new_QueNode
OutQueue：pop_Queue=(LQ.front)->next;   (LQ.front)->next=pop_Queue->next;    if (pop_Queue.next==NULL){LQ.rear=LQ.front;}
GetHead：return LQ.front->next->data;
*/
typedef BinTree BtData; //专门为Bintree而写的
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
//队列初始化
{
    LkQueNode *temp;
    temp = (LkQueNode *)malloc(sizeof(LkQueNode)); //生成队列的head头结点
    LQ->front=temp; //队列头指针指向队列头结点
    LQ->rear=temp; //队列尾指针指向队列尾结点
    (LQ->front)->next=NULL;  //相当于 temp->next=NULL
}

int EmptyQueue(LkQue LQ)
//判断队列是否为空
{
    if(LQ.rear==LQ.front){
        return 1; //队列为空
    }else{
        return 0;
    }
}

void EnQueue(LkQue *LQ, BtData x)
//入队列
{
    LkQueNode *temp;
    temp = (LkQueNode *)malloc(sizeof(LkQueNode));
    temp->data = x;
    temp->next = NULL;
    (LQ->rear)->next = temp; //新结点入队列 
    LQ->rear = temp; //重置队列尾结点
}

int OutQueue(LkQue *LQ)
//出队列
{
    LkQueNode *temp;
    if(EmptyQueue(*LQ)){
        printf("队列为空，无法出队.\n");
        return 0;
    }else{
        temp = (LQ->front)->next; //指向队列的首结点
        (LQ->front)->next = temp->next; //修改头结点指针域指向新的首结点
        if(temp->next==NULL){
            LQ->rear=LQ->front; //无首结点时，front和rear都指向头结点
        }
        free(temp);
        return 1;
    }
}

BtData GetHead(LkQue LQ)
//取队列首元素
{
    LkQueNode *temp;
    if(EmptyQueue(LQ)){
        return NULL;
    }else{
        temp = LQ.front->next;
        return temp->data; //队列首结点元素
    }
}

BinTree CreateTree()
//循环交互式建树
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
    EnQueue(&Q, root); //空的首结点先入队
    while(1){
        printf("\n请输入新插入的结点值(输入0结束程序)：");
        scanf("%d", &val);
        if (!val){break;}

        parent_node = GetHead(Q); //获取父结点
        if(parent_node->data == NULL){
            parent_node->data = val; //如果父结点是头结点的话，只要赋个值就可以了，不用出队列
        }else{
            new_node = (BinTree)malloc(sizeof(BinTree));
            new_node->data = val;
            new_node->lchild = NULL;
            new_node->rchild = NULL;
            EnQueue(&Q, new_node); //把新的子节点作为将来第一个出队列的父结点（以保持层序结构插入）

            if (parent_node->lchild == NULL){
                parent_node->lchild = new_node;
            }else if(parent_node->rchild == NULL){
                parent_node->rchild = new_node;
                OutQueue(&Q); 
                // 如果右子树也插入了新的结点，说明当前父结点已经满了，将当前parent出队，以保证将来第一个出队的是未插入（或未满）孩子的结点作为父结点
            }else{
                printf("\n当前父结点：%d 已经左右都有孩子了，无法再插入新孩子。", parent_node->data);
            }
        }
    }

    return root;
}

BinTree GetLast(BinTree bt)
//找到最后一个子树
{return bt;}

void insert(BinTree bt, DataType val)
//插入新节点（先插入左边节点，如果左边为空再往右边插入，如果左右都不为空，则插入左节点作为左孩子
{
    if (bt->data == NULL){
        bt->data = val; // 如果是空树的话，则当成 root 节点赋值
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
//访问树结点存储的数据
{
    printf("，%d", bt->data);
}

void preorder(BinTree bt)
//先序遍历：root，left，right
{
    if(bt!=NULL){
        visit(bt);
        preorder(bt->lchild);
        preorder(bt->rchild);
    }
}

void inorder(BinTree bt)
//中序遍历：left，root，right
{
    if(bt!=NULL){
        inorder(bt->lchild);
        visit(bt);
        inorder(bt->rchild);
    }
}

void postorder(BinTree bt)
//后序遍历：left，right，root
{
    if(bt!=NULL){
        postorder(bt->lchild);
        postorder(bt->rchild);
        visit(bt);
    }
}

void levelorder(BinTree bt)
//层次遍历（利用队列）：root.data，left.data，right.data，left，right
{
    if(bt!=NULL){
        LkQue Q;
        InitQueue(&Q);
        EnQueue(&Q, bt); //根结点入队列
        while (!EmptyQueue(Q)){
            BinTree p = GetHead(Q);
            OutQueue(&Q);
            visit(p); //访问出队列的结点

            if(p->lchild!=NULL){EnQueue(&Q, p->lchild);} //左孩子结点入队列
            if(p->rchild!=NULL){EnQueue(&Q, p->rchild);} //右孩子结点入队列
        }
    }
}

int Height(BinTree bt)
//求二叉树的高度
{
    int lh, rt; //初始左右子树的高度为0
    if(bt==NULL){
        return 0;
    }else{
        lh=Height(bt->lchild);
        rt=Height(bt->rchild);
        return 1+(lh>rt ? lh: rt);
    }
}

