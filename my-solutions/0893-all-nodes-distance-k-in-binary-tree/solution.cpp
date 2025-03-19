/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        dfs(root, nullptr, parent);
        TreeNode* curr = target;
        unordered_set<TreeNode*> visited;
        vector<int> res;
        while(curr) {
            findNodes(curr, k--, visited, res);
            curr = parent[curr];
        }
        return res;
    }

    void dfs(TreeNode* root, TreeNode* prev, unordered_map<TreeNode*, TreeNode*>& parent) {
        if(!root) return;
        parent[root] = prev;
        dfs(root->left, root, parent);
        dfs(root->right, root, parent);
    }

    void findNodes(TreeNode* node, int k, unordered_set<TreeNode*>& visited, vector<int>& res) {
        if(!node || k < 0 || visited.count(node)) return;
        visited.insert(node);
        if(k == 0) res.push_back(node->val);
        findNodes(node->left, k - 1, visited, res);
        findNodes(node->right, k - 1, visited, res);
    }
};
