#include<iostream>
using namespace std;
bool fun(int A[],int n,int sum)
{
	if(sum==0)
	{
		return 1;
	}
	else if(n==0)
	{
		return 0;
	}
	else if(A[n-1]<=sum)
	{
		return (1&&fun(A,n-1,sum-A[n-1]))||(fun(A,n-1,sum));
	}
	else if(A[n-1]>sum)
	{
		return fun(A,n-1,sum);
	}
}
int main()
{
	int A[]={1,4,3,4};
	int n=4;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum=sum+A[i];
	}
	if(sum%2==0)
	{
		cout<<fun(A,n,sum/2);
	}
	else
	{
		cout<<0;
	}
}
