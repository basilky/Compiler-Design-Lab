#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char s[50];
void main()
{
	char temp='A';
	printf("\nenter expression : ");
	scanf("%s",s);
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]=='/')
		{
			printf("\n%c = %c %c %c",temp,s[i-1],s[i],s[i+1]);
			s[i-1]=temp++;
			int j=i;
			for(;s[j]!='\0';j++)
			{
				s[j]=s[j+1];
			}
			j=i;
			for(;s[j]!='\0';j++)
			{
				s[j]=s[j+1];
			}
			s[j]='\0';
		//	printf("\n%s",s);
		}
	}
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]=='*')
		{
			printf("\n%c = %c %c %c",temp,s[i-1],s[i],s[i+1]);
			s[i-1]=temp++;
			int j=i;
			for(;s[j]!='\0';j++)
			{
				s[j]=s[j+1];
			}
			j=i;
			for(;s[j]!='\0';j++)
			{
				s[j]=s[j+1];
			}
			s[j]='\0';
		}
	}
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]=='+')
		{
			printf("\n%c = %c %c %c",temp,s[i-1],s[i],s[i+1]);
			s[i-1]=temp++;
			int j=i;
			for(;s[j]!='\0';j++)
			{
				s[j]=s[j+1];
			}
			j=i;
			for(;s[j]!='\0';j++)
			{
				s[j]=s[j+1];
			}
			s[j]='\0';
		}
	}
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]=='-')
		{
			printf("\n%c = %c %c %c",temp,s[i-1],s[i],s[i+1]);
			s[i-1]=temp++;
			int j=i;
			for(;s[j]!='\0';j++)
			{
				s[j]=s[j+1];
			}
			j=i;
			for(;s[j]!='\0';j++)
			{
				s[j]=s[j+1];
			}
			s[j]='\0';
		}
	}
	printf("\n");
}
