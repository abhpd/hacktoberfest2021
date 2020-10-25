using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
 
namespace DijkstraAlgorithm
{
    public class Dijkstra
    {
        /*
        Dijkstra's algorithm is an algorithm for finding the shortest paths between nodes in a graph.
        It was conceived by computer scientist Edsger W. Dijkstra in 1956.
        This algorithm helps to find the shortest path from a point in a graph (the source) to a destination.
        */
        
        // A utility function to find the 
        // vertex with minimum distance 
        // value, from the set of vertices 
        // not yet included in shortest 
        // path tree
        private static int MinimumDistance(int[] distance, bool[] shortestPathTreeSet, int verticesCount)
        {
            // Initialize min value 
            int min = int.MaxValue;
            int minIndex = 0;
 
            for (int v = 0; v < verticesCount; ++v)
            {
                if (shortestPathTreeSet[v] == false && distance[v] <= min)
                {
                    min = distance[v];
                    minIndex = v;
                }
            }
 
            return minIndex;
        }
 
        // A utility function to print 
        // the constructed distance array 
        private static void Print(int[] distance, int verticesCount)
        {
            Console.WriteLine("Vertex    Distance from source");
 
            for (int i = 0; i < verticesCount; ++i)
                Console.WriteLine("{0}\t  {1}", i, distance[i]);
        }
 
        // Function that implements Dijkstra's 
        // single source shortest path algorithm 
        // for a graph represented using adjacency 
        // matrix representation 
        public static void DijkstraAlgo(int[,] graph, int source, int verticesCount)
        {
            int[] distance = new int[verticesCount]; // The output array. distance[i] 
            // will hold the shortest 
            // distance from src to i 
         
            // shortestPathTreeSet will true if vertex 
            // i is included in shortest path 
            // tree or shortest distance from 
            // src to i is finalized 
            bool[] shortestPathTreeSet = new bool[verticesCount];
 
            // Initialize all distances as 
            // INFINITE and shortestPathTreeSet[] as false 
            for (int i = 0; i < verticesCount; ++i)
            {
                distance[i] = int.MaxValue;
                shortestPathTreeSet[i] = false;
            }
 
            // Distance of source vertex 
            // from itself is always 0
            distance[source] = 0;
            
            // Find shortest path for all vertices
            for (int count = 0; count < verticesCount - 1; ++count)
            {
                // Pick the minimum distance vertex 
                // from the set of vertices not yet 
                // processed. u is always equal to 
                // src in first iteration. 
                int u = MinimumDistance(distance, shortestPathTreeSet, verticesCount);
             
                // Mark the picked vertex as processed
                shortestPathTreeSet[u] = true;
 
                // Update dist value of the adjacent 
                // vertices of the picked vertex.
                for (int v = 0; v < verticesCount; ++v)
                    // Update distance[v] only if is not in 
                    // shortestPathTreeSet, there is an edge from u 
                    // to v, and total weight of path 
                    // from src to v through u is smaller 
                    // than current value of distance[v] 
                    if (!shortestPathTreeSet[v] && Convert.ToBoolean(graph[u, v]) && distance[u] != int.MaxValue && distance[u] + graph[u, v] < distance[v])
                        distance[v] = distance[u] + graph[u, v];
            }
            
            // print the constructed distance array 
            Print(distance, verticesCount);
        }
 
        // Driver Code
        public static void Main(string[] args)
        {
            int[,] graph =  {
                         { 0, 6, 0, 0, 0, 0, 0, 9, 0 },
                         { 6, 0, 9, 0, 0, 0, 0, 11, 0 },
                         { 0, 9, 0, 5, 0, 6, 0, 0, 2 },
                         { 0, 0, 5, 0, 9, 16, 0, 0, 0 },
                         { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                         { 0, 0, 6, 0, 10, 0, 2, 0, 0 },
                         { 0, 0, 0, 16, 0, 2, 0, 1, 6 },
                         { 9, 11, 0, 0, 0, 0, 1, 0, 5 },
                         { 0, 0, 2, 0, 0, 0, 6, 5, 0 }
                            };
 
            DijkstraAlgo(graph, 0, 9);
        }
    }
}
