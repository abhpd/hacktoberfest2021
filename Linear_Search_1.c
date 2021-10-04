//lINEAR SEARCH FOR MORE THAN ONE POSITION OF SEARCHING ELEMENT IN C	
#include<stdio.h>
#include<stdlib.h>
#define ll long long int// For taking large integer value
void Linear_Search_for_Element(ll*a,ll n,ll element)
{
	ll i,k=0;
	printf("The position of %lld is",element);
	for(i=0;i<n;i++)
	{
		if(a[i]==element)
		{
			printf("\n%lld",i+1);
			k++;
		}
	}
	if(k==0)
	{
		printf(" not found in array element list.");
	}	
}
int main()
{
	ll n,i,ele;
	printf("Enter the size of array:\t");
	scanf("%lld",&n);
	printf("Enter the elements of array you want:\n");
	ll *a=(ll*)malloc(n*sizeof(ll));
	for(i=0;i<n;i++)
	{
		printf("The element-%lld is:\t",i+1);
		scanf("%lld",(a+i));
	}
	printf("Enter the element you want to search:\t");
	scanf("%lld",&ele);
	Linear_Search_for_Element(a,n,ele);
	return 0;
}
