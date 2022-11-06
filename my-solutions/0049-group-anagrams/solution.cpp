class Solution {
public:
    string getKey(string s) {
        vector<int> count(26);
        for(int i = 0; i < s.length(); i++){
            count[s[i] - 'a']++;
        }
        // for(auto &i: count) {
        //     cout << i << " ";
        // }
        string key = string("");
        for(int i = 0; i < 26; i++) {
            key.append(to_string(count[i] + 'a'));
        }
        // cout << "\n" << key << " ";
        return key;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> string_map;
        vector<vector<string>> result;
        for(int i = 0; i < size(strs); i++) {
            string key = getKey(strs[i]);
            if(string_map.find(key) == string_map.end()) {
                string_map.insert(pair<string, vector<int>>(key, vector<int>{i}));
                // cout << key << " " << i << endl;
            } else {
                string_map[key].push_back(i);
                // cout << key << " " << i << endl;
            }
        }
        for(auto &i: string_map) {
            vector<string> vs;
            for(auto &j : i.second) {
                cout << j << " ";
                vs.push_back(strs[j]);
            }
            cout << endl;
            result.push_back(vs);
        }
        return result;
    }
};
