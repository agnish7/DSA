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
    vector<int> dfs(TreeNode* p) {
        if(p == nullptr)
            return vector<int>({0, 0});
        vector<int> left_max = dfs(p->left);
        vector<int> right_max = dfs(p->right);
        vector<int> res({p->val + left_max[1] + right_max[1], max(left_max[0], left_max[1]) + max(right_max[0], right_max[1])});
        return res;
    }
    int rob(TreeNode* root) {
        vector<int> res = dfs(root);
        return max(res[0], res[1]);
    }
};
