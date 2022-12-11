#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *next;
};
typedef struct node n;
n *top=NULL,*f=NULL,*r=NULL;

void enqueue()
{
	int item;
	printf("Enter the data :\n");
	scanf("%d",&item);
	n *ptr;
	ptr=(n*)malloc(sizeof(n));
	ptr->info=item;
	ptr->next=NULL;
	if(r==NULL && f==NULL)
	{
		f=ptr;
		r=ptr;
	}
	else
	{
		r->next=ptr;
		r=ptr;
	}

}
void dequeue()
{
	int x;
	
	if(f==r && r==NULL)
	{
		printf("\nUnderflow\n");
		return;
	}
x=f->info;
	if(f==r)
	{
		f=NULL;
		r=NULL;
		printf("%d\nhas been deleted\n",x);
	}
	else
	{
		f=f->next;
		printf("%d\nhas been deleted\n",x);
	}
}
void display()
{
	int i;
	if(f==NULL && r==NULL)
	{
		printf("\nUnderflow\n");
	}
	n *temp;
	temp=f;
	while(temp!=NULL)
	{
		printf("%d\n",temp->info);
		temp=temp->next;
	}
}
void main()
{
	int i,ch;
	while(1)
	{
		printf("1->insert\n2->Delete\n3->Display\n4->Exit\n");
		printf("Enter choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: 
				enqueue();
			break;
			case 2:
				dequeue();
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
}
