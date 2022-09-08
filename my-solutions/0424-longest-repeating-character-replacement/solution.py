class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        max_len, i = -1, 0
        char_dict = {s[0]:1}
        for j in range(1, len(s)):
            if s[j] in char_dict.keys():
                char_dict[s[j]] += 1
            else:
                char_dict[s[j]] = 1
            max_freq = max(char_dict.values())
            while j - i + 1 - max_freq > k:
                

                char_dict[s[i]] -= 1
                    
                i+=1
                
                max_freq = max(char_dict.values())
                #print(i, j, char_dict, max_freq)

            max_len = max(max_len, j - i + 1)
            #print(i, j, max_len)
        
        return max_len
