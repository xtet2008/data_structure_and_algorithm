/* ���������Ԫ�ؽṹ 
typedef struct
{
    int num;    // ѧ��
    char name[8];   // ����
    char sex[2];    // �Ա�
    int age;    // ����
    int score;    // ��ѧ�ɼ�
} DataType; // �����������
*/
typedef int DataType; //��int���� DataType �ṹ�ͣ���Ȼ�ṹ��������ʹ�� != �� == �������ж�

/* ˳��� */
const int Maxsize = 7;
typedef struct 
{
    /* data */
    DataType data[7];  // ������ݵ�����
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



/* ˫����(˫��ѭ������) */
typedef struct dbnode
{
    DataType data; // ������
    struct dbnode *prior; // ָ����һ��˫��������ָ����
    struct dbnode *next; // ָ����һ��˫��������ָ����
}DbNode, *DLinkList;