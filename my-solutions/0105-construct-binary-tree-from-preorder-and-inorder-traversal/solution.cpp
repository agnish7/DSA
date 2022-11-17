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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& index, int i, int j) {
        if(i > j) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[index]);
        int split = 0;
        for(int i = 0; i < size(inorder); i++) {
            if(inorder[i] == preorder[index]) {
                split = i;
            }
        }
        index++;
        root->left = build(preorder, inorder, index, i, split - 1);
        root->right = build(preorder, inorder, index, split + 1, j);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        TreeNode* root = build(preorder, inorder, index, 0, size(inorder) - 1);
        return root;
    }
};
