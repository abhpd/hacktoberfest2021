//srishti1302
import java.util.*;

// A class to represent a connected, directed and weighted graph
class bellman {
        // A class to represent a weighted edge in graph
        class Edge {
                int src, dest, weight;
                Edge()
                {
                        src = dest = weight = 0;
                }
        }

        int V, E;
        Edge edge[];

        // Creates a graph with V vertices and E edges
        bellman(int v, int e)
        {
                V = v;
                E = e;
                edge = new Edge[e];
                for (int i = 0; i < e; ++i)
                        edge[i] = new Edge();
        }

        // The main function that finds shortest distances from src
        // to all other vertices using Bellman-Ford algorithm. The
        // function also detects negative weight cycle
        void BellmanFord(bellman graph, int src)
        {
                int V = graph.V, E = graph.E;
                int dist[] = new int[V];

                // Step 1: Initialize distances from src to all other
                // vertices as INFINITE
                for (int i = 0; i < V; ++i)
                        dist[i] = Integer.MAX_VALUE;
                dist[src] = 0;

                // Step 2: Relax all edges |V| - 1 times. A simple
                // shortest path from src to any other vertex can
                // have at-most |V| - 1 edges
                for (int i = 1; i < V; ++i) {
                        for (int j = 0; j < E; ++j) {
                                int u = graph.edge[j].src;
                                int v = graph.edge[j].dest;
                                int weight = graph.edge[j].weight;
                                if (dist[u] != Integer.MAX_VALUE && dist[u] + weight < dist[v])
                                        dist[v] = dist[u] + weight;
                        }
                }

                // Step 3: check for negative-weight cycles. The above
                // step guarantees shortest distances if graph doesn't
                // contain negative weight cycle. If we get a shorter
                // path, then there is a cycle.
                for (int j = 0; j < E; ++j) {
                        int u = graph.edge[j].src;
                        int v = graph.edge[j].dest;
                        int weight = graph.edge[j].weight;
                        if (dist[u] != Integer.MAX_VALUE && dist[u] + weight < dist[v]) {
                                System.out.println("Graph contains negative weight cycle");
                                return;
                        }
                }
                printArr(dist, V);
        }

        // A utility function used to print the solution
        void printArr(int dist[], int V)
        {
                System.out.println("Vertex Distance from Source");
                for (int i = 0; i < V; ++i)
                        System.out.println(i + "\t\t" + dist[i]);
        }

        // Driver method to test above function
        public static void main(String[] args)
        {       Scanner s=new Scanner(System.in);
        System.out.println("Enter number of vertices n edges");
                int V = s.nextInt(); // Number of vertices in graph
                int E = s.nextInt(); // Number of edges in graph

                bellman graph = new bellman(V, E);
                for(int i=0;i<E;i++)
                {       System.out.println("Enter sirce destinaion n weight for edge"+ i);
                        graph.edge[i].src=s.nextInt();
                        graph.edge[i].dest=s.nextInt();
                        graph.edge[i].weight=s.nextInt();
                }

                graph.BellmanFord(graph, 0);
                s.close();
        }
}

