#include<stdlib.h>
#include<stdio.h>

//ɢ�б�Ļ��������㷨

//����ַɢ�б� (ÿ����ַָ��һ������)
typedef int KeyType;
typedef struct TagNode{
    KeyType key; //�ؼ���
    // other fields //������
    struct TagNode *next;
}*Pointer, Node;
#define length 20 //����������
typedef Pointer LinkHash[length]; //���������� LinkHash[i]�е�����Ԫ��i������һ�� Pointer���͵Ľṹ�壬������ key��nextԪ��(�� )

//����ɢ�е�ַ
#define hash_mod 13 //����ɢ�м���ֵ
int Hash(KeyType key){
    return key % hash_mod; //���ຯ�� (����һ�� 0~hash_mod�������)
}

//ɢ�б����
Pointer SearchLinkHash(KeyType key, LinkHash HP)
// ��ɢ�б�HP�в��Ҽ�ֵ����key�Ľ�㣬�ɹ�ʱ����ָ��ý���ָ�룬���ɹ�ʱ���ؿ�ָ��
{
    int i=Hash(key); //����key��ɢ�е�ַ
    Pointer p=HP[i]; //ͬ����ӱ���ͷָ�봫��p
    if(p == NULL){return NULL;}

    while(p!=NULL && p->key!=key){
        p=p->next; //δ��ͬ����ӱ��β��δ�ҵ�ʱ������ɨ��
    }

    return p;
}

//ɢ�б����
void InsertLinkHash(KeyType key, LinkHash HP){
    if (SearchLinkHash(key, HP) == NULL){
        int i = Hash(key);
        Pointer q = (Pointer) malloc(sizeof(Node));
        q->key = key;
        q->next = HP[i]; //�����½��
        HP[i] = q; //ǰ�巨�����½��
    }
}

//����ɢ�б� (����������봴��)
void CreateLinkHash(LinkHash HP, int arr[], int arr_len)
{
    for(int i =0; i<length; i++) { HP[i] = NULL;} //��ʼ��HPɢ�б�
    for(int i = 0; i < arr_len; i++){ InsertLinkHash(arr[i], HP);} //��ɢ�б����������
}

//ɾ��ɢ�б�
void DeleteLinkHash(KeyType key, LinkHash HP)
//��ɢ�б�HP�д��ڼ�ֵΪkey�Ľ�㣬����ɾ��
{
    int i = Hash(key);
    if(HP[i] == NULL) {
        return ; // ͬ����ӱ�Ϊ���򷵻�
    } 
    else{
        Pointer p = HP[i];
        if(p->key == key){ //��ɾ�����λ���ӱ����
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