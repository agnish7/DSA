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
#include <queue>

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) {
            return vector<vector<int>>();
        }
        vector<vector<int>> result;
        vector<int> level;
        queue<TreeNode*> q;
        q.push(root);
        int count = 1;
        while(!q.empty()) {
            level.clear();
            for(int i = 0; i < count; i++) {
                if(q.front()) {
                    level.push_back(q.front()->val);
                    if(q.front()->left) q.push(q.front()->left);
                    if(q.front()->right) q.push(q.front()->right);
                    q.pop();
                }
            }
            count = size(q);
            result.push_back(level);
        }
        return result;
    }
};
