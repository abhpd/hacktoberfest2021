#include <bits/stdc++.h>
using namespace std;
long long ans[100000] = {0};
long long factorial(long long n)
{
   if (n >= 0)
   {
      ans[0] = 1;
      for (long long i = 1; i <= n; i++)
      {
         ans[i] = i * ans[i - 1];
      }
      return ans[n];
   }
}
int main()
{
   long long n;
   cout<<"Enter number to find factorial: ";
   cin>>n;
   cout<<factorial(n)<<endl;
   return 0;
}