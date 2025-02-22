class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0, close = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '(') {
                ++open;
            }
            if(s[i] == ')') {
                ++close;
                if(close > open) {
                    s[i] = '*';
                    --close;
                }
            }
        }

        for(int i = s.size() - 1; i > -1; --i) {
            if(s[i] == '(' && open > close) {
                s[i] = '*';
                --open;
            }
        }

        string res;
        for(auto& c: s) {
            if(c != '*') {
                res += c;
            }
        }

        return res;
    }
};
