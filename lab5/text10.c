#include <stdio.h>
#include <ctype.h>
char buf[100];
int buffer = 0;
int getch(void)
{
    return (buffer > 0) ? buf[--buffer] : getchar();
}
void ungetch(int c)
{
    if (buffer >= 100)
        printf("TOO MANY NUMBERS");
    else
        buf[buffer++] = c;
}
int getfloat(float *p)
{
    int c, sign;
    float i;
    while (isspace(c = getch())&&c!='\n')
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
    {
        _ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    int flag = 0;
    for (*p = 0.0, i = 1; isdigit(c) || c == '.'; c = getch())
    {
        if (c == '.')
            flag = 1;
        else if (flag == 1)
        {
            i *= 0.1;
            *p = *p + (c - '0') * i;
        }
        else if (isdigit(c))
            *p = 10.0 * *p + (c - '0');
    }
    *p *= sign;
    if (c != '\n')
        ungetch(c);
    else
    {
        ungetch(c);
    }
    
    return *p;
}
int main()
{
    float a[100];
    int n = 0;
    float sum = 0;
    for (int i = 0; i < 100; i++)
    {
        getfloat(&a[i]);
        if (a[i] != '\0')
        {
            n++;
            sum = sum + a[i];
        }
        else
        {
            break;
        }
    }
    printf("%g\n", sum);
}