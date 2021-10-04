import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
 

class Edge
{
    int src, dest;
 
    Edge(int src, int dest)
    {
        this.src = src;
        this.dest = dest;
    }
}
 

class Graph
{
    List<List<Integer>> adj = new ArrayList<>();
 

    public Graph(List<Edge> edges)
    {
        int n = 0;
        for (Edge e: edges) {
            n = Integer.max(n, Integer.max(e.src, e.dest));
        }
 
       t
        for (int i = 0; i <= n; i++) {
            adj.add(i, new ArrayList<>());
        }
 
        for (Edge current: edges)
        {
            
            adj.get(current.src).add(current.dest);
 
          
        }
    }
 
    
    public static void printGraph(Graph graph)
    {
        int src = 0;
        int n = graph.adj.size();
 
        while (src < n)
        {
          
            for (int dest: graph.adj.get(src)) {
                System.out.print("(" + src + " ——> " + dest + ")\t");
            }
            System.out.println();
            src++;
        }
    }
}
 
class Main
{
    public static void main (String[] args)
    {
        List<Edge> edges = Arrays.asList(new Edge(0, 1), new Edge(1, 2),
                new Edge(2, 0), new Edge(2, 1), new Edge(3, 2),
                new Edge(4, 5), new Edge(5, 4));
 
       
        Graph graph = new Graph(edges);
 
        
        Graph.printGraph(graph);
    }
}
