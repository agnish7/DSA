# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        prev1, prev2  = None, None
        if not list1:
            return list2
        if not list2:
            return list1
        head = list1 if list1.val <= list2.val else list2
        while(list1 and list2):

            if(list1 and list2 and list1.val <= list2.val):
                while(list1 and list1.val <= list2.val):
                    prev1 = list1
                    list1 = list1.next
                prev1.next = list2

            if(list2 and list1 and list2.val <= list1.val):
                while(list2 and list2.val <= list1.val):
                    prev2 = list2
                    list2 = list2.next
                prev2.next = list1

        
        prev1, prev2, list1, list2 = None, None, None, None
        return head

