class Solution {
public:
    int calculate(string s) {
        s += '+';
        int last = 0;
        int num = 0;
        int val = 0;
        char lastOp = '+';
        for(auto& c: s) {
            if(c == ' ') continue;
            if(isdigit(c)){
                num = num*10 + (c - '0');
            } else {
                if(lastOp == '+') {
                    val += num;
                    last = num;
                } else if(lastOp == '-') {
                    val -= num;
                    last = -num;
                } else if(lastOp == '*') {
                    val = val - last + last * num;
                    last = last * num;
                } else if(lastOp == '/') {
                    val = val - last + last / num;
                    last = last / num;
                }
                num = 0;
                lastOp = c;
            }
        }

        return val;
    }
};
