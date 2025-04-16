class Solution {
public:
    bool isSubsequence(string s, string t) {
        for(int i = t.size() - 1; i > -1; --i) {
            if(s.size() == 0) return true;
            if(t[i] == s[s.size() - 1]) s.pop_back();
        }
        return s.size() == 0;
    }
};
