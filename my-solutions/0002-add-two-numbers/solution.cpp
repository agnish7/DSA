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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * output = nullptr; ListNode * head = output;
        int carry = 0;
        int sum = 0;
        while(l1 != nullptr || l2 != nullptr) {
            sum = (l1 == nullptr ? 0 : l1->val) + (l2 == nullptr ? 0 : l2->val) + carry;
            carry = sum > 9 ? 1 : 0;
            if(output == nullptr) {
                output = new ListNode(sum % 10); head = output;
            }
            else {
               output->next = new ListNode(sum > 9 ? sum - 10 : sum); output = output->next; 
            }
            // cout << num1 << "&" << num2 << " ";
            l1 != nullptr ? l1 = l1->next : nullptr;
            l2 != nullptr ? l2 = l2->next : nullptr;
        }
        if(carry > 0) {
            output->next = new ListNode(carry);
            output = output->next;
        }
        return head;
    }
};
