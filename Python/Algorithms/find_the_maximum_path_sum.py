dp = [0]*100
 
# Function for dfs traversal and
# to store the maximum value in
# dp[] for every node till the leaves
def dfs(a, v, u, parent):
     
    # Initially dp[u] is always a[u]
    dp[u] = a[u - 1]
     
    # Stores the maximum value from nodes
    maximum = 0
     
    # Traverse the tree
    for child in v[u]:
         
        # If child is parent, then we continue
        # without recursing further
        if child == parent:
            continue
         
        # Call dfs for further traversal
        dfs(a, v, child, u)
         
        # Store the maximum of previous visited 
        # node and present visited node
        maximum = max(maximum, dp[child])
         
    # Add the maximum value
    # returned to the parent node
    dp[u] += maximum
 
 
# Function that returns the maximum value
def maximumValue(a, v):
    dfs(a, v, 1, 0)
    return dp[1]
 
# Driver Code
def main():
     
    # Number of nodes
    n = 14
     
    # Adjacency list as a dictionary
    v = {}
    for i in range(n + 1):
        v[i] = []
         
    # Create undirected edges
    # initialize the tree given in the diagram
    v[1].append(2), v[2].append(1)
    v[1].append(3), v[3].append(1)
    v[1].append(4), v[4].append(1)
    v[2].append(5), v[5].append(2)
    v[2].append(6), v[6].append(2)
    v[3].append(7), v[7].append(3)
    v[4].append(8), v[8].append(4)
    v[4].append(9), v[9].append(4)
    v[4].append(10), v[10].append(4)
    v[5].append(11), v[11].append(5)
    v[5].append(12), v[12].append(5)
    v[7].append(13), v[13].append(7)
    v[7].append(14), v[14].append(7)
     
    # Values of node 1, 2, 3....14
    a = [ 3, 2, 1, 10, 1, 3, 9,
          1, 5, 3, 4, 5, 9, 8 ]
     
    # Function call
    print(maximumValue(a, v))
main()
