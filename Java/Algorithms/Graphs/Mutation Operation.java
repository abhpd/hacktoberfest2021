// adding and removing elements from vertices Set

void addVertex(String label) {
    adjVertices.putIfAbsent(new Vertex(label), new ArrayList<>());
}

void removeVertex(String label) {
    Vertex v = new Vertex(label);
    adjVertices.values().stream().forEach(e -> e.remove(v));
    adjVertices.remove(new Vertex(label));
}

// defined a method to add a edge

void addEdge(String label1, String label2) {
    Vertex v1 = new Vertex(label1);
    Vertex v2 = new Vertex(label2);
    adjVertices.get(v1).add(v2);
    adjVertices.get(v2).add(v1);
}

// defined the removeEdge() method:

void removeEdge(String label1, String label2) {
    Vertex v1 = new Vertex(label1);
    Vertex v2 = new Vertex(label2);
    List<Vertex> eV1 = adjVertices.get(v1);
    List<Vertex> eV2 = adjVertices.get(v2);
    if (eV1 != null)
        eV1.remove(v2);
    if (eV2 != null)
        eV2.remove(v1);
}