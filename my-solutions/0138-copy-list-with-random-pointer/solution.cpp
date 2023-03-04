/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> nodeMap;

        Node* curr = head;
        while(curr) {
            if(nodeMap.find(curr) == nodeMap.end()) {
                nodeMap[curr] = new Node(curr->val);
            }
            if(nodeMap.find(curr->next) == nodeMap.end()) {
                if(curr->next) nodeMap[curr->next] = new Node(curr->next->val); else nodeMap[curr->next] = nullptr;
                nodeMap[curr]->next = nodeMap[curr->next];
            } else {
                nodeMap[curr]->next = nodeMap[curr->next];
            }
            if(nodeMap.find(curr->random) == nodeMap.end()) {
                if(curr->random) nodeMap[curr->random] = new Node(curr->random->val); else nodeMap[curr->random] = nullptr;
                nodeMap[curr]->random = nodeMap[curr->random];
            } else {
                nodeMap[curr]->random = nodeMap[curr->random];
            }
            curr = curr->next;
        }
        return nodeMap[head];
    }
};
