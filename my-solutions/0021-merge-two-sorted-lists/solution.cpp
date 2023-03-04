/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 and !list2) return nullptr;
        else if(!list1) return list2;
        else if(!list2) return list1;

        ListNode* mergedList = new ListNode(list1->val > list2->val ? list2->val : list1->val);
        if(list1->val > list2->val) list2 = list2->next; else list1 = list1->next;
        ListNode* head = mergedList;
        while(list1 and list2) {
            ListNode* newNode  = new ListNode(list1->val > list2->val ? list2->val : list1->val);
            if(list1->val > list2->val) list2 = list2->next; else list1 = list1->next;
            if(mergedList) mergedList->next = newNode; else mergedList = newNode;
            mergedList = mergedList->next;
        }
        while(list1) {
            ListNode* newNode = new ListNode(list1->val);
            if(mergedList) mergedList->next = newNode; else mergedList = newNode;
            mergedList = mergedList->next;
            list1 = list1->next;
        }
        while(list2) {
            ListNode* newNode = new ListNode(list2->val);
            if(mergedList) mergedList->next = newNode; else mergedList = newNode;
            mergedList = mergedList->next;
            list2 = list2->next;
        }
        return head;
    }
};
