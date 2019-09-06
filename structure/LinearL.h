/* 定义表数据元素结构 
typedef struct
{
    int num;    // 学号
    char name[8];   // 姓名
    char sex[2];    // 性别
    int age;    // 年龄
    int score;    // 入学成绩
} DataType; // 定义结点的类型
*/
typedef int DataType; //用int代替 DataType 结构型，不然结构变量不能使用 != 或 == 操作符判断

/* 顺序表 */
const int Maxsize = 7;
typedef struct 
{
    /* data */
    DataType data[7];  // 存放数据的数组
    int length;  // 顺序表的实际长度
} SeqList;  // 顺序表名字为 SeqList
// SeqList student;  // student为顺序表的名称



/* 单链表 */
typedef struct node
{
    DataType data;    // 数据域
    struct node * next; // 指针域
}Node, *LinkList;
// LinkList head;    // head为头指针



/* 双链表(双向循环链表) */
typedef struct dbnode
{
    DataType data; // 数据域
    struct dbnode *prior; // 指向上一个双链表对象的指针域
    struct dbnode *next; // 指向下一个双链表对象的指针域
}DbNode, *DLinkList;