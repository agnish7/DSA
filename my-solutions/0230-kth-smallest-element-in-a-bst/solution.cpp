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
    int i = 0;
    void inorder(TreeNode* root, int& k, int& result) {
        if(root == nullptr) {return;}
        inorder(root->left, k, result);
        k--;
        if(k == 0) {
            result = root->val;
        }
        inorder(root->right, k, result);
    }
    int kthSmallest(TreeNode* root, int k) {
        int result = INT_MIN;
        inorder(root, k, result);
        return result;
    }
};
