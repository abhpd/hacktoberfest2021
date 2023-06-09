public class Prims {
    public static void main(String[] args){
        MinimumSpanningTreeExample mst = new MinimumSpanningTreeExample();
        int graphArray[][] = new int[][]{   { 0, 2, 0, 1, 4, 0, 0 },
                { 2, 0, 5, 0, 0, 0, 0 },
                { 0, 5, 0, 2, 0, 4, 0 },
                { 1, 0, 2, 0, 0, 0, 0 },
                { 4, 0, 0, 0, 0, 3, 6 },
                { 0, 0, 4, 0, 3, 0, 2 },
                { 0, 0, 0, 0, 6, 2, 0 }};
        mst.designMST(graphArray);
    }

    static class MinimumSpanningTreeExample{
        private static final int countOfVertices = 7;
        int findMinKeyVertex(int keys[], Boolean MST[]) {
            int minIndex = -1;
            int minValue = Integer.MAX_VALUE;

            for (int v = 0; v < countOfVertices; v++)
                if (MST[v] == false && keys[v] < minValue) {
                    minValue = keys[v];
                    minIndex = v;
                }

            return minIndex;
        }

        void showMinimumSpanningTree(int mstArray[], int graphArray[][]) {
            System.out.println("Edge \t\t Weight");
            for (int j = 1; j < countOfVertices; j++)
                System.out.println(mstArray[j] + " <--> " + j + "\t \t" + graphArray[j][mstArray[j]]);
        }

        void designMST(int graphArray[][]) {
            int parent[] = new int[countOfVertices];
            int key[] = new int[countOfVertices];
            Boolean MST[] = new Boolean[countOfVertices];

            for (int j = 0; j < countOfVertices; j++) {
                key[j] = Integer.MAX_VALUE;
                MST[j] = false;
            }

            key[0] = 0;
            parent[0] = -1;

            for (int i = 0; i < countOfVertices - 1; i++) {
                int e = findMinKeyVertex(key, MST);
                MST[e] = true;

                for (int v = 0; v < countOfVertices; v++)
                    if (graphArray[e][v] != 0 && MST[v] == false && graphArray[e][v] < key[v]) {
                        parent[v] = e;
                        key[v] = graphArray[e][v];
                    }
            }
            showMinimumSpanningTree(parent, graphArray);
        }

    }
}
