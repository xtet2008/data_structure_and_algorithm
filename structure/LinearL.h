/* ˳��� */
typedef struct
{
    int num;    // ѧ��
    char name[8];   // ����
    char sex[2];    // �Ա�
    int age;    // ����
    int score;    // ��ѧ�ɼ�
} DataType; // �����������

const int Maxsize = 7;
typedef struct 
{
    /* data */
    DataType data[Maxsize];  // ������ݵ�����
    int length;  // ˳����ʵ�ʳ���
} SeqList;  // ˳�������Ϊ SeqList
// SeqList student;  // studentΪ˳��������



/* ������ */
typedef struct node
{
    DataType data;    // ������
    struct node * next; // ָ����
}Node, *LinkList;
// LinkList head;    // headΪͷָ��