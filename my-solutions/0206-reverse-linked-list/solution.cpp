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

#include<list>

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        else if(head->next == nullptr) {
            return head;
        }
        else {
            ListNode* prev = nullptr;
            ListNode* curr = head;
            while(curr->next != nullptr) {
                auto temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            curr->next = prev;
            return curr;  
        }
    }
};
