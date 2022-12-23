# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def merge(self, list1, list2):
        if not list1 and not list2:
            return None
        # return copy of list 2 if list 1 empty
        elif not list1:
            head = ListNode(list2.val)
            list2 = list2.next
            temp = head
            while(list2):
                temp.next = ListNode(list2.val)
                temp = temp.next
                list2 = list2.next
            temp.next = None
            return head
        # return copy of list 1 if list 2 is empty
        elif not list2:
            head = list1
            list1 = list1.next
            temp = head
            while(list1):
                temp.next = ListNode(list1.val)
                temp = temp.next
                list1 = list1.next
            temp.next = None
            return head
        else:
        # merge
            res = None
            if list1.val < list2.val:
                res = ListNode(list1.val)
                list1 = list1.next
            else:
                res = ListNode(list2.val)
                list2 = list2.next
            
            temp = res
            while(list1 and list2):
                if(list1.val < list2.val):
                    temp.next = ListNode(list1.val)
                    list1 = list1.next
                    temp = temp.next
                else:
                    temp.next = ListNode(list2.val)
                    list2 = list2.next
                    temp = temp.next
            
            while(list1):
                temp.next = ListNode(list1.val)
                temp = temp.next
                list1 = list1.next
            
            while(list2):
                temp.next = ListNode(list2.val)
                temp = temp.next
                list2 = list2.next

            temp.next = None
            return res

    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        if(len(lists) == 0):
            return None

        
        while(len(lists) > 1):
            mergedLists = []
            for i in range(0, len(lists), 2):
                l1 = lists[i]
                l2 = lists[i+1] if i + 1 < len(lists) else None
                ll = self.merge(l1, l2)
                mergedLists.append(ll)
            lists = mergedLists
        
        return lists[0]


        # l1 = ListNode(6)
        # h1 = l1
        # l1.next = ListNode(8)
        # l1 = l1.next
        # l1.next = ListNode(9)
        # l1 = l1.next
        # l1.next = ListNode(80)
        # l1 = l1.next
        # l1.next = None

        # l2 = ListNode(5)
        # h2 = l2
        # l2.next = ListNode(7)
        # l2 = l2.next
        # l2.next = ListNode(8)
        # l2 = l2.next
        # l2.next = None

        # printL(self.merge(h1, h2))




