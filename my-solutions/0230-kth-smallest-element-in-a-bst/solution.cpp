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
    int i = 0;
    int inorder(TreeNode* root, int k) {
        if(root ==  nullptr) {
            return -1;
        }
        if(root->left) {
            int temp = inorder(root->left, k);
            if(temp != -1)
                return temp;
        }
        i++;
        if(i == k)
            return root->val;

        if(root->right) {
            int temp = inorder(root->right, k);
            if(temp != -1)
                return temp;
        }
        
        return -1;
        
    }
    int kthSmallest(TreeNode* root, int k) {
        return inorder(root, k);
    }
};
