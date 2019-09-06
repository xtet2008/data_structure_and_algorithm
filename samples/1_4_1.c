// 编制函数求 1! + 2! + ... + n!

#include <stdio.h>

int fact1(int n);
int fact2(int n);

void main(void){
    int n;
    printf("请输入一个十进制数，例如(5)：");
    scanf("%d", &n);

    printf("第一种O(n^2)的方式计算结果为：%d\n", fact1(n));
    printf("第一种O(n)的方式计算结果为：%d\n", fact2(n));
    getch(); // 等待按下任意键后退出
}

int fact1(int n)
{
    int i, j, temp, s;
    s = 0;
    for (i=1; i<=n; i++)
    {
        temp = 1;
        for (j=1; j<=i; j++)
            temp = temp * j;
        s = s + temp;
    }
    return s;
}

int fact2(int n)
{
    int i,j,temp,s;
    s=0; temp=1;
    for(i=1;i<=n;i++)
    {
        temp = temp*i;
        s = s+temp;
    }
    return s;
}