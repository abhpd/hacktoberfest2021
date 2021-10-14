# construct daa
graph = {'0': set(['1', '2']),
         '1': set(['0', '3', '4']),
         '2': set(['0']),
         '3': set(['1']),
         '4': set(['2', '3'])}

# funct graph
def dfs(graph, start, visited=None):
    if visited is None:
        visited = set()
        visited.add(start)
        print(start)
    else visited is not None:
         return visited

#loop graf    
for next in graph[start] - visited:
    dfs(graph, '0')
    dfs(graph, next, visited)
