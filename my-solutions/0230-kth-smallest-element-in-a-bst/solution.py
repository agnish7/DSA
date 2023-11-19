# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        # iterative solution
        inorder = []
        def io(node):
            if not node:
                return
            nonlocal inorder
            io(node.left)
            if len(inorder) == k:
                return
            inorder.append(node.val)
            io(node.right)

        io(root)

        return inorder[k - 1]
