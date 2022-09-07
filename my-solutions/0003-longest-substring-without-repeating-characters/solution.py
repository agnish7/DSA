class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0
        elif len(s) == 1:
            return 1
        i = 0
        window_chars = set([s[0]])
        max_window_len = -1
        for j in range(1, len(s)):
            while s[j] in window_chars:
                window_chars.discard(s[i])
                i = i + 1
            window_chars.add(s[j])
            if len(window_chars) > max_window_len:
                max_window_len = len(window_chars)
        return max_window_len
            
            
