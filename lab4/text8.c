#include <stdio.h>
#define MAXOP 100
#define NUMBER '0'
int getop(char[]);
void push(double d);
double pop(void);
void printtop(void);
double copy(void);
double peek(void);
int swop();
int clear();
double atof(char s[]);
int isspace(int);
int isdigit(int);
main()
{
    int type;
    double op2, op3;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            op3 = pop();
            if (op2 != (int)op2 || op3 != (int)op3)
                printf("error: Only integers can get the modulus\n");
            else if (op2 == 0)
                printf("error: zero divisor\n");
            else if (op2 < 0)
                push(0);
            else
                push((int)op3 % (int)op2);
            break;
        case '=':
            printf("\t%.8g\n", pop());
            break;
        case '.':
            printf("error: There's no number in front of the decimal point");
            break;
        case 'c':
        case 'C':
            op2 = copy();
            if (op2 != 0)
                printf("%g to be copied\n", op2);
            break;
        case 'e':
        case 'E':
            op2 = clear();
            if (op2 != 0)
                printf("The %d elements were deleted\n", (int)op2);
            break;
        case 'p':
        case 'P':
            printtop();
            break;
        case 's':
        case 'S':
            swop();
            break;
        case 'b':
        case 'B':
            op2 = pop();
            printf("%g deleted\n", op2);
            break;
        case ' ':
        case '\n':
        case '\t':
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
}
int getch(void);
void ungetch(int);
int getop(char s[])
{
    int i, c, c2;
    while ((c = getch()) == ' ' || c == '\n' || c == '\t')
        ;


    if (c == '-' || c == '+')
        if (isdigit(c2 = getch()))
        {
            s[i++] = c;
            c = c2;
        }
        else
        {
            ungetch(c2);
            return c;
        }
    if (isdigit(c))
    {
        s[0] = c;
        i = 1;
        while (isdigit(c = getch()))
            s[i++] = c;
        if (c == '.')
        {
            s[i++] = c;
            while (isdigit(c = getch()))
                s[i++] = c;
        }
        s[i] = '\0';
        if (c != '\n' && c != ' ' && c != '\t')
            ungetch(c);
        return NUMBER;
    }
    else
        return c;
}
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    if (bufp > 0)
        return buf[--bufp];
    else
        return getchar();
}
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
#define MAXVAL 100

int op = 0;
double val[MAXVAL];
void push(double d)
{
    if (op < MAXVAL)
        val[op++] = d;
    else
        printf("error: stack full, can't push %g\n", d);
}
double pop(void)
{
    if (op > 0)
        return val[--op];
    else
        printf("error: stack empty\n");
    return 0.0;
}
void printtop(void)
{
    if (op > 0)
        printf("%g\n", val[op - 1]);
    else 
        printf("error: stack empty\n");
}
double copy(void)
{   
    double n;
    if (op > 0)
    {
        push(n = val[op - 1]);
        return n;
    }
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}
double peek(void)
{
    if (op > 0)
        return val[op - 1];
    else
        printf("error: stack empty\n");
    return 0.0;
}
int swop()
{
    double t;
    if (op > 1)
    {
        t = val[op - 1];
        val[op - 1] = val[op - 2];
        val[op - 2] = t;
        return 1;
    }
    else
    {
        printf("The number of elements in the stack is insufficient\n");
        return 0;
    }
}
int clear()
{
    int n;
    if (op > 0)
    {
        n = op;
        op = 0;
        return n;
    }
    else
    {
        printf("error: stack empty\n");
        return 0;
    }
}
double atof(char s[])
{
    double power, val;
    int sign, i, sign2, j, n;
    for (i = 0; isspace(s[i]); i++);
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = val * 10 + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = val * 10 + (s[i] - '0');
        power *= 10;
    }
    if (s[i] == 'e' || s[i] == 'E')
    {
        i++;
        sign2 = (s[i] == '-') ? 1 : 0;
        if (s[i] == '-' || s[i] == '+')
            i++;
        for (n = 0; isdigit(s[i]); i++)
            n = n * 10 + (s[i] - '0');
        for (j = 0; j < n; j++)
            power = (sign2) ? (power * 10) : (power / 10);
    }
    return val * sign / power;
}
int isspace(int x)
{
    return (x == ' ' || x == '\t' || x == '\n') ? 1 : 0;
}
int isdigit(int x)
{
    return (x >= '0' && x <= '9') ? 1 : 0;
}