class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        backtrack(0, 0, "", 0, num, target, res);
        return res;
    }

    void backtrack(int i, long val, string expr, long last, string& num, long target, vector<string>& res) {
        if(i == num.size()) {
            if(val == target) {
                res.push_back(expr);
            }
            return;
        }

        string number;
        long currVal = 0;
        for(int j = i; j < num.size(); ++j) {

            number += num[j];
            currVal = currVal * 10 + (num[j] - '0');

            if(num[i] == '0' && j > i) break;
            
            if(i == 0) {
                backtrack(j + 1, currVal, number, currVal, num, target, res);
            } else {
                backtrack(j + 1, val + currVal, expr + '+' + number, currVal, num, target, res);
                backtrack(j + 1, val - currVal, expr + '-' + number, -currVal, num, target, res);
                backtrack(j + 1, val - last + last * currVal, expr + '*' + number, last * currVal, num, target, res);
            }
        }
    } 
};
