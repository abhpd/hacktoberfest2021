#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N,m;
    cin>>N>>m;

    vector<pair<int,int>> adj[N];

    int a,b,wt;

    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>wt;
        adj[a].push_back({b,wt});
        adj[b].push_back({a,wt});
    }

    int parent[N];
    int key[N];
    bool mstSet[N];

    for(int i=0;i<N;i++)
       mstSet[i]=false, key[i]=INT_MAX;

    key[0]=0;
    parent[0]=-1;


    for(int count=0;count<N-1;count++)
    {
        int min=INT_MAX,u;

        for(int i=0;i<N;i++)
        {
            if(mstSet[i]==false && key[i]<min)
            {
                min=key[i];
                u=i;
            }
        }

        mstSet[u]=true;

        for(auto it: adj[u])
        {
            int v=it.first;
            int weight=it.second;
            if(mstSet[v]==false && weight < key[v])
            {
                key[v]=weight;
                parent[v]=u;
            }
        }

    }


    for(int i=1;i<N;i++)
    {
        cout<<"parent of" <<i<<" is "<<parent[i]<<endl;
    }



    return 0;
}
