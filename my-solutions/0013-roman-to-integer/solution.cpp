class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> value {
            {'I'     ,       1},
            {'V'      ,       5},
            {'X'     ,       10},
            {'L'      ,       50},
            {'C'      ,       100},
            {'D'      ,       500},
            {'M'      ,       1000}
        };

        int i = 0;
        int res = 0;
        while(i < s.size() - 1) {
            if(value[s[i + 1]] > value[s[i]]) {
                res += value[s[i + 1]] - value[s[i]];
                i += 2;
            } else {
                res += value[s[i]];
                ++i;
            }
        }

        if(i < s.size()) res += value[s[i]];
        return res;
    }
};
