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
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return nullptr;
        else if(!head->next)
            return head;
        else {
            ListNode* newList = reverseList(head->next);
            head->next->next = head;
            head->next = nullptr;
            return newList;
        }
    }

    void reorderList(ListNode* head) {
        if(!head) return;
        else if(!head->next) return;

        // split the LL into 2
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* list1 = head;
        ListNode* list2 = slow->next;

        slow->next = nullptr;

        list2 = reverseList(list2);

        while(list1 && list2) {
            ListNode* temp = list1;
            list1 = list1->next;
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
            temp->next = list1;
        }
    }
};
