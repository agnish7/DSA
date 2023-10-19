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
        fast, slow = head, head
        while(fast and fast.next):
            fast = fast.next.next
            slow = slow.next

        list1 = head
        list2 = slow.next
        slow.next = None

        # function to reverse a list
        def reverseList(head):
            if not head or not head.next:
                return head
            else:
                newHead = reverseList(head.next)
                head.next.next = head
                head.next = None
                return newHead
        
        list2 = reverseList(list2)

        # merge the 2 lists
        prev1, prev2 = None, None
        while(list1 and list2):
            prev1 = list1
            list1 = list1.next

            prev1.next = list2

            prev2 = list2
            list2 = list2.next

            prev2.next = list1


