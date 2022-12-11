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

void InsertAtFront(int a)
{
	Node *New;
	New=getnode();
	New->data=a;
	if(F==NULL)
	{
		F=New;
		R=F;
	}
	else
	{
		New->llink=F;
		F->rlink=New;	
		F=New;
	}
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
	}
	else
	{
		New->rlink=R;
		R->llink=New;	
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
		}
		free(x);
	}
}

void DeleteRear()
{
	Node *x;
	x=R;
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
			R=R->rlink;
			R->llink=NULL;
		}
	}
	free(x);
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
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->llink;
	}
}
void main()
{
	int ch,n;
	while(1)
	{
		printf("1->Insert from rear end\n2->Insert from front end\n3->Delete from rear\n4->Delete from front\n5->Display\n6->Exit\n");
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
				printf("enter the data :");
				scanf("%d",&n);
				InsertAtFront(n);
			break;
			case 3: 
				DeleteRear();
			break;
			case 4: 
				DeleteFront();
			break;
			case 5: 
				display();
			break;
			case 6: 
				exit(0);
			default:
				printf("Wrong Choice\n");
		}
	}
}
