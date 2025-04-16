class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        bool flag = false;
        while(l < r) {
            if(s[l] == s[r]) {
                ++l;
                --r;
            } else break;
        }
        return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
    }

    bool isPalindrome(string& s, int l, int r) {
        while(l < r) {
            if(s[l] != s[r]) return false;
            ++l;
            --r;
        }
        return true;
    }
};
