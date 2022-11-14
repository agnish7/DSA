class Trie {
    class Node {
        public:
        char val;
        Node* next[26];
        bool isWord;
        Node(char c) {
            this->val = c;
            this->isWord = false;
            for(int i = 0; i < 26; i++) {
                this->next[i] = nullptr;
            }
        }
    };
    Node* getNode(string word) {
        Node* curr = this->root;
        for(int i = 0; i < word.length(); i++) {
            if(curr->next[word[i] - 'a'] == nullptr) {
                return nullptr;
            }
            // cout << curr->next[word[i] - 'a']->val << " " << word[i] << endl;
            curr = curr->next[word[i] - 'a'];
        }
        return curr;
    }
    Node* root;
public:
    Trie() {
        this->root = new Node('\0');
    }
    
    void insert(string word) {
        Node* curr = this->root;
        for(int i = 0; i < word.length(); i++) {
            int idx = word[i] - 'a';
            if(curr->next[idx] == nullptr) {
                curr->next[word[i] - 'a'] = new Node(word[i]);
            }
            curr = curr->next[idx];
        }
        curr->isWord = true;
    }
    
    bool search(string word) {
        Node* res = getNode(word);
        // cout << res->val << res->isWord << endl;
        return res != nullptr && res->isWord;
    }
    
    bool startsWith(string prefix) {
        Node* res = getNode(prefix);
        return res != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
