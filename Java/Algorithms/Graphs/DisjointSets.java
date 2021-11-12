import java.lang.reflect.Array;
import java.util.*;
import java.util.stream.StreamSupport;

/**
 * Class to represent disjoint sets.
 */
public class DisjointSets {

    int[] sets;
    int[] rank;
    int n;

    DisjointSets(int n) {
        sets = new int[n];
        rank = new int[n];
        this.n = n;
        initialize();
    }

    // Initializing the base values and setting their rank.
    void initialize() {
        for(int i = 0; i < n; i++) {
            sets[i] = i;
            rank[i] = 0;
        }
    }

    /**
     * Method to identify the set based on the node value.
     * @param i : Value of the node
     * @return : Value of the node representing the set.
     */
    int findSet(int i) {

        if(sets[i] == i) {
            return i;
        }
        else {
            sets[i] = findSet(sets[i]);
            return sets[i];
        }
    }

    /**
     * Creates an edge between the 2 nodes and thus creates a single set out of 2 different sets.
     * @param i : Node 1
     * @param j : Node 2
     * @return : Returns true if two sets are merged and false if the two nodes were already part of a single set.
     * This method is also helpful in identifying a cycle within a graph.
     */
    boolean union(int i, int j) {

        //Step 1: Find the sets to which each node belongs i.e. the representative node.
        int pi = findSet(i);
        int pj = findSet(j);

        //Step 2 : If both of them have the same representative then they both belong to the same set already, no need to merge.
        // If this is an existing edge in a graph then a cycle is found.
        if(pi == pj) {
            return false;
        }

        //Step 3 : If they belong to different sets then merge to two sets based on their rank.
        if(rank[pi] > rank[pj]) {
            sets[pj] = pi;
        }
        else if(rank[pj] > rank[pi]){
            sets[pi] = pj;
        }
        else {
            sets[pj] = pi;
            rank[pi]++;
        }
        return true;
    }

    /**
     * Method to display all the different disjoint sets found.
     */
    void displaySets() {

        Map<Integer,Set<Integer>> map = new HashMap<Integer, Set<Integer>>();

        for(int i = 0; i < n; i++) {
            if(map.containsKey(findSet(i))) {
                map.get(sets[i]).add(i);
            }
            else {
                map.put(sets[i], new HashSet<Integer>(Arrays.asList(i)));
            }
        }
        System.out.println("--------------------------------------");
        for(Map.Entry<Integer,Set<Integer>> e : map.entrySet()) {
            System.out.print(e.getKey() + "  : { ");
            for(int i : e.getValue()) {
                System.out.print(i + " ");
            }
            System.out.println("}");
        }
        System.out.println("--------------------------------------");

    }

    //Main method to run.
    public static void main(String args[]) {

        //Display different sets formed.
        System.out.println("DS1");
        DisjointSets ds = new DisjointSets(10);

        ds.union(0,2);
        ds.union(1,3);
        ds.union(3,6);
        ds.union(7,8);
        ds.union(1,8);
        ds.union(9,2);

        ds.displaySets();

        //Find if a cycle exists in the following graph.
        /**
         *                                0 - 1 - 2 - 3 - 5
         *                                   |  /
         *                                   4
         */
        System.out.println("DS2");
        System.out.println("--------------------------------------");
        DisjointSets ds2 = new DisjointSets(6);
        int[][] edges = {{0,1}, {1,2}, {2,3}, {3,5}, {1,4}, {2,4}};

        for (int[] edge : edges) {
            if(!ds2.union(edge[0], edge[1])) {
                System.out.println("A cycle is found !!!");
            }
        }
        ds2.displaySets();
    }

}
