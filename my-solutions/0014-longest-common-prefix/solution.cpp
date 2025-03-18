class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        return helper(strs, 0, strs.size() - 1);
    }
    string helper(vector<string>& strs, int l, int r) {
        if(l == r) return strs[l];
        if(l + 1 == r) {
            string res = "";
            int i = 0;
            while(i < strs[l].size() && i < strs[r].size()) {
                if(strs[l][i] == strs[r][i]) res += strs[l][i++];
                else break;
            }
            // cout << l << " " << r << " " << res << endl;
            return res;
        }
        int m = (l + r) / 2;
        string left = helper(strs, l, m);
        string right = helper(strs, m + 1, r);
        // cout << l << " " << r << " " << left << " " << right << endl;
        string res = "";
        int i = 0;
        while(i < left.size() && i < right.size()) {
            if(left[i] == right[i]) res += left[i++];
            else break;
        }
        return res;
    }
};
