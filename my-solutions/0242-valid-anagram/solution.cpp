class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> char_count;
        for(int i = 0; i < size(s); i++){
            if(char_count.find(s[i]) == char_count.end()){
                char_count.insert(pair<char, int>(s[i], 1));
            } else {
                char_count[s[i]]++;
            }
        }
        for(int i = 0; i < size(t); i++) {
            if(char_count.find(t[i]) == char_count.end()) {
                return false;
            } else {
                char_count[t[i]]--;
                if(char_count[t[i]] < 0) {
                    return false;
                }
            }
        }
        for(auto &i: char_count) {
            if(i.second != 0) {
                return false;
            }
        }
        return true;
    }
};
