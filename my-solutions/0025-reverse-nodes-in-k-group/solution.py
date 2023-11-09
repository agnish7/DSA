# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        def reverse(head):
            if not head or not head.next:
                return head
            else:
                newHead = reverse(head.next)
                head.next.next = head
                head.next = None
                return newHead
        # def printList(head):
        #     while(head):
        #         if not head.next:
        #             print(head.val, end = "")
        #         else:
        #             print(head.val, "->", end = "")
        #         head = head.next
        #     print("")

        fast = slow = head
        for i in range(k - 1):
            if fast:
                fast = fast.next
        if not fast:
            return head
        if not fast.next:
            return reverse(slow)
        temp = fast.next
        fast.next = None
        fast = temp

        head = reverse(slow)
        slow.next = self.reverseKGroup(fast, k)
        
        return head


