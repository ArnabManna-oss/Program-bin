#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *link;
}N;
N *f=NULL; //declare the list front pointer

N *getnode() //allocating the space for nodes
{
	N *n=(N*)malloc(sizeof(N));
	n->data=0;
	n->link=NULL;
	return n;
}

void Insert(int x)// insert in reverse order
{
	N *n,*a;
	n=getnode();	
	n->data=x;
	a=f;
	if(f==NULL)
	{
		f=n;
	}
	else
	{	
		while(a->link!=NULL)			
		{
			a=a->link;
		}
		a->link=n;
	}
}

void display()//display
{
	N *x;
	x=f;
	if(x==NULL)
	{
		printf("empty\n");
	}
	else
	{
		while(x!=NULL)
		{
			printf("%d\n",x->data);
			x=x->link;
		}
	}
}

void swap(int *a,int *b)//swap two pointer data
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void swapPair()// 
{
	N *temp=f;
	while(temp!=NULL && temp->link!=NULL)
	{
		swap(&temp->data,&temp->link->data);
		temp=temp->link->link;
	}
}

int main()
{
	int i=1,n,ch;
	while(1)
	{	
		printf("enter 1 to input data:");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("Enter the data no (%d) :",i);
			scanf("%d",&n);
			Insert(n);
		}

		else
		{	

			display();
			printf("swap");
			swapPair();
			printf("new    ..\n");
			display();
			break;
		}
		i++;
	}
	printf("\ncode ends");
	return 0;
}	
	































		
