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
        copy_map = {}
        ptr = head
        while(ptr):
            if ptr not in copy_map:
                newNode = Node(ptr.val)
                copy_map[ptr] = newNode
            ptr = ptr.next
    
        copy_map[None] = None
        
        newHead = copy_map[head]
        ptr = head
        while(ptr):
            copy_map[ptr].next =  copy_map[ptr.next]
            copy_map[ptr].random = copy_map[ptr.random]
            ptr = ptr.next
        
        return newHead

