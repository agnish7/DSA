# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def merge(self, list1, list2):
        head = ListNode(0)
        curr = head

        while(list1 and list2):
            if list1.val <= list2.val:
                curr.next = list1
                list1 = list1.next
            else:
                curr.next = list2
                list2 = list2.next
            curr = curr.next

        if list1:
            curr.next = list1
        if list2:
            curr.next = list2

        return head.next
    
    def printList(self, list):
        while(list):
            if list.next == None:
                print(list.val, end = "")
            else:
                print(list.val, "->", end = "")
            list = list.next

        print("")
    
    def printAll(self, lists):
        for list in lists:
            self.printList(list)
        print("")

    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        def mergeLists(lists):
            if len(lists) <= 1:
                return lists
            size = len(lists)
            for i in range(size // 2):
                idx = 2 * i
                lists[i] = self.merge(lists[idx], lists[idx + 1])

            # self.printAll(lists)

            if size % 2 == 0:
                lists = lists[:size // 2]
            else:
                last = lists[-1]
                lists = lists[:size // 2]
                lists.append(last)

            # self.printAll(lists)
    
            return mergeLists(lists)
        
        res = mergeLists(lists)
        if res:
            return res[0]
        else:
            return None


