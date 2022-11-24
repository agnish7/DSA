# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPath(self, root):
        if not root:
            return[float("-inf"), float("-inf")]
        
        if not root.left and not root.right:
            return [root.val, root.val]

        left = self.maxPath(root.left)
        right = self.maxPath(root.right)

        # include parent max(left include, right include) + root.val
        res = [max(max(left[0], right[0]) + root.val, root.val)]
        # not include parent max(left not include, right not include, root val, root val + left include + right include)
        res.append(max(left[1], right[1], root.val, root.val + left[0] + right[0], root.val + left[0], root.val + right[0]))

        return res

    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        return max(self.maxPath(root))
