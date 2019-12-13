#include<stdio.h>
void reverse(char *s);
int main()
{   
    char *s = (char *)malloc(100);
	gets(s);
	reverse(s);
	return 0;
}
void reverse(char *s)
{
	char line =*s;
	if(line)
    {
		reverse(++s);
		printf("%c",line);
	}
}