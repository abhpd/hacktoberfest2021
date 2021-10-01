
```
import java.io.*;
import java.util.*;
class Main {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            String[] st = br.readLine().split(" ");
            int n = Integer.parseInt(st[0]);
            int m = Integer.parseInt(st[1]);
            if (n == 0 && m == 0) {
                return;
            }
            int[][] arr = new int[m][2];
            for (int i = 0; i < m; i++) {
                st = br.readLine().split(" ");
                arr[i][0] = Integer.parseInt(st[0]);
                arr[i][1] = Integer.parseInt(st[1]);
            }
            System.out.println(doctorStrange(n, m, arr));
        }
    }
    static int[] disc;
    static int[] low;
    static boolean[] vis;
    static int time;
    static int[] par;
    static boolean[] ap;
    public static int doctorStrange(int n, int k, int g[][]) {
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }
        for (int i = 0; i < g.length; i++) {
            int u = g[i][0];
            int v = g[i][1];
            graph.get(u).add(v);
            graph.get(v).add(u);
        }
        disc = new int[n + 1];
        low = new int[n + 1];
        vis = new boolean[n + 1];
        time = 0;
        par = new int[n + 1];
        ap = new boolean[n + 1];
        count = 0;
        articulationpoint(1, graph);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (ap[i] == true) {
                ans++;
            }
        }
        return ans;
    }
    static int count;
    public static void articulationpoint(int u, ArrayList<ArrayList<Integer>> graph) {
        disc[u] = low[u] = time;
        time++;
        vis[u] = true;
        ArrayList<Integer> nbrs = graph.get(u);
        for (int v : nbrs) {
            if (par[u] == v) {
                continue;
            } else if (vis[v] == true) {
                low[u] = Math.min(low[u], disc[v]);
            } else {
                par[v] = u;
                articulationpoint(v, graph);
                if (par[u] == 0) { // actual src
                    count++;
                    if (count >= 2) {
                        ap[u] = true;
                    }
                } else {
                    if (low[v] >= disc[u]) {
                        ap[u] = true;
                    }
                }
                low[u] = Math.min(low[u], low[v]);
            }
        }
    }
}
```
