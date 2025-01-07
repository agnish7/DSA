class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string start = strs[0];

        for(int i = 1; i < strs.size(); ++i) {
            int j = 0, n = strs[i].size();
            while(j < n && strs[i][j] == start[j]) {
                ++j;
            }
            start = start.substr(0, j);
        }
        return start;
    }
};
