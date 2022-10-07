# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        
        if(head == None):
            return None
        elif head.next == None:
            if n == 0:
                return head
            else:
                return None

        
        slow = head
        fast = head
        for i in range(n):
            if fast == None:
                return
            fast = fast.next
            
        if(fast == None):
            temp = head.next
            head.next = None
            return temp

        while(fast.next != None):
            slow = slow.next
            fast = fast.next
            
        if(slow.next.next == None):
            slow.next = None
        else:
            temp = slow.next
            slow.next = temp.next
            temp.next = None
            
        return head
            
