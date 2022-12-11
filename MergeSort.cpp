#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
 
void printarray(int a[],int n)
{
    int i;
    for (i=0;i<n;i++)
         printf("%d, ",a[i]);
}
 
void merge(int a[],int lb,int mid,int ub,char ch)
{
    int i,j,k,n=ub;
    int b[n];
    i=lb;
    j=mid+1;
    k=lb;
    if(ch=='1')
    {
    while(i<=mid && j<=ub)
    {
        if(a[i]<=a[j])
        {
            b[k]=a[i];
            i++;
        }
        else
        {
            b[k]=a[j];
            j++;
        }
        k++;
    }
    }
    else if(ch=='2')
    {
    while(i<=mid && j<=ub)
    {
        if(a[i]>=a[j])
        {
            b[k]=a[i];
            i++;
        }
        else
        {
            b[k]=a[j];
            j++;
        }
        k++;
    }
    }
    if(i>mid)
    {
        while(j<=ub)
        {
            b[k]=a[j];j++;k++;
        }
    }
    else
    {
        while(i<=mid)
        {
            b[k]=a[i];i++;k++;
        }
    }
    for(k=lb;k<=ub;k++)
    {
        a[k]=b[k];
    }
}
    
void merge_sort(int a[],int lb,int ub,char ch)
{
    int mid;
    if(lb<ub)
    {
        mid=(lb+ub)/2;
        merge_sort(a,lb,mid,ch);
        merge_sort(a,mid+1,ub,ch);
        merge(a,lb,mid,ub,ch);
    }   
}
 
main()
{
    int a[10],i,n;
    char ch;
    printf("enter the number of elements to be inserted : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {scanf("%d",&a[i]);}
    while(1)
    {
    printf("\n1> sort in ascending order\n2>sort in descending order\nenter your choice : ");
    fflush(stdin);
    ch=getche();
    if(ch=='1') printf("the ascending order arrangement is : ");
    else if(ch=='2') printf("the descending order arrangement is : ");
    else exit(0);
    merge_sort(a,0,n-1,ch);
    printarray(a,n);
    }
    
}
