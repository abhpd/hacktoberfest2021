package com.technalaa.kosaraju;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.Deque;
import java.util.Scanner;
import java.util.TreeSet;
import java.util.zip.ZipFile;

import com.technalaa.kosaraju.DirectedGraph.EdgeTraversalPolicy;

/**
* https://class.coursera.org/algo/quiz/attempt?quiz_id=57
* 
* Reads the graph directly from the zip file
*/
public class KosarajuSCC {
   
   private static int t;
   private static ArrayList<Integer> scc = new ArrayList<Integer>();
   private static int pass = 0;
   private static Deque<DirectedVertex> deque;
   
   private static void dfsLoop( DirectedGraph gr, EdgeTraversalPolicy tp ) {
       t = 0;
       deque = new ArrayDeque<DirectedVertex>();
       
       Collection<DirectedVertex> vs; 
       if( pass == 0 ) 
           vs = gr.getVerticesInReversedOrder().values();
       else {
           vs = new TreeSet<DirectedVertex>(new Comparator<DirectedVertex>() {
               @Override
               public int compare( DirectedVertex v1, DirectedVertex v2 ) {
                   return new Integer( v2.getF() ).compareTo( v1.getF() );
               }
           });
           vs.addAll( gr.getVertices().values() );
       }
       
       for ( DirectedVertex v : vs ) {
           if( !v.isVisited() ) {
               v.setVisited(true);
   			deque.push(v);
               
               while (!deque.isEmpty()) {
   				v = deque.peek();
                   dfs( tp, v );
               }
               if( pass == 1 ) {
                   scc.add( t );
                   t = 0;
               }
           }
       }
       
       pass++;
   }
   
   private static void dfs( EdgeTraversalPolicy tp, DirectedVertex v ) {
       for ( DirectedEdge edge : tp.edges( v ) ) {
           DirectedVertex next = tp.vertex( edge );
           if( !next.isVisited() ) {
               next.setVisited(true);
   			deque.push(next);
				return;
           }
       }
       t++;
       if( pass == 0 ) {
           v.setF( t );
       }
       deque.pop();
   }
   
   private static DirectedGraph readGraph( InputStream is ) throws FileNotFoundException {
       Scanner sc = new Scanner( is );
       DirectedGraph gr = new DirectedGraph();
       while( sc.hasNext() ) {
           addEdge( gr, sc.nextInt(), sc.nextInt() );
       }
       sc.close();
       
       return gr;
   }
   
   private static void addEdge( DirectedGraph gr, int tailId, int headId ) {
       DirectedVertex tail = gr.getVertex( tailId );
       DirectedVertex head = gr.getVertex( headId );
       DirectedEdge edge = new DirectedEdge( tail, head );
       gr.addEdge( edge );
       tail.addOutgoingEdge( edge );
       head.addIncomingEdge( edge );
   }

   private static void test( DirectedGraph gr ) {
       System.out.println("First pass:");
       dfsLoop( gr, DirectedGraph.BACKWARD_TRAVERSAL );
       
       gr.reset();
       System.out.println("Second pass:");
       dfsLoop( gr, DirectedGraph.FORWARD_TRAVERSAL );
       
       int count = 0;
       Collections.sort( scc );
       for( int i = scc.size()-1; i >= 0; i-- ) {
           if( count >= 5 ) break;
           System.out.println("ssc:" + scc.get( i ));
           count++;
       }
       
       cleanup();
   }

   private static void cleanup() {
       t = 0;
       pass = 0;
       scc.clear();
   }
   
   private static DirectedGraph example1() {
       DirectedGraph gr = new DirectedGraph();
       addEdge( gr, 1, 2 );
       addEdge( gr, 1, 3 );
       addEdge( gr, 3, 4 );
       addEdge( gr, 2, 4 );
       return gr;
   }

   private static DirectedGraph example2() {
       DirectedGraph gr = new DirectedGraph();
       addEdge( gr, 1, 4 );
       addEdge( gr, 2, 8 );
       addEdge( gr, 3, 6 );
       addEdge( gr, 4, 7 );
       addEdge( gr, 5, 2 );
       addEdge( gr, 6, 9 );
       addEdge( gr, 7, 1 );
       addEdge( gr, 8, 5 );
       addEdge( gr, 8, 6 );
       addEdge( gr, 9, 3 );
       addEdge( gr, 9, 7 );
       return gr;
   }

   private static DirectedGraph example3()
           throws Exception {
       
       long start = System.currentTimeMillis();
       ZipFile zf = new ZipFile( "src/com/technalaa/kosaraju/SCC.zip" );
       DirectedGraph g = readGraph( zf.getInputStream( zf.getEntry( "SCC.txt" ) ) );
       
       System.out.println( "Read from ZIP: " + ( System.currentTimeMillis() - start ) );
       System.out.println( "Graph: " + g.getVertices().size() + " vertices, "
               + g.getEdges().size() + " edges." );
       return g;
   }
   
   /**
    * @param args
    * @throws IOException 
    */
   public static void main( String[] args ) throws Exception {
       
        test(example1());
        test(example2());
        test(example3());
   }

}
