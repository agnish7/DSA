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
        int sum = 0, carry = 0;
        ListNode* i = l1, *j = l2;
        ListNode head = ListNode(0);
        ListNode* ptr = &head;
        while(i || j || carry) {
            sum = (i?i->val:0) + (j?j->val:0) + carry;
            carry = sum / 10;
            sum = sum % 10;
            ptr->next = new ListNode(sum);
            ptr = ptr->next;
            if(i) i = i->next;
            if(j) j = j->next;
        }

        return head.next;
    }
};
