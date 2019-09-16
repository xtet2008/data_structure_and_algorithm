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
typedef Pointer LinkHash[length]; //代表着数组 LinkHash[i]中的任意元素i，都是一个 Pointer指针类型的结构体，并含有 key和next元素(域 )

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



//线性探测法散列表 (如果key存在，则key++，直到后面的元素槽为空为止)
typedef struct{
    KeyType key; //键值域
    //other fields //其他域
}*Element;
typedef Element OpenHash[length]; //代表着数组 OpenHash[i]中的任意元素i，都是一个 Element指针类型的结构体，并含有 key元素(域 )

int SearchOpenHash(KeyType key, OpenHash HL)
// 在散列表HL中查找键值为 key的结点，成功时返回该位置，不成功时返回标志0，假定以线性探测法解决冲突
{
    int d = Hash(key); //计算散列地址
    int i = d;
    int slot_used = 1;
    while(slot_used<length && HL[i]!= NULL && HL[i]->key != key){
        slot_used ++; //用来记录找了多少个槽了，防止槽满了，死循环永无止境的找
        i = (i+1) % hash_mod; //继续往后面循环找槽（到底后，又会重新从槽的开始位置找）
    }

    if(HL[i]==NULL || HL[i]->key == key){
        return i; //查找成功
    }else{
        return -1; //查找失败
    }
}

//创建散列表 (根据线性探测法，如果key对应的插槽用过了，则往后插槽偏移寻找空余的槽)
void CreateOpenHash(OpenHash HL, int arr[], int arr_len)
{
    for(int i =0; i<length; i++) { HL[i] = NULL;} //初始化HP散列表
    for(int i = 0; i < arr_len; i++){ 
        //往散列表里插入数据
        int slot_index = SearchOpenHash(arr[i], HL);
        if(slot_index >= 0){
            Element el = (Element *)malloc(sizeof(Element));
            el->key = arr[i];
            HL[slot_index] = el;
        }
    }
}

//打印线性散列表
void PrintOpenHash(OpenHash HL){
    printf("\nprint for open hash start ------------------");

    for(int i=0; i<length; i++){
        Element el = HL[i];
        if(el != NULL){
            printf("\nhash key %d: %d", i, el->key);
        }
    }

    printf("\nprint for open hash ending ------------------");
}