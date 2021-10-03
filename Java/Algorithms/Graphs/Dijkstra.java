import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Set;
import java.util.List;
import java.util.Map;

class GraphNode {
    private String name;
    private List<GraphNode> shortestPath = new LinkedList<GraphNode>();
    private Integer distance = Integer.MAX_VALUE;
    Map<GraphNode, Integer> adjNodes = new HashMap<>();
    
    public void addDestination (GraphNode node, int dist) {
        this.adjNodes.put(node, dist);
    }
    public GraphNode(String name) {
        this.name = name;
    }

    public Map<GraphNode, Integer> getAdjNodes() {
        return adjNodes;
    }
    public void setAdjNodes(Map<GraphNode, Integer> adjNodes) {
        this.adjNodes = adjNodes;
    }

    public Integer getDistance() {
        return distance;
    }
    public void setDistance(Integer distance) {
        this.distance = distance;
    }
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public List<GraphNode> getShortestPath() {
        return shortestPath;
    }
    public void setShortestPath(List<GraphNode> shortestPath) {
        this.shortestPath = shortestPath;
    }
}


class Graph {
   private Set<GraphNode> nodes = new HashSet<>();

   public void addNode(GraphNode nodeA) {
       this.nodes.add(nodeA);
   }

   public Set<GraphNode> getNodes() {
       return nodes;
   }
   public void setNodes(Set<GraphNode> nodes) {
       this.nodes = nodes;
   }
}


public class Dijkstra {
    
    public static Graph calculateShortestPathFromSource(Graph graph, GraphNode source) {
        source.setDistance(0);

        Set<GraphNode> settledNodes = new HashSet<>();
        Set<GraphNode> unsettledNodes = new HashSet<>();
        unsettledNodes.add(source);

        while (unsettledNodes.size()!=0) {
            GraphNode currentNode = getShortestDistanceNode(unsettledNodes);
            unsettledNodes.remove(currentNode);
            for(java.util.Map.Entry<GraphNode, Integer> adjancyPair : currentNode.getAdjNodes().entrySet() ) {
                GraphNode adjNode = adjancyPair.getKey();
                Integer edgeWt = adjancyPair.getValue();
                if(!settledNodes.contains(adjNode)) {
                    calculateMinimumDistance(adjNode,edgeWt,currentNode);
                    unsettledNodes.add(adjNode);
                }
                settledNodes.add(currentNode);
            }
        }

        return graph;
    }

    private static void calculateMinimumDistance (GraphNode adjNode, Integer edgeWt, GraphNode currentNode ){
        Integer sourceDistance = currentNode.getDistance();
        if(sourceDistance + edgeWt < adjNode.getDistance()) {
            adjNode.setDistance(sourceDistance+edgeWt);
            LinkedList<GraphNode> shortestPath = new LinkedList<>(currentNode.getShortestPath());
            shortestPath.add(adjNode);
            adjNode.setShortestPath(shortestPath);
        }
    }


    private static GraphNode getShortestDistanceNode(Set<GraphNode> unsettledNodes) {
        GraphNode lowestDistanceNode = null;
        Integer lowestDistance = Integer.MAX_VALUE;
        for(GraphNode node : unsettledNodes) {
            if(node.getDistance() < lowestDistance) {
                lowestDistance = node.getDistance();
                lowestDistanceNode = node;
            }
        }
        return lowestDistanceNode;
    }

    public static void main(String[] args) {
        GraphNode nodeA = new GraphNode("A");
        GraphNode nodeB = new GraphNode("B");
        GraphNode nodeC = new GraphNode("C");
        GraphNode nodeD = new GraphNode("D");
        GraphNode nodeE = new GraphNode("E");
        GraphNode nodeF = new GraphNode("F");
        
        nodeA.addDestination(nodeB, 10);
        nodeA.addDestination(nodeC, 15);

        nodeB.addDestination(nodeD, 12);
        nodeB.addDestination(nodeF, 15);

        nodeC.addDestination(nodeE, 10);

        nodeD.addDestination(nodeE, 2);
        nodeD.addDestination(nodeF, 1);

        nodeF.addDestination(nodeE, 5);

        Graph graph = new Graph();

        graph.addNode(nodeA);
        graph.addNode(nodeB);
        graph.addNode(nodeC);
        graph.addNode(nodeD);
        graph.addNode(nodeE);
        graph.addNode(nodeF);

        graph = Dijkstra.calculateShortestPathFromSource(graph, nodeA);
        System.out.println(nodeB.getDistance());
    }

}
