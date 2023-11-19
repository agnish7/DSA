# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        res = True
        def dfs(node, left, right):
            nonlocal res
            if not node:
                return
            
            if not(left < node.val < right):
                res = False

            dfs(node.left, left, node.val)
            dfs(node.right, node.val, right)

        dfs(root, float('-inf'), float('inf'))

        return res
