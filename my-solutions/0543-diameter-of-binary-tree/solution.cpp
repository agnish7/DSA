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
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = INT_MIN;
        dfs(root, dia);
        return dia;
    }
    int dfs(TreeNode* root, int& dia) {
        if(!root) {
            return 0;
        }
        int left = dfs(root->left, dia);
        int right = dfs(root->right, dia);
        dia = max(dia, left + right);
        return 1 + max(left, right);
    }
};
