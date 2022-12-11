#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *llink;
	struct node *rlink;
}Node;

Node *F=NULL;
Node *R=NULL;

Node *getnode()
{
	Node *New;
	New=(Node*)malloc(sizeof(Node));
	New->data=0;
	New->llink=NULL;
	New->rlink=NULL;
	return New;
}

void InsertAtRear(int a)
{
	Node *New;
	New=getnode();
	New->data=a;
	if(F==NULL)
	{
		F=New;
		R=F;
		R->llink=F;
		F->rlink=R;
	}
	else
	{
		R->llink=New;
		New->llink=F;
		F->rlink=New;
		New->rlink=R;
		
		R=New;
	}
}

void DeleteFront()
{
	Node *x;
	x=F;
	if(F==NULL)
	{
		printf("NO element present");
	}
	else
	{
		if(F==R)
		{
			F=NULL;
			R=NULL;
		}
		else
		{
			F=F->llink;
			F->rlink=R;
			R->llink=F;
		}
		free(x);
	}
}


void display()
{
	int i;
	if(F==NULL)
	{
		printf("\nUnderflow\n");
	}
	Node *temp;
	temp=F;
	while(temp->llink!=F)
	{
		printf("%d\n",temp->data);
		temp=temp->llink;
	}
	printf("%d\n",temp->data);
}
int main()
{
	int n,ch;
	while(1)
	{
		printf("1->insert\n2->Delete\n3->Display\n4->Exit\n");
		printf("Enter choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: 
				printf("enter the data :");
				scanf("%d",&n);
				InsertAtRear(n);
			break;
			case 2:
				DeleteFront();
			break;
			case 3: 
				display();
			break;
			case 4: 
				exit(0);
			default:
				printf("Wrong Choice\n");
		}
	}
	return 0;
}
