import java.util.*;

public class Prims {
    private static int V = 5;

    public static void main(String[] args) {
        PrimsMST object = new PrimsMST();
        int[][] graph = new int[][] { { 0, 2, 0, 6, 0 }, { 2, 0, 3, 8, 5 }, { 0, 3, 0, 0, 7 }, { 6, 8, 0, 0, 9 },
                { 0, 5, 7, 9, 0 } };
        object.prims(graph);
    }

    void prims(int[][] graph) {
        int[] parent = new int[V];
        int key[] = new int[V];
        boolean[] mst = new boolean[V];
        Arrays.fill(key, Integer.MAX_VALUE);
        Arrays.fill(mst, false);
        key[0] = 0;
        parent[0] = -1;

        for (int i = 0; i < V - 1; i++) {
            int u = minKey(key, mst);
            mst[u] = true;

            for (int v = 0; v < V; v++) {
                if (graph[u][v] != 0 && !mst[v] && graph[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = graph[u][v];
                }
            }
        }

        printMst(parent, graph);
    }

    int minKey(int[] key, boolean[] mst) {
        int index = -1;
        int minValue = Integer.MAX_VALUE;

        for (int v = 0; v < V; v++) {
            if (!mst[v] && key[v] < minValue) {
                minValue = key[v];
                index = v;
            }
        }
        return index;
    }

    void printMst(int[] parent, int[][] graph) {
        for (int i = 1; i < V; i++) {
            System.out.println(parent[i] + " - " + i + " : " + graph[i][parent[i]]);
        }
    }

}