#include<iostream>
#include<algorithm>
using namespace std;
void sort_end (int s[], int f[], int n)
{
	for (int i=0; i<n-1; i++)
	{
		int flag = 0;
		for (int j=0; j<n-1-i; j++)
		{
			if (f[j] > f[j+1])
			{
				swap(f[j], f[j+1]);
				swap(s[j], s[j+1]);
				flag = 1;
			}
		}
		if (flag == 0)
		break;
	}
}
void activitiesSelected (int a[], int s[], int f[], int n)
{
	cout<<a[0]<<" ";
	int j = 0;
	for (int i=1; i<n; i++)
	{
		if (s[i] >= f[j])
		{
			cout<<a[i]<<" ";
			j = i;
		}
	}
}
int main()
{
	int n;
	cout<<"\nEnter size of array: ";
	cin>>n;
	int a[n], s[n], f[n];
	cout<<"\nEnter start time array: ";
	for (int i=0; i<n; i++)
	cin>>s[i];
	cout<<"\nEnter finish time array: ";
	for (int i=0; i<n; i++)
	cin>>f[i];
	sort_end(s, f, n);
	for (int i=0; i<n; i++)
	a[i] = i+1;
	cout<<"\nThe selected activities are: ";
	activitiesSelected(a, s, f, n);
}
