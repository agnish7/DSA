# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if(list1 == None and list2 == None):
            return None
        elif list1 == None:
            return list2
        elif list2 == None:
            return list1
        else:
            head = ListNode()
            curr = head
            
            if(list1.val <= list2.val):
                curr.val = list1.val
                list1 = list1.next
            else:
                curr.val = list2.val
                list2 = list2.next
                
            while list1 and list2:
                newNode = ListNode()
                curr.next = newNode
                curr = newNode
                
                if(list1.val <= list2.val):
                    curr.val = list1.val
                    list1 = list1.next
                else:
                    curr.val = list2.val
                    list2 = list2.next

            while list1:
                newNode = ListNode()
                curr.next = newNode
                curr = newNode            
                curr.val = list1.val
                list1 = list1.next

            while list2:
                newNode = ListNode()
                curr.next = newNode
                curr = newNode            
                curr.val = list2.val
                list2 = list2.next
                
            return head
