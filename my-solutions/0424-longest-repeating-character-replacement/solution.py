class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        char_map = {}
        l = 0
        max_size_ss = 1

        for r in range(len(s)):
            if s[r] in char_map:
                char_map[s[r]] += 1
            else:
                char_map[s[r]] = 1

            max_char = max(list(char_map.values())) if len(list(char_map.values())) > 0 else 0
            while(l < r and r - l + 1 - max_char > k):
                char_map[s[l]] -= 1
                l += 1

            max_size_ss = max(max_size_ss, r - l + 1)

        return max_size_ss
