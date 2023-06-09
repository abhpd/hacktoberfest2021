#include <bits/stdc++.h>
using namespace std;

//define array globally
const int N = 1e6 +4;

int a[N];
int n;//array size

//elememt to be searched in array
int k;

bool check(int dig)
{
	//element at dig position in array
	int ele=a[dig];

	//if k is less than
	//element at dig position
	//then we need to bring our higher ending to dig
	//and then continue further
	if(k<=ele)
	{
		return 1;
	}
	else
	{
	return 0;
	}
}
void binsrch(int lo,int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi)/2;
		if(check(mid))
		{
			hi=mid;
		}
		else
		{
			lo=mid+1;
		}
	}
	//if a[lo] is k
	if(a[lo]==k)
		cout<<"Element found at index "<<lo;// 0 based indexing
	else
		cout<<"Element doesnt exist in array";//element was not in our array

}


int main()
{
	cin>>n;
for(int i=0; i<n; i++)
{
	cin>>a[i];
}
cin>>k;

//it is being given array is sorted
//if not then we have to sort it

//minimum possible point where our k can be is starting index
//so lo=0
//also k cannot be outside of array so end point
//hi=n

binsrch(0,n);

	return 0;
}

