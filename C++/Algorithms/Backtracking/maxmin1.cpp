#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m,n;
	cout<<"Enter no of tasks";
	cin>>m;
	cout<<"Enter no of machines";
	cin>>n;
	int A[m][n];
	cout<<"\nEnter duration-";
	for(int i=0;i<m;i++)
	{  cout<<"\nEnter for Task "<<i+1;
		for(int j=0;j<n;j++)
		{
			cin>>A[i][j];
		}
	}
	int assigned[m],busy_wait[n];
	memset(assigned,0,sizeof(assigned));
	memset(busy_wait,0,sizeof(busy_wait));
	int count = 0;
	while(count<m)
	{
		int min_t[m],assigned_server[m];
		for(int i=0;i<m;i++)
		{
			if(assigned[i]==0)
			{
				int min_time=A[i][0] + busy_wait[0];
				assigned_server[i] = 0;
				for(int j=1;j<n;j++)
				{
					if(A[i][j]+busy_wait[j] < min_time)
					{
						min_time = A[i][j]+busy_wait[j];
						assigned_server[i] = j;
					}
				}
				min_t[i] = min_time;
			}
			else
			{
				min_t[i] = INT_MAX;
			}
		}
		int overall_max = -1;
		int task =0;
		for(int i=0;i<m;i++)
		{
			if(assigned[i]==0)
			{
				if(overall_max < min_t[i])
					{overall_max = min_t[i];task =i;}
			}
		}
		cout<<"Assign T"<<task+1<<" to machine number "<<assigned_server[task]+1<<"\n";
		assigned[task] =1;
		busy_wait[assigned_server[task]]+=A[task][assigned_server[task]];
		count++;
	}
	int max_t = busy_wait[0];
	for(int i=0;i<n;i++)
	{
		
		if(max_t < busy_wait[i])
			max_t=busy_wait[i];
	}
	cout<<"MakeSpan = "<<max_t;
}
