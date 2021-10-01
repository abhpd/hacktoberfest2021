/*Problem Statement: Given number of pages in n different books and m students. 
The books are arranged in ascending order of number of pages. Every student is assigned to read some consecutive books. 
The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum. 

Time Complexity: O(nlogn)

*/
#include<iostream>
#include<climits>
using namespace std;
bool isvalidconfig(int books[],int n,int k,int ans)
{
	int students=1;
	int current_pages=0;
	for(int i=0;i<n;i++)
	{
		if(current_pages+books[i]>ans)
		{
			current_pages=books[i];
			students++;
			if(students>k)
			{
				return false;
			}
		}
		else
		{
			current_pages+=books[i];
		}
	}
	return true;
}
int searchBooks(int books[],int n,int k)
{
	int total_pages=0;
	int s=0,e=0,finalAns=0;
	for(int i=0;i<n;i++)
	{
		total_pages+=books[i];
		s=max(s,books[i]);
	}
	finalAns=s;
	e=total_pages;
	while(s<=e)
	{
		int mid=(s+e)/2;
		if(isvalidconfig(books,n,k,mid))
		{
			finalAns=mid;
			e=mid-1;
		}
		else
		{
			s=mid+1;
		}
	}
	return finalAns;
}
int main()
{

		int n,k;
		cin>>n>>k;
		int arr[1000];
		for(int j=0;j<n;j++)
		{
			cin>>arr[j];
		}
		cout<<searchBooks(arr,n,k)<<endl;
	return 0;
}
