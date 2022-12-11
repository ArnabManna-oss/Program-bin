#include<stdio.h>
void selectionsort(int *a, int n)
{
	int i,j,min,pos,temp=0;
	for(i=0;i<n-1;i++)
	{
		min=a[i];
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<min)
			{
				min=a[j];
				pos=j;
			}
		}	
		temp=a[i];
		a[i]=a[pos];
		a[pos]=temp;
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
int main()
{
	int *a,n,i;
	printf("enter the array size");
	scanf("%d",&n);
	
	a=(int *)calloc(n,sizeof(int));
	for(i=0;i<n;i++)
	{
		printf("enter the data %d :",i);
		scanf("%d",&a[i]);
	}

	selectionsort(a,n);
	return 0;
}


