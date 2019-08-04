digits [0-9]*
letters [a-zA-Z]
%%
"char"|"int"|"float"|"for"|"while"|"if"|"else"|"main"|"printf"	{printf("\n%s is a keyword",yytext);}
{digits} {printf("\n%s is a digit",yytext);}
#.* {printf("\n%s is a header file",yytext);}
("_")*{letters}("_"|{letters}|{digits})* {printf("\n%s is an identifier",yytext);}
"+"|"-"|"*"|"/"|"%"|"=" {printf("\n%s is an operator",yytext);}
";"	{printf("\n%s is delimiter",yytext);}
">"|"<"|">="|"<="     {printf("\n%s is a relational operator",yytext);}
" "     {printf("\n here is  a white space");}
"("|")"     {printf("\n%s is a paranthesis",yytext);}
"{"     {printf("\nblock begins");}
"}"     {printf("\nblock ends");}

(\/\/.*)|(\/\*.*.\*\/)   {printf("\n%s is comment",yytext);}
(\".*.\")   {printf("\n%s is comment",yytext);}
{letters}+"()"   {printf("\n%s is a function",yytext);}

%%
void main()
{
	FILE *fp1;
	fp1=fopen("inp.c","r");
	yyin=fp1;
	yylex();
}
