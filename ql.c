#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	
	struct node *link;
}Node;

Node GetNode()
{
	Node *New;
	New=(Node*)malloc(sizeof(Node));
	New->data=0;	
	New->link=NULL;
	return New;
}

Node Insert(Node *F,Node *R,int a)
{
	Node *New=GetNode();
	New->data=a;
	if(N=NULL)
	{
		F=New;
		R=F;
		F->link=NULL;
		R->link=NULL;
	}
	else
	{
		R->link=New;
		R=New;
	}
	return F;
}

Node Delete(Node *F,Node *R)
{
	Node *x;
	x=F;
	if(F==NULL)
	{
		printf

