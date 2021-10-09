#Implementation of breadth-first-search algorithm for traversing graphs

#In bfs, we traverse the given graph level by level,
#  which means we will first visit all the nodes, which are one edge distant from the source
#  then the vertices which are two edges distant and so on......


def bfs (lst, node):     # declaration of the bfs function which takes "adjacencyList" and "source" as arguments

  visited = {}           # this dictionary keeps tracks of the nodes visited 

  for x in lst.keys():
    visited[x] = False   # initially all the nodes are unvisited

  nodes_visited = []     # this list will store the nodes in sequence which will be visited during bfs 

  queue = []             # this queue will give us the next node to be explored
  visited[node] = True          # set the visited[source] to be true
  queue.append(node)            # append the "source node" to the queue
  nodes_visited.append(node)    # append the first node which visited which is the source node

  while queue != []:            # explore the nodes till the queue has nodes
    next = queue.pop(0)         # get the next node to be explored as the first element of the queue

    for x in lst[next]:         # check for the nodes connected to the next node
      if not visited[x]:        # if the neighbours of the next node has not been visited till now,  
        visited[x] = True       # make them visited
        nodes_visited.append(x) # add them to the nodes visited
        queue.append(x)         # and append them to the queue which will be explored in next level (loop)


  return nodes_visited          # get the sequence of the nodes_visited during bfs