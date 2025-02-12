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
            }
            if(close > open) {
                s[i] = '*';
                open = 0;
                close = 0;
            }
        }
        open = open - close;
        for(int i = s.size() - 1; i > -1; --i) {
            if(open <= 0)
                break;
            if(s[i] == '(') {
                s[i] = '*';
                --open;
            }
        }
        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};
