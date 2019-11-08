#include<stdio.h>

int main()
{
    unsigned int a = 1 , b = 0;
    while(a > 0){
        a = a << 1;
        b = b + 1;   
        }
     printf("digit:%d\n",b);
     printf("%u\n",__UINT32_MAX__);
     return 0;
}
   


