#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void main()
{
	char c, d, keywords[100][50] = {"void", "main", "char", "int", "file", "while", "printf", "if", "else"}, buffer[100], operators[] = {'+', '-', '*', '/', '%'};
	int i, j = 0, flag = 0, k, indi;
	FILE *fp1 = fopen("inputprogram.c", "r");
	c = fgetc(fp1);
	while (c != EOF)
	{
		if (c == '#')
		{
			while (c != '\n')
			{
				buffer[j] = c;
				j++;
				c = fgetc(fp1);
			}
			buffer[j] = '\0';
			j = 0;
			printf("%s is a header", buffer);
			c = fgetc(fp1);
		}
		for (i = 0; i <= 5; i++)
		{
			if (c == operators[i])
			{
				printf("\n %c is an operator", c);
				j = 0;
				continue;
			}
		}
		if (isalnum(c))
		{
			buffer[j] = c;
			j++;
		}
		if (c == '"')
		{
			c = fgetc(fp1);
			while (c != '"')
			{
				c = fgetc(fp1);
			}
			c = fgetc(fp1);
		}
		else if (c == ' ' || c == '\n' || c == ',' || c == '(')
		{
			buffer[j] = '\0';
			for (k = 0; k < 9; k++)
			{
				if (strcmp(buffer, keywords[k]) == 0)
				{
					printf("\n %s is a keyword", buffer);
					flag = 1;
				}
			}
			if ((flag == 0) && (strcmp(buffer, " ") != 0) && (strcmp(buffer, "\0") != 0))
			{
				printf("\n %s is an identifier", buffer);
			}
			flag = 0;
			j = 0;
		}
		c = fgetc(fp1);
	}
	printf("\n");
}
