class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while(l < r) {
            if(s[l] == s[r]) {
                ++l;
                --r;
            } else {
                int l1 = l + 1, r1 = r;
                int l2 = l, r2 = r - 1;
                bool res1 = true, res2 = true;
                while(l1 < r1) {
                    // cout << l1 << " " << r1 << endl;
                    if(s[l1] == s[r1]) {
                        ++l1;
                        --r1;
                    } else {
                        res1 = false;
                        break;
                    }
                }
                while(l2 < r2) {
                    // cout << l2 << " " << r2 << endl;
                    if(s[l2] == s[r2]) {
                        ++l2;
                        --r2;
                    } else {
                        res2 = false;
                        break;
                    }
                }
                if(!res1 && !res2) {
                    return false;
                } else {
                    return true;
                }
            }
        }
        return true;
    }
};
