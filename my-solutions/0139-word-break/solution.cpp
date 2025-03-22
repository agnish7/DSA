class Solution {
    struct Node {
        Node* next[26] = {nullptr};
        bool e = false;
    } root;
public:
    void insert(string s) {
        Node* node = &root;
        for(auto& c: s) {
            int idx = c - 'a';
            if(!node->next[idx]) node->next[idx] = new Node();
            node = node->next[idx];
        }
        node->e = true;
    }

    bool search(int i, int j, string& s) {
        if(j >= s.size()) return false;
        Node* node = &root;
        for(int e = i; e <= j; ++e) {
            int idx = s[e] - 'a';
            if(!node->next[idx]) return false;
            node = node->next[idx];
        }
        return node->e;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto& word: wordDict) {
            insert(word);
        }
        vector<bool> res(s.size() + 1, false);
        res[s.size()] = true;
        for(int i = s.size() - 1; i > -1; --i) {
            for(int j = i; j < s.size(); ++j) {
                res[i] = res[i] || (search(i, j, s) && res[j+1]);
            }
        }
        return res[0];
    }
};
