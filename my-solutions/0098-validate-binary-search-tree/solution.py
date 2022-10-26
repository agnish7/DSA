# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.inorder_list = []
    
    def inorder(self, root):
        if not root:
            return
        if root.left:
            self.inorder(root.left)
        self.inorder_list.append(root.val)
        if root.right:
            self.inorder(root.right)
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        self.inorder(root)
        result = True
        for i in range(1, len(self.inorder_list)):
            result = result and self.inorder_list[i] > self.inorder_list[i-1]
        return result
        
        
