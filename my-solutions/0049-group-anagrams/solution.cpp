class Solution {
public:
    string getKey(string s) {
        string key = "00000000000000000000000000";
        for(int i = 0; i < s.length(); i++) {
            key[(int(s[i]) - int('a'))]++;
        }
        return key;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> string_map;
        for(int i = 0; i < size(strs); i++) {
            string key = getKey(strs[i]);
            if(string_map.find(key) == string_map.end()) {
                string_map[key] = vector<string> {strs[i]};
            } else {
                string_map[key].push_back(strs[i]);
            }
        }

        for(const auto &i: string_map) {
            res.push_back(i.second);
        }

        return res;
    }
};
