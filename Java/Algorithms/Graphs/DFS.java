    // helper function of the dfs function
    public static void dfsUtil(int v, ArrayList<ArrayList<Integer>> graph, boolean[] visited, ArrayList<Integer> ans){
        
        ArrayList<Integer> nbrs = graph.get(v);
        for(int i = 0; i < nbrs.size(); i++){
            int rem = nbrs.get(i);
            if(!visited[rem]){
                visited[rem] = true;
                ans.add(rem);
                dfsUtil(rem, graph, visited, ans);
            }
        }
        
        return;
        
    }
    
    // function to implement dfs
    // N - Number of Vertices
    // graph - adj list representing edges of graph
    public static ArrayList<Integer> dfs(ArrayList<ArrayList<Integer>> graph, int N)
    {
       ArrayList<Integer> ans = new ArrayList<>();
        boolean[] visited = new boolean[N];
        
        visited[0] = true;
        ans.add(0);
    
        dfsUtil(0, graph, visited, ans);
    
        return ans;

    }
