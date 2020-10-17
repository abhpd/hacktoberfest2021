# kaustubh0201

INF = 99999
V = 4


def printGraph(graph):
    print("The shortest path of each element from each other is as follows: ")
    print("Note that there is no loop for each element. \n")
    for i in range(0, V):
        for j in range(0, V):
            if(graph[i][j] == INF):
                continue
            else:
                print(str(graph[i][j]) + "   ", end="")
        print("")


def floyd_warshall(graph):
    for i in range(0, V):
        for j in range(0, V):
            for k in range(0, V):
                if(graph[j][i] + graph[i][k] < graph[j][k]):
                    graph[j][k] = graph[j][i] + graph[i][k]
    printGraph(graph)


graph = [
    [0, 3, INF, 7],
    [8, 0, 2, INF],
    [5, INF, 0, 1],
    [2, INF, INF, 0]
]

floyd_warshall(graph)
