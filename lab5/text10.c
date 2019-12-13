#include <ctype.h>
#include <stdio.h>
#define NUMBER '0'
int getch(vold);
void ungetch(int);
int getfloat(float *pn)
{
    int c,sign;
    while (isspace(c=getch()));
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        return 0;
    }
    sign = (c == '-')? -1 : 1;
    if (c == '+'||c == '-')
    c = getch();
    for (*pn = 0;isdigit(c);c = getch())
    *pn *= sign;
    if (c != EOF)
    ungetch(c);
    return c;
}
int getop(char s[])
{
    int i,c;
    while ((s[0] = c = getch())==' '|| c == '\t');
    s[1] = '\0';
    if (isdigit(c))
    while (isdigit (s[++i] = c = getch()));
    if (c == '.')
    while (isdigit(s[++i] = c = getch()));
    s[i]='\0';
    if (c != EOF)
    ungetch(c);
    return NUMBER;
    printf("%e\n",c);
}