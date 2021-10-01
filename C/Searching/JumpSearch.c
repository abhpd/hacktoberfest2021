#include <stdio.h>
#include <math.h>
void search(int *arr, int n, int no)
{
	int jump = sqrt(n);
	int low = 0;
	int high = jump;
	int flag = 0;
	int i;
	for(i=1;i<=jump;i++)
	{
		if(no>=*(arr+low) && no<=*(arr+high))
		{
			flag = 1;
			break;
		}
		else
		{
			low = high;
			high = high + jump;
		}
	}
	if(flag==0)
	{
		printf("Number is Not Present in Array\n");
	}
	else
	{
		for(i=low;i<high;i=i+1)
		{
			if(no == *(arr+i))
			{
				printf("Number Found in Position %d\n",(i+1));
				break;
			}
		}
	}
}
int main()
{
	printf("Jump Search\n");
	printf("***********\n\n");
	int arr[100];
	int n,i,no;
	printf("Enter Size of Array : ");
	scanf("%d",&n);
	printf("\n");
	printf("Enter Numbers in Sorted Form : \n");
	for(i=0;i<n;i=i+1)
	{
		scanf("%d",&arr[i]);
	}
	printf("\n");
	printf("Enter Number to be Searched : ");
	scanf("%d",&no);
	printf("\n");
	search(arr,n,no);
}