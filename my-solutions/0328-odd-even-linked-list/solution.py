# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None or head.next == None or head.next.next == None:
            return head
        
        p_head = head
        oddList = ListNode(p_head.val)
        oddHead = oddList
        p_head = p_head.next.next

        while(p_head != None and p_head.next != None):
            oddList.next = ListNode(p_head.val)
            oddList = oddList.next
            p_head = p_head.next.next
        
        if p_head != None:
            oddList.next = ListNode(p_head.val)
            oddList = oddList.next

        p_head = head.next
        evenList = ListNode(p_head.val)
        evenHead = evenList
        p_head = p_head.next.next

        while(p_head != None and p_head.next != None):
            evenList.next = ListNode(p_head.val)
            evenList = evenList.next
            p_head = p_head.next.next

        if p_head != None:
            evenList.next = ListNode(p_head.val)
            evenList = evenList
        
        oddList.next = evenHead
        return oddHead
