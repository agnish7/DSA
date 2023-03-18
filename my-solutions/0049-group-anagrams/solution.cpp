class Solution {
public:
    string getKey(string s) {
        string key = "000000000000000000000000000";
        for(int i = 0; i < s.length(); i++) {
            key[int(s[i] - 'a')]++;
        }
        return key;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> string_map;
        for(int i = 0; i < size(strs); i++) {
            string key = getKey(strs[i]);
            if(string_map.find(key) == string_map.end()) {
                vector<string> v;
                v.push_back(strs[i]);
                string_map[key] = v;
            } else {
                string_map[key].push_back(strs[i]);
            }
        }

        vector<vector<string>> res;
        for(const auto& kv_pair: string_map) {
            res.push_back(kv_pair.second);
        }
        return res;
    }
};
