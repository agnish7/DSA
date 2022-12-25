"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        node_map = {}

        def clone(node):
            if node in node_map:
                return node_map[node]
            else:
                # clone the node
                curr = Node(node.val)

                # add curr to the map
                node_map[node] = curr

                for i in range(len(node.neighbors)):
                    curr.neighbors.append(clone(node.neighbors[i]))
                
                return curr

        return clone(node) if node else None
