class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        
        
        char_set = set()
        last = 0
        curr_len = -1
        max_len = 0

        for i in range(len(s)):
            # max_len = max(max_len, i - last)
            while(s[i] in char_set):
                char_set.discard(s[last])
                last += 1
            
            max_len = max(max_len, i - last + 1)
            char_set.add(s[i])
                
        return max_len
