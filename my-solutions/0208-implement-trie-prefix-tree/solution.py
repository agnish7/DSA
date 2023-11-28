class Node:
    def __init__(self, end = 'False'):
        self.end = end
        self.next = [None] * 26



class Trie:

    def __init__(self):
        self.root = Node()
        

    def insert(self, word: str) -> None:
        curr = self.root
        for char in word:
            if not curr.next[ord(char) - ord('a')]:
                curr.next[ord(char) - ord('a')] = Node()
            curr = curr.next[ord(char) - ord('a')]
        curr.end = True
        

    def search(self, word: str) -> bool:
        curr = self.root
        for char in word:
            if not curr.next[ord(char) - ord('a')]:
                print("")
                return False
            curr = curr.next[ord(char) - ord('a')]        
        return curr.end == True
        

    def startsWith(self, prefix: str) -> bool:
        curr = self.root
        for char in prefix:
            if not curr.next[ord(char) - ord('a')]:
                return False
            curr = curr.next[ord(char) - ord('a')]
        return True
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
