# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:

        maxPath = float('-inf')
        
        def dfs(node):
            nonlocal maxPath
            if not node:
                return float('-inf')

            l = dfs(node.left)
            r = dfs(node.right)

            maxPath = max(maxPath, l, r, node.val + max(l, 0) + max(r, 0))
            return node.val + max(l, r, 0)

        dfs(root)

        return maxPath
            
