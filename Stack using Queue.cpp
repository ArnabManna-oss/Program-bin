#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define TRUE 1
#define FALSE 0

typedef unsigned char BOOLEAN;
  
typedef struct node
{
	int data;
	struct node *LLINK;
	struct node *RLINK;
}NODE; 

NODE *getnode()
{
	NODE *New;
	New=(NODE *)malloc(sizeof(NODE));
	New->LLINK=NULL;
	New->RLINK=NULL;
	return New;
}
typedef struct Queue{
	NODE *front;
	NODE *rear;}QUEUE;
	
	QUEUE initialize(QUEUE Q){
		Q.front=NULL;
		Q.rear=NULL;
		return Q;}
			
		BOOLEAN isfull(QUEUE Q)
		{
			NODE *NEW;
			NEW =getnode();
			if(NEW==NULL)
			return TRUE;
			else{free(NEW);
			return FALSE;}
		}
		BOOLEAN isempty(QUEUE Q)
		{
			if(Q.rear==NULL)
			return TRUE;
			else
			return FALSE;
		}
	QUEUE insert(QUEUE Q,int x)
	{
		NODE *New;
		New=getnode();
		if(New==NULL)
		{
			printf("Queue is full");
			return Q;
		}
		New->data=x;
		if(Q.rear==NULL)
		{
			Q.rear=Q.front=New;
		}
		else
		{
			(Q.rear)->RLINK= New;
			New->LLINK=Q.		rear;
			Q.rear=New;
		}
		return Q;
	}
	
QUEUE Delete(QUEUE Q, int *x)
{
	NODE *del;
	if (Q.rear == NULL)
	{
		printf("\nEmpty Queue");
		return Q;
	}
	if(Q.front->RLINK==Q.rear->RLINK)
	{
		del=Q.front;
		Q.rear=NULL;
	}
	else
	{
	Q.front=Q.front->RLINK;
	del=Q.front->LLINK;
	Q.front->LLINK=NULL;
	}
	*x=del->data;
	free(del);
	return Q;
}

void swap(QUEUE Q1,QUEUE Q2)
{
	QUEUE temp;
	temp=Q1;
	Q1=Q2;
	Q2=temp;
}
void Display(QUEUE Q)
{
	NODE *Ptr;
	printf("\nCurrent content of the Queue:");
	Ptr=Q.front;	
	while(Ptr != NULL)
	{
		printf("%d ", Ptr->data);
		Ptr=Ptr->RLINK;
	}
}
int main()
{
	QUEUE Q1,Q2;
	char Choice;
	int x;
	Q1 = initialize(Q1);
	Q2 = initialize(Q2);
	
	while(1)
	{
		printf("\n 1. Insert");
		printf("\n 2. Delete");
		printf("\n 3. Display");
		printf("\n 4. IS FULL");
		printf("\n 5. IS EMPTY");
		printf("\n 6. Exit");
		printf("\n\n\nEnter your option(1-4)");
		fflush(stdin);
		Choice = getche();
		switch(Choice)
		{
			case '1': 	printf("\n\nEnter data to insert");
						scanf("%d", &x);
						Q2 = insert(Q2, x);
						while(Q1.rear != NULL)
						{
							Q1 = Delete(Q1, &x);
							Q2 = insert(Q1, x);
						}						
						swap(Q1,Q2);
						break;
			case '2':	Q1 = Delete(Q1, &x);
			printf("\n\nData deleted: %d",x);
						break;
			case '3':   Display(Q1);
						break;
			case '4':if(isfull(Q1)==TRUE)printf("queue is full");else printf("queue is not full");
			            break;
			 case '5':if(isempty(Q1)==TRUE)printf("queue is empty");else printf("queue is not empty");
			            break;
			case '6':   exit(0);
			default: 	printf("\n\nInvalid option");
		}		
	}
return 0;
}
