# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
import math

class Solution:
    def maxPath(self, root):
        if root == None:
            return [-math.inf, -math.inf]
        else:
            left = self.maxPath(root.left)
            right = self.maxPath(root.right)
            wo = max(root.val + left[0] + right[0], left[1], right[1], left[0], right[0])
            wm = max(root.val + left[0], root.val + right[0], root.val)
            return [wm, wo]
    
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        return max(self.maxPath(root))
