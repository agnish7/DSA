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
        if(head == nullptr)
            return nullptr;
        else if(head->next == nullptr) {
            if(n == 1)
                return nullptr;
            else if(n == 0)
                return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        while(n > 0) {
            if(fast)
                fast = fast->next;
            n--;
        }
        while(fast) {
            prev = slow;
            fast = fast->next;
            slow = slow->next;
        }
        if(prev)
            cout << prev->val << endl;
        if(!prev) {
            head = head->next;
            return head;
        }
        else if(!prev->next)
            return head;
        else if(!prev->next->next) {
            prev->next = nullptr;
        } else {
            ListNode* temp = prev->next;
            prev->next = temp->next;
        }
        return head;
    }
};
