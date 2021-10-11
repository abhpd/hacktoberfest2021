# Author: Manuel Di Lullo
# Python Version: 3.9

"""
**********************************
            CLASSES
**********************************
"""
# This class represents a directed graph using adjacency list representation
class Graph:

    def __init__(self, vertices):
        # number of vertices
        self.V = vertices
        # adjacency list
        self.adj = {x: [] for x in range(vertices)}

    # function to add an edge to graph
    def addEdge(self, u, v):
        if not self.hasEdge(u, v):
            self.adj[u].append(v)
        if not self.hasEdge(v, u):
            self.adj[v].append(u)

    # function to check if edge (u,v) is in graph
    def hasEdge(self, u, v):
        if v in self.adj[u]:
            return True
        return False

    # function that returns a list of all the vertices in graph
    def getVertices(self):
        return list(self.adj.keys())

    # function that returns a set of couples that represents
    #  the set of all the edges
    def getEdges(self):
        edges = set()
        for u in self.adj.keys():
            for v in self.adj[u]:
                edges.add((u, v))
        return edges

    # print adjacency list representation of graph
    def printGraph(self):
        # print current vertex and all its neighboring vertices
        for u in range(self.V):
            print(f"({u} -> ", end="")
            for v in self.adj[u]:
                print(f", {v} ", end="")
            print(")")


# Directed Graph class, extends Graph class
class DiGraph(Graph):
    def __init__(self, vertices):
        Graph.__init__(vertices)

    # function to add an edge to graph
    def addEdge(self, u, v):
        if self.hasEdge(u, v):
            self.adj[u].append(v)

"""
**********************************
            ALGORITHM
**********************************
"""
import heapq

# APX Algorithm for min Vertex Cover
#   GREEDY STRATEGY
def greedy_minVertexCover(graph):
    # s = set of chosen vertices
    S = set()
    # queue used to store nodes and their rank
    queue = []

    # for each node and his adjacency list
    #   add them and the rank of the node to queue
    # using heapq module the queue will be filled like
    #  a Priority Queue
    # heapq works with a min priority queue, so I used -1*len(v)
    #   to build it
    for k, v in graph.adj.items():
        # O(log(n))
        heapq.heappush(queue, [-1 * len(v), (k, v)])

    # while queue isn't empty and there are still edges
    #   (queue[0][0] is the rank of the node with max rank)
    while queue and not queue[0][0] == 0:
        # extract vertex with max rank from queue
        #  and add it to s
        argmax = heapq.heappop(queue)[1][0]
        S.add(argmax)

        # Remove all arcs adjacent to argmax
        for elem in queue:
            # if v haven't adjacent node, skip
            if elem[0] == 0:
                continue
            # if argmax is reachable from elem
            #   remove argmax from elem's adjacent list and update his rank
            if argmax in elem[1][1]:
                index = elem[1][1].index(argmax)
                del (elem[1][1][index])
                elem[0] += 1
        # re-order the queue
        heapq.heapify(queue)
    return S
