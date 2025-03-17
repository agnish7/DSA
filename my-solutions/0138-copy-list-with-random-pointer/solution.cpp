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
        unordered_map<Node*, Node*> nodeMap{};
        Node* prev = nullptr;
        Node* res = head;
        while(head) {
            if(!nodeMap.count(head)) {
                nodeMap[head] = new Node(head->val);
            }
            if(head->random && !nodeMap.count(head->random)) {
                nodeMap[head->random] = new Node(head->random->val);
            }
            nodeMap[head]->random = nodeMap[head->random];
            if(prev) nodeMap[prev]->next = nodeMap[head];
            prev = head;
            head = head->next;
        }
        return nodeMap[res];
    }
};
