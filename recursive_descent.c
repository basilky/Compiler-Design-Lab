#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
void E();
int i=0;
char l,s[100];
void match(char c)
{
	//printf("\nc is %c l is %c",c,l);
	if(l==c)
	{
		l=s[++i];
	}
	else if(isalpha(l))
	{
		l=s[++i];
	}
	else 
	{
		printf("\nerror..!\n");
		exit(0);
	}
}
void F()
{
	//printf("\non F");
	if(l=='(')
	{
		match('(');
		E();
		match(')');
	}
	else
	{
		match('i');
	}
}
void Z()
{
	//printf("\non Z");
	if(l=='*')
	{
		match('*');
		F();
		Z();
	}
	else return;
}
void T()
{
	//printf("\non T");
	F();
	Z();
}
void A()
{
	//printf("\non A");
	if(l=='+')
	{
		match('+');
		T();
		A();
	}
	else return;
}
void E()
{
	//printf("\non E");
	T();
	A();
}

void main()
{
	printf("\nenter string : ");
	scanf("%s",s);
	strcat(s,"$");
	l=s[i];
	E();
	if(s[i]=='$')
		printf("\naccepted..!");
	else printf("\nerror..!\n");
	printf("\n");
}
	

