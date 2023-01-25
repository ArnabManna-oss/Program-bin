#include<stdio.h>

int main()
{
	int a[30],n,i,k=0,j;
	printf("enter the range :");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("enter the element :");
		scanf("%d",&a[i]);
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(a[i]==a[j])
			break;
		}
		if(j==i)
			a[k++]=a[i];
	}
	for(i=0;i<k;i++)
	{
		printf("%d ",a[i]);
	}	
}
