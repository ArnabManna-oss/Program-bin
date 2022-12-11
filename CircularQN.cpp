#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 5

typedef struct node_tag
{
	int Data[MAXSIZE];
	int f,r;
}Q;

Q Initialize(Q q)
{
	q.f=-1;
	q.r=-1;
	return q;
}

Q Insert(Q q,int a)
{
	if(q.f==((q.r+1)%MAXSIZE))
	{
		printf("Overflow");
		return q;
	}
	else if(q.f==-1 && q.r==-1)
	{
		q.f=0;
		q.r=0;
		//q.Data[q.r]=a;
	}
	else
	{
		q.r=(q.r+1)%MAXSIZE;
	}
	q.Data[q.r]=a;
	return q;
}

Q Delete(Q q)
{
	int v;
	v=q.Data[q.f];
	if(q.f==-1 && q.r==-1)
	{
		printf("\nQueue is empty");
		return q;
	}
	else
	{
		if(q.f==q.r)
		{
			q.f=-1;
			q.r=-1;
		}
		else
		{
			q.f=(q.f+1)%MAXSIZE;
		}
	}
	printf("%d has been deleted !",v);
	return q;
}

void Display(Q q)
{
	int i;
	if(q.f==-1 && q.r==-1)
	{
		printf("\nQueue is empty");
	}
	else
	{
		i=q.f;
		while(i!=q.r)
		{
			printf("%d\n",q.Data[i]);
			i=(i+1)%MAXSIZE;
		}
		printf("%d\n",q.Data[q.r]);
	}
}

int main()
{
	int ch;
	int n;
	Q q=Initialize(q);

	while(1)
	{
		printf("1>insert\n2>Delete\n3>display\n4>exit enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the Data:");
				scanf("%d",&n);
				q=Insert(q,n);
				break;
			case 2:
				q=Delete(q);
				printf("deleted");
				break;
			case 3:
				Display(q);
				break;
			case 4:
				exit(0);
			default:
				printf("invalid choice");
		}
	}
return 0;
}
