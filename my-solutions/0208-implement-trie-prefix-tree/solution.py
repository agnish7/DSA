class Trie(object):
    class Node:
        def __init__(self):
            self.next = [None for i in range(26)]
            self.isWord = False

    def __init__(self):
        self.root = self.Node()

    def getNode(self, word):
        curr = self.root
        for i in range(len(word)):
            if curr.next[ord(word[i]) - ord('a')] == None:
                return None
            else:
                curr = curr.next[ord(word[i]) - ord('a')]
        return curr

    def insert(self, word):
        """
        :type word: str
        :rtype: None
        """
        curr = self.root
        for i in range(len(word)):
            if curr.next[ord(word[i]) - ord('a')] == None:
                curr.next[ord(word[i]) - ord('a')] = self.Node()
            curr = curr.next[ord(word[i]) - ord('a')]
        curr.isWord = True

    def search(self, word):
        """
        :type word: str
        :rtype: bool
        """

        return self.getNode(word) != None and self.getNode(word).isWord
        

    def startsWith(self, prefix):
        """
        :type prefix: str
        :rtype: bool
        """
        return self.getNode(prefix) != None
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
