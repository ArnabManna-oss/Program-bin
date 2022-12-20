#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
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
    char exp[MAX],*ptr;
    char data;
    int i,k,op1,op2,res=0;
    
    printf("\n Enter Exp. =");
    scanf("%s",exp);
    ptr=strrev(exp);
    for(i=0;ptr[i]!='\0';i++)
    {
        data=ptr[i];
        if(isalpha(exp[i]))
        {
            printf("kaka  %c er velu dao :",data);
            scanf("%d",&k);
            push(k);
        }
        else
        {
            op1=pop();
            op2=pop();
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
