/*
ϡ�������Ԫ��Ĵ洢�ṹ
i,j,v
��i�У���j�е�ֵΪv
*/
#define maxnum 10
typedef int DataType;
typedef struct node
{
    int i,j; //����Ԫ���е��кţ��к�
    DataType v; //����Ԫ��ֵ
} NODE;

typedef struct SpMatrix
{
    int mu, nu, tu; //����������������Ԫ�صĸ���
    NODE data[maxnum]; //�ٶ���Ԫ����±����ʼֵΪ0
} SpMtx;


void Matrix_to_SpMtx(DataType mat[][10], int m, SpMtx *a)
//����άϡ�����ת��Ϊ��Ԫ��ı�����ʽ
{
    int n=10; //�ٶ���ת����ϡ�����ÿ����10��Ԫ��
    int q=0; //��¼�����Ԫ�صĸ���
    
    for(int i=0; i<m; i++){ //�ȱ���ÿ��
        for(int j=0; j<n; j++){ //����ÿ�У��൱��i�У�j�е�ĳ��Ԫ�أ�
            if(mat[i][j] != 0){
                (*a).data[q].i = i;
                (*a).data[q].j = j;
                (*a).data[q].v = mat[i][j];
                q++;
            }
        }
    }

    (*a).mu = m; // ��Ԫ��.����
    (*a).nu = n; // ��Ԫ��.����
    (*a).tu = q; // ��Ԫ��.����Ԫ�ظ���
}