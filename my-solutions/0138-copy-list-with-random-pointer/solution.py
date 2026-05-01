"""
# Definition for a Node.
class Node:
    def __init__(self, x, next=None, random=None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution(object):
    def copyRandomList(self, head):
        nodemap = {}
        nodemap[None] = None
        tmp = head

        while tmp:
            nodemap[tmp] = Node(tmp.val)
            tmp = tmp.next

        tmp = head
        while tmp:

            nodemap[tmp].next = nodemap[tmp.next]
            nodemap[tmp].random = nodemap[tmp.random]
            tmp = tmp.next

        return nodemap[head]
