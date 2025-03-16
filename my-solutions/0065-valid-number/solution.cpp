class Solution {
public:
    bool isNumber(string s) {
        bool digit = false, sign = false, decimal = false, exponent = false;
        for(auto& c: s) {
            if(isalpha(c)) {
                string symbols = "eE+-";
                if(find(symbols.begin(), symbols.end(), c) == symbols.end()) return false;
            }
            if(isdigit(c)) digit = true;
            if(c == '+' || c == '-') {
                // cout << c << " " << sign << endl;
                if(sign || digit || (decimal && !exponent)) return false;
                sign = true;
            }
            if(c == '.') {
                // cout << c << " " << decimal << endl;
                if(decimal || exponent) return false;
                decimal = true;
            }
            if(c == 'e' || c == 'E') {
                // cout << c << " " << exponent << endl;
                if(exponent || !digit) return false;
                exponent = true;
                sign = false;
                digit = false;
            }
        }
        if(!digit) return false;
        return true;
    }
};
