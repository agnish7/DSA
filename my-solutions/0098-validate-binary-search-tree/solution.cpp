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

    bool isValid(TreeNode* root, TreeNode*& prev) {
        // check if the root is nullptr;
        if(root == nullptr) return true;

        if(!isValid(root->left, prev)) return false;

        if(prev && prev->val >= root->val) return false;
        prev =  root;

        if(!isValid(root->right, prev)) return false;

        return true;
    }

    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return isValid(root, prev);
    }
};
