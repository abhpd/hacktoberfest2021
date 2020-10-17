# kaustubh0201

INF = 99999
V = 7


def printGraph(parent, graph):
    print("Edge \tWeight")
    for i in range(1, V):
        print(str(parent[i]) + " - " + str(i) +
              " \t" + str(graph[i][parent[i]]))


def min_ele(distance, check):
    temp = INF
    index = 0
    for i in range(0, V):
        if(check[i] == 0 and distance[i] < temp):
            temp = distance[i]
            index = i
    return index


def prims(graph):
    check = []
    distance = []
    parent = []

    for i in range(0, V):
        distance.append(INF)
        check.append(0)
        parent.append(0)

    distance[0] = 0
    parent[0] = -1

    for i in range(0, V):
        u = min_ele(distance, check)

        check[u] = 1

        for j in range(0, V):
            if(graph[u][j] == 0):
                continue
            else:
                if(check[j] == 0):
                    if(graph[u][j] < distance[j]):
                        distance[j] = graph[u][j]
                        parent[j] = u
    printGraph(parent, graph)


graph = [
    [0, 28, 0, 0, 0, 10, 0],
    [28, 0, 16, 0, 0, 0, 14],
    [0, 16, 0, 12, 0, 0, 0],
    [0, 0, 12, 0, 22, 0, 18],
    [0, 0, 0, 22, 0, 25, 24],
    [10, 0, 0, 0, 25, 0, 0],
    [0, 14, 0, 18, 24, 0, 0]
]

prims(graph)
