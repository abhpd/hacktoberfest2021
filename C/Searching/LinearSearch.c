#include <stdio.h>
int search(int *arr, int n, int no)
{
	int i,pos=0;
	for(i=0;i<n;i=i+1)
	{
		if(*(arr+i) == no)
		{
			pos = i;
			break;
		}
	}
	return pos;
}
int main()
{
	printf("Linear Search\n");
	printf("*************\n\n");
	int arr[100];
	int n,i,no;
	printf("Enter Size of Array : ");
	scanf("%d",&n);
	printf("\n");
	printf("Enter Numbers : \n");
	for(i=0;i<n;i=i+1)
	{
		scanf("%d",&arr[i]);
	}
	printf("\n");
	printf("Enter Number to be Searched : ");
	scanf("%d",&no);
	printf("\n");
	int pos = search(arr,n,no);
	if(pos==0)
	{
		printf("Number is not Present in Array\n");
	}
	else
	{
		printf("Number Found in Position %d\n",(pos+1));
	}
}