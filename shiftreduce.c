#include<stdio.h>
#include<string.h>
int top=0;
int i=0;
char input[50];
char lasth[6];
char stack[50];
char handles[][4]={"E*E","E+E","i","E^E"};
char precedence[4][4]={
					/* +   *  i    $*/
				/* + */ '>','<','<','>',
				/* * */ '>','>','<','>',
				/* i */ '>','>','e','>',
				/* $ */ '<','<','<','>'
				};
int gindex(char c)
{
switch(c)
	{
		case '+':return 0;
		case '*':return 1;
		case 'i':return 2;
		case '$':return 3;
	}
}
void shift()
{
	stack[++top]=input[i++];
	stack[top+1]='\0';
}
int reduce()
{
	int match=0;
	int j=0;
	int i=0;
	for(i=0;i<4;i++)
	{
		if(stack[top]==handles[i][0]&&(top+1)>=strlen(handles[i]))
		{
			match=1;
			for(j=0;j<strlen(handles[i]);j++)
			{
				if(stack[top-j]!=handles[i][j])
				{
					match=0;
					break;
				}
			}
			if(match)
			{
				stack[top-j+1]='E';
				top=top-j+1;
				strcpy(lasth,handles[i]);
				stack[top+1]='\0';
				return 1;
			}
		}
	}
}
void main()
{
	printf("\nenter string : ");
	scanf("%s",input);
	strcat(input,"$");
	strcpy(stack,"$");
	int i=0;
	while(i<=strlen(input))
	{
		shift();
		if(precedence[gindex(stack[top])][gindex(input[i])]=='>')
		{
			while(reduce())
			{
			printf("\n");
			printf("\t");
			printf("Reduced: E->%s",lasth);
			}
		}
	}
	printf("accepted");
}

	
	
	
	
	
	

