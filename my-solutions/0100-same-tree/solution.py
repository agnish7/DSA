# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        def dfs(a, b):
            if (a and b):
                l = dfs(a.left, b.left)
                r = dfs(a.right, b.right)
                return l and r and (a.val == b.val)
            elif not a and not b:
                return True
            else:
                return False
        
        return dfs(p, q)

        
