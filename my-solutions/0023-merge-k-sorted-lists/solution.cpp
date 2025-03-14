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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        return helper(lists, 0, lists.size() - 1);
    }
    ListNode* merge2Lists(ListNode* a, ListNode* b) {
        if(!a) return b;
        if(!b) return a;

        ListNode head(0);
        ListNode* ptr = &head;

        while(a && b) {
            if(a->val < b->val) {
                ptr->next = a;
                a = a->next;
            } else {
                ptr->next = b;
                b = b->next;
            }
            ptr = ptr->next;
        }

        ptr->next = a ? a : b;
        return head.next;
    }

    ListNode* helper(vector<ListNode*>& lists, int l, int r) {
        if(l == r) return lists[l];
        if(l + 1 == r) return merge2Lists(lists[l], lists[r]);
        int mid = (l + r) / 2;
        ListNode* left = helper(lists, l, mid);
        ListNode* right = helper(lists, mid + 1, r);
        return merge2Lists(left, right);
    }
};
