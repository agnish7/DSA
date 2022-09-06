# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        tortoise, hare = head, head
        
        while True:
            if tortoise == None or hare == None:
                return False
            if tortoise.next == None or hare.next == None:
                return False
            if hare.next.next ==  None:
                return False
            tortoise = tortoise.next
            hare = hare.next.next
            
            if(tortoise == hare):
                return True
        
