#include<stdio.h>


int binserch(int *a,int item,int lb,int ub)
{	
int mid;
	if(lb>ub)
	{
		return -1;
	}
	mid=(lb+ub)/2;
	if(a[mid]==item)
	{
		return 1;
	}
	if(item<a[mid])
	{
		binserch(a,item,lb,mid-1);
	}
	else
	{
		binserch(a,item,mid+1,ub);
	}
}



int main()
{
	int lb=1,ub,i,item,n;
	int a[100];
	
	printf("enter the array size");
	scanf("%d",&n);
	ub=n-1;
	
	for(i=0;i<n;i++)
	{
		printf("enter the data %d :",i);
		scanf("%d",&a[i]);
	}
	printf("enter the item to be searched: ");
	scanf("%d",&item); 
	if(binserch(a,item,lb,ub)==1)
	{
		printf("found!!!");
	}
	else
	{
		printf("not found !!");
	}
	return 0;
}
