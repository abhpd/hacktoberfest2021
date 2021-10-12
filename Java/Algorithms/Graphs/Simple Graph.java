// created a Simple graph using the methods defined 

Graph createGraph() {
    Graph graph = new Graph();
    graph.addVertex("Bobby");
    graph.addVertex("Alic");
    graph.addVertex("Marry");
    graph.addVertex("Robin");
    graph.addVertex("Maria");
    graph.addEdge("Bobby", "Alic");
    graph.addEdge("Bobby", "Robin");
    graph.addEdge("Alic", "Marry");
    graph.addEdge("Robin", "Marry");
    graph.addEdge("Alic", "Maria");
    graph.addEdge("Robin", "Maria");
    return graph;
}