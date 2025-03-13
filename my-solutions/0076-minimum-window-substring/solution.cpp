class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        unordered_map<char, int> tMap, sMap;
        int required = 0, matches = 0;
        int minLen = INT_MAX, minStart = 0;

        // Build tMap and count unique characters needed
        for (char c : t) {
            if (tMap[c] == 0) required++; // New unique character
            tMap[c]++;
        }

        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            // Expand window
            char right = s[i];
            sMap[right]++;
            if (tMap.count(right) && sMap[right] == tMap[right]) {
                matches++;
            }

            // Shrink window as much as possible
            while (matches == required) {
                if (i - j + 1 < minLen) {
                    minLen = i - j + 1;
                    minStart = j;
                }
                char left = s[j];
                sMap[left]--;
                if (tMap.count(left) && sMap[left] < tMap[left]) {
                    matches--;
                }
                j++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};
