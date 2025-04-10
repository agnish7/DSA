class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0, close = 0;
        for(auto& c: s) {
            if(c == '(') ++open;
            else if(c == ')') ++ close;
            if(close > open) {
                c = '*';
                --close;
            }
        }

        for(int i = s.size() - 1; i > -1; --i) {
            if(s[i] == '(' && open > close){
                s[i] = '*';
                --open;
            }
            if(open == close) break;
        }

        string res = "";
        for(auto& c: s) {
            if(c != '*') res += c;
        }

        return res;
    }
};
