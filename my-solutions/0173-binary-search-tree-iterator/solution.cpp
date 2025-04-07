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
class BSTIterator {
    TreeNode* first;
    TreeNode* last;
    TreeNode* curr;
    TreeNode* root;
public:
    BSTIterator(TreeNode* root) {
        this->root = root;
        TreeNode* p = root;
        while(p && p->left) p = p->left;
        first = p;
        p = root;
        while(p && p->right) p = p->right;
        last = p;
        curr = new TreeNode(INT_MIN);
    }
    
    int next() {
        if(curr->val == INT_MIN) {
            curr = first;
            return curr->val;
        }

        if(curr == root) {
            curr = curr->right;
            while(curr && curr->left) curr = curr->left;
            return curr->val;
        }

        if(curr->right) {
            curr = curr->right;
            while(curr && curr->left) curr = curr->left;
        } else {
            TreeNode* node = root;
            TreeNode* res = node;
            int minVal = INT_MAX;
            while(node && node->left != curr && node->right != curr) {

                if(node->val < curr->val) node = node->right;
                else node = node->left;
                if(node->val < minVal && node->val > curr->val) {
                    minVal = min(minVal, node->val);
                    res = node;
                } 
            }
            curr = res;
        }

        return curr->val;
    }
    
    bool hasNext() {
        return curr != last;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
