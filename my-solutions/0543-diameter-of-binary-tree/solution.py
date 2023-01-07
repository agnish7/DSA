
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:

        max_height = {}

        def findheight(root):
            if root == None:
                return 0

            else:
                res = 1 + max(findheight(root.left), findheight(root.right))
                max_height[root] = res
                return res

        findheight(root)

        maxdia = -1
        for key in max_height:
            left = max_height[key.left] if key.left in max_height else 0
            right = max_height[key.right] if key.right in max_height else 0
            dia =  left + right + 1
            # print(key, dia)
            if dia > maxdia:
                maxdia = dia

        return maxdia - 1

