class Trie {
    struct Node {
        Node* c[26] = {nullptr}; // Fixed-size array for children
        bool e = false;          // End-of-word flag
    } root;  
public:
    Trie() {
     
    }
    
    void insert(string w) {
        Node* n = &root;
        for (char ch : w) {
            if (!n->c[ch - 'a']) n->c[ch - 'a'] = new Node();
            n = n->c[ch - 'a'];
        }
        n->e = true;
    }
    
    bool search(string w) const {
        const Node* n = &root;
        for (char ch : w) {
            if (!n->c[ch - 'a']) return false;
            n = n->c[ch - 'a'];
        }
        return n->e;
    }
    
    bool startsWith(string p) const {
        const Node* n = &root;
        for (char ch : p) {
            if (!n->c[ch - 'a']) return false;
            n = n->c[ch - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
