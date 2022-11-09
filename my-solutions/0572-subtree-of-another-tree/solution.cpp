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
    bool checkSubTree(TreeNode* root, TreeNode* subroot) {
        if(subroot && root) {
            // cout << root->val << " " << subroot->val << endl;
            return subroot->val == root->val && checkSubTree(root->left, subroot->left) && checkSubTree(root->right, subroot->right);
        } else if (!root && !subroot) {
            // cout << "null" << " " << "null" << endl;
            return true;
        } else {
            return false;
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root){
            return false;
        } else {
            if(checkSubTree(root, subRoot)) {
                // cout << root->val << " " << subRoot->val << endl;
                return true;
            } else {
                return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
            }
        }
    }
};
