// ���ƺ����� 1! + 2! + ... + n!

#include <stdio.h>

int fact1(int n);
int fact2(int n);

void main(void){
    int n;
    printf("������һ��ʮ������������(5)��");
    scanf("%d", &n);

    printf("��һ��O(n^2)�ķ�ʽ������Ϊ��%d\n", fact1(n));
    printf("��һ��O(n)�ķ�ʽ������Ϊ��%d\n", fact2(n));
    getch(); // �ȴ�������������˳�
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