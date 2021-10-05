package Graphs;
import java.util.*;
public class prims {
    public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    int e = scanner.nextInt();
    int[][] edges = new int[n][n];
        for(int i = 0;i<e;i++)

    {
        int sv = scanner.nextInt();
        int ev = scanner.nextInt();
        int weight = scanner.nextInt();
        edges[sv][ev] = weight;
        edges[ev][sv] = weight;
    }

    prim(edges);
}
public static void prim(int edges[][])
{
    int parent[]=new int[edges.length];
    boolean visited[]=new boolean[edges.length];
    int weight[]=new int[edges.length];

    parent[0]=-1;
    weight[0]=0;
    for(int i=1;i< edges.length;i++)
        weight[i]=Integer.MAX_VALUE;

    for(int i=1;i< edges.length;i++)
    {
        int minvertex=findmin(weight,visited);
        visited[minvertex]=true;
        for(int j=0;j< edges.length;j++)
        {
            if(edges[minvertex][j]!=0 && !visited[j])
            {
                if(edges[minvertex][j]<weight[j])
                {
                    weight[j]=edges[minvertex][j];
                    parent[j]=minvertex;
                }
            }
        }
    }
    for(int i=1;i<weight.length;i++) {
        if( i > parent[i])
            System.out.println( parent[i] +" " + i+" " +weight[i]  );
        else
            System.out.println( i +" " + parent[i]+" " +weight[i]  );
    }

}
public static int findmin(int weight[],boolean visited[])
{
    int mini=0;
    int minweight=Integer.MAX_VALUE;
    for(int i=0;i<weight.length;i++)
    {
        if(!visited[i] && minweight>weight[i])
        {
            minweight=weight[i];
            mini=i;
        }
    }
    return mini;
}

}
