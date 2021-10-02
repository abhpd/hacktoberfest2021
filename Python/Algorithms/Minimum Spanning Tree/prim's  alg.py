class PrimAlg:
    def __init__(self, vertices):
        self.vertices = vertices
        self.graph = [[0 for column in range(vertices)] for row in range(vertices)]

    def run_alg(self):
        selected = []
        for i in range(self.vertices):
            selected.append(0)
        edge = 0
        selected[0] = True
        print("Edge\t:\tWeight")
        while edge < self.vertices - 1:
            min_key = 9999999
            x = 0
            y = 0
            for i in range(self.vertices):
                # if selected[i]:
                for j in range(self.vertices):
                    if (not selected[j]) and self.graph[i][j]:
                        if min_key > self.graph[i][j]:
                            min_key = self.graph[i][j]
                            x = i
                            y = j
            print("{}-{}\t\t:\t  {}".format(x, y, self.graph[x][y]))
            selected[y] = True
            edge += 1


a = PrimAlg(5)
a.graph = [
    [0, 2, 0, 8, 1],
    [2, 0, 3, 0, 4],
    [0, 3, 0, 7, 5],
    [8, 0, 7, 0, 6],
    [1, 4, 5, 6, 0]
]

a.run_alg()
