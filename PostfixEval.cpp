#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 100
 
int stack[MAX];
int top = -1;
 
void push(int x)
{
    stack[++top]= x;
}
 
int pop()
{
    if(top == -1)
        return -1;
    else 
    {
        return stack[top--];    
    }   
}
 
int POW(int n,int m)
{
    int i,res=1;
    for(i=1;i<=m;i++)
    {
        res=res*n;
    }
    return res;
}
int main()
{
    char exp[MAX];
    char data;
    int i,k,op1,op2,res=0;
    
    printf("\n Enter Exp. =");
    scanf("%s",exp);
    for(i=0;exp[i]!='\0';i++)
    {
        data=exp[i];
        if(isalpha(exp[i]))
        {
            printf("kaka  %c er velu dao :",data);
            scanf("%d",&k);
            push(k);
        }
        else
        {
            op2=pop();
            op1=pop();
            switch(data)
            {
                case '+':
                    res=op1+op2;
                    break;
                case '-':
                    res=op1-op2;
                    break;
                case '*':
                    res=op1*op2;
                    break;
                case '/':
                    res=op1/op2;
                    break;
                case '%':
                    res=op1%op2;
                    break;
                case '^':
                    res=POW(op1,op2);
                    break;
            }
            push(res);  
        }
    }
    printf("%d",stack[0]);
}
