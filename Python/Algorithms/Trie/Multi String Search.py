class ModifiedSuffixTrie:
    def __init__(self, string):
        self.root = {}
        self.end = "*"
        self._prepareTrie(string)

    def _prepareTrie(self, string):
        for i in range(len(string)):
            self._insert(string, i)

    def _insert(self, string, startIdx):
        node = self.root
        for i in range(startIdx, len(string)):
            letter = string[i]
            if letter not in node:
                node[letter] = {}
            node = node[letter]
        node[self.end] = string

    def contains(self, string):
        node = self.root
        for letter in string:
            if letter not in node:
                return False
            node = node[letter]
        return True

class Trie:
    def __init__(self):
        self.root = {}
        self.end = "*"

    def insert(self, string):
        node = self.root
        for letter in string:
            if letter not in node:
                node[letter] = {}
            node = node[letter]
        node[self.end] = string

class Solution:
    # O(bns) time | O(n) space 
    # n = number of substrings | b = length of big string | s = length of longest small string in small strings 
    def multiStringSearch(self, bigString, smallStrings):
        return [self._isContains(bigString, smallString) for smallString in smallStrings]

    def _isContains(self, bigString, smallString):
        for i in range(len(bigString)):
            if i + len(smallString) > len(bigString):
                break
            if self._contains(bigString, smallString, i):
                return True
        return False

    def _contains(self, bigString, smallString, startIdx):
        leftBigIdx = startIdx
        rightBigIdx = startIdx + len(smallString) - 1
        leftSmallIdx = 0
        rightSmallIdx = len(smallString) - 1
        while leftBigIdx <= rightBigIdx:
            if bigString[leftBigIdx] != smallString[leftSmallIdx] or bigString[rightBigIdx] != smallString[rightSmallIdx]:
                return False
            leftSmallIdx += 1
            leftBigIdx += 1
            rightSmallIdx -= 1
            rightBigIdx -= 1
        return True

    # O(b^2 + ns) time | O(b^2 + n) space
    def modifiedSuffixTrie(self, bigString, smallStrings):
        trie = ModifiedSuffixTrie(bigString)
        return [trie.contains(smallString) for smallString in smallStrings]

    # O(ns + bs) time | O(ns) space
    def trie(self, bigString, smallStrings):
        trie = Trie()
        for smallString in smallStrings:
            trie.insert(smallString)
        contains = {}
        for i in range(len(bigString)):
            self._isBigStringIn(bigString, trie, i, contains)
        return [string in contains for string in smallStrings]
    
    def _isBigStringIn(self, string, trie, startIdx, contains):
        node = trie.root
        for i in range(startIdx, len(string)):
            letter = string[i]
            if letter not in node:
                break
            node = node[letter]
            if trie.end in node:
                contains[node[trie.end]] = True


if __name__ == "__main__":
    s = Solution()
    bigString = "hacktoberfest 2021 is going to rock"
    smallStrings = [
        "2021", "is", "rock", "lose", "hacktoberfest", "yoyo"
    ]
    print(s.multiStringSearch(bigString, smallStrings))
    print(s.modifiedSuffixTrie(bigString, smallStrings))
    print(s.trie(bigString, smallStrings))