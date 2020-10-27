// N - number of vertex
// graph - the adj list storing the edges
static ArrayList<Integer> bfs(ArrayList<ArrayList<Integer>> graph, int N) {

  boolean[] visited = new boolean[N];
  ArrayList<Integer> ans = new ArrayList<>();
  
  Queue<Integer> q = new LinkedList<Integer>();
  q.add(0);
  visited[0] = true;
        
  while(q.size() != 0){
    int rem = q.remove();
    ans.add(rem);
            
    ArrayList<Integer> nbr = graph.get(rem);
    for(int i = 0; i < nbr.size(); i++){
      if(!visited[nbr.get(i)]){
        q.add(nbr.get(i));
        visited[nbr.get(i)] = true;
      }
    }
  }
        
 return ans;
 }
