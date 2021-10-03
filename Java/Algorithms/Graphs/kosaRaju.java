
import java.util.ArrayList;
import java.util.Stack;
//A directed graph is strongly connected if there is a path between all pairs of vertices. 
//A strongly connected component (SCC) of a directed graph is a maximal strongly connected subgraph.

// A class to find strongly connected component (SCC) in directed graph
public class kosaraju {
	 // 3 steps to apply kosaraju
	 // 1) find the topological sort ( i will create another file for it )
	 // 2) then take transpose of the graph
	 // 3) then just apply dfs in topological sort
	 void kosaRaju(ArrayList<ArrayList<Integer>> adj, int n)
	    {
	        int vis[] = new int[n]; 
	        Stack<Integer> st = new Stack<Integer>();  // stack is used to store the topological sort ,and we will apaly dfs accordingly
	        for(int i = 0;i<n;i++) {
	        	if(vis[i] == 0) { // if already visited ,don't visit it
	        		dfs(i, st, adj, vis); 
	        	}
	        }

	        ArrayList<ArrayList<Integer> > transpose = new ArrayList<ArrayList<Integer> >(); // to store the transpose of graph
			
			for (int i = 0; i < n; i++)  
				transpose.add(new ArrayList<Integer>());

			for(int i = 0;i<n;i++) {
				vis[i] = 0; 
				for(Integer it: adj.get(i)) {
					transpose.get(it).add(i); 
				}
			}
			
            // step 3 -- apply dfs in topo sort
			while(st.size() > 0) {
				int node = st.peek(); 
				st.pop(); 
				if(vis[node] == 0) {
					System.out.print("SCC: "); 
					revDfs(node, transpose, vis);
					System.out.println(); 
				}
			}

	    }
	 // step 1 -- to find topo sort
	private void dfs(int node, Stack<Integer> st, ArrayList<ArrayList<Integer>> adj, int vis[]) {
		vis[node] = 1;
		for(Integer it : adj.get(node)) {
			if(vis[it] == 0) {
				dfs(it, st, adj, vis); 
			}
		}
        // when dfs complete we will store in stack
		st.push(node); 
	}
    // apply dfs
	private void revDfs(int node, ArrayList<ArrayList<Integer>> transpose, int vis[]) {
		vis[node] = 1;
		System.out.print(node + " "); 
		for(Integer it : transpose.get(node)) {
			if(vis[it] == 0) {
				revDfs(it, transpose, vis); 
			}
		}
	}

   
 
}
