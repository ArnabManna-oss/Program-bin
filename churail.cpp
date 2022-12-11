#include<stdio.h>
#include<stdlib.h>

void merge(int array[],int low,int mid,int high)
{
    int i,j,k,n=high;
    int b[n];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high)
    {
        if(array[i]<=array[j])
        {
            b[k]=array[i];
            i++;
        }
        else
        {
            b[k]=array[j];
            j++;
        }
        k++;
    }
    if(i>mid)
    {
        while(j<=high)
        {
            b[k]=array[j];j++;k++;
        }
    }
    else
    {
        while(i<=mid)
        {
            b[k]=array[i];i++;k++;
        }
    }
    for(k=low;k<=high;k++)
    {
        array[k]=b[k];
    }
    
}
void printarray(int array[],int n)
{
    int i;
    for (i=0;i<n;i++)
         printf("%d, ",array[i]);
} 
void merge_sort(int array[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        merge_sort(array,low,high);
        merge_sort(array,mid+1,high);
        merge(array,low,mid,low);
    }   
}
int main()
{
    int array[10],i,n;
    printf("enter the number of elements : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
	scanf("%d",&array[i]);
	}
    merge_sort(array,0,n-1);
    printf("The sorted order is:");
	for(i=0;i<n;i++)
	 printf("%d",array[i]);
	return 0;
}
