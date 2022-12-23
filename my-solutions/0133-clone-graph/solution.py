"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        visited = {}

        if not node:
            return None
        def dfs(node):
            if node in visited:
                return visited[node]
            else:
                # create copy
                cpy = Node(node.val)

                # add to visited
                visited[node] = cpy
                for i in range(len(node.neighbors)):
                    cpy.neighbors.append(dfs(node.neighbors[i]))
            
                return cpy

        return dfs(node)

