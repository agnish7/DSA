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
        if(!l1 and !l2) return 0;
        else if(!l1) return l2;
        else if(!l2) return l1;

        ListNode* l3 = new ListNode((l1->val + l2->val)%10);
        ListNode* head = l3;
        int carry = (l1->val + l2->val) / 10;
        l1 = l1->next; l2 = l2->next;
        while(l1 and l2) {
            int sum = l1->val + l2->val + carry;
            l3->next = new ListNode(sum % 10);
            l3 = l3->next;
            l1 = l1->next;
            l2 = l2->next;
            carry = sum / 10;
        }
        while(l1) {
            int sum = l1->val + carry;
            l3->next = new ListNode(sum % 10);
            l3 = l3->next;
            l1 = l1->next;
            carry = sum / 10;
        }
        while(l2) {
            int sum = l2->val + carry;
            l3->next = new ListNode(sum % 10);
            l3 = l3->next;
            l2 = l2->next;
            carry = sum / 10;
        }
        if(carry) {
            l3->next = new ListNode(carry);
            l3 = l3->next;
        }
        return head;
    }
};
