#include<stdlib.h>
#include<stdio.h>

/*静态查找表
*/

//顺序表上的查找
#define Maxsize 20 //静态查找表的长度
typedef int KeyType;
typedef struct{
    KeyType key; //关键字
    // other fields
} TableElem;
typedef struct{
    TableElem elem[Maxsize+1];
    int n; //最后一个数据元素的下标
}SqTable;
/*
数据存放在 1 to n
n+1 至 Maxsize为备用区(空闲区)
0，用于设置 岗哨
*/


//无序表查找（遍历查找）
int SearchSqTable(SqTable T, KeyType key)
// 在顺序表T中，从后往前查找键值为key的数据元素，若找到，则返回该元素在T中的位置，否则返回0，代表查找不到
{
    T.elem[0].key = key; //设置岗哨
    int i = T.n; //设置比较位置初值
    while(T.elem[i].key!=key){i--;} //未找到时，修改比较位置继续查找

    return i;
}

//有序表查找（假设事先已排好序，采用二分查找），默认情况下都当是升序排列
int SearchBin(SqTable T, KeyType key){
    int low=1; 
    int high=T.n; //初始化区间值

    while(low<=high){
        int mid = (low + high)/2; //查找中间位
        if (key == T.elem[mid].key){
            return mid; //找着了
        }else if(key < T.elem[mid].key){
            high = mid-1; //如果待查找的值小于当前中间值，则说明在区间的左边，需要调整 high为边界值
        }else if(key > T.elem[mid].key){
            low = mid+1; //如果待查找的值大于当前中间值，则说明应该在区间的右边查找，需要调整到 low为起始边界值
        }
    }

    return 0; //查找不成功返回0
}


// 二叉排序树 left<parent<right
typedef struct btnode
{
    KeyType key;
    struct btnode *lchild, *rchild; //指向左右孩子的指针
}BSTNode, *BinTree; //BinTree为指向二叉链表结点的指针类型

//动态创建二叉排序树 (左 <父 <右)
BinTree CreateBinTree(){
    BinTree T = malloc(sizeof(BinTree));
    T->key = NULL;
    T->lchild = NULL;
    T->rchild = NULL;

    int val;
    while(1){
        printf("\nPls type a number as node value in tree，type 0 to exit the input：");
        fflush(stdin);
        scanf("%d", &val);

        if(val==0){
            break;
        }else{
            if(T->key == NULL){
                T->key = val;
            }else{
                int deep_node_found =0;
                BinTree node = T;
                while(!deep_node_found){
                    if (node->lchild != NULL){ //左边不为空
                        if (val < node->key){ // 小于 parent_node.key 值
                            node = node->lchild; //往左边延伸找到合适的节点插入
                        }else{ //相当于 > parent_node.key 值 （暂不考虑等于情况)
                            if (node->rchild != NULL){
                                node = node->rchild; //往右边延伸找
                            }else{
                                deep_node_found = 1; //如果右边结点为NULL，说明右边没有子树了，没必要再循环找下去
                            }
                        }
                    }else if((node->rchild != NULL)){ //左边为空，并且右边不为空
                        node = node->rchild;                        
                    }else{ //左右都为空
                        deep_node_found =1;
                    }
                }

                if(node->key==NULL){
                    node->key = val;
                }else{
                    BinTree new_node=malloc(sizeof(BinTree));
                    new_node->key = val;
                    new_node->lchild = NULL;
                    new_node->rchild = NULL;
                    if(val < node->key){
                        node->lchild = new_node;
                    }else{
                        node->rchild = new_node;
                    }
                }                 
            }
        }
    }

    return T;
}

/*二叉排序树查找 
只需要比较某结点键大小 ，如果小于则往其左孩子递归查找，否则往其右孩子递归查找
*/
BinTree SearchBST(BinTree bst, KeyType key){
    if(bst==NULL) {
        return NULL;
    }else if(key == bst->key){
        return bst;
    }else if(key < bst->key){
        return SearchBST(bst->lchild, key); //继续在左子树中查找
    }else{
        return SearchBST(bst->rchild, key); //继续在右子树中查找
    }
}
