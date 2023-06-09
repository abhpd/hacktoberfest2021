#include<iostream>
using namespace std;
int rod(int l[],int p[],int n, int len)
{
	if(n==0||len==0)
	{
		return 0;
	}
	else if(l[n-1]<=len)
	{
		return max(p[n-1]+rod(l,p,n,len-l[n-1]),rod(l,p,n-1,len));
	}
	else if(l[n-1]>len)
	{
		return rod(l,p,n-1,len);
	}
}
int main()
{
	int length[]={1,2,3,4,5,6,7,8};
	int price[]={1,5,8,9,10,20};
	int len=8;
	cout<<rod(length,price,8,len);
}
