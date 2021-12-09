def hill_climbing(graph, goal, starting,type):
    if type == "minimization":
        text = "minima"
    if type == "maximization":
        text = "maxima"
    x = 0
    print()
    print(graph)
    if goal not in graph:
        print("wrong node entered")
        return
    explored = [starting]  # explored nodes
    node = starting  # current node
    while True:
        neighbours = graph[node]
        res = not bool(neighbours)
        if res:
            if goal in explored:
                print("\nThe node has been found at Global "+text+" : "+''.join([str(elem) for elem in explored]))
            else:
                print("\nThe node has been found at Local "+text+" : "+''.join([str(elem) for elem in explored]))
            return
        if type == "minimization":
            max_node = min(neighbours, key=neighbours.get)
        else:
            max_node = max(neighbours, key=neighbours.get)
        y = int(neighbours[max_node])
        if x == y:
            print("\nYou have reached the Plateau region : "+''.join([str(elem) for elem in explored]))
            return
        if type == "maximization":
            if y < x:
                print("\nThe node has been found at Local " + text + " : " + ''.join([str(elem) for elem in explored]))
                return
        else:
            if y > x:
                print("\nThe node has been found at Local " + text + " : " + ''.join([str(elem) for elem in explored]))
                return
        explored.append(max_node)
        node = max_node
        x = y


n = int(input("enter number of nodes : "))
graph = {}
subgraph = {}
for i in range(n):
    key = input("enter the node : ")
    # child_count = int(input("enter number of child nodes : "))
    child_count = 10
    for x in range(child_count):
        child = input("enter the child node : ")
        if child == "":
            break
        child_value = int(input("enter the value of " + child + " : "))
        subgraph[child] = child_value
    graph[key] = subgraph
    subgraph = {}
    print("")
starting_node = input("enter the root node : ")
goal_node = input("enter goal node : ")
option = int(input("enter 1 if minimization and 2 if maximization : "))
if option == 1:
    hill_climbing(graph, goal_node, starting_node,"minimization")
if option == 2:
    hill_climbing(graph, goal_node, starting_node,"maximization")
