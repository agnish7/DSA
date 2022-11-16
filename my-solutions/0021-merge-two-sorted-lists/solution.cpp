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

        if(list1 == nullptr && list2 == nullptr)
            return nullptr;
        else if(list1 ==  nullptr) return list2;
        else if(list2 ==  nullptr) return list1;
        
        // assign the first node to the new list.
        ListNode* new_head = nullptr;
        if(list1->val < list2->val) {
            new_head = new ListNode(list1->val);
            list1 = list1->next;
        } else {
            new_head = new ListNode(list2->val);
            list2 = list2->next;
        }

        // add new nodes to the new list.
        ListNode* curr = new_head;
        while(list1 != nullptr && list2 != nullptr) {
            ListNode* temp = nullptr;
            if(list1->val > list2->val) {
                temp = new ListNode(list2->val);
                list2 = list2->next;
            } else {
                temp = new ListNode(list1->val);
                list1 = list1->next;
            }
            curr->next = temp;
            curr = curr->next;
            temp = nullptr;
        }

        // add remaining nodes from list1
        while(list1 != nullptr) {
            ListNode* temp = new ListNode(list1->val);
            list1 = list1->next;
            curr->next = temp;
            curr = curr->next;
            temp = nullptr;
        }

        // add remaining nodes form list2
        while(list2 != nullptr) {
            ListNode* temp = new ListNode(list2->val);
            list2 = list2->next;
            curr->next = temp;
            curr = curr->next;
            temp = nullptr;
        }

        // return the new list.
        return new_head;
    }
};
