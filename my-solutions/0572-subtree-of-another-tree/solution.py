# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sameTree(self, s, t):
        if not s and not t:
            return True
        if s and t and s.val == t.val:
            return self.sameTree(s.left, t.left) and self.sameTree(s.right, t.right)
        return False

    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if subRoot == None:
            return True
        elif root == None:
            return False
        
        if self.sameTree(root, subRoot):
            return True
        
        temp1 = self.isSubtree(root.left, subRoot)
        temp2 = self.isSubtree(root.right, subRoot)
        return temp1 or temp2
    
        
