# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        tmp = []
        while head:
            tmp.append(head.val)
            head = head.next

        for i in range(len(tmp) // 2):
            if tmp[i] != tmp[len(tmp) - 1 - i]:
                return False

        return True 
