#include<stdio.h>
#include<stdlib.h>
#include<String.h>

int m;
int c;

int HashFn(int k,int i)
{
	return ((k+(i*c))%m);
}

int isfull(int *a)
{
	int i,f=0;
	for(i=0;i<m;i++)
	{
		if(a[i]!=-1)
		{
			f++;
		}
	}
	if(f==0)
	return 1;
	else
	return 0;
}

int isempty(int *a)
{
	int i,f=0;
	for(i=0;i<m;i++)
	{
		if(a[i]==-1)
		{
			f++;
		}
	}
	if(f==12)
	return 1;
	else
	return 0;
}
void printHash(int *a)
{
	int i;
	puts("index\t\tdata\n");
	for(i=0;i<m;i++)
	{
		
		if(a[i]==-1)
		printf("%d\t\t\n",i);
		else
		printf("%d\t\t%d\n",i,a[i]);
	}
} 

void insert(int *a,int k)
{
	int i=0;
	int h=HashFn(k,i);
	while (a[h]!=-1)
	{
		if(isfull(a)==1)
		{
			printf("no space found ");
			break;
		}
		i++;
		h=HashFn(k,i);
	}
	a[h]=k;
	puts("data added successfully");
	
}

void search(int *a,int n1)
{
	int i=0;
	int h=HashFn(n1,i);
	while (a[h]!=n1)
	{
		i++;
		h=HashFn(n1,i);
	}
	if(a[h]==n1)
	{
		printf("the data is present at position%d\n",h);
	}
	else
	{
		printf("not found !\n");
	}
}

void Delete(int *a,int n1)
{
	int i=0;
	int h=HashFn(n1,i);
	while (a[h]!=n1)
	{
		if(isempty(a)==1)
		{
			printf("no space found ");
			break;
		}
		i++;
		h=HashFn(n1,i);
	}
	if(a[h]==n1)
	{
		a[h]=-1;
		printf("deleted\n");
	}
	else
	{
		printf("not found!\n");
	}
}

int main()
{
	int *a,i,n,ch;
	puts("enter m :");
	scanf("%d",&m);
	a=(int*) calloc(m,sizeof(int));
	puts("enter c :");
	scanf("%d",&c);
	
	for(i=0;i<m;i++)
	{
		a[i]=-1;
	}
	while(1)
	{
		puts("1>insert a key\n2> search key\n3> delete a key\n4>display the hash table\n5>exit\nenter your choice :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the data :");
				scanf("%d",&n);
				insert(a,n);
			break;
			case 2:
				printf("the data you want ? :");
				scanf("%d",&n);
				search(a,n);
			break;
			case 3:
				printf("the data you want to delete ? :");
				scanf("%d",&n);
				Delete(a,n);
			break;
			case 4:
				printHash(a);
			break;
			case 5:
				exit(0);
			default:
				puts("invalid choice");
		}
	}
	return 0;
}
