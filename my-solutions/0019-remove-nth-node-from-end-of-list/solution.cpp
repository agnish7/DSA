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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* last = head;
        ListNode* first = nullptr;
        int i = 0;

        while(last) {
            last = last->next;
            if(first) first = first->next;
            ++i;
            if(i == n + 1) {
                first = head;
            }
        }

        if(i == n) {
            ListNode* temp = head;
            ListNode* newHead = head->next;
            temp->next = nullptr;
            delete(temp);
            return newHead;
        }

        if(!first) {
            return head;
        } else if (!first->next) {
            return head;
        } else if(!first->next->next) {
            first->next = nullptr;
            return head;
        } else {
            ListNode* temp = first->next;
            first->next = temp->next;
            temp->next = nullptr;
            delete(temp);
            return head;
        }
    }
};
