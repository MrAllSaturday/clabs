#include <stdio.h>

int count_one_bits(unsigned int value)
{
    int count = 0
    while (value)
    {
        if (1 == value%2)
        {
            count++;
        }
        value = value/2;
    }
    return count;
}

int main()
{
    int input;
    int c = 0;
    scanf("%d",&input);
    c = count_one_bits(input);
    printf("十进制整数的二进制表示中1的个数为: %d\n", c);
    return 0;
}