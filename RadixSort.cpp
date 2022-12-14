#include<stdio.h>
#include<stdlib.h>

int getmax(int *a,int n)
{
	int max=a[0];
	for(int i=1;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	return max;
}

void Sort(int *a,int size,int div)
{
	int output[size];
	int count[10]={0};
	
	for (int i=0;i<size;i++)
	{
		count[(a[i]/div)%10]++;
	}
	for (int i=1;i<10;i++)
	{
		count[i]+=count[i-1];
	}
	for (int i=size-1;i>=0;i--)
	{
		output[count[(a[i]/div)%10]-1]=a[i];
		count[(a[i]/div)%10]--;
	}
	for(int i=0;i<size;i++)
		a[i]=output[i];
	
}

void radix_sort(int *a,int n)
{
	int m=getmax(a,n);
	for (int div=1;(m/div)>0;div=div*10)
	{
		Sort(a,n,div);
	}
	
}

void printarray(int *a,int n)
{
    int i;
    for (i=0;i<n;i++)
         printf("%d, ",a[i]);
}

int main()
{
	int *a;
	int n,i;
	puts("enter the range");
	scanf("%d",&n);
	a=(int*) calloc(n,sizeof(int));
	
	for(i=0;i<n;i++)
	{
		printf("enter the data (%d):",i);
		scanf("%d",&a[i]);
	}
	printf("original array\n");
	printarray(a,n);
	puts("\narray after sorting");
	radix_sort(a,n);
	printarray(a,n);
	return 0;
}
