/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package graphs;

/**
 *
 * @author Zohaib Hassan Soomro
 * implementataion DijkStra's algorithm  for finding shortest path using Priority Queue
 */
import java.util.*;
public class DPQ {
    private int dist[];   //distance
    private Set<Integer> settled;
    private PriorityQueue<Node> pq;
    private int v;	//number of vertices
    List<List<Node>>adj;

    public DPQ(int v){
    	this.v=v;
    	dist=new int[v];
    	settled=new HashSet<Integer>();
    	pq=new PriorityQueue<Node>(v,new Node());
    }

    //Function for Dijkstra's algo
    public void dijkstra(List<List<Node>> adj,int src){
    	this.adj=adj;
    	for (int i=0;i<v;i++) {
    		dist[i]=Integer.MAX_VALUE;

    		//add source node to priority queue
    		pq.add(new Node(src,0));

    		//Distance to the source is 0
    		dist[src]=0;
    		while(settled.size()!=v){

    			//remove minimum distance node from priority queue
    			int u=pq.remove().node;

    			//adding the node whose distance is finalized
    			settled.add(u);

    			e_Neighbours(u);
    		}
    	}
    }
//Function to process all neighbours of the passed node
    	private void e_Neighbours(int u){
    		int edgeDistance=-1;
    		int newDistance=-1;
    	
    		//all neighbours of v
    		for (int i=0;i<adj.get(u).size();i++) {
    			Node  v=adj.get(u).get(i);

    			//if current node hasn't already been processed
    			if(!settled.contains(v.node)){
    				edgeDistance=v.cost;
    				newDistance=dist[u]+edgeDistance;

					//if new distance is cheaper than cost
    				if(newDistance<dist[v.node])
    					dist[v.node]=newDistance;

    				//add current node to queue
    				pq.add(new Node(v.node,dist[v.node]));
    			}
    		}
    	}

    	

    //driver code
    public static void main(String[] args) {
    	int v=5;
    	int source=0;

    	//initialize List reperesentation of the connected edges
    	List<List<Node>> adj=new ArrayList<List<Node>>();

    	////initialize List for every node
    	for (int i=0;i<v;i++) {
    		List<Node> item=new ArrayList<Node>();
    		adj.add(item);
    	}

    		//inputs for DPQ graph
    		adj.get(0).add(new Node(1,9));
    		adj.get(0).add(new Node(2,6));
    		adj.get(0).add(new Node(3,5));
    		adj.get(0).add(new Node(4,3));
    		adj.get(2).add(new Node(1,2));
    		adj.get(2).add(new Node(3,4));

    		//calculate single source shortest path
    		DPQ dpq=new DPQ(v);
    		dpq.dijkstra(adj,source);


    		//print the shortest path to all the nodes from the source node
    		System.out.println("The shortest path from node : ");
    		for (int i=0;i<dpq.dist.length;i++) {
    			System.out.println(source+" to "+i+" is "+dpq.dist[i]);
    		}
   	}
}

class Node implements Comparator<Node>{
	public int node;public int cost;

	public Node(){}
	public Node(int node,int cost){
		this.node=node;
		this.cost=cost;
	}

	@Override
	public int compare(Node node1,Node node2){
		if(node1.cost < node2.cost)
			return -1;
		if(node1.cost > node2.cost)
			return 1;
		return 0;
	}
}
