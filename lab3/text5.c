#include<stdio.h>
#define MAX 9999999999999
void main()
{
    int htoi(char x[]);
    int c, i, flag, FLAG;
    char y[MAX];
    i = 0; 
    flag = 0;
    FLAG = 1;
    printf("\n输入一个十六进制数字:");
    while ((c = getchar() )!= '\0'&&i < MAX && FLAG)
    { 
        if (c >= '0' && c <= '9' || c >= 'a' && c <= 'f' || c >= 'A' && c <= 'F')
        {
            flag = 1;
            y[i++] = c;
        }
        else if (flag)
        {
            y[i] = '\0';
            printf("十进制表达: %d\n", htoi(y));
            printf("是否继续?(Y/N)");
            c = getchar();
            if (c == 'N' || c == 'n')
                FLAG = 0;
            else if (c == 'Y' || c == 'y')
            {
                flag = 0;
                i = 0;
                printf("\n输入一个十六进制数字:");
            }
            else
            {
                printf("\n请输入Y/N！");
            }
           
        }
        else
        {
            printf("请输入合法数字！");
            return 0;
        }

    }
}
int htoi(char x[])
{
    int i, n;
    n = 0;
    for (i = 0; x[i] != '\0'; i++)
    {
        if(x[i] >= '0' && x[i] <= '9')
            n = n * 16 + x[i] - '0';
        if (x[i] >= 'a' && x[i] <= 'f')
            n = n * 16 + x[i] - 'a' + 10;
        if (x[i] >= 'A' && x[i] <= 'F')
            n = n * 16 + x[i] - 'A' + 10;
    }
    return (n);
}