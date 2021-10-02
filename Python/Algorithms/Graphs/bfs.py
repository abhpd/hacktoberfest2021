from collections import defaultdict
class Graph:
    def __init__(self):
        self.graph=defaultdict(list)
    def addEdge(self,u,v):
        self.graph[u].append(v)
    def printg(self):
        print(self.graph)
    def bfs(self,s):
        q=[]
        visited=[False]*len(self.graph)
        q.append(s)
        visited[s]=True
        while q:
            k=q.pop(0)
            print(k,end=" ")
            for i in self.graph[k]:
                if visited[i]==False:
                    q.append(i)
                    visited[i]=True
g=Graph()
g.addEdge(0, 1) 
g.addEdge(0, 2) 
g.addEdge(1, 2) 
g.addEdge(2, 0) 
g.addEdge(2, 3) 
g.addEdge(3, 3)
g.printg()
g.bfs(2)
