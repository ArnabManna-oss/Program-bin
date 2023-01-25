#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}


int mode(int arr[], int n) {
    int maxValue = 0, maxCount = 0;
	int i, j;
    for (i = 0; i < n; ++i) {
        int count = 0;
        for (j = 0; j < n; ++j) {
            if (arr[j] == arr[i]) {
                ++count;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            maxValue = arr[i];
        }
    }
    return maxValue;
}

int main()
{
	int i,n;
	int a[100],mean,mid,sd,va=0,s=0;
	
	printf("enter the range");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		a[i]=rand() % 100;
		printf("%d\n",a[i]);
		s+=a[i];
	}
	mean=s/n;
	printf("mean =%d\n",mean);
	bubbleSort(a,n);
	if(n%2==0)
	{
		mid=(a[(n/2)]+a[(n+2)/2])/2;
	}
	else
	{
		mid=a[(n+1)/2];
	}
	
	printf("Median =%d\n",mid);
	printf("Mode =%d\n",mode(a,n));
	
	for(i=0;i<n;i++)
	{
		va=va+pow(a[i]-mean,2);
	}
	
	va=va/(n-1);
	printf("variance =%d\n",va);
	sd=sqrt(va);
	printf("standard deviation =%d\n",sd);
	return 0;
}
