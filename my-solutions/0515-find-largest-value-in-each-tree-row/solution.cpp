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
    vector<int> largestValues(TreeNode* root) {
        deque<TreeNode*> q{root};
        vector<int> res;
        while(!q.empty()) {
            deque<TreeNode*> level;
            int maxInLevel = INT_MIN;
            while(!q.empty()) {
                if(q.front()) maxInLevel = max(maxInLevel, q.front()->val);
                if(q.front()) level.push_back(q.front()->left);
                if(q.front()) level.push_back(q.front()->right); 
                q.pop_front();
            }
            if(!level.empty()) res.push_back(maxInLevel);
            q = level;
        }

        return res;
    }
};
