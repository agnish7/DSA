# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:

        res = True

        # maxLeft, minLeft, maxRight, minRight
        def dfs(node):
            nonlocal res
            if not node:
                return float('inf'), float('-inf')

            lmin, lmax = dfs(node.left)
            rmin, rmax = dfs(node.right)

            if lmax >= node.val or rmin <= node.val:
                res = False

            return min([node.val, lmin, rmin]), max([node.val, lmax, rmax])

        dfs(root)

        return res


