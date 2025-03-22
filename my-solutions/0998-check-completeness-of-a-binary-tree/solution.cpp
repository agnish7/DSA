/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        deque<TreeNode*> q{root};
        TreeNode* prev;

        while(!q.empty()) {
            TreeNode* curr = q.front();
            if(curr) q.push_back(curr->left);
            if(curr) q.push_back(curr->right);
            q.pop_front();
            if(!prev && curr) return false;
            prev = curr;
        }

        return true;
    }
};
