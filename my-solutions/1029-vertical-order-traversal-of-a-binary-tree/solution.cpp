/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map < int, vector<pair<int, int>>> col_to_data;

        int minCol = 0, maxCol = 0;

        queue<tuple<TreeNode*, int, int>> q;
        q.push(tuple(root, 0, 0));

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [node, r, c] = q.front();
                q.pop();

                minCol = min(minCol, c);
                maxCol = max(maxCol, c);

                col_to_data[c].emplace_back(r, node->val);
                if (node->left)
                    q.push(tuple(node->left, r + 1, c - 1));
                if (node->right)
                    q.push(tuple(node->right, r + 1, c + 1));
            }
        }

        vector<vector<int>> res;
        for (int c = minCol; c <= maxCol; ++c) {
            // Sort by row, then value
            sort(col_to_data[c].begin(), col_to_data[c].end());
            vector<int> vertical;
            vertical.reserve(col_to_data[c].size());
            for (auto& [row, val] : col_to_data[c]) {
                vertical.push_back(val);
            }
            res.push_back(vertical);
        }

        return res;
    }
};
