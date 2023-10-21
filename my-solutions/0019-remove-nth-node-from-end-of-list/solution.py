# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if not head:
            return None
        
        prev, first, nth = None, head, head

        for i in range(n):
            first = first.next
        
        while(first):
            prev = nth
            nth = nth.next
            first = first.next

        # print(prev, first, nth)
        
        if not prev: # remove first element
            if not head.next:
                return None
            else:
                head = head.next
                return head

        if prev and prev.next.next:
            prev.next = prev.next.next
        elif not prev.next.next:
            prev.next = None
        return head

            

