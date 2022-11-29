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
    void* mergeLists(ListNode* node1, ListNode* node2) {
        ListNode* head = node1;
        while(node2) {
            ListNode* temp1 = node1;
            node1 = node1->next;
            temp1->next = node2;
            ListNode* temp2 = node2;
            node2 = node2->next;
            temp2->next = node1;
        }
        return head;
    }
    ListNode* reverseList(ListNode* node) {
        if(!node) {
            return nullptr;
        }
        if(!node->next) {
            return node;
        }
        ListNode* temp =  reverseList(node->next);
        node->next->next = node;
        node->next = nullptr;
        return temp;
    }
    void reorderList(ListNode* head) {
        // find the mid point of the given list
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = slow;
        while(fast && fast->next) {
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        prev = slow;
        slow = slow->next;

        // detach the 2nd list from the original
        ListNode* list1= head;
        ListNode* list2= slow;
        prev->next = nullptr;

        // reverse the 2nd list
        list2 = reverseList(list2);

        // merge the reversed list with first half
        mergeLists(list1, list2);

        // ListNode* ptr = list2;
        // while(ptr) {
        //     cout << ptr->val;
        //     ptr = ptr->next;
        // }
    }
};
