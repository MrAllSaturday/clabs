#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define NUMBER '0'
#define MAXOP 100
int getop(char s[]);
void push(double);
double pop(void);
char s[MAXOP];
main(int argc,char *argv[])
{
    int type;
    double op;
    int i = 1;
    int a = argc;
    while((argc--)>0 && i<a)
    {
    type = getop(argv[i++]);
        switch (type)
        {
        case NUMBER:
            push(atof(argv[i-1]));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op = pop();
            push(pop() - op);
            break;
        case '/':
            op = pop();
            if (op != 0.0)
                push(pop() / op);
            else
                printf("zero warning\n");
            break;
        default:
            printf("unknown command %s\n", s);
            argc=1;
            break;
        }
    }
    printf("\t%.2g\n",pop());
    return 0;
}
#define MAXVAL 100
int p = 0;
double val[MAXVAL];
void push(double f)
{
    if (p < MAXVAL)
        val[p++] = f;
    else
    {
        printf("stack is full %g\n", f);
    }
}
double pop(void)
{
    if (p > 0)
        return val[--p];
    else
    {
        printf("stack is empty \n");
        return 0.0;
    }
}

int getop(char s[])
{
    if (*s> '9' || *s < '0')
        return *s;
    else
        return NUMBER;       
}