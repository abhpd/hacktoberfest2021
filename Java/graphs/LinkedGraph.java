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
public class LinkedGraph {
    int size;
    List[]  a;	////adjacency list

    public LinkedGraph(String args[]){
    	size=args.length;
    	a=new List[size];
    	for (int i=0;i<size;i++) 
    		a[i]=new List(args[i]);
    	
    }

    private class List{
    	String vertex;
    	Node edges;

    	private class Node{
    		int to;
    		Node next;

    		Node(int t,Node n){
    			to=t;  
    			next=n;
    		}
    	}

    	public List(String v){
    		vertex=v;
    	}

    	public void add(int j){
    		edges=new Node(j,edges);
    	}
    	public String toString(){
    		String buf=vertex;
    		if(edges!=null) buf+=":";
    		for (Node p=edges;p!=null;p=p.next)
    			buf+=(LinkedGraph.this.a[p.to].vertex);
    		return buf;
    	}
    }	//list class ended


   	public void add(String v,String w){
   		a[index(v)].add(index(w));
   		a[index(w)].add(index(v));	//a[i][j]=a[j][i]
   	}

   	private int index(String v){
   		for (int i=0;i<size;i++) {
   			if(a[i].vertex.equals(v)) return i;
   		}
   		return -1;
   	}
   	public String toString(){
   		if(size==0) return "{}";
   		String buf="{"+a[0];
   		for (int i=1;i<size;i++) 
   			buf+=","+a[i];
   		
   		return buf+"}";
   	}

   	
   	public static void main(String[] args) {
   		LinkedGraph graph=new LinkedGraph(new String[]{"A","B","C","D","E"});
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
