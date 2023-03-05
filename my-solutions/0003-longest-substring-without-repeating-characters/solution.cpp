class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (size(s) == 0)
            return 0;
        unordered_map<char, int> char_map;
        int max_window_size = 1; // window size will be 1 at a minimum
        int j = 0;
        char_map[s[0]] = 1;
        for(int i = 1; i < size(s); i++) {
            // add s[i] to the map
            if(char_map.find(s[i]) == char_map.end()) {
                char_map[s[i]] = 1;
            } else {
                char_map[s[i]]++;
            }

            // if char_map[s[i]] > 1, keep removing s[j++] from char_map till char_map[s[i]] becomes == 1
            while(char_map[s[i]] > 1) {
                if(char_map[s[j]] == 1) {
                    char_map.erase(s[j]);
                } else if(char_map[s[j]] > 1) {
                    char_map[s[j]]--;
                }
                j++;
            }
            int curr_window_size = i - j + 1;
            // cout << "current window: " << i << ", " << j << endl;
            max_window_size = std::max(max_window_size, curr_window_size);

        }
        return max_window_size;
    }
};
