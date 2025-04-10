class Solution {
public:
    int calculate(string s) {
        int num = 0, res = 0, sign = 1;
        stack<int> stk;

        for(auto& c: s) {
            if(isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if(c == '+') {
                res += sign * num;
                sign = 1;
                num = 0;
            } else if(c == '-') {
                res += sign * num;
                sign = -1;
                num = 0;
            } else if(c == '(') {
                stk.push(res);
                stk.push(sign);
                res = 0;
                sign = 1;
            } else if(c == ')') {
                res += num * sign;
                num = 0;
                int prevSign = stk.top(); stk.pop();
                int prevRes = stk.top(); stk.pop();
                res = prevRes + prevSign * res;
            }
        }

        res += sign* num;
        return res;
    }
};
