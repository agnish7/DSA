
#include<string>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> operands;
        unordered_set<string> operators({"+", "-", "/", "*"});
        for(int i = 0; i < size(tokens); i++) {
            if(operators.find(tokens[i]) != operators.end()) {
                int op1 = stoi(operands.top());
                operands.pop();
                int op2 = stoi(operands.top());
                operands.pop();
                string operation = *(operators.find(tokens[i]));
                int result = 0;
                switch(operation[0]) {
                    case '+': result = op2 + op1; break;
                    case '-': result = op2 - op1; break;
                    case '*': result = op2 * op1; break;
                    case '/': result = op2 / op1; break;
                    default: cout << "Abort!" << endl;
                }
                operands.push(to_string(result));
            } else {
                operands.push(string(tokens[i]));
            }
        }

        return stoi(operands.top());
    }
};
