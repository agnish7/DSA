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
    unordered_map<TreeNode*, TreeNode*> parent;

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> q;
        q.push(target);

        parent[root] = nullptr;

        dfs(root);

        int distance = 0;

        while(!q.empty()) {

            if(distance == k) break;
            int size = q.size();
            for(int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                node->val = -1;

                if(node->left && node->left->val != -1) q.push(node->left);
                if(node->right && node->right->val != -1) q.push(node->right);
                if(parent[node] && parent[node]->val != -1) q.push(parent[node]);
            }
            ++distance;
        }

        vector<int> res;
        while(!q.empty()) {res.push_back(q.front()->val); q.pop();}
        return res;
    }
    void dfs(TreeNode* root) {
        if(!root) return;
        if(root->left) {
            parent[root->left] = root;
            dfs(root->left);
        }
        if(root->right) {
            parent[root->right] = root;
            dfs(root->right);
        }
    }

};
