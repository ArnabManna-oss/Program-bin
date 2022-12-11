#include<stdio.h>


int binserch(int *a,int item,int lb,int ub)
{	
int mid;
	while(lb<ub)
	{
	mid=(lb+ub)/2;
	if(a[mid]==item)
	{
		return 1;
	}
	if(item<a[mid])
	{
		ub=mid-1;
	}
	else
	{
		lb=mid+1;
	}
}
return 0;
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
