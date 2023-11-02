class Node:
    def __init__(self, key, val):
        self.key, self.val = key, val
        self.left = self.right = None

class LRUCache:

    def __init__(self, capacity: int):
        self.right, self.left = Node(0, 0), Node(0, 0)
        self.right.next, self.left.prev = None, None
        self.right.prev, self.left.next = self.left, self.right
        self.cap = capacity
        self.cache = {}
    
    def remove(self, node):
        prev, nxt = node.prev, node.next
        prev.next, nxt.prev = nxt, prev

    def insert(self, node): # insert at right
        prev, nxt = self.right.prev, self.right
        prev.next = nxt.prev = node
        node.prev, node.next = prev, nxt

    def get(self, key: int) -> int:
        if key in self.cache:
            self.remove(self.cache[key])
            self.insert(self.cache[key])
            return self.cache[key].val
        else:
            return -1
        
    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.cache[key].val = value
            self.remove(self.cache[key])
            self.insert(self.cache[key])
        else:
            if len(self.cache) == self.cap:
                lru = self.left.next
                self.remove(lru)
                del self.cache[lru.key]

                

            node = Node(key, value)
            self.cache[key] = node
            self.insert(node)
            
            # temp = self.left
            # while(temp):
            #     print(temp.key, temp.val)
            #     temp = temp.next
            # print("")
        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
