#include <bits/stdc++.h>
#include <queue>
#include <deque>
#include <unordered_map>
using namespace std;

int main()
{

#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif

    int cacheSize;
    cin>>cacheSize;

    int pg;
    cin>>pg;

    vector<int> a(pg);
    for(int i=0;i<pg;i++)
    cin>>a[i];

    deque<int> q;
    deque<int> :: iterator it;

    bool hit=false;
    int tr=0;
    for(int i=0;i<pg;i++)
    {
        hit=false;
        for(int it=0;it<q.size();it++)
        {
            if(q[it]==a[i])
            {
                hit=true;
                tr=it;
            }
        }

        



        if(hit==false)
        {
            if(q.size()==cacheSize)
            {
                q.pop_front();
                q.push_back(a[i]);
            }
            else
            {
                q.push_back(a[i]);
            }
            cout<<a[i]<<" ";
        }
        else
        {
            q.erase(q.begin()+tr);
            q.push_back(a[i]);
        }
        
    }
    

}