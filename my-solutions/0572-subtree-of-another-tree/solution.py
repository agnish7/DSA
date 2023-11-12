# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:

        res = False
        def isSubRoot(a, b):
            if a and b:
                return isSubRoot(a.left, b.left) and isSubRoot(a.right, b.right) and a.val == b.val
            elif not a and not b:
                return True
            else:
                return False

        def dfs(root):
            nonlocal res
            if root:
                res = res or isSubRoot(root, subRoot)
                dfs(root.left)
                dfs(root.right)

        dfs(root)

        return res
