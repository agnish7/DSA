# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def traverseTree(self, root, level, level_map):
        if root == None:
            return level_map
        if level in level_map.keys():
            level_map[level].append(root.val)
        else:
            level_map[level] = [root.val]
        self.traverseTree(root.left, level + 1, level_map)
        self.traverseTree(root.right, level + 1, level_map)
        return level_map
        
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        # traversal
        level_map = self.traverseTree(root, 1, {})
        return list(level_map.values())
        
        
