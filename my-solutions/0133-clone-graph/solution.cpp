/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<Node*, Node*> nodeMap;
        dfs(node, nodeMap);
        return nodeMap[node];
    }
    void dfs(Node* node, unordered_map<Node*, Node*>& nodeMap) {
        if(!node || nodeMap.count(node)) return;

        Node* clonedNode = new Node(node->val);
        nodeMap[node] = clonedNode;
        
        for(auto& n: node->neighbors) {
            if(!nodeMap.count(n)) dfs(n, nodeMap);
            clonedNode->neighbors.push_back(nodeMap[n]);
        }
    }
};
