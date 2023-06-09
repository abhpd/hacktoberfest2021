#include <iostream>
using namespace std;

int main() 
{
        int n,start=0,end,k,s,d=0;
        cin >>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
        }
         int curr_sum=0;
        for(int end=0;end<=n;)
        {
            if(end==n)
            {
            end=n-1;
            d++;
            }
            if(curr_sum < k)
            {
                curr_sum=curr_sum+a[end];
                end++;
            }
            else if(curr_sum > k)
            {
               
                curr_sum=curr_sum-a[start];
                 start=start+1;
                
            }
            else if(curr_sum==k)
            {
                if(d==0)
                {
              s=end-1;
                }
                if(d!=0)
                {
                s=n-1;
                }
              end=n+1;
            }
        }
        cout <<start <<" "<<s;
	return 0;
}
