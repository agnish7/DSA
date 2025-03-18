class Solution {
public:
    string addStrings(string num1, string num2) {
        int sum = 0, carry = 0;
        string res = "";
        while(num1.size() || num2.size() || carry) {
            sum = (num1.size() ? (num1[num1.size() - 1] - '0') : 0)
                + (num2.size() ? (num2[num2.size() - 1] - '0') : 0)
                + carry;
            carry = sum / 10;
            sum = sum % 10;
            res.push_back(sum + '0');

            if(num1.size()) num1.pop_back();
            if(num2.size()) num2.pop_back();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
