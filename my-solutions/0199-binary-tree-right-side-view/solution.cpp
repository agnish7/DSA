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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        deque<TreeNode*> nodes{root};
        vector<int> res;

        // cout << nodes.back()->val << " " << nodes.front()->val << endl;

        while(!nodes.empty()) {
            int level = nodes.size();
            for(int i = 0; i < level; ++i) {
                TreeNode* curr = nodes.front();
                nodes.pop_front();
                if(i == level - 1) res.push_back(curr->val);
                if(curr->left) nodes.push_back(curr->left);
                if(curr->right) nodes.push_back(curr->right);
            }
        }

        return res;
    }
};
