class Node:
  def __init__(self, key, val, front = None, back = None):
    self.key, self.val, self.front, self.back = key, val, front, back
  def getKey(self):
    return self.key
  def getFront(self):
    return self.front
  def getBack(self):
    return self.back
  def getVal(self):
    return self.val
  def setFront(self, node):
    self.front = node
  def setBack(self, node):
    self.back = node
  def setVal(self, val):
    self.val = val

class DLL:
  def __init__(self):
    self.start = None
    self.end = None
  
  def addNode(self, key, val): # adds a node to the front of the list
    if self.start:
      newNode = Node(key, val, None, self.start)
      self.start.setFront(newNode)
      self.start = newNode
    else:
      self.start = Node(key, val)
      self.end = self.start
  
  def moveToStart(self, node): # move a node to the front of the list
    def setNodeFront(node):
      self.start.setFront(node)
      node.setBack(self.start)
      self.start = node
      self.start.front = None
    if self.end == None or self.start == self.end or node == self.start:
      return
    if self.start.getBack().getBack() == None: # only 2 nodes
      self.start.front, self.end.back = self.end, self.start
      self.start.back, self.end.front = None, None
      self.start, self.end = self.end, self.start
    elif node == self.end: # end node
      prev = node.getFront()
      prev.setBack(None)
      self.end = prev
      setNodeFront(node)
    else: # middle node
      prev, nxt = node.getFront(), node.getBack()
      prev.setBack(nxt)
      nxt.setFront(prev)
      setNodeFront(node)
  
  def popBack(self):
    key = float("-inf")
    if self.start == self.end:
      key = self.start.getKey()
      self.start, self.end = None, None
    else:
      key = self.end.getKey()
      prev = self.end.getFront()
      prev.setBack(None)
      self.end = prev
    return key
  
  def getStart(self):
    return self.start
  
  def getEnd(self):
    return self.end

  # debugging
  def printAll(self):
    ptr = self.start
    while(ptr):
      print([ptr.front.key, ptr.front.val] if ptr.front else "None", [ptr.key, ptr.val], [ptr.back.key, ptr.back.val] if ptr.back else "None", end = ", ")
      ptr = ptr.back
    print("")
  

class LRUCache:

    def __init__(self, capacity: int):
      self.cacheList = DLL()
      self.cache = {}
      self.cap = capacity
      self.numNodes = 0

    def printCache(self):
      for key, val in self.cache.items():
        print(key, val.getVal())
      print("")

    def get(self, key: int) -> int:
      # print("get", key, ": ")
      if key not in self.cache:
        #
        # self.cacheList.printAll()
        # self.printCache()
        return -1
      else:
        node = self.cache[key]
        res = node.getVal()
        self.cacheList.moveToStart(node)
        # 
        # self.cacheList.printAll()
        # self.printCache()
        return res

    def put(self, key: int, value: int) -> None:
      # print("put", key, value, ": ")
      if key in self.cache:
        node = self.cache[key]
        node.setVal(value)
        self.cacheList.moveToStart(node)
        # 
        # self.cacheList.printAll()
        # self.printCache()
      else:
        if self.numNodes == self.cap: # capacity reached
          delKey = self.cacheList.popBack()
          # print("key for deletion = ", delKey)
          if key != float("-inf"):
            del self.cache[delKey]
          self.cacheList.addNode(key, value)
          self.cache[key] = self.cacheList.getStart()
          #
          # self.cacheList.printAll()
          # self.printCache()
        else:
          self.cacheList.addNode(key, value)
          self.cache[key] = self.cacheList.getStart()
          self.numNodes += 1
          #
          # self.cacheList.printAll()
          # self.printCache()
        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
