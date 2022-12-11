#include<stdio.h>

void Insertionsort(int *a,int n)
{
	int i,j,v;
	for(i=1;i<n;i++)
	{
		v=a[i];
		j=i-1;
		while(j>=0 && v<a[j])
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=v;
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

	Insertionsort(a,n);
	return 0;
}

