"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        # without hashmap
        if not head:
            return None

        dummyAdder = head
        while(dummyAdder.next):
            temp = dummyAdder.next
            dummyAdder.next = Node(dummyAdder.val)
            dummyAdder.next.next = temp
            dummyAdder = dummyAdder.next.next

        dummyAdder.next = Node(dummyAdder.val)

        # temp = head
        # while(temp):
        #     print(temp, temp.val)
        #     temp = temp.next
        # return head
        
        randomAdder = head
        while(randomAdder and randomAdder.next):
            temp = randomAdder.next.next
            if randomAdder.random:
                randomAdder.next.random = randomAdder.random.next
            randomAdder = temp

        splitter = head
        res = head.next
        while(splitter.next.next):
            temp = splitter.next.next
            splitter1 = splitter
            splitter2 = splitter.next
            splitter1.next = splitter1.next.next
            splitter2.next = splitter2.next.next
            splitter = temp
        
        return res


