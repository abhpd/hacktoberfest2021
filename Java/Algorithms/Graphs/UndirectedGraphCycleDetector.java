import java.util.*;


public class UndirectedGraphCycleDetector {
    public static ArrayList<ArrayList<Integer>> graph = new ArrayList<ArrayList<Integer>>();
    public static ArrayList<Boolean> visited = new ArrayList<Boolean>();

    public UndirectedGraphCycleDetector(int verticesCount) {
        for (int i = 0; i < verticesCount+10; i++) {
            graph.add(new ArrayList<Integer>());
            visited.add(false);
        }
    }

    public void addEdge(int from, int to) {
        graph.get(from).add(to);
        graph.get(to).add(from);
    }

    public int getCycles(int currentVertex, int parent) {
        int cycles = 0;
        visited.set(currentVertex, Boolean.TRUE);
        for (Integer child: graph.get(currentVertex)) {
            if (child == parent) {continue;}
            if (visited.get(child)) {cycles++;}
            else {getCycles(child, currentVertex);}
        }
        return 0 + cycles;
    }

    public static void main(String[] args) {
        int n = 6;
        UndirectedGraphCycleDetector graph = new UndirectedGraphCycleDetector(n);
        graph.addEdge(1, 2);
        graph.addEdge(2, 3);
        graph.addEdge(3,1);
        graph.addEdge(2, 4);
        // test: answer sould be 1
        System.out.println(graph.getCycles(1, -1));
    }
}
