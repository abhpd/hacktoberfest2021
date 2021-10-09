#Implementation of depth-first-search algorithm for traversing graphs

#In dfs, we traverse the given graph in greedy approach,
#  which means we will continuously choose any node and visit the node, 
#  and suspend the exploration of the current node
#  if we will reach the leaf node then we will backtrack to nearest suspended nodes
# and continue for other nodes in same greedy manner


def dfs (lst, source):     # declaration of the dfs function which takes "adjacencyList" and "source" as arguments

  visited = {}           # this dictionary keeps tracks of the nodes visited 

  for x in lst.keys():
    visited[x] = False   # initially all the nodes are unvisited

  nodes_visited = []     # this list will store the nodes in sequence which will be visited during dfs 

    # the below recursive_dfs function is defined under dfs and hence can access "visited" and "nodes_visited" declared earlier

  def recursive_dfs(node):         # declare the recursive dfs function for any given node
  
    if visited[node]:    # returns from the function if the node has been visited earlier
      return            
  
    visited[node] = True            # set the node which is to be explored as visited
    nodes_visited.append(node)      # append the node to he list of nodes_visited

    for x in lst[node]:             # for every node in neighbour of the current node 
      recursive_dfs(x)                        # suspend the exploration of the current node and explore the selected neighbour node recursively

    return                          # return from the function if all neighbour nodes has been visited

  recursive_dfs(source)                        # call the recursive dfs function starting from source node 

  return nodes_visited          # get the sequence of the nodes_visited during dfs