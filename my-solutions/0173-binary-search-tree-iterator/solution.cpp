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
    TreeNode* tail = nullptr;
    TreeNode* head = nullptr;
    TreeNode* it = nullptr;
public:
    BSTIterator(TreeNode* root) {
        head = convertToLL(root);
        TreeNode* p = head;
        it = head;
    }

    TreeNode* convertToLL(TreeNode* root) {
        if(!root) return nullptr;

        TreeNode* ll = convertToLL(root->left);
        root->left = tail;
        if(tail) tail->right = root;

        tail = root;

        TreeNode* rl = convertToLL(root->right);
        root->right = rl;
        if(rl) rl->left = root;

        return ll ? ll : root;
    }
    
    int next() {
        if(it) {
            int val = it->val;
            it = it->right;
            return val;
        } else return -1;
    }
    
    bool hasNext() {
        return it != nullptr;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
