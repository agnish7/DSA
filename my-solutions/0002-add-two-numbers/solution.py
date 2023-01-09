# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        if not l1 and not l2:
            return ListNode(0)
        if not l1:
            return l2
        if not l2:
            return l1
        
        s, c = (l1.val + l2.val) % 10, (l1.val + l2.val) // 10
        res = ListNode(s)
        res.next = None
        head = res
        l1, l2 = l1.next, l2.next

        while(l1 and l2):
            
            s = (l1.val + l2.val + c)
            d = s % 10
            c = s // 10
            # print(l1.val, l2.val, s, c)
            res.next = ListNode(d)
            res = res.next
            l1, l2 = l1.next, l2.next
        
        while(l1):
            s = (l1.val + c)
            d = s % 10
            c = s // 10
            res.next = ListNode(d)
            res = res.next
            l1 = l1.next
        
        while(l2):
            s = (l2.val + c)
            d = s % 10
            c = s // 10
            res.next = ListNode(d)
            res = res.next
            l2 = l2.next
        
        if c:
            res.next = ListNode(c)
            res = res.next
        
        res.next = None

        return head
