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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
    }
    void dfs(TreeNode* root, int num, int& sum) {
        if(!root) {
            return;
        }
        num = num * 10 + root->val;
        if(!root->left && !root->right) {
            sum += num;
            return;
        }
        dfs(root->left, num, sum);
        dfs(root->right, num, sum);
    }
};
