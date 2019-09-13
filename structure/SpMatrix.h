/*
稀疏矩阵，三元组的存储结构
i,j,v
第i行，第j列的值为v
*/
#define maxnum 10
typedef int DataType;
typedef struct node
{
    int i,j; //非零元所有的行号，列号
    DataType v; //非零元的值
} NODE;

typedef struct SpMatrix
{
    int mu, nu, tu; //行数，列数，非零元素的个数
    NODE data[maxnum]; //假定三元组的下标的起始值为0
} SpMtx;


void Matrix_to_SpMtx(DataType mat[][10], int m, SpMtx *a)
//将二维稀疏矩阵转换为三元组的表现形式
{
    int n=10; //假定待转换的稀疏矩阵每行有10个元素
    int q=0; //记录非零的元素的个数
    
    for(int i=0; i<m; i++){ //先遍历每行
        for(int j=0; j<n; j++){ //遍历每列（相当于i行，j列的某个元素）
            if(mat[i][j] != 0){
                (*a).data[q].i = i;
                (*a).data[q].j = j;
                (*a).data[q].v = mat[i][j];
                q++;
            }
        }
    }

    (*a).mu = m; // 三元组.行数
    (*a).nu = n; // 三元组.列数
    (*a).tu = q; // 三元组.非零元素个数
}