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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> res;
        dfs(res, root, 0, 0);
        vector<vector<int>> output;
        for(auto& p1: res) {
            vector<int> temp;
            for(auto& p2: p1.second) {
                // cout << p1.first << " " << p2.first << " ";
                // for(int i = 0; i < p2.second.size(); ++i) {
                //     cout << p2.second[i] << " ";
                // }
                // cout << endl;
                sort(p2.second.begin(), p2.second.end());
                for(auto& e: p2.second) {
                    temp.push_back(e);
                }
            }
            output.push_back(temp);
        }
        return output;
    }
    void dfs(map<int, map<int, vector<int>>>& res, TreeNode* root, int r, int c) {
        if(!root) {
            return;
        }
        res[c][r].push_back(root->val);
        dfs(res, root->left, r + 1, c - 1);
        dfs(res, root->right, r + 1, c + 1);
    }
};
