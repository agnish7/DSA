class Node:
    def __init__(self):
        self.end = False
        self.next = [None] * 26

class WordDictionary:

    def __init__(self):
        self.root = Node()
        

    def addWord(self, word: str) -> None:
        curr = self.root

        for c in word:
            if not curr.next[ord(c) - ord('a')]:
                curr.next[ord(c) - ord('a')] = Node()

            curr = curr.next[ord(c) - ord('a')]


        curr.end = True
        

    def search(self, word: str) -> bool:
        
        def dfs(curr, word):
            if curr == None:

                return False
            if len(word) == 0:

                return curr.end

            if word[0] == '.':
                res = False
                for ptr in curr.next:
                    res = dfs(ptr, word[1:])
                    if res:
                        return True
                return False
                
            else:
                c = word[0]
                if curr.next[ord(c) - ord('a')]:
                    return dfs(curr.next[ord(c) - ord('a')], word[1:])
                else:
                    return False

        return dfs(self.root, word)


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
