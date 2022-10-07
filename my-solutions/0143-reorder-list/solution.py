# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        
        if(head == None or head.next == None):
            return head
        
        # find the middle of the list
        fast = head
        slow = head
        while(fast.next != None and fast.next.next != None):
            fast = fast.next.next
            slow = slow.next    
        middle = slow
        
        # split the list into 2
        list1 = head
        list2 = middle.next
        middle.next = None
        
        # reverse the second list
        prev = None
        curr = list2
        while(curr.next != None):
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
        curr.next = prev
        list2 = curr
        
        # combine the 2 lists into 1
        while(list1 != None and list2 != None):
            t1 = list1.next
            list1.next = list2
            list1 = t1
            
            t2 = list2.next
            list2.next = list1
            list2 = t2
