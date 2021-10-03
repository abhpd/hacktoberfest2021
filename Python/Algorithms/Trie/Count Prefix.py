# O(ns + p + e) time | O(ns) space
# n = number of strings | s = length of the longest string in strings | p = length of the prefix | v = number of vertices | e = number of edges
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
        node[self.end] = string

    def search(self, string):
        node = self.root
        for letter in string:
            if letter not in node:
                return False
            node = node[letter]
        return self.end in node

    def printTrie(self):
        node = self.root
        array = []
        self._dfsHelper(array, node)
        return array

    def _dfsHelper(self, array, node):
        for letter in node:
            if letter == self.end:
                array.append(node[self.end])
                continue
            self._dfsHelper(array, node[letter])
        return array

    def countPrefix(self, prefix):
        node = self.root
        for letter in prefix:
            if letter not in node:
                return 0
            node = node[letter]
        words = []
        self._dfsHelper(words, node)
        return len(words)

# Alternative Approach Optimal one
# O(np) time | O(1) space
# n = number of elements in array, p = length of prefix, s = length of the longest string in strings
class OptimalSolution:
    def autoComplete(self, strings, prefix):
        result = 0
        for string in strings:
            left = 0
            right = len(prefix) - 1
            add = True
            while left <= right:
                if string[left] != prefix[left] or string[right] != prefix[right]:
                    add = False
                    break
                left += 1
                right -= 1
            if add:
                result += 1
        return result
        
if __name__ == "__main__":
    trie = Trie()
    strings = [
        "Dog", "Doom", "Cat", "Doll"
    ]
    for string in strings:
        trie.prepareTrie(string)

    print(trie.search("Dog"))
    print(trie.printTrie())

    print(trie.countPrefix("Do"))

    s = OptimalSolution()
    print(s.autoComplete(strings, "Do"))