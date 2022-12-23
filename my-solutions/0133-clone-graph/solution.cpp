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
    unordered_map<Node*, Node*> visited;
public:
    Node* clone(Node* node) {
        if(visited.find(node) != visited.end()) {
            return visited[node];
        } else {
            // clone the node
            Node* cpy = new Node(node->val);
            visited[node] = cpy;

            // insert all neighbors to the cpy node's list of neighbors
            for(int i = 0; i < size(node->neighbors); i++) {
                cpy->neighbors.push_back(clone(node->neighbors[i]));
            }
            return cpy;
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node)
            return nullptr;
        else {
            return clone(node);
        }
    }
};
