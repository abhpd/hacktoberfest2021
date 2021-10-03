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

    def autoComplete(self, prefix):
        node = self.root
        for letter in prefix:
            if letter not in node:
                return []
            node = node[letter]
        words = []
        self._dfsHelper(node, words)
        return words

    def _dfsHelper(self, node, words):
        for letter in node:
            if letter == self.end:
                words.append(node[self.end])
                continue
            self._dfsHelper(node[letter], words)
        return words

# Alternative Approach Optimal one
# O(np) time | O(n) space
# n = number of elements in array, p = length of prefix, s = length of the longest string in strings
class OptimalSolution:
    def autoComplete(self, strings, prefix):
        result = []
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
                result.append(string)
        return result
                

# O(ns + p + e) time | O(ns) space
# n = number of strings | s = length of the longest string in strings | p = length of the prefix | v = number of vertices | e = number of edges 
if __name__ == "__main__":
    trie = Trie()
    strings = [
        "Hack",
        "Hacktober",
        "Hacktoberfest",
        "Hacktoberfest2021",
    ]
    for string in strings:
        trie.prepareTrie(string)
    
    print(trie.autoComplete("Ha"))

    s = OptimalSolution()
    print(s.autoComplete(strings, "H"))