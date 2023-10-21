# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        summa, carry = 0, 0
        res, head = None, None

        while(l1 and l2):
            summa = (l1.val + l2.val + carry) % 10
            newNode = ListNode(summa)
            if res:
                res.next = newNode
                res = res.next
            else:
                res = newNode
                head = res
            carry = (l1.val + l2.val + carry) // 10
            l1, l2 = l1.next, l2.next

        while(l1):
            summa = (l1.val + carry) % 10
            newNode = ListNode(summa)
            res.next = newNode
            res = res.next
            carry = (l1.val + carry) // 10
            l1 = l1.next
        
        while(l2):
            summa = (l2.val + carry) % 10
            newNode = ListNode(summa)
            res.next = newNode
            res = res.next
            carry = (l2.val + carry) // 10
            l2 = l2.next

        if carry:
            res.next = ListNode(carry)
        
        res = None

        return head
        
