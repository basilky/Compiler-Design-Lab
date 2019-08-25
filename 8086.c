#include<stdio.h>
char* getop(char c)
{
    switch(c)
    {
        case '+':return "ADD";
        case '-':return "SUB";
        case '*':return "MUL";
        case '/':return "DIV";
    }
}
void main()
{
    FILE *fp;
    char op1,op2,var,opr;
    fp=fopen("3add2.txt","r");
    int i=0;
    while(fscanf(fp,"%c=%c%c%c\n",&var,&op1,&opr,&op2)!=EOF)
    {
        printf("\nMOV %c R%d",op1,i);
        printf("\n%s %c R%d",getop(opr),op2,i);
        printf("\nMOV R%d %c",i++,var);
    }
    printf("\n");
}