#include<iostream>
using namespace std;
#define V 5
int min_key(int key[],bool visit[])
{
	int min=INT_MAX,min_index;
	for(int i=0;i<V;i++)
	{
		if(visit[i]==false&&key[i]<min)
		{
			min=key[i];
			min_index=i;
		}
	}
	return min_index;
}
void prim(int graph[V][V])
{
   int key[V],parent[V];
   bool visit[V];
   for(int i=0;i<V;i++)
   {
   	key[i]=INT_MAX;
   	visit[i]=false;
   }
   key[0]=0;
   parent[0]=-1;
   for(int i=0;i<V-1;i++)
   {
   	int u=min_key(key,visit);
   	visit[u]=true;
   	for(int j=0;j<V;j++)
   	{
   		if(graph[u][j]&&visit[j]==false&&graph[u][j]<key[j])
   		{
   			key[j]=graph[u][j];
   			parent[j]=u;
   		}
   	}
   }
   for(int i=0;i<V;i++)
   {
   	cout<<i<<" "<<parent[i]<<" "<<graph[i][parent[i]]<<endl;
   }
}
int main()  
{  
    int graph[V][V] = { { 0, 2, 0, 6, 0 },  
                        { 2, 0, 3, 8, 5 },  
                        { 0, 3, 0, 0, 7 },  
                        { 6, 8, 0, 0, 9 },  
                        { 0, 5, 7, 9, 0 } };   
    prim(graph);  
  
    return 0;  
} 