class Solution {
public:
    int calculate(string s) {
        stack<long> values;
        char op = '+';
        long num = 0;

        for(int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if(isdigit(c)) {
                num = num * 10 + c - '0';
            } 
            if((c != ' ' && !isdigit(c)) || i == s.size() - 1) {
                if(op == '+') {
                    values.push(num);
                } else if(op == '-') {
                    values.push(-num);
                } else if(op == '*') {
                    int topVal = values.top();
                    values.pop();
                    values.push(topVal * num);
                } else if(op == '/') {
                    int topVal = values.top();
                    values.pop();
                    values.push(topVal / num);
                }
                op = c;
                num = 0;
            }
        }

        // printStack(values);

        int res = 0;
        while(!values.empty()) {
            res += values.top();
            values.pop();
        }

        return res;
    }

    void printStack(stack<int> a) {
        string res = "";
        while(!a.empty()) {
            res = (to_string(a.top()) + " ") + res;
            a.pop();
        }
        cout << res;
    }
};
