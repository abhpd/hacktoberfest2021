/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package graphs;

/**
 *
 * @author Zohaib Hassan Soomro
 */
public class MyGraph {
    int size;
    String[] vertices;
    boolean[][] a;	//adjacency matrix
    public MyGraph(String args[]){
    	size=args.length;
    	vertices=new String[size];
    	System.arraycopy(args,0,vertices,0,size);
    	a=new boolean[size][size];
    }
   	public void add(String v,String w){
   		int i=index(v),j=index(w);
   		a[i][j]=a[j][i]=true;
   	}
   	private int index(String v){
   		for (int i=0;i<size;i++) {
   			if(vertices[i].equals(v)) return i;
   		}
   		return -1;
   	}
   	public String toString(){
   		if(size==0) return "{}";
   		String buf="{"+vertex(0);
   		for (int i=1;i<size;i++) {
   			buf+=","+vertex(i);
   		}return buf+"}";
   		
   	}

   	private String vertex(int i){
   		String buf=vertices[i]+":";
   		for (int j=0;j<size;j++) {
   			if(a[i][j])
   				buf+=vertices[j];
   		}
   		return buf;
   	}

   	public static void main(String[] args) {
   		MyGraph graph=new MyGraph(new String[]{"A","B","C","D","E"});
   		System.out.println(graph);
   		graph.add("A","B");
   		graph.add("A","C");
   		graph.add("B","C");
   		graph.add("B","D");
   		graph.add("C","D");
   		graph.add("D","E");
   		System.out.println(graph);
   	}

}
