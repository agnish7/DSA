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
    void mergeLists(ListNode* x, ListNode* y) {
        // x has to be the longer one.
        ListNode* head = nullptr;
        ListNode* ptr = head;
        while(x && y) {
            ListNode* temp = x;
            if(x) {
                x = x->next;
            }
            temp->next = y;
            temp = y;
            if(y) {
                y = y->next;
            }
            temp->next = x;  
        }
    }

    ListNode* reverseList(ListNode* list) {
        if(!list)
            return nullptr;
        else if(!list->next) {
            return list;
        } else {
            ListNode* temp = reverseList(list->next);
            list->next->next = list;
            list->next = nullptr;
            return temp;
        }
    }

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while(fast) {
            prev = slow;
            slow = slow->next;
            if(!fast->next)
                break;
            fast = fast->next->next;
        }

        prev->next = nullptr;
        slow = reverseList(slow);
        ListNode* temp = slow;
        while(temp){
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;

        mergeLists(head, slow);

        if(prev)cout << "prev" << prev->val << endl;
        if(slow)cout << "slow" << slow->val << endl;
        if(fast)cout << "fast" << fast->val << endl;
    }
};
