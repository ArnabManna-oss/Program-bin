#include<stdio.h>

void bubblesort(int *a,int n)
{
	int i,j,temp=0,flag=1;
	for(i=0;i<n && flag==1;i++)
	{	
		flag=0;
		for(j=0;j<n-i;j++)
		{
			if(a[j]>a[j+1])
			{	
				flag=1;
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
int main()
{
	int lb=1,ub,i,item,*a,n;
	printf("enter the array size");
	scanf("%d",&n);
	ub=n-1;
	
	a=(int *)calloc(n,sizeof(int));
	for(i=0;i<n;i++)
	{
		printf("enter the data %d :",i);
		scanf("%d",&a[i]);
	}

	bubblesort(a,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d,",a[i]);
	}
return 0;
}


