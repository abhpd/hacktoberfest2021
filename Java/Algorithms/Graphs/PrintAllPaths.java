import java.io.*;
import java.util.*;

//Print all possible path from src to dest

public class Main {
   static ArrayList<String> res = new ArrayList<>();
   static class Edge {
      int src; 
      int nbr;
      int wt;

      Edge(int src, int nbr, int wt) {
         this.src = src;
         this.nbr = nbr;
         this.wt = wt;
      }
   }
   public static void searchPath(ArrayList<Integer> path, ArrayList<Edge>[] graph, int start, int end,boolean[] vis){
        if(start==end){
            String s = "";
            for(int x : path)
                s+=x;
            res.add(s);
            return; 
        }
        // if(vis[start])
        //     return;
        vis[start] = true;
        for(int i=0;i<graph[start].size();i++){ 
            Edge e = graph[start].get(i);
            if(!vis[e.nbr]){
                path.add(e.nbr);
                searchPath(path,graph,e.nbr,end,vis); 
                path.remove(path.size()-1); 
            }        
        }
        vis[start] = false;
        return;
    }

   public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

      int vtces = Integer.parseInt(br.readLine());
      ArrayList<Edge>[] graph = new ArrayList[vtces];
      for (int i = 0; i < vtces; i++) {
         graph[i] = new ArrayList<>();
      }

      int edges = Integer.parseInt(br.readLine());
      for (int i = 0; i < edges; i++) {
         String[] parts = br.readLine().split(" ");
         int v1 = Integer.parseInt(parts[0]);
         int v2 = Integer.parseInt(parts[1]);
         int wt = Integer.parseInt(parts[2]);
         graph[v1].add(new Edge(v1, v2, wt)); //storing neighbours
         graph[v2].add(new Edge(v2, v1, wt));
      }

      int src = Integer.parseInt(br.readLine());
      int dest = Integer.parseInt(br.readLine());

      boolean[] vis = new boolean[graph.length];
      ArrayList<Integer> path = new ArrayList<>();
      path.add(src);
      searchPath(path,graph, src, dest,vis); 
      Collections.sort(res);
      for(String s : res)
        System.out.println(s);
        res = new ArrayList<>();
   }


}