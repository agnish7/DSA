# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        res = ""
        def dfs(node):
            nonlocal res
            if not node:
                res += "N" + ","
                return
            res += str(node.val) + ","
            dfs(node.left)
            dfs(node.right)


        dfs(root)
        return res[:-1]
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """

        vals = data.split(',')
        idx = 0

        def build():
            nonlocal idx
            if vals[idx] == 'N':
                idx += 1
                return None

            node = TreeNode(int(vals[idx]))
            idx += 1
            left = build()
            right = build()

            node.left = left
            node.right = right

            return node

        res = build()
        return res

        

        return None
        

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
