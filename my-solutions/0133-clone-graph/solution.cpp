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
        unordered_map<Node*, Node*> nodemap{{node, new Node(node->val)}};
        dfs(node, nodemap);
        return nodemap[node];
    }

    void dfs(Node* node, unordered_map<Node*, Node*>& nodemap) {
        for(auto& n: node->neighbors) {
            if(nodemap.find(n) == nodemap.end()) {
                nodemap[n] = new Node(n->val);
                dfs(n, nodemap);
            }
            nodemap[node]->neighbors.push_back(nodemap[n]);
        }
    }
};
