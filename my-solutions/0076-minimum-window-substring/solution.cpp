class Solution {
public:
    string minWindow(string s, string t) {
        int matches = 0;
        int window[128] = {0}, tMap[128] = {0}; // Use 128 for ASCII characters
        int l = 0, r = s.size();
        int needed = 0;
        for (auto& c : t) {
            if (!tMap[c]) ++needed; // Use c directly, no toupper
            ++tMap[c];
        }
        int j = 0;

        for (int i = 0; i < s.size(); ++i) {
            int idx = s[i]; // Use s[i] directly, no toupper
            ++window[idx];
            if (window[idx] == tMap[idx]) ++matches;

            if (matches == needed) {
                while (matches == needed) {
                    if (i - j < r - l) {
                        r = i;
                        l = j;
                    }
                    int idx = s[j]; // Use s[j] directly, no toupper
                    ++j;
                    --window[idx];
                    if (window[idx] == tMap[idx] - 1) --matches;
                }
            }
        }

        return r == s.size() ? "" : s.substr(l, (r - l + 1));
    }
};
