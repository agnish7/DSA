class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        backtrack(num, target, 0, "", 0, 0, result);
        return result;
    }
    
private:
    void backtrack(const string& num, int target, int pos, string expr, long value, long last, vector<string>& result) {
        // Base case: processed all digits
        if (pos == num.length()) {
            if (value == target) {
                result.push_back(expr);
            }
            return;
        }
        
        // Try all possible substrings starting at pos
        long curr = 0;
        string currStr;
        for (int i = pos; i < num.length(); ++i) {
            // Build current number
            curr = curr * 10 + (num[i] - '0');
            currStr += num[i];
            
            // Skip if leading zero and length > 1
            if (currStr.length() > 1 && currStr[0] == '0') break;
            
            // First number: no operator
            if (pos == 0) {
                backtrack(num, target, i + 1, currStr, curr, curr, result);
            } else {
                // Try all operators
                backtrack(num, target, i + 1, expr + "+" + currStr, value + curr, curr, result);
                backtrack(num, target, i + 1, expr + "-" + currStr, value - curr, -curr, result);
                // For *, undo the last addition and apply multiplication
                backtrack(num, target, i + 1, expr + "*" + currStr, value - last + last * curr, last * curr, result);
            }
        }
    }
};
