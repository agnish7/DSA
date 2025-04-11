class Solution {
public:
    bool isPalindrome(int x) {
        string x_bar = to_string(x);
        int l = 0, r = x_bar.size() - 1;
        while(l < r) {
            if(x_bar[l] != x_bar[r]) return false;
            ++l;
            --r;
        }
        return true;
    }
};
