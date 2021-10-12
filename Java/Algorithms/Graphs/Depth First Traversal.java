// defined a method to perform the depth-first traversal

Set<String> depthFirstTraversal(Graph graph, String root) {
    Set<String> visited = new LinkedHashSet<String>();
    Stack<String> stack = new Stack<String>();
    stack.push(root);
    while (!stack.isEmpty()) {
        String vertex = stack.pop();
        if (!visited.contains(vertex)) {
            visited.add(vertex);
            for (Vertex v : graph.getAdjVertices(vertex)) {              
                stack.push(v.label);
            }
        }
    }
    return visited;
}