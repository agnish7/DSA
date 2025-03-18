class Solution {
public:
    string longestPalindrome(string s) {
        // odd length palindrome
        int max_l = 0, max_r = 0;
        for(int i = 0; i < s.size(); ++i) {
            for(int l = i, r = i; l > -1 && r < s.size(); --l, ++r) {
                // cout << l << " " << r << endl;
                if(s[l] == s[r]) {
                    if(r - l > max_r - max_l) {
                        max_l = l;
                        max_r = r;
                    }
                } else break;
            }
        }

        for(int i = 1; i < s.size(); ++i) {
            for(int l = i - 1, r = i; l > -1 && r < s.size(); --l, ++r) {
                // cout << l << " " << r << endl; 
                if(s[l] == s[r]) {
                    if(r - l > max_r - max_l) {
                        max_l = l;
                        max_r = r;
                    }
                } else break;
            }
        }

        return s.substr(max_l, max_r - max_l + 1);
    }
};
