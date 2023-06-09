#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int main() 
{
	int n;
	cin >>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
	    cin >> a[i];
	}
        const int N=1e+2;
        int indx[N];
        int min_index=1000;
    for(int i=0;i<N;i++)
        {
            indx[i]=-1;
        }
        for(int i=0;i<n;i++)
        {
            if(indx[a[i]]==-1)
                 {
                    indx[a[i]]=i;
                 }
            else
            {
            if(min_index >indx[a[i]])
                {
                    min_index=indx[a[i]];
                }
            }
        }
        cout << min_index;
	return 0;
}
