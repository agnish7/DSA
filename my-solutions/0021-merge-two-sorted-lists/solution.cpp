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
        if(!list1) return list2;
        if(!list2) return list1;
        if(!list1 && !list2) return nullptr;
        
        ListNode *prev1{}, *prev2{}, *head{};

        head = list1->val < list2->val ? list1 : list2;

        while(list1 && list2) {
            if(list1->val < list2->val) {
                while(list1 && list1->val <= list2->val) {
                    prev1 = list1;
                    list1 = list1->next;
                }
                prev1->next = list2;
            } else {
                while(list2 && list2->val <= list1->val) {
                    prev2 = list2;
                    list2 = list2->next;
                }
                prev2->next = list1;
            }
        }

        return head;
    }
};
