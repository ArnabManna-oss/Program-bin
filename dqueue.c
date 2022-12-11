#include<stdio.h>
#include<stdlib.h>

int r=-1,f=-1;
void insertrear(int *a,int max)
{
	int data;
	printf("Enter the data\n");
	scanf("%d",&data);
	if(r==(max-1))
	{
		printf("\nOverflow\n");
	}
	else if(f==-1 && r==-1)
	{
		f=0;
		r=0;
	}
	else
	{
		r=r+1;
	}
	a[r]=data;
}
void insertfront(int *a,int max)
{
	int data;
	
	if(f==0)
	{
		printf("\nOverflow\n");
		return;
	}
	if(f==-1 && r==-1)
	{
		f=0;
		r=0;
	}
	else
	{
		f=f-1;
	}
	printf("Enter the data\n");
	scanf("%d",&data);
	a[f]=data;
}

void deleterear(int *a)
{
	int v=a[r];
	if(f==-1 && r==-1)
	{
		printf("\nUnderflow\n");
	}
	else if(f==r)
	{
		f=-1;
		r=-1;
		printf("%d\nhas been deleted\n",v);
	}
	else
	{
		r--;
		printf("%d\nhas been deleted\n",v);
	}
}
void deletefront(int *a)
{
	int v=a[f];
	if(f==-1 && r==-1)
	{
		printf("\nUnderflow\n");
	}
	else if(f==r)
	{
		f=-1;
		r=-1;
		printf("%d\nhas been deleted\n",v);
	}
	else
	{
		f++;
		printf("%d\nhas been deleted\n",v);
	}
}
void display(int *a)
{
int i;
	if(f==-1 && r==-1)
	{
		printf("\nUnderflow\n");
	}
	i=f;
	while(i<=r)
	{
		printf("%d\n",a[i]);
		i++;
	}
}
void main()
{
	int a[50],i,ch,max;
	printf("Enter max size\n");
	scanf("%d",&max);
	while(1)
	{
		printf("1->Insert from rear end\n2->Insert from front end\n3->Delete from rear\n4->Delete from front\n5->Display\n6->Exit\n");
		printf("Enter choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: 
				insertrear(a,max);
			break;
			case 2: 
				insertfront(a,max);
			break;
			case 3: 
				deleterear(a);
			break;
			case 4: 
				deletefront(a);
			break;
			case 5: 
				display(a);
			break;
			case 6: 
				exit(0);
			default:
				printf("Wrong Choice\n");
		}
	}
}

