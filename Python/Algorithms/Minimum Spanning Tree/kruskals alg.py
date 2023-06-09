class Graph:
    def __init__(self, vertices):
        self.vertices = vertices
        self.graph = []

    def add(self, x, y, z):
        self.graph.append([x, y, z])

    def search(self, root, index):
        if root[index] == index:
            return index
        return self.search(root, root[index])

    def union(self, root, rank, x, y):
        xroot = self.search(root, x)
        yroot = self.search(root, y)

        if rank[xroot] < rank[yroot]:
            root[xroot] = yroot
        elif rank[xroot] > rank[yroot]:
            root[yroot] = xroot
        else:
            root[yroot] = xroot
            rank[xroot] += 1

    def alg(self):
        data = []
        root = []
        rank = []
        index = 0
        element = 0
        self.graph = sorted(self.graph, key=lambda data: data[2])

        for d in range(self.vertices):
            root.append(d)
            rank.append(0)

        while element < self.vertices - 1:
            a, b, c = self.graph[index]
            index += 1
            q = self.search(root, a)
            r = self.search(root, b)

            if q != r:  # no cycle
                element += 1
                data.append([a, b, c])
                self.union(root, rank, q, r)

            if index == self.vertices:
                break
        min = 0
        print("Edges constructed")
        for a, b, weight in data:
            min += weight
            print("{} ---- {} ==== {}".format(a, b, weight))
        print("Minimum cost spanning of tree = {}".format(min))


if __name__ == '__main__':
    g = Graph(13)

    g.add(1, 2, 1)
    g.add(1, 4, 4)
    g.add(2, 4, 6)
    g.add(2, 5, 4)
    g.add(2, 3, 2)
    g.add(2, 5, 4)
    g.add(3, 5, 5)
    g.add(3, 6, 6)
    g.add(4, 5, 3)
    g.add(4, 7, 4)
    g.add(5, 7, 7)
    g.add(5, 6, 8)
    g.add(6, 7, 3)

    g.alg()
