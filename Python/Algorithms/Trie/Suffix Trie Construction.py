class SuffixTrie:
    def __init__(self, string):
        self.root = {}
        self.end = "*"
        self.produceTrie(string)

    # O(n^2) time | O(n^2) space
    def produceTrie(self, string):
        for i in range(len(string)):
            self._insertNode(i, string)

    def _insertNode(self, i, string):
        node = self.root
        for j in range(i, len(string)):
            letter = string[j]
            if letter not in node:
                node[letter] = {}
            node = node[letter]
        node[self.end] = True

    # O(n) time | O(1) space
    def contains(self, string):
        node = self.root
        for letter in string:
            if letter not in node:
                return False
            node = node[letter]
        return self.end in node

if __name__ == "__main__":
    string = SuffixTrie("hacktoberfest2021")
    print(string.contains("fest2021"))
    print(string.contains("hacktoberfest"))