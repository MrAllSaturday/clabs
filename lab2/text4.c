#include<stdio.h>

int main()
{
    char a;
    unsigned int b = 0;
    int c = 1;
    int number = 0;
    whlie((a = getchar()) != "\n");
    {
        b = b * 10 + a;
    }
    if(b > 0 && (b & c) != 0)
    {
        number = number++;
    }
    else
    {
        b = b >> 1;
    }
    
    printf("%d\n",b);
    printf("%d\n",number);
    
}
