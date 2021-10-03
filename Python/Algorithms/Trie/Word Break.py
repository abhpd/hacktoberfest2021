class Trie:
    def __init__(self):
        self.root = {}
        self.end = "*"

    def prepareTrie(self, string):
        node = self.root
        for letter in string:
            if letter not in node:
                node[letter] = {}
            node = node[letter]
        node[self.end] = True

    def isWordBreak(self, string):
        node = self.root
        for i in range(len(string)):
            letter = string[i]
            if len(node) > 1 and self.end in node:
                if letter not in node:
                    node = self.root
            if len(node) == 1 and self.end in node:
                node = self.root
            if letter not in node:
                return False
            node = node[letter]
        return self.end in node

# O(ns + b) time | O(ns) space
if __name__ == "__main__":
    trie = Trie()
    strings = [
        "hacktober",
        "fest",
        "2021"
    ]
    for string in strings:
        trie.prepareTrie(string)

    print(trie.isWordBreak("hacktoberfest2021"))