class Solution {
public:
    bool isNumber(string s) {
        bool sign = false, decimal = false, exp = false;
        bool digit = false;
        for(auto& c: s) {
            if(isalpha(c) && c != 'e' && c != 'E') return false;
            if(c == '+' || c == '-') {
                if(sign || decimal || digit) return false;
                sign = true;
            }
            else if(c == '.') {
                if(exp || decimal) return false;
                decimal = true;
            } else if(c == 'e' || c == 'E') {
                if(exp || !digit) return false;
                digit = false;
                sign = false;
                decimal = false;
                exp = true;
            } else if(isdigit(c)) {
                digit = true;
            }
        }

        cout << digit << endl;

        if(!digit) return false;
        else return true;
    }
};
