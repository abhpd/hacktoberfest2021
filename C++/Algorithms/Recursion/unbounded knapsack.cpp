#include<iostream>
using namespace std;
int unbounded(int wt[],int pr[],int n,int total)
{
	if(n==0||total==0)
	{
		return 0;
	}
	else if(wt[n-1]<=total)
	{
		return max(pr[n-1]+unbounded(wt,pr,n,total-wt[n-1]),unbounded(wt,pr,n-1,total));
	}
	else if(wt[n-1]>total)
	{
		return unbounded(wt,pr,n-1,total);
	}
}
int main()
{
	int weight[]={1,2,5,8,10};
	int price[]={3,2,5,7,1};
	int total=10;
	cout<<unbounded(weight,price,5,total);
}
