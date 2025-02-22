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
        unordered_map<int, unordered_map<int, vector<int>>> nodeMap;
        int minCol = 0, maxCol = 0, minRow = 0, maxRow = 0;
        vector<vector<int>> res;

        dfs(nodeMap, minCol, maxCol, minRow, maxRow, 0, 0, root);

        for(int i = minCol; i <= maxCol; ++i) {
            vector<int> rowElements;
            for(int j = minRow; j <= maxRow; ++j) {
                sort(nodeMap[i][j].begin(), nodeMap[i][j].end());
                // cout << i << " " << j << ": ";
                for(auto& e : nodeMap[i][j]) {
                    rowElements.push_back(e);
                    // cout << e << " ";
                }
                // cout << endl;
            }
            res.push_back(rowElements);
        }
        return res;
    }
    void dfs(
        unordered_map<int, unordered_map<int, vector<int>>>& nodeMap,
        int& minCol,
        int& maxCol,
        int& minRow,
        int& maxRow,
        int c,
        int r,
        TreeNode* currNode
    ) {
        if(!currNode) {
            return;
        }
        maxCol = max(c, maxCol);
        minCol = min(c, minCol);
        maxRow = max(r, maxRow);
        minRow = min(r, minRow);
        nodeMap[c][r].push_back(currNode->val);
        dfs(nodeMap, minCol, maxCol, minRow, maxRow, c - 1, r + 1, currNode->left);
        dfs(nodeMap, minCol, maxCol, minRow, maxRow, c + 1, r + 1, currNode->right);
    }
};
