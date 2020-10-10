#include <bits/stdc++.h>
using namespace std;
int main()
{
   map<char, int> m;
   cout<<"Enter number of characters you want to enter: ";
   int n;
   cin>>n;
   cout<<"Enter characters: "<<endl;
   while(n--)
   {
       char ch;
       cin>>ch;
       m[ch]++;
   }
   cout<<"Character count: "<<endl;
   for(auto x:m)
   {
       cout<<x.first<<" = "<<x.second<<endl;
   }
   return 0;
}