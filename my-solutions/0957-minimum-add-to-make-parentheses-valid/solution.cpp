class Solution {
public:
    int minAddToMakeValid(string s) {
        int balance = 0;
        int res = 0;
        for(auto& c: s) {
            if(c == ')') {
                --balance;
            } else if (c == '(') {
                ++balance;
            }

            if(balance < 0) {
                ++res;
                balance = 0;
            }
        }
        return res + balance;
    }
};
