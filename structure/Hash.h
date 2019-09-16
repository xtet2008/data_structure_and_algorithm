#include<stdlib.h>
#include<stdio.h>

//散列表的基本操作算法

//链地址散列表 (每个地址指向一个链表)
typedef int KeyType;
typedef struct TagNode{
    KeyType key; //关键字
    // other fields //其他域
    struct TagNode *next;
}*Pointer, Node;
#define length 20 //定义链表长度
typedef Pointer LinkHash[length]; //代表着数组 LinkHash[i]中的任意元素i，都是一个 Pointer类型的结构体，并含有 key和next元素(域 )

//计算散列地址
#define hash_mod 13 //定义散列计算值
int Hash(KeyType key){
    return key % hash_mod; //求余函数 (生成一个 0~hash_mod区间的数)
}

//散列表查找
Pointer SearchLinkHash(KeyType key, LinkHash HP)
// 在散列表HP中查找键值等于key的结点，成功时返回指向该结点的指针，不成功时返回空指针
{
    int i=Hash(key); //计算key的散列地址
    Pointer p=HP[i]; //同义词子表，表头指针传给p
    if(p == NULL){return NULL;}

    while(p!=NULL && p->key!=key){
        p=p->next; //未达同义词子表表尾且未找到时，继续扫描
    }

    return p;
}

//散列表插入
void InsertLinkHash(KeyType key, LinkHash HP){
    if (SearchLinkHash(key, HP) == NULL){
        int i = Hash(key);
        Pointer q = (Pointer) malloc(sizeof(Node));
        q->key = key;
        q->next = HP[i]; //生成新结点
        HP[i] = q; //前插法插入新结点
    }
}

//创建散列表 (根据数组插入创建)
void CreateLinkHash(LinkHash HP, int arr[], int arr_len)
{
    for(int i =0; i<length; i++) { HP[i] = NULL;} //初始化HP散列表
    for(int i = 0; i < arr_len; i++){ InsertLinkHash(arr[i], HP);} //往散列表里插入数据
}

//删除散列表
void DeleteLinkHash(KeyType key, LinkHash HP)
//或散列表HP中存在键值为key的结点，则将其删除
{
    int i = Hash(key);
    if(HP[i] == NULL) {
        return ; // 同义词子表为空则返回
    } 
    else{
        Pointer p = HP[i];
        if(p->key == key){ //待删除结点位于子表表首
            HP[i] = p->next;
            free(p);
            return ;
        }else{
            while(p->next !=NULL){
                Pointer q=p;
                p=p->next;
                if(p->key==key){
                    q->next = p->next;
                    free(p);
                    return ;
                }
            }
        }
    }
}

void PrintLinkHash(LinkHash HP){
    printf("\nprint for link hash start ------------------");

    for(int i=0; i<length; i++){
        Pointer p = HP[i];
        if(p != NULL){
            printf("\nhash key %d: ", i);
            printf("%d", p->key);
            p = p->next;

            while(p!=NULL){
                printf(" -> %d", p->key);
                p = p->next;
            }
        }
    }

    printf("\nprint for link hash ending ------------------");
}