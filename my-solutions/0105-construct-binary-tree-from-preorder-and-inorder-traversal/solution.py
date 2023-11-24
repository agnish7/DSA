# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        pre = 0
        def build(ino_l, ino_r):
            nonlocal pre
            if ino_l > ino_r:
                return None

            root = TreeNode(preorder[pre])
            idx = inorder.index(preorder[pre])
            pre += 1
            left = build(ino_l, idx - 1)
            right = build(idx + 1, ino_r)
            root.left = left
            root.right = right
            return root

        return build(0, len(inorder) - 1)

