#include<stdlib.h>
#include<stdio.h>

/*��̬���ұ�
*/

//˳����ϵĲ���
#define Maxsize 20 //��̬���ұ��ĳ���
typedef int KeyType;
typedef struct{
    KeyType key; //�ؼ���
    // other fields
} TableElem;
typedef struct{
    TableElem elem[Maxsize+1];
    int n; //���һ������Ԫ�ص��±�
}SqTable;
/*
���ݴ���� 1 to n
n+1 �� MaxsizeΪ������(������)
0���������� ����
*/


//��������ң��������ң�
int SearchSqTable(SqTable T, KeyType key)
// ��˳���T�У��Ӻ���ǰ���Ҽ�ֵΪkey������Ԫ�أ����ҵ����򷵻ظ�Ԫ����T�е�λ�ã����򷵻�0���������Ҳ���
{
    T.elem[0].key = key; //���ø���
    int i = T.n; //���ñȽ�λ�ó�ֵ
    while(T.elem[i].key!=key){i--;} //δ�ҵ�ʱ���޸ıȽ�λ�ü�������

    return i;
}

//��������ң������������ź��򣬲��ö��ֲ��ң���Ĭ������¶�������������
int SearchBin(SqTable T, KeyType key){
    int low=1; 
    int high=T.n; //��ʼ������ֵ

    while(low<=high){
        int mid = (low + high)/2; //�����м�λ
        if (key == T.elem[mid].key){
            return mid; //������
        }else if(key < T.elem[mid].key){
            high = mid-1; //��������ҵ�ֵС�ڵ�ǰ�м�ֵ����˵�����������ߣ���Ҫ���� highΪ�߽�ֵ
        }else if(key > T.elem[mid].key){
            low = mid+1; //��������ҵ�ֵ���ڵ�ǰ�м�ֵ����˵��Ӧ����������ұ߲��ң���Ҫ������ lowΪ��ʼ�߽�ֵ
        }
    }

    return 0; //���Ҳ��ɹ�����0
}


// ���������� left<parent<right
typedef struct btnode
{
    KeyType key;
    struct btnode *lchild, *rchild; //ָ�����Һ��ӵ�ָ��
}BSTNode, *BinTree; //BinTreeΪָ�������������ָ������

//��̬�������������� (�� <�� <��)
BinTree CreateBinTree(){
    BinTree T = malloc(sizeof(BinTree));
    T->key = NULL;
    T->lchild = NULL;
    T->rchild = NULL;

    int val;
    while(1){
        printf("\nPls type a number as node value in tree��type 0 to exit the input��");
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
                    if (node->lchild != NULL){ //��߲�Ϊ��
                        if (val < node->key){ // С�� parent_node.key ֵ
                            node = node->lchild; //����������ҵ����ʵĽڵ����
                        }else{ //�൱�� > parent_node.key ֵ ���ݲ����ǵ������)
                            if (node->rchild != NULL){
                                node = node->rchild; //���ұ�������
                            }else{
                                deep_node_found = 1; //����ұ߽��ΪNULL��˵���ұ�û�������ˣ�û��Ҫ��ѭ������ȥ
                            }
                        }
                    }else if((node->rchild != NULL)){ //���Ϊ�գ������ұ߲�Ϊ��
                        node = node->rchild;                        
                    }else{ //���Ҷ�Ϊ��
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

/*�������������� 
ֻ��Ҫ�Ƚ�ĳ������С �����С�����������ӵݹ���ң����������Һ��ӵݹ����
*/
BinTree SearchBST(BinTree bst, KeyType key){
    if(bst==NULL) {
        return NULL;
    }else if(key == bst->key){
        return bst;
    }else if(key < bst->key){
        return SearchBST(bst->lchild, key); //�������������в���
    }else{
        return SearchBST(bst->rchild, key); //�������������в���
    }
}