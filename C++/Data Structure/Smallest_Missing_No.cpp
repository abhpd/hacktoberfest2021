#include <iostream>
using namespace std;

int main() {
    int n;
	cin >>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
	    cin >> a[i];
	}
        const int N=1e+2;
        int indx[N];
       
    for(int i=0;i<N;i++)
        {
            indx[i]=0;
        }
        for(int i=0;i<n;i++)
        {
            if(a[i]>=0)
            {
            indx[a[i]]++;
            }
        }
        for(int i=0;i<N;i++)
        {
            if(indx[i]==0)
            {
                cout<< i;
                break;
            }
        }
	return 0;
}
