# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):

    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """

        if len(preorder) == 0:
            return None
        if len(preorder) == 1:
            return TreeNode(preorder[0])
        
        if preorder[0] not in inorder:
            return None
        root_idx = inorder.index(preorder[0])

        left_tree = self.buildTree(preorder[1:root_idx+1], inorder[:root_idx])
        right_tree = self.buildTree(preorder[root_idx+1:], inorder[root_idx+1:])

        root = TreeNode(preorder[0])

        root.left = left_tree
        root.right = right_tree

        return root

