//This algo helps us find all the SCCs.
//SCCs are those in which if we start from 1 node, we can reach each and every other node in that component.

// The entire algo can be divided into 3 parts:
// i) Sorting all nodes in order of finishing time (done with the help of toposort)
// ii) Finding trnaspose of graph
// iii) Do DFS according to finishing time.

class Solution
{
    //Function to find number of strongly connected components in the graph.
    public int kosaraju(int V, ArrayList<ArrayList<Integer>> adj)
    {
      
       //i) This part helps to find the topological order of graph:
        Stack<Integer> st= new Stack<>();
        int[] vis= new int[V];
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
             topo(i,vis,adj,st);
        }
        //ii) Now, finding a trnaspose of the actual graph
        //    By transpose, we mean to reverse the direction of edges. 
        //    For example, 1->2 will be changed to 1<-2
        ArrayList<ArrayList<Integer>> transpose= new  ArrayList<ArrayList<Integer>>();
        for(int i=0;i<V;i++)
         transpose.add(new ArrayList<Integer>());
         
         for(int i=0;i<V;i++)
         {
             vis[i]=0;
             for(int it: adj.get(i))
               transpose.get(it).add(i);
         }
         //Doing DFS to find no. of SCCs
         int c=0;
         while(st.size()>0)
         {
             int node=st.pop();
             if(vis[node]==0)
             {
                 c++;
               revDfs(node,transpose,vis);
             }
         }
          return c;  //returns the count
    }
    // this function is a normal DFS 
    void revDfs(int node,  ArrayList<ArrayList<Integer>> transpose, int[]vis)
    {
        vis[node]=1;
        
        for(int it: transpose.get(node))
        {
            if(vis[it]==0)
              revDfs(it,transpose,vis);
        }
    }
    //Topological sorting using DFS
    void topo(int node, int[] vis, ArrayList<ArrayList<Integer>> adj, Stack<Integer> st)
    {
        vis[node]=1;
        for(int it: adj.get(node))
        {
            if(vis[it]==0)
              topo(it,vis,adj,st);
        }
        st.push(node);
    }
}
