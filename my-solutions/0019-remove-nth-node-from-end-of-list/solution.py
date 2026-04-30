# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: Optional[ListNode]
        :type n: int
        :rtype: Optional[ListNode]
        """
        fast = slow = head
        prev = None
        i = 0
        while fast:
            fast = fast.next
            if i >= n:
                prev = slow
                slow = slow.next

            i += 1

        if prev == None:
            return head.next

        prev.next = slow.next

        return head        
