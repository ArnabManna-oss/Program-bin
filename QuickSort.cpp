#include<stdio.h>
#include<stdlib.h>

void swap(int *p,int *q)
{
	int temp=*p;
	*p=*q;
	*q=temp;
}

int partition(int *a,int low,int high)
{
    int pivot,start,end;
    pivot=a[low];
    start=low;
    end=high;
    while(start<end)
    {
        while(a[start]<=pivot)
        {
           start++;
       }                
        while(a[end]>pivot)
        {
            end--;
        }   
                
        if(start<end)
        {
            swap(&a[start],&a[end]);
        }
        swap(&a[low],&a[end]);
        return end;
 	}
        
}

 void quick_sort(int *a,int lb,int ub)
 {
    int loc;
    if(lb<ub)
    {
        loc=partition(a,lb,ub);
        quick_sort(a,lb,loc-1);
        quick_sort(a,loc+1,ub);   
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
	quick_sort(a,0,n-1);
	printarray(a,n);
	return 0;
}
