package Graphs;

import java.util.Arrays;
import java.util.Scanner;

public class kruskal {
    static class Edge implements Comparable<Edge>
    {
        int source;
        int dest;
        int weight;
        @Override
        public int compareTo(Edge o) {
            return this.weight-o.weight;
        }
    }
    public static void main(String args[]) {
        Scanner s=new Scanner(System.in);
        int v=s.nextInt();
        int e=s.nextInt();
        Edge input[]=new Edge[e];
        for(int i=0;i<e;i++)
        {
            input[i]=new Edge();
            input[i].source=s.nextInt();
            input[i].dest=s.nextInt();
            input[i].weight=s.nextInt();
        }
        kruskals(input,v);
    }
    public static void kruskals(Edge[] input,int v)
    {
        Arrays.sort(input);
        Edge[] output=new Edge[v-1];
        int parent[]=new int[v];
        for(int i=0;i<v;i++)
            parent[i]=i;

        int c=0;
        int i=0;
        while(c != v-1)
        {
            Edge current=input[i];
            int sourceP=findp(input[i].source,parent);
            int destp=findp(input[i].dest,parent);
            if(sourceP != destp)
            {
                output[c]=current;
                c++;
                parent[sourceP]=destp;
            }
            i++;
        }
        for(int j=0;j<v-1;j++) {
            if(output[j].source < output[j].dest) {
                System.out.println(output[j].source + " " + output[j].dest + " "+ output[j].weight);
            }else {
                System.out.println(output[j].dest + " " + output[j].source + " "+ output[j].weight);
            }
        }

    }
    public static int findp(int source,int parent[])
    {
        if(parent[source]==source)
            return source;

        return findp(parent[source],parent);
    }
}
