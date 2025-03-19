class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        // vector<vector<int>> cache(s.size(), vector<int>(s.size(), 0));
        for(int i = 0; i < s.size(); ++i) {
            for(int l = i, r = i; l > -1 && r < s.size(); --l, ++r) {
                // if(cache[l][r]) continue;
                if(s[l] == s[r]) {
                    // cout << l << " " << r << endl;
                    // cache[l][r] = 1;
                    ++res;
                } else {
                    break;
                }
            }
        }

        for(int i = 1; i < s.size(); ++i) {
            for(int l = i -1, r = i; l > -1 && r < s.size(); --l, ++r) {
                // if(cache[l][r]) continue;
                if(s[l] == s[r]) {
                    // cout << l << " " << r << endl;
                    // cache[l][r] = 1;
                    ++res;
                } else {
                    break;
                }
            }
        }
        return res;
    }
};
