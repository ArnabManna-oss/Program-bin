#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 10

typedef struct node_tag
{
	int Data[MAXSIZE][MAXSIZE];
	int f,r,max;
}Q;

Q Initialize(Q q)
{
	q.f=-1;
	q.r=-1;
	q.max=0;
	return q;
}

int MAXPri(Q q)
{
	int i;
	q.max=0;
	for(i=q.f;i<=q.r;i++)
	{
		if(q.max<q.Data[1][i])
		{
			q.max=q.Data[1][i];
		}
	}
}
	

Q Insert(Q q,int a,int pr)
{
	if(q.f==-1 && q.r==-1)
	{
		q.f=0;
		q.r=0;
	}
	else
	{	
		q.r++;
	}
	q.Data[0][q.r]=a;
	q.Data[1][q.r]=pr;
	if(q.max<pr)
		q.max=pr;
	return q;
}

Q Delete(Q q)
{	
	int i,j;
	q.max=0;
	for(i=q.f;i<=q.r;i++)
	{	
		if(q.max<q.Data[1][i])
		{

			q.max=q.Data[1][i];
		}
	}
	if(q.f==-1 && q.r==-1)
	{
		printf("\nQueue is empty");
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
			if(q.max==q.Data[1][q.f])
			{
				for(i=q.f;i<q.r;i++)
				{
					q.Data[0][i]=q.Data[0][i+1];
					q.Data[1][i]=q.Data[1][i+1];
				}
				q.r--;
			}
			else if(q.max==q.Data[1][q.r])
			{
				q.r--;
			}
			else
			{
				for(i=q.f;i<=q.r;i++)
				{
					if(q.Data[1][i]==q.max)
					{
						break;
					}
				}
				for(j=i;j<q.r;j++)
				{
					q.Data[0][j]=q.Data[0][j+1];
					q.Data[1][j]=q.Data[1][j+1];

				}
				q.r--;
			}	
		}
	}
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
		for(i=q.f ;i<=q.r;i++)
		{
			printf("%d,",q.Data[0][i]);
			printf("%d\n",q.Data[1][i]);
		}
	}
}

int main()
{
	int ch;
	int n,pr;
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
				printf("enter the Priority:");
				scanf("%d",&pr);
				q=Insert(q,n,pr);
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

